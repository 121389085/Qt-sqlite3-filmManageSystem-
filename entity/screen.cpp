#include "screen.h"
#include <QDebug>
Screen::Screen()
{
    scid=0;
}

Screen::Screen(const QString &scname, const int num, const int cid)
{
    this->scname=scname;
    this->num=num;
    this->cid=cid;
}

int Screen::getScid() const
{
    return scid;
}

void Screen::setScid(int value)
{
    scid = value;
}

int Screen::getNum() const
{
    return num;
}

void Screen::setNum(int value)
{
    num = value;
}

int Screen::getCid() const
{
    return cid;
}

void Screen::setCid(int value)
{
    cid = value;
}

QString Screen::getScname() const
{
    return scname;
}

void Screen::setScname(const QString &value)
{
    scname = value;
}

void Screen::print()
{
    qDebug()<<"scid:"<<scid;
    qDebug()<<"放映厅:"<<scname;
    qDebug()<<"剩余座位数量:"<<num;
    qDebug()<<"影院id:"<<cid;
}
