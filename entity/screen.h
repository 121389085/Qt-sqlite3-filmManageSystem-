#ifndef SCREEN_H
#define SCREEN_H

#include <QString>



class Screen
{
public:
    Screen();
    Screen(const QString&,const int,const int);

    int getScid() const;
    void setScid(int value);

    QString getScname() const;
    void setScname(const QString &value);

    int getNum() const;
    void setNum(int value);

    int getCid() const;
    void setCid(int value);

    void print();
private:
    int scid;
    QString scname;
    int num;
    int cid;
};

#endif // SCREEN_H
