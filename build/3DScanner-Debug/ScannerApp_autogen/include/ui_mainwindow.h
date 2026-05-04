/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "visualizer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    Visualizer *visWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 533);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 281, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 26pt \"Franklin Gothic Book\";"));
        label->setAlignment(Qt::AlignCenter);
        visWidget = new Visualizer(centralwidget);
        visWidget->setObjectName("visWidget");
        visWidget->setGeometry(QRect(370, 20, 400, 400));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(80, 340, 195, 76));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(100, 160, 159, 69));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        comboBox = new QComboBox(horizontalLayoutWidget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(80, 240, 201, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSlider = new QSlider(horizontalLayoutWidget_3);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Scanner Test", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Shape:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Square", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Bunny", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Tilt: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
