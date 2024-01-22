#ifndef MAINWINDOWUSER_H
#define MAINWINDOWUSER_H

#include <QListWidget>
#include <QMainWindow>
#include "entity/user.h"
#include "service/filmserviceimpl.h"
#include "formbuyticket.h"
#include "commentwidget.h"
namespace Ui {
class MainWindowUser;
}

class MainWindowUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUser(const User&,QWidget *parent = nullptr);
    ~MainWindowUser();
    void initListWidget();
signals:
    void signalReturnLogin();
private slots:
    void sendReturnLogin();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void onReturnMainWindowUser();

    void onBuyHistory();
private:
    Ui::MainWindowUser *ui;
    QVector<QWidget*> widgetRubbish;
    FilmService* filmService;
    FormBuyTicket* formBuyTicket;
    CommentWidget* commentWidget;
    User user;
};

#endif // MAINWINDOWUSER_H
