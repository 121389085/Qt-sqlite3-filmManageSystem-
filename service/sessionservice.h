#ifndef SESSIONSERVICE_H
#define SESSIONSERVICE_H

#include "entity/session.h"



class SessionService
{
public:
    SessionService();
    virtual ~SessionService(){}
    virtual bool addSession(const Session&) = 0;
    virtual bool deleteSessionBySeid(const int) = 0;
    virtual bool upadteSession(const Session&) = 0;
    virtual QVector<Session> getAllSession() = 0;
    virtual QVector<Session> getSessionByFid(const int) = 0;
    virtual Session getSessionBySeid(const int) = 0;
};

#endif // SESSIONSERVICE_H
