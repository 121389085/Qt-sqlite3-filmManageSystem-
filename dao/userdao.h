#ifndef USERDAO_H
#define USERDAO_H
#include "entity/user.h"

class UserDao
{
public:
    UserDao();
    virtual ~UserDao(){}
    virtual bool insertUser(const User&) = 0;    //注册用户
    virtual bool deleteUserByAccount(const QString&) = 0;   //删除用户
    virtual bool updateUser(const User&) = 0;   //更新用户名或密码
    virtual QVector<User> selectAllUser() = 0;
    virtual User selectUserByUid(const int&) = 0;
};

#endif // USERDAO_H
