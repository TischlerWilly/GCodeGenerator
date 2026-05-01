/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_abfahren.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_ABFAHREN_H
#define UI_DIALOG_FRAESER_ABFAHREN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_fraeser_abfahren
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label_afb;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_afb;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_fraeser_abfahren)
    {
        if (Dialog_fraeser_abfahren->objectName().isEmpty())
            Dialog_fraeser_abfahren->setObjectName("Dialog_fraeser_abfahren");
        Dialog_fraeser_abfahren->resize(400, 119);
        Dialog_fraeser_abfahren->setModal(true);
        layoutWidget = new QWidget(Dialog_fraeser_abfahren);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 381, 61));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_bezeichnung = new QLabel(layoutWidget);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout->addWidget(label_bezeichnung, 0, 0, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget);
        label_bezeichnung_var->setObjectName("label_bezeichnung_var");

        gridLayout->addWidget(label_bezeichnung_var, 0, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_bezeichnung->setObjectName("lineEdit_bezeichnung");

        gridLayout->addWidget(lineEdit_bezeichnung, 0, 2, 1, 1);

        label_afb = new QLabel(layoutWidget);
        label_afb->setObjectName("label_afb");

        gridLayout->addWidget(label_afb, 1, 0, 1, 1);

        label_afb_var = new QLabel(layoutWidget);
        label_afb_var->setObjectName("label_afb_var");

        gridLayout->addWidget(label_afb_var, 1, 1, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget);
        lineEdit_afb->setObjectName("lineEdit_afb");

        gridLayout->addWidget(lineEdit_afb, 1, 2, 1, 1);

        layoutWidget1 = new QWidget(Dialog_fraeser_abfahren);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 80, 381, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget1);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget1);
        pushButton_speichern->setObjectName("pushButton_speichern");

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget1);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);


        retranslateUi(Dialog_fraeser_abfahren);

        QMetaObject::connectSlotsByName(Dialog_fraeser_abfahren);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_abfahren)
    {
        Dialog_fraeser_abfahren->setWindowTitle(QCoreApplication::translate("Dialog_fraeser_abfahren", "Abfahren", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "Bezeichnung", nullptr));
        label_bezeichnung_var->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "[BEZ]", nullptr));
        label_afb->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "Ausf\303\274hrbedingung", nullptr));
        label_afb_var->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "[AFB]", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_fraeser_abfahren", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_abfahren: public Ui_Dialog_fraeser_abfahren {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_ABFAHREN_H
