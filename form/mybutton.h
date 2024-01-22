#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

enum STATUS
{
    UNSELECTED,
    SELECTED
};

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton();
    QString getPos() const;
    void setPos(const QString &value);
    STATUS getStatus() const;
    void setStatus(const STATUS &value);
signals:
    void signalPos(const MyButton*);
private slots:
    void changeIcon();
private:
    QString unSelectedImag="C:/Users/12138/Desktop/project/code/filmManageSystem/recourese/unselected.png";
    QString selectedImag="C:/Users/12138/Desktop/project/code/filmManageSystem/recourese/selected.png";
    STATUS status;
    QString pos;
};

#endif // MYBUTTON_H
