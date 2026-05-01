/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_bogen.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_BOGEN_H
#define UI_DIALOG_FRAESER_BOGEN_H

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

class Ui_Dialog_fraeser_bogen
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_radius;
    QLabel *label_ende_x;
    QLabel *label_ende_x_var;
    QLineEdit *lineEdit_ende_x;
    QLabel *label_ende_y;
    QLabel *label_ende_y_var;
    QLineEdit *lineEdit_ende_y;
    QLabel *label_ende_z;
    QLabel *label_ende_z_var;
    QLineEdit *lineEdit_ende_z;
    QLabel *label_radius_var;
    QLabel *label_radius;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label_ausfbed;
    QLabel *label_ausfbed_var;
    QLineEdit *lineEdit_ausfbed;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_im_UZS;
    QRadioButton *radioButton_gegen_UZS;

    void setupUi(QDialog *Dialog_fraeser_bogen)
    {
        if (Dialog_fraeser_bogen->objectName().isEmpty())
            Dialog_fraeser_bogen->setObjectName("Dialog_fraeser_bogen");
        Dialog_fraeser_bogen->resize(453, 399);
        Dialog_fraeser_bogen->setModal(true);
        layoutWidget = new QWidget(Dialog_fraeser_bogen);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 431, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_radius = new QLineEdit(layoutWidget);
        lineEdit_radius->setObjectName("lineEdit_radius");

        gridLayout->addWidget(lineEdit_radius, 3, 2, 1, 1);

        label_ende_x = new QLabel(layoutWidget);
        label_ende_x->setObjectName("label_ende_x");

        gridLayout->addWidget(label_ende_x, 0, 0, 1, 1);

        label_ende_x_var = new QLabel(layoutWidget);
        label_ende_x_var->setObjectName("label_ende_x_var");

        gridLayout->addWidget(label_ende_x_var, 0, 1, 1, 1);

        lineEdit_ende_x = new QLineEdit(layoutWidget);
        lineEdit_ende_x->setObjectName("lineEdit_ende_x");

        gridLayout->addWidget(lineEdit_ende_x, 0, 2, 1, 1);

        label_ende_y = new QLabel(layoutWidget);
        label_ende_y->setObjectName("label_ende_y");

        gridLayout->addWidget(label_ende_y, 1, 0, 1, 1);

        label_ende_y_var = new QLabel(layoutWidget);
        label_ende_y_var->setObjectName("label_ende_y_var");

        gridLayout->addWidget(label_ende_y_var, 1, 1, 1, 1);

        lineEdit_ende_y = new QLineEdit(layoutWidget);
        lineEdit_ende_y->setObjectName("lineEdit_ende_y");

        gridLayout->addWidget(lineEdit_ende_y, 1, 2, 1, 1);

        label_ende_z = new QLabel(layoutWidget);
        label_ende_z->setObjectName("label_ende_z");

        gridLayout->addWidget(label_ende_z, 2, 0, 1, 1);

        label_ende_z_var = new QLabel(layoutWidget);
        label_ende_z_var->setObjectName("label_ende_z_var");

        gridLayout->addWidget(label_ende_z_var, 2, 1, 1, 1);

        lineEdit_ende_z = new QLineEdit(layoutWidget);
        lineEdit_ende_z->setObjectName("lineEdit_ende_z");

        gridLayout->addWidget(lineEdit_ende_z, 2, 2, 1, 1);

        label_radius_var = new QLabel(layoutWidget);
        label_radius_var->setObjectName("label_radius_var");

        gridLayout->addWidget(label_radius_var, 3, 1, 1, 1);

        label_radius = new QLabel(layoutWidget);
        label_radius->setObjectName("label_radius");

        gridLayout->addWidget(label_radius, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 290, 431, 61));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_bezeichnung = new QLabel(layoutWidget1);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout_3->addWidget(label_bezeichnung, 0, 0, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget1);
        label_bezeichnung_var->setObjectName("label_bezeichnung_var");

        gridLayout_3->addWidget(label_bezeichnung_var, 0, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget1);
        lineEdit_bezeichnung->setObjectName("lineEdit_bezeichnung");

        gridLayout_3->addWidget(lineEdit_bezeichnung, 0, 2, 1, 1);

        label_ausfbed = new QLabel(layoutWidget1);
        label_ausfbed->setObjectName("label_ausfbed");

        gridLayout_3->addWidget(label_ausfbed, 1, 0, 1, 1);

        label_ausfbed_var = new QLabel(layoutWidget1);
        label_ausfbed_var->setObjectName("label_ausfbed_var");

        gridLayout_3->addWidget(label_ausfbed_var, 1, 1, 1, 1);

        lineEdit_ausfbed = new QLineEdit(layoutWidget1);
        lineEdit_ausfbed->setObjectName("lineEdit_ausfbed");

        gridLayout_3->addWidget(lineEdit_ausfbed, 1, 2, 1, 1);

        layoutWidget2 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 360, 431, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget2);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget2);
        pushButton_speichern->setObjectName("pushButton_speichern");

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget2);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        layoutWidget3 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(9, 221, 431, 61));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_im_UZS = new QRadioButton(layoutWidget3);
        radioButton_im_UZS->setObjectName("radioButton_im_UZS");

        verticalLayout->addWidget(radioButton_im_UZS);

        radioButton_gegen_UZS = new QRadioButton(layoutWidget3);
        radioButton_gegen_UZS->setObjectName("radioButton_gegen_UZS");

        verticalLayout->addWidget(radioButton_gegen_UZS);

        QWidget::setTabOrder(lineEdit_ende_x, lineEdit_ende_y);
        QWidget::setTabOrder(lineEdit_ende_y, lineEdit_ende_z);
        QWidget::setTabOrder(lineEdit_ende_z, lineEdit_radius);
        QWidget::setTabOrder(lineEdit_radius, radioButton_im_UZS);
        QWidget::setTabOrder(radioButton_im_UZS, radioButton_gegen_UZS);
        QWidget::setTabOrder(radioButton_gegen_UZS, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_ausfbed);
        QWidget::setTabOrder(lineEdit_ausfbed, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_fraeser_bogen);

        QMetaObject::connectSlotsByName(Dialog_fraeser_bogen);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_bogen)
    {
        Dialog_fraeser_bogen->setWindowTitle(QCoreApplication::translate("Dialog_fraeser_bogen", "gebogene Fr\303\244sbahn", nullptr));
        label_ende_x->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Endpunkt in X", nullptr));
        label_ende_x_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "*[X]", nullptr));
        label_ende_y->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Endpunkt in Y", nullptr));
        label_ende_y_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "*[Y]", nullptr));
        label_ende_z->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Endpunkt in Z", nullptr));
        label_ende_z_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "*[Z]", nullptr));
        label_radius_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "[RAD]", nullptr));
        label_radius->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Radius", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Bezeichnung", nullptr));
        label_bezeichnung_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "[BEZ]", nullptr));
        label_ausfbed->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Ausf\303\274hrbedinging", nullptr));
        label_ausfbed_var->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "[AFB]", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "OK", nullptr));
        radioButton_im_UZS->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "in Uhrzeigersinn (G02)", nullptr));
        radioButton_gegen_UZS->setText(QCoreApplication::translate("Dialog_fraeser_bogen", "gegen den Uhrzeigersinn (G03)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_bogen: public Ui_Dialog_fraeser_bogen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_BOGEN_H
