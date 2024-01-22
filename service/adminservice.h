#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include <QString>



class AdminService
{
public:
    AdminService();
    virtual ~AdminService(){}
    virtual bool Login(const QString&,const QString&) = 0;
};

#endif // ADMINSERVICE_H
