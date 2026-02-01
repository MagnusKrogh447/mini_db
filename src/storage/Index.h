//
// Created by Magnus Krogh on 01/02/2026.
//

#pragma once

#include <string>
#include <optional>

using namespace std;

class Index {
public:
    virtual ~Index() = default;

    virtual void set(const string& key, const string& value) = 0;

    virtual optional<string> get(const string& key) const = 0;

    virtual bool remove(const string& key) = 0;
};