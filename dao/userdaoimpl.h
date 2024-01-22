#ifndef USERDAOIMPL_H
#define USERDAOIMPL_H
#include "userdao.h"

class UserDaoImpl : public UserDao
{
public:
    UserDaoImpl();
    ~UserDaoImpl(){}
    bool insertUser(const User &) override;//注册用户
    bool deleteUserByAccount(const QString &) override;//删除用户
    bool updateUser(const User &) override;//更新用户名或密码
    QVector<User> selectAllUser() override;//查询所有用户(判断用户名是否重复)
    User selectUserByUid(const int &) override;
};

#endif // USERDAOIMPL_H
