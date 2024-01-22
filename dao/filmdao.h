#ifndef FILMDAO_H
#define FILMDAO_H

#include <entity/film.h>



class FilmDao
{
public:
    FilmDao();
    virtual ~FilmDao(){}
    virtual bool insertFilm(const Film&) = 0;    //添加电影
    virtual bool deleteFilmByFid(const int) = 0;   //删除电影
    virtual bool updateFilm(const Film&) = 0;   //更新电影
    virtual QVector<Film> selectAllFilm() = 0;
    virtual QVector<Film> selectFilmByFname(const QString&) = 0;
    virtual Film selectFilmByFid(const int) = 0;
    virtual QVector<Film> selectFilmGreatByDuration(const int) = 0;//大于指定时长
    virtual QVector<Film> selectFilmLessByDuration(const int) = 0;//小于指定时长
};

#endif // FILMDAO_H
