#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:

    MyPushButton(QString normarlImg, QString pressImg = "");
    void zoom1();
    void zoom2();

    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);

    QString normarlImgPath;
    QString pressImgPath;
signals:
};

#endif // MYPUSHBUTTON_H
