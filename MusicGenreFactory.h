#pragma once
#include <string>
#include <vector>

class MusicGenreFactory {
    static std::vector<std::string> _data;

public:
    static size_t size();
    static std::string at(size_t index);
};

