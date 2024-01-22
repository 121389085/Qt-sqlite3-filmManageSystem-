#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
public:
    Admin();
    Admin(const QString&,const QString&);
    QString getAccount() const;
    void setAccount(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    void print();
    bool operator==(const Admin&)const;
private:
    QString account;
    QString password;
};

#endif // ADMIN_H
