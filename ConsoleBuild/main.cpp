#include <QCoreApplication>

#include "../source/Program.h"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    while (true) {
        Program program;
        if (!program.execute()) {
            break;
        }
    }
    return a.exec();
}
