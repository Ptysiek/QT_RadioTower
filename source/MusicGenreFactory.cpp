#include "MusicGenreFactory.h"

std::vector<std::string> MusicGenreFactory::_data {
    "pop",
    "rock",
    "metal",
    "blues",
    "jezz",
    "soul",
    "reggae",
    "punk",
    "electronic",
    "funk"
};

size_t MusicGenreFactory::size() { return _data.size(); }

std::string MusicGenreFactory::at(size_t index) { return _data.at(index); }
