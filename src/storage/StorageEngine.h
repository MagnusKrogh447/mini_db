//
// Created by Magnus Krogh on 25/01/2026.
//

#pragma once
#include <string>
#include <optional>

#include <unordered_map>

using namespace std;

class StorageEngine {
public:
    void set(const string& key, const string& value);

    optional<string> get(const string& key);

    bool remove(const string& key);

    void loadFromDisk(const string& filename);
    void saveToDisk(const string& filename) const;

private:
    unordered_map<string, string> data_;
};

