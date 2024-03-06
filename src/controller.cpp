#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    initialize();
}

Controller *Controller::getInstance()
{
    static Controller _self;
    return &_self;
}

void Controller::initialize()
{
    index = 0;
}
