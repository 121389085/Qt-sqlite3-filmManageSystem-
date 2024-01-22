#ifndef SCREENDAO_H
#define SCREENDAO_H

#include "entity/screen.h"

#include <QVector>



class ScreenDao
{
public:
    ScreenDao();
    virtual ~ScreenDao(){}
    virtual bool insertScreen(const Screen&) = 0;
    virtual bool deleteScreenByScid(const int) = 0;
    virtual bool updateScreen(const Screen&) = 0;
    virtual QVector<Screen> selectAllScreen() = 0;
    virtual Screen selectScreenByScid(const int&) = 0;
    virtual QVector<Screen> selectScreenByCid(const int&) = 0;
    virtual QVector<Screen> selectScreenIsNotFull() = 0;
};

#endif // SCREENDAO_H
