/****************************************************************************
** Meta object code from reading C++ file 'mapthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/mapthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMapThread_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMapThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMapThread_t qt_meta_stringdata_CMapThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CMapThread"
QT_MOC_LITERAL(1, 11, 11), // "reachedHome"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "_device"
QT_MOC_LITERAL(4, 32, 10), // "StopThread"
QT_MOC_LITERAL(5, 43, 21), // "UpdateDeviceStructure"
QT_MOC_LITERAL(6, 65, 16), // "CDeviceStructure"
QT_MOC_LITERAL(7, 82, 8), // "_Devices"
QT_MOC_LITERAL(8, 91, 8), // "checkGPS"
QT_MOC_LITERAL(9, 100, 7), // "SetHome"
QT_MOC_LITERAL(10, 108, 14), // "QGeoCoordinate"
QT_MOC_LITERAL(11, 123, 11) // "_coordinate"

    },
    "CMapThread\0reachedHome\0\0_device\0"
    "StopThread\0UpdateDeviceStructure\0"
    "CDeviceStructure\0_Devices\0checkGPS\0"
    "SetHome\0QGeoCoordinate\0_coordinate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMapThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       8,    0,   46,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void CMapThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMapThread *_t = static_cast<CMapThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reachedHome((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->StopThread(); break;
        case 2: _t->UpdateDeviceStructure((*reinterpret_cast< CDeviceStructure(*)>(_a[1]))); break;
        case 3: _t->checkGPS(); break;
        case 4: _t->SetHome((*reinterpret_cast< QGeoCoordinate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMapThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMapThread::reachedHome)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMapThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CMapThread.data,
      qt_meta_data_CMapThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMapThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMapThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMapThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CMapThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CMapThread::reachedHome(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
