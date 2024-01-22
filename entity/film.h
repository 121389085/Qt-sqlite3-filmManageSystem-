#ifndef FILM_H
#define FILM_H

#include <QString>



class Film
{
public:
    Film();
    Film(const QString& fname,const QString& introduction,const QString& imagData,const int);
    int getFid() const;
    void setFid(int value);

    QString getFname() const;
    void setFname(const QString &value);

    QString getIntroduction() const;
    void setIntroduction(const QString &value);

    QString getPreview() const;
    void setPreview(const QString &value);

    int getDuration() const;
    void setDuration(const int value);

    void print();

private:
    int fid;
    QString fname;
    QString introduction;
    QString preview;
    int duration;
};

#endif // FILM_H
