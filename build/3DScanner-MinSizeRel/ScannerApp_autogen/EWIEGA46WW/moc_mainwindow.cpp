/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onShapeChanged",
    "",
    "shapeType",
    "onRotChanged",
    "rot",
    "stopRot",
    "updateRot",
    "dir",
    "sendLidarData",
    "GLfloat",
    "d",
    "r",
    "s",
    "active",
    "sq",
    "pcdFileSelected",
    "filePath",
    "changeKeyframe",
    "oldIndex",
    "newIndex",
    "loadEmptyFrame",
    "index",
    "clearKeyframe",
    "KFNum",
    "clearAllKeyframes",
    "onRegisterPressed",
    "onConstructMesh",
    "currentTab",
    "radioRowSelected",
    "applyPairwiseRegistration",
    "maxCorrDist",
    "maxIter",
    "fitThresh",
    "applyVoxeltoCombined",
    "leafSize",
    "updateScanSettings",
    "eAngles",
    "aAngles",
    "changeFloatParam",
    "name",
    "value",
    "changeIntParam",
    "applyFilter",
    "radius",
    "upsampleRadius",
    "upsampleStep",
    "order",
    "revertKeyframe",
    "triggerUpdate",
    "triggerKeyframeChange",
    "combineKeyframes",
    "cleanKeyframe",
    "applyPassThrough",
    "std::string",
    "axis",
    "min",
    "max",
    "applyVoxelGrid",
    "applySOR",
    "meanK",
    "stddev",
    "applyMirrorCorrect",
    "maxY",
    "revertClean",
    "undoClean",
    "redoClean",
    "tryRegistration",
    "sourceIndex",
    "targetIndex",
    "on_comboBox_currentIndexChanged",
    "updateServo",
    "command",
    "on_tiltEdit_returnPressed",
    "on_panEdit_returnPressed",
    "on_getDistanceButton_clicked",
    "sendData",
    "instruction",
    "msg",
    "readLidarData",
    "on_scanButton_clicked",
    "on_rotCheck_stateChanged",
    "arg1",
    "on_leftRot_pressed",
    "on_rightRot_pressed",
    "on_leftRot_released",
    "on_rightRot_released",
    "on_elevEdit_returnPressed",
    "openClicked",
    "saveKeyframe",
    "saveKeyframes",
    "saveKeyframesAsOne",
    "saveSession",
    "loadSession",
    "on_registerButton_clicked",
    "on_tabWidget_tabBarClicked",
    "onAddKeyframeClicked",
    "onKeyframeTableRowSelected",
    "QModelIndex",
    "current",
    "previous",
    "on_constructMeshButton_clicked",
    "on_lowerButton_clicked",
    "on_higherButton_clicked",
    "on_stopButton_clicked",
    "on_pauseButton_clicked",
    "on_lineScanButton_clicked",
    "on_rotAzimButton_clicked",
    "on_panScanButton_clicked",
    "on_filterButton_clicked",
    "on_revertButton_clicked",
    "on_combineButton_clicked",
    "on_cleanButton_clicked",
    "on_passButton_clicked",
    "on_voxButton_clicked",
    "on_sorButton_clicked",
    "on_applyAlltoCurButton_clicked",
    "on_applyAlltoAllButton_clicked",
    "on_revertCleanButton_clicked",
    "on_undoCleanButton_clicked",
    "on_redoCleanButton_clicked",
    "on_pairRegisButton_clicked",
    "onUpdateComboCount",
    "kfCount",
    "on_targetIndC_currentIndexChanged",
    "on_sourceIndC_currentIndexChanged",
    "on_scanOneButton_clicked",
    "on_mirrorCorrectButton_clicked",
    "on_mirrorCorrectButton_2_clicked",
    "on_passButton_2_clicked",
    "on_voxButton_2_clicked",
    "on_sorButton_2_clicked",
    "on_pairRegisButton_2_clicked",
    "on_voxButton_3_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      89,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      33,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  548,    2, 0x06,    1 /* Public */,
       4,    1,  551,    2, 0x06,    3 /* Public */,
       6,    0,  554,    2, 0x06,    5 /* Public */,
       7,    1,  555,    2, 0x06,    6 /* Public */,
       9,    5,  558,    2, 0x06,    8 /* Public */,
      16,    1,  569,    2, 0x06,   14 /* Public */,
      18,    2,  572,    2, 0x06,   16 /* Public */,
      21,    1,  577,    2, 0x06,   19 /* Public */,
      23,    1,  580,    2, 0x06,   21 /* Public */,
      25,    0,  583,    2, 0x06,   23 /* Public */,
      26,    0,  584,    2, 0x06,   24 /* Public */,
      27,    0,  585,    2, 0x06,   25 /* Public */,
      28,    1,  586,    2, 0x06,   26 /* Public */,
      29,    1,  589,    2, 0x06,   28 /* Public */,
      30,    3,  592,    2, 0x06,   30 /* Public */,
      34,    1,  599,    2, 0x06,   34 /* Public */,
      36,    2,  602,    2, 0x06,   36 /* Public */,
      39,    2,  607,    2, 0x06,   39 /* Public */,
      42,    2,  612,    2, 0x06,   42 /* Public */,
      43,    4,  617,    2, 0x06,   45 /* Public */,
      48,    0,  626,    2, 0x06,   50 /* Public */,
      49,    0,  627,    2, 0x06,   51 /* Public */,
      50,    1,  628,    2, 0x06,   52 /* Public */,
      51,    0,  631,    2, 0x06,   54 /* Public */,
      52,    0,  632,    2, 0x06,   55 /* Public */,
      53,    3,  633,    2, 0x06,   56 /* Public */,
      58,    1,  640,    2, 0x06,   60 /* Public */,
      59,    2,  643,    2, 0x06,   62 /* Public */,
      62,    1,  648,    2, 0x06,   65 /* Public */,
      64,    0,  651,    2, 0x06,   67 /* Public */,
      65,    0,  652,    2, 0x06,   68 /* Public */,
      66,    0,  653,    2, 0x06,   69 /* Public */,
      67,    5,  654,    2, 0x06,   70 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      70,    1,  665,    2, 0x08,   76 /* Private */,
      71,    1,  668,    2, 0x08,   78 /* Private */,
      73,    0,  671,    2, 0x08,   80 /* Private */,
      74,    0,  672,    2, 0x08,   81 /* Private */,
      75,    0,  673,    2, 0x08,   82 /* Private */,
      76,    2,  674,    2, 0x08,   83 /* Private */,
      79,    0,  679,    2, 0x08,   86 /* Private */,
      80,    0,  680,    2, 0x08,   87 /* Private */,
      81,    1,  681,    2, 0x08,   88 /* Private */,
      83,    0,  684,    2, 0x08,   90 /* Private */,
      84,    0,  685,    2, 0x08,   91 /* Private */,
      85,    0,  686,    2, 0x08,   92 /* Private */,
      86,    0,  687,    2, 0x08,   93 /* Private */,
      87,    0,  688,    2, 0x08,   94 /* Private */,
      88,    0,  689,    2, 0x08,   95 /* Private */,
      89,    0,  690,    2, 0x08,   96 /* Private */,
      90,    0,  691,    2, 0x08,   97 /* Private */,
      91,    0,  692,    2, 0x08,   98 /* Private */,
      92,    0,  693,    2, 0x08,   99 /* Private */,
      93,    0,  694,    2, 0x08,  100 /* Private */,
      94,    0,  695,    2, 0x08,  101 /* Private */,
      95,    1,  696,    2, 0x08,  102 /* Private */,
      96,    0,  699,    2, 0x08,  104 /* Private */,
      97,    2,  700,    2, 0x08,  105 /* Private */,
     101,    0,  705,    2, 0x08,  108 /* Private */,
     102,    0,  706,    2, 0x08,  109 /* Private */,
     103,    0,  707,    2, 0x08,  110 /* Private */,
     104,    0,  708,    2, 0x08,  111 /* Private */,
     105,    0,  709,    2, 0x08,  112 /* Private */,
     106,    0,  710,    2, 0x08,  113 /* Private */,
     107,    0,  711,    2, 0x08,  114 /* Private */,
     108,    0,  712,    2, 0x08,  115 /* Private */,
     109,    0,  713,    2, 0x08,  116 /* Private */,
     110,    0,  714,    2, 0x08,  117 /* Private */,
     111,    0,  715,    2, 0x08,  118 /* Private */,
     112,    0,  716,    2, 0x08,  119 /* Private */,
     113,    0,  717,    2, 0x08,  120 /* Private */,
     114,    0,  718,    2, 0x08,  121 /* Private */,
     115,    0,  719,    2, 0x08,  122 /* Private */,
     116,    0,  720,    2, 0x08,  123 /* Private */,
     117,    0,  721,    2, 0x08,  124 /* Private */,
     118,    0,  722,    2, 0x08,  125 /* Private */,
     119,    0,  723,    2, 0x08,  126 /* Private */,
     120,    0,  724,    2, 0x08,  127 /* Private */,
     121,    0,  725,    2, 0x08,  128 /* Private */,
     122,    1,  726,    2, 0x08,  129 /* Private */,
     124,    1,  729,    2, 0x08,  131 /* Private */,
     125,    1,  732,    2, 0x08,  133 /* Private */,
     126,    0,  735,    2, 0x08,  135 /* Private */,
     127,    0,  736,    2, 0x08,  136 /* Private */,
     128,    0,  737,    2, 0x08,  137 /* Private */,
     129,    0,  738,    2, 0x08,  138 /* Private */,
     130,    0,  739,    2, 0x08,  139 /* Private */,
     131,    0,  740,    2, 0x08,  140 /* Private */,
     132,    0,  741,    2, 0x08,  141 /* Private */,
     133,    0,  742,    2, 0x08,  142 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Double, QMetaType::Int, QMetaType::Double,   31,   32,   33,
    QMetaType::Void, QMetaType::Double,   35,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,   37,   38,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,   40,   41,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   40,   41,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,   44,   45,   46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 54, QMetaType::Int, QMetaType::Int,   55,   56,   57,
    QMetaType::Void, QMetaType::Double,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   60,   61,
    QMetaType::Void, QMetaType::Double,   63,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Double,   68,   69,   31,   32,   33,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QByteArray,   72,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   77,   78,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 98, 0x80000000 | 98,   99,  100,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  123,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onShapeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onRotChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stopRot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateRot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendLidarData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pcdFileSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'changeKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadEmptyFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearAllKeyframes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRegisterPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onConstructMesh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'radioRowSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'applyPairwiseRegistration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'applyVoxeltoCombined'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateScanSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'changeFloatParam'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'changeIntParam'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'applyFilter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'revertKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerKeyframeChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'combineKeyframes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cleanKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyPassThrough'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'applyVoxelGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'applySOR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'applyMirrorCorrect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'revertClean'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'undoClean'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'redoClean'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tryRegistration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateServo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'on_tiltEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_panEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_getDistanceButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'readLidarData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotCheck_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_leftRot_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rightRot_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leftRot_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rightRot_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_elevEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveKeyframes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveKeyframesAsOne'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveSession'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadSession'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_registerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tabWidget_tabBarClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onAddKeyframeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onKeyframeTableRowSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_constructMeshButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lowerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_higherButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pauseButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineScanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotAzimButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_panScanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_filterButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_revertButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_combineButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cleanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_passButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voxButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sorButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_applyAlltoCurButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_applyAlltoAllButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_revertCleanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_undoCleanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_redoCleanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pairRegisButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUpdateComboCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_targetIndC_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sourceIndC_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_scanOneButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mirrorCorrectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mirrorCorrectButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_passButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voxButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sorButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pairRegisButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voxButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onShapeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->onRotChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->stopRot(); break;
        case 3: _t->updateRot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->sendLidarData((*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 5: _t->pcdFileSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->changeKeyframe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->loadEmptyFrame((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->clearKeyframe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->clearAllKeyframes(); break;
        case 10: _t->onRegisterPressed(); break;
        case 11: _t->onConstructMesh(); break;
        case 12: _t->currentTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->radioRowSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->applyPairwiseRegistration((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 15: _t->applyVoxeltoCombined((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 16: _t->updateScanSettings((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2]))); break;
        case 17: _t->changeFloatParam((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 18: _t->changeIntParam((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 19: _t->applyFilter((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 20: _t->revertKeyframe(); break;
        case 21: _t->triggerUpdate(); break;
        case 22: _t->triggerKeyframeChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->combineKeyframes(); break;
        case 24: _t->cleanKeyframe(); break;
        case 25: _t->applyPassThrough((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 26: _t->applyVoxelGrid((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 27: _t->applySOR((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 28: _t->applyMirrorCorrect((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 29: _t->revertClean(); break;
        case 30: _t->undoClean(); break;
        case 31: _t->redoClean(); break;
        case 32: _t->tryRegistration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5]))); break;
        case 33: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->updateServo((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 35: _t->on_tiltEdit_returnPressed(); break;
        case 36: _t->on_panEdit_returnPressed(); break;
        case 37: _t->on_getDistanceButton_clicked(); break;
        case 38: _t->sendData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 39: _t->readLidarData(); break;
        case 40: _t->on_scanButton_clicked(); break;
        case 41: _t->on_rotCheck_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->on_leftRot_pressed(); break;
        case 43: _t->on_rightRot_pressed(); break;
        case 44: _t->on_leftRot_released(); break;
        case 45: _t->on_rightRot_released(); break;
        case 46: _t->on_elevEdit_returnPressed(); break;
        case 47: _t->openClicked(); break;
        case 48: _t->saveKeyframe(); break;
        case 49: _t->saveKeyframes(); break;
        case 50: _t->saveKeyframesAsOne(); break;
        case 51: _t->saveSession(); break;
        case 52: _t->loadSession(); break;
        case 53: _t->on_registerButton_clicked(); break;
        case 54: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 55: _t->onAddKeyframeClicked(); break;
        case 56: _t->onKeyframeTableRowSelected((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 57: _t->on_constructMeshButton_clicked(); break;
        case 58: _t->on_lowerButton_clicked(); break;
        case 59: _t->on_higherButton_clicked(); break;
        case 60: _t->on_stopButton_clicked(); break;
        case 61: _t->on_pauseButton_clicked(); break;
        case 62: _t->on_lineScanButton_clicked(); break;
        case 63: _t->on_rotAzimButton_clicked(); break;
        case 64: _t->on_panScanButton_clicked(); break;
        case 65: _t->on_filterButton_clicked(); break;
        case 66: _t->on_revertButton_clicked(); break;
        case 67: _t->on_combineButton_clicked(); break;
        case 68: _t->on_cleanButton_clicked(); break;
        case 69: _t->on_passButton_clicked(); break;
        case 70: _t->on_voxButton_clicked(); break;
        case 71: _t->on_sorButton_clicked(); break;
        case 72: _t->on_applyAlltoCurButton_clicked(); break;
        case 73: _t->on_applyAlltoAllButton_clicked(); break;
        case 74: _t->on_revertCleanButton_clicked(); break;
        case 75: _t->on_undoCleanButton_clicked(); break;
        case 76: _t->on_redoCleanButton_clicked(); break;
        case 77: _t->on_pairRegisButton_clicked(); break;
        case 78: _t->onUpdateComboCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 79: _t->on_targetIndC_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 80: _t->on_sourceIndC_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 81: _t->on_scanOneButton_clicked(); break;
        case 82: _t->on_mirrorCorrectButton_clicked(); break;
        case 83: _t->on_mirrorCorrectButton_2_clicked(); break;
        case 84: _t->on_passButton_2_clicked(); break;
        case 85: _t->on_voxButton_2_clicked(); break;
        case 86: _t->on_sorButton_2_clicked(); break;
        case 87: _t->on_pairRegisButton_2_clicked(); break;
        case 88: _t->on_voxButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::onShapeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::onRotChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::stopRot; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (_t _q_method = &MainWindow::updateRot; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(GLfloat , GLfloat , GLfloat , int , int );
            if (_t _q_method = &MainWindow::sendLidarData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::pcdFileSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int );
            if (_t _q_method = &MainWindow::changeKeyframe; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::loadEmptyFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::clearKeyframe; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::clearAllKeyframes; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::onRegisterPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::onConstructMesh; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::currentTab; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::radioRowSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double , int , double );
            if (_t _q_method = &MainWindow::applyPairwiseRegistration; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double );
            if (_t _q_method = &MainWindow::applyVoxeltoCombined; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 , quint8 );
            if (_t _q_method = &MainWindow::updateScanSettings; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , float );
            if (_t _q_method = &MainWindow::changeFloatParam; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , int );
            if (_t _q_method = &MainWindow::changeIntParam; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float , float , float , int );
            if (_t _q_method = &MainWindow::applyFilter; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::revertKeyframe; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::triggerUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::triggerKeyframeChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::combineKeyframes; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::cleanKeyframe; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::string , int , int );
            if (_t _q_method = &MainWindow::applyPassThrough; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double );
            if (_t _q_method = &MainWindow::applyVoxelGrid; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , double );
            if (_t _q_method = &MainWindow::applySOR; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(double );
            if (_t _q_method = &MainWindow::applyMirrorCorrect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::revertClean; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::undoClean; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::redoClean; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int , double , int , double );
            if (_t _q_method = &MainWindow::tryRegistration; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 32;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 89)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 89;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 89)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 89;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::onShapeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::onRotChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::stopRot()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::updateRot(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sendLidarData(GLfloat _t1, GLfloat _t2, GLfloat _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::pcdFileSelected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::changeKeyframe(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::loadEmptyFrame(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::clearKeyframe(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::clearAllKeyframes()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::onRegisterPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::onConstructMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MainWindow::currentTab(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::radioRowSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::applyPairwiseRegistration(double _t1, int _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::applyVoxeltoCombined(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainWindow::updateScanSettings(quint8 _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::changeFloatParam(QString _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::changeIntParam(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::applyFilter(float _t1, float _t2, float _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::revertKeyframe()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void MainWindow::triggerUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void MainWindow::triggerKeyframeChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::combineKeyframes()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void MainWindow::cleanKeyframe()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void MainWindow::applyPassThrough(std::string _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void MainWindow::applyVoxelGrid(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void MainWindow::applySOR(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void MainWindow::applyMirrorCorrect(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void MainWindow::revertClean()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void MainWindow::undoClean()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void MainWindow::redoClean()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void MainWindow::tryRegistration(int _t1, int _t2, double _t3, int _t4, double _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}
QT_WARNING_POP
