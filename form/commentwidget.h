#ifndef COMMENTWIDGET_H
#define COMMENTWIDGET_H

#include <QListWidget>
#include <QWidget>
#include "entity/film.h"
#include "entity/user.h"
#include "service/commentserviceimpl.h"
#include "service/ticketserviceimpl.h"
#include "service/sessionservice.h"
#include "service/filmserviceimpl.h"
#include "service/screenserviceimpl.h"
#include "service/cinemaserviceimpl.h"
namespace Ui {
class CommentWidget;
}

class CommentWidget : public QWidget
{
    Q_OBJECT
//电影->场次->票->评论
public:
    explicit CommentWidget(const User&, QWidget *parent = nullptr);
    ~CommentWidget();
    void initComment();
    void closeEvent(QCloseEvent *event) override;
signals:
    void signalReturnMainWindowUser();
private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::CommentWidget *ui;
    CommentService* commentService;
    TicketService* ticketService;
    SessionService* sessionService;
    FilmService* filmServie;
    ScreenService* screenService;
    CinemaService* cinemaService;
    User user;
    int currentTid;
};

#endif // COMMENTWIDGET_H
