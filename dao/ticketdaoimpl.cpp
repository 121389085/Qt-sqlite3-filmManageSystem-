#include "ticketdaoimpl.h"

#include <QMap>
#include "dbutil/dbutil.h"

TicketDaoImpl::TicketDaoImpl()
{

}

bool TicketDaoImpl::insertTicket(const Ticket &ticket)
{
    int uid=ticket.getUid();
    int seid=ticket.getSeid();
    QString seat=ticket.getSeat();
    QString sql="insert into ticket(uid,seid,seat)"
                " values(:uid,:seid,:seat)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":uid",QString::number(uid));
    paramMap.insert(":seid",QString::number(seid));
    paramMap.insert(":seat",seat);
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool TicketDaoImpl::deleteTicketByTid(const int tid)
{
    QString sql="delete from ticket where tid=:tid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":tid",QString::number(tid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool TicketDaoImpl::updateTicket(const Ticket &)
{
    return false;
}

QVector<Ticket> TicketDaoImpl::selectTicketByUid(const int uid)
{
    QString sql="select * from ticket where uid =:uid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":uid",QString::number(uid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Ticket tTemp;
    QVector<Ticket> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        tTemp.setTid(qTemp["tid"].toInt());
        tTemp.setUid(qTemp["uid"].toInt());
        tTemp.setSeid(qTemp["seid"].toInt());
        tTemp.setSeat(qTemp["seat"]);
        vTemp.push_back(tTemp);
    }
    return vTemp;
}

QVector<Ticket> TicketDaoImpl::selectTicketBySeid(const int seid)
{
    QString sql="select * from ticket where seid =:seid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":seid",QString::number(seid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Ticket tTemp;
    QVector<Ticket> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        tTemp.setTid(qTemp["tid"].toInt());
        tTemp.setUid(qTemp["uid"].toInt());
        tTemp.setSeid(qTemp["seid"].toInt());
        tTemp.setSeat(qTemp["seat"]);
        vTemp.push_back(tTemp);
    }
    return vTemp;
}
