#include "cinemadaoimpl.h"
#include "dbutil/dbutil.h"
#include <QVector>

CinemaDaoImpl::CinemaDaoImpl()
{

}

bool CinemaDaoImpl::insertCinema(const Cinema &cinema)
{
    QString address=cinema.getAddress();
    QString cname=cinema.getCname();
    QString sql="insert into cinema(address,cname)"
                " values(:address,:cname)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":address",address);
    paramMap.insert(":cname",cname);
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool CinemaDaoImpl::deleteCinemaByCid(const int cid)
{
    QString sql="delete from cinema where cid=:cid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":cid",QString::number(cid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool CinemaDaoImpl::updateCinema(const Cinema &cinema)
{
    QString sql="update cinema set address=:address,cname=:cname"
                " where cid=:cid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":address",cinema.getAddress());
    paramMap.insert(":cname",cinema.getCname());
    paramMap.insert(":cid",QString::number(cinema.getCid()));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

QVector<Cinema> CinemaDaoImpl::selectAllCinema()
{
    QString sql="select * from cinema";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Cinema cTemp;
    QVector<Cinema> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        cTemp.setCid(qTemp["cid"].toInt());
        cTemp.setAddress(qTemp["address"]);
        cTemp.setCname(qTemp["cname"]);
        vTemp.push_back(cTemp);
    }
    return vTemp;
}

Cinema CinemaDaoImpl::selectCinemaByCid(const int cid)
{
    QString sql="select * from cinema where cid=:cid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":cid",QString::number(cid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Cinema cTemp;
    auto it=temp.begin();
    if(it==temp.end())
        return cTemp;//cid为0表示没找到
    QMap<QString,QString> qTemp=*it;
    cTemp.setCid(qTemp["cid"].toInt());
    cTemp.setAddress(qTemp["address"]);
    cTemp.setCname(qTemp["cname"]);
    return cTemp;
}
