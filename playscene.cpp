#include "playscene.h"
#include "mypushbutton.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QFont>

PlayScene::PlayScene(int levelNumber)
{
    this->levelIndex = levelNumber;

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("reverse gold");

    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("start");
    QAction * quitAction = startMenu->addAction("end");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);

    backBtn->move(this->width()-backBtn->width()-10, this->height()-backBtn->height()-10);

    connect(backBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(200, this, [=](){
            this->hide();
            emit this->chooseSceneBack();
        });
    });

    // from level to show games
    QLabel * label = new QLabel;
    label->setParent(this);
    label->setText("Level : " + QString::number(this->levelIndex));
    label->setGeometry(QRect(30, this->height()-50, 120, 50));

    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");

    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
