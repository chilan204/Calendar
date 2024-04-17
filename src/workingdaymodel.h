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

    void initialize(QJsonArray arr);
    void append(QString addday);
    void remove(QString removeday);
    void clear();

private:
    QList <QString> m_listDay;
};

#endif // WORKINGDAYMODEL_H
