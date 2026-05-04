/********************************************************************************
** Form generated from reading UI file 'propdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPDIALOG_H
#define UI_PROPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *xSpinBox;
    QDoubleSpinBox *ySpinBox;
    QDoubleSpinBox *zSpinBox;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *pitchSpinBox;
    QDoubleSpinBox *yawSpinBox;
    QDoubleSpinBox *rollSpinBox;
    QLabel *label_8;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *applyButton;
    QPushButton *revertButton;
    QPushButton *closeButton;

    void setupUi(QDialog *PropDialog)
    {
        if (PropDialog->objectName().isEmpty())
            PropDialog->setObjectName("PropDialog");
        PropDialog->resize(400, 300);
        PropDialog->setMinimumSize(QSize(400, 300));
        PropDialog->setMaximumSize(QSize(400, 300));
        verticalLayoutWidget = new QWidget(PropDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 30, 303, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setHorizontalSpacing(20);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(20, -1, -1, -1);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        xSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        xSpinBox->setObjectName("xSpinBox");
        xSpinBox->setDecimals(2);
        xSpinBox->setMinimum(-100.000000000000000);
        xSpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, xSpinBox);

        ySpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        ySpinBox->setObjectName("ySpinBox");
        ySpinBox->setDecimals(2);
        ySpinBox->setMinimum(-100.000000000000000);
        ySpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, ySpinBox);

        zSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        zSpinBox->setObjectName("zSpinBox");
        zSpinBox->setDecimals(2);
        zSpinBox->setMinimum(-100.000000000000000);
        zSpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, zSpinBox);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(20);
        formLayout_2->setVerticalSpacing(20);
        formLayout_2->setContentsMargins(20, -1, -1, -1);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        pitchSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        pitchSpinBox->setObjectName("pitchSpinBox");
        pitchSpinBox->setDecimals(2);
        pitchSpinBox->setMinimum(-180.000000000000000);
        pitchSpinBox->setMaximum(180.000000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pitchSpinBox);

        yawSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        yawSpinBox->setObjectName("yawSpinBox");
        yawSpinBox->setDecimals(2);
        yawSpinBox->setMinimum(-180.000000000000000);
        yawSpinBox->setMaximum(360.000000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, yawSpinBox);

        rollSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        rollSpinBox->setObjectName("rollSpinBox");
        rollSpinBox->setDecimals(2);
        rollSpinBox->setMinimum(-180.000000000000000);
        rollSpinBox->setMaximum(180.000000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, rollSpinBox);


        gridLayout->addLayout(formLayout_2, 1, 1, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 40));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 40));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        applyButton = new QPushButton(verticalLayoutWidget);
        applyButton->setObjectName("applyButton");
        applyButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(applyButton);

        revertButton = new QPushButton(verticalLayoutWidget);
        revertButton->setObjectName("revertButton");
        revertButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(revertButton);

        closeButton = new QPushButton(verticalLayoutWidget);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PropDialog);

        QMetaObject::connectSlotsByName(PropDialog);
    } // setupUi

    void retranslateUi(QDialog *PropDialog)
    {
        PropDialog->setWindowTitle(QCoreApplication::translate("PropDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PropDialog", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("PropDialog", "Y:", nullptr));
        label_3->setText(QCoreApplication::translate("PropDialog", "Z:", nullptr));
        label_5->setText(QCoreApplication::translate("PropDialog", "Pitch:", nullptr));
        label_6->setText(QCoreApplication::translate("PropDialog", "Yaw:", nullptr));
        label_7->setText(QCoreApplication::translate("PropDialog", "Roll:", nullptr));
        label_8->setText(QCoreApplication::translate("PropDialog", "Rotation", nullptr));
        label_4->setText(QCoreApplication::translate("PropDialog", "Translation", nullptr));
        applyButton->setText(QCoreApplication::translate("PropDialog", "Apply", nullptr));
        revertButton->setText(QCoreApplication::translate("PropDialog", "Revert", nullptr));
        closeButton->setText(QCoreApplication::translate("PropDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PropDialog: public Ui_PropDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPDIALOG_H
