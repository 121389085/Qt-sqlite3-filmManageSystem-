#ifndef FORMSESSIONMANAGE_H
#define FORMSESSIONMANAGE_H

#include <QWidget>
#include "service/filmserviceimpl.h"
#include "service/cinemaserviceimpl.h"
#include "service/screenserviceimpl.h"
#include "service/sessionserviceimpl.h"
enum OPENMODE
{
    ADDMODE,
    UPDATEMODE
};

namespace Ui {
class FormSessionManage;
}

class FormSessionManage : public QWidget
{
    Q_OBJECT

public:
    explicit FormSessionManage(QWidget *parent = nullptr);
    explicit FormSessionManage(const int seid,QWidget *parent = nullptr);
    ~FormSessionManage();
    void updateFilmList();
    void upadteCinemaList();
    void upadteScreenList();
    void showByUpdateMode();
    void closeEvent(QCloseEvent *event) override;
signals:
    void signalClose();
private slots:
    void on_saveButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_timeEdit_userTimeChanged(const QTime &time);

    void on_filmComboBox_currentTextChanged(const QString &arg1);

    void on_screenComboBox_currentTextChanged(const QString &arg1);

    void on_cinemaComboBox_currentTextChanged(const QString &arg1);

    void on_cancelButton_clicked();

private:
    Ui::FormSessionManage *ui;
    FilmService* filmService;
    CinemaService* cinemaService;
    ScreenService* screenService;
    SessionService* sessionService;
    int currentFid;
    int currentCid;
    int currentScid;
    QString currentDate;
    QString currentTime;
    QString currentShowtime;//showtime由Date+Time组成
    int currentPrice;
    OPENMODE openMode;
    int seid;
};

#endif // FORMSESSIONMANAGE_H
