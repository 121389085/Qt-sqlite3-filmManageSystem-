#include "formbuyticket.h"
#include "ui_formbuyticket.h"

#include <QMessageBox>
#include <QDebug>

FormBuyTicket::FormBuyTicket(const Film &film, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormBuyTicket),film(film),sessionService(new SessionServiceImpl),
    screenService(new ScreenServiceImpl),cinemaService(new CinemaServiceImpl)
{
    ui->setupUi(this);
    this->setWindowTitle(film.getFname()+"场次列表");
    model=new QStandardItemModel(ui->tableView);
    currentSeid=0;
    initTableView();
}

FormBuyTicket::FormBuyTicket(const User &user, const Film &film, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormBuyTicket),film(film),user(user),
    sessionService(new SessionServiceImpl),screenService(new ScreenServiceImpl),
    cinemaService(new CinemaServiceImpl),ticketService(new TicketServiceImpl)
{
    ui->setupUi(this);
    formSelectSeat=nullptr;
    this->setWindowTitle(film.getFname()+"场次列表");
    model=new QStandardItemModel(ui->tableView);
    currentSeid=0;
    initTableView();
}

FormBuyTicket::~FormBuyTicket()
{
    delete ui;
    delete sessionService;
    delete screenService;
    delete cinemaService;
    delete ticketService;
    qDeleteAll(QStandardItemrubbish);
}

void FormBuyTicket::initTableView()
{
    // 设置表头
    model->setHorizontalHeaderLabels({"场次id","影院",
                                      "放映厅","放映时间","价格"});

    //确保列的宽度会自动伸缩以填充整个QTableView的宽度
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置选择行为为选择整行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QVector<Session> sessionByFname=sessionService->getSessionByFid(film.getFid());
    if(sessionByFname.count()==0)
    {
        // 将数据模型设置给表格视图
        ui->tableView->setModel(model);
        QStandardItem* itemp=new QStandardItem("您选择的电影暂无场次");
        QStandardItemrubbish.push_back(itemp);
        model->appendRow(itemp);
        return;
    }

    QList<QStandardItem*>* temp=new QList<QStandardItem*>[sessionByFname.count()];
    for(int i=0;i<sessionByFname.count();i++)
    {
        QString seid=QString::number(sessionByFname[i].getSeid());
        QStandardItem* itemp=new QStandardItem(seid);
        temp[i].push_back(itemp);


//        QString fname=filmService->getFilmNameByFid(allSession[i].getFid());
//        itemp=new QStandardItem(fname);
//        temp[i].push_back(itemp);
//        QStandardItemrubbish.push_back(itemp);

        int scid=sessionByFname[i].getScid();
        int cid=screenService->getCidByScid(scid);
        QString cname=cinemaService->getCnameByCid(cid);
        itemp=new QStandardItem(cname);
        temp[i].push_back(itemp);
        QStandardItemrubbish.push_back(itemp);

        QString scname=screenService->getScnameByScid(scid);
        itemp=new QStandardItem(scname);
        temp[i].push_back(itemp);
        QStandardItemrubbish.push_back(itemp);

        QString showtime=sessionByFname[i].getShowtime();
        itemp=new QStandardItem(showtime);
        temp[i].push_back(itemp);
        QStandardItemrubbish.push_back(itemp);

        QString price=QString::number(sessionByFname[i].getPrice());
        itemp=new QStandardItem(price);
        temp[i].push_back(itemp);
        QStandardItemrubbish.push_back(itemp);

        model->appendRow(temp[i]);
    }

    // 将数据模型设置给表格视图
    ui->tableView->setModel(model);
}

void FormBuyTicket::closeEvent(QCloseEvent *event)
{
    emit signalReturnMainWindowUser();
}

void FormBuyTicket::on_buyButton_clicked()
{
    if(currentSeid==0)
    {
        QMessageBox::information(this,"购买失败","请先选择场次再点击购买");
        return;
    }
    Session session=sessionService->getSessionBySeid(currentSeid);
    Screen screen=screenService->getScreenByScid(session.getScid());
    formSelectSeat=new FormSelectSeat(screen.getNum());
    connect(formSelectSeat,&FormSelectSeat::signalDefinite,this,&FormBuyTicket::onDefiniteSeat);
    connect(formSelectSeat,&FormSelectSeat::signalCancel,this,&FormBuyTicket::onCancelSeat);
    formSelectSeat->show();
}

void FormBuyTicket::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        // 获取整行的QModelIndex
        QModelIndex rowModelIndex = index.sibling(index.row(), 0);

        // 使用索引获取数据模型中的数据
        QVariant data = rowModelIndex.data();
        currentSeid=data.toInt();
    }

}

void FormBuyTicket::onDefiniteSeat()
{
    currentSeat=formSelectSeat->getSelectInfo();
    QStringList data=currentSeat.split(",");
    bool result;
    QString sigleSeat;
    for(int i=0;i<data.count();i=i+2)
    {
        sigleSeat=data[i]+","+data[i+1];
        result=ticketService->buyTicket(user.getUid(),currentSeid,sigleSeat);
        if(!result)
            break;
    }
    if(result)
    {
        QMessageBox::information(this,"购买成功","购买成功");
        delete formSelectSeat;
    }
    else
    {
        QMessageBox::information(this,"购买失败","购买失败");
        delete formSelectSeat;
    }
}

void FormBuyTicket::onCancelSeat()
{
    delete formSelectSeat;
    formSelectSeat=nullptr;
}
