/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *sideBarWidget;
    QGridLayout *gridLayout_8;
    QVBoxLayout *sideBar;
    QPushButton *pushButton_16;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_10;
    QPushButton *pushButton_15;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *home;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QWidget *info;
    QGridLayout *gridLayout;
    QLineEdit *elementInput;
    QPushButton *pushButton_7;
    QLabel *elementInfo;
    QWidget *gazInerte;
    QGridLayout *gridLayout_5;
    QLineEdit *elementInput_2;
    QPushButton *pushButton_9;
    QLabel *elementInfo_2;
    QWidget *allElements;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContainer;
    QGridLayout *gridLayout_7;
    QLabel *elementList;
    QWidget *page_3;
    QWidget *page_4;
    QPushButton *pushButton_8;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 692);
        QFont font;
        font.setPointSize(25);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setFont(font);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        sideBarWidget = new QWidget(centralwidget);
        sideBarWidget->setObjectName(QString::fromUtf8("sideBarWidget"));
        gridLayout_8 = new QGridLayout(sideBarWidget);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        sideBar = new QVBoxLayout();
        sideBar->setSpacing(0);
        sideBar->setObjectName(QString::fromUtf8("sideBar"));
        pushButton_16 = new QPushButton(sideBarWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        QFont font1;
        font1.setPointSize(12);
        pushButton_16->setFont(font1);

        sideBar->addWidget(pushButton_16);

        pushButton_11 = new QPushButton(sideBarWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setFont(font1);

        sideBar->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(sideBarWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setFont(font1);

        sideBar->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(sideBarWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setFont(font1);

        sideBar->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(sideBarWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setFont(font1);

        sideBar->addWidget(pushButton_14);

        pushButton_10 = new QPushButton(sideBarWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setFont(font1);

        sideBar->addWidget(pushButton_10);

        pushButton_15 = new QPushButton(sideBarWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setFont(font1);

        sideBar->addWidget(pushButton_15);

        label_3 = new QLabel(sideBarWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        sideBar->addWidget(label_3);


        gridLayout_8->addLayout(sideBar, 0, 0, 1, 1);


        gridLayout_4->addWidget(sideBarWidget, 0, 0, 3, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QFont font2;
        font2.setPointSize(4);
        stackedWidget->setFont(font2);
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        gridLayout_3 = new QGridLayout(home);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, 1, -1);
        pushButton_4 = new QPushButton(home);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QFont font3;
        font3.setPointSize(15);
        pushButton_4->setFont(font3);

        gridLayout_2->addWidget(pushButton_4, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(home);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font3);

        gridLayout_2->addWidget(pushButton_2, 5, 0, 1, 1);

        pushButton_6 = new QPushButton(home);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font3);

        gridLayout_2->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButton = new QPushButton(home);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font3);

        gridLayout_2->addWidget(pushButton, 5, 1, 1, 1);

        pushButton_3 = new QPushButton(home);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font3);

        gridLayout_2->addWidget(pushButton_3, 4, 0, 1, 1);

        label_2 = new QLabel(home);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font4;
        font4.setPointSize(15);
        font4.setUnderline(true);
        label_2->setFont(font4);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 2);

        pushButton_5 = new QPushButton(home);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font3);

        gridLayout_2->addWidget(pushButton_5, 3, 1, 1, 1);

        label_5 = new QLabel(home);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sans Serif")});
        font5.setPointSize(25);
        label_5->setFont(font5);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(home);
        info = new QWidget();
        info->setObjectName(QString::fromUtf8("info"));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font6.setPointSize(4);
        info->setFont(font6);
        gridLayout = new QGridLayout(info);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        elementInput = new QLineEdit(info);
        elementInput->setObjectName(QString::fromUtf8("elementInput"));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Ubuntu")});
        font7.setPointSize(10);
        elementInput->setFont(font7);

        gridLayout->addWidget(elementInput, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(info);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font7);

        gridLayout->addWidget(pushButton_7, 0, 2, 1, 1);

        elementInfo = new QLabel(info);
        elementInfo->setObjectName(QString::fromUtf8("elementInfo"));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font8.setPointSize(20);
        elementInfo->setFont(font8);
        elementInfo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(elementInfo, 1, 1, 1, 2);

        stackedWidget->addWidget(info);
        gazInerte = new QWidget();
        gazInerte->setObjectName(QString::fromUtf8("gazInerte"));
        QFont font9;
        font9.setPointSize(10);
        gazInerte->setFont(font9);
        gridLayout_5 = new QGridLayout(gazInerte);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        elementInput_2 = new QLineEdit(gazInerte);
        elementInput_2->setObjectName(QString::fromUtf8("elementInput_2"));

        gridLayout_5->addWidget(elementInput_2, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(gazInerte);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_5->addWidget(pushButton_9, 0, 1, 1, 1);

        elementInfo_2 = new QLabel(gazInerte);
        elementInfo_2->setObjectName(QString::fromUtf8("elementInfo_2"));
        QFont font10;
        font10.setPointSize(20);
        elementInfo_2->setFont(font10);
        elementInfo_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(elementInfo_2, 1, 0, 1, 2);

        stackedWidget->addWidget(gazInerte);
        allElements = new QWidget();
        allElements->setObjectName(QString::fromUtf8("allElements"));
        gridLayout_6 = new QGridLayout(allElements);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(allElements);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaContainer = new QWidget();
        scrollAreaContainer->setObjectName(QString::fromUtf8("scrollAreaContainer"));
        scrollAreaContainer->setGeometry(QRect(0, 0, 693, 658));
        gridLayout_7 = new QGridLayout(scrollAreaContainer);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        elementList = new QLabel(scrollAreaContainer);
        elementList->setObjectName(QString::fromUtf8("elementList"));
        elementList->setFont(font10);
        elementList->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(elementList, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaContainer);

        gridLayout_6->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(allElements);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);

        gridLayout_4->addWidget(stackedWidget, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font3);

        gridLayout_4->addWidget(pushButton_8, 2, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font10);

        gridLayout_4->addWidget(label_4, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Gaz Inerte", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Compos\303\251", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Tout les\n"
"\303\251l\303\251ments", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\303\200 propos de\n"
"Chimie++", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Sortir de\n"
"l'application", nullptr));
        label_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Obtenir une liste des\n"
"propri\303\251t\303\251es de tout les\n"
" \303\251l\303\251ments", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\303\200 Propos de Chimie++", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Obtenir n'importe quel\n"
"\303\251l\303\251ment", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Sortir de l'application", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "G\303\251nerer un compos\303\251 \303\240 partir\n"
"de deux \303\251l\303\251ments\n"
"", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"Liste d'actions:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Trouver le Gaz Inerte le plus\n"
"proche d'un \303\251l\303\251ment", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><pre style=\"font-family: sans-serif\">Chimie++ </pre><img src=\":/chimieLogo.ico\" width=40/></p></body></html>", nullptr));
        elementInput->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        elementInfo->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        elementInfo_2->setText(QString());
        elementList->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\342\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
