#ifndef TICKETDAO_H
#define TICKETDAO_H

#include "entity/ticket.h"



class TicketDao
{
public:
    TicketDao();
    virtual ~TicketDao(){}
    virtual bool insertTicket(const Ticket&) = 0;
    virtual bool updateTicket(const Ticket&) = 0;
    virtual bool deleteTicketByTid(const int) = 0;
    virtual QVector<Ticket> selectTicketByUid(const int) = 0;
    virtual QVector<Ticket> selectTicketBySeid(const int) = 0;
};

#endif // TICKETDAO_H
