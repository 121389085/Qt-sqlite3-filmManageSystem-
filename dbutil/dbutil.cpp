#include "dbutil.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
DbUtil* DbUtil::instance=nullptr;
DbUtil *DbUtil::getInstance()
{
    if(instance==nullptr)
        instance=new DbUtil;
    return instance;
}

void DbUtil::createConnection()
{
    connection=QSqlDatabase::addDatabase("QSQLITE");
    connection.setDatabaseName("filmManage.db");
    if(!connection.open())
        qDebug()<<"数据库连接失败："<<connection.lastError().text();
}

void DbUtil::destroyConnection()
{
    connection.close();
    connection.removeDatabase("filmManage.db");
}

bool DbUtil::execute(const QString &sql,const QMap<QString, QString> &paramMap)
{
    createConnection();
    QSqlQuery query;
    query.prepare(sql);
    for(auto it=paramMap.begin();it!=paramMap.end();it++)
        query.bindValue(it.key(),it.value());

    bool result=query.exec();
    if(!result)
        qDebug()<<"语句执行失败："<<query.lastQuery()<<query.lastError().text();
    destroyConnection();
    return result;
}

QVector<QMap<QString, QString> > DbUtil::selectAllResult(const QString &sql)
{
    createConnection();
    QSqlQuery query;
    bool result=query.exec(sql);
    QVector<QMap<QString, QString> > Vtemp;
    if(!result)
    {
        qDebug()<<"查询失败："<<query.lastQuery()<<query.lastError().text();
        return Vtemp;
    }
    while (query.next())
    {
        QMap<QString,QString> Mtemp;
        QSqlRecord record=query.record();
        for(int i=0;i<record.count();i++)
        {
            Mtemp.insert(record.fieldName(i),record.value(i).toString());
        }
        Vtemp.push_back(Mtemp);
    }
    destroyConnection();
    return Vtemp;
}

QVector<QMap<QString, QString> > DbUtil::selectResultByCondition(const QString &sql, const QMap<QString, QString> &paramMap)
{
    createConnection();
    QSqlQuery query;
    query.prepare(sql);
    for(auto it=paramMap.begin();it!=paramMap.end();it++)
    {
        query.bindValue(it.key(),it.value());
    }

    bool result=query.exec();
    QVector<QMap<QString, QString> > Vtemp;
    if(!result)
    {
        qDebug()<<"条件查询失败："<<query.lastQuery()<<query.lastError().text();
        return Vtemp;
    }
    while (query.next())
    {
        QMap<QString,QString> Mtemp;
        QSqlRecord record=query.record();
        for(int i=0;i<record.count();i++)
            Mtemp.insert(record.fieldName(i),record.value(i).toString());
        Vtemp.push_back(Mtemp);
    }
    destroyConnection();
    return Vtemp;
}
