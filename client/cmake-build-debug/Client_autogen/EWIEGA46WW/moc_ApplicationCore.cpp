/****************************************************************************
** Meta object code from reading C++ file 'ApplicationCore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ApplicationCore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ApplicationCore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApplicationCore_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApplicationCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApplicationCore_t qt_meta_stringdata_ApplicationCore = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ApplicationCore"
QT_MOC_LITERAL(1, 16, 17), // "onSocketConnected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "onSocketDisconnected"
QT_MOC_LITERAL(4, 56, 19), // "onConnectionTimeOut"
QT_MOC_LITERAL(5, 76, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(6, 94, 13), // "onMessageSent"
QT_MOC_LITERAL(7, 108, 17), // "onLoginBtnPressed"
QT_MOC_LITERAL(8, 126, 8), // "username"
QT_MOC_LITERAL(9, 135, 8) // "password"

    },
    "ApplicationCore\0onSocketConnected\0\0"
    "onSocketDisconnected\0onConnectionTimeOut\0"
    "onSocketReadyRead\0onMessageSent\0"
    "onLoginBtnPressed\0username\0password"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApplicationCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,

       0        // eod
};

void ApplicationCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApplicationCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSocketConnected(); break;
        case 1: _t->onSocketDisconnected(); break;
        case 2: _t->onConnectionTimeOut(); break;
        case 3: _t->onSocketReadyRead(); break;
        case 4: _t->onMessageSent(); break;
        case 5: _t->onLoginBtnPressed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApplicationCore::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ApplicationCore.data,
    qt_meta_data_ApplicationCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApplicationCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApplicationCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationCore.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ApplicationCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
