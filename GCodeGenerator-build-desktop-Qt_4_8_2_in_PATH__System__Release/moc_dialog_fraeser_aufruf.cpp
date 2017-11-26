/****************************************************************************
** Meta object code from reading C++ file 'dialog_fraeser_aufruf.h'
**
** Created: Sun Nov 26 14:35:42 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_fraeser_aufruf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_fraeser_aufruf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_Fraeser_Aufruf[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
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
     150,  110,   22,   22, 0x0a,
     199,   22,   22,   22, 0x08,
     233,   22,   22,   22, 0x08,
     267,   22,   22,   22, 0x08,
     299,  294,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_Fraeser_Aufruf[] = {
    "Dialog_Fraeser_Aufruf\0\0text\0"
    "sendDialogData(QString)\0"
    "sendDialogDataModifyed(QString)\0"
    "signalSaveConfig(QString)\0"
    "text,openToChangeData,WerkzeugNamen,wkz\0"
    "getDialogData(QString,bool,QStringList,werkzeug)\0"
    "on_pushButton_abbrechen_clicked()\0"
    "on_pushButton_speichern_clicked()\0"
    "on_pushButton_ok_clicked()\0arg1\0"
    "on_comboBox_werkzeug_currentIndexChanged(QString)\0"
};

void Dialog_Fraeser_Aufruf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_Fraeser_Aufruf *_t = static_cast<Dialog_Fraeser_Aufruf *>(_o);
        switch (_id) {
        case 0: _t->sendDialogData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendDialogDataModifyed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalSaveConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->getDialogData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< werkzeug(*)>(_a[4]))); break;
        case 4: _t->on_pushButton_abbrechen_clicked(); break;
        case 5: _t->on_pushButton_speichern_clicked(); break;
        case 6: _t->on_pushButton_ok_clicked(); break;
        case 7: _t->on_comboBox_werkzeug_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog_Fraeser_Aufruf::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_Fraeser_Aufruf::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_Fraeser_Aufruf,
      qt_meta_data_Dialog_Fraeser_Aufruf, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_Fraeser_Aufruf::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_Fraeser_Aufruf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_Fraeser_Aufruf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_Fraeser_Aufruf))
        return static_cast<void*>(const_cast< Dialog_Fraeser_Aufruf*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_Fraeser_Aufruf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Dialog_Fraeser_Aufruf::sendDialogData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_Fraeser_Aufruf::sendDialogDataModifyed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_Fraeser_Aufruf::signalSaveConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
