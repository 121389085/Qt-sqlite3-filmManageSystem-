#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QString>

#include "entity/user.h"

class UserService
{
public:
    UserService();
    virtual ~UserService(){}
    virtual bool Login(const QString&,const QString&) = 0;
    virtual bool Regist(const QString&,const QString&) = 0;
    virtual QVector<User> getAllUser() = 0;
    virtual User getUserByAccount(const QString&) = 0;
};

#endif // USERSERVICE_H
