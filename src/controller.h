#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "define.h"
#include "sinhvienmodel.h"

class Controller : public QObject
{
    Q_OBJECT

public:
     static Controller *getInstance();
     void initialize();

     SinhVienModel *svModel();

signals:
     void showNotifyPopUp(QString msg);

private:
    explicit Controller(QObject *parent = nullptr);
    SinhVienModel m_svModel;
};

#endif // CONTROLLER_H
