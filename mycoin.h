#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString imgPath);

    int posX;
    int posY;

    bool flag;

    void changeFlag();
    void mousePressEvent(QMouseEvent * e);

    QTimer * timer1;
    QTimer * timer2;
    int min = 1;
    int max = 8;

    bool isAnimation = false;
signals:
};

#endif // MYCOIN_H
