#ifndef COMMENTSERVICE_H
#define COMMENTSERVICE_H
#include "entity/comment.h"

class CommentService
{
public:
    CommentService();
    virtual ~CommentService(){}
    virtual bool viewByTid(const int,const QString&) = 0;
    virtual QVector<Comment> getAllComment() = 0;
    virtual Comment getCommentByTid(const int) = 0;
    virtual QVector<Comment> getCommentBySeid(const int) = 0;
    virtual QVector<Comment> getCommentByUid(const int) = 0;
    virtual QVector<Comment> getCommentByFid(const int) = 0;
};

#endif // COMMENTSERVICE_H
