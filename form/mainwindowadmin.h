#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "service/filmserviceimpl.h"
#include "service/sessionserviceimpl.h"
#include "service/screenserviceimpl.h"
#include "form/formsessionmanage.h"
namespace Ui {
class MainWindowAdmin;
}

class MainWindowAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowAdmin(QWidget *parent = nullptr);
    ~MainWindowAdmin();
    void showEvent(QShowEvent *event) override;
    void initTableView();
    void updateTableView();
signals:
    void signalReturnLogin();
private slots:
    void on_SessionView_doubleClicked(const QModelIndex &index);

    void on_addButton_clicked();

    void sendReturnLogin();

    void onSessionManageClose();
    void on_deleteButton_clicked();

    void on_SessionView_clicked(const QModelIndex &index);

private:
    Ui::MainWindowAdmin *ui;
    FormSessionManage* sessionManage;
    QStandardItemModel* model;//tableView的数据model
    FilmService* filmService;
    SessionService* sessionService;
    CinemaService* cinemaService;
    ScreenService* screenService;
    int currentSeid;
    QVector<QStandardItem*> QStandardItemRubbish;
};

#endif // MAINWINDOWADMIN_H
