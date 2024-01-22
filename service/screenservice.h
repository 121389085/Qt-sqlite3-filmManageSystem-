#ifndef SCREENSERVICE_H
#define SCREENSERVICE_H
#include "entity/screen.h"

class ScreenService
{
public:
    ScreenService();
    virtual ~ScreenService(){}
    virtual QVector<Screen> getAllScreen() = 0;
    virtual QVector<Screen> getScreenByCid(const int) = 0;
    virtual Screen getScreenByScid(const int) = 0;
    virtual QString getScnameByScid(const int) = 0;
    virtual int getCidByScid(const int) = 0;
};

#endif // SCREENSERVICE_H
