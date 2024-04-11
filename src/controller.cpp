#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    initialize();
}

Controller *Controller::getInstance()
{
    static Controller _self;
    return &_self;
}

void Controller::initialize()
{
    index = 0;
}

controller::controller(QObject *parent) : QObject(parent)
{
    readDatafromJson();
}

void controller::readDatafromJson()
{
    QFile file(":/data/data.json");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qDebug() << "Không thể phân tích JSON";
    }

    QJsonObject jsonObject = jsonDoc.object();

    m_sinhvienArray = jsonObject["sinhvien"].toArray();

    foreach(const QJsonValue &value, m_sinhvienArray){
        sinhvien sv;
        sv.name = value.toObject()["Name"].toString();
        sv.color = value.toObject()["Color"].toString();
        sv.tuition = value.toObject()["Tuition"].toInt();
        m_listSV.append(sv);
    }

    m_name = m_sinhvienArray[0].toObject()["Name"].toString();
}

QString controller::name()
{
    return m_name;
}

void controller::setName(QString name)
{
    if (m_name == name) return;
    m_name = name;
    emit nameChanged();
}

void controller::setNamefromUI(int index, QString name)
{
    setName(name);
    m_listSV[index].name = name;
    foreach(const sinhvien &value, m_listSV){
        qDebug() << value.name << " - " << value.color;
    }
}

int controller::getLength()
{
    return m_listSV.length();
}

QVariantMap controller::getData(int index) const {
    QVariantMap itemMap;
    if (index >= 0 && index < m_listSV.size()) {
        const sinhvien &item = m_listSV[index];
        itemMap["name"] = item.name;
        itemMap["color"] = item.color;
        itemMap["tuition"] = item.tuition;
    }
    return itemMap;

}

void controller::addSV(QString name, QString color, int tuition)
{
    m_listSV.append(sinhvien(name, color, tuition));
    qDebug() << m_listSV.length();
    addSVjson();
}

void controller::addSVjson()
{
        QJsonObject jsonObject;

        QJsonObject sinhvien;
        sinhvien["Name"] = "A";
        sinhvien["Color"] = "Green";
        sinhvien["Tuition"] = 200000;

        m_sinhvienArray.append(sinhvien);

        jsonObject["sinhvien"] = m_sinhvienArray;

        QJsonDocument jsonDoc(jsonObject);

        QFile file("C:/Users/NCT/Desktop/Lân/Calendar/data/data.json");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Không thể mở tệp JSON";
            return;
        }

        file.write(jsonDoc.toJson());

        file.close();
}
