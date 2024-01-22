#include "filmserviceimpl.h"

#include <QVector>

FilmServiceImpl::FilmServiceImpl()
    :filmDao(new FilmDaoImpl)
{

}

FilmServiceImpl::~FilmServiceImpl()
{
    delete filmDao;
}

QVector<Film> FilmServiceImpl::getALLfilm()
{
    return filmDao->selectAllFilm();
}

Film FilmServiceImpl::getFilmByFid(const int fid)
{
    return filmDao->selectFilmByFid(fid);
}

QString FilmServiceImpl::getFilmNameByFid(const int fid)
{
    Film temp=getFilmByFid(fid);
    return temp.getFname();
}
