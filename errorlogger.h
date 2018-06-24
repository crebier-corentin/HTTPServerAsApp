#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <QObject>
#include <QMessageBox>
#include <QApplication>

class ErrorLogger : public QObject
{
    Q_OBJECT

    ErrorLogger(){};
public:
    static ErrorLogger* getInstance()
    {
        static ErrorLogger instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return &instance;
    }
    ErrorLogger(ErrorLogger const&)               = delete;
    void operator=(ErrorLogger const&)  = delete;

    void logAndExit(QString error);


signals:

public slots:
};

#endif // ERRORLOGGER_H
