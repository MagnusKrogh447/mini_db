//
// Created by Magnus Krogh on 25/01/2026.
//

#include "StorageEngine.h"

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
