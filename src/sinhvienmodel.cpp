#include "sinhvienmodel.h"

SinhVienModel::SinhVienModel(QObject *parent) : QAbstractListModel(parent)
{
    readDatafromJson();
}

int SinhVienModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listSinhVien.count();
}

QVariant SinhVienModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_listSinhVien.count())
        return QVariant();

    const SinhVien &item = m_listSinhVien[index.row()];

    switch (role) {
    case NameRole:
        return item.name;
    case ColorRole:
        return item.color;
    case TuitionRole:
        return item.tuition;
    default:
        return QVariant();
    }
}

void SinhVienModel::readDatafromJson()
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

    QJsonArray svArray = m_data["sinhvien"].toArray();

    foreach(const QJsonValue &value, svArray){
        SinhVien sv;
        sv.name = value.toObject()["Name"].toString();
        sv.color = value.toObject()["Color"].toString();
        sv.tuition = value.toObject()["Tuition"].toInt();
        m_listSinhVien.append(sv);
    }
}

void SinhVienModel::append(QString addname, QString addcolor, int addtuition)
{
    SinhVien item(addname, addcolor, addtuition);
    beginInsertRows(QModelIndex(), m_listSinhVien.count(), m_listSinhVien.count());
    m_listSinhVien.append(item);
    endInsertRows();
}

void SinhVienModel::modify(QString addname, QString addcolor, int addtuition, int index)
{
    SinhVien item(addname, addcolor, addtuition);
    beginResetModel();
    m_listSinhVien.replace(index, item);
    endResetModel();
}

void SinhVienModel::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_listSinhVien.removeAt(index);
    endRemoveRows();
}

void SinhVienModel::clear()
{
    beginResetModel();
    m_listSinhVien.clear();
    endResetModel();
}

void SinhVienModel::add(QString addname, QString addcolor, QString tuition)
{
    foreach (SinhVien item, m_listSinhVien) {
        if (addcolor == item.color) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject sinhvien;
    sinhvien["Name"] = addname;
    sinhvien["Color"] = addcolor;
    sinhvien["Tuition"] = tuition.toInt();

    QJsonArray arr = m_data["sinhvien"].toArray();
    arr.append(sinhvien);
    m_data["sinhvien"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    append(addname, addcolor, tuition.toInt());
}

void SinhVienModel::modifyItem(QString addname, QString addcolor, QString addtuition, int index)
{
    foreach (SinhVien item, m_listSinhVien) {
        if ( addcolor != m_listSinhVien[index].color && addcolor == item.color ) {
            emit showNotifyPopUp("Màu đã được sử dụng!");
            return;
        }
    };

    QJsonObject sinhvien;
    sinhvien["Name"] = addname;
    sinhvien["Color"] = addcolor;
    sinhvien["Tuition"] = addtuition.toInt();

    QJsonArray arr = m_data["sinhvien"].toArray();
    arr[index] = sinhvien;
    m_data["sinhvien"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();

    modify(addname, addcolor, addtuition.toInt(), index);
}

void SinhVienModel::removeItem(int index)
{
    remove(index);

    QJsonArray arr = m_data["sinhvien"].toArray();
    arr.removeAt(index);
    m_data["sinhvien"]= arr;

    QJsonDocument jsonDoc(m_data);

    QFile file(PATH_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở tệp JSON";
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();
}

QHash<int, QByteArray> SinhVienModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ColorRole] = "color";
    roles[TuitionRole] = "tuition";
    return roles;
}
