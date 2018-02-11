/****************************************************************************
** Meta object code from reading C++ file 'dialog_fraeser_gerade.h'
**
** Created: Sun Feb 11 14:55:59 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_fraeser_gerade.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_fraeser_gerade.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_fraeser_gerade[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   23,   22,   22, 0x05,
      52,   23,   22,   22, 0x05,
      84,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   22,   22,   22, 0x08,
     144,   22,   22,   22, 0x08,
     178,   22,   22,   22, 0x08,
     227,  205,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_fraeser_gerade[] = {
    "Dialog_fraeser_gerade\0\0text\0"
    "sendDialogData(QString)\0"
    "sendDialogDataModifyed(QString)\0"
    "signalSaveConfig(QString)\0"
    "on_pushButton_abbrechen_clicked()\0"
    "on_pushButton_speichern_clicked()\0"
    "on_pushButton_ok_clicked()\0"
    "text,openToChangeData\0getDialogData(QString,bool)\0"
};

void Dialog_fraeser_gerade::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_fraeser_gerade *_t = static_cast<Dialog_fraeser_gerade *>(_o);
        switch (_id) {
        case 0: _t->sendDialogData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendDialogDataModifyed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalSaveConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_abbrechen_clicked(); break;
        case 4: _t->on_pushButton_speichern_clicked(); break;
        case 5: _t->on_pushButton_ok_clicked(); break;
        case 6: _t->getDialogData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog_fraeser_gerade::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_fraeser_gerade::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_fraeser_gerade,
      qt_meta_data_Dialog_fraeser_gerade, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_fraeser_gerade::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_fraeser_gerade::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_fraeser_gerade::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_fraeser_gerade))
        return static_cast<void*>(const_cast< Dialog_fraeser_gerade*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_fraeser_gerade::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Dialog_fraeser_gerade::sendDialogData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_fraeser_gerade::sendDialogDataModifyed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_fraeser_gerade::signalSaveConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
