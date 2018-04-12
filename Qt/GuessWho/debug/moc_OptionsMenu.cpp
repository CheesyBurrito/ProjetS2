/****************************************************************************
** Meta object code from reading C++ file 'OptionsMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OptionsMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionsMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionsMenu_t {
<<<<<<< HEAD
    QByteArrayData data[6];
    char stringdata0[76];
=======
    QByteArrayData data[11];
    char stringdata0[128];
>>>>>>> Connecting-Back-End-with-Front-End
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsMenu_t qt_meta_stringdata_OptionsMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "OptionsMenu"
<<<<<<< HEAD
QT_MOC_LITERAL(1, 12, 10), // "showDialog"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "addCharacters"
QT_MOC_LITERAL(4, 38, 19), // "activateOptionsMenu"
QT_MOC_LITERAL(5, 58, 17) // "createOptionsMenu"

    },
    "OptionsMenu\0showDialog\0\0addCharacters\0"
    "activateOptionsMenu\0createOptionsMenu"
=======
QT_MOC_LITERAL(1, 12, 7), // "hovered"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "MenuButton*"
QT_MOC_LITERAL(4, 33, 16), // "setHoveredButton"
QT_MOC_LITERAL(5, 50, 6), // "button"
QT_MOC_LITERAL(6, 57, 10), // "showDialog"
QT_MOC_LITERAL(7, 68, 13), // "addCharacters"
QT_MOC_LITERAL(8, 82, 19), // "activateOptionsMenu"
QT_MOC_LITERAL(9, 102, 17), // "createOptionsMenu"
QT_MOC_LITERAL(10, 120, 7) // "newList"

    },
    "OptionsMenu\0hovered\0\0MenuButton*\0"
    "setHoveredButton\0button\0showDialog\0"
    "addCharacters\0activateOptionsMenu\0"
    "createOptionsMenu\0newList"
>>>>>>> Connecting-Back-End-with-Front-End
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       4,   14, // methods
=======
       7,   14, // methods
>>>>>>> Connecting-Back-End-with-Front-End
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
<<<<<<< HEAD
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,
=======
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
>>>>>>> Connecting-Back-End-with-Front-End

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsMenu *_t = static_cast<OptionsMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
<<<<<<< HEAD
        case 0: _t->showDialog(); break;
        case 1: _t->addCharacters(); break;
        case 2: _t->activateOptionsMenu(); break;
        case 3: _t->createOptionsMenu(); break;
=======
        case 0: _t->hovered((*reinterpret_cast< MenuButton*(*)>(_a[1]))); break;
        case 1: _t->setHoveredButton((*reinterpret_cast< MenuButton*(*)>(_a[1]))); break;
        case 2: _t->showDialog(); break;
        case 3: _t->addCharacters(); break;
        case 4: _t->activateOptionsMenu(); break;
        case 5: _t->createOptionsMenu(); break;
        case 6: _t->newList(); break;
>>>>>>> Connecting-Back-End-with-Front-End
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OptionsMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionsMenu.data,
      qt_meta_data_OptionsMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionsMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OptionsMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
=======
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
>>>>>>> Connecting-Back-End-with-Front-End
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
