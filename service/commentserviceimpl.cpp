#include "commentserviceimpl.h"

#include <QVector>

CommentServiceImpl::CommentServiceImpl()
    :commentDao(new CommentDaoImpl),ticketService(new TicketServiceImpl)
{

}

CommentServiceImpl::~CommentServiceImpl()
{
    delete commentDao;
}

bool CommentServiceImpl::viewByTid(const int tid,const QString& text)
{
    return commentDao->insertComment(Comment(text,tid));
}

Comment CommentServiceImpl::getCommentByTid(const int tid)
{
    return commentDao->selectCommentByTid(tid);
}

QVector<Comment> CommentServiceImpl::getAllComment()
{
    return commentDao->selectAllComment();
}

QVector<Comment> CommentServiceImpl::getCommentBySeid(const int seid)
{
    QVector<Ticket> TicketBySession=ticketService->getTicketBySeid(seid);
    QVector<Comment> CommentByTickets;
    for(auto it=TicketBySession.begin();it!=TicketBySession.end();it++)
    {
        Comment temp=getCommentByTid(it->getTid());
        CommentByTickets.push_back(temp);
    }
    return CommentByTickets;
}

QVector<Comment> CommentServiceImpl::getCommentByFid(const int fid)
{
    QVector<Session> SessionByFilm=sessionSerive->getSessionByFid(fid);
    QVector<Ticket> TicketBySession;
    QVector<Comment> commentByFilm;
    for(auto it=SessionByFilm.begin();it!=SessionByFilm.end();it++)
    {
        QVector<Ticket> Temp=ticketService->getTicketBySeid(it->getSeid());
        for(auto it2=Temp.begin();it2!=Temp.end();it2++)
        {
            Comment comment=getCommentByTid(it2->getTid());
            commentByFilm.push_back(comment);
        }
    }
    return commentByFilm;
}

QVector<Comment> CommentServiceImpl::getCommentByUid(const int uid)
{
    QVector<Ticket> TicketByUser=ticketService->getTicketByUid(uid);
    QVector<Comment> commentByTickets;
    for(auto it=TicketByUser.begin();it!=TicketByUser.end();it++)
    {
        Comment temp=getCommentByTid(it->getTid());
        commentByTickets.push_back(temp);
    }
    return commentByTickets;
}
