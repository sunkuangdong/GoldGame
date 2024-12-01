#include "mainscene.h"
#include "./ui_mainscene.h"
#include <QPainter>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setWindowTitle("gold game");
    this->setFixedSize(320, 588);

    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    connect(ui->actionend, &QAction::triggered, [=](){
        this->close();
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
