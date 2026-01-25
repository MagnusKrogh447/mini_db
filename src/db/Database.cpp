//
// Created by Magnus Krogh on 25/01/2026.
//

#include "Database.h"
#include <sstream>
#include <vector>


std::string Database::execute(const std::string& command) {
    return "NOT IMPLEMENTED";
}

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