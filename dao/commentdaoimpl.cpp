#include "commentdaoimpl.h"

#include <QVector>

#include <dbutil/dbutil.h>

CommentDaoImpl::CommentDaoImpl()
{

}

bool CommentDaoImpl::insertComment(const Comment& comment)
{
    QString content=comment.getContent();
    int tid=comment.getTid();
    QString sql="insert into comment(content,tid)"
                " values(:content,:tid)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":content",content);
    paramMap.insert(":tid",QString::number(tid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool CommentDaoImpl::deleteCommentByCoid(const int coid)
{
    return false;
}

bool CommentDaoImpl::updateComment(const Comment &)
{
    return false;
}

QVector<Comment> CommentDaoImpl::selectAllComment()
{
    QString sql="select * from comment";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Comment cTemp;
    QVector<Comment> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        cTemp.setCoid(qTemp["coid"].toInt());
        cTemp.setContent(qTemp["content"]);
        cTemp.setTid(qTemp["tid"].toInt());
        vTemp.push_back(cTemp);
    }
    return vTemp;
}

Comment CommentDaoImpl::selectCommentByTid(const int tid)
{
    QString sql="select * from comment where tid=:tid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":tid",QString::number(tid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Comment cTemp;
    auto it=temp.begin();
    if(it==temp.end())
        return Comment(0);
    QMap<QString,QString> qTemp=*it;
    cTemp.setCoid(qTemp["coid"].toInt());
    cTemp.setContent(qTemp["content"]);
    cTemp.setTid(qTemp["tid"].toInt());
    return cTemp;
}
