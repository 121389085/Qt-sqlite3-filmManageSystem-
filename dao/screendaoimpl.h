#ifndef SCREENDAOIMPL_H
#define SCREENDAOIMPL_H

#include "screendao.h"



class ScreenDaoImpl : public ScreenDao
{
public:
    ScreenDaoImpl();
    ~ScreenDaoImpl(){}
    bool insertScreen(const Screen &) override;
    bool deleteScreenByScid(const int) override;
    bool updateScreen(const Screen &) override;
    QVector<Screen> selectAllScreen() override;
    Screen selectScreenByScid(const int &) override;
    QVector<Screen> selectScreenByCid(const int &) override;
    QVector<Screen> selectScreenIsNotFull() override;
};

#endif // SCREENDAOIMPL_H
