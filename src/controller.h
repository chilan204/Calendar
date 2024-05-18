#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include <QDir>
#include "define.h"
#include "studentmodel.h"

class Controller : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString monthStatistical READ monthStatistical   WRITE SetMonthStatistical   NOTIFY monthStatisticalChanged)
public:
    static Controller *getInstance();
    void initialize();
    void readDatafromJson();
    void writeDatafromJson();

    QString monthStatistical();

    StudentModel *svModel();
    //Home
    Q_INVOKABLE void modifyWorkingday(QDate workingday, QList<int> listcolor);
    Q_INVOKABLE QList<QString> getListColorDate(QDate workingday);
    //Infor
    Q_INVOKABLE void addStudent(QString addname, QString addcolor, QString tuition);
    Q_INVOKABLE void modifyStudent(QString addname, QString addcolor, QString addtuition, int index);
    Q_INVOKABLE void removeStudent(int index);
    //Statistical
    Q_INVOKABLE int getWorkingDay(QDate workingday);

    //
signals:
     void showNotifyPopUp(QString msg);
     void workingdayChanged(QDate workingday);

private:
    explicit Controller(QObject *parent = nullptr);
    StudentModel m_svModel;
    QList <QString> m_listDay;
    QJsonObject m_data;
    QString m_monthStatistical;
};

#endif // CONTROLLER_H
