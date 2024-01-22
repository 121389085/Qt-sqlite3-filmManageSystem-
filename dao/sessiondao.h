#ifndef SESSIONDAO_H
#define SESSIONDAO_H

#include "entity/session.h"



class SessionDao
{
public:
    SessionDao();
    virtual ~SessionDao(){}
    virtual bool intserSession(const Session&) = 0;
    virtual bool deleteSessionBySeid(const int) = 0;
    virtual bool updateSession(const Session&) = 0;
    virtual QVector<Session> selectAllSession() = 0;
    virtual Session selectSessionBySeid(const int) = 0;
    virtual QVector<Session> selectSessionByScid(const int) = 0;
    virtual QVector<Session> selectSessionByFid(const int) = 0;
};

#endif // SESSIONDAO_H
