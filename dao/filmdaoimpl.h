#ifndef FILMDAOIMPL_H
#define FILMDAOIMPL_H

#include "filmdao.h"



class FilmDaoImpl : public FilmDao
{
public:
    FilmDaoImpl();
    bool insertFilm(const Film &) override;//添加电影
    bool deleteFilmByFid(const int) override;//根据fid删除电影
    bool updateFilm(const Film &) override;//更新电影
    QVector<Film> selectAllFilm() override;
    QVector<Film> selectFilmByFname(const QString &) override;
    Film selectFilmByFid(const int) override;
    QVector<Film> selectFilmGreatByDuration(const int) override;
    QVector<Film> selectFilmLessByDuration(const int) override;
};

#endif // FILMDAOIMPL_H
