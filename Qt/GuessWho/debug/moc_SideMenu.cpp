/****************************************************************************
** Meta object code from reading C++ file 'SideMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SideMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SideMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SideMenu_t {
    QByteArrayData data[10];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SideMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SideMenu_t qt_meta_stringdata_SideMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SideMenu"
QT_MOC_LITERAL(1, 9, 12), // "lowerBarTest"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 9), // "setTraits"
QT_MOC_LITERAL(5, 45, 9), // "newTraits"
QT_MOC_LITERAL(6, 55, 14), // "switchZoomIcon"
QT_MOC_LITERAL(7, 70, 9), // "fpgaError"
QT_MOC_LITERAL(8, 80, 6), // "fpgaOn"
QT_MOC_LITERAL(9, 87, 7) // "fpgaOff"

    },
    "SideMenu\0lowerBarTest\0\0std::string\0"
    "setTraits\0newTraits\0switchZoomIcon\0"
    "fpgaError\0fpgaOn\0fpgaOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SideMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   49,    2, 0x0a /* Public */,
       6,    0,   52,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SideMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SideMenu *_t = static_cast<SideMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lowerBarTest((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setTraits((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->switchZoomIcon(); break;
        case 3: _t->fpgaError(); break;
        case 4: _t->fpgaOn(); break;
        case 5: _t->fpgaOff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SideMenu::*_t)(std::string , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SideMenu::lowerBarTest)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SideMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SideMenu.data,
      qt_meta_data_SideMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SideMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SideMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SideMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SideMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SideMenu::lowerBarTest(std::string _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
