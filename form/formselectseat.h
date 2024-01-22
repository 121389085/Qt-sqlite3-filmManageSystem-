#ifndef FORMSELECTSEAT_H
#define FORMSELECTSEAT_H

#include <QWidget>
#include "seatwidget.h"
namespace Ui {
class FormSelectSeat;
}

class FormSelectSeat : public QWidget
{
    Q_OBJECT

public:
    explicit FormSelectSeat(const int num,QWidget *parent = nullptr);
    ~FormSelectSeat();
    void initListWidget();
    void closeEvent(QCloseEvent *event) override;
    QString getSelectInfo() const;

private slots:
    void onSeatList(const QMap<QString, int> &seatList);
    void on_definiteButton_clicked();
    void on_cancelButton_clicked();

signals:
    void signalDefinite();
    void signalCancel();
private:
    Ui::FormSelectSeat *ui;
    SeatWidget* seatWidget;
    QString selectInfo;
};

#endif // FORMSELECTSEAT_H
