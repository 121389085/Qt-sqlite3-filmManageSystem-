#ifndef USER_H
#define USER_H

#include <QString>

enum UserType
{
    NORMAL,
    VIP
};

class User
{
public:
    User();
    User(const int);//构造uid
    User(const QString&);//构造账户
    User(const QString&,const QString&);
    User(const QString&,const QString&,const UserType);
    User(const int, const QString&,const QString&,const UserType);//重载构造，方便使用不同的匿名对象
    int getUid() const;
    void setUid(int value);

    QString getAccount() const;
    void setAccount(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    UserType getType() const;
    void setType(const UserType &value);

    void print();//输出用户数据，用于测试

    bool operator==(const User&)const;//重载为account相等之用户，用户相等
private:
    int uid;
    QString account;
    QString password;
    UserType type;
};

#endif // USER_H
