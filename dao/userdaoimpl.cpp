#include "userdaoimpl.h"
#include "dbutil/dbutil.h"
#include <QDebug>
UserDaoImpl::UserDaoImpl()
{

}

bool UserDaoImpl::insertUser(const User &user)
{
    QString account=user.getAccount();
    QString password=user.getPassword();
    UserType type=user.getType();
    QString sql="insert into user(account,password,type)"
                " values(:account,:password,:type)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":account",account);
    paramMap.insert(":password",password);
    paramMap.insert(":type",QString::number(type));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool UserDaoImpl::deleteUserByAccount(const QString &account)
{
    QString sql="delete from user where account=:account";
    QMap<QString,QString> paramMap;
    paramMap.insert(":account",account);
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool UserDaoImpl::updateUser(const User &user)
{
    int uid=user.getUid();
    QString account=user.getAccount();
    QString password=user.getPassword();
    UserType type=user.getType();
    QString sql="update user set account=:account,"
                "password=:password,type=:type"
                " where uid=:uid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":account",account);
    paramMap.insert(":password",password);
    paramMap.insert(":type",QString::number(type));
    paramMap.insert(":uid",QString::number(uid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}



QVector<User> UserDaoImpl::selectAllUser()
{
    QString sql="select * from user";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    User uTemp;
    QVector<User> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        uTemp.setUid(qTemp["uid"].toInt());
        uTemp.setAccount(qTemp["account"]);
        uTemp.setPassword(qTemp["password"]);
        if(qTemp["type"]=="0")
            uTemp.setType(NORMAL);
        else
            uTemp.setType(VIP);
        vTemp.push_back(uTemp);
    }
    return vTemp;
}

User UserDaoImpl::selectUserByUid(const int &uid)
{
    QString sql="select * from user where uid=:uid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":uid",QString::number(uid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    if(temp.count()==0)
        return User(0);//uid为0表示没查到
    User uTemp;
    auto it=temp.begin();
    QMap<QString, QString> mTemp=*it;
    uTemp.setUid(mTemp["uid"].toInt());
    uTemp.setAccount(mTemp["account"]);
    uTemp.setPassword(mTemp["password"]);
    if(mTemp["type"]=="0")
        uTemp.setType(NORMAL);
    else
        uTemp.setType(VIP);
    return uTemp;
}
