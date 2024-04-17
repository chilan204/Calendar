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

}

StudentModel *Controller::svModel()
{
    return &m_svModel;
}

DayModel *Controller::dayModel()
{
    return &m_dayModel;
}

void Controller::readStudentfromJson()
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
}

void Controller::readWorkingDayfromJson()
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

    QJsonArray svArray = m_data["ngay"].toArray();
    qDebug() << svArray;

    m_dayModel.initialize(m_data["ngay"].toArray());
}

void Controller::addStudent(QString addname, QString addcolor, QString tuition)
{
    foreach (QJsonValue item, m_data["student"].toArray()) {
        if (addcolor == item.toObject()["color"].toString()) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor;
    student["Tuition"] = tuition.toInt();

    QJsonArray arr = m_data["student"].toArray();
    arr.append(student);
    m_data["student"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    m_svModel.append(addname, addcolor, tuition.toInt());
}

void Controller::modifyStudent(QString addname, QString addcolor, QString addtuition, int index)
{
    foreach (QJsonValue item, m_data["student"].toArray()) {
        if ( addcolor !=item.toObject()["color"].toString() && addcolor == item.toObject()["color"].toString() ) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject student;
    student["Name"] = addname;
    student["Color"] = addcolor;
    student["Tuition"] = addtuition.toInt();

    QJsonArray arr = m_data["student"].toArray();
    arr[index] = student;
    m_data["student"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    m_svModel.modify(addname, addcolor, addtuition.toInt(), index);
}

void Controller::removeStudent(int index)
{
    QJsonArray arr = m_data["student"].toArray();
    arr.removeAt(index);
    m_data["student"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    m_svModel.remove(index);
}

void Controller::addWorkingday(QString day, QString month, QString year)
{
    QString str = year.remove(0,1) + month + day;
    QJsonArray arr = m_data["ngay"].toArray();
    arr.append(str);
    m_data["ngay"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    m_dayModel.append(str);
}

void Controller::removeWorkingday(QString removeday)
{
    //    remove(index);

    //    QJsonArray arr = m_data["student"].toArray();
    //    arr.removeAt(index);
    //    m_data["student"]= arr;

    //    QJsonDocument jsonDoc(m_data);

    //    QFile file(PATH_DATA);
    //    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    //        qDebug() << "Không thể mở tệp JSON";
    //        return;
    //    }
    //    file.write(jsonDoc.toJson());
    //    file.close();
}
