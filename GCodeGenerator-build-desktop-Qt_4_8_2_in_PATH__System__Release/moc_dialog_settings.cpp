/****************************************************************************
** Meta object code from reading C++ file 'dialog_settings.h'
**
** Created: Sun Feb 11 14:55:53 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialoge/dialog_settings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialog_settings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   48,   16,   16, 0x0a,
      98,   16,   16,   16, 0x08,
     129,   16,   16,   16, 0x08,
     158,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dialog_settings[] = {
    "dialog_settings\0\0text\0signalSaveConfig(QString)\0"
    "text,openToChangeData\0getDialogData(QString,bool)\0"
    "on_pushButton_cancel_clicked()\0"
    "on_pushButton_save_clicked()\0"
    "on_pushButton_tooltable_clicked()\0"
};

void dialog_settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dialog_settings *_t = static_cast<dialog_settings *>(_o);
        switch (_id) {
        case 0: _t->signalSaveConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getDialogData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_cancel_clicked(); break;
        case 3: _t->on_pushButton_save_clicked(); break;
        case 4: _t->on_pushButton_tooltable_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dialog_settings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dialog_settings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_settings,
      qt_meta_data_dialog_settings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialog_settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialog_settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialog_settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_settings))
        return static_cast<void*>(const_cast< dialog_settings*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialog_settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void dialog_settings::signalSaveConfig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
