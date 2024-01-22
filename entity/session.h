#ifndef SESSION_H
#define SESSION_H

#include <QDate>
#include <QString>


class Session
{
public:
    Session();
    Session(const int);
    Session(const int,const int,const QString&,const double,const int);
    Session(const int,const QString&,const double,const int);
    int getSeid() const;
    void setSeid(int value);

    int getScid() const;
    void setScid(int value);

    QString getShowtime() const;
    void setShowtime(const QString &value);

    QDate getShowDate() const;
    QTime getshowTime() const;

    double getPrice() const;
    void setPrice(double value);

    int getFid() const;
    void setFid(int value);

    bool operator<(const Session&) const;

    void print();
private:
    int seid;
    int scid;
    QString showtime;
    double price;
    int fid;
};

#endif // SESSION_H
