#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include <QString>

#include "entity/ticket.h"



class TicketService
{
public:
    TicketService();
    virtual ~TicketService(){}
    virtual bool buyTicket(const int,const int,const QString&) = 0;
    virtual QVector<Ticket> getTicketByUid(const int) = 0;
    virtual QVector<Ticket> getTicketBySeid(const int) = 0;
};

#endif // TICKETSERVICE_H
