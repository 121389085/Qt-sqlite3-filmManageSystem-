#include "mybutton.h"
#include <QDebug>
MyButton::MyButton()
    :status(UNSELECTED)
{
    this->setFixedSize(50,50);
    this->setIcon(QPixmap(unSelectedImag));
    this->setIconSize(this->size());
    connect(this,&MyButton::clicked,this,&MyButton::changeIcon);
}

void MyButton::changeIcon()
{
    if(status==UNSELECTED)
    {
        this->setIcon(QPixmap(selectedImag));
        this->setIconSize(this->size());
        status=SELECTED;
        emit signalPos(this);
        return;
    }

    if(status==SELECTED)
    {
        this->setIcon(QPixmap(unSelectedImag));
        this->setIconSize(this->size());
        status=UNSELECTED;
        emit signalPos(this);
    }

}

STATUS MyButton::getStatus() const
{
    return status;
}

void MyButton::setStatus(const STATUS &value)
{
    status = value;
}

QString MyButton::getPos() const
{
    return pos;
}

void MyButton::setPos(const QString &value)
{
    pos = value;
}
