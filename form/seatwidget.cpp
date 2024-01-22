#include "seatwidget.h"
#include <cmath>
SeatWidget::SeatWidget(const int num,QWidget *parent)
    :QWidget(parent),row(sqrt(num)),column(row)
{
    gridlayout=new QGridLayout(this);
    seat=new MyButton*[num];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            seat[i*column+j]=new MyButton;
            seat[i*column+j]->setPos(QString("第%1排,第%2座")
                         .arg(QString::number(i+1)).arg(QString::number(j+1)));
            gridlayout->addWidget(seat[i*column+j],i,j);
            connect(seat[i*column+j],&MyButton::signalPos,
                    this,&SeatWidget::onSelectSeat);
        }
    }

}

void SeatWidget::onSelectSeat(const MyButton* button)
{

    if(button->getStatus()==SELECTED)
    {
        seatList.insert(button->getPos(),1);
    }
    if(button->getStatus()==UNSELECTED)
    {
        auto it=seatList.find(button->getPos());
        seatList.erase(it);
    }
    emit signalseatList(seatList);
}
