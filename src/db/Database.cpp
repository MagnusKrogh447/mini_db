//
// Created by Magnus Krogh on 25/01/2026.
//

#include "Database.h"
#include "Command.h"
#include <sstream>
#include <vector>

using namespace std;

//Splits a string into whitespace‑separated tokens.
static vector<string> tokenize(const string &input) {
    //Wrap the input string in a stream so we can extract words easily
    istringstream stream(input);
    //Container to store the resulting tokens
    vector<string> tokens;
    //Temporary buffer for each extracted token
    string token;
    //Extract tokens separated by whitespace until the stream is exhausted
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

//Dedicated function command parsing
static Command parseCommand(const vector<string> &tokens) {
    //Handles empty commands
    if (tokens.empty()) {
        return {CommandType::INVALID, {}};
    }
    //First element of the command
    const auto &cmd = tokens[0];

    //Vector containing everything else than the first element
    vector<string> args = {tokens.begin() + 1, tokens.end()};

    //handles the get command
    if (cmd == "SET") {
        return {CommandType::SET, args};
    }
    //handles the get command
    if (cmd == "GET") {
        return {CommandType::GET, args};
    }
    //handles the delete command
    if (cmd == "DELETE") {
        return {CommandType::DELETE, args};
    }
    //Unknown Commands
    return {CommandType::INVALID, {}};
}


//Set, get and delete command handling using parse command
string Database::execute(const string& input) {
    auto tokens = tokenize(input);
    auto command = parseCommand(tokens);

    switch (command.type) {
        case CommandType::SET:
            //Set must have key and value
            if (command.args.size() != 2) {
                return "ERROR: SET requires key and value";
            }
            //Store the value with the key
            storage_.set(command.args[0], command.args[1]);
            return "OK";

        case CommandType::GET:
            //Get needs key
            if (command.args.size() != 1) {
                return "ERROR: GET requires key";
            }
            //Finds and returns the value
            if (auto value = storage_.get(command.args[0])) {
                return *value;
            }
            return "ERROR: Key not found";

        case CommandType::DELETE:
            //Delete requires key
            if (command.args.size() != 1) {
                return "ERROR: DELETE requires key";
            }
            //removes the stored value
            return storage_.remove(command.args[0]) ? "OK" : "ERROR: Key not found";

        //If not picked up by now, must be unknown command
        default:
            return "ERROR: Unknown command";
    }
}

