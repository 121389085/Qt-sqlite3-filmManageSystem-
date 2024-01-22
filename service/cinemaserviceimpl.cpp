#include "cinemaserviceimpl.h"

#include <QVector>

CinemaServiceImpl::CinemaServiceImpl()
    :cinemaDao(new CinemaDaoImpl)
{

}

CinemaServiceImpl::~CinemaServiceImpl()
{
    delete cinemaDao;
}

QVector<Cinema> CinemaServiceImpl::getAllCinema()
{
    return cinemaDao->selectAllCinema();
}

Cinema CinemaServiceImpl::getCinemaByCid(const int cid)
{
    return cinemaDao->selectCinemaByCid(cid);
}

QString CinemaServiceImpl::getCnameByCid(const int cid)
{
    return getCinemaByCid(cid).getCname();
}
