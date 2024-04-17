#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QAbstractListModel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "define.h"

struct Student {
    QString name;
    QString color;
    int tuition;

    Student(){};
    Student(QString addname, QString addcolor, int addtuition){
        name = addname;
        color = addcolor;
        tuition = addtuition;
    };
};

class StudentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StudentModel(QObject *parent = nullptr);

    enum StudentRoles {
        NameRole = Qt::UserRole + 1,
        ColorRole,
        TuitionRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void initialize(QJsonArray arr);
    void append(QString addname, QString addcolor, int addtuition);
    void modify(QString addname, QString addcolor, int addtuition, int index);
    void remove(int index);
    void clear();

signals:
    void showNotifyPopUp(QString msg);

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList <Student> m_listStudent;
};

#endif // STUDENTMODEL_H
