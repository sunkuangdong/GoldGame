#include "mypushbutton.h"
#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normarlImg, QString pressImg)
{
    this->normarlImgPath = normarlImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normarlImgPath);

    if(!ret){
        QString str = QString("We can not load image!").arg(normarlImg);
        qDebug() << "";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());

    this->setStyleSheet("QPushButton{border: 0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
