#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "define.h"
#include "sinhvienmodel.h"
#include "daymodel.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    static Controller *getInstance();
    void initialize();

    SinhVienModel *svModel();
    DayModel *dayModel();
signals:
     void showNotifyPopUp(QString msg);

private:
    explicit Controller(QObject *parent = nullptr);
    SinhVienModel m_svModel;
    DayModel m_dayModel;
};

#endif // CONTROLLER_H
