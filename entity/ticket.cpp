#include "ticket.h"
#include <QDebug>
Ticket::Ticket()
{
    tid=0;
}

Ticket::Ticket(const int tid)
{
    this->tid=tid;
}

Ticket::Ticket(const int uid, const int seid, const QString &seat)
{
    this->uid=uid;
    this->seid=seid;
    this->seat=seat;
}

int Ticket::getTid() const
{
    return tid;
}

void Ticket::setTid(int value)
{
    tid = value;
}

int Ticket::getUid() const
{
    return uid;
}

void Ticket::setUid(int value)
{
    uid = value;
}

int Ticket::getSeid() const
{
    return seid;
}

void Ticket::setSeid(int value)
{
    seid = value;
}

QString Ticket::getSeat() const
{
    return seat;
}

void Ticket::setSeat(const QString &value)
{
    seat = value;
}

void Ticket::print()
{
    qDebug()<<"tid:"<<tid;
    qDebug()<<"用户id:"<<uid;
    qDebug()<<"场次:"<<seid;
    qDebug()<<"座位:"<<seat;
}
