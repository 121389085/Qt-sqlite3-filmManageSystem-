#include "session.h"
#include <QDebug>
Session::Session()
{
    this->seid=0;
}

Session::Session(const int seid)
{
    this->seid=seid;
}

Session::Session(const int seid, const int scid, const QString &showtime, const double price, const int fid)
{
    this->seid=seid;
    this->scid=scid;
    this->showtime=showtime;
    this->price=price;
    this->fid=fid;
}

Session::Session(const int scid, const QString &showtime, const double price, const int fid)
{
    this->scid=scid;
    this->showtime=showtime;
    this->price=price;
    this->fid=fid;
}

int Session::getSeid() const
{
    return seid;
}

void Session::setSeid(int value)
{
    seid = value;
}

int Session::getScid() const
{
    return scid;
}

void Session::setScid(int value)
{
    scid = value;
}

QString Session::getShowtime() const
{
    return showtime;
}

void Session::setShowtime(const QString &value)
{
    showtime = value;
}

QDate Session::getShowDate() const
{
    QStringList parts=showtime.split(" ");
    QString date="";
    for(int i=0;i<4;i++)
    {
        date+=parts[i];
        date+=" ";
    }
    return QDate::fromString(date);
}

QTime Session::getshowTime() const
{
    QStringList parts=showtime.split(" ");
    return QTime::fromString(parts[4]);
}

double Session::getPrice() const
{
    return price;
}

void Session::setPrice(double value)
{
    price = value;
}

int Session::getFid() const
{
    return fid;
}

void Session::setFid(int value)
{
    fid = value;
}

bool Session::operator<(const Session &session) const
{
    return this->getshowTime()<session.getshowTime();
}

void Session::print()
{
    qDebug()<<"seid:"<<seid;
    qDebug()<<"放映厅:"<<scid;
    qDebug()<<"放映时间:"<<showtime;
    qDebug()<<"价格:"<<price;
    qDebug()<<"电影id:"<<fid;
}
