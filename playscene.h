#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
 #include <QPaintEvent>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNumber);

    void paintEvent(QPaintEvent *);


    int levelIndex;
signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
