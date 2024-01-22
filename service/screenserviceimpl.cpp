#include "screenserviceimpl.h"

#include <QVector>

ScreenServiceImpl::ScreenServiceImpl()
    :screenDao(new ScreenDaoImpl)
{

}

ScreenServiceImpl::~ScreenServiceImpl()
{
    delete screenDao;
}

QVector<Screen> ScreenServiceImpl::getAllScreen()
{
    return screenDao->selectAllScreen();
}

QVector<Screen> ScreenServiceImpl::getScreenByCid(const int cid)
{
    return screenDao->selectScreenByCid(cid);
}

Screen ScreenServiceImpl::getScreenByScid(const int scid)
{
    return screenDao->selectScreenByScid(scid);
}

QString ScreenServiceImpl::getScnameByScid(const int scid)
{
    return getScreenByScid(scid).getScname();
}

int ScreenServiceImpl::getCidByScid(const int scid)
{
    return getScreenByScid(scid).getCid();
}
