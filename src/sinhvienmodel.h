#ifndef SINHVIENMODEL_H
#define SINHVIENMODEL_H

#include <QAbstractListModel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "define.h"

struct SinhVien {
    QString name;
    QString color;
    int tuition;

    SinhVien(){};
    SinhVien(QString addname, QString addcolor, int addtuition){
        name = addname;
        color = addcolor;
        tuition = addtuition;
    };
};

class SinhVienModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SinhVienModel(QObject *parent = nullptr);

    enum SinhVienRoles {
        NameRole = Qt::UserRole + 1,
        ColorRole,
        TuitionRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void readDatafromJson();
    void append(QString addname, QString addcolor, int addtuition);
    void modify(QString addname, QString addcolor, int addtuition, int index);
    void remove(int index);
    void clear();

    Q_INVOKABLE void add(QString addname, QString addcolor, QString tuition);
    Q_INVOKABLE void modifyItem(QString addname, QString addcolor, QString addtuition, int index);
    Q_INVOKABLE void removeItem(int index);

signals:
    void showNotifyPopUp(QString msg);

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<SinhVien> m_listSinhVien;
    QJsonObject m_data;
    bool saveIndex = true;
};

#endif // SINHVIENMODEL_H
