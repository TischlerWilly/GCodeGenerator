/********************************************************************************
** Form generated from reading UI file 'dialog_variable.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VARIABLE_H
#define UI_DIALOG_VARIABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Variable
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_Bezeichnung;
    QLabel *label_Bezeichnung_var;
    QLineEdit *lineEdit_Bezeichnung;
    QLabel *label_Wert;
    QLabel *label_Wert_var;
    QLineEdit *lineEdit_Wert;
    QLabel *label_Ausfuehrbedingung;
    QLabel *label_Ausfuehrbedingung_var;
    QLineEdit *lineEdit_Ausfuehrbedingung;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_Speichern;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Variable)
    {
        if (Dialog_Variable->objectName().isEmpty())
            Dialog_Variable->setObjectName(QString::fromUtf8("Dialog_Variable"));
        Dialog_Variable->resize(442, 134);
        layoutWidget = new QWidget(Dialog_Variable);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 10, 421, 83));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Bezeichnung = new QLabel(layoutWidget);
        label_Bezeichnung->setObjectName(QString::fromUtf8("label_Bezeichnung"));

        gridLayout->addWidget(label_Bezeichnung, 0, 0, 1, 1);

        label_Bezeichnung_var = new QLabel(layoutWidget);
        label_Bezeichnung_var->setObjectName(QString::fromUtf8("label_Bezeichnung_var"));
        label_Bezeichnung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Bezeichnung_var, 0, 1, 1, 1);

        lineEdit_Bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_Bezeichnung->setObjectName(QString::fromUtf8("lineEdit_Bezeichnung"));

        gridLayout->addWidget(lineEdit_Bezeichnung, 0, 2, 1, 1);

        label_Wert = new QLabel(layoutWidget);
        label_Wert->setObjectName(QString::fromUtf8("label_Wert"));

        gridLayout->addWidget(label_Wert, 1, 0, 1, 1);

        label_Wert_var = new QLabel(layoutWidget);
        label_Wert_var->setObjectName(QString::fromUtf8("label_Wert_var"));
        label_Wert_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Wert_var, 1, 1, 1, 1);

        lineEdit_Wert = new QLineEdit(layoutWidget);
        lineEdit_Wert->setObjectName(QString::fromUtf8("lineEdit_Wert"));

        gridLayout->addWidget(lineEdit_Wert, 1, 2, 1, 1);

        label_Ausfuehrbedingung = new QLabel(layoutWidget);
        label_Ausfuehrbedingung->setObjectName(QString::fromUtf8("label_Ausfuehrbedingung"));

        gridLayout->addWidget(label_Ausfuehrbedingung, 2, 0, 1, 1);

        label_Ausfuehrbedingung_var = new QLabel(layoutWidget);
        label_Ausfuehrbedingung_var->setObjectName(QString::fromUtf8("label_Ausfuehrbedingung_var"));
        label_Ausfuehrbedingung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Ausfuehrbedingung_var, 2, 1, 1, 1);

        lineEdit_Ausfuehrbedingung = new QLineEdit(layoutWidget);
        lineEdit_Ausfuehrbedingung->setObjectName(QString::fromUtf8("lineEdit_Ausfuehrbedingung"));

        gridLayout->addWidget(lineEdit_Ausfuehrbedingung, 2, 2, 1, 1);

        layoutWidget1 = new QWidget(Dialog_Variable);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 100, 331, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget1);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget1);
        pushButton_Speichern->setObjectName(QString::fromUtf8("pushButton_Speichern"));

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget1);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);


        retranslateUi(Dialog_Variable);

        QMetaObject::connectSlotsByName(Dialog_Variable);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Variable)
    {
        Dialog_Variable->setWindowTitle(QApplication::translate("Dialog_Variable", "Variable", 0, QApplication::UnicodeUTF8));
        label_Bezeichnung->setText(QApplication::translate("Dialog_Variable", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        label_Bezeichnung_var->setText(QApplication::translate("Dialog_Variable", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_Wert->setText(QApplication::translate("Dialog_Variable", "Wert", 0, QApplication::UnicodeUTF8));
        label_Wert_var->setText(QApplication::translate("Dialog_Variable", "*[WERT]", 0, QApplication::UnicodeUTF8));
        label_Ausfuehrbedingung->setText(QApplication::translate("Dialog_Variable", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_Ausfuehrbedingung_var->setText(QApplication::translate("Dialog_Variable", "[AFB]", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Variable", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_Speichern->setText(QApplication::translate("Dialog_Variable", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Variable", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Variable: public Ui_Dialog_Variable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VARIABLE_H
