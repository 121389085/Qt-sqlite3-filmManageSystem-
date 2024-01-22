#include "commentwidget.h"
#include "ui_commentwidget.h"

#include <QDebug>
#include <QMessageBox>
CommentWidget::CommentWidget(const User &user ,QWidget *parent):
    QWidget(parent),
    ui(new Ui::CommentWidget),commentService(new CommentServiceImpl),
    ticketService(new TicketServiceImpl),sessionService(new SessionServiceImpl),
    filmServie(new FilmServiceImpl),screenService(new ScreenServiceImpl),
    cinemaService(new CinemaServiceImpl),
    user(user)
{
    ui->setupUi(this);
    currentTid=0;
    initComment();
}
CommentWidget::~CommentWidget()
{
    delete ui;
    delete commentService;
    delete ticketService;
    delete sessionService;
    delete filmServie;
    delete screenService;
    delete cinemaService;
}

void CommentWidget::initComment()
{
        QVector<Ticket> ticketByUser=ticketService->getTicketByUid(user.getUid());
        qDebug()<<"test";
        QString temp;
        for(auto it=ticketByUser.begin();it!=ticketByUser.end();it++)
        {
            temp.clear();
            Session session=sessionService->getSessionBySeid(it->getSeid());
            Film film=filmServie->getFilmByFid(session.getFid());
            Screen screen=screenService->getScreenByScid(session.getScid());
            Cinema cinema=cinemaService->getCinemaByCid(screen.getCid());
            temp=QString::number(it->getTid())+" "+film.getFname()+" "+screen.getScname()+" "+cinema.getCname();
            ui->listWidget->addItem(temp);
        }
}

void CommentWidget::closeEvent(QCloseEvent *event)
{
    emit signalReturnMainWindowUser();
}

void CommentWidget::on_pushButton_clicked()
{
    if(currentTid==0)
    {
        QMessageBox::information(this,"评论失败","请先选择需要评论的票");
        return;
    }
    QString text=ui->textEdit->toPlainText();
    if(text.size()==0)
    {
        QMessageBox::information(this,"评论失败","评论不能为空");
        return;
    }
    bool result=commentService->viewByTid(currentTid,text);
    if(result)
        QMessageBox::information(this,"评论成功","评论成功");
    else
        QMessageBox::information(this,"评论失败","评论失败");
}

void CommentWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
     ui->textEdit->clear();
    int index=item->text().indexOf(" ");
    currentTid=item->text().left(index).toInt();
    Comment comment=commentService->getCommentByTid(currentTid);
    if(comment.getCoid()!=0)
    {
        ui->textEdit->setText(comment.getContent());
        ui->textEdit->setReadOnly(true);
    }
    else
        ui->textEdit->setReadOnly(false);
}
