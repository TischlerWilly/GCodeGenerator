/****************************************************************************
** Meta object code from reading C++ file 'dialog_fraeser_bogen.h'
**
** Created: Sun Feb 11 14:56:00 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_fraeser_bogen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_fraeser_bogen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_fraeser_bogen[] = {

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
      27,   22,   21,   21, 0x05,
      51,   22,   21,   21, 0x05,
      83,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   21,   21,   21, 0x08,
     143,   21,   21,   21, 0x08,
     177,   21,   21,   21, 0x08,
     226,  204,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_fraeser_bogen[] = {
    "Dialog_fraeser_bogen\0\0text\0"
    "sendDialogData(QString)\0"
    "sendDialogDataModifyed(QString)\0"
    "signalSaveConfig(QString)\0"
    "on_pushButton_abbrechen_clicked()\0"
    "on_pushButton_speichern_clicked()\0"
    "on_pushButton_ok_clicked()\0"
    "text,openToChangeData\0getDialogData(QString,bool)\0"
};

void Dialog_fraeser_bogen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_fraeser_bogen *_t = static_cast<Dialog_fraeser_bogen *>(_o);
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

const QMetaObjectExtraData Dialog_fraeser_bogen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_fraeser_bogen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_fraeser_bogen,
      qt_meta_data_Dialog_fraeser_bogen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_fraeser_bogen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_fraeser_bogen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_fraeser_bogen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_fraeser_bogen))
        return static_cast<void*>(const_cast< Dialog_fraeser_bogen*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_fraeser_bogen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Dialog_fraeser_bogen::sendDialogData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_fraeser_bogen::sendDialogDataModifyed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_fraeser_bogen::signalSaveConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
