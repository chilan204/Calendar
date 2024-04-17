#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "define.h"
#include "studentmodel.h"
#include "workingdaymodel.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    static Controller *getInstance();
    void initialize();
    void readStudentfromJson();
    void readWorkingDayfromJson();

    StudentModel *svModel();
    DayModel *dayModel();

    Q_INVOKABLE void addStudent(QString addname, QString addcolor, QString tuition);
    Q_INVOKABLE void modifyStudent(QString addname, QString addcolor, QString addtuition, int index);
    Q_INVOKABLE void removeStudent(int index);
    Q_INVOKABLE void addWorkingday(QString day, QString month, QString year);
    Q_INVOKABLE void removeWorkingday(QString removeday);

signals:
     void showNotifyPopUp(QString msg);

private:
    explicit Controller(QObject *parent = nullptr);
    StudentModel m_svModel;
    DayModel m_dayModel;
    QJsonObject m_data;
};

#endif // CONTROLLER_H
