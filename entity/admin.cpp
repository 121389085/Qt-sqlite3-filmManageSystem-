#include "admin.h"
#include <QDebug>
Admin::Admin()
{

}

Admin::Admin(const QString &account, const QString &password)
{
    this->account=account;
    this->password=password;
}

QString Admin::getAccount() const
{
    return account;
}

void Admin::setAccount(const QString &value)
{
    account = value;
}

QString Admin::getPassword() const
{
    return password;
}

void Admin::setPassword(const QString &value)
{
    password = value;
}

void Admin::print()
{
    qDebug()<<"account:"<<account;
    qDebug()<<"password:"<<password;
}

bool Admin::operator==(const Admin &admin)const
{
    return this->account==admin.getAccount()
            && this->password==admin.getPassword();
}
