#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent),  trayIcon(qApp->style()->standardIcon(QStyle::SP_FileIcon), this)
{
    trayIcon.setToolTip(Config::getInstance()->name);

    //Menu
    auto quitAction = menu.addAction("Quit");
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayIcon.setContextMenu(&menu);

}
