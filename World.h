#pragma once

#include <exception>
#include <memory>
#include <QRandomGenerator>
#include <vector>

#include "MusicGenreFactory.h"
#include "Radio.h"
#include "RadioTower.h"
#include "Tile.h"


class World {
    MusicGenreFactory _musicLabel;
    const size_t _minRadioFrequency;
    const size_t _maxRadioFrequency;
    const size_t _matrixSize;
    Radio _radio;
    std::vector<std::vector<Tile>> _tiles;
    std::vector<std::shared_ptr<RadioTower>> _radioTowers;

public:
    World();    
    size_t minRadioFrequency() const;
    size_t maxRadioFrequency() const;
    size_t size() const;
    Radio& radio();
    const Radio& radio() const;
    const std::vector<std::vector<Tile>>& tiles() const;
    const Tile& tile(size_t x, size_t y) const;
    bool setTile(size_t x, size_t y, std::shared_ptr<RadioTower> radioTower);
    const std::vector<std::shared_ptr<RadioTower>>& radioTowers() const;

private:
    std::vector<std::vector<Tile>> initTiles() const;
    std::vector<std::shared_ptr<RadioTower>> initRadioTowers() const;
    void putRadioTowersOnTiles();
    void giveRadioTowersChannelRepertuars();
    void initRadio();
    std::string generateID() const;
    char randomChar(char a, char b, size_t offset = 0) const;
    int random(int a, int b) const;
    void setTiles(std::shared_ptr<RadioTower> radioTower);
};
