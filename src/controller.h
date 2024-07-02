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
    Q_PROPERTY(QString monthStatistical     READ monthStatistical   NOTIFY monthStatisticalChanged)
    Q_PROPERTY(int maxWorkingDay     READ maxWorkingDay   NOTIFY maxWorkingDayChanged)

public:
    static Controller *getInstance();
    void initialize();
    void readDatafromJson();
    void writeDatafromJson();

    QString monthStatistical();
    int maxWorkingDay();

    StudentModel *svModel();

    //Home
    Q_INVOKABLE void modifyWorkingday(QDate workingday, QList<int> listcolor);
    Q_INVOKABLE QList<QString> getListColorDate(QDate workingday);

    //Infor
    Q_INVOKABLE void addStudent(QString addname, QString addcolor, QString tuition);
    Q_INVOKABLE void modifyStudent(QString addname, QString addcolor, QString addtuition, int index);
    Q_INVOKABLE void removeStudent(int index);

    //Statistical
    Q_INVOKABLE void changeMonthStatistical(bool isNext);
    Q_INVOKABLE int getWorkingDay(QString color);
    Q_INVOKABLE bool getColorDate(QDate workingday, QString color);

    //
signals:
    void monthStatisticalChanged();
    void showNotifyPopUp(QString msg);
    void workingdayChanged(QDate workingday);
    void maxWorkingDayChanged();

private:
    explicit Controller(QObject *parent = nullptr);
    StudentModel m_svModel;
    QList <QString> m_listDay;
    QJsonArray m_data;
    QDate m_monthStatistical;
    int m_maxWorkingDay;
};

#endif // CONTROLLER_H
