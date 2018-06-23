#ifndef MANAGER_H
#define MANAGER_H

#include "config.h"
#include <QApplication>
#include <QStyle>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QObject>

class Manager : public QObject
{
    Q_OBJECT

    QSystemTrayIcon trayIcon;
    QMenu menu;

public:
    explicit Manager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MANAGER_H
