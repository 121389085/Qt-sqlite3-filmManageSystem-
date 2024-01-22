#ifndef CINEMASERVICEIMPL_H
#define CINEMASERVICEIMPL_H

#include "cinemaservice.h"
#include "dao/cinemadaoimpl.h"


class CinemaServiceImpl : public CinemaService
{
public:
    CinemaServiceImpl();
    ~CinemaServiceImpl();
    QVector<Cinema> getAllCinema() override;
    Cinema getCinemaByCid(const int) override;
    QString getCnameByCid(const int) override;
private:
    CinemaDao* cinemaDao;
};

#endif // CINEMASERVICEIMPL_H
