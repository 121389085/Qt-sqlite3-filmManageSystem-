#include "cinema.h"
#include <QDebug>
Cinema::Cinema()
{
    cid=0;
}

Cinema::Cinema(const int cid, const QString &address, const QString &cname)
{
    this->cid=cid;
    this->address=address;
    this->cname=cname;
}

Cinema::Cinema(const QString &address, const QString &cname)
{
    this->address=address;
    this->cname=cname;
}

int Cinema::getCid() const
{
    return cid;
}

void Cinema::setCid(int value)
{
    cid = value;
}

QString Cinema::getAddress() const
{
    return address;
}

void Cinema::setAddress(const QString &value)
{
    address = value;
}

QString Cinema::getCname() const
{
    return cname;
}

void Cinema::setCname(const QString &value)
{
    cname = value;
}

void Cinema::print()
{
    qDebug()<<"影院名称："<<cname;
    qDebug()<<"地址："<<address;
}
