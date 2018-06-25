#include "manager.h"


Manager::Manager(QObject *parent) : QObject(parent),  trayIcon(Config::getInstance()->icon, this), proccess(this),
    port(getOpenPort())
{
    trayIcon.setToolTip(Config::getInstance()->name);

    //****//
    //Menu//
    //****//

    //Open
    auto openAction = menu.addAction("Open");
    connect(openAction, &QAction::triggered, [=]() {
        QDesktopServices::openUrl(QUrl("http://localhost:" + QString::number(port)));
    });

    //Quit
    auto quitAction = menu.addAction("Quit");
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));



    trayIcon.setContextMenu(&menu);
    trayIcon.show();

    //Show the menu when clicked
    connect(&trayIcon, &QSystemTrayIcon::activated, [=](QSystemTrayIcon::ActivationReason reason) {
        if(reason == QSystemTrayIcon::Trigger) {
            menu.exec(QCursor::pos());
        }
    });

    startServer();

}

int Manager::getOpenPort()
{

    if(Config::getInstance()->port == 0) {
        //Generate port
        QTcpServer server;
        server.listen();

        int p = server.serverPort();
        server.close();

        return p;


    }
    else {
        return Config::getInstance()->port;
    }
}

void Manager::startServer()
{
    //Start proccess with port as first argument
    QStringList arg = Config::getInstance()->args;
    arg << QString::number(port);

    proccess.start(Config::getInstance()->program, arg);

    //Stop proccess when app close
    connect(qApp, &QApplication::aboutToQuit, [=]() {
        proccess.close();
    });

    //If dev copy output to console
#ifdef DEV
    connect(&proccess, &QProcess::readyRead, [=]() {
        std::cout << proccess.readAll().toStdString();
    });
#endif
}
