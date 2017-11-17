/****************************************************************************
** Meta object code from reading C++ file 'dialog_kreistasche.h'
**
** Created: Fri Nov 17 21:29:17 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_kreistasche.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_kreistasche.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_Kreistasche[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x05,
      49,   20,   19,   19, 0x05,
      81,   20,   19,   19, 0x05,
     127,  107,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     207,  171,   19,   19, 0x0a,
     261,  247,   19,   19, 0x0a,
     287,   19,   19,   19, 0x08,
     321,   19,   19,   19, 0x08,
     355,   19,   19,   19, 0x08,
     388,  382,   19,   19, 0x08,
     421,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_Kreistasche[] = {
    "Dialog_Kreistasche\0\0text\0"
    "sendDialogData(QString)\0"
    "sendDialogDataModifyed(QString)\0"
    "signalSaveConfig(QString)\0Werkzeugname,Dialog\0"
    "signalBraucheWerkzeugdaten(QString,QString)\0"
    "text,openToChangeData,WerkzeugNamen\0"
    "getDialogData(QString,bool,QStringList)\0"
    "Werkzeugdaten\0getWerkzeugdaten(QString)\0"
    "on_pushButton_Abbrechen_clicked()\0"
    "on_pushButton_Speichern_clicked()\0"
    "on_pushButton_OK_clicked()\0index\0"
    "on_tabWidget_currentChanged(int)\0"
    "on_comboBox_Werkzeug_currentIndexChanged()\0"
};

void Dialog_Kreistasche::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_Kreistasche *_t = static_cast<Dialog_Kreistasche *>(_o);
        switch (_id) {
        case 0: _t->sendDialogData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendDialogDataModifyed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalSaveConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signalBraucheWerkzeugdaten((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getDialogData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 5: _t->getWerkzeugdaten((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_Abbrechen_clicked(); break;
        case 7: _t->on_pushButton_Speichern_clicked(); break;
        case 8: _t->on_pushButton_OK_clicked(); break;
        case 9: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_Werkzeug_currentIndexChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog_Kreistasche::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_Kreistasche::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_Kreistasche,
      qt_meta_data_Dialog_Kreistasche, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_Kreistasche::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_Kreistasche::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_Kreistasche::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_Kreistasche))
        return static_cast<void*>(const_cast< Dialog_Kreistasche*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_Kreistasche::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Dialog_Kreistasche::sendDialogData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_Kreistasche::sendDialogDataModifyed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_Kreistasche::signalSaveConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dialog_Kreistasche::signalBraucheWerkzeugdaten(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
