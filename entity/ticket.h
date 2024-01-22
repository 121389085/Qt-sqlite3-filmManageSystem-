#ifndef TICKET_H
#define TICKET_H

#include <QString>



class Ticket
{
public:
    Ticket();
    Ticket(const int);
    Ticket(const int,const int,const QString&);
    int getTid() const;
    void setTid(int value);

    int getUid() const;
    void setUid(int value);

    int getSeid() const;
    void setSeid(int value);

    QString getSeat() const;
    void setSeat(const QString &value);

    void print();
private:
    int tid;
    int uid;
    int seid;
    QString seat;
};

#endif // TICKET_H
