#include "config.h"

Config* Config::instance = nullptr;

Config::Config(QObject* parent) : QObject(parent)
{

    //Check if instance exist
    if (Config::instance) {
        throw std::logic_error("Instance of Config already created");
    }

    else {
        Config::instance = this;

        loadConfigFile();
    }

}

Config* Config::getInstance()
{
    //Check if instance exist
    if (Config::instance) {

        return Config::instance;
    }

    else {
        throw std::logic_error("No instance of Config created");
    }
}

void Config::loadConfigFile()
{
    //Check if file exist
    QFile file("HTTPServerAsAppConfig.json");

    if(!file.exists()) {
        ErrorLogger::getInstance()->logAndExit("Cannot find HTTPServerAsAppConfig.json");
    }

    //Parse Json
    file.open(QFile::ReadOnly | QFile::Text);

    QJsonParseError docError;

    auto doc = QJsonDocument::fromJson(file.readAll(), &docError);
    if(doc.isNull()) {
        ErrorLogger::getInstance()->logAndExit(QString("Json Parse error : " + docError.errorString()));
    }

    //Check if is right format
    verifyConfigFile(doc);

    //Copy data from file to object
    name = doc["name"].toString();
    port = doc["port"].toDouble();

    //Program and args
    QStringList str = doc["command"].toString().split(QRegExp("\\s+"));
    program = str.takeFirst();
    args = str;

    QString iconStr = doc["icon"].toString();

    //Icon
    //If starts with SP_ use style icon
    if(iconStr.startsWith("SP_")) {
        //QString to Enum
        auto enumValue = QMetaEnum::fromType<QStyle::StandardPixmap>().keysToValue(iconStr.toStdString().c_str());
        icon = qApp->style()->standardIcon(static_cast<QStyle::StandardPixmap>(enumValue));

    }
    else {
        icon = QIcon(iconStr);
    }

    //Check if icon is valid
    if(icon.isNull()) {
         ErrorLogger::getInstance()->logAndExit("Icon not found");
    }

}

void Config::verifyConfigFile(QJsonDocument doc)
{

    if(!doc.isObject()) {
        ErrorLogger::getInstance()->logAndExit("Wrong format, is not an object (HTTPServerAsAppConfig.json)");
    }

    if(!doc["name"].isString()) {
        ErrorLogger::getInstance()->logAndExit("Missing name (HTTPServerAsAppConfig.json)");
    }

    if(!doc["port"].isDouble()) {
        ErrorLogger::getInstance()->logAndExit("Missing port (HTTPServerAsAppConfig.json)");
    }

    if(!doc["command"].isString()) {
        ErrorLogger::getInstance()->logAndExit("Missing command (HTTPServerAsAppConfig.json)");
    }

    if(!doc["icon"].isString()) {
        ErrorLogger::getInstance()->logAndExit("Missing icon (HTTPServerAsAppConfig.json)");
    }
}
