/****************************************************************************
** Meta object code from reading C++ file 'ft_kqoauth.h'
**
** Created: Tue Nov 30 14:12:19 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ft_kqoauth.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ft_kqoauth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyEventLoop[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyEventLoop[] = {
    "MyEventLoop\0\0quitWithTimeout()\0"
};

const QMetaObject MyEventLoop::staticMetaObject = {
    { &QEventLoop::staticMetaObject, qt_meta_stringdata_MyEventLoop,
      qt_meta_data_MyEventLoop, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyEventLoop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyEventLoop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyEventLoop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyEventLoop))
        return static_cast<void*>(const_cast< MyEventLoop*>(this));
    return QEventLoop::qt_metacast(_clname);
}

int MyEventLoop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QEventLoop::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quitWithTimeout(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_Ft_KQOAuth[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      43,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     252,  243,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ft_KQOAuth[] = {
    "Ft_KQOAuth\0\0init()\0cleanup()\0constructor()\0"
    "ft_getRequestToken_data()\0"
    "ft_getRequestToken()\0ft_getAccessToken_data()\0"
    "ft_getAccessToken()\0ft_AuthenticatedCall_data()\0"
    "ft_AuthenticatedCall()\0"
    "ft_AuthenticatedGetCall_data()\0"
    "ft_AuthenticatedGetCall()\0response\0"
    "onRequestReady(QByteArray)\0"
};

const QMetaObject Ft_KQOAuth::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ft_KQOAuth,
      qt_meta_data_Ft_KQOAuth, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ft_KQOAuth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ft_KQOAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ft_KQOAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ft_KQOAuth))
        return static_cast<void*>(const_cast< Ft_KQOAuth*>(this));
    return QObject::qt_metacast(_clname);
}

int Ft_KQOAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: cleanup(); break;
        case 2: constructor(); break;
        case 3: ft_getRequestToken_data(); break;
        case 4: ft_getRequestToken(); break;
        case 5: ft_getAccessToken_data(); break;
        case 6: ft_getAccessToken(); break;
        case 7: ft_AuthenticatedCall_data(); break;
        case 8: ft_AuthenticatedCall(); break;
        case 9: ft_AuthenticatedGetCall_data(); break;
        case 10: ft_AuthenticatedGetCall(); break;
        case 11: onRequestReady((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
