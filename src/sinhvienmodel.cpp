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

        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        if (jsonDoc.isNull()) {
            qDebug() << "Không thể phân tích JSON";
        }

        m_data = jsonDoc.object();

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

void SinhVienModel::clear()
{
    beginResetModel();
    m_listSinhVien.clear();
    endResetModel();
}

void SinhVienModel::add(QString addname, QString addcolor, QString tuition)
{
    append(addname, addcolor, tuition.toInt());

    QJsonObject sinhvien;
    sinhvien["Name"] = addname;
    sinhvien["Color"] = addcolor;
    sinhvien["Tuition"] = tuition.toInt();

    QJsonArray arr = m_data["sinhvien"].toArray();
    arr.append(sinhvien);
    m_data["sinhvien"]= arr;
    qDebug() << m_data;

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
