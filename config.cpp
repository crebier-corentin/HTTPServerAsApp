#include "config.h"
#include <iostream>

Config* Config::instance = nullptr;

Config::Config(QObject *parent) : QObject(parent)
{
    Config::instance = this;
}

Config* Config::getInstance()
{
    if(Config::instance) {

        return Config::instance;
    }

    else {
        std::cerr << "No instance of Config created";
        std::abort();
    }
}
