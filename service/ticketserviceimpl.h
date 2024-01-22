#ifndef TICKETSERVICEIMPL_H
#define TICKETSERVICEIMPL_H

#include "ticketservice.h"
#include "dao/ticketdaoimpl.h"


class TicketServiceImpl : public TicketService
{
public:
    TicketServiceImpl();
    ~TicketServiceImpl();
    bool buyTicket(const int, const int, const QString &) override;
    QVector<Ticket> getTicketByUid(const int) override;
    QVector<Ticket> getTicketBySeid(const int) override;
private:
    TicketDao* ticketDao;
};

#endif // TICKETSERVICEIMPL_H
