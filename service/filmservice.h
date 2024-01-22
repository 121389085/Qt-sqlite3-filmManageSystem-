#ifndef FILMSERVICE_H
#define FILMSERVICE_H

#include "entity/film.h"



class FilmService
{
public:
    FilmService();
    virtual ~FilmService(){}
    virtual QVector<Film> getALLfilm() = 0;
    virtual Film getFilmByFid(const int) = 0;
    virtual QString getFilmNameByFid(const int) = 0;
};

#endif // FILMSERVICE_H
