#include "comment.h"
#include <QDebug>
Comment::Comment()
{
    coid=0;
}

Comment::Comment(const int coid)
{
    this->coid=coid;
}

Comment::Comment(const int coid, const QString &content, const int tid)
{
    this->coid=coid;
    this->content=content;
    this->tid=tid;
}

Comment::Comment(const QString &content, const int tid)
{
    this->content=content;
    this->tid=tid;
}

int Comment::getCoid() const
{
    return coid;
}

void Comment::setCoid(int value)
{
    coid = value;
}

QString Comment::getContent() const
{
    return content;
}

void Comment::setContent(const QString &value)
{
    content = value;
}

int Comment::getTid() const
{
    return tid;
}

void Comment::setTid(int value)
{
    tid = value;
}

void Comment::print()
{
    qDebug()<<"评论id:"<<coid;
    qDebug()<<"评论内容:"<<content;
    qDebug()<<"票id:"<<tid;
}
