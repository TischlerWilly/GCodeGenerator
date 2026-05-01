/****************************************************************************
** Meta object code from reading C++ file 'vorschau.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../eigeneKlassen/vorschau.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vorschau.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
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
struct qt_meta_tag_ZN8vorschauE_t {};
} // unnamed namespace

template <> constexpr inline auto vorschau::qt_create_metaobjectdata<qt_meta_tag_ZN8vorschauE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "vorschau",
        "anfrage_werkstueckmasse",
        "",
        "sende_maus_pos",
        "QPoint",
        "p",
        "slot_aktualisieren",
        "programmtext",
        "t_neu",
        "aktive_zeile",
        "slot_aktives_Element_einfaerben",
        "zeilennummer",
        "slot_zf_gleich_eins"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'anfrage_werkstueckmasse'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sende_maus_pos'
        QtMocHelpers::SignalData<void(QPoint)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'slot_aktualisieren'
        QtMocHelpers::SlotData<void(programmtext, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { QMetaType::Int, 9 },
        }}),
        // Slot 'slot_aktives_Element_einfaerben'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Slot 'slot_zf_gleich_eins'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<vorschau, qt_meta_tag_ZN8vorschauE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject vorschau::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8vorschauE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8vorschauE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8vorschauE_t>.metaTypes,
    nullptr
} };

void vorschau::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<vorschau *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->anfrage_werkstueckmasse(); break;
        case 1: _t->sende_maus_pos((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->slot_aktualisieren((*reinterpret_cast<std::add_pointer_t<programmtext>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->slot_aktives_Element_einfaerben((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->slot_zf_gleich_eins(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (vorschau::*)()>(_a, &vorschau::anfrage_werkstueckmasse, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (vorschau::*)(QPoint )>(_a, &vorschau::sende_maus_pos, 1))
            return;
    }
}

const QMetaObject *vorschau::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vorschau::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8vorschauE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int vorschau::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void vorschau::anfrage_werkstueckmasse()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void vorschau::sende_maus_pos(QPoint _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
