#include "user.h"
#include <QDebug>

User::User()
{

}

User::User(const int uid)
{
    this->uid=uid;
}

User::User(const QString &account)
{
    this->account=account;
}

User::User(const QString &account, const QString &password)
{
    this->account=account;
    this->password=password;
}

User::User(const QString &account, const QString &password, const UserType type)
{
    this->account=account;
    this->password=password;
    this->type=type;
}

User::User(const int uid, const QString &account, const QString &password, const UserType type)
{
    this->uid=uid;
    this->account=account;
    this->password=password;
    this->type=type;
}

int User::getUid() const
{
    return uid;
}

void User::setUid(int value)
{
    uid = value;
}

QString User::getAccount() const
{
    return account;
}

void User::setAccount(const QString &value)
{
    account = value;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &value)
{
    password = value;
}

UserType User::getType() const
{
    return type;
}

void User::setType(const UserType &value)
{
    type = value;
}

void User::print()
{
    qDebug()<<"uid:"<<uid;
    qDebug()<<"account:"<<account;
    qDebug()<<"password:"<<password;
    if(this->type==NORMAL)
        qDebug()<<"type:NORMAL";
    else
        qDebug()<<"type:VIP";
}

bool User::operator==(const User &user) const
{
    return this->getAccount()==user.getAccount();
}
