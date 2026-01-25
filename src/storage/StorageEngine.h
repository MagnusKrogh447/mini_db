//
// Created by Magnus Krogh on 25/01/2026.
//

#ifndef MINI_DB_STORAGEENGINE_H
#define MINI_DB_STORAGEENGINE_H

#pragma once
#include <string>
#include <optional>

#include <unordered_map>

class StorageEngine {
public:
    void set(const std::string& key, const std::string& value);

    std::optional<std::string> get(const std::string& key);

    bool remove(const std::string& key);

private:
    std::unordered_map<std::string, std::string> data_;
};

#endif //MINI_DB_STORAGEENGINE_H