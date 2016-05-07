/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtproj1Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qtproj1Class)
    {
        if (Qtproj1Class->objectName().isEmpty())
            Qtproj1Class->setObjectName(QStringLiteral("Qtproj1Class"));
        Qtproj1Class->resize(627, 522);
        centralWidget = new QWidget(Qtproj1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 1, 1);

        Qtproj1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qtproj1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 21));
        Qtproj1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qtproj1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qtproj1Class->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qtproj1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qtproj1Class->setStatusBar(statusBar);

        retranslateUi(Qtproj1Class);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Qtproj1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qtproj1Class)
    {
        Qtproj1Class->setWindowTitle(QApplication::translate("Qtproj1Class", "Qtproj1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Qtproj1Class", "\320\241\320\266\320\260\321\202\320\270\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Qtproj1Class", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class Qtproj1Class: public Ui_Qtproj1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
