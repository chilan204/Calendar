#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include "define.h"
#include "studentmodel.h"
#include "workingdaymodel.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    static Controller *getInstance();
    void initialize();
    void readDatafromJson();
    void writeDatafromJson();

    StudentModel *svModel();
    DayModel *dayModel();

    Q_INVOKABLE void addStudent(QString addname, QString addcolor, QString tuition);
    Q_INVOKABLE void modifyStudent(QString addname, QString addcolor, QString addtuition, int index);
    Q_INVOKABLE void removeStudent(int index);

    Q_INVOKABLE void modifyWorkingday(QDate workingday, QList<int> listcolor);
    Q_INVOKABLE QList<QString> getListColorDate(QDate workingday);

signals:
     void showNotifyPopUp(QString msg);
     void workingdayChanged(QDate workingday);

private:
    explicit Controller(QObject *parent = nullptr);
    StudentModel m_svModel;
    DayModel m_dayModel;
    QJsonObject m_data;
};

#endif // CONTROLLER_H
