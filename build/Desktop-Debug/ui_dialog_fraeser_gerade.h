/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_gerade.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_GERADE_H
#define UI_DIALOG_FRAESER_GERADE_H

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

class Ui_Dialog_fraeser_gerade
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_ende_y_var;
    QLineEdit *lineEdit_radius;
    QLineEdit *lineEdit_afb;
    QLabel *label_ende_z_var;
    QLabel *label_ende_x_var;
    QLabel *label_radius_var;
    QLabel *label_ende_y;
    QLineEdit *lineEdit_ende_x;
    QLabel *label_afb;
    QLabel *label_ende_z;
    QLabel *label_ende_x;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_ende_z;
    QLabel *label_radius;
    QLineEdit *lineEdit_ende_y;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_fraeser_gerade)
    {
        if (Dialog_fraeser_gerade->objectName().isEmpty())
            Dialog_fraeser_gerade->setObjectName("Dialog_fraeser_gerade");
        Dialog_fraeser_gerade->resize(400, 326);
        Dialog_fraeser_gerade->setModal(true);
        layoutWidget = new QWidget(Dialog_fraeser_gerade);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_ende_y_var = new QLabel(layoutWidget);
        label_ende_y_var->setObjectName("label_ende_y_var");

        gridLayout->addWidget(label_ende_y_var, 1, 1, 1, 1);

        lineEdit_radius = new QLineEdit(layoutWidget);
        lineEdit_radius->setObjectName("lineEdit_radius");

        gridLayout->addWidget(lineEdit_radius, 3, 2, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget);
        lineEdit_afb->setObjectName("lineEdit_afb");

        gridLayout->addWidget(lineEdit_afb, 5, 2, 1, 1);

        label_ende_z_var = new QLabel(layoutWidget);
        label_ende_z_var->setObjectName("label_ende_z_var");

        gridLayout->addWidget(label_ende_z_var, 2, 1, 1, 1);

        label_ende_x_var = new QLabel(layoutWidget);
        label_ende_x_var->setObjectName("label_ende_x_var");

        gridLayout->addWidget(label_ende_x_var, 0, 1, 1, 1);

        label_radius_var = new QLabel(layoutWidget);
        label_radius_var->setObjectName("label_radius_var");

        gridLayout->addWidget(label_radius_var, 3, 1, 1, 1);

        label_ende_y = new QLabel(layoutWidget);
        label_ende_y->setObjectName("label_ende_y");

        gridLayout->addWidget(label_ende_y, 1, 0, 1, 1);

        lineEdit_ende_x = new QLineEdit(layoutWidget);
        lineEdit_ende_x->setObjectName("lineEdit_ende_x");

        gridLayout->addWidget(lineEdit_ende_x, 0, 2, 1, 1);

        label_afb = new QLabel(layoutWidget);
        label_afb->setObjectName("label_afb");

        gridLayout->addWidget(label_afb, 5, 0, 1, 1);

        label_ende_z = new QLabel(layoutWidget);
        label_ende_z->setObjectName("label_ende_z");

        gridLayout->addWidget(label_ende_z, 2, 0, 1, 1);

        label_ende_x = new QLabel(layoutWidget);
        label_ende_x->setObjectName("label_ende_x");

        gridLayout->addWidget(label_ende_x, 0, 0, 1, 1);

        label_afb_var = new QLabel(layoutWidget);
        label_afb_var->setObjectName("label_afb_var");

        gridLayout->addWidget(label_afb_var, 5, 1, 1, 1);

        lineEdit_ende_z = new QLineEdit(layoutWidget);
        lineEdit_ende_z->setObjectName("lineEdit_ende_z");

        gridLayout->addWidget(lineEdit_ende_z, 2, 2, 1, 1);

        label_radius = new QLabel(layoutWidget);
        label_radius->setObjectName("label_radius");

        gridLayout->addWidget(label_radius, 3, 0, 1, 1);

        lineEdit_ende_y = new QLineEdit(layoutWidget);
        lineEdit_ende_y->setObjectName("lineEdit_ende_y");

        gridLayout->addWidget(lineEdit_ende_y, 1, 2, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout->addWidget(label_bezeichnung, 4, 0, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget);
        label_bezeichnung_var->setObjectName("label_bezeichnung_var");

        gridLayout->addWidget(label_bezeichnung_var, 4, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_bezeichnung->setObjectName("lineEdit_bezeichnung");

        gridLayout->addWidget(lineEdit_bezeichnung, 4, 2, 1, 1);

        layoutWidget1 = new QWidget(Dialog_fraeser_gerade);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 290, 381, 29));
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

        QWidget::setTabOrder(lineEdit_ende_x, lineEdit_ende_y);
        QWidget::setTabOrder(lineEdit_ende_y, lineEdit_ende_z);
        QWidget::setTabOrder(lineEdit_ende_z, lineEdit_radius);
        QWidget::setTabOrder(lineEdit_radius, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_afb);
        QWidget::setTabOrder(lineEdit_afb, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_fraeser_gerade);

        QMetaObject::connectSlotsByName(Dialog_fraeser_gerade);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_gerade)
    {
        Dialog_fraeser_gerade->setWindowTitle(QCoreApplication::translate("Dialog_fraeser_gerade", "Gerade Fraesbahn", nullptr));
        label_ende_y_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "*[Y]", nullptr));
        label_ende_z_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "*[Z]", nullptr));
        label_ende_x_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "*[X]", nullptr));
        label_radius_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "[RAD]", nullptr));
        label_ende_y->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Endpunkt Y:", nullptr));
        label_afb->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Ausf\303\274hrbedingung:", nullptr));
        label_ende_z->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Endpunkt Z:", nullptr));
        label_ende_x->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Endpunkt X:", nullptr));
        label_afb_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "[AFB]", nullptr));
        label_radius->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Radius zum Nachfolger:", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Bezeichnung:", nullptr));
        label_bezeichnung_var->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "[BEZ]", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_fraeser_gerade", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_gerade: public Ui_Dialog_fraeser_gerade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_GERADE_H
