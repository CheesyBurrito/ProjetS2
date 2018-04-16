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
    QByteArrayData data[48];
    char stringdata0[748];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "wKeyPressed"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "sKeyPressed"
QT_MOC_LITERAL(4, 36, 15), // "enterKeyPressed"
QT_MOC_LITERAL(5, 52, 16), // "escapeKeyPressed"
QT_MOC_LITERAL(6, 69, 10), // "keyPressed"
QT_MOC_LITERAL(7, 80, 17), // "phonemeKeyPressed"
QT_MOC_LITERAL(8, 98, 11), // "deleteStart"
QT_MOC_LITERAL(9, 110, 14), // "showMenuWindow"
QT_MOC_LITERAL(10, 125, 10), // "gameWindow"
QT_MOC_LITERAL(11, 136, 12), // "returnToMenu"
QT_MOC_LITERAL(12, 149, 17), // "exitAfterGameOver"
QT_MOC_LITERAL(13, 167, 8), // "quitGame"
QT_MOC_LITERAL(14, 176, 8), // "nextSong"
QT_MOC_LITERAL(15, 185, 8), // "prevSong"
QT_MOC_LITERAL(16, 194, 9), // "playPause"
QT_MOC_LITERAL(17, 204, 17), // "emulateMouseClick"
QT_MOC_LITERAL(18, 222, 14), // "setColorPlayer"
QT_MOC_LITERAL(19, 237, 17), // "setColorPlayer1_0"
QT_MOC_LITERAL(20, 255, 17), // "setColorPlayer1_1"
QT_MOC_LITERAL(21, 273, 17), // "setColorPlayer1_2"
QT_MOC_LITERAL(22, 291, 17), // "setColorPlayer1_3"
QT_MOC_LITERAL(23, 309, 17), // "setColorPlayer1_4"
QT_MOC_LITERAL(24, 327, 17), // "setColorPlayer1_5"
QT_MOC_LITERAL(25, 345, 17), // "setColorPlayer2_0"
QT_MOC_LITERAL(26, 363, 17), // "setColorPlayer2_1"
QT_MOC_LITERAL(27, 381, 17), // "setColorPlayer2_2"
QT_MOC_LITERAL(28, 399, 17), // "setColorPlayer2_3"
QT_MOC_LITERAL(29, 417, 17), // "setColorPlayer2_4"
QT_MOC_LITERAL(30, 435, 17), // "setColorPlayer2_5"
QT_MOC_LITERAL(31, 453, 18), // "p1_chooseCharacter"
QT_MOC_LITERAL(32, 472, 19), // "p1_askFirstQuestion"
QT_MOC_LITERAL(33, 492, 14), // "p1_askQuestion"
QT_MOC_LITERAL(34, 507, 17), // "p1_answerQuestion"
QT_MOC_LITERAL(35, 525, 16), // "std::vector<int>"
QT_MOC_LITERAL(36, 542, 20), // "p1_answerQuestionYes"
QT_MOC_LITERAL(37, 563, 19), // "p1_answerQuestionNo"
QT_MOC_LITERAL(38, 583, 18), // "p2_chooseCharacter"
QT_MOC_LITERAL(39, 602, 16), // "p1_getLastAnswer"
QT_MOC_LITERAL(40, 619, 14), // "p2_askQuestion"
QT_MOC_LITERAL(41, 634, 17), // "p2_answerQuestion"
QT_MOC_LITERAL(42, 652, 20), // "p2_answerQuestionYes"
QT_MOC_LITERAL(43, 673, 19), // "p2_answerQuestionNo"
QT_MOC_LITERAL(44, 693, 16), // "p2_getLastAnswer"
QT_MOC_LITERAL(45, 710, 8), // "gameOver"
QT_MOC_LITERAL(46, 719, 6), // "winner"
QT_MOC_LITERAL(47, 726, 21) // "checkEndGameCondition"

    },
    "MainWindow\0wKeyPressed\0\0sKeyPressed\0"
    "enterKeyPressed\0escapeKeyPressed\0"
    "keyPressed\0phonemeKeyPressed\0deleteStart\0"
    "showMenuWindow\0gameWindow\0returnToMenu\0"
    "exitAfterGameOver\0quitGame\0nextSong\0"
    "prevSong\0playPause\0emulateMouseClick\0"
    "setColorPlayer\0setColorPlayer1_0\0"
    "setColorPlayer1_1\0setColorPlayer1_2\0"
    "setColorPlayer1_3\0setColorPlayer1_4\0"
    "setColorPlayer1_5\0setColorPlayer2_0\0"
    "setColorPlayer2_1\0setColorPlayer2_2\0"
    "setColorPlayer2_3\0setColorPlayer2_4\0"
    "setColorPlayer2_5\0p1_chooseCharacter\0"
    "p1_askFirstQuestion\0p1_askQuestion\0"
    "p1_answerQuestion\0std::vector<int>\0"
    "p1_answerQuestionYes\0p1_answerQuestionNo\0"
    "p2_chooseCharacter\0p1_getLastAnswer\0"
    "p2_askQuestion\0p2_answerQuestion\0"
    "p2_answerQuestionYes\0p2_answerQuestionNo\0"
    "p2_getLastAnswer\0gameOver\0winner\0"
    "checkEndGameCondition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  234,    2, 0x06 /* Public */,
       3,    0,  235,    2, 0x06 /* Public */,
       4,    0,  236,    2, 0x06 /* Public */,
       5,    0,  237,    2, 0x06 /* Public */,
       6,    0,  238,    2, 0x06 /* Public */,
       7,    0,  239,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  240,    2, 0x0a /* Public */,
       9,    0,  241,    2, 0x0a /* Public */,
      10,    0,  242,    2, 0x0a /* Public */,
      11,    0,  243,    2, 0x0a /* Public */,
      12,    0,  244,    2, 0x0a /* Public */,
      13,    0,  245,    2, 0x0a /* Public */,
      14,    0,  246,    2, 0x0a /* Public */,
      15,    0,  247,    2, 0x0a /* Public */,
      16,    0,  248,    2, 0x0a /* Public */,
      17,    0,  249,    2, 0x0a /* Public */,
      18,    0,  250,    2, 0x0a /* Public */,
      19,    0,  251,    2, 0x0a /* Public */,
      20,    0,  252,    2, 0x0a /* Public */,
      21,    0,  253,    2, 0x0a /* Public */,
      22,    0,  254,    2, 0x0a /* Public */,
      23,    0,  255,    2, 0x0a /* Public */,
      24,    0,  256,    2, 0x0a /* Public */,
      25,    0,  257,    2, 0x0a /* Public */,
      26,    0,  258,    2, 0x0a /* Public */,
      27,    0,  259,    2, 0x0a /* Public */,
      28,    0,  260,    2, 0x0a /* Public */,
      29,    0,  261,    2, 0x0a /* Public */,
      30,    0,  262,    2, 0x0a /* Public */,
      31,    0,  263,    2, 0x0a /* Public */,
      32,    0,  264,    2, 0x0a /* Public */,
      33,    0,  265,    2, 0x0a /* Public */,
      34,    1,  266,    2, 0x0a /* Public */,
      36,    0,  269,    2, 0x0a /* Public */,
      37,    0,  270,    2, 0x0a /* Public */,
      38,    0,  271,    2, 0x0a /* Public */,
      39,    0,  272,    2, 0x0a /* Public */,
      40,    0,  273,    2, 0x0a /* Public */,
      41,    1,  274,    2, 0x0a /* Public */,
      42,    0,  277,    2, 0x0a /* Public */,
      43,    0,  278,    2, 0x0a /* Public */,
      44,    0,  279,    2, 0x0a /* Public */,
      45,    1,  280,    2, 0x0a /* Public */,
      47,    0,  283,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Bool,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wKeyPressed(); break;
        case 1: _t->sKeyPressed(); break;
        case 2: _t->enterKeyPressed(); break;
        case 3: _t->escapeKeyPressed(); break;
        case 4: _t->keyPressed(); break;
        case 5: _t->phonemeKeyPressed(); break;
        case 6: _t->deleteStart(); break;
        case 7: _t->showMenuWindow(); break;
        case 8: _t->gameWindow(); break;
        case 9: _t->returnToMenu(); break;
        case 10: _t->exitAfterGameOver(); break;
        case 11: _t->quitGame(); break;
        case 12: _t->nextSong(); break;
        case 13: _t->prevSong(); break;
        case 14: _t->playPause(); break;
        case 15: _t->emulateMouseClick(); break;
        case 16: _t->setColorPlayer(); break;
        case 17: _t->setColorPlayer1_0(); break;
        case 18: _t->setColorPlayer1_1(); break;
        case 19: _t->setColorPlayer1_2(); break;
        case 20: _t->setColorPlayer1_3(); break;
        case 21: _t->setColorPlayer1_4(); break;
        case 22: _t->setColorPlayer1_5(); break;
        case 23: _t->setColorPlayer2_0(); break;
        case 24: _t->setColorPlayer2_1(); break;
        case 25: _t->setColorPlayer2_2(); break;
        case 26: _t->setColorPlayer2_3(); break;
        case 27: _t->setColorPlayer2_4(); break;
        case 28: _t->setColorPlayer2_5(); break;
        case 29: _t->p1_chooseCharacter(); break;
        case 30: _t->p1_askFirstQuestion(); break;
        case 31: _t->p1_askQuestion(); break;
        case 32: _t->p1_answerQuestion((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 33: _t->p1_answerQuestionYes(); break;
        case 34: _t->p1_answerQuestionNo(); break;
        case 35: _t->p2_chooseCharacter(); break;
        case 36: _t->p1_getLastAnswer(); break;
        case 37: _t->p2_askQuestion(); break;
        case 38: _t->p2_answerQuestion((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 39: _t->p2_answerQuestionYes(); break;
        case 40: _t->p2_answerQuestionNo(); break;
        case 41: _t->p2_getLastAnswer(); break;
        case 42: _t->gameOver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 43: { bool _r = _t->checkEndGameCondition();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::wKeyPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sKeyPressed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::enterKeyPressed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::escapeKeyPressed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::keyPressed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::phonemeKeyPressed)) {
                *result = 5;
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
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::wKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::sKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::enterKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::escapeKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::keyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::phonemeKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
