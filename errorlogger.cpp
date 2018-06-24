#include "errorlogger.h"



void ErrorLogger::logAndExit(QString error)
{
#ifdef DEV
    QMessageBox::critical(NULL, "Error", error);
#endif
    std::abort();
}
