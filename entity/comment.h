#ifndef COMMENT_H
#define COMMENT_H

#include <QString>



class Comment
{
public:
    Comment();
    Comment(const int);
    Comment(const int,const QString&,const int);
    Comment(const QString&,const int);


    int getCoid() const;
    void setCoid(int value);

    QString getContent() const;
    void setContent(const QString &value);

    int getTid() const;
    void setTid(int value);

    void print();
private:
    int coid;
    QString content;
    int tid;
};

#endif // COMMENT_H
