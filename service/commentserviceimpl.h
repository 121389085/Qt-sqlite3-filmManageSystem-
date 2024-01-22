#ifndef COMMENTSERVICEIMPL_H
#define COMMENTSERVICEIMPL_H

#include "commentservice.h"
#include "dao/commentdaoimpl.h"
#include "ticketserviceimpl.h"
#include "sessionserviceimpl.h"
class CommentServiceImpl : public CommentService
{
public:
    CommentServiceImpl();
    ~CommentServiceImpl();
    bool viewByTid(const int,const QString&) override;
    Comment getCommentByTid(const int) override;
    QVector<Comment> getAllComment() override;
    QVector<Comment> getCommentBySeid(const int) override;
    QVector<Comment> getCommentByFid(const int) override;
    QVector<Comment> getCommentByUid(const int) override;
private:
    CommentDao* commentDao;
    TicketService* ticketService;
    SessionService* sessionSerive;
};

#endif // COMMENTSERVICEIMPL_H
