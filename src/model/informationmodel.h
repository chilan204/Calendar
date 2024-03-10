#ifndef INFORMATIONMODEL_H
#define INFORMATIONMODEL_H

#include <QObject>

struct Student {
    QString name;
    QString color;
    int salary;

    Student(){};

    Student(QString n, QString c, int s){
        name = n;
        color = c;
        salary = s;
    };
};


class InformationModel
{
public:
    InformationModel();
    void test() {
        Student s;
        s.name = "Tung";
    }

private:
    QString t;
    int age;

};

class InformationModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit NoteModel(QObject *parent = nullptr);

    enum MeanRoles {
        IndexRole = Qt::UserRole + 1,
        WordsRole,
        MeansRole,
        NotesRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void append(NoteItem item);
    void removeAt(int index);
    void replace(int index, NoteItem &item);
    void clear();

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<NoteItem> m_listNote;
};

#endif // INFORMATIONMODEL_H
