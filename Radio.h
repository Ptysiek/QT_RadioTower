#pragma once

#include <QObject>

class Radio : public QObject {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;

public:
    Radio();

    size_t x() const;
    size_t y() const;
    size_t frequency() const;
    bool isOn() const;

    void setX(const size_t x);
    void setY(const size_t y);
    void setFrequency(const size_t frequency);
};

