#ifndef COMMENTDAOIMPL_H
#define COMMENTDAOIMPL_H

#include "commentdao.h"



class CommentDaoImpl : public CommentDao
{
public:
    CommentDaoImpl();
    ~CommentDaoImpl(){}
    bool insertComment(const Comment &) override;
    bool deleteCommentByCoid(const int) override;
    bool updateComment(const Comment &) override;
    QVector<Comment> selectAllComment() override;
    Comment selectCommentByTid(const int) override;
};

#endif // COMMENTDAOIMPL_H
