/****************************************************************************
** Meta object code from reading C++ file 'CharacterCard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CharacterCard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CharacterCard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacterCard_t {
    QByteArrayData data[12];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharacterCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharacterCard_t qt_meta_stringdata_CharacterCard = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CharacterCard"
QT_MOC_LITERAL(1, 14, 7), // "hovered"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 6), // "traits"
QT_MOC_LITERAL(5, 42, 13), // "doubleClicked"
QT_MOC_LITERAL(6, 56, 16), // "clickedCharacter"
QT_MOC_LITERAL(7, 73, 10), // "Character*"
QT_MOC_LITERAL(8, 84, 8), // "flipCard"
QT_MOC_LITERAL(9, 93, 8), // "zoomCard"
QT_MOC_LITERAL(10, 102, 18), // "setChosenCharacter"
QT_MOC_LITERAL(11, 121, 9) // "character"

    },
    "CharacterCard\0hovered\0\0std::string\0"
    "traits\0doubleClicked\0clickedCharacter\0"
    "Character*\0flipCard\0zoomCard\0"
    "setChosenCharacter\0character"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterCard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   11,

       0        // eod
};

void CharacterCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CharacterCard *_t = static_cast<CharacterCard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hovered((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->doubleClicked(); break;
        case 2: _t->clickedCharacter((*reinterpret_cast< Character*(*)>(_a[1]))); break;
        case 3: _t->flipCard(); break;
        case 4: _t->zoomCard(); break;
        case 5: _t->setChosenCharacter((*reinterpret_cast< Character*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CharacterCard::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharacterCard::hovered)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CharacterCard::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharacterCard::doubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CharacterCard::*_t)(Character * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharacterCard::clickedCharacter)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CharacterCard::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_CharacterCard.data,
      qt_meta_data_CharacterCard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CharacterCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterCard.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int CharacterCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void CharacterCard::hovered(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CharacterCard::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CharacterCard::clickedCharacter(Character * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
