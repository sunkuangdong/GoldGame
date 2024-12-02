#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    QMenuBar * bar = menuBar();
    QMenu * startMenu = bar->addMenu("start");

    QAction * quitAction = startMenu->addAction("out");

    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    this->setWindowTitle("gold game");
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    // return butoon
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");

    backBtn->setParent(this);

    backBtn->move(this->width()-backBtn->width()-10, this->height()-backBtn->height()-10);

    connect(backBtn, &MyPushButton::clicked, [=](){
        this->hide();

        this->chooseSceneBack();
    });

    for (int i = 0; i < 20; ++i) {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+(i%4)*70, 140+(i/4)*70);

        connect(menuBtn, &MyPushButton::clicked, [=](){
            qDebug() << i+1;
        });
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+(i%4)*70, 140+(i/4)*70);

        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

 void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
