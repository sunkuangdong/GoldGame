/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionend;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menustart;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName("MainScene");
        MainScene->resize(800, 600);
        actionend = new QAction(MainScene);
        actionend->setObjectName("actionend");
        centralwidget = new QWidget(MainScene);
        centralwidget->setObjectName("centralwidget");
        MainScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScene);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menustart = new QMenu(menubar);
        menustart->setObjectName("menustart");
        MainScene->setMenuBar(menubar);

        menubar->addAction(menustart->menuAction());
        menustart->addSeparator();
        menustart->addAction(actionend);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "MainScene", nullptr));
        actionend->setText(QCoreApplication::translate("MainScene", "end", nullptr));
        menustart->setTitle(QCoreApplication::translate("MainScene", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
