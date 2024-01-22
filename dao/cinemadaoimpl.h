#ifndef CINEMADAOIMPL_H
#define CINEMADAOIMPL_H

#include "cinemadao.h"



class CinemaDaoImpl : public CinemaDao
{
public:
    CinemaDaoImpl();
    bool insertCinema(const Cinema &) override;
    bool deleteCinemaByCid(const int) override;
    bool updateCinema(const Cinema &) override;
    QVector<Cinema> selectAllCinema() override;
    Cinema selectCinemaByCid(const int) override;
};

#endif // CINEMADAOIMPL_H
