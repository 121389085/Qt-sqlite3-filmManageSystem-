#include "formselectseat.h"
#include "ui_formselectseat.h"

FormSelectSeat::FormSelectSeat(const int num,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSelectSeat),seatWidget(new SeatWidget(num))
{
    ui->setupUi(this);
    connect(seatWidget,&SeatWidget::signalseatList,
                this,&FormSelectSeat::onSeatList);
    initListWidget();
}

FormSelectSeat::~FormSelectSeat()
{
    delete ui;
    delete seatWidget;
}

void FormSelectSeat::initListWidget()
{
    QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(0,850));
    ui->listWidget->setItemWidget(item,seatWidget);
}

void FormSelectSeat::closeEvent(QCloseEvent *event)
{
    emit signalCancel();
}


void FormSelectSeat::onSeatList(const QMap<QString, int> &seatList)
{
    selectInfo.clear();
    auto it=seatList.begin();
    for (;it!=seatList.end();it++)
    {
        selectInfo+=it.key()+",";
    }
    int index=selectInfo.size()-1;
    if(index>0)
        selectInfo=selectInfo.left(index);
    ui->textBrowser->setText(selectInfo);
}

void FormSelectSeat::on_definiteButton_clicked()
{
    this->hide();
    emit signalDefinite();
}

void FormSelectSeat::on_cancelButton_clicked()
{
    this->close();
}

QString FormSelectSeat::getSelectInfo() const
{
    return selectInfo;
}
