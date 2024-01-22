#ifndef SEATWIDGET_H
#define SEATWIDGET_H

#include "mybutton.h"

#include <QGridLayout>
#include <QMap>
#include <QWidget>

class SeatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SeatWidget(const int num,QWidget *parent = nullptr);

signals:
    void signalseatList(const QMap<QString,int>&);
private:
    MyButton** seat;
    QGridLayout* gridlayout;
    int row;
    int column;
    QString currentSeat;
    QMap<QString,int> seatList;
private slots:
    void onSelectSeat(const MyButton* button);
};

#endif // SEATWIDGET_H
