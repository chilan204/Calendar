#include "controller.h"

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
}

StudentModel *Controller::svModel()
{
    return &m_svModel;
}

DayModel *Controller::dayModel()
{
    return &m_dayModel;
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

    m_data = jsonData.object();

    m_svModel.initialize(m_data["student"].toArray());
    m_dayModel.initialize(m_data["workingDay"].toArray());
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

void Controller::addStudent(QString addname, QString addcolor, QString tuition)
{
    foreach (QJsonValue item, m_data["student"].toArray()) {
        if (addcolor.toLower() == item.toObject()["Color"].toString().toLower()) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor.toLower();
    student["Tuition"] = tuition.toInt();

    QJsonArray arr = m_data["student"].toArray();
    arr.append(student);
    m_data["student"]= arr;

    writeDatafromJson();
    m_svModel.append(addname, addcolor, tuition.toInt());
}

void Controller::modifyStudent(QString addname, QString addcolor, QString addtuition, int index)
{
    foreach (QJsonValue item, m_data["student"].toArray()) {
        if (addcolor.toLower() != m_data["student"].toArray()[index].toObject()["Color"].toString().toLower() &&
                addcolor.toLower() == item.toObject()["Color"].toString().toLower()){
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor.toLower();
    student["Tuition"] = addtuition.toInt();

    QJsonArray arr = m_data["student"].toArray();
    arr[index] = student;
    m_data["student"]= arr;

    writeDatafromJson();
    m_svModel.modify(addname, addcolor, addtuition.toInt(), index);
}

void Controller::removeStudent(int index)
{
    QJsonArray arr = m_data["student"].toArray();
    arr.removeAt(index);
    m_data["student"]= arr;

    writeDatafromJson();
    m_svModel.remove(index);
}

void Controller::modifyWorkingday(QDate workingday, QList<int> listcolor)
{
    QString year = QString::number(workingday.year());
    QString month = QString::number(workingday.month());
    QJsonObject obj = m_data["workingDay"].toObject();
    QJsonObject objYear = obj[year].toObject();
    QJsonArray arrMonth = objYear[month].toArray();
    qDebug() << arrMonth;

    if(arrMonth.isEmpty())
        for (int i = 0; i < m_data["student"].toArray().size(); i++) {
            QJsonArray arr;
            arrMonth.append(arr);
        }

    for(int i = 0; i < m_data["student"].toArray().size(); i++) {
        bool check = false;

        foreach(int j, listcolor) {
            if(i == j) {
                check = true;
                break;
            }
        }

        if(check) {
            QJsonArray arr = arrMonth[i].toArray();
            if(!arr.contains(workingday.day())) {
                arr.append(workingday.day());
                arrMonth[i] = arr;
            }
        } else {
            QJsonArray arr = arrMonth[i].toArray();
            for(int j = 0; j < arrMonth[i].toArray().size(); j++)
                if(arr[j].toInt() == workingday.day())
                    arr.removeAt(j);
            arrMonth[i] = arr;
        }
    }

    objYear[month] = arrMonth;
    obj[year] = objYear;
    m_data["workingDay"] = obj;

    writeDatafromJson();
    //m_dayModel.append(workingday);
}

QList<QString> Controller::getListColorDate(QDate workingday)
{
    QString year = QString::number(workingday.year());
    QString month = QString::number(workingday.month());
    QString day = QString::number(workingday.day());
    QJsonObject obj = m_data["workingDay"].toObject();
    QJsonObject objYear = obj[year].toObject();
    QJsonArray arrMonth = objYear[month].toArray();
    QList<QString> arr;

    if(arrMonth.isEmpty())
        for (int i = 0; i < m_data["student"].toArray().size(); i++) {
            QJsonArray arr;
            arrMonth.append(arr);
        }
    
    for(int i = 0; i < m_data["student"].toArray().size(); i++) {
        foreach(int j, m_data["student"].toArray()[i]) {
            if(j == day) {
                arr.push_back(m_data["student"].toArray()[i].toObject()["Color"].toString().toLower());
                        break;
            }
        }
    }
    qDebug() << arr;
    return arr;
}
