#ifndef ADMINSERVICEIMPL_H
#define ADMINSERVICEIMPL_H

#include "adminservice.h"
#include "dao/admindaoimpl.h"


class AdminServiceImpl : public AdminService
{
public:
    AdminServiceImpl();
    ~AdminServiceImpl();
    bool Login(const QString &, const QString &) override;
private:
    AdminDao* adminDao;
};

#endif // ADMINSERVICEIMPL_H
