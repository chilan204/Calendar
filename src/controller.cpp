#include "controller.h"
#include "set"

Controller::Controller(QObject *parent) : QObject(parent)
{
    initialize();
    connect(&m_svModel, &StudentModel::showNotifyPopUp, this, &Controller::showNotifyPopUp);
}

Controller *Controller::getInstance()
{
    static Controller _self;
    return &_self;
}

void Controller::initialize()
{
    readDatafromJson();
    m_monthStatistical = QDate::currentDate();
    m_maxWorkingDay = 0;
}

StudentModel *Controller::svModel()
{
    return &m_svModel;
}

void Controller::readDatafromJson()
{
    QFile file(PATH_DATA);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument jsonData = QJsonDocument::fromJson(data);
    if (jsonData.isNull()) {
        qDebug() << "Không thể phân tích JSON";
    }

    m_data = jsonData.array();

    m_svModel.initialize(m_data);
}

void Controller::writeDatafromJson()
{
    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();
}

QString Controller::monthStatistical(){
    return m_monthStatistical.toString("MMMM, yyyy");
}

int Controller::maxWorkingDay()
{
    return m_maxWorkingDay;
}

void Controller::addStudent(QString addname, QString addcolor, QString tuition)
{
    foreach (QJsonValue item, m_data) {
        if (addcolor.toLower() == item.toObject()["Color"].toString().toLower()) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor.toLower();
    student["Tuition"] = tuition.toInt();
    student["WorkingDay"] = QJsonObject();

    m_data.append(student);

    writeDatafromJson();
    m_svModel.append(addname, addcolor, tuition.toInt());
}

void Controller::modifyStudent(QString addname, QString addcolor, QString addtuition, int index)
{
    foreach (QJsonValue item, m_data) {
        if (addcolor.toLower() != m_data[index].toObject()["Color"].toString().toLower() &&
                addcolor.toLower() == item.toObject()["Color"].toString().toLower()){
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor.toLower();
    student["Tuition"] = addtuition.toInt();
    student["WorkingDay"] = m_data[index].toObject()["WorkingDay"];

    m_data[index] = student;

    writeDatafromJson();
    m_svModel.modify(addname, addcolor, addtuition.toInt(), index);
}

void Controller::removeStudent(int index)
{
    m_data.removeAt(index);

    writeDatafromJson();
    m_svModel.remove(index);
}

void Controller::changeMonthStatistical(bool isNext)
{
    m_monthStatistical = m_monthStatistical.addMonths(isNext ? 1 : -1);
    m_maxWorkingDay = 0;
    emit maxWorkingDayChanged();
    emit monthStatisticalChanged();
}

void Controller::modifyWorkingday(QDate workingday, QList<int> listcolor)
{
    QString year = QString::number(workingday.year());
    QString month = QString::number(workingday.month());

    for(int i = 0; i < m_data.size(); i++) {
        QJsonObject student = m_data[i].toObject();
        QJsonObject workingDay = student["WorkingDay"].toObject();
        QJsonObject yearObj = workingDay[year].toObject();
        QJsonArray monthArr = yearObj[month].toArray();

        if(listcolor.contains(i)) {
            std::set<int> arrSet;
            foreach(QJsonValue item, monthArr){
                arrSet.insert(item.toInt());
            }
            arrSet.insert(workingday.day());
            monthArr = QJsonArray();
            foreach(int item, arrSet){
                monthArr.append(item);
            }
        }
        else {
            for(int j = 0; j < monthArr.size(); j++) {
                if(monthArr[j] == workingday.day())
                    monthArr.removeAt(j);
            }
        }

        yearObj[month] = monthArr;
        workingDay[year] = yearObj;
        student["WorkingDay"] = workingDay;
        m_data[i] = student;
    }

    writeDatafromJson();
    emit workingdayChanged(workingday);
}

QList<QString> Controller::getListColorDate(QDate workingday)
{
    QList<QString> listColor;
    
    for(int i = 0; i < m_data.size(); i++) {
        if(m_data[i].toObject()["WorkingDay"].toObject()[QString::number(workingday.year())].toObject()
                [QString::number(workingday.month())].toArray().contains(workingday.day())) {
            listColor.append(m_data[i].toObject()["Color"].toString());
        }
    }
    return listColor;
}

int Controller::getWorkingDay(QString color)
{
    int count = 0;
    foreach (QJsonValue item, m_data) {
        if (color.toLower() == item.toObject()["Color"].toString().toLower()){
            count = item.toObject()["WorkingDay"].toObject()[QString::number(m_monthStatistical.year())].toObject()[QString::number(m_monthStatistical.month())].toArray().size();
        }
    }

    if(count > m_maxWorkingDay) {
        m_maxWorkingDay = count;
        emit maxWorkingDayChanged();
    }

    return count;
}

bool Controller::getColorDate(QDate workingday, QString color)
{
    if(workingday.month() != m_monthStatistical.month()){
        return false;
    }

    for(int i = 0; i < m_data.size(); i++) {
        if(color == m_data[i].toObject()["Color"].toString() && m_data[i].toObject()["WorkingDay"].toObject()[QString::number(workingday.year())].toObject()
                [QString::number(workingday.month())].toArray().contains(workingday.day())) {
            return true;
        }
    }
    return false;
}
