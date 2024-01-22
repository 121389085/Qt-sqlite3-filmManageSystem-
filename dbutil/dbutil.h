#ifndef DBUTIL_H
#define DBUTIL_H

#include <QMap>
#include <QString>
#include <QSqlDatabase>

class DbUtil
{
public:
    static DbUtil* getInstance();
    void createConnection();
    void destroyConnection();
    bool execute(const QString&,const QMap<QString,QString>&);
    QVector<QMap<QString,QString>> selectAllResult(const QString&);
    QVector<QMap<QString,QString>> selectResultByCondition(const QString&,const QMap<QString, QString>&);
private:
    QSqlDatabase connection;
    static DbUtil* instance;
};

#endif // DBUTIL_H
