#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>

/*
Contains the config in HTTPServerAsAppConfig.json
*/
class Config : public QObject
{
    Q_OBJECT

     static Config* instance;
public:
    explicit Config(QObject *parent = nullptr);
    static Config* getInstance();

signals:

public slots:
};

#endif // CONFIG_H
