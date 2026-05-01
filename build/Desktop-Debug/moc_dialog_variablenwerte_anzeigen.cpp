/****************************************************************************
** Meta object code from reading C++ file 'dialog_variablenwerte_anzeigen.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialoge/dialog_variablenwerte_anzeigen.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_variablenwerte_anzeigen.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t {};
} // unnamed namespace

template <> constexpr inline auto Dialog_variablenwerte_anzeigen::qt_create_metaobjectdata<qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Dialog_variablenwerte_anzeigen",
        "brauche_variablen",
        "",
        "on_pushButton_clicked",
        "slot_bekomme_variablen",
        "text_zeilenweise",
        "variablen"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'brauche_variablen'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'slot_bekomme_variablen'
        QtMocHelpers::SlotData<void(text_zeilenweise)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Dialog_variablenwerte_anzeigen, qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Dialog_variablenwerte_anzeigen::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>.metaTypes,
    nullptr
} };

void Dialog_variablenwerte_anzeigen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Dialog_variablenwerte_anzeigen *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->brauche_variablen(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->slot_bekomme_variablen((*reinterpret_cast<std::add_pointer_t<text_zeilenweise>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Dialog_variablenwerte_anzeigen::*)()>(_a, &Dialog_variablenwerte_anzeigen::brauche_variablen, 0))
            return;
    }
}

const QMetaObject *Dialog_variablenwerte_anzeigen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_variablenwerte_anzeigen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30Dialog_variablenwerte_anzeigenE_t>.strings))
        return static_cast<void*>(this);
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
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Dialog_variablenwerte_anzeigen::brauche_variablen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
