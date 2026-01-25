//
// Created by Magnus Krogh on 25/01/2026.
//

#ifndef MINI_DB_DATABASE_H
#define MINI_DB_DATABASE_H

#pragma once
#include <string>

class Database {
public:
    std::string execute(const std::string& command);
};


#endif //MINI_DB_DATABASE_H

