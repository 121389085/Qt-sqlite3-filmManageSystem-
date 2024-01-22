#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"
#include <QDebug>
#include <QMessageBox>
MainWindowAdmin::MainWindowAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowAdmin),
    filmService(new FilmServiceImpl),sessionService(new SessionServiceImpl),
    cinemaService(new CinemaServiceImpl),screenService(new ScreenServiceImpl)
{
    ui->setupUi(this);
    sessionManage=nullptr;
    connect(ui->actionExit, &QAction::triggered,
            this, &MainWindowAdmin::sendReturnLogin);
    model=new QStandardItemModel(ui->SessionView);
    currentSeid=0;
    initTableView();
}

MainWindowAdmin::~MainWindowAdmin()
{
    delete ui;
    delete filmService;
    delete sessionService;
    delete cinemaService;
    qDeleteAll(QStandardItemRubbish);
}

void MainWindowAdmin::showEvent(QShowEvent *event)
{
    updateTableView();
}

void MainWindowAdmin::initTableView()
{
    // 设置表头
    model->setHorizontalHeaderLabels({"场次id","电影名称","影院",
                                      "放映厅","放映时间","价格"});

    //确保列的宽度会自动伸缩以填充整个QTableView的宽度
    ui->SessionView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置选择行为为选择整行
    ui->SessionView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 将数据模型设置给表格视图
    ui->SessionView->setModel(model);
}

void MainWindowAdmin::updateTableView()
{
        // 添加数据
//        QList<QStandardItem*> rowData1 = {new QStandardItem("John"), new QStandardItem("25"), new QStandardItem("New York")};
//        QList<QStandardItem*> rowData2 = {new QStandardItem("Alice"), new QStandardItem("30"), new QStandardItem("London")};
    qDeleteAll(QStandardItemRubbish);
    QStandardItemRubbish.clear();
    model->clear();
    QVector<Session> allSession=sessionService->getAllSession();
    if(allSession.count()==0)
        return;
    QList<QStandardItem*>* temp=new QList<QStandardItem*>[allSession.count()];
        for(int i=0;i<allSession.count();i++)
        {
            QString seid=QString::number(allSession[i].getSeid());
            QStandardItem* itemp=new QStandardItem(seid);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            QString fname=filmService->getFilmNameByFid(allSession[i].getFid());
            itemp=new QStandardItem(fname);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            int scid=allSession[i].getScid();
            int cid=screenService->getCidByScid(scid);
            QString cname=cinemaService->getCnameByCid(cid);
            itemp=new QStandardItem(cname);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            QString scname=screenService->getScnameByScid(scid);
            itemp=new QStandardItem(scname);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            QString showtime=allSession[i].getShowtime();
            itemp=new QStandardItem(showtime);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            QString price=QString::number(allSession[i].getPrice());
            itemp=new QStandardItem(price);
            temp[i].push_back(itemp);
            QStandardItemRubbish.push_back(itemp);

            model->appendRow(temp[i]);
        }
            // 插入一行数据
//        model->appendRow(rowData1);
//        model->appendRow(rowData2);
}

void MainWindowAdmin::on_SessionView_doubleClicked(const QModelIndex &index)
{
//    sessionManage=new FormSessionManage;
//    connect(sessionManage,&FormSessionManage::signalClose,
//            this,&MainWindowAdmin::onSessionManageClose);
//    sessionManage->show();
    int seid=0;
    if (index.isValid())
    {
        // 获取整行的QModelIndex
        QModelIndex rowModelIndex = index.sibling(index.row(), 0);

//        // 获取用户双击的行和列
//        int row = rowModelIndex.row();
//        int col = index.column();

        // 使用索引获取数据模型中的数据
        QVariant data = rowModelIndex.data();
        seid=data.toInt();
//         // 在这里可以添加处理双击操作的逻辑
//        qDebug() << "Double clicked on row" << row << "column" << col << "with data:" << data.toString();
    }
        sessionManage=new FormSessionManage(seid);
        connect(sessionManage,&FormSessionManage::signalClose,
                this,&MainWindowAdmin::onSessionManageClose);
        sessionManage->show();
}

void MainWindowAdmin::on_addButton_clicked()
{
    sessionManage=new FormSessionManage;
    connect(sessionManage,&FormSessionManage::signalClose,
            this,&MainWindowAdmin::onSessionManageClose);
    sessionManage->show();
}

void MainWindowAdmin::sendReturnLogin()
{
    this->hide();
    qDebug()<<"emit signalReturnLogin()";
    emit signalReturnLogin();
}

void MainWindowAdmin::onSessionManageClose()
{
    updateTableView();
    delete sessionManage;
    sessionManage=nullptr;
}

void MainWindowAdmin::on_deleteButton_clicked()
{
    if(currentSeid==0)
    {
        QMessageBox::information(this,"删除失败","请先单击要删除的场次");
        return;
    }
    bool result=sessionService->deleteSessionBySeid(currentSeid);
    if(result)
        QMessageBox::information(this,"删除成功","删除成功");
    else
    {
        QMessageBox::information(this,"删除失败","删除失败");
        return;
    }
    updateTableView();
}

void MainWindowAdmin::on_SessionView_clicked(const QModelIndex &index)
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
