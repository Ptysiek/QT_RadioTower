#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream stream(stdin);
    QString line = stream.readLine();
    qDebug() << line.trimmed();

    return a.exec();
}
