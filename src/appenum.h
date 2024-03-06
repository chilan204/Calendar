#ifndef APPENUM_H
#define APPENUM_H

#include <QObject>

class AppEnum : public QObject
{
    Q_OBJECT
public:
    enum SCREEN {
        HOME = 0,
        INFOR,
        STATISTICAL,
        SETTING
    }Q_ENUMS(SCREEN);
};

#endif // APPENUM_H
