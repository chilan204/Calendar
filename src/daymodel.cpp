#include "daymodel.h"

DayModel::DayModel(QObject *parent) : QAbstractListModel(parent)
{
    readDatafromJson();
}

int DayModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listDay.count();
}

QVariant DayModel::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid() || index.row() >= m_listDay.count())
//        return QVariant();

//    const SinhVien &item = m_listSinhVien[index.row()];

//    switch (role) {
//    case NameRole:
//        return item.name;
//    case ColorRole:
//        return item.color;
//    case TuitionRole:
//        return item.tuition;
//    default:
//        return QVariant();
//    }
}

void DayModel::readDatafromJson()
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

    foreach(const QJsonValue &value, svArray){
        m_listDay.append(value.toString());
    }
}

void DayModel::append(QString addday)
{
    QString item(addday);
    beginInsertRows(QModelIndex(), m_listDay.count(), m_listDay.count());
    m_listDay.append(item);
    endInsertRows();
}

void DayModel::remove(QString removeday)
{
//    beginRemoveRows(QModelIndex(), index, index);
//    m_listDay.removeAt(index);
//    endRemoveRows();
}

void DayModel::clear()
{
    beginResetModel();
    m_listDay.clear();
    endResetModel();
}

void DayModel::addItem(QString addday)
{
    QJsonArray arr = m_data["ngay"].toArray();
    arr.append(addday);
    m_data["ngay"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    append(addday);
}

void DayModel::removeItem(QString removeday)
{
//    remove(index);

//    QJsonArray arr = m_data["sinhvien"].toArray();
//    arr.removeAt(index);
//    m_data["sinhvien"]= arr;

//    QJsonDocument jsonDoc(m_data);

//    QFile file(PATH_DATA);
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        qDebug() << "Không thể mở tệp JSON";
//        return;
//    }
//    file.write(jsonDoc.toJson());
//    file.close();
}

