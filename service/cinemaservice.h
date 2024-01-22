#ifndef CINEMASERVICE_H
#define CINEMASERVICE_H

#include <dao/cinemadaoimpl.h>
class CinemaService
{
public:
    CinemaService();
    virtual ~CinemaService(){}
    virtual QVector<Cinema> getAllCinema() = 0;
    virtual Cinema getCinemaByCid(const int) = 0;
    virtual QString getCnameByCid(const int) = 0 ;
};

#endif // CINEMASERVICE_H
