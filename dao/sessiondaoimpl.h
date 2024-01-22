#ifndef SESSIONDAOIMPL_H
#define SESSIONDAOIMPL_H

#include "sessiondao.h"



class SessionDaoImpl : public SessionDao
{
public:
    SessionDaoImpl();
    bool intserSession(const Session &) override;
    bool deleteSessionBySeid(const int) override;
    bool updateSession(const Session &) override;
    QVector<Session> selectAllSession() override;
    Session selectSessionBySeid(const int) override;
    QVector<Session> selectSessionByScid(const int) override;
    QVector<Session> selectSessionByFid(const int) override;
};

#endif // SESSIONDAOIMPL_H
