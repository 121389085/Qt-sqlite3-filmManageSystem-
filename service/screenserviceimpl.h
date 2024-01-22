#ifndef SCREENSERVICEIMPL_H
#define SCREENSERVICEIMPL_H

#include "screenservice.h"
#include "dao/screendaoimpl.h"


class ScreenServiceImpl : public ScreenService
{
public:
    ScreenServiceImpl();
    ~ScreenServiceImpl();
    QVector<Screen> getAllScreen() override;
    QVector<Screen> getScreenByCid(const int) override;
    Screen getScreenByScid(const int) override;
    QString getScnameByScid(const int) override;
    int getCidByScid(const int) override;
private:
    ScreenDao* screenDao;
};

#endif // SCREENSERVICEIMPL_H
