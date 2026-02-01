//
// Created by Magnus Krogh on 01/02/2026.
//

#include "StorageIndex.h"

using namespace std;

void StorageIndex::set(const string &key, const string &value) {
    data_[key] = value;
}

optional<string> StorageIndex::get(const string &key) const{
    auto it = data_.find(key);
    if (it == data_.end()) {
        return nullopt;
    }
    return it->second;
}

bool StorageIndex::remove(const string &key) {
    return data_.erase(key) > 0;
}
