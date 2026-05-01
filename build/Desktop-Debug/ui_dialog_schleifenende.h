/********************************************************************************
** Form generated from reading UI file 'dialog_schleifenende.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SCHLEIFENENDE_H
#define UI_DIALOG_SCHLEIFENENDE_H

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

class Ui_Dialog_Schleifenende
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_bez;
    QLabel *label_bez_var;
    QLineEdit *lineEdit_bez;
    QLabel *label_afb;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_afb;

    void setupUi(QDialog *Dialog_Schleifenende)
    {
        if (Dialog_Schleifenende->objectName().isEmpty())
            Dialog_Schleifenende->setObjectName("Dialog_Schleifenende");
        Dialog_Schleifenende->resize(432, 163);
        layoutWidget = new QWidget(Dialog_Schleifenende);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 120, 411, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget);
        pushButton_speichern->setObjectName("pushButton_speichern");

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        layoutWidget1 = new QWidget(Dialog_Schleifenende);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(13, 10, 411, 101));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_bez = new QLabel(layoutWidget1);
        label_bez->setObjectName("label_bez");

        gridLayout->addWidget(label_bez, 0, 0, 1, 1);

        label_bez_var = new QLabel(layoutWidget1);
        label_bez_var->setObjectName("label_bez_var");

        gridLayout->addWidget(label_bez_var, 0, 1, 1, 1);

        lineEdit_bez = new QLineEdit(layoutWidget1);
        lineEdit_bez->setObjectName("lineEdit_bez");

        gridLayout->addWidget(lineEdit_bez, 0, 2, 1, 1);

        label_afb = new QLabel(layoutWidget1);
        label_afb->setObjectName("label_afb");

        gridLayout->addWidget(label_afb, 1, 0, 1, 1);

        label_afb_var = new QLabel(layoutWidget1);
        label_afb_var->setObjectName("label_afb_var");

        gridLayout->addWidget(label_afb_var, 1, 1, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget1);
        lineEdit_afb->setObjectName("lineEdit_afb");

        gridLayout->addWidget(lineEdit_afb, 1, 2, 1, 1);

        QWidget::setTabOrder(lineEdit_bez, lineEdit_afb);
        QWidget::setTabOrder(lineEdit_afb, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_Schleifenende);

        QMetaObject::connectSlotsByName(Dialog_Schleifenende);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Schleifenende)
    {
        Dialog_Schleifenende->setWindowTitle(QCoreApplication::translate("Dialog_Schleifenende", "Schleifenende", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_Schleifenende", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_Schleifenende", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_Schleifenende", "OK", nullptr));
        label_bez->setText(QCoreApplication::translate("Dialog_Schleifenende", "Bezeichnung", nullptr));
        label_bez_var->setText(QCoreApplication::translate("Dialog_Schleifenende", "[BEZ]", nullptr));
        label_afb->setText(QCoreApplication::translate("Dialog_Schleifenende", "Ausf\303\274hrbedingung", nullptr));
        label_afb_var->setText(QCoreApplication::translate("Dialog_Schleifenende", "[AFB]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Schleifenende: public Ui_Dialog_Schleifenende {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SCHLEIFENENDE_H
