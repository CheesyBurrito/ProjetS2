/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
<<<<<<< HEAD
    QByteArrayData data[11];
    char stringdata0[118];
=======
    QByteArrayData data[14];
    char stringdata0[188];
>>>>>>> Connecting-Back-End-with-Front-End
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "escapeKeyPressed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "keyPressed"
QT_MOC_LITERAL(4, 40, 11), // "deleteStart"
QT_MOC_LITERAL(5, 52, 14), // "showMenuWindow"
QT_MOC_LITERAL(6, 67, 10), // "gameWindow"
QT_MOC_LITERAL(7, 78, 12), // "returnToMenu"
QT_MOC_LITERAL(8, 91, 8), // "quitGame"
<<<<<<< HEAD
QT_MOC_LITERAL(9, 100, 8), // "nextSong"
QT_MOC_LITERAL(10, 109, 8) // "prevSong"
=======
QT_MOC_LITERAL(9, 100, 18), // "p1_chooseCharacter"
QT_MOC_LITERAL(10, 119, 14), // "p1_askQuestion"
QT_MOC_LITERAL(11, 134, 18), // "p2_chooseCharacter"
QT_MOC_LITERAL(12, 153, 17), // "p2_answerQuestion"
QT_MOC_LITERAL(13, 171, 16) // "std::vector<int>"
>>>>>>> Connecting-Back-End-with-Front-End

    },
    "MainWindow\0escapeKeyPressed\0\0keyPressed\0"
    "deleteStart\0showMenuWindow\0gameWindow\0"
<<<<<<< HEAD
    "returnToMenu\0quitGame\0nextSong\0prevSong"
=======
    "returnToMenu\0quitGame\0p1_chooseCharacter\0"
    "p1_askQuestion\0p2_chooseCharacter\0"
    "p2_answerQuestion\0std::vector<int>"
>>>>>>> Connecting-Back-End-with-Front-End
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       9,   14, // methods
=======
      11,   14, // methods
>>>>>>> Connecting-Back-End-with-Front-End
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
<<<<<<< HEAD
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
=======
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
>>>>>>> Connecting-Back-End-with-Front-End

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
<<<<<<< HEAD
=======
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
>>>>>>> Connecting-Back-End-with-Front-End

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->escapeKeyPressed(); break;
        case 1: _t->keyPressed(); break;
        case 2: _t->deleteStart(); break;
        case 3: _t->showMenuWindow(); break;
        case 4: _t->gameWindow(); break;
        case 5: _t->returnToMenu(); break;
        case 6: _t->quitGame(); break;
<<<<<<< HEAD
        case 7: _t->nextSong(); break;
        case 8: _t->prevSong(); break;
=======
        case 7: _t->p1_chooseCharacter(); break;
        case 8: _t->p1_askQuestion(); break;
        case 9: _t->p2_chooseCharacter(); break;
        case 10: _t->p2_answerQuestion((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
>>>>>>> Connecting-Back-End-with-Front-End
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::escapeKeyPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::keyPressed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
=======
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
>>>>>>> Connecting-Back-End-with-Front-End
    }
    return _id;
}

// SIGNAL 0
void MainWindow::escapeKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::keyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
