#include "Radio.h"

Radio::Radio(size_t minFrequency, size_t maxFrequency):
    _minRadioFrequency(minFrequency),
    _maxRadioFrequency(maxFrequency),
    _x(),
    _y(),
    _currentFrequency(),
    _isOn(false),
    _channels()
{}

size_t Radio::x() const { return _x; }

size_t Radio::y() const { return _y; }

size_t Radio::frequency() const { return _currentFrequency; }

bool Radio::isOn() const { return _isOn; }

void Radio::setFrequency(const size_t frequency) { _currentFrequency = frequency; }

bool Radio::autoSetFrequency() {
    if (!_isOn) {
        return false;
    }
    if (_channels.empty()) {
        return false;
    }
    const size_t newFrequency = _channels.begin()->second._frequency;
    setFrequency(newFrequency);
    return true;
}

bool Radio::turnRadio() {
    _isOn = !_isOn;
    return _isOn;
}

void Radio::move(const size_t x, const size_t y, const Tile &tile) {
    _x = x;
    _y = y;
    _channels.clear();
    disconnectAll();
    _lastlyConnected = tile;
    connectAll();
}

std::string Radio::play() const {
    if (!_isOn) {
        return "...";
    }
    return browseChannels();
}

void Radio::onSignal(const std::vector<Channel> &channels) {
    for (const auto& channel : channels) {
        _channels[channel._id] = channel;
    }
}

std::string Radio::browseChannels() const {
    std::string output = "white-noise";
    for (const auto& [ID, channel] : _channels) {
        if ((_currentFrequency -2 < channel._frequency) && (_currentFrequency +2 > channel._frequency)) {
            return "[channel: " + ID + "]  " + channel._genre;
        }
        if ((_currentFrequency -5 < channel._frequency) && (_currentFrequency +5 > channel._frequency)) {
            output = "distorted-sound";
        }
    }
    return output;
}

void Radio::disconnectAll() {
    for (auto& radioTower : _lastlyConnected._towersInRange) {
        if (radioTower.expired()) {
            continue;
        }
        this->disconnect(std::shared_ptr<RadioTower>{radioTower}.get(), &RadioTower::signal, this, &Radio::onSignal);
    }
}

void Radio::connectAll() {
    for (auto& radioTower : _lastlyConnected._towersInRange) {
        if (radioTower.expired()) {
            continue;
        }
        this->connect(std::shared_ptr<RadioTower>{radioTower}.get(), &RadioTower::signal, this, &Radio::onSignal);
    }
}
