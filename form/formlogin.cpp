#include "formlogin.h"
#include "ui_formlogin.h"

#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
FormLogin::FormLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLogin),currentRadioButton(NONE),
    userService(new UserServiceImpl),adminService(new AdminServiceImpl)
{
    ui->setupUi(this);
}

FormLogin::~FormLogin()
{
    delete ui;
    delete userService;
    delete adminService;
}

void FormLogin::hideEvent(QHideEvent *event)
{
    ui->accountEdit->clear();
    ui->passowordEdit->clear();
}

void FormLogin::on_adminRadioButton_toggled(bool checked)
{
    if(checked)
        currentRadioButton=adminRadioButton;
}

void FormLogin::on_userRadioButton_toggled(bool checked)
{
    if(checked)
        currentRadioButton=userRadioButton;
}

void FormLogin::on_registPushButton_clicked()
{
    QString account=ui->accountEdit->text();
    QString password=ui->passowordEdit->text();
    if(account.size()==0 || password.size()==0)
    {
        QMessageBox::information(this,"注册失败","账户或密码不能为空");
        return;
    }
    if(userService->Regist(account,password))
        QMessageBox::information(this,"注册成功","欢迎加入电影购票系统");
    else
        QMessageBox::information(this,"注册失败","账户已存在");
}

void FormLogin::on_loginPushButton_clicked()
{
    if(currentRadioButton==NONE)
    {
        QMessageBox::information(this,"登录失败","请选择登录类型");
        return;
    }

    QString account=ui->accountEdit->text();
    QString password=ui->passowordEdit->text();

    if(currentRadioButton==userRadioButton)//用户登录
    {
        if(userService->Login(account,password))
        {
            QMessageBox::information(this,"登录成功","欢迎进入电影购票系统");
            this->hide();
            mainWindowUser=new MainWindowUser(userService->getUserByAccount(account));
            connect(mainWindowUser,&MainWindowUser::signalReturnLogin,
                    this,&FormLogin::onUserReturnLogin);
            mainWindowUser->show();
            return;
        }
        else
            QMessageBox::information(this,"登录失败","账户或密码错误");
        return;
    }

    if(currentRadioButton==adminRadioButton)//管理员登录
    {
        if(adminService->Login(account,password))
        {
            QMessageBox::information(this,"登录成功","欢迎进入电影购票系统后台管理");
            this->hide();
            mainWindowAdmin=new MainWindowAdmin;
            connect(mainWindowAdmin,&MainWindowAdmin::signalReturnLogin,
                    this,&FormLogin::onAdminReturnLogin);
            mainWindowAdmin->show();
        }
        else
            QMessageBox::information(this,"登录失败","账户或密码错误");
    }
}

void FormLogin::onAdminReturnLogin()
{
    delete mainWindowAdmin;
    qDebug()<<"FormLogin show";
    this->show();
}

void FormLogin::onUserReturnLogin()
{
    delete mainWindowUser;
    qDebug()<<"FormLogin show";
    this->show();
}
