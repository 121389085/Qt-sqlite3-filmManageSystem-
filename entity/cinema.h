#ifndef CINEMA_H
#define CINEMA_H

#include <QString>



class Cinema
{
public:
    Cinema();
    Cinema(const int,const QString&,const QString&);
    Cinema(const QString&,const QString&);

    int getCid() const;
    void setCid(int value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QString getCname() const;
    void setCname(const QString &value);

    void print();
private:
    int cid;
    QString address;
    QString cname;
};

#endif // CINEMA_H
