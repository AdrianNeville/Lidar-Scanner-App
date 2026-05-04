/****************************************************************************
** Meta object code from reading C++ file 'visualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../visualizer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualizer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVisualizerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVisualizerENDCLASS = QtMocHelpers::stringData(
    "Visualizer",
    "changeRot",
    "",
    "rot",
    "updateRot",
    "dir",
    "stopRot",
    "receiveLidarData",
    "GLfloat",
    "d",
    "r",
    "s",
    "activeFrame",
    "sq",
    "loadPCD",
    "path",
    "loadKeyframe",
    "oldIndex",
    "newIndex",
    "clearKeyframe",
    "KFNum",
    "clearAllKeyframes",
    "registerKeyframe",
    "constructMesh",
    "updateCurrentTab",
    "index",
    "loadEmptyFrame",
    "receiveScanSettings",
    "eAngles",
    "aAngles",
    "triggerUpdate",
    "triggerKeyframeChange",
    "handlePosUpdate",
    "visRegisterKeyframe",
    "sourceIndex",
    "targetIndex",
    "RegistrationResult",
    "res",
    "updateByLoadSession",
    "kfCount"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVisualizerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x0a,    1 /* Public */,
       4,    1,  125,    2, 0x0a,    3 /* Public */,
       6,    0,  128,    2, 0x0a,    5 /* Public */,
       7,    5,  129,    2, 0x0a,    6 /* Public */,
      14,    1,  140,    2, 0x0a,   12 /* Public */,
      16,    2,  143,    2, 0x0a,   14 /* Public */,
      19,    1,  148,    2, 0x0a,   17 /* Public */,
      21,    0,  151,    2, 0x0a,   19 /* Public */,
      22,    0,  152,    2, 0x0a,   20 /* Public */,
      23,    0,  153,    2, 0x0a,   21 /* Public */,
      24,    1,  154,    2, 0x0a,   22 /* Public */,
      26,    1,  157,    2, 0x0a,   24 /* Public */,
      27,    2,  160,    2, 0x0a,   26 /* Public */,
      30,    0,  165,    2, 0x0a,   29 /* Public */,
      31,    1,  166,    2, 0x0a,   30 /* Public */,
      32,    1,  169,    2, 0x0a,   32 /* Public */,
      33,    3,  172,    2, 0x0a,   34 /* Public */,
      38,    1,  179,    2, 0x0a,   38 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,   28,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 36,   34,   35,   37,
    QMetaType::Void, QMetaType::Int,   39,

       0        // eod
};

Q_CONSTINIT const QMetaObject Visualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSVisualizerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVisualizerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVisualizerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Visualizer, std::true_type>,
        // method 'changeRot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateRot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'stopRot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveLidarData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLfloat, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadPCD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearAllKeyframes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'constructMesh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCurrentTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadEmptyFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'receiveScanSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'triggerUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerKeyframeChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handlePosUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'visRegisterKeyframe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<RegistrationResult, std::false_type>,
        // method 'updateByLoadSession'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Visualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Visualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeRot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->updateRot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->stopRot(); break;
        case 3: _t->receiveLidarData((*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<GLfloat>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 4: _t->loadPCD((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->loadKeyframe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->clearKeyframe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->clearAllKeyframes(); break;
        case 8: _t->registerKeyframe(); break;
        case 9: _t->constructMesh(); break;
        case 10: _t->updateCurrentTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->loadEmptyFrame((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->receiveScanSettings((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[2]))); break;
        case 13: _t->triggerUpdate(); break;
        case 14: _t->triggerKeyframeChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->handlePosUpdate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->visRegisterKeyframe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<RegistrationResult>>(_a[3]))); break;
        case 17: _t->updateByLoadSession((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Visualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Visualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVisualizerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions_3_3_Core"))
        return static_cast< QOpenGLFunctions_3_3_Core*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int Visualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
