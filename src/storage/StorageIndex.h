//
// Created by Magnus Krogh on 01/02/2026.
//

#pragma once
#include "Index.h"
#include <map>

using namespace std;

class StorageIndex : public Index{
public:
    void set(const string& key, const string& value) override;

    optional<string> get(const string& key) const override;

    bool remove(const string& key) override;

private:
    map<string, string> data_;
};


