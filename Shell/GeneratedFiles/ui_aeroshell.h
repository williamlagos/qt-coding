/********************************************************************************
** Form generated from reading UI file 'aeroshell.ui'
**
** Created: Tue 13. Sep 17:14:55 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AEROSHELL_H
#define UI_AEROSHELL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AERoshellClass
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionOccurrences;
    QAction *actionPerformance;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *consoleOutLayout;
    QVBoxLayout *consoleInLayout;
    QHBoxLayout *buttonsLayout;
    QPushButton *sendButton;
    QPushButton *deleteButton;
    QMenuBar *menuBar;
    QMenu *menuProgram;
    QMenu *menuHelp;
    QMenu *menuFind;
    QMenu *menuGraphics;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AERoshellClass)
    {
        if (AERoshellClass->objectName().isEmpty())
            AERoshellClass->setObjectName(QString::fromUtf8("AERoshellClass"));
        AERoshellClass->setWindowModality(Qt::NonModal);
        AERoshellClass->resize(800, 600);
        AERoshellClass->setUnifiedTitleAndToolBarOnMac(false);
        actionQuit = new QAction(AERoshellClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(AERoshellClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOccurrences = new QAction(AERoshellClass);
        actionOccurrences->setObjectName(QString::fromUtf8("actionOccurrences"));
        actionPerformance = new QAction(AERoshellClass);
        actionPerformance->setObjectName(QString::fromUtf8("actionPerformance"));
        centralWidget = new QWidget(AERoshellClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        consoleOutLayout = new QVBoxLayout();
        consoleOutLayout->setSpacing(5);
        consoleOutLayout->setObjectName(QString::fromUtf8("consoleOutLayout"));
        consoleOutLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_2->addLayout(consoleOutLayout);

        consoleInLayout = new QVBoxLayout();
        consoleInLayout->setSpacing(5);
        consoleInLayout->setObjectName(QString::fromUtf8("consoleInLayout"));
        consoleInLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        consoleInLayout->setContentsMargins(-1, 0, 0, 0);

        verticalLayout_2->addLayout(consoleInLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(5);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        buttonsLayout->addWidget(sendButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        buttonsLayout->addWidget(deleteButton);


        verticalLayout_2->addLayout(buttonsLayout);

        AERoshellClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AERoshellClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuProgram = new QMenu(menuBar);
        menuProgram->setObjectName(QString::fromUtf8("menuProgram"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QString::fromUtf8("menuFind"));
        menuGraphics = new QMenu(menuBar);
        menuGraphics->setObjectName(QString::fromUtf8("menuGraphics"));
        AERoshellClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AERoshellClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AERoshellClass->setStatusBar(statusBar);

        menuBar->addAction(menuProgram->menuAction());
        menuBar->addAction(menuGraphics->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuProgram->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuFind->addAction(actionOccurrences);
        menuGraphics->addAction(actionPerformance);

        retranslateUi(AERoshellClass);

        QMetaObject::connectSlotsByName(AERoshellClass);
    } // setupUi

    void retranslateUi(QMainWindow *AERoshellClass)
    {
        AERoshellClass->setWindowTitle(QApplication::translate("AERoshellClass", "AERoshell", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("AERoshellClass", "Quit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("AERoshellClass", "About", 0, QApplication::UnicodeUTF8));
        actionOccurrences->setText(QApplication::translate("AERoshellClass", "Occurrences", 0, QApplication::UnicodeUTF8));
        actionPerformance->setText(QApplication::translate("AERoshellClass", "Plot", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("AERoshellClass", "Send", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("AERoshellClass", "Clear", 0, QApplication::UnicodeUTF8));
        menuProgram->setTitle(QApplication::translate("AERoshellClass", "Program", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("AERoshellClass", "Help", 0, QApplication::UnicodeUTF8));
        menuFind->setTitle(QApplication::translate("AERoshellClass", "Search", 0, QApplication::UnicodeUTF8));
        menuGraphics->setTitle(QApplication::translate("AERoshellClass", "Profile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AERoshellClass: public Ui_AERoshellClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AEROSHELL_H
