/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../samp17_1ESP8266/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "do_com_readyRead",
    "",
    "do_label_clicked",
    "on_btnWF_UART_Qry_clicked",
    "on_btnWF_Reset_clicked",
    "on_btnWF_Test_clicked",
    "on_btnWF_UART_Set_clicked",
    "on_btnTrans_Exit_clicked",
    "on_btnTrans_Enter_clicked",
    "on_btnTCP_GetMac_clicked",
    "on_btnWF_GetAP_clicked",
    "on_btnTCP_Query_clicked",
    "on_btnWF_SetAsSTA_clicked",
    "on_btnWF_SetAP_clicked",
    "on_btnTCP_SetServer_clicked",
    "on_pushButton_4_clicked",
    "on_btnTrans_AutoOnReset_clicked",
    "on_btnNormSend_clicked",
    "on_btnTCP_AutoConn_clicked",
    "on_actCom_Open_triggered",
    "on_actCom_Close_triggered",
    "on_actClear_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[26];
    char stringdata5[23];
    char stringdata6[22];
    char stringdata7[26];
    char stringdata8[25];
    char stringdata9[26];
    char stringdata10[25];
    char stringdata11[23];
    char stringdata12[24];
    char stringdata13[26];
    char stringdata14[23];
    char stringdata15[28];
    char stringdata16[24];
    char stringdata17[32];
    char stringdata18[23];
    char stringdata19[27];
    char stringdata20[25];
    char stringdata21[26];
    char stringdata22[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "do_com_readyRead"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 16),  // "do_label_clicked"
        QT_MOC_LITERAL(46, 25),  // "on_btnWF_UART_Qry_clicked"
        QT_MOC_LITERAL(72, 22),  // "on_btnWF_Reset_clicked"
        QT_MOC_LITERAL(95, 21),  // "on_btnWF_Test_clicked"
        QT_MOC_LITERAL(117, 25),  // "on_btnWF_UART_Set_clicked"
        QT_MOC_LITERAL(143, 24),  // "on_btnTrans_Exit_clicked"
        QT_MOC_LITERAL(168, 25),  // "on_btnTrans_Enter_clicked"
        QT_MOC_LITERAL(194, 24),  // "on_btnTCP_GetMac_clicked"
        QT_MOC_LITERAL(219, 22),  // "on_btnWF_GetAP_clicked"
        QT_MOC_LITERAL(242, 23),  // "on_btnTCP_Query_clicked"
        QT_MOC_LITERAL(266, 25),  // "on_btnWF_SetAsSTA_clicked"
        QT_MOC_LITERAL(292, 22),  // "on_btnWF_SetAP_clicked"
        QT_MOC_LITERAL(315, 27),  // "on_btnTCP_SetServer_clicked"
        QT_MOC_LITERAL(343, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(367, 31),  // "on_btnTrans_AutoOnReset_clicked"
        QT_MOC_LITERAL(399, 22),  // "on_btnNormSend_clicked"
        QT_MOC_LITERAL(422, 26),  // "on_btnTCP_AutoConn_clicked"
        QT_MOC_LITERAL(449, 24),  // "on_actCom_Open_triggered"
        QT_MOC_LITERAL(474, 25),  // "on_actCom_Close_triggered"
        QT_MOC_LITERAL(500, 21)   // "on_actClear_triggered"
    },
    "MainWindow",
    "do_com_readyRead",
    "",
    "do_label_clicked",
    "on_btnWF_UART_Qry_clicked",
    "on_btnWF_Reset_clicked",
    "on_btnWF_Test_clicked",
    "on_btnWF_UART_Set_clicked",
    "on_btnTrans_Exit_clicked",
    "on_btnTrans_Enter_clicked",
    "on_btnTCP_GetMac_clicked",
    "on_btnWF_GetAP_clicked",
    "on_btnTCP_Query_clicked",
    "on_btnWF_SetAsSTA_clicked",
    "on_btnWF_SetAP_clicked",
    "on_btnTCP_SetServer_clicked",
    "on_pushButton_4_clicked",
    "on_btnTrans_AutoOnReset_clicked",
    "on_btnNormSend_clicked",
    "on_btnTCP_AutoConn_clicked",
    "on_actCom_Open_triggered",
    "on_actCom_Close_triggered",
    "on_actClear_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  140,    2, 0x08,    1 /* Private */,
       3,    0,  141,    2, 0x08,    2 /* Private */,
       4,    0,  142,    2, 0x08,    3 /* Private */,
       5,    0,  143,    2, 0x08,    4 /* Private */,
       6,    0,  144,    2, 0x08,    5 /* Private */,
       7,    0,  145,    2, 0x08,    6 /* Private */,
       8,    0,  146,    2, 0x08,    7 /* Private */,
       9,    0,  147,    2, 0x08,    8 /* Private */,
      10,    0,  148,    2, 0x08,    9 /* Private */,
      11,    0,  149,    2, 0x08,   10 /* Private */,
      12,    0,  150,    2, 0x08,   11 /* Private */,
      13,    0,  151,    2, 0x08,   12 /* Private */,
      14,    0,  152,    2, 0x08,   13 /* Private */,
      15,    0,  153,    2, 0x08,   14 /* Private */,
      16,    0,  154,    2, 0x08,   15 /* Private */,
      17,    0,  155,    2, 0x08,   16 /* Private */,
      18,    0,  156,    2, 0x08,   17 /* Private */,
      19,    0,  157,    2, 0x08,   18 /* Private */,
      20,    0,  158,    2, 0x08,   19 /* Private */,
      21,    0,  159,    2, 0x08,   20 /* Private */,
      22,    0,  160,    2, 0x08,   21 /* Private */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'do_com_readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_label_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_UART_Qry_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_Reset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_Test_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_UART_Set_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTrans_Exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTrans_Enter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTCP_GetMac_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_GetAP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTCP_Query_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_SetAsSTA_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWF_SetAP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTCP_SetServer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTrans_AutoOnReset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnNormSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTCP_AutoConn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actCom_Open_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actCom_Close_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actClear_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->do_com_readyRead(); break;
        case 1: _t->do_label_clicked(); break;
        case 2: _t->on_btnWF_UART_Qry_clicked(); break;
        case 3: _t->on_btnWF_Reset_clicked(); break;
        case 4: _t->on_btnWF_Test_clicked(); break;
        case 5: _t->on_btnWF_UART_Set_clicked(); break;
        case 6: _t->on_btnTrans_Exit_clicked(); break;
        case 7: _t->on_btnTrans_Enter_clicked(); break;
        case 8: _t->on_btnTCP_GetMac_clicked(); break;
        case 9: _t->on_btnWF_GetAP_clicked(); break;
        case 10: _t->on_btnTCP_Query_clicked(); break;
        case 11: _t->on_btnWF_SetAsSTA_clicked(); break;
        case 12: _t->on_btnWF_SetAP_clicked(); break;
        case 13: _t->on_btnTCP_SetServer_clicked(); break;
        case 14: _t->on_pushButton_4_clicked(); break;
        case 15: _t->on_btnTrans_AutoOnReset_clicked(); break;
        case 16: _t->on_btnNormSend_clicked(); break;
        case 17: _t->on_btnTCP_AutoConn_clicked(); break;
        case 18: _t->on_actCom_Open_triggered(); break;
        case 19: _t->on_actCom_Close_triggered(); break;
        case 20: _t->on_actClear_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
