#include "mainwindowuser.h"
#include "ui_mainwindowuser.h"
#include "filmwidget.h"


MainWindowUser::MainWindowUser(const User &user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowUser),filmService(new FilmServiceImpl),user(user)
{
    ui->setupUi(this);
    formBuyTicket=nullptr;
    commentWidget=nullptr;
    connect(ui->actionExit, &QAction::triggered,
            this, &MainWindowUser::sendReturnLogin);
    connect(ui->actionBuyHistory,&QAction::triggered,
            this,&MainWindowUser::onBuyHistory);
    initListWidget();
}

MainWindowUser::~MainWindowUser()
{
    delete ui;
    delete filmService;
    qDeleteAll(widgetRubbish);
}

void MainWindowUser::initListWidget()
{
    QVector<Film> allFilm=filmService->getALLfilm();
    for(auto it=allFilm.begin();it!=allFilm.end();it++)
    {
        QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
        FilmWidget* fw=new FilmWidget(*it);
        item->setSizeHint(QSize(0,750));
        widgetRubbish.push_back(fw);
        ui->listWidget->setItemWidget(item,fw);
    }
}

void MainWindowUser::sendReturnLogin()
{
    this->hide();
    emit signalReturnLogin();
}

void MainWindowUser::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if (item)
    {
        // 获取被双击的 QListWidgetItem
        QWidget *widget = ui->listWidget->itemWidget(item);
        if (widget)
        {
            //处理双击事件，widget 就是被双击项的 QWidget 对象
            FilmWidget *filmWidget = qobject_cast<FilmWidget*>(widget);
            formBuyTicket=new FormBuyTicket(user,filmWidget->getFilm());
            connect(formBuyTicket,&FormBuyTicket::signalReturnMainWindowUser,
                    this,&MainWindowUser::onReturnMainWindowUser);
            this->hide();
            formBuyTicket->show();
        }
    }
}

void MainWindowUser::onReturnMainWindowUser()
{
    if(formBuyTicket)
    {
        delete formBuyTicket;
        formBuyTicket=nullptr;
    }
    if(commentWidget)
    {
        delete commentWidget;
        commentWidget=nullptr;
    }
    this->show();
}

void MainWindowUser::onBuyHistory()
{
    commentWidget=new CommentWidget(user);
    connect(commentWidget,&CommentWidget::signalReturnMainWindowUser,
            this,&MainWindowUser::onReturnMainWindowUser);
    this->hide();
    commentWidget->show();
}
