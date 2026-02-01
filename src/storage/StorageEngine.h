//
// Created by Magnus Krogh on 25/01/2026.
//

#pragma once
#include <memory>
#include <string>
#include <optional>

#include "Index.h"

using namespace std;

class StorageEngine {
public:
    StorageEngine();

    void set(const string& key, const string& value);

    optional<string> get(const string& key);

    bool remove(const string& key);

    void loadFromDisk(const string& filename);
    void saveToDisk(const string& filename) const;

private:
    unique_ptr<Index> index_;
};

