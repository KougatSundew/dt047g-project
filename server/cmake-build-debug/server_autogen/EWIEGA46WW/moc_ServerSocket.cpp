/****************************************************************************
** Meta object code from reading C++ file 'ServerSocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ServerSocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerSocket_t {
    QByteArrayData data[11];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerSocket_t qt_meta_stringdata_ServerSocket = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerSocket"
QT_MOC_LITERAL(1, 13, 22), // "disconnectedFromClient"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "messageReceived"
QT_MOC_LITERAL(4, 53, 13), // "ServerSocket*"
QT_MOC_LITERAL(5, 67, 6), // "sender"
QT_MOC_LITERAL(6, 74, 7), // "message"
QT_MOC_LITERAL(7, 82, 10), // "logMessage"
QT_MOC_LITERAL(8, 93, 3), // "msg"
QT_MOC_LITERAL(9, 97, 20), // "disconnectFromClient"
QT_MOC_LITERAL(10, 118, 14) // "receiveMessage"

    },
    "ServerSocket\0disconnectedFromClient\0"
    "\0messageReceived\0ServerSocket*\0sender\0"
    "message\0logMessage\0msg\0disconnectFromClient\0"
    "receiveMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerSocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   48,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnectedFromClient(); break;
        case 1: _t->messageReceived((*reinterpret_cast< ServerSocket*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->disconnectFromClient(); break;
        case 4: _t->receiveMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ServerSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSocket::disconnectedFromClient)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerSocket::*)(ServerSocket * , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSocket::messageReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerSocket::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSocket::logMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerSocket::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ServerSocket.data,
    qt_meta_data_ServerSocket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ServerSocket::disconnectedFromClient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ServerSocket::messageReceived(ServerSocket * _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerSocket::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
