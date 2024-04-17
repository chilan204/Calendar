#include "studentmodel.h"

StudentModel::StudentModel(QObject *parent) : QAbstractListModel(parent)
{

}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listStudent.count();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_listStudent.count())
        return QVariant();

    const Student &item = m_listStudent[index.row()];

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

void StudentModel::initialize(QJsonArray arr)
{
    foreach(const QJsonValue &value, arr){
        Student sv;
        sv.name = value.toObject()["Name"].toString();
        sv.color = value.toObject()["Color"].toString();
        sv.tuition = value.toObject()["Tuition"].toInt();
        m_listStudent.append(sv);
    }
}

void StudentModel::append(QString addname, QString addcolor, int addtuition)
{
    Student item(addname, addcolor, addtuition);
    beginInsertRows(QModelIndex(), m_listStudent.count(), m_listStudent.count());
    m_listStudent.append(item);
    endInsertRows();
}

void StudentModel::modify(QString addname, QString addcolor, int addtuition, int index)
{
    Student item(addname, addcolor, addtuition);
    beginResetModel();
    m_listStudent.replace(index, item);
    endResetModel();
}

void StudentModel::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_listStudent.removeAt(index);
    endRemoveRows();
}

void StudentModel::clear()
{
    beginResetModel();
    m_listStudent.clear();
    endResetModel();
}

QHash<int, QByteArray> StudentModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ColorRole] = "color";
    roles[TuitionRole] = "tuition";
    return roles;
}
