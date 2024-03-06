#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

public:
     static Controller *getInstance();
     void initialize();

private:
    explicit Controller(QObject *parent = nullptr);
    int index;
};

#endif // CONTROLLER_H
