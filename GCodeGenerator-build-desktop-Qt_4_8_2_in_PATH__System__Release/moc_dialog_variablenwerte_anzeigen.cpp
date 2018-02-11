/****************************************************************************
** Meta object code from reading C++ file 'dialog_variablenwerte_anzeigen.h'
**
** Created: Sun Feb 11 14:55:51 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_variablenwerte_anzeigen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_variablenwerte_anzeigen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog_variablenwerte_anzeigen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   31,   31,   31, 0x08,
      86,   76,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialog_variablenwerte_anzeigen[] = {
    "Dialog_variablenwerte_anzeigen\0\0"
    "brauche_variablen()\0on_pushButton_clicked()\0"
    "variablen\0slot_bekomme_variablen(text_zeilenweise)\0"
};

void Dialog_variablenwerte_anzeigen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog_variablenwerte_anzeigen *_t = static_cast<Dialog_variablenwerte_anzeigen *>(_o);
        switch (_id) {
        case 0: _t->brauche_variablen(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->slot_bekomme_variablen((*reinterpret_cast< text_zeilenweise(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog_variablenwerte_anzeigen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog_variablenwerte_anzeigen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_variablenwerte_anzeigen,
      qt_meta_data_Dialog_variablenwerte_anzeigen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog_variablenwerte_anzeigen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog_variablenwerte_anzeigen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog_variablenwerte_anzeigen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_variablenwerte_anzeigen))
        return static_cast<void*>(const_cast< Dialog_variablenwerte_anzeigen*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_variablenwerte_anzeigen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Dialog_variablenwerte_anzeigen::brauche_variablen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
