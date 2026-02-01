//
// Created by Magnus Krogh on 28/01/2026.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

enum class CommandType {
    SET,
    GET,
    DELETE,
    INVALID
};

struct Command {
    CommandType type;
    vector<string> args;
};