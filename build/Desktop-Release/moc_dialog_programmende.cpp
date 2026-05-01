/****************************************************************************
** Meta object code from reading C++ file 'dialog_programmende.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialoge/dialog_programmende.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_programmende.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19Dialog_ProgrammendeE_t {};
} // unnamed namespace

template <> constexpr inline auto Dialog_Programmende::qt_create_metaobjectdata<qt_meta_tag_ZN19Dialog_ProgrammendeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Dialog_Programmende",
        "sendDialogData",
        "",
        "text",
        "sendDialogDataModifyed",
        "signalSaveConfig",
        "getDialogData",
        "openToChangeData",
        "on_pushButton_OK_clicked",
        "on_pushButton_save_clicked",
        "on_pushButton_abbrechen_clicked",
        "on_radioButton_amNullpunkt_clicked",
        "on_radioButton_benutzerdefiniert_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendDialogData'
        QtMocHelpers::SignalData<void(QString)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'sendDialogDataModifyed'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'signalSaveConfig'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'getDialogData'
        QtMocHelpers::SlotData<void(QString, bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 7 },
        }}),
        // Slot 'on_pushButton_OK_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_save_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_abbrechen_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_amNullpunkt_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButton_benutzerdefiniert_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Dialog_Programmende, qt_meta_tag_ZN19Dialog_ProgrammendeE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Dialog_Programmende::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19Dialog_ProgrammendeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19Dialog_ProgrammendeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19Dialog_ProgrammendeE_t>.metaTypes,
    nullptr
} };

void Dialog_Programmende::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Dialog_Programmende *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendDialogData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendDialogDataModifyed((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->signalSaveConfig((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->getDialogData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->on_pushButton_OK_clicked(); break;
        case 5: _t->on_pushButton_save_clicked(); break;
        case 6: _t->on_pushButton_abbrechen_clicked(); break;
        case 7: _t->on_radioButton_amNullpunkt_clicked(); break;
        case 8: _t->on_radioButton_benutzerdefiniert_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Dialog_Programmende::*)(QString )>(_a, &Dialog_Programmende::sendDialogData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Dialog_Programmende::*)(QString )>(_a, &Dialog_Programmende::sendDialogDataModifyed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Dialog_Programmende::*)(QString )>(_a, &Dialog_Programmende::signalSaveConfig, 2))
            return;
    }
}

const QMetaObject *Dialog_Programmende::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_Programmende::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19Dialog_ProgrammendeE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_Programmende::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Dialog_Programmende::sendDialogData(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Dialog_Programmende::sendDialogDataModifyed(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Dialog_Programmende::signalSaveConfig(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
