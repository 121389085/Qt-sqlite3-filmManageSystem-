 #ifndef COMMENTDAO_H
#define COMMENTDAO_H

#include <entity/comment.h>



class CommentDao
{
public:
    CommentDao();
    virtual ~CommentDao(){}
    virtual bool insertComment(const Comment&) = 0;
    virtual bool deleteCommentByCoid(const int) = 0;
    virtual bool updateComment(const Comment&) = 0;
    virtual QVector<Comment> selectAllComment() = 0;
    virtual Comment selectCommentByTid(const int) = 0;

};

#endif // COMMENTDAO_H
