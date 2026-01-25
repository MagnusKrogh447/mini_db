//
// Created by Magnus Krogh on 25/01/2026.
//

#include "Database.h"
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

//Set command handling
std::string Database::execute(const std::string& command) {
    auto tokens = tokenize(command);

    if (tokens.empty()) {
        return "ERROR: Empty command";
    }

    if (tokens [0] == "SET") {
        //SET must have exactly 3 tokens: ["SET", key, value]
        if (tokens.size() != 3) {
            return "ERROR: SET requieres key and value";
        }
        //Call the database's internal storage to save the key/value pair
        storage_.set(tokens[1], tokens[2]);
        return "Succes";
    }
    //If the command is not recognized
    return "ERROR: Unknown command";
}
