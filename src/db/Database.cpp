//
// Created by Magnus Krogh on 25/01/2026.
//

#include "Database.h"
#include "Command.h"
#include <sstream>
#include <vector>

//Splits a string into whitespace‑separated tokens.
static std::vector< std::string > tokenize( const std::string& input) {
    //Wrap the input string in a stream so we can extract words easily
    std::istringstream stream(input);
    //Container to store the resulting tokens
    std::vector< std::string > tokens;
    //Temporary buffer for each extracted token
    std::string token;
    //Extract tokens separated by whitespace until the stream is exhausted
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

static Command parseCommand(const std::vector<std::string>& tokens) {
    //Handles empty commands
    if (tokens.empty()) {
        return {CommandType::INVALID, {}};
    }
    //First element of the command
    const auto& cmd = tokens[0];

    //Vector containing everything else than the first element
    std::vector <std::string> args = {tokens.begin() + 1, tokens.end()};

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


//Set, get and delete command handling
std::string Database::execute(const std::string& command) {
    //Break the command into whitespace-separated tokens
    auto tokens = tokenize(command);

    //Handles empty commands
    if (tokens.empty()) {
        return "ERROR: Empty command";
    }

    // Handle the SET command
    if (tokens [0] == "SET") {
        //SET must have exactly 3 tokens: ["SET", key, value]
        if (tokens.size() != 3) {
            return "ERROR: SET requires key and value";
        }
        //Store the key/value pair in the internal storage engine
        storage_.set(tokens[1], tokens[2]);
        return "Success";
    }

    // Handle the GET command
    if (tokens [0] == "GET") {
        // GET must have exactly 2 tokens: ["GET", key]
        if (tokens.size() != 2) {
            return "ERROR: GET requires key";
        }

        // Attempt to retrieve the value
        auto value = storage_.get(tokens[1]);
        if (!value) {
            return "ERROR: key not found";
        }

        return *value; //Extract the value from the optional
    }

    // Handle the DELETE command
    if (tokens [0] == "DELETE") {
        // DELETE must have exactly 2 tokens: ["DELETE", key]
        if (tokens.size() != 2) {
            return "ERROR: DELETE requires key";
        }
        // Attempt to remove the key
        if (!storage_.remove(tokens[1])) {
            return "ERROR: key not found";
        }
        return "Success";
    }

    //If the command is not recognized
    return "ERROR: Unknown command";
}


