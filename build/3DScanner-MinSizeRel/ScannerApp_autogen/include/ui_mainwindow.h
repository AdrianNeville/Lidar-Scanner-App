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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "visualizer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExpCurKeyframe;
    QAction *actionExpAll;
    QAction *actionImportK;
    QAction *actionExpAllAsOne;
    QAction *actionSave_Session;
    QAction *actionLoad_Session;
    QWidget *centralwidget;
    Visualizer *visWidget;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *scanButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *scanOneButton;
    QSpinBox *frameIndex;
    QGroupBox *groupBox_17;
    QWidget *horizontalLayoutWidget_18;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_37;
    QLineEdit *lowAnglePan;
    QSpacerItem *horizontalSpacer_41;
    QLineEdit *highAnglePan;
    QWidget *horizontalLayoutWidget_19;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_38;
    QLineEdit *lowAnglePitch;
    QSpacerItem *horizontalSpacer_42;
    QLineEdit *highAnglePitch;
    QWidget *horizontalLayoutWidget_20;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_39;
    QSpacerItem *horizontalSpacer_44;
    QLineEdit *panRes;
    QWidget *horizontalLayoutWidget_21;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer_45;
    QLineEdit *pitchRes;
    QWidget *tab_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QDoubleSpinBox *mirrorMaxY;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *horizontalLayout_61;
    QPushButton *mirrorCorrectButton;
    QPushButton *mirrorCorrectButton_2;
    QGroupBox *passThroughSettings;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_52;
    QLabel *label_46;
    QComboBox *passCombo;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QSpinBox *passMin;
    QLabel *label_2;
    QSpinBox *passMax;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_54;
    QPushButton *passButton;
    QPushButton *passButton_2;
    QGroupBox *passThroughSettings_3;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QDoubleSpinBox *voxLeafSize;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_56;
    QPushButton *voxButton;
    QPushButton *voxButton_2;
    QGroupBox *passThroughSettings_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QSpinBox *sorMean;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_55;
    QPushButton *sorButton;
    QPushButton *sorButton_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *applyAlltoCurButton;
    QPushButton *applyAlltoAllButton;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *revertCleanButton;
    QPushButton *undoCleanButton;
    QPushButton *redoCleanButton;
    QWidget *tab_7;
    QGroupBox *passThroughSettings_4;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_53;
    QLabel *label_12;
    QSpinBox *regisMaxDist;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QSpinBox *regisMaxIter;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QDoubleSpinBox *registFitThresh;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QComboBox *targetIndC;
    QLabel *label_11;
    QComboBox *sourceIndC;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_57;
    QPushButton *pairRegisButton;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pairRegisButton_2;
    QWidget *tab_6;
    QGroupBox *filterSettings;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QLineEdit *searchRadiusEdit;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QLineEdit *upsampleRadiusEdit;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_24;
    QLineEdit *upsampleStepEdit;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_25;
    QLineEdit *orderEdit;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *revertButton;
    QPushButton *filterButton;
    QGroupBox *passThroughSettings_5;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_15;
    QDoubleSpinBox *voxLeafSize_2;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_58;
    QPushButton *voxButton_3;
    QWidget *tab_3;
    QPushButton *constructMeshButton;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QCheckBox *rotCheck;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *leftRot;
    QPushButton *rightRot;
    QWidget *tab;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *panEdit;
    QSpacerItem *horizontalSpacer_5;
    QLabel *tiltAngle_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *tiltEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *tiltAngle;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *elevEdit;
    QSpacerItem *horizontalSpacer_8;
    QLabel *tiltAngle_3;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *getDistanceButton;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *distLabel;
    QLabel *label_18;
    QLineEdit *sqLabel;
    QLabel *label_5;
    QGroupBox *groupBox_9;
    QPushButton *lineScanButton;
    QPushButton *panScanButton;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *rotAzimButton;
    QSpacerItem *horizontalSpacer_21;
    QLineEdit *distLabel_2;
    QLabel *label_19;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *lowerButton;
    QPushButton *higherButton;
    QTableWidget *keyframeTable;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menu_Open;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1481, 768);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionExpCurKeyframe = new QAction(MainWindow);
        actionExpCurKeyframe->setObjectName("actionExpCurKeyframe");
        actionExpAll = new QAction(MainWindow);
        actionExpAll->setObjectName("actionExpAll");
        actionImportK = new QAction(MainWindow);
        actionImportK->setObjectName("actionImportK");
        actionExpAllAsOne = new QAction(MainWindow);
        actionExpAllAsOne->setObjectName("actionExpAllAsOne");
        actionSave_Session = new QAction(MainWindow);
        actionSave_Session->setObjectName("actionSave_Session");
        actionLoad_Session = new QAction(MainWindow);
        actionLoad_Session->setObjectName("actionLoad_Session");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        visWidget = new Visualizer(centralwidget);
        visWidget->setObjectName("visWidget");
        visWidget->setGeometry(QRect(410, 20, 751, 651));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(visWidget->sizePolicy().hasHeightForWidth());
        visWidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 40, 341, 631));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 30, 291, 131));
        groupBox_3->setFlat(false);
        horizontalLayoutWidget = new QWidget(groupBox_3);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 295, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scanButton = new QPushButton(horizontalLayoutWidget);
        scanButton->setObjectName("scanButton");

        horizontalLayout->addWidget(scanButton);

        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName("pauseButton");

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName("stopButton");

        horizontalLayout->addWidget(stopButton);

        horizontalLayoutWidget_9 = new QWidget(groupBox_3);
        horizontalLayoutWidget_9->setObjectName("horizontalLayoutWidget_9");
        horizontalLayoutWidget_9->setGeometry(QRect(40, 80, 211, 41));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        scanOneButton = new QPushButton(horizontalLayoutWidget_9);
        scanOneButton->setObjectName("scanOneButton");

        horizontalLayout_14->addWidget(scanOneButton);

        frameIndex = new QSpinBox(horizontalLayoutWidget_9);
        frameIndex->setObjectName("frameIndex");

        horizontalLayout_14->addWidget(frameIndex);

        groupBox_17 = new QGroupBox(tab_4);
        groupBox_17->setObjectName("groupBox_17");
        groupBox_17->setGeometry(QRect(10, 200, 311, 211));
        groupBox_17->setFlat(false);
        horizontalLayoutWidget_18 = new QWidget(groupBox_17);
        horizontalLayoutWidget_18->setObjectName("horizontalLayoutWidget_18");
        horizontalLayoutWidget_18->setGeometry(QRect(20, 40, 277, 31));
        horizontalLayout_44 = new QHBoxLayout(horizontalLayoutWidget_18);
        horizontalLayout_44->setObjectName("horizontalLayout_44");
        horizontalLayout_44->setContentsMargins(0, 0, 0, 0);
        label_37 = new QLabel(horizontalLayoutWidget_18);
        label_37->setObjectName("label_37");

        horizontalLayout_44->addWidget(label_37);

        lowAnglePan = new QLineEdit(horizontalLayoutWidget_18);
        lowAnglePan->setObjectName("lowAnglePan");
        lowAnglePan->setAlignment(Qt::AlignCenter);

        horizontalLayout_44->addWidget(lowAnglePan);

        horizontalSpacer_41 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_41);

        highAnglePan = new QLineEdit(horizontalLayoutWidget_18);
        highAnglePan->setObjectName("highAnglePan");
        highAnglePan->setAlignment(Qt::AlignCenter);

        horizontalLayout_44->addWidget(highAnglePan);

        horizontalLayoutWidget_19 = new QWidget(groupBox_17);
        horizontalLayoutWidget_19->setObjectName("horizontalLayoutWidget_19");
        horizontalLayoutWidget_19->setGeometry(QRect(10, 80, 286, 31));
        horizontalLayout_45 = new QHBoxLayout(horizontalLayoutWidget_19);
        horizontalLayout_45->setObjectName("horizontalLayout_45");
        horizontalLayout_45->setContentsMargins(0, 0, 0, 0);
        label_38 = new QLabel(horizontalLayoutWidget_19);
        label_38->setObjectName("label_38");

        horizontalLayout_45->addWidget(label_38);

        lowAnglePitch = new QLineEdit(horizontalLayoutWidget_19);
        lowAnglePitch->setObjectName("lowAnglePitch");
        lowAnglePitch->setAlignment(Qt::AlignCenter);

        horizontalLayout_45->addWidget(lowAnglePitch);

        horizontalSpacer_42 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_42);

        highAnglePitch = new QLineEdit(horizontalLayoutWidget_19);
        highAnglePitch->setObjectName("highAnglePitch");
        highAnglePitch->setAlignment(Qt::AlignCenter);

        horizontalLayout_45->addWidget(highAnglePitch);

        horizontalLayoutWidget_20 = new QWidget(groupBox_17);
        horizontalLayoutWidget_20->setObjectName("horizontalLayoutWidget_20");
        horizontalLayoutWidget_20->setGeometry(QRect(10, 120, 286, 31));
        horizontalLayout_46 = new QHBoxLayout(horizontalLayoutWidget_20);
        horizontalLayout_46->setObjectName("horizontalLayout_46");
        horizontalLayout_46->setContentsMargins(0, 0, 0, 0);
        label_39 = new QLabel(horizontalLayoutWidget_20);
        label_39->setObjectName("label_39");

        horizontalLayout_46->addWidget(label_39);

        horizontalSpacer_44 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_44);

        panRes = new QLineEdit(horizontalLayoutWidget_20);
        panRes->setObjectName("panRes");
        panRes->setAlignment(Qt::AlignCenter);

        horizontalLayout_46->addWidget(panRes);

        horizontalLayoutWidget_21 = new QWidget(groupBox_17);
        horizontalLayoutWidget_21->setObjectName("horizontalLayoutWidget_21");
        horizontalLayoutWidget_21->setGeometry(QRect(10, 160, 286, 31));
        horizontalLayout_47 = new QHBoxLayout(horizontalLayoutWidget_21);
        horizontalLayout_47->setObjectName("horizontalLayout_47");
        horizontalLayout_47->setContentsMargins(0, 0, 0, 0);
        label_40 = new QLabel(horizontalLayoutWidget_21);
        label_40->setObjectName("label_40");

        horizontalLayout_47->addWidget(label_40);

        horizontalSpacer_45 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_45);

        pitchRes = new QLineEdit(horizontalLayoutWidget_21);
        pitchRes->setObjectName("pitchRes");
        pitchRes->setAlignment(Qt::AlignCenter);

        horizontalLayout_47->addWidget(pitchRes);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        scrollArea = new QScrollArea(tab_5);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 321, 441));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 300, 600));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 600));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setMaximumSize(QSize(16777215, 120));
        verticalLayoutWidget_10 = new QWidget(groupBox_4);
        verticalLayoutWidget_10->setObjectName("verticalLayoutWidget_10");
        verticalLayoutWidget_10->setGeometry(QRect(10, 20, 261, 91));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_18->setContentsMargins(50, -1, 50, -1);
        label_16 = new QLabel(verticalLayoutWidget_10);
        label_16->setObjectName("label_16");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy3);
        label_16->setMaximumSize(QSize(80, 16777215));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(label_16);

        mirrorMaxY = new QDoubleSpinBox(verticalLayoutWidget_10);
        mirrorMaxY->setObjectName("mirrorMaxY");
        mirrorMaxY->setMaximumSize(QSize(90, 16777215));
        mirrorMaxY->setDecimals(4);
        mirrorMaxY->setMinimum(0.000000000000000);
        mirrorMaxY->setMaximum(500.000000000000000);
        mirrorMaxY->setSingleStep(0.010000000000000);
        mirrorMaxY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        mirrorMaxY->setValue(300.556199999999990);

        horizontalLayout_18->addWidget(mirrorMaxY);


        verticalLayout_12->addLayout(horizontalLayout_18);

        verticalSpacer_14 = new QSpacerItem(10, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_12->addItem(verticalSpacer_14);

        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setObjectName("horizontalLayout_61");
        mirrorCorrectButton = new QPushButton(verticalLayoutWidget_10);
        mirrorCorrectButton->setObjectName("mirrorCorrectButton");
        mirrorCorrectButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_61->addWidget(mirrorCorrectButton);

        mirrorCorrectButton_2 = new QPushButton(verticalLayoutWidget_10);
        mirrorCorrectButton_2->setObjectName("mirrorCorrectButton_2");
        mirrorCorrectButton_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_61->addWidget(mirrorCorrectButton_2);


        verticalLayout_12->addLayout(horizontalLayout_61);


        verticalLayout_2->addWidget(groupBox_4);

        passThroughSettings = new QGroupBox(scrollAreaWidgetContents);
        passThroughSettings->setObjectName("passThroughSettings");
        passThroughSettings->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(passThroughSettings->sizePolicy().hasHeightForWidth());
        passThroughSettings->setSizePolicy(sizePolicy4);
        passThroughSettings->setMaximumSize(QSize(16777215, 160));
        passThroughSettings->setFlat(false);
        verticalLayoutWidget_6 = new QWidget(passThroughSettings);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(10, 30, 261, 120));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(0);
        horizontalLayout_52->setObjectName("horizontalLayout_52");
        horizontalLayout_52->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_52->setContentsMargins(80, -1, 80, -1);
        label_46 = new QLabel(verticalLayoutWidget_6);
        label_46->setObjectName("label_46");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy5);
        label_46->setMinimumSize(QSize(0, 0));
        label_46->setMaximumSize(QSize(30, 16777215));
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_52->addWidget(label_46);

        passCombo = new QComboBox(verticalLayoutWidget_6);
        passCombo->addItem(QString());
        passCombo->addItem(QString());
        passCombo->addItem(QString());
        passCombo->setObjectName("passCombo");
        passCombo->setMinimumSize(QSize(10, 0));
        passCombo->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_52->addWidget(passCombo);


        verticalLayout_7->addLayout(horizontalLayout_52);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_8->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(verticalLayoutWidget_6);
        label->setObjectName("label");
        label->setMaximumSize(QSize(40, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label);

        passMin = new QSpinBox(verticalLayoutWidget_6);
        passMin->setObjectName("passMin");
        passMin->setMaximumSize(QSize(70, 16777215));
        passMin->setMinimum(-100000);
        passMin->setMaximum(100000);
        passMin->setSingleStep(1);
        passMin->setStepType(QAbstractSpinBox::DefaultStepType);
        passMin->setValue(-2);

        horizontalLayout_8->addWidget(passMin);

        label_2 = new QLabel(verticalLayoutWidget_6);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_2);

        passMax = new QSpinBox(verticalLayoutWidget_6);
        passMax->setObjectName("passMax");
        passMax->setMaximumSize(QSize(70, 16777215));
        passMax->setMinimum(-100000);
        passMax->setMaximum(100000);
        passMax->setValue(10000);

        horizontalLayout_8->addWidget(passMax);


        verticalLayout_7->addLayout(horizontalLayout_8);

        verticalSpacer_9 = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_9);

        horizontalLayout_54 = new QHBoxLayout();
        horizontalLayout_54->setObjectName("horizontalLayout_54");
        passButton = new QPushButton(verticalLayoutWidget_6);
        passButton->setObjectName("passButton");
        passButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_54->addWidget(passButton);

        passButton_2 = new QPushButton(verticalLayoutWidget_6);
        passButton_2->setObjectName("passButton_2");
        passButton_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_54->addWidget(passButton_2);


        verticalLayout_7->addLayout(horizontalLayout_54);


        verticalLayout_2->addWidget(passThroughSettings);

        passThroughSettings_3 = new QGroupBox(scrollAreaWidgetContents);
        passThroughSettings_3->setObjectName("passThroughSettings_3");
        passThroughSettings_3->setEnabled(true);
        sizePolicy4.setHeightForWidth(passThroughSettings_3->sizePolicy().hasHeightForWidth());
        passThroughSettings_3->setSizePolicy(sizePolicy4);
        passThroughSettings_3->setMaximumSize(QSize(16777215, 130));
        passThroughSettings_3->setFlat(false);
        verticalLayoutWidget_8 = new QWidget(passThroughSettings_3);
        verticalLayoutWidget_8->setObjectName("verticalLayoutWidget_8");
        verticalLayoutWidget_8->setGeometry(QRect(10, 30, 261, 85));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_10->setContentsMargins(50, -1, 60, 0);
        label_8 = new QLabel(verticalLayoutWidget_8);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(80, 16777215));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_8);

        voxLeafSize = new QDoubleSpinBox(verticalLayoutWidget_8);
        voxLeafSize->setObjectName("voxLeafSize");
        voxLeafSize->setMaximumSize(QSize(60, 16777215));
        voxLeafSize->setDecimals(3);
        voxLeafSize->setMinimum(0.010000000000000);
        voxLeafSize->setMaximum(10.000000000000000);
        voxLeafSize->setSingleStep(0.010000000000000);
        voxLeafSize->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_10->addWidget(voxLeafSize);


        verticalLayout_9->addLayout(horizontalLayout_10);

        verticalSpacer_11 = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_11);

        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setObjectName("horizontalLayout_56");
        voxButton = new QPushButton(verticalLayoutWidget_8);
        voxButton->setObjectName("voxButton");
        voxButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_56->addWidget(voxButton);

        voxButton_2 = new QPushButton(verticalLayoutWidget_8);
        voxButton_2->setObjectName("voxButton_2");
        voxButton_2->setMinimumSize(QSize(100, 0));
        voxButton_2->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_56->addWidget(voxButton_2);


        verticalLayout_9->addLayout(horizontalLayout_56);


        verticalLayout_2->addWidget(passThroughSettings_3);

        passThroughSettings_2 = new QGroupBox(scrollAreaWidgetContents);
        passThroughSettings_2->setObjectName("passThroughSettings_2");
        passThroughSettings_2->setEnabled(true);
        sizePolicy4.setHeightForWidth(passThroughSettings_2->sizePolicy().hasHeightForWidth());
        passThroughSettings_2->setSizePolicy(sizePolicy4);
        passThroughSettings_2->setMaximumSize(QSize(16777215, 150));
        passThroughSettings_2->setFlat(false);
        verticalLayoutWidget_7 = new QWidget(passThroughSettings_2);
        verticalLayoutWidget_7->setObjectName("verticalLayoutWidget_7");
        verticalLayoutWidget_7->setGeometry(QRect(10, 30, 261, 120));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_9->setContentsMargins(50, -1, 60, 0);
        label_7 = new QLabel(verticalLayoutWidget_7);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(80, 16777215));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_7);

        sorMean = new QSpinBox(verticalLayoutWidget_7);
        sorMean->setObjectName("sorMean");
        sorMean->setMinimum(1);
        sorMean->setMaximum(999);
        sorMean->setValue(50);

        horizontalLayout_9->addWidget(sorMean);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_11->setContentsMargins(50, -1, 60, 0);
        label_9 = new QLabel(verticalLayoutWidget_7);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(80, 16777215));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_9);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_7);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximum(5.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        horizontalLayout_11->addWidget(doubleSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_11);

        verticalSpacer_10 = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_8->addItem(verticalSpacer_10);

        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setSpacing(0);
        horizontalLayout_55->setObjectName("horizontalLayout_55");
        sorButton = new QPushButton(verticalLayoutWidget_7);
        sorButton->setObjectName("sorButton");
        sorButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_55->addWidget(sorButton);

        sorButton_2 = new QPushButton(verticalLayoutWidget_7);
        sorButton_2->setObjectName("sorButton_2");
        sorButton_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_55->addWidget(sorButton_2);


        verticalLayout_8->addLayout(horizontalLayout_55);


        verticalLayout_2->addWidget(passThroughSettings_2);


        verticalLayout->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget_2 = new QWidget(tab_5);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 470, 301, 111));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        applyAlltoCurButton = new QPushButton(verticalLayoutWidget_2);
        applyAlltoCurButton->setObjectName("applyAlltoCurButton");
        sizePolicy5.setHeightForWidth(applyAlltoCurButton->sizePolicy().hasHeightForWidth());
        applyAlltoCurButton->setSizePolicy(sizePolicy5);

        verticalLayout_4->addWidget(applyAlltoCurButton);

        applyAlltoAllButton = new QPushButton(verticalLayoutWidget_2);
        applyAlltoAllButton->setObjectName("applyAlltoAllButton");

        verticalLayout_4->addWidget(applyAlltoAllButton);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        revertCleanButton = new QPushButton(verticalLayoutWidget_2);
        revertCleanButton->setObjectName("revertCleanButton");

        horizontalLayout_13->addWidget(revertCleanButton);

        undoCleanButton = new QPushButton(verticalLayoutWidget_2);
        undoCleanButton->setObjectName("undoCleanButton");
        undoCleanButton->setMinimumSize(QSize(20, 0));

        horizontalLayout_13->addWidget(undoCleanButton);

        redoCleanButton = new QPushButton(verticalLayoutWidget_2);
        redoCleanButton->setObjectName("redoCleanButton");
        redoCleanButton->setMinimumSize(QSize(20, 0));

        horizontalLayout_13->addWidget(redoCleanButton);


        verticalLayout_4->addLayout(horizontalLayout_13);

        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        passThroughSettings_4 = new QGroupBox(tab_7);
        passThroughSettings_4->setObjectName("passThroughSettings_4");
        passThroughSettings_4->setEnabled(true);
        passThroughSettings_4->setGeometry(QRect(20, 20, 276, 271));
        sizePolicy4.setHeightForWidth(passThroughSettings_4->sizePolicy().hasHeightForWidth());
        passThroughSettings_4->setSizePolicy(sizePolicy4);
        passThroughSettings_4->setMinimumSize(QSize(0, 240));
        passThroughSettings_4->setMaximumSize(QSize(16777215, 16777215));
        passThroughSettings_4->setFlat(false);
        verticalLayoutWidget_9 = new QWidget(passThroughSettings_4);
        verticalLayoutWidget_9->setObjectName("verticalLayoutWidget_9");
        verticalLayoutWidget_9->setGeometry(QRect(10, 30, 261, 228));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(0);
        horizontalLayout_53->setObjectName("horizontalLayout_53");
        horizontalLayout_53->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_53->setContentsMargins(0, -1, 0, -1);
        label_12 = new QLabel(verticalLayoutWidget_9);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_53->addWidget(label_12);

        regisMaxDist = new QSpinBox(verticalLayoutWidget_9);
        regisMaxDist->setObjectName("regisMaxDist");
        regisMaxDist->setMaximumSize(QSize(60, 16777215));
        regisMaxDist->setMinimum(1);
        regisMaxDist->setMaximum(2000);
        regisMaxDist->setValue(50);

        horizontalLayout_53->addWidget(regisMaxDist);


        verticalLayout_10->addLayout(horizontalLayout_53);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(30, -1, 30, -1);
        label_13 = new QLabel(verticalLayoutWidget_9);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(label_13);

        regisMaxIter = new QSpinBox(verticalLayoutWidget_9);
        regisMaxIter->setObjectName("regisMaxIter");
        regisMaxIter->setMaximumSize(QSize(50, 16777215));
        regisMaxIter->setMinimum(1);
        regisMaxIter->setMaximum(9999);
        regisMaxIter->setValue(50);

        horizontalLayout_15->addWidget(regisMaxIter);


        verticalLayout_10->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(20, -1, 20, -1);
        label_14 = new QLabel(verticalLayoutWidget_9);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_16->addWidget(label_14);

        registFitThresh = new QDoubleSpinBox(verticalLayoutWidget_9);
        registFitThresh->setObjectName("registFitThresh");
        registFitThresh->setMaximumSize(QSize(80, 16777215));
        registFitThresh->setDecimals(4);
        registFitThresh->setMinimum(0.000100000000000);
        registFitThresh->setMaximum(1.000000000000000);
        registFitThresh->setSingleStep(0.000100000000000);
        registFitThresh->setValue(0.100000000000000);

        horizontalLayout_16->addWidget(registFitThresh);


        verticalLayout_10->addLayout(horizontalLayout_16);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_12->setContentsMargins(-1, -1, -1, 0);
        label_10 = new QLabel(verticalLayoutWidget_9);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(50, 16777215));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_10);

        targetIndC = new QComboBox(verticalLayoutWidget_9);
        targetIndC->setObjectName("targetIndC");
        targetIndC->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_12->addWidget(targetIndC);

        label_11 = new QLabel(verticalLayoutWidget_9);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(50, 16777215));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_11);

        sourceIndC = new QComboBox(verticalLayoutWidget_9);
        sourceIndC->setObjectName("sourceIndC");
        sourceIndC->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_12->addWidget(sourceIndC);


        verticalLayout_10->addLayout(horizontalLayout_12);

        verticalSpacer_12 = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_10->addItem(verticalSpacer_12);

        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setObjectName("horizontalLayout_57");
        pairRegisButton = new QPushButton(verticalLayoutWidget_9);
        pairRegisButton->setObjectName("pairRegisButton");
        pairRegisButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_57->addWidget(pairRegisButton);


        verticalLayout_10->addLayout(horizontalLayout_57);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        pairRegisButton_2 = new QPushButton(verticalLayoutWidget_9);
        pairRegisButton_2->setObjectName("pairRegisButton_2");
        pairRegisButton_2->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_17->addWidget(pairRegisButton_2);


        verticalLayout_10->addLayout(horizontalLayout_17);

        tabWidget->addTab(tab_7, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        filterSettings = new QGroupBox(tab_6);
        filterSettings->setObjectName("filterSettings");
        filterSettings->setEnabled(true);
        filterSettings->setGeometry(QRect(20, 160, 291, 251));
        filterSettings->setFlat(true);
        verticalLayoutWidget = new QWidget(filterSettings);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 30, 279, 201));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(5);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        horizontalLayout_24->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_24->setContentsMargins(50, -1, 60, -1);
        label_22 = new QLabel(verticalLayoutWidget);
        label_22->setObjectName("label_22");
        sizePolicy5.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy5);
        label_22->setMinimumSize(QSize(0, 0));
        label_22->setMaximumSize(QSize(150, 16777215));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_24->addWidget(label_22);

        searchRadiusEdit = new QLineEdit(verticalLayoutWidget);
        searchRadiusEdit->setObjectName("searchRadiusEdit");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(5);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(searchRadiusEdit->sizePolicy().hasHeightForWidth());
        searchRadiusEdit->setSizePolicy(sizePolicy6);
        searchRadiusEdit->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_24->addWidget(searchRadiusEdit);


        verticalLayout_3->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(0);
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        horizontalLayout_25->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_25->setContentsMargins(-1, -1, 50, -1);
        label_23 = new QLabel(verticalLayoutWidget);
        label_23->setObjectName("label_23");
        sizePolicy5.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy5);
        label_23->setMinimumSize(QSize(0, 0));
        label_23->setMaximumSize(QSize(120, 16777215));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_25->addWidget(label_23);

        upsampleRadiusEdit = new QLineEdit(verticalLayoutWidget);
        upsampleRadiusEdit->setObjectName("upsampleRadiusEdit");
        sizePolicy6.setHeightForWidth(upsampleRadiusEdit->sizePolicy().hasHeightForWidth());
        upsampleRadiusEdit->setSizePolicy(sizePolicy6);
        upsampleRadiusEdit->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_25->addWidget(upsampleRadiusEdit);


        verticalLayout_3->addLayout(horizontalLayout_25);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(0);
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        horizontalLayout_27->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_27->setContentsMargins(-1, -1, 50, -1);
        label_24 = new QLabel(verticalLayoutWidget);
        label_24->setObjectName("label_24");
        sizePolicy5.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy5);
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setMaximumSize(QSize(120, 16777215));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_27->addWidget(label_24);

        upsampleStepEdit = new QLineEdit(verticalLayoutWidget);
        upsampleStepEdit->setObjectName("upsampleStepEdit");
        sizePolicy6.setHeightForWidth(upsampleStepEdit->sizePolicy().hasHeightForWidth());
        upsampleStepEdit->setSizePolicy(sizePolicy6);
        upsampleStepEdit->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_27->addWidget(upsampleStepEdit);


        verticalLayout_3->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(0);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        horizontalLayout_28->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_28->setContentsMargins(-1, -1, 50, -1);
        label_25 = new QLabel(verticalLayoutWidget);
        label_25->setObjectName("label_25");
        sizePolicy5.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy5);
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setMaximumSize(QSize(120, 16777215));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_28->addWidget(label_25);

        orderEdit = new QLineEdit(verticalLayoutWidget);
        orderEdit->setObjectName("orderEdit");
        sizePolicy6.setHeightForWidth(orderEdit->sizePolicy().hasHeightForWidth());
        orderEdit->setSizePolicy(sizePolicy6);
        orderEdit->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_28->addWidget(orderEdit);


        verticalLayout_3->addLayout(horizontalLayout_28);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        revertButton = new QPushButton(verticalLayoutWidget);
        revertButton->setObjectName("revertButton");
        revertButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_26->addWidget(revertButton);

        filterButton = new QPushButton(verticalLayoutWidget);
        filterButton->setObjectName("filterButton");
        filterButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_26->addWidget(filterButton);


        verticalLayout_3->addLayout(horizontalLayout_26);

        passThroughSettings_5 = new QGroupBox(tab_6);
        passThroughSettings_5->setObjectName("passThroughSettings_5");
        passThroughSettings_5->setEnabled(true);
        passThroughSettings_5->setGeometry(QRect(30, 20, 276, 130));
        sizePolicy4.setHeightForWidth(passThroughSettings_5->sizePolicy().hasHeightForWidth());
        passThroughSettings_5->setSizePolicy(sizePolicy4);
        passThroughSettings_5->setMaximumSize(QSize(16777215, 130));
        passThroughSettings_5->setFlat(false);
        verticalLayoutWidget_11 = new QWidget(passThroughSettings_5);
        verticalLayoutWidget_11->setObjectName("verticalLayoutWidget_11");
        verticalLayoutWidget_11->setGeometry(QRect(10, 30, 261, 85));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        horizontalLayout_19->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_19->setContentsMargins(50, -1, 60, 0);
        label_15 = new QLabel(verticalLayoutWidget_11);
        label_15->setObjectName("label_15");
        label_15->setMaximumSize(QSize(80, 16777215));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_15);

        voxLeafSize_2 = new QDoubleSpinBox(verticalLayoutWidget_11);
        voxLeafSize_2->setObjectName("voxLeafSize_2");
        voxLeafSize_2->setMaximumSize(QSize(60, 16777215));
        voxLeafSize_2->setDecimals(3);
        voxLeafSize_2->setMinimum(0.010000000000000);
        voxLeafSize_2->setMaximum(10.000000000000000);
        voxLeafSize_2->setSingleStep(0.010000000000000);
        voxLeafSize_2->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_19->addWidget(voxLeafSize_2);


        verticalLayout_11->addLayout(horizontalLayout_19);

        verticalSpacer_13 = new QSpacerItem(10, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_11->addItem(verticalSpacer_13);

        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setObjectName("horizontalLayout_58");
        voxButton_3 = new QPushButton(verticalLayoutWidget_11);
        voxButton_3->setObjectName("voxButton_3");
        voxButton_3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_58->addWidget(voxButton_3);


        verticalLayout_11->addLayout(horizontalLayout_58);

        tabWidget->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        constructMeshButton = new QPushButton(tab_3);
        constructMeshButton->setObjectName("constructMeshButton");
        constructMeshButton->setGeometry(QRect(100, 170, 141, 29));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 20, 291, 101));
        groupBox_2->setFlat(true);
        rotCheck = new QCheckBox(groupBox_2);
        rotCheck->setObjectName("rotCheck");
        rotCheck->setGeometry(QRect(20, 30, 91, 24));
        rotCheck->setChecked(false);
        horizontalLayoutWidget_6 = new QWidget(groupBox_2);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(10, 60, 241, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        leftRot = new QPushButton(horizontalLayoutWidget_6);
        leftRot->setObjectName("leftRot");
        leftRot->setEnabled(false);

        horizontalLayout_6->addWidget(leftRot);

        rightRot = new QPushButton(horizontalLayoutWidget_6);
        rightRot->setObjectName("rightRot");
        rightRot->setEnabled(false);

        horizontalLayout_6->addWidget(rightRot);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 301, 181));
        groupBox->setFlat(true);
        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 230, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        panEdit = new QLineEdit(horizontalLayoutWidget_4);
        panEdit->setObjectName("panEdit");

        horizontalLayout_4->addWidget(panEdit);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        tiltAngle_2 = new QLabel(horizontalLayoutWidget_4);
        tiltAngle_2->setObjectName("tiltAngle_2");

        horizontalLayout_4->addWidget(tiltAngle_2);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 50, 228, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        tiltEdit = new QLineEdit(horizontalLayoutWidget_3);
        tiltEdit->setObjectName("tiltEdit");

        horizontalLayout_3->addWidget(tiltEdit);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        tiltAngle = new QLabel(horizontalLayoutWidget_3);
        tiltAngle->setObjectName("tiltAngle");

        horizontalLayout_3->addWidget(tiltAngle);

        horizontalLayoutWidget_7 = new QWidget(groupBox);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(10, 90, 222, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_7);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_7 = new QSpacerItem(14, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        elevEdit = new QLineEdit(horizontalLayoutWidget_7);
        elevEdit->setObjectName("elevEdit");

        horizontalLayout_7->addWidget(elevEdit);

        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        tiltAngle_3 = new QLabel(horizontalLayoutWidget_7);
        tiltAngle_3->setObjectName("tiltAngle_3");

        horizontalLayout_7->addWidget(tiltAngle_3);

        horizontalLayoutWidget_5 = new QWidget(tab);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(20, 200, 301, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        getDistanceButton = new QPushButton(horizontalLayoutWidget_5);
        getDistanceButton->setObjectName("getDistanceButton");
        getDistanceButton->setMinimumSize(QSize(110, 0));
        QFont font;
        font.setPointSize(9);
        getDistanceButton->setFont(font);

        horizontalLayout_5->addWidget(getDistanceButton);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        distLabel = new QLineEdit(horizontalLayoutWidget_5);
        distLabel->setObjectName("distLabel");
        distLabel->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy7.setHorizontalStretch(10);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(distLabel->sizePolicy().hasHeightForWidth());
        distLabel->setSizePolicy(sizePolicy7);
        distLabel->setMinimumSize(QSize(5, 0));
        distLabel->setAlignment(Qt::AlignCenter);
        distLabel->setReadOnly(true);

        horizontalLayout_5->addWidget(distLabel);

        label_18 = new QLabel(horizontalLayoutWidget_5);
        label_18->setObjectName("label_18");

        horizontalLayout_5->addWidget(label_18);

        sqLabel = new QLineEdit(horizontalLayoutWidget_5);
        sqLabel->setObjectName("sqLabel");
        sqLabel->setEnabled(true);
        sizePolicy7.setHeightForWidth(sqLabel->sizePolicy().hasHeightForWidth());
        sqLabel->setSizePolicy(sizePolicy7);
        sqLabel->setMinimumSize(QSize(5, 0));
        sqLabel->setAlignment(Qt::AlignCenter);
        sqLabel->setReadOnly(true);

        horizontalLayout_5->addWidget(sqLabel);

        label_5 = new QLabel(horizontalLayoutWidget_5);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(19, 269, 301, 201));
        lineScanButton = new QPushButton(groupBox_9);
        lineScanButton->setObjectName("lineScanButton");
        lineScanButton->setGeometry(QRect(20, 30, 93, 29));
        panScanButton = new QPushButton(groupBox_9);
        panScanButton->setObjectName("panScanButton");
        panScanButton->setGeometry(QRect(180, 30, 93, 29));
        horizontalLayoutWidget_8 = new QWidget(groupBox_9);
        horizontalLayoutWidget_8->setObjectName("horizontalLayoutWidget_8");
        horizontalLayoutWidget_8->setGeometry(QRect(20, 70, 251, 31));
        horizontalLayout_21 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        rotAzimButton = new QPushButton(horizontalLayoutWidget_8);
        rotAzimButton->setObjectName("rotAzimButton");

        horizontalLayout_21->addWidget(rotAzimButton);

        horizontalSpacer_21 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_21);

        distLabel_2 = new QLineEdit(horizontalLayoutWidget_8);
        distLabel_2->setObjectName("distLabel_2");
        distLabel_2->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy8.setHorizontalStretch(10);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(distLabel_2->sizePolicy().hasHeightForWidth());
        distLabel_2->setSizePolicy(sizePolicy8);
        distLabel_2->setMinimumSize(QSize(5, 0));
        distLabel_2->setAlignment(Qt::AlignCenter);
        distLabel_2->setReadOnly(true);

        horizontalLayout_21->addWidget(distLabel_2);

        label_19 = new QLabel(horizontalLayoutWidget_8);
        label_19->setObjectName("label_19");

        horizontalLayout_21->addWidget(label_19);

        horizontalLayoutWidget_2 = new QWidget(groupBox_9);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 110, 251, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lowerButton = new QPushButton(horizontalLayoutWidget_2);
        lowerButton->setObjectName("lowerButton");

        horizontalLayout_2->addWidget(lowerButton);

        higherButton = new QPushButton(horizontalLayoutWidget_2);
        higherButton->setObjectName("higherButton");

        horizontalLayout_2->addWidget(higherButton);

        tabWidget->addTab(tab, QString());
        keyframeTable = new QTableWidget(centralwidget);
        if (keyframeTable->columnCount() < 4)
            keyframeTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        keyframeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        keyframeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        keyframeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        keyframeTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        keyframeTable->setObjectName("keyframeTable");
        keyframeTable->setGeometry(QRect(1180, 20, 291, 651));
        keyframeTable->setAutoFillBackground(false);
        keyframeTable->setFrameShape(QFrame::Box);
        keyframeTable->setFrameShadow(QFrame::Sunken);
        keyframeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        keyframeTable->setWordWrap(true);
        keyframeTable->setColumnCount(4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1481, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName("menuSave");
        menu_Open = new QMenu(menuFile);
        menu_Open->setObjectName("menu_Open");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(menu_Open->menuAction());
        menuFile->addAction(menuSave->menuAction());
        menuFile->addAction(actionSave_Session);
        menuFile->addAction(actionLoad_Session);
        menuSave->addAction(actionExpCurKeyframe);
        menuSave->addAction(actionExpAll);
        menuSave->addAction(actionExpAllAsOne);
        menu_Open->addAction(actionImportK);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        passCombo->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExpCurKeyframe->setText(QCoreApplication::translate("MainWindow", "Current Keyframe", nullptr));
        actionExpAll->setText(QCoreApplication::translate("MainWindow", "All Keyframes", nullptr));
        actionImportK->setText(QCoreApplication::translate("MainWindow", "to Current Keyframe", nullptr));
        actionExpAllAsOne->setText(QCoreApplication::translate("MainWindow", "All Keyframes as One", nullptr));
        actionSave_Session->setText(QCoreApplication::translate("MainWindow", "Save Session...", nullptr));
        actionLoad_Session->setText(QCoreApplication::translate("MainWindow", "Load Session...", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Data", nullptr));
        scanButton->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        scanOneButton->setText(QCoreApplication::translate("MainWindow", "Scan One Keyframe", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Pan Angle Limit:", nullptr));
        lowAnglePan->setText(QCoreApplication::translate("MainWindow", "-18", nullptr));
        highAnglePan->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Pitch Angle Limit:", nullptr));
        lowAnglePitch->setText(QCoreApplication::translate("MainWindow", "-18", nullptr));
        highAnglePitch->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Pan Resolution (deg)", nullptr));
        panRes->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Tilt Resolution (deg)", nullptr));
        pitchRes->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Scan", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Mirror Correction", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Max Y:", nullptr));
        mirrorCorrectButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        mirrorCorrectButton_2->setText(QCoreApplication::translate("MainWindow", "Apply to All", nullptr));
        passThroughSettings->setTitle(QCoreApplication::translate("MainWindow", "Passthrough Filter", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Axis:", nullptr));
        passCombo->setItemText(0, QCoreApplication::translate("MainWindow", "x", nullptr));
        passCombo->setItemText(1, QCoreApplication::translate("MainWindow", "y", nullptr));
        passCombo->setItemText(2, QCoreApplication::translate("MainWindow", "z", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Min: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Max: ", nullptr));
        passButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        passButton_2->setText(QCoreApplication::translate("MainWindow", "Apply to All", nullptr));
        passThroughSettings_3->setTitle(QCoreApplication::translate("MainWindow", "Voxel Grid Downsampling", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Leaf Size: ", nullptr));
        voxButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        voxButton_2->setText(QCoreApplication::translate("MainWindow", "Apply to All", nullptr));
        passThroughSettings_2->setTitle(QCoreApplication::translate("MainWindow", "Statistical Outlier Removal", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "MeanK: ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "StdDev: ", nullptr));
        sorButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        sorButton_2->setText(QCoreApplication::translate("MainWindow", "Apply to All", nullptr));
        applyAlltoCurButton->setText(QCoreApplication::translate("MainWindow", "Apply All to Current Keyframe", nullptr));
        applyAlltoAllButton->setText(QCoreApplication::translate("MainWindow", "Apply All to All Keyframes", nullptr));
        revertCleanButton->setText(QCoreApplication::translate("MainWindow", "Revert to Original", nullptr));
        undoCleanButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        redoCleanButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Cleaning", nullptr));
        passThroughSettings_4->setTitle(QCoreApplication::translate("MainWindow", "Pair-wise registration", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Max Corr. Distance: ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Max Iterations: ", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Fitness Threshold: ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Target:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        pairRegisButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pairRegisButton_2->setText(QCoreApplication::translate("MainWindow", "Apply Pairwise Registration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Registration", nullptr));
        filterSettings->setTitle(QCoreApplication::translate("MainWindow", "Moving Least Squares", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Search Radius", nullptr));
        searchRadiusEdit->setText(QCoreApplication::translate("MainWindow", "0.05", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Upsample Radius", nullptr));
        upsampleRadiusEdit->setText(QCoreApplication::translate("MainWindow", "0.025", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Upsample Step", nullptr));
        upsampleStepEdit->setText(QCoreApplication::translate("MainWindow", "0.01", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Polynomial Order", nullptr));
        orderEdit->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        revertButton->setText(QCoreApplication::translate("MainWindow", "Revert", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        passThroughSettings_5->setTitle(QCoreApplication::translate("MainWindow", "Voxel Grid Downsampling", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Leaf Size: ", nullptr));
        voxButton_3->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Filter", nullptr));
        constructMeshButton->setText(QCoreApplication::translate("MainWindow", "Construct Mesh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "3D Reconstruction", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        rotCheck->setText(QCoreApplication::translate("MainWindow", "Automatic", nullptr));
        leftRot->setText(QCoreApplication::translate("MainWindow", "Rotate Left", nullptr));
        rightRot->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Display", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Pan: ", nullptr));
        panEdit->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        tiltAngle_2->setText(QCoreApplication::translate("MainWindow", "(45-135)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tilt: ", nullptr));
        tiltEdit->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        tiltAngle->setText(QCoreApplication::translate("MainWindow", "(45-135)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Elev: ", nullptr));
        elevEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tiltAngle_3->setText(QCoreApplication::translate("MainWindow", "(0-90)", nullptr));
        getDistanceButton->setText(QCoreApplication::translate("MainWindow", "Get Distance", nullptr));
        distLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        sqLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "sq", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        lineScanButton->setText(QCoreApplication::translate("MainWindow", "X Line Scan", nullptr));
        panScanButton->setText(QCoreApplication::translate("MainWindow", "Z Line Scan", nullptr));
        rotAzimButton->setText(QCoreApplication::translate("MainWindow", "Rotate Azimuth", nullptr));
        distLabel_2->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        lowerButton->setText(QCoreApplication::translate("MainWindow", "Lower", nullptr));
        higherButton->setText(QCoreApplication::translate("MainWindow", "Higher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem = keyframeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Keyframe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = keyframeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = keyframeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = keyframeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menu_Open->setTitle(QCoreApplication::translate("MainWindow", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
