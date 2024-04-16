#ifndef DAYMODEL_H
#define DAYMODEL_H

#include <QAbstractListModel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "define.h"

class DayModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DayModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void readDatafromJson();
    void append(QString addday);
    void remove(QString removeday);
    void clear();

    Q_INVOKABLE void addItem(QString addday);
    Q_INVOKABLE void removeItem(QString removeday);

private:
    QList <QString> m_listDay;
    QJsonObject m_data;
};

#endif // SINHVIENMODEL_H
