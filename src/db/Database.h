//
// Created by Magnus Krogh on 25/01/2026.
//

#pragma once
#include <string>

#include "../storage/StorageEngine.h"

using namespace std;

class Database {
public:
    string execute(const string& command);

private:
    StorageEngine storage_;
};


