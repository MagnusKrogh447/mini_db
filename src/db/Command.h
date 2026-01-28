//
// Created by Magnus Krogh on 28/01/2026.
//

#pragma once
#include <string>
#include <vector>

enum class CommandType {
    SET,
    GET,
    DELETE,
    INVALID
};

struct Command {
    CommandType type;
    std::vector<std::string> args;
};