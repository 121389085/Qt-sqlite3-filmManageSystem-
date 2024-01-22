#include "sessiondaoimpl.h"

#include <QMap>

#include "dbutil/dbutil.h"

SessionDaoImpl::SessionDaoImpl()
{

}

bool SessionDaoImpl::intserSession(const Session &session)
{
    int scid=session.getScid();
    QString showtime=session.getShowtime();
    double price=session.getPrice();
    int fid=session.getFid();
    QString sql="insert into session(scid,showtime,price,fid)"
                " values(:scid,:showtime,:price,:fid)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scid",QString::number(scid));
    paramMap.insert(":showtime",showtime);
    paramMap.insert(":price",QString::number(price));
    paramMap.insert(":fid",QString::number(fid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool SessionDaoImpl::deleteSessionBySeid(const int seid)
{
    QString sql="delete from session where seid=:seid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":seid",QString::number(seid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool SessionDaoImpl::updateSession(const Session &session)
{
    int seid=session.getSeid();
    int scid=session.getScid();
    QString showtime=session.getShowtime();
    double price=session.getPrice();
    int fid=session.getFid();
    QString sql="update session set scid=:scid,"
                "showtime=:showtime,price=:price,fid=:fid"
                " where seid=:seid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scid",QString::number(scid));
    paramMap.insert(":showtime",showtime);
    paramMap.insert(":price",QString::number(price));
    paramMap.insert(":fid",QString::number(fid));
    paramMap.insert(":seid",QString::number(seid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

QVector<Session> SessionDaoImpl::selectAllSession()
{
    QString sql="select * from session";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Session sTemp;
    QVector<Session> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setSeid(qTemp["seid"].toInt());
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setShowtime(qTemp["showtime"]);
        sTemp.setPrice(qTemp["price"].toInt());
        sTemp.setFid(qTemp["fid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}

Session SessionDaoImpl::selectSessionBySeid(const int seid)
{
    QString sql="select * from session where seid = :seid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":seid",QString::number(seid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Session sTemp;
    auto it=temp.begin();
    if(it==temp.end())
        return sTemp;
    QMap<QString,QString> qTemp=*it;
    sTemp.setSeid(qTemp["seid"].toInt());
    sTemp.setScid(qTemp["scid"].toInt());
    sTemp.setShowtime(qTemp["showtime"]);
    sTemp.setPrice(qTemp["price"].toInt());
    sTemp.setFid(qTemp["fid"].toInt());
    return sTemp;
}

QVector<Session> SessionDaoImpl::selectSessionByScid(const int scid)
{
    QString sql="select * from session where scid = :scid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scid",QString::number(scid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Session sTemp;
    QVector<Session> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setSeid(qTemp["seid"].toInt());
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setShowtime(qTemp["showtime"]);
        sTemp.setPrice(qTemp["price"].toInt());
        sTemp.setFid(qTemp["fid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}

QVector<Session> SessionDaoImpl::selectSessionByFid(const int fid)
{
    QString sql="select * from session where fid = :fid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fid",QString::number(fid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Session sTemp;
    QVector<Session> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setSeid(qTemp["seid"].toInt());
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setShowtime(qTemp["showtime"]);
        sTemp.setPrice(qTemp["price"].toInt());
        sTemp.setFid(qTemp["fid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}
