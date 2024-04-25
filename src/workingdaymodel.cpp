#include "workingdaymodel.h"

DayModel::DayModel(QObject *parent) : QAbstractListModel(parent)
{

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

//    const Student &item = m_listStudent[index.row()];

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

void DayModel::initialize(QJsonArray arr)
{
    foreach(const QJsonValue &value, arr){
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

void DayModel::clear()
{
    beginResetModel();
    m_listDay.clear();
    endResetModel();
}
