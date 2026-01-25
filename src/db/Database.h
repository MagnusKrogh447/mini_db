//
// Created by Magnus Krogh on 25/01/2026.
//

#ifndef MINI_DB_DATABASE_H
#define MINI_DB_DATABASE_H

#pragma once
#include <string>

#include "../storage/StorageEngine.h"

class Database {
public:
    std::string execute(const std::string& command);

private:
    StorageEngine storage_;
};
#endif //MINI_DB_DATABASE_H

