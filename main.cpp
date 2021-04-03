#include <QCoreApplication>

#include "Program.h"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Program program;
    program.execute();

    return a.exec();
}
