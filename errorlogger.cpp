#include "errorlogger.h"

void ErrorLogger::logAndExit(QString error)
{
    QMessageBox::critical(NULL, "Error", error);
    std::abort();
}
