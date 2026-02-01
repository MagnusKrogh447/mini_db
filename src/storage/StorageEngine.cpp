//
// Created by Magnus Krogh on 25/01/2026.
//

#include "StorageEngine.h"

#include <filesystem>
#include <fstream>
#include "SortedIndex.h"
#include <iostream>

using namespace std;

StorageEngine::StorageEngine()
    : index_(make_unique<SortedIndex>()){}


//Store or overwrite a key/value pair in the internal map
void StorageEngine::set(const string &key, const string &value) {
    index_->set(key, value);
}

//Retrieve a value by key. Returns empty optional if key doesn't exist.
optional<string> StorageEngine::get(const string& key) {
    return index_->get(key);
}

// Remove a key/value pair. Returns true if something was erased.
bool StorageEngine::remove(const string &key) {
    return index_->remove(key);
}

//Disk storage to save data on reboot
void StorageEngine::loadFromDisk(const string& filename) {
    //Attempt to open file for reading
    ifstream file(filename);
    if (!file.is_open()) {
        //If the file cant be opened, give warning and bail out fast.
        cerr << "Could not open file " << filename << " for reading.\n";
    }

    string line;
    //Read file line by line
    while (getline(file, line)) {
        //Look for key and value separator
        auto pos = line.find('=');
        //If separator not found, skip since invalid format
        if (pos == string::npos) continue;

        //Extract the key
        string key = line.substr(0, pos);
        //Extract the value
        string value = line.substr(pos + 1);
        //Store the key and value pair in map
        index_ -> set(key, value);
    }
}

void StorageEngine::saveToDisk(const string &filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Warning could not open" << filename << "for writing .\n";
        return;
    }

    for (const auto& [key, value] : index_->scan()) {
        file << key << "=" << value << "\n";
    }
}
