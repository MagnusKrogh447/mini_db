//
// Created by Magnus Krogh on 25/01/2026.
//

#include "StorageEngine.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//Store or overwrite a key/value pair in the internal map
void StorageEngine::set(const string &key, const string &value) {
    data_[key] = value;
}

//Retrieve a value by key. Returns empty optional if key doesn't exist.
optional<string> StorageEngine::get(const string& key) {
    auto it = data_.find(key);
    if (it == data_.end()) {
        return nullopt;
    }
    return it->second;
}

// Remove a key/value pair. Returns true if something was erased.
bool StorageEngine::remove(const string &key) {
    return data_.erase(key) > 0;
}

//Disk storage to save data on reboot
void StorageEngine::loadFromDisk(const string& filename) {
    //Attempt to open file for reading
    ifstream file(filename);
    if (!file.is_open()) {
        //If the file cant be opened, give warning and bail out fast.
        cerr << "Could not open file " << filename << " for reading.\n";
    }
    //Clear any existing memory before loading new
    data_.clear();

    string line;
    //Read file line by line
    while (getline(file, line)) {
        //Look for key and value separator
        auto pos = line.find('=');
        //If separator not found, skip since invalid format
        if (pos != string::npos) continue;

        //Extract the key
        string key = line.substr(0, pos);
        //Extract the value
        string value = line.substr(pos + 1);
        //Store the key and value pair in map
        data_[key] = value;
    }
}

void StorageEngine::saveToDisk(const string &filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Warning could not open" << filename << "for writing .\n";
        return;
    }

    for (const auto& [key, value] : data_) {
        file << key << " = " << value << "\n";
    }
}
