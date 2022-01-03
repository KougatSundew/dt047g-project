/****************************************************************************
** Meta object code from reading C++ file 'Client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[16];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 9), // "connected"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "messageReceived"
QT_MOC_LITERAL(4, 34, 6), // "sender"
QT_MOC_LITERAL(5, 41, 4), // "text"
QT_MOC_LITERAL(6, 46, 11), // "onReadyRead"
QT_MOC_LITERAL(7, 58, 15), // "connectToServer"
QT_MOC_LITERAL(8, 74, 12), // "QHostAddress"
QT_MOC_LITERAL(9, 87, 7), // "address"
QT_MOC_LITERAL(10, 95, 4), // "port"
QT_MOC_LITERAL(11, 100, 11), // "sendMessage"
QT_MOC_LITERAL(12, 112, 11), // "const char*"
QT_MOC_LITERAL(13, 124, 20), // "disconnectFromServer"
QT_MOC_LITERAL(14, 145, 5), // "login"
QT_MOC_LITERAL(15, 151, 8) // "userName"

    },
    "Client\0connected\0\0messageReceived\0"
    "sender\0text\0onReadyRead\0connectToServer\0"
    "QHostAddress\0address\0port\0sendMessage\0"
    "const char*\0disconnectFromServer\0login\0"
    "userName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   60,    2, 0x08 /* Private */,
       7,    2,   61,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::UShort,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->connectToServer((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 4: _t->connectToServer(); break;
        case 5: _t->sendMessage((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 6: _t->disconnectFromServer(); break;
        case 7: _t->login((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::messageReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Client::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Client.data,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Client::messageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
