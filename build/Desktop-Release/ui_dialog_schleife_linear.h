/********************************************************************************
** Form generated from reading UI file 'dialog_schleife_linear.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SCHLEIFE_LINEAR_H
#define UI_DIALOG_SCHLEIFE_LINEAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Schleife_linear
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_versatzx_var;
    QLabel *label_versatzy_var;
    QSpinBox *spinBox_anzy;
    QLabel *label_versatzy;
    QLineEdit *lineEdit_versatzy;
    QLabel *label_anzy;
    QLabel *label_anzy_var;
    QLabel *label_anzx_var;
    QSpinBox *spinBox_anzx;
    QLabel *label_anzx;
    QLabel *label_versatzx;
    QLabel *label_bez;
    QLineEdit *lineEdit_versatzx;
    QLabel *label_afb;
    QLabel *label_bez_var;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_bez;
    QLineEdit *lineEdit_afb;

    void setupUi(QDialog *Dialog_Schleife_linear)
    {
        if (Dialog_Schleife_linear->objectName().isEmpty())
            Dialog_Schleife_linear->setObjectName("Dialog_Schleife_linear");
        Dialog_Schleife_linear->resize(542, 425);
        layoutWidget = new QWidget(Dialog_Schleife_linear);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 380, 411, 31));
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

        layoutWidget1 = new QWidget(Dialog_Schleife_linear);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 8, 521, 361));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_versatzx_var = new QLabel(layoutWidget1);
        label_versatzx_var->setObjectName("label_versatzx_var");

        gridLayout->addWidget(label_versatzx_var, 2, 1, 1, 1);

        label_versatzy_var = new QLabel(layoutWidget1);
        label_versatzy_var->setObjectName("label_versatzy_var");

        gridLayout->addWidget(label_versatzy_var, 3, 1, 1, 1);

        spinBox_anzy = new QSpinBox(layoutWidget1);
        spinBox_anzy->setObjectName("spinBox_anzy");
        spinBox_anzy->setValue(1);

        gridLayout->addWidget(spinBox_anzy, 1, 2, 1, 1);

        label_versatzy = new QLabel(layoutWidget1);
        label_versatzy->setObjectName("label_versatzy");

        gridLayout->addWidget(label_versatzy, 3, 0, 1, 1);

        lineEdit_versatzy = new QLineEdit(layoutWidget1);
        lineEdit_versatzy->setObjectName("lineEdit_versatzy");

        gridLayout->addWidget(lineEdit_versatzy, 3, 2, 1, 1);

        label_anzy = new QLabel(layoutWidget1);
        label_anzy->setObjectName("label_anzy");

        gridLayout->addWidget(label_anzy, 1, 0, 1, 1);

        label_anzy_var = new QLabel(layoutWidget1);
        label_anzy_var->setObjectName("label_anzy_var");

        gridLayout->addWidget(label_anzy_var, 1, 1, 1, 1);

        label_anzx_var = new QLabel(layoutWidget1);
        label_anzx_var->setObjectName("label_anzx_var");

        gridLayout->addWidget(label_anzx_var, 0, 1, 1, 1);

        spinBox_anzx = new QSpinBox(layoutWidget1);
        spinBox_anzx->setObjectName("spinBox_anzx");
        spinBox_anzx->setValue(1);

        gridLayout->addWidget(spinBox_anzx, 0, 2, 1, 1);

        label_anzx = new QLabel(layoutWidget1);
        label_anzx->setObjectName("label_anzx");

        gridLayout->addWidget(label_anzx, 0, 0, 1, 1);

        label_versatzx = new QLabel(layoutWidget1);
        label_versatzx->setObjectName("label_versatzx");

        gridLayout->addWidget(label_versatzx, 2, 0, 1, 1);

        label_bez = new QLabel(layoutWidget1);
        label_bez->setObjectName("label_bez");

        gridLayout->addWidget(label_bez, 4, 0, 1, 1);

        lineEdit_versatzx = new QLineEdit(layoutWidget1);
        lineEdit_versatzx->setObjectName("lineEdit_versatzx");

        gridLayout->addWidget(lineEdit_versatzx, 2, 2, 1, 1);

        label_afb = new QLabel(layoutWidget1);
        label_afb->setObjectName("label_afb");

        gridLayout->addWidget(label_afb, 5, 0, 1, 1);

        label_bez_var = new QLabel(layoutWidget1);
        label_bez_var->setObjectName("label_bez_var");

        gridLayout->addWidget(label_bez_var, 4, 1, 1, 1);

        label_afb_var = new QLabel(layoutWidget1);
        label_afb_var->setObjectName("label_afb_var");

        gridLayout->addWidget(label_afb_var, 5, 1, 1, 1);

        lineEdit_bez = new QLineEdit(layoutWidget1);
        lineEdit_bez->setObjectName("lineEdit_bez");

        gridLayout->addWidget(lineEdit_bez, 4, 2, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget1);
        lineEdit_afb->setObjectName("lineEdit_afb");

        gridLayout->addWidget(lineEdit_afb, 5, 2, 1, 1);

        QWidget::setTabOrder(spinBox_anzx, spinBox_anzy);
        QWidget::setTabOrder(spinBox_anzy, lineEdit_versatzx);
        QWidget::setTabOrder(lineEdit_versatzx, lineEdit_versatzy);
        QWidget::setTabOrder(lineEdit_versatzy, lineEdit_bez);
        QWidget::setTabOrder(lineEdit_bez, lineEdit_afb);
        QWidget::setTabOrder(lineEdit_afb, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_Schleife_linear);

        QMetaObject::connectSlotsByName(Dialog_Schleife_linear);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Schleife_linear)
    {
        Dialog_Schleife_linear->setWindowTitle(QCoreApplication::translate("Dialog_Schleife_linear", "Schleife linear", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_Schleife_linear", "OK", nullptr));
        label_versatzx_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[VX]", nullptr));
        label_versatzy_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[VY]", nullptr));
        label_versatzy->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Y-Versatz", nullptr));
        label_anzy->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Anz der Durchl\303\244ufe Y", nullptr));
        label_anzy_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[AY]", nullptr));
        label_anzx_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[AX]", nullptr));
        label_anzx->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Anz der Durchl\303\244ufe X", nullptr));
        label_versatzx->setText(QCoreApplication::translate("Dialog_Schleife_linear", "X-Versatz", nullptr));
        label_bez->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Bezeichnung", nullptr));
        label_afb->setText(QCoreApplication::translate("Dialog_Schleife_linear", "Ausf\303\274hrbedingung", nullptr));
        label_bez_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[BEZ]", nullptr));
        label_afb_var->setText(QCoreApplication::translate("Dialog_Schleife_linear", "[AFB]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Schleife_linear: public Ui_Dialog_Schleife_linear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SCHLEIFE_LINEAR_H
