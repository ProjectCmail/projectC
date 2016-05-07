/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "TimerTick1"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "TimerTick2"
QT_MOC_LITERAL(4, 34, 22), // "on_pushButton1_clicked"
QT_MOC_LITERAL(5, 57, 22), // "on_pushButton2_clicked"
QT_MOC_LITERAL(6, 80, 22), // "on_pushButton4_clicked"
QT_MOC_LITERAL(7, 103, 22), // "on_pushButton5_clicked"
QT_MOC_LITERAL(8, 126, 22), // "on_pushButton6_clicked"
QT_MOC_LITERAL(9, 149, 22), // "on_pushButton7_clicked"
QT_MOC_LITERAL(10, 172, 22), // "on_pushButton8_clicked"
QT_MOC_LITERAL(11, 195, 22), // "on_pushButton3_clicked"
QT_MOC_LITERAL(12, 218, 22), // "on_pushButton9_clicked"
QT_MOC_LITERAL(13, 241, 23), // "on_pushButton10_clicked"
QT_MOC_LITERAL(14, 265, 8), // "slotOpen"
QT_MOC_LITERAL(15, 274, 9), // "slotAbout"
QT_MOC_LITERAL(16, 284, 13), // "slotImageSize"
QT_MOC_LITERAL(17, 298, 2) // "on"

    },
    "MainWindow\0TimerTick1\0\0TimerTick2\0"
    "on_pushButton1_clicked\0on_pushButton2_clicked\0"
    "on_pushButton4_clicked\0on_pushButton5_clicked\0"
    "on_pushButton6_clicked\0on_pushButton7_clicked\0"
    "on_pushButton8_clicked\0on_pushButton3_clicked\0"
    "on_pushButton9_clicked\0on_pushButton10_clicked\0"
    "slotOpen\0slotAbout\0slotImageSize\0on"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    1,  103,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->TimerTick1(); break;
        case 1: _t->TimerTick2(); break;
        case 2: _t->on_pushButton1_clicked(); break;
        case 3: _t->on_pushButton2_clicked(); break;
        case 4: _t->on_pushButton4_clicked(); break;
        case 5: _t->on_pushButton5_clicked(); break;
        case 6: _t->on_pushButton6_clicked(); break;
        case 7: _t->on_pushButton7_clicked(); break;
        case 8: _t->on_pushButton8_clicked(); break;
        case 9: _t->on_pushButton3_clicked(); break;
        case 10: _t->on_pushButton9_clicked(); break;
        case 11: _t->on_pushButton10_clicked(); break;
        case 12: _t->slotOpen(); break;
        case 13: _t->slotAbout(); break;
        case 14: _t->slotImageSize((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
