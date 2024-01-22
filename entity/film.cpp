#include "film.h"
#include <QDebug>
Film::Film()
{
    this->fid=0;
}

Film::Film(const QString& fname, const QString& introduction, const QString& preview,const int duration)
{
    this->fname=fname;
    this->introduction=introduction;
    this->preview=preview;
    this->duration=duration;
}

int Film::getFid() const
{
    return fid;
}

void Film::setFid(int value)
{
    fid = value;
}

QString Film::getFname() const
{
    return fname;
}

void Film::setFname(const QString &value)
{
    fname = value;
}

QString Film::getIntroduction() const
{
    return introduction;
}

void Film::setIntroduction(const QString &value)
{
    introduction = value;
}

int Film::getDuration() const
{
    return duration;
}

void Film::setDuration(const int value)
{
    duration = value;
}

void Film::print()
{
    qDebug()<<"电影名："<<fname;
    qDebug()<<"介绍："<<introduction;
    qDebug()<<"时长："<<duration;
}

QString Film::getPreview() const
{
    return preview;
}

void Film::setPreview(const QString &value)
{
    preview = value;
}
