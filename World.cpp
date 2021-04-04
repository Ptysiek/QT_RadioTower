#include "World.h"

size_t World::minRadioFrequency() const
{
    return _minRadioFrequency;
}

size_t World::maxRadioFrequency() const
{
    return _maxRadioFrequency;
}

World::World():
    _minRadioFrequency(75),
    _maxRadioFrequency(256),
    _matrixSize(20),
    _radio(),
    _tiles(initTiles()),
    _radioTowers(initRadioTowers())
{
    putRadioTowersOnTiles();
    giveRadioTowersChannelRepertuars();
    initRadio();
}

size_t World::size() const { return _matrixSize; }

Radio &World::radio() { return _radio; }

const Radio &World::radio() const { return _radio; }

const std::vector<std::vector<Tile> > &World::tiles() const { return _tiles; }

const Tile& World::tile(const size_t x, const size_t y) const {
    return _tiles.at(y).at(x);
}

bool World::setTile(const size_t x, const size_t y, std::shared_ptr<RadioTower> radioTower) {
    try {
        auto& choosenTile = _tiles.at(y).at(x);
        choosenTile._towersInRange.push_back(radioTower);
        return true;
    }
    catch (const std::out_of_range& e) {
        return false;
    }
}

const std::vector<std::shared_ptr<RadioTower> > &World::radioTowers() const { return _radioTowers; }

std::vector<std::vector<Tile> > World::initTiles() const {
    std::vector<std::vector<Tile>> rows(_matrixSize);
    for (auto& row : rows) {
        row.resize(_matrixSize);
    }
    return rows;
}

std::vector<std::shared_ptr<RadioTower>> World::initRadioTowers() const {
    const int smallRange = _matrixSize / 4;
    const int mediumRange = (_matrixSize * 2) / 3;
    const int fullRange = _matrixSize;

    return { std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(2, smallRange)),
                std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(2, smallRange)),
                std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(smallRange, mediumRange)),
                std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(smallRange, mediumRange)),
                std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(mediumRange, fullRange)),
                std::make_shared<RadioTower>(generateID(), random(0, fullRange), random(0, fullRange), random(mediumRange, fullRange)) };
}

void World::putRadioTowersOnTiles() {
    for (auto& radioTower : _radioTowers) {
        setTiles(radioTower);
    }
}

void World::giveRadioTowersChannelRepertuars() {
    for (auto& radioTower : _radioTowers) {
        const size_t quantity = random(2, 7);
        for (size_t i = 0; i < quantity; ++i) {
            const size_t frequency = random(_minRadioFrequency, _maxRadioFrequency);
            const std::string id = generateID();
            const std::string genre = _musicLabel.at(random(0, _musicLabel.size()));
            radioTower->addChannel({frequency, id, genre});
        }
    }
}

void World::initRadio() {
    const size_t x = static_cast<size_t>(random(0, _matrixSize));
    const size_t y = static_cast<size_t>(random(0, _matrixSize));
    _radio.move(x, y, this->tile(x, y));
    _radio.setFrequency(static_cast<size_t>(random(_minRadioFrequency, _maxRadioFrequency)));
}

std::string World::generateID() const {
    std::string result;
    result += randomChar('A', 'Z', 1);
    result += randomChar('A', 'Z', 1);
    result += randomChar('A', 'Z', 1);
    result += '-';
    result += std::to_string(random(0, 10));
    result += std::to_string(random(0, 10));
    result += std::to_string(random(0, 10));
    result += std::to_string(random(0, 10));
    return result;
}

char World::randomChar(char a, char b, size_t offset) const {
    return static_cast<char>(random(static_cast<int>(a), static_cast<int>(b) + offset));
}

int World::random(int a, int b) const {
    return QRandomGenerator::global()->bounded(a, b);
}

void World::setTiles(std::shared_ptr<RadioTower> radioTower) {
    const int startX = static_cast<int>(radioTower->x());
    const int startY = static_cast<int>(radioTower->y());
    const int range = static_cast<int>(radioTower->range());

    for (int row = startY - range; row < startY + range; ++row) {
        for (int col = startX - range; col < startX + range; ++col) {
            setTile(col, row, radioTower);
        }
    }
}
