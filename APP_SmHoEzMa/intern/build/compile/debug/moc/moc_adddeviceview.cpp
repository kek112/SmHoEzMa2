/****************************************************************************
** Meta object code from reading C++ file 'adddeviceview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/adddeviceview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adddeviceview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAddDeviceView_t {
    QByteArrayData data[7];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAddDeviceView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAddDeviceView_t qt_meta_stringdata_CAddDeviceView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CAddDeviceView"
QT_MOC_LITERAL(1, 15, 10), // "sendDevice"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 24), // "CDeviceStructure::Device"
QT_MOC_LITERAL(4, 52, 7), // "_device"
QT_MOC_LITERAL(5, 60, 6), // "cancel"
QT_MOC_LITERAL(6, 67, 14) // "AcceptSettings"

    },
    "CAddDeviceView\0sendDevice\0\0"
    "CDeviceStructure::Device\0_device\0"
    "cancel\0AcceptSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAddDeviceView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CAddDeviceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAddDeviceView *_t = static_cast<CAddDeviceView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDevice((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 1: _t->cancel(); break;
        case 2: _t->AcceptSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CAddDeviceView::*)(CDeviceStructure::Device );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAddDeviceView::sendDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CAddDeviceView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAddDeviceView::cancel)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAddDeviceView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CAddDeviceView.data,
      qt_meta_data_CAddDeviceView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAddDeviceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAddDeviceView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAddDeviceView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CAddDeviceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CAddDeviceView::sendDevice(CDeviceStructure::Device _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAddDeviceView::cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
