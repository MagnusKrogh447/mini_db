//
// Created by Magnus Krogh on 01/02/2026.
//

#include "SortedIndex.h"

using namespace std;

void SortedIndex::set(const string &key, const string &value) {
    data_[key] = value;
}

optional<string> SortedIndex::get(const string &key) const{
    auto it = data_.find(key);
    if (it == data_.end()) {
        return nullopt;
    }
    return it->second;
}

bool SortedIndex::remove(const string &key) {
    return data_.erase(key) > 0;
}

vector<pair<string, string>> SortedIndex::scan() const {
    vector<pair<string, string>> result;

    result.reserve(data_.size());

    for (const auto& [key,value] : data_) {
        result.emplace_back(key, value);
    }

    return result;
}