#include "mainscene.h"
#include "./ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setWindowTitle("gold game");
    this->setFixedSize(320, 588);

    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
}

MainScene::~MainScene()
{
    delete ui;
}
