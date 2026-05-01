/********************************************************************************
** Form generated from reading UI file 'dialog_programmende.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMMENDE_H
#define UI_DIALOG_PROGRAMMENDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Programmende
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_amNullpunkt;
    QRadioButton *radioButton_benutzerdefiniert;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ausfuehrbedingung;
    QLineEdit *lineEdit_pos_z;
    QLabel *label_pos_y;
    QLineEdit *lineEdit_pos_x;
    QLineEdit *lineEdit_pos_y;
    QLabel *label_Ausfuerbedingung;
    QLabel *label_pos_z;
    QLabel *label_pos_x;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label__bezeichnung_var;
    QLabel *label_bezeichnung;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Programmende)
    {
        if (Dialog_Programmende->objectName().isEmpty())
            Dialog_Programmende->setObjectName("Dialog_Programmende");
        Dialog_Programmende->resize(440, 272);
        Dialog_Programmende->setModal(true);
        layoutWidget = new QWidget(Dialog_Programmende);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 419, 251));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        radioButton_amNullpunkt = new QRadioButton(layoutWidget);
        radioButton_amNullpunkt->setObjectName("radioButton_amNullpunkt");

        verticalLayout->addWidget(radioButton_amNullpunkt);

        radioButton_benutzerdefiniert = new QRadioButton(layoutWidget);
        radioButton_benutzerdefiniert->setObjectName("radioButton_benutzerdefiniert");

        verticalLayout->addWidget(radioButton_benutzerdefiniert);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEdit_ausfuehrbedingung = new QLineEdit(layoutWidget);
        lineEdit_ausfuehrbedingung->setObjectName("lineEdit_ausfuehrbedingung");

        gridLayout->addWidget(lineEdit_ausfuehrbedingung, 4, 2, 1, 1);

        lineEdit_pos_z = new QLineEdit(layoutWidget);
        lineEdit_pos_z->setObjectName("lineEdit_pos_z");

        gridLayout->addWidget(lineEdit_pos_z, 2, 2, 1, 1);

        label_pos_y = new QLabel(layoutWidget);
        label_pos_y->setObjectName("label_pos_y");

        gridLayout->addWidget(label_pos_y, 1, 0, 1, 1);

        lineEdit_pos_x = new QLineEdit(layoutWidget);
        lineEdit_pos_x->setObjectName("lineEdit_pos_x");

        gridLayout->addWidget(lineEdit_pos_x, 0, 2, 1, 1);

        lineEdit_pos_y = new QLineEdit(layoutWidget);
        lineEdit_pos_y->setObjectName("lineEdit_pos_y");

        gridLayout->addWidget(lineEdit_pos_y, 1, 2, 1, 1);

        label_Ausfuerbedingung = new QLabel(layoutWidget);
        label_Ausfuerbedingung->setObjectName("label_Ausfuerbedingung");

        gridLayout->addWidget(label_Ausfuerbedingung, 4, 0, 1, 1);

        label_pos_z = new QLabel(layoutWidget);
        label_pos_z->setObjectName("label_pos_z");

        gridLayout->addWidget(label_pos_z, 2, 0, 1, 1);

        label_pos_x = new QLabel(layoutWidget);
        label_pos_x->setObjectName("label_pos_x");

        gridLayout->addWidget(label_pos_x, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_bezeichnung->setObjectName("lineEdit_bezeichnung");

        gridLayout->addWidget(lineEdit_bezeichnung, 3, 2, 1, 1);

        label__bezeichnung_var = new QLabel(layoutWidget);
        label__bezeichnung_var->setObjectName("label__bezeichnung_var");

        gridLayout->addWidget(label__bezeichnung_var, 3, 1, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout->addWidget(label_bezeichnung, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout->addWidget(pushButton_OK);


        verticalLayout_3->addLayout(horizontalLayout);

        QWidget::setTabOrder(radioButton_amNullpunkt, radioButton_benutzerdefiniert);
        QWidget::setTabOrder(radioButton_benutzerdefiniert, lineEdit_pos_x);
        QWidget::setTabOrder(lineEdit_pos_x, lineEdit_pos_y);
        QWidget::setTabOrder(lineEdit_pos_y, lineEdit_pos_z);
        QWidget::setTabOrder(lineEdit_pos_z, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_ausfuehrbedingung);
        QWidget::setTabOrder(lineEdit_ausfuehrbedingung, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Programmende);

        QMetaObject::connectSlotsByName(Dialog_Programmende);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programmende)
    {
        Dialog_Programmende->setWindowTitle(QCoreApplication::translate("Dialog_Programmende", "Programmende", nullptr));
        radioButton_amNullpunkt->setText(QCoreApplication::translate("Dialog_Programmende", "am Nullpunkt", nullptr));
        radioButton_benutzerdefiniert->setText(QCoreApplication::translate("Dialog_Programmende", "an Benutzerdefinierter Position", nullptr));
        label_pos_y->setText(QCoreApplication::translate("Dialog_Programmende", "Position in Y:", nullptr));
        label_Ausfuerbedingung->setText(QCoreApplication::translate("Dialog_Programmende", "Ausf\303\274hrbedingung", nullptr));
        label_pos_z->setText(QCoreApplication::translate("Dialog_Programmende", "Position in Z:", nullptr));
        label_pos_x->setText(QCoreApplication::translate("Dialog_Programmende", "Position in X:", nullptr));
        label->setText(QCoreApplication::translate("Dialog_Programmende", "[Y]", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_Programmende", "[X]", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_Programmende", "[Z]", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog_Programmende", "[AFB]", nullptr));
        label__bezeichnung_var->setText(QCoreApplication::translate("Dialog_Programmende", "[BEZ]", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_Programmende", "Bezeichnung:", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_Programmende", "Abbrechen", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_Programmende", "Speichern", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Programmende", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programmende: public Ui_Dialog_Programmende {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMMENDE_H
