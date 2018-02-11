/****************************************************************************
** Meta object code from reading C++ file 'dialog_import_ggf.h'
**
** Created: Sun Feb 11 14:56:04 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_import_ggf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_import_ggf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_import_ggf[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   19,   18,   18, 0x0a,
      59,   18,   18,   18, 0x08,
      93,   18,   18,   18, 0x08,
     124,   18,   18,   18, 0x08,
     153,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_import_ggf[] = {
    "Dialog_import_ggf\0\0text\0sendData(QString)\0"
    "getText(QString)\0on_pushButton_abbrechen_clicked()\0"
    "on_pushButton_import_clicked()\0"
    "on_pushButton_alle_clicked()\0"
    "on_pushButton_keine_clicked()\0"
};

void Dialog_import_ggf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_import_ggf *_t = static_cast<Dialog_import_ggf *>(_o);
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_abbrechen_clicked(); break;
        case 3: _t->on_pushButton_import_clicked(); break;
        case 4: _t->on_pushButton_alle_clicked(); break;
        case 5: _t->on_pushButton_keine_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog_import_ggf::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_import_ggf::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_import_ggf,
      qt_meta_data_Dialog_import_ggf, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_import_ggf::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_import_ggf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_import_ggf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_import_ggf))
        return static_cast<void*>(const_cast< Dialog_import_ggf*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_import_ggf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Dialog_import_ggf::sendData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
