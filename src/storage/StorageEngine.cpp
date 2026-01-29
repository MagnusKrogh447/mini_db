//
// Created by Magnus Krogh on 25/01/2026.
//

#include "StorageEngine.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

//Store or overwrite a key/value pair in the internal map
void StorageEngine::set(const std::string &key, const std::string &value) {
    data_[key] = value;
}

//Retrieve a value by key. Returns empty optional if key doesn't exist.
std::optional<std::string> StorageEngine::get(const std::string& key) {
    auto it = data_.find(key);
    if (it == data_.end()) {
        return std::nullopt;
    }
    return it->second;
}

// Remove a key/value pair. Returns true if something was erased.
bool StorageEngine::remove(const std::string &key) {
    return data_.erase(key) > 0;
}

//Disk storage to save data on reboot
void StorageEngine::loadFromDisk(const std::string& filename) {
    //Attempt to open file for reading
    std::ifstream file(filename);
    if (!file.is_open()) {
        //If the file cant be opened, give warning and bail out fast.
        std::cerr << "Could not open file " << filename << " for reading.\n";
    }
    //Clear any existing memory before loading new
    data_.clear();

    std::string line;
    //Read file line by line
    while (std::getline(file, line)) {
        //Look for key and value separator
        auto pos = line.find('=');
        //If separator not found, skip since invalid format
        if (pos != std::string::npos) continue;

        //Extract the key
        std::string key = line.substr(0, pos);
        //Extract the value
        std::string value = line.substr(pos + 1);
        //Store the key and value pair in map
        data_[key] = value;
    }
}
