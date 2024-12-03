#include "mainscene.h"
#include "mypushbutton.h"

#include "./ui_mainscene.h"

#include <QPainter>
#include <QDebug>
#include <QTimer>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setWindowTitle("gold game");
    this->setFixedSize(320, 588);

    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    connect(ui->actionend, &QAction::triggered, [=](){
        this->close();
    });

    // sound

    // choose level
    chooseScene = new ChooseLevelScene;

    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);
    startBtn->setParent(this);

    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        QTimer::singleShot(200, this, [=](){
            chooseScene->hide();
            this->setGeometry(chooseScene->geometry());
            this->show();
        });
    });

    connect(startBtn, &MyPushButton::clicked, [=](){
        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(500, this, [=](){
            this->hide();
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
        });
    });
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // title
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 10, pix.width(), pix.height(), pix);
}

MainScene::~MainScene()
{
    delete ui;
}
