/****************************************************************************
** Meta object code from reading C++ file 'twittercli.h'
**
** Created: Tue Nov 30 18:05:55 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "twittercli.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'twittercli.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TwitterCLI[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   12,   11,   11, 0x08,
      75,   69,   11,   11, 0x08,
     114,  105,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TwitterCLI[] = {
    "TwitterCLI\0\0token,tokenSecret\0"
    "onAccessTokenReceived(QString,QString)\0"
    "reply\0replyFinished(QNetworkReply*)\0"
    "response\0outputResponse(QByteArray)\0"
};

const QMetaObject TwitterCLI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TwitterCLI,
      qt_meta_data_TwitterCLI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TwitterCLI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TwitterCLI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TwitterCLI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TwitterCLI))
        return static_cast<void*>(const_cast< TwitterCLI*>(this));
    return QObject::qt_metacast(_clname);
}

int TwitterCLI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onAccessTokenReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: outputResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
