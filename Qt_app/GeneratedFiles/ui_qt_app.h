/********************************************************************************
** Form generated from reading UI file 'qt_app.ui'
**
** Created: Sat Feb 15 21:21:15 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_APP_H
#define UI_QT_APP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "testgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_Qt_appClass
{
public:
    QWidget *centralWidget;
    TestGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_appClass)
    {
        if (Qt_appClass->objectName().isEmpty())
            Qt_appClass->setObjectName(QString::fromUtf8("Qt_appClass"));
        Qt_appClass->resize(656, 473);
        centralWidget = new QWidget(Qt_appClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new TestGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 641, 411));
        Qt_appClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt_appClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 22));
        Qt_appClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_appClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_appClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt_appClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_appClass->setStatusBar(statusBar);

        retranslateUi(Qt_appClass);

        QMetaObject::connectSlotsByName(Qt_appClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_appClass)
    {
        Qt_appClass->setWindowTitle(QApplication::translate("Qt_appClass", "Qt_app", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qt_appClass: public Ui_Qt_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_APP_H
