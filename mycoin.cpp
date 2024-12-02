#include "mycoin.h"

#include <QDebug>
#include <QTimer>

MyCoin::MyCoin(QString imgPath)
{
    QPixmap pix;
    bool ret = pix.load(imgPath);

    if(!ret)
    {
        qDebug()<< "To load image is fial!";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "To load image is fail :" << str;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->min > this->max)
        {
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "To load image is fail :" << str;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        if(this->max < this->min)
        {
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });
}

void MyCoin::changeFlag()
{
    if(this->flag) {
        timer1->start(30);
    };
    if(!this->flag) {
        timer2->start(30);
    };
    this->flag = !this->flag;
    this->isAnimation = true;
}

void MyCoin::mousePressEvent(QMouseEvent * e)
{
    if(this->isAnimation)
    {
        return;
    }
    QPushButton::mousePressEvent(e);
}
