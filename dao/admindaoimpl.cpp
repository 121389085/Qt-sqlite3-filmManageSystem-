#include "admindaoimpl.h"
#include <dbutil/dbutil.h>
#include <QMap>


AdminDaoImpl::AdminDaoImpl()
{

}

bool AdminDaoImpl::insertAdmin(const Admin &admin)
{
    QString account=admin.getAccount();
    QString password=admin.getPassword();
    QString sql="insert into admin(account,password)"
                " values(:account,:password)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":account",account);
    paramMap.insert(":password",password);
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool AdminDaoImpl::deleteAdmin(const Admin &)
{
    return false;
}

bool AdminDaoImpl::updateAdmin(const Admin &)
{
    return false;
}

QVector<Admin> AdminDaoImpl::selectAllAdmin()
{
    QString sql="select * from admin";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Admin aTemp;
    QVector<Admin> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        aTemp.setAccount(qTemp["account"]);
        aTemp.setPassword(qTemp["password"]);
        vTemp.push_back(aTemp);
    }
    return vTemp;
}
