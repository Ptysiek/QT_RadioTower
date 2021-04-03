#pragma once

#include <QDebug>

class Program {
public:

    void execute() {
        auto userInput = getUserInput();
    }

private:
    QString getUserInput() {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        return line.trimmed().toUpper();
    }
};

