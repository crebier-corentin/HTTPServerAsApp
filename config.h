#ifndef CONFIG_H
#define CONFIG_H

#include "errorlogger.h"

#include <QApplication>
#include <QStyle>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QMetaEnum>
#include <QIcon>
#include <QDebug>


/*
Contains the config in HTTPServerAsAppConfig.json
*/
class Config : public QObject
{
    Q_OBJECT

     static Config* instance;

     void loadConfigFile();
     void verifyConfigFile(QJsonDocument doc);
public:
    explicit Config(QObject *parent = nullptr);
    static Config* getInstance();

    QString name;
    int port;
    QString program;
    QStringList args;

    QIcon icon;

signals:

public slots:
};

#endif // CONFIG_H
