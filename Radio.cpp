#include "Radio.h"

Radio::Radio():
    _x(),
    _y(),
    _currentFrequency(),
    _isOn(false)
{}

size_t Radio::x() const { return _x; }

size_t Radio::y() const { return _y; }

size_t Radio::frequency() const { return _currentFrequency; }

bool Radio::isOn() const { return _isOn; }

void Radio::setX(const size_t x) { _x = x; }

void Radio::setY(const size_t y) { _y = y; }

void Radio::setFrequency(const size_t frequency) { _currentFrequency = frequency; }
