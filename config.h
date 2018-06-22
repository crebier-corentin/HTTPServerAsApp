#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>

/*
Contains the config in
*/
class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONFIG_H
