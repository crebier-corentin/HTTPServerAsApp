#ifndef MANAGER_H
#define MANAGER_H

#include "config.h"
#include <QApplication>
#include <QStyle>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QObject>
#include <QTcpServer>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <iostream>

class Manager : public QObject
{
    Q_OBJECT

    QSystemTrayIcon trayIcon;
    QMenu menu;
    QProcess proccess;

    int port;

    //If port is 0 generate open port
    //Else use port specified
    int getOpenPort();

    void startServer();

public:
    explicit Manager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MANAGER_H
