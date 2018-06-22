#include "mainwindow.h"
#include "config.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);

    MainWindow w;

    Config::getInstance();

    return a.exec();
}
