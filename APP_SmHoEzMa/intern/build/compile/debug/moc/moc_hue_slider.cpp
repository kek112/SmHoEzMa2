/****************************************************************************
** Meta object code from reading C++ file 'hue_slider.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../extern/Qt-Color-Widgets-master/include/QtColorWidgets/hue_slider.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hue_slider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_color_widgets__HueSlider_t {
    QByteArrayData data[17];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_color_widgets__HueSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_color_widgets__HueSlider_t qt_meta_stringdata_color_widgets__HueSlider = {
    {
QT_MOC_LITERAL(0, 0, 24), // "color_widgets::HueSlider"
QT_MOC_LITERAL(1, 25, 15), // "colorHueChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 8), // "colorHue"
QT_MOC_LITERAL(4, 51, 12), // "colorChanged"
QT_MOC_LITERAL(5, 64, 13), // "setColorValue"
QT_MOC_LITERAL(6, 78, 5), // "value"
QT_MOC_LITERAL(7, 84, 18), // "setColorSaturation"
QT_MOC_LITERAL(8, 103, 13), // "setColorAlpha"
QT_MOC_LITERAL(9, 117, 5), // "alpha"
QT_MOC_LITERAL(10, 123, 11), // "setColorHue"
QT_MOC_LITERAL(11, 135, 8), // "setColor"
QT_MOC_LITERAL(12, 144, 5), // "color"
QT_MOC_LITERAL(13, 150, 12), // "setFullColor"
QT_MOC_LITERAL(14, 163, 15), // "colorSaturation"
QT_MOC_LITERAL(15, 179, 10), // "colorValue"
QT_MOC_LITERAL(16, 190, 10) // "colorAlpha"

    },
    "color_widgets::HueSlider\0colorHueChanged\0"
    "\0colorHue\0colorChanged\0setColorValue\0"
    "value\0setColorSaturation\0setColorAlpha\0"
    "alpha\0setColorHue\0setColor\0color\0"
    "setFullColor\0colorSaturation\0colorValue\0"
    "colorAlpha"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_color_widgets__HueSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   60,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    6,
    QMetaType::Void, QMetaType::QReal,    6,
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void, QMetaType::QColor,   12,

 // properties: name, type, flags
      14, QMetaType::QReal, 0x00095103,
      15, QMetaType::QReal, 0x00095103,
      16, QMetaType::QReal, 0x00095103,
      12, QMetaType::QColor, 0x00095103,
       3, QMetaType::QReal, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void color_widgets::HueSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HueSlider *_t = static_cast<HueSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorHueChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->setColorValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->setColorSaturation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->setColorAlpha((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->setColorHue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setFullColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HueSlider::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HueSlider::colorHueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HueSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HueSlider::colorChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        HueSlider *_t = static_cast<HueSlider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->colorSaturation(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->colorValue(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->colorAlpha(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->colorHue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        HueSlider *_t = static_cast<HueSlider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setColorSaturation(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setColorValue(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setColorAlpha(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setColorHue(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject color_widgets::HueSlider::staticMetaObject = {
    { &GradientSlider::staticMetaObject, qt_meta_stringdata_color_widgets__HueSlider.data,
      qt_meta_data_color_widgets__HueSlider,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *color_widgets::HueSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *color_widgets::HueSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_color_widgets__HueSlider.stringdata0))
        return static_cast<void*>(this);
    return GradientSlider::qt_metacast(_clname);
}

int color_widgets::HueSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GradientSlider::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void color_widgets::HueSlider::colorHueChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void color_widgets::HueSlider::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
