#include "adminserviceimpl.h"

#include <QVector>

AdminServiceImpl::AdminServiceImpl()
    :adminDao(new AdminDaoImpl)
{

}

AdminServiceImpl::~AdminServiceImpl()
{
    delete adminDao;
}

bool AdminServiceImpl::Login(const QString &account, const QString &password)
{
    QVector<Admin> allAdmin=adminDao->selectAllAdmin();
    for(auto it=allAdmin.begin();it!=allAdmin.end();++it)
        if(*it==Admin(account,password))
            return true;
    return false;
}
