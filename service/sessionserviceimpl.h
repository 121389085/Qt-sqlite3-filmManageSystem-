#ifndef SESSIONSERVICEIMPL_H
#define SESSIONSERVICEIMPL_H

#include "sessionservice.h"
#include "dao/sessiondaoimpl.h"
#include "filmserviceimpl.h"

class SessionServiceImpl : public SessionService
{
public:
    SessionServiceImpl();
    ~SessionServiceImpl();
    bool addSession(const Session &) override;
    bool deleteSessionBySeid(const int) override;
    bool upadteSession(const Session &) override;
    QVector<Session> getAllSession() override;
    QVector<Session> getSessionByFid(const int) override;
    Session getSessionBySeid(const int) override;
private:
    SessionDao* sessionDao;
    FilmService* filmService;
};

#endif // SESSIONSERVICEIMPL_H
