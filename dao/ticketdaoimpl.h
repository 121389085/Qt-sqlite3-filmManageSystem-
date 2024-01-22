#ifndef TICKETDAOIMPL_H
#define TICKETDAOIMPL_H

#include "ticketdao.h"



class TicketDaoImpl : public TicketDao
{
public:
    TicketDaoImpl();
    ~TicketDaoImpl(){}
    bool insertTicket(const Ticket &) override;
    bool deleteTicketByTid(const int) override;
    bool updateTicket(const Ticket &) override;
    QVector<Ticket> selectTicketByUid(const int) override;
    QVector<Ticket> selectTicketBySeid(const int) override;
};

#endif // TICKETDAOIMPL_H
