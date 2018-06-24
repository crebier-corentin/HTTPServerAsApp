#include "config.h"
#include "manager.h"
#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //If DEV show error message in dialog

    a.setQuitOnLastWindowClosed(false);

    Config c;
    a.setApplicationDisplayName(c.name);

    Manager m;

    return a.exec();
}
