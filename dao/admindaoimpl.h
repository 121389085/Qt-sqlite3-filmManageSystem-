#ifndef ADMINDAOIMPL_H
#define ADMINDAOIMPL_H

#include "admindao.h"

class AdminDaoImpl : public AdminDao
{
public:
    AdminDaoImpl();
    bool insertAdmin(const Admin &) override;
    bool deleteAdmin(const Admin &) override;
    bool updateAdmin(const Admin &) override;
    QVector<Admin> selectAllAdmin() override;
};

#endif // ADMINDAOIMPL_H
