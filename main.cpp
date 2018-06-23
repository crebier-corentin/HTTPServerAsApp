#include "config.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);

    Config c;

    return a.exec();
}
