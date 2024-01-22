#include "sessionserviceimpl.h"
#include <QVector>
#include <QDebug>
#include <QDate>
SessionServiceImpl::SessionServiceImpl()
    :sessionDao(new SessionDaoImpl),filmService(new FilmServiceImpl)
{

}

SessionServiceImpl::~SessionServiceImpl()
{
    delete sessionDao;
    delete filmService;
}

bool SessionServiceImpl::addSession(const Session &session)
{
    qDebug()<<"确定\nfid"<<session.getFid();
    //场次只能添加在8:00-22:00之间
    QTime time=session.getshowTime();
    if(time.hour()<8 || time.hour()>22)
        return false;

    //同一放映厅
    int scid=session.getScid();
    QVector<Session> sessionInSameScreen=sessionDao->selectSessionByScid(scid);
    if(sessionInSameScreen.count()==0)//放映厅没有场次,直接添加
        return sessionDao->intserSession(session);

    //同一放映厅是否同一天
    QVector<Session> sessionSameDay;
    for(auto it=sessionInSameScreen.begin();it!=sessionInSameScreen.end();it++)
        if(it->getShowDate()==session.getShowDate())
            sessionSameDay.push_back(*it);

    if(sessionSameDay.count()==0)//同一天没有场次,直接添加
        return sessionDao->intserSession(session);

    //同一天时间是否冲突(两个场次间隔十分钟)
    std::sort(sessionSameDay.begin(),sessionSameDay.end());//根据时间先后排好序重载<，根据showtime
    int fid=session.getFid();
    int duration=filmService->getFilmByFid(fid).getDuration();
    auto it=sessionSameDay.begin();
    for(;it!=sessionSameDay.end();it++)
    {
        int secondsTo=time.secsTo(it->getshowTime());//到指定时间需要秒数
        qDebug()<<secondsTo;
        int minutesTo=abs(secondsTo/60);//到指定时间需要分钟
        qDebug()<<minutesTo;
        int durationTemp=filmService->getFilmByFid(it->getFid()).getDuration();
        if(secondsTo < 0)//添加的session时间在*it之后
        {
            if(durationTemp+10>minutesTo)
            {
                continue;
                qDebug()<<"1111111\n\n11111";
            }
            else
            {
                qDebug()<<"2222222\n\n222222";
                auto next=it+1;
                if(next!=sessionSameDay.end())
                {
                    secondsTo=time.secsTo(next->getshowTime());
                    minutesTo=secondsTo/60;
                    if(minutesTo>=duration+10)
                        return sessionDao->intserSession(session);
                    else
                        continue;
                }
                else//是当天唯一的场次
                {
                    int secToEnd=it->getshowTime().secsTo(QTime::fromString("22:00:00"));//当天唯一场次距离22:00结束秒数
                    int minuteToEnd=secToEnd/60;
                    if(minuteToEnd>durationTemp+10)
                        return sessionDao->intserSession(session);
                    else
                        return false;
                }
            }
        }
        if(secondsTo == 0)//添加的session时间与*it相同
        {
            return false;
        }
        if(secondsTo > 0)//添加的session时间在*it之前
        {
            qDebug()<<"添加的\nsession时间\n在*it之前"<<fid<<duration;
            if(duration+10 <= minutesTo)
                return sessionDao->intserSession(session);
            else
                continue;
        }
    }
    return false;
}

bool SessionServiceImpl::deleteSessionBySeid(const int seid)
{
    return sessionDao->deleteSessionBySeid(seid);
}

bool SessionServiceImpl::upadteSession(const Session &session)
{
    qDebug()<<"确定\nfid"<<session.getFid();
    //场次只能添加在8:00-22:00之间
    QTime time=session.getshowTime();
    if(time.hour()<8 || time.hour()>22)
        return false;

    //同一放映厅
    int scid=session.getScid();
    QVector<Session> sessionInSameScreen=sessionDao->selectSessionByScid(scid);
    if(sessionInSameScreen.count()==0)//放映厅没有场次,直接添加
        return sessionDao->updateSession(session);

    //同一放映厅是否同一天
    QVector<Session> sessionSameDay;
    for(auto it=sessionInSameScreen.begin();it!=sessionInSameScreen.end();it++)
        if(it->getShowDate()==session.getShowDate())
            sessionSameDay.push_back(*it);

    if(sessionSameDay.count()==0)//同一天没有场次,直接添加
        return sessionDao->updateSession(session);

    if(sessionSameDay.count()==1 && sessionSameDay[0].getSeid()==session.getSeid())//同一天有场次且为自己,直接添加
        return sessionDao->updateSession(session);

    //同一天时间是否冲突(两个场次间隔十分钟)
    std::sort(sessionSameDay.begin(),sessionSameDay.end());//根据时间先后排好序重载<，根据showtime
    int fid=session.getFid();
    int duration=filmService->getFilmByFid(fid).getDuration();
    auto it=sessionSameDay.begin();
    for(;it!=sessionSameDay.end();it++)
    {
        if(it->getSeid()==session.getSeid())//跳过要修改的场次
            continue;
        int secondsTo=time.secsTo(it->getshowTime());//到指定时间需要秒数
        qDebug()<<secondsTo;
        int minutesTo=abs(secondsTo/60);//到指定时间需要分钟
        qDebug()<<minutesTo;
        int durationTemp=filmService->getFilmByFid(it->getFid()).getDuration();
        if(secondsTo < 0)//添加的session时间在*it之后
        {
            if(durationTemp+10>minutesTo)
            {
                continue;
                qDebug()<<"1111111\n\n11111";
            }
            else
            {
                qDebug()<<"2222222\n\n222222";
                auto next=it+1;
                if(next!=sessionSameDay.end())
                {
                    secondsTo=time.secsTo(next->getshowTime());
                    minutesTo=secondsTo/60;
                    if(minutesTo>=duration+10)
                        return sessionDao->updateSession(session);
                    else
                        continue;
                }
                else//是当天唯一的场次
                {
                    int secToEnd=it->getshowTime().secsTo(QTime::fromString("22:00:00"));//当天唯一场次距离22:00结束秒数
                    int minuteToEnd=secToEnd/60;
                    if(minuteToEnd>durationTemp+10)
                        return sessionDao->updateSession(session);
                    else
                        return false;
                }
            }
        }
//        if(secondsTo == 0)//添加的session时间与*it相同
//        {
//            return false;
//        }
        if(secondsTo > 0)//添加的session时间在*it之前
        {
            qDebug()<<"添加的\nsession时间\n在*it之前"<<fid<<duration;
            if(duration+10 <= minutesTo)
                return sessionDao->updateSession(session);
            else
                continue;
        }
    }
    return false;
}

QVector<Session> SessionServiceImpl::getAllSession()
{
    return sessionDao->selectAllSession();
}

QVector<Session> SessionServiceImpl::getSessionByFid(const int fid)
{
    return sessionDao->selectSessionByFid(fid);
}

Session SessionServiceImpl::getSessionBySeid(const int seid)
{
    return sessionDao->selectSessionBySeid(seid);
}
