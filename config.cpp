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
