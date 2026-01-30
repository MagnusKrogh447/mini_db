//
// Created by Magnus Krogh on 25/01/2026.
//

#pragma once
#include <string>

#include "../storage/StorageEngine.h"

using namespace std;

class Database {
public:
    Database();
    string execute(const string& command);
    void save() const;

private:
    StorageEngine storage_;
};


