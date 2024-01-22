#include "filmdaoimpl.h"
#include "dbutil/dbutil.h"
#include <QMap>

FilmDaoImpl::FilmDaoImpl()
{

}

bool FilmDaoImpl::insertFilm(const Film &film)
{
    QString fname=film.getFname();
    QString introduction=film.getIntroduction();
    QString preview=film.getPreview();
    int duration=film.getDuration();
    QString sql="insert into film(fname,introduction,preview,duration)"
                " values(:fname,:introduction,:preview,:duration)";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fname",fname);
    paramMap.insert(":introduction",introduction);
    paramMap.insert(":preview",preview);
    paramMap.insert(":duration",QString::number(duration));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool FilmDaoImpl::deleteFilmByFid(const int fid)
{
    QString sql="delete from film where fid=:fid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fid",QString::number(fid));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

bool FilmDaoImpl::updateFilm(const Film &film)
{
    QString sql="update film set fname=:fname,introduction=:introduction,"
                "preview=:preview,duration=:duration"
                " where fid=:fid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fname",film.getFname());
    paramMap.insert(":introduction",film.getIntroduction());
    paramMap.insert(":preview",film.getPreview());
    paramMap.insert(":duration",QString::number(film.getDuration()));
    paramMap.insert(":fid",QString::number(film.getFid()));
    DbUtil* db=DbUtil::getInstance();
    bool result=db->execute(sql,paramMap);
    return result;
}

QVector<Film> FilmDaoImpl::selectAllFilm()
{
    QString sql="select * from film";
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectAllResult(sql);
    Film fTemp;
    QVector<Film> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        fTemp.setFid(qTemp["fid"].toInt());
        fTemp.setFname(qTemp["fname"]);
        fTemp.setIntroduction(qTemp["introduction"]);
        fTemp.setPreview(qTemp["preview"]);
        fTemp.setDuration(qTemp["duration"].toInt());
        vTemp.push_back(fTemp);
    }
    return vTemp;
}

QVector<Film> FilmDaoImpl::selectFilmByFname(const QString &fname)
{
    QString sql="select * from film where fname LIKE :fname";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fname","%"+fname+"%");
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Film fTemp;
    QVector<Film> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        fTemp.setFname(qTemp["fname"]);
        fTemp.setIntroduction(qTemp["introduction"]);
        fTemp.setPreview(qTemp["preview"]);
        fTemp.setDuration(qTemp["duration"].toInt());
        vTemp.push_back(fTemp);
    }
    return vTemp;
}

Film FilmDaoImpl::selectFilmByFid(const int fid)
{
    QString sql="select * from film where fid = :fid";
    QMap<QString,QString> paramMap;
    paramMap.insert(":fid",QString::number(fid));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Film fTemp;
    auto it=temp.begin();
    if(it==temp.end())
        return fTemp;//fid为0表示没找到
    QMap<QString,QString> qTemp=*it;
    fTemp.setFname(qTemp["fname"]);
    fTemp.setIntroduction(qTemp["introduction"]);
    fTemp.setPreview(qTemp["preview"]);
    fTemp.setDuration(qTemp["duration"].toInt());
    return fTemp;
}

QVector<Film> FilmDaoImpl::selectFilmGreatByDuration(const int duration)
{
    QString sql="select * from film where duration > :duration";
    QMap<QString,QString> paramMap;
    paramMap.insert(":duration",QString::number(duration));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Film fTemp;
    QVector<Film> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        fTemp.setFname(qTemp["fname"]);
        fTemp.setIntroduction(qTemp["introduction"]);
        fTemp.setPreview(qTemp["preview"]);
        fTemp.setDuration(qTemp["duration"].toInt());
        vTemp.push_back(fTemp);
    }
    return vTemp;
}

QVector<Film> FilmDaoImpl::selectFilmLessByDuration(const int duration)
{
    QString sql="select * from film where duration < :duration";
    QMap<QString,QString> paramMap;
    paramMap.insert(":duration",QString::number(duration));
    DbUtil* db=DbUtil::getInstance();
    QVector<QMap<QString, QString>> temp=db->selectResultByCondition(sql,paramMap);
    Film fTemp;
    QVector<Film> vTemp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        QMap<QString,QString> qTemp=*it;
        fTemp.setFname(qTemp["fname"]);
        fTemp.setIntroduction(qTemp["introduction"]);
        fTemp.setPreview(qTemp["preview"]);
        fTemp.setDuration(qTemp["duration"].toInt());
        vTemp.push_back(fTemp);
    }
    return vTemp;
}
