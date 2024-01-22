#include "screendaoimpl.h"

#include <QMap>

#include "dbutil/dbutil.h"

ScreenDaoImpl::ScreenDaoImpl()
{

}

bool ScreenDaoImpl::insertScreen(const Screen &screen)
{
    QString scname=screen.getScname();
    int num=screen.getNum();
    int cid=screen.getCid();
    QString sql="insert into screen(scname,num,cid)"
                " values(:scname,:num,:cid)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scname",scname);
    paramMap.insert(":num",QString::number(num));
    paramMap.insert(":cid",QString::number(cid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool ScreenDaoImpl::deleteScreenByScid(const int scid)
{
    QString sql="delete from screen where scid=:scid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scid",QString::number(scid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool ScreenDaoImpl::updateScreen(const Screen &screen)
{
    int scid=screen.getScid();
    QString scname=screen.getScname();
    int num=screen.getNum();
    int cid=screen.getCid();
    QString sql="update screen set scname=:scname,"
                "num=:num,cid=:cid"
                " where scid=:scid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scname",scname);
    paramMap.insert(":num",QString::number(num));
    paramMap.insert(":cid",QString::number(cid));
    paramMap.insert(":scid",QString::number(scid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

QVector<Screen> ScreenDaoImpl::selectAllScreen()
{
    QString sql="select * from screen";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Screen sTemp;
    QVector<Screen> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setScname(qTemp["scname"]);
        sTemp.setNum(qTemp["num"].toInt());
        sTemp.setCid(qTemp["cid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}

Screen ScreenDaoImpl::selectScreenByScid(const int &scid)
{
    QString sql="select * from screen where scid=:scid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":scid",QString::number(scid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Screen sTemp;
    auto it=temp.begin();
    if(it==temp.end())
        return sTemp;
    QMap<QString,QString> qTemp=*it;
    sTemp.setScid(qTemp["scid"].toInt());
    sTemp.setScname(qTemp["scname"]);
    sTemp.setNum(qTemp["num"].toInt());
    sTemp.setCid(qTemp["cid"].toInt());
    return sTemp;
}

QVector<Screen> ScreenDaoImpl::selectScreenByCid(const int &cid)
{
    QString sql="select * from screen where cid=:cid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":cid",QString::number(cid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Screen sTemp;
    QVector<Screen> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setScname(qTemp["scname"]);
        sTemp.setNum(qTemp["num"].toInt());
        sTemp.setCid(qTemp["cid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}

QVector<Screen> ScreenDaoImpl::selectScreenIsNotFull()
{
    QString sql="select * from screen where num > 0";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Screen sTemp;
    QVector<Screen> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        sTemp.setScid(qTemp["scid"].toInt());
        sTemp.setScname(qTemp["scname"]);
        sTemp.setNum(qTemp["num"].toInt());
        sTemp.setCid(qTemp["cid"].toInt());
        vTemp.push_back(sTemp);
    }
    return vTemp;
}
