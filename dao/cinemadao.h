#ifndef CINEMADAO_H
#define CINEMADAO_H

#include <entity/cinema.h>



class CinemaDao
{
public:
    CinemaDao();
    virtual ~CinemaDao(){}
    virtual bool insertCinema(const Cinema&) = 0;    //添加影院
    virtual bool deleteCinemaByCid(const int) = 0;   //删除影院
    virtual bool updateCinema(const Cinema&) = 0;   //更新影院
    virtual QVector<Cinema> selectAllCinema() = 0;
    virtual Cinema selectCinemaByCid(const int) = 0;
};

#endif // CINEMADAO_H
