#include "Map.h"

void Map::lookup(const World &world) const {
    drawMap(world);
    drawRadioInfo(world);
}

void Map::drawMap(const World &world) const {
    for (const auto& row : world.tiles()) {
        QString str;
        for (const auto& tile : row) {
            str += " ";
            str += QString::number(tile.contentSize());
        }
        qInfo() << str;
    }
}

void Map::drawRadioInfo(const World &world) const {
    const auto& radio = world.radio();
    const auto& tile = world.tile(radio.x(), radio.y());
    const size_t numberOfStations = tile.contentSize();
    qInfo() << "Current radio position: [" << radio.x() << ", " << radio.y() << "]";
    qInfo() << "Number of available stations: [" << numberOfStations << "]";
}
