/****************************************************************************
** Meta object code from reading C++ file 'mainview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/mainview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMainView_t {
    QByteArrayData data[13];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainView_t qt_meta_stringdata_CMainView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CMainView"
QT_MOC_LITERAL(1, 10, 17), // "sendIsMenuVisible"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "_visible"
QT_MOC_LITERAL(4, 38, 11), // "triggerMenu"
QT_MOC_LITERAL(5, 50, 9), // "closeMenu"
QT_MOC_LITERAL(6, 60, 11), // "_sendSignal"
QT_MOC_LITERAL(7, 72, 8), // "openMenu"
QT_MOC_LITERAL(8, 81, 11), // "ShowDevices"
QT_MOC_LITERAL(9, 93, 12), // "ShowSettings"
QT_MOC_LITERAL(10, 106, 9), // "ShowAbout"
QT_MOC_LITERAL(11, 116, 10), // "SleepModus"
QT_MOC_LITERAL(12, 127, 13) // "MenuXPosition"

    },
    "CMainView\0sendIsMenuVisible\0\0_visible\0"
    "triggerMenu\0closeMenu\0_sendSignal\0"
    "openMenu\0ShowDevices\0ShowSettings\0"
    "ShowAbout\0SleepModus\0MenuXPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       5,    0,   66,    2, 0x28 /* Private | MethodCloned */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00095103,

       0        // eod
};

void CMainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainView *_t = static_cast<CMainView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendIsMenuVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->triggerMenu(); break;
        case 2: _t->closeMenu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->closeMenu(); break;
        case 4: _t->openMenu(); break;
        case 5: _t->ShowDevices(); break;
        case 6: _t->ShowSettings(); break;
        case 7: _t->ShowAbout(); break;
        case 8: _t->SleepModus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMainView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMainView::sendIsMenuVisible)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CMainView *_t = static_cast<CMainView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->MenuXPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CMainView *_t = static_cast<CMainView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMenuXPosition(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CMainView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMainView.data,
      qt_meta_data_CMainView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMainView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CMainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CMainView::sendIsMenuVisible(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
