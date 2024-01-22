#ifndef USERSERVICEIMPL_H
#define USERSERVICEIMPL_H

#include "userservice.h"
#include "dao/userdaoimpl.h"


class UserServiceImpl : public UserService
{
public:
    UserServiceImpl();
    ~UserServiceImpl(){}
    bool Login(const QString &, const QString &) override;
    bool Regist(const QString &, const QString &) override;
    QVector<User> getAllUser() override;
    User getUserByAccount(const QString &) override;
private:
    UserDao* userDao;
};

#endif // USERSERVICEIMPL_H
