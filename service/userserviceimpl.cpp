#include "userserviceimpl.h"

#include <QVector>

UserServiceImpl::UserServiceImpl()
    :userDao(new UserDaoImpl)
{

}


bool UserServiceImpl::Login(const QString &account, const QString &password)
{
    QVector<User> allUser=userDao->selectAllUser();
    if(allUser.count()==0)
        return false;
    auto it=allUser.begin();
    for(;it!=allUser.end();++it)
        if(*it==User(account))
            break;
    if(it->getPassword()==password)
        return true;
    return false;
}

bool UserServiceImpl::Regist(const QString &account, const QString &password)
{
    QVector<User> allUser=userDao->selectAllUser();
    for(auto it=allUser.begin();it!=allUser.end();++it)
        if(*it==User(account))
            return  false;
    userDao->insertUser(User(account,password,NORMAL));
    return true;
}

QVector<User> UserServiceImpl::getAllUser()
{
    return userDao->selectAllUser();
}

User UserServiceImpl::getUserByAccount(const QString &account)
{
    QVector<User> allUser=getAllUser();
    for(auto it=allUser.begin();it!=allUser.end();it++)
        if(*it==User(account))
            return *it;
    return User(0);
}
