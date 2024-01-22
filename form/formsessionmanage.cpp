#include "formsessionmanage.h"
#include "ui_formsessionmanage.h"

#include <QMessageBox>
#include <QDebug>
FormSessionManage::FormSessionManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSessionManage),filmService(new FilmServiceImpl),
    cinemaService(new CinemaServiceImpl),screenService(new ScreenServiceImpl),
    sessionService(new SessionServiceImpl)
{
    ui->setupUi(this);
    ui->PriceSpinBox->setButtonSymbols( QAbstractSpinBox::NoButtons );
    ui->timeEdit->setButtonSymbols( QAbstractSpinBox::NoButtons );
    openMode=ADDMODE;
    currentFid=0;
    currentCid=0;
    currentScid=0;
    updateFilmList();
    upadteCinemaList();
    upadteScreenList();
}

FormSessionManage::FormSessionManage(const int seid, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormSessionManage),filmService(new FilmServiceImpl),
    cinemaService(new CinemaServiceImpl),screenService(new ScreenServiceImpl),
    sessionService(new SessionServiceImpl)
{
    ui->setupUi(this);
    ui->PriceSpinBox->setButtonSymbols( QAbstractSpinBox::NoButtons );
    ui->timeEdit->setButtonSymbols( QAbstractSpinBox::NoButtons );
    openMode=UPDATEMODE;
    currentFid=0;
    currentCid=0;
    currentScid=0;
    this->seid=seid;
    updateFilmList();
    upadteCinemaList();
    upadteScreenList();
    showByUpdateMode();
}

FormSessionManage::~FormSessionManage()
{
    delete ui;
    delete filmService;
    delete cinemaService;
    delete sessionService;
}

void FormSessionManage::updateFilmList()
{
    QVector<Film> allFilm=filmService->getALLfilm();
    ui->filmComboBox->addItem("");
    for(auto it=allFilm.begin();it!=allFilm.end();++it)
    {
        ui->filmComboBox->addItem(QString::number(it->getFid())
                                  +" "+it->getFname());
    }
}

void FormSessionManage::upadteCinemaList()
{
    QVector<Cinema> allCinema=cinemaService->getAllCinema();
    ui->cinemaComboBox->addItem("");
    for(auto it=allCinema.begin();it!=allCinema.end();++it)
    {
        ui->cinemaComboBox->addItem(QString::number(it->getCid())
                                  +" "+it->getCname());
    }
}

void FormSessionManage::upadteScreenList()
{
    if(currentCid==0)
    {
        ui->screenComboBox->addItem("请先选择影院");
        return;
    }
    ui->screenComboBox->hide();
    ui->screenComboBox->clear();
    ui->screenComboBox->show();
    QVector<Screen> screen=screenService->getScreenByCid(currentCid);
    for(auto it=screen.begin();it!=screen.end();++it)
    {
        ui->screenComboBox->addItem(QString::number(it->getScid())
                                  +" "+it->getScname());
    }
}

void FormSessionManage::showByUpdateMode()
{
    Session session=sessionService->getSessionBySeid(seid);
    QVector<Film> allFilm=filmService->getALLfilm();
    int fid=session.getFid();
    for(int i=0;i<allFilm.count();i++)
    {
        ui->filmComboBox->setCurrentIndex(i);
        int index=ui->filmComboBox->currentText().indexOf(" ");
        QString curFid=ui->filmComboBox->currentText().left(index);
        if(QString::number(fid)==curFid)
            break;
    }


    QVector<Cinema> allCinema=cinemaService->getAllCinema();
    int scid=session.getScid();
    int cid=screenService->getCidByScid(scid);
    for(int i=0;i<allCinema.count();i++)
    {
        ui->cinemaComboBox->setCurrentIndex(i);
        int index=ui->cinemaComboBox->currentText().indexOf(" ");
        QString curCid=ui->cinemaComboBox->currentText().left(index);
        if(QString::number(cid)==curCid)
            break;
    }


    QVector<Screen> allScreenByCinema=screenService->getScreenByCid(cid);
    for(int i=0;i<allScreenByCinema.count();i++)
    {
        ui->screenComboBox->setCurrentIndex(i);
        int index=ui->screenComboBox->currentText().indexOf(" ");
        QString curScid=ui->screenComboBox->currentText().left(index);
        if(QString::number(scid)==curScid)
            break;
    }
}

void FormSessionManage::closeEvent(QCloseEvent*)
{
    emit signalClose();
}

void FormSessionManage::on_saveButton_clicked()
{
    if(currentFid==0)//comboBox没内容，indexof会返回-1
    {
        QMessageBox::information(this,"保存失败","请选择电影");
        return;
    }

    if(currentScid==0)
    {
        QMessageBox::information(this,"保存失败","请选择放映厅");
        return;
    }

    //获取放映时间
    currentShowtime=currentDate+" "+currentTime;
    if(currentDate<=0 || currentTime<=0)
    {
        QMessageBox::information(this,"保存失败","请设置放映日期与时间");
        return;
    }

    //获取价格
    currentPrice=ui->PriceSpinBox->value();
    if(currentPrice<=0)
    {
        QMessageBox::information(this,"保存失败","价格必须大于等于0");
        return;
    }

    if(openMode==ADDMODE)
    {
        bool result=sessionService->addSession(Session(currentScid,currentShowtime,currentPrice,currentFid));
        if(result)
        {
            QMessageBox::information(this,"保存成功","保存成功");
            this->hide();
            emit signalClose();
        }
        else
            QMessageBox::information(this,"保存失败","场次与已有场次冲突");
        return;
    }

    if(openMode==UPDATEMODE)
    {
        bool result=sessionService->upadteSession(Session(seid,currentScid,currentShowtime,currentPrice,currentFid));
        if(result)
        {
            QMessageBox::information(this,"修改成功","修改成功");
            this->hide();
            emit signalClose();
        }
        else
            QMessageBox::information(this,"修改失败","修改失败");
    }

}

void FormSessionManage::on_calendarWidget_clicked(const QDate &date)
{
    currentDate=date.toString();
}

void FormSessionManage::on_timeEdit_userTimeChanged(const QTime &time)
{
    currentTime=time.toString();
}

void FormSessionManage::on_filmComboBox_currentTextChanged(const QString &arg1)
{
    int index;
    //获取电影id
    index=ui->filmComboBox->currentText().indexOf(" ");
    if(index<=0)
    {
        currentFid=0;
        return;
    }
    currentFid=ui->filmComboBox->currentText().left(index).toInt();//获取空格左侧所有字符
}



void FormSessionManage::on_screenComboBox_currentTextChanged(const QString &arg1)
{
    int index;
    //获取放映厅id
    index=ui->screenComboBox->currentText().indexOf(" ");
    if(index<0)
    {
        currentScid=0;
        return;
    }
    currentScid=ui->screenComboBox->currentText().left(index).toInt();
}

void FormSessionManage::on_cinemaComboBox_currentTextChanged(const QString &arg1)
{
    int index;
    //获取影院id
    index=ui->cinemaComboBox->currentText().indexOf(" ");
    if(index<0)
    {
        currentScid=0;
        return;
    }
    currentCid=ui->cinemaComboBox->currentText().left(index).toInt();
    upadteScreenList();
}

void FormSessionManage::on_cancelButton_clicked()
{
    this->hide();
    emit signalClose();
}
