/****************************************************************************
** Meta object code from reading C++ file 'menubar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/menubar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menubar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMenuBar_t {
    QByteArrayData data[9];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMenuBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMenuBar_t qt_meta_stringdata_CMenuBar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CMenuBar"
QT_MOC_LITERAL(1, 9, 19), // "DeviceButtonPressed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "SettingsButtonPressed"
QT_MOC_LITERAL(4, 52, 18), // "AboutButtonPressed"
QT_MOC_LITERAL(5, 71, 18), // "SleepButtonPressed"
QT_MOC_LITERAL(6, 90, 20), // "priavteButtonPressed"
QT_MOC_LITERAL(7, 111, 16), // "QAbstractButton*"
QT_MOC_LITERAL(8, 128, 14) // "_pressedButton"

    },
    "CMenuBar\0DeviceButtonPressed\0\0"
    "SettingsButtonPressed\0AboutButtonPressed\0"
    "SleepButtonPressed\0priavteButtonPressed\0"
    "QAbstractButton*\0_pressedButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMenuBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void CMenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMenuBar *_t = static_cast<CMenuBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DeviceButtonPressed(); break;
        case 1: _t->SettingsButtonPressed(); break;
        case 2: _t->AboutButtonPressed(); break;
        case 3: _t->SleepButtonPressed(); break;
        case 4: _t->priavteButtonPressed((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMenuBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMenuBar::DeviceButtonPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CMenuBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMenuBar::SettingsButtonPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CMenuBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMenuBar::AboutButtonPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CMenuBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMenuBar::SleepButtonPressed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMenuBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMenuBar.data,
      qt_meta_data_CMenuBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMenuBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CMenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CMenuBar::DeviceButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CMenuBar::SettingsButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CMenuBar::AboutButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CMenuBar::SleepButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
