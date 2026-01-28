//
// Created by Magnus Krogh on 25/01/2026.
//

#pragma once
#include <string>

#include "../storage/StorageEngine.h"

class Database {
public:
    std::string execute(const std::string& command);

private:
    StorageEngine storage_;
};


