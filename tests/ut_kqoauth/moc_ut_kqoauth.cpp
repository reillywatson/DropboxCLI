/****************************************************************************
** Meta object code from reading C++ file 'ut_kqoauth.h'
**
** Created: Tue Nov 30 14:12:18 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ut_kqoauth.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ut_kqoauth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_KQOAuth[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
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
      71,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_KQOAuth[] = {
    "Ut_KQOAuth\0\0init()\0cleanup()\0constructor()\0"
    "ut_requestBaseString_data()\0"
    "ut_requestBaseString()\0ut_hmac_sha1_data()\0"
    "ut_hmac_sha1()\0"
};

const QMetaObject Ut_KQOAuth::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_KQOAuth,
      qt_meta_data_Ut_KQOAuth, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_KQOAuth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_KQOAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_KQOAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_KQOAuth))
        return static_cast<void*>(const_cast< Ut_KQOAuth*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_KQOAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: cleanup(); break;
        case 2: constructor(); break;
        case 3: ut_requestBaseString_data(); break;
        case 4: ut_requestBaseString(); break;
        case 5: ut_hmac_sha1_data(); break;
        case 6: ut_hmac_sha1(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
