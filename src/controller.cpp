#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    initialize();
    connect(&m_svModel, &SinhVienModel::showNotifyPopUp, this, &Controller::showNotifyPopUp);
}

Controller *Controller::getInstance()
{
    static Controller _self;
    return &_self;
}

void Controller::initialize()
{

}

SinhVienModel *Controller::svModel()
{
    return &m_svModel;
}
