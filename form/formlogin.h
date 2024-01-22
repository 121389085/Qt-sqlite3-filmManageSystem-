#ifndef FORMLOGIN_H
#define FORMLOGIN_H

#include <QWidget>
#include "service/userserviceimpl.h"
#include "service/adminserviceimpl.h"
#include "form/mainwindowadmin.h"
#include "form/mainwindowuser.h"
namespace Ui {
class FormLogin;
}

enum RadioButton
{
    NONE,
    adminRadioButton,
    userRadioButton
};


class FormLogin : public QWidget
{
    Q_OBJECT

public:
    explicit FormLogin(QWidget *parent = nullptr);
    ~FormLogin();
    void hideEvent(QHideEvent *event) override;
private slots:
    void on_adminRadioButton_toggled(bool checked);

    void on_userRadioButton_toggled(bool checked);

    void on_registPushButton_clicked();

    void on_loginPushButton_clicked();

    void onAdminReturnLogin();

    void onUserReturnLogin();
private:
    Ui::FormLogin *ui;
    RadioButton currentRadioButton;
    UserService* userService;
    AdminService* adminService;
    MainWindowAdmin* mainWindowAdmin;
    MainWindowUser* mainWindowUser;
};

#endif // FORMLOGIN_H
