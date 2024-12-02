#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"

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

    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);

    label->setGeometry(QRect(30, this->height()-50, 120, 50));

    dataConfig config;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel * lb = new QLabel;
            QPixmap pix;
            pix.load(":/res/BoardNode.png");
            lb->setGeometry(0,0,pix.width(),pix.height());
            lb->setPixmap(pix);
            lb->setParent(this);
            lb->move(57+i*pix.width(), 200+j*pix.height());

            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }

            // create gold icon
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*pix.width(), 204+j*pix.height());

            coin->posX = i;
            coin->posY = j;

            coin->flag = this->gameArray[i][j];

            coinBtn[i][j] = coin;


            connect(coin, &MyCoin::clicked, [=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 1 ? 0 : 1;
                QTimer::singleShot(100, this, [=](){
                    // right
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 1 ? 0 : 1;
                    }
                    // left
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 1 ? 0 : 1;
                    }
                    // top
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 1 ? 0 : 1;
                    }
                    // bottom
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 1 ? 0 : 1;
                    }

                    this->win = true;
                    for (int k = 0; k < 4; ++k) {
                        for (int l = 0; l < 4; ++l) {
                            if(!coinBtn[k][l]->flag)
                            {
                                this->win = false;
                                break;
                            }
                        }
                    }
                    if(this->win)
                    {
                        qDebug() << "You win!";
                        for (int k = 0; k < 4; ++k) {
                            for (int l = 0; l < 4; ++l) {
                                coinBtn[k][l]->isWin = true;
                            }
                        }
                    }
                });
            });
        }
    }
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
