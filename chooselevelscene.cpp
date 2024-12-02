#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>

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
