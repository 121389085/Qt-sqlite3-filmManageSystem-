#include "ticketserviceimpl.h"

#include <QVector>

TicketServiceImpl::TicketServiceImpl()
    :ticketDao(new TicketDaoImpl)
{

}

TicketServiceImpl::~TicketServiceImpl()
{
    delete ticketDao;
}

bool TicketServiceImpl::buyTicket(const int uid, const int seid, const QString &seat)
{
    return ticketDao->insertTicket(Ticket(uid,seid,seat));
}

QVector<Ticket> TicketServiceImpl::getTicketByUid(const int uid)
{
    return ticketDao->selectTicketByUid(uid);
}

QVector<Ticket> TicketServiceImpl::getTicketBySeid(const int seid)
{
    return ticketDao->selectTicketBySeid(seid);
}
