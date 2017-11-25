/****************************************************************************
** Meta object code from reading C++ file 'vorschau.h'
**
** Created: Sat Nov 25 21:45:36 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eigeneKlassen/vorschau.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vorschau.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vorschau[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      38,   36,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   61,    9,    9, 0x0a,
     144,  125,    9,    9, 0x0a,
     194,  181,    9,    9, 0x0a,
     231,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vorschau[] = {
    "vorschau\0\0anfrage_werkstueckmasse()\0"
    "p\0sende_maus_pos(QPoint)\0"
    "neuer_programmtext,aktive_zeile\0"
    "slot_aktualisieren(QString,int)\0"
    "t_neu,aktive_zeile\0"
    "slot_aktualisieren(programmtext,int)\0"
    "zeilennummer\0slot_aktives_Element_einfaerben(int)\0"
    "slot_zf_gleich_eins()\0"
};

void vorschau::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        vorschau *_t = static_cast<vorschau *>(_o);
        switch (_id) {
        case 0: _t->anfrage_werkstueckmasse(); break;
        case 1: _t->sende_maus_pos((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->slot_aktualisieren((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slot_aktualisieren((*reinterpret_cast< programmtext(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slot_aktives_Element_einfaerben((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_zf_gleich_eins(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vorschau::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vorschau::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vorschau,
      qt_meta_data_vorschau, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vorschau::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vorschau::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vorschau::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vorschau))
        return static_cast<void*>(const_cast< vorschau*>(this));
    return QWidget::qt_metacast(_clname);
}

int vorschau::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void vorschau::anfrage_werkstueckmasse()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void vorschau::sende_maus_pos(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
