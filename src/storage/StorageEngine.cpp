//
// Created by Magnus Krogh on 25/01/2026.
//

#include "StorageEngine.h"

void StorageEngine::set(const std::string &key, const std::string &value) {}

std::optional<std::string> StorageEngine::get(const std::string& key) {
    return std::nullopt;
}

bool StorageEngine::remove(const std::string &key) {
    return false;
}
