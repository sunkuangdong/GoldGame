#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNumber);

    void paintEvent(QPaintEvent *);

    int levelIndex;
    int gameArray[4][4];

    MyCoin * coinBtn[4][4];

    bool win = false;
signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
