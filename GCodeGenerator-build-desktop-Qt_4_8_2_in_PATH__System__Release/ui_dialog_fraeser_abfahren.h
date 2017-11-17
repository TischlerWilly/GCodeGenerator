/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_abfahren.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_ABFAHREN_H
#define UI_DIALOG_FRAESER_ABFAHREN_H

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

class Ui_Dialog_fraeser_abfahren
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label_afb;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_afb;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_fraeser_abfahren)
    {
        if (Dialog_fraeser_abfahren->objectName().isEmpty())
            Dialog_fraeser_abfahren->setObjectName(QString::fromUtf8("Dialog_fraeser_abfahren"));
        Dialog_fraeser_abfahren->resize(400, 119);
        widget = new QWidget(Dialog_fraeser_abfahren);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 381, 61));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_bezeichnung = new QLabel(widget);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout->addWidget(label_bezeichnung, 0, 0, 1, 1);

        label_bezeichnung_var = new QLabel(widget);
        label_bezeichnung_var->setObjectName(QString::fromUtf8("label_bezeichnung_var"));

        gridLayout->addWidget(label_bezeichnung_var, 0, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(widget);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout->addWidget(lineEdit_bezeichnung, 0, 2, 1, 1);

        label_afb = new QLabel(widget);
        label_afb->setObjectName(QString::fromUtf8("label_afb"));

        gridLayout->addWidget(label_afb, 1, 0, 1, 1);

        label_afb_var = new QLabel(widget);
        label_afb_var->setObjectName(QString::fromUtf8("label_afb_var"));

        gridLayout->addWidget(label_afb_var, 1, 1, 1, 1);

        lineEdit_afb = new QLineEdit(widget);
        lineEdit_afb->setObjectName(QString::fromUtf8("lineEdit_afb"));

        gridLayout->addWidget(lineEdit_afb, 1, 2, 1, 1);

        widget1 = new QWidget(Dialog_fraeser_abfahren);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 80, 381, 29));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(widget1);
        pushButton_abbrechen->setObjectName(QString::fromUtf8("pushButton_abbrechen"));

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(widget1);
        pushButton_speichern->setObjectName(QString::fromUtf8("pushButton_speichern"));

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(widget1);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout->addWidget(pushButton_ok);


        retranslateUi(Dialog_fraeser_abfahren);

        QMetaObject::connectSlotsByName(Dialog_fraeser_abfahren);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_abfahren)
    {
        Dialog_fraeser_abfahren->setWindowTitle(QApplication::translate("Dialog_fraeser_abfahren", "Abfahren", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_fraeser_abfahren", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        label_bezeichnung_var->setText(QApplication::translate("Dialog_fraeser_abfahren", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_afb->setText(QApplication::translate("Dialog_fraeser_abfahren", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_afb_var->setText(QApplication::translate("Dialog_fraeser_abfahren", "[AFB]", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_fraeser_abfahren", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_speichern->setText(QApplication::translate("Dialog_fraeser_abfahren", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("Dialog_fraeser_abfahren", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_abfahren: public Ui_Dialog_fraeser_abfahren {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_ABFAHREN_H
