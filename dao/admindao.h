#ifndef ADMINDAO_H
#define ADMINDAO_H

#include <entity/admin.h>

class AdminDao
{
public:
    AdminDao();
    virtual ~AdminDao(){}
    virtual bool insertAdmin(const Admin&) = 0;
    virtual bool deleteAdmin(const Admin&) = 0;
    virtual bool updateAdmin(const Admin&) = 0;
    virtual QVector<Admin> selectAllAdmin() = 0;
};

#endif // ADMINDAO_H
