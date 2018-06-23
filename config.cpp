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
        throw std::runtime_error("Cannot find HTTPServerAsAppConfig.json");
    }

    //Parse Json
    file.open(QFile::ReadOnly | QFile::Text);

    QJsonParseError docError;

    auto doc = QJsonDocument::fromJson(file.readAll(), &docError);
    if(doc.isNull()) {
        throw std::runtime_error(QString("Json Parse error : " + docError.errorString()).toStdString());
    }

    //Check if is right format
    verifyConfigFile(doc);

    //Copy data from file to object
    name = doc["name"].toString();
    port = doc["port"].toDouble();
    command = doc["command"].toString();

    emit loaded();
}

void Config::verifyConfigFile(QJsonDocument doc)
{

    if(!doc.isObject()) {
        throw std::runtime_error("Wrong format : Is not object (HTTPServerAsAppConfig.json)");
    }

    if(!doc["name"].isString()) {
        throw std::runtime_error("Missing name (HTTPServerAsAppConfig.json)");
    }

    if(!doc["port"].isDouble()) {
        throw std::runtime_error("Missing port (HTTPServerAsAppConfig.json)");
    }

    if(!doc["command"].isString()) {
        throw std::runtime_error("Missing command (HTTPServerAsAppConfig.json)");
    }
}
