/****************************************************************************
** Meta object code from reading C++ file 'QuestionMenuBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QuestionMenuBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuestionMenuBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuestionMenuBar_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuestionMenuBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuestionMenuBar_t qt_meta_stringdata_QuestionMenuBar = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QuestionMenuBar"
QT_MOC_LITERAL(1, 16, 12), // "sendQuestion"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "std::vector<int>"
QT_MOC_LITERAL(4, 47, 21), // "treeWidgetItemClicked"
QT_MOC_LITERAL(5, 69, 18), // "goUpTreeWidgetItem"
QT_MOC_LITERAL(6, 88, 20) // "goDownTreeWidgetItem"

    },
    "QuestionMenuBar\0sendQuestion\0\0"
    "std::vector<int>\0treeWidgetItemClicked\0"
    "goUpTreeWidgetItem\0goDownTreeWidgetItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionMenuBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuestionMenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuestionMenuBar *_t = static_cast<QuestionMenuBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendQuestion((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 1: _t->treeWidgetItemClicked(); break;
        case 2: _t->goUpTreeWidgetItem(); break;
        case 3: _t->goDownTreeWidgetItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QuestionMenuBar::*_t)(std::vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuestionMenuBar::sendQuestion)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QuestionMenuBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QuestionMenuBar.data,
      qt_meta_data_QuestionMenuBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QuestionMenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuestionMenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuestionMenuBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QuestionMenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QuestionMenuBar::sendQuestion(std::vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
