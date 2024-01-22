#ifndef FILMSERVICEIMPL_H
#define FILMSERVICEIMPL_H

#include "filmservice.h"
#include "dao/filmdaoimpl.h"


class FilmServiceImpl : public FilmService
{
public:
    FilmServiceImpl();
    ~FilmServiceImpl();
    QVector<Film> getALLfilm() override;
    Film getFilmByFid(const int) override;//如果没查到，返回的film的fid为0(正常fid不能为0)
    QString getFilmNameByFid(const int) override;
private:
    FilmDao* filmDao;
};

#endif // FILMSERVICEIMPL_H
