#ifndef FORMBUYTICKET_H
#define FORMBUYTICKET_H

#include <QStandardItemModel>
#include <QWidget>
#include "entity/film.h"
#include "entity/user.h"
#include "service/sessionserviceimpl.h"
#include "service/screenserviceimpl.h"
#include "service/cinemaserviceimpl.h"
#include "service/ticketserviceimpl.h"
#include "formselectseat.h"
namespace Ui {
class FormBuyTicket;
}

class FormBuyTicket : public QWidget
{
    Q_OBJECT

public:
    explicit FormBuyTicket(const Film&, QWidget *parent = nullptr);
    explicit FormBuyTicket(const User&, const Film&, QWidget *parent = nullptr);
    ~FormBuyTicket();
    void initTableView();
    void closeEvent(QCloseEvent *event) override;
signals:
    void signalReturnMainWindowUser();
private slots:
    void on_buyButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void onDefiniteSeat();

    void onCancelSeat();
private:
    Ui::FormBuyTicket *ui;
    Film film;
    User user;
    SessionService* sessionService;
    ScreenService* screenService;
    CinemaService* cinemaService;
    TicketService* ticketService;
    QStandardItemModel* model;//tableView的数据model
    QVector<QStandardItem*> QStandardItemrubbish;
    FormSelectSeat* formSelectSeat;
    int currentSeid;
    QString currentSeat;
};

#endif // FORMBUYTICKET_H
