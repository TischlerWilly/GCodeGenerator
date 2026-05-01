/****************************************************************************
** Meta object code from reading C++ file 'dialog_kreistasche.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialoge/dialog_kreistasche.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_kreistasche.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18Dialog_KreistascheE_t {};
} // unnamed namespace

template <> constexpr inline auto Dialog_Kreistasche::qt_create_metaobjectdata<qt_meta_tag_ZN18Dialog_KreistascheE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Dialog_Kreistasche",
        "sendDialogData",
        "",
        "text",
        "sendDialogDataModifyed",
        "signalSaveConfig",
        "signalBraucheWerkzeugdaten",
        "Werkzeugname",
        "Dialog",
        "getDialogData",
        "openToChangeData",
        "WerkzeugNamen",
        "getWerkzeugdaten",
        "Werkzeugdaten",
        "on_pushButton_Abbrechen_clicked",
        "on_pushButton_Speichern_clicked",
        "on_pushButton_OK_clicked",
        "on_tabWidget_currentChanged",
        "index",
        "on_comboBox_Werkzeug_currentIndexChanged"
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
        // Signal 'signalBraucheWerkzeugdaten'
        QtMocHelpers::SignalData<void(QString, QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
        // Slot 'getDialogData'
        QtMocHelpers::SlotData<void(QString, bool, QStringList)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 10 }, { QMetaType::QStringList, 11 },
        }}),
        // Slot 'getWerkzeugdaten'
        QtMocHelpers::SlotData<void(QString)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'on_pushButton_Abbrechen_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_Speichern_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_OK_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tabWidget_currentChanged'
        QtMocHelpers::SlotData<void(int)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Slot 'on_comboBox_Werkzeug_currentIndexChanged'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Dialog_Kreistasche, qt_meta_tag_ZN18Dialog_KreistascheE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Dialog_Kreistasche::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Dialog_KreistascheE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Dialog_KreistascheE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18Dialog_KreistascheE_t>.metaTypes,
    nullptr
} };

void Dialog_Kreistasche::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Dialog_Kreistasche *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendDialogData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendDialogDataModifyed((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->signalSaveConfig((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->signalBraucheWerkzeugdaten((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->getDialogData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 5: _t->getWerkzeugdaten((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_pushButton_Abbrechen_clicked(); break;
        case 7: _t->on_pushButton_Speichern_clicked(); break;
        case 8: _t->on_pushButton_OK_clicked(); break;
        case 9: _t->on_tabWidget_currentChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_comboBox_Werkzeug_currentIndexChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Dialog_Kreistasche::*)(QString )>(_a, &Dialog_Kreistasche::sendDialogData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Dialog_Kreistasche::*)(QString )>(_a, &Dialog_Kreistasche::sendDialogDataModifyed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Dialog_Kreistasche::*)(QString )>(_a, &Dialog_Kreistasche::signalSaveConfig, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Dialog_Kreistasche::*)(QString , QString )>(_a, &Dialog_Kreistasche::signalBraucheWerkzeugdaten, 3))
            return;
    }
}

const QMetaObject *Dialog_Kreistasche::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_Kreistasche::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Dialog_KreistascheE_t>.strings))
        return static_cast<void*>(this);
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
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Dialog_Kreistasche::sendDialogData(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Dialog_Kreistasche::sendDialogDataModifyed(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Dialog_Kreistasche::signalSaveConfig(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Dialog_Kreistasche::signalBraucheWerkzeugdaten(QString _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
