/********************************************************************************
** Form generated from reading UI file 'dialog_bogen.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_BOGEN_H
#define UI_DIALOG_BOGEN_H

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

class Ui_Dialog_Bogen
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_spz;
    QLineEdit *lineEdit_epx;
    QLineEdit *lineEdit_spy;
    QLabel *label_spx;
    QLineEdit *lineEdit_spx;
    QLabel *label_spz;
    QLineEdit *lineEdit_epz;
    QLineEdit *lineEdit_epy;
    QLineEdit *lineEdit_rad;
    QLabel *label_spy;
    QLabel *label_epx;
    QLabel *label_epy;
    QLabel *label_epz;
    QLabel *label_rad;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_uzs;
    QRadioButton *radioButton_guzs;

    void setupUi(QDialog *Dialog_Bogen)
    {
        if (Dialog_Bogen->objectName().isEmpty())
            Dialog_Bogen->setObjectName("Dialog_Bogen");
        Dialog_Bogen->setWindowModality(Qt::NonModal);
        Dialog_Bogen->resize(341, 516);
        Dialog_Bogen->setModal(true);
        layoutWidget = new QWidget(Dialog_Bogen);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 480, 321, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_ok = new QPushButton(layoutWidget);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        layoutWidget1 = new QWidget(Dialog_Bogen);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 321, 391));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_spz = new QLineEdit(layoutWidget1);
        lineEdit_spz->setObjectName("lineEdit_spz");

        gridLayout->addWidget(lineEdit_spz, 2, 1, 1, 1);

        lineEdit_epx = new QLineEdit(layoutWidget1);
        lineEdit_epx->setObjectName("lineEdit_epx");

        gridLayout->addWidget(lineEdit_epx, 3, 1, 1, 1);

        lineEdit_spy = new QLineEdit(layoutWidget1);
        lineEdit_spy->setObjectName("lineEdit_spy");

        gridLayout->addWidget(lineEdit_spy, 1, 1, 1, 1);

        label_spx = new QLabel(layoutWidget1);
        label_spx->setObjectName("label_spx");

        gridLayout->addWidget(label_spx, 0, 0, 1, 1);

        lineEdit_spx = new QLineEdit(layoutWidget1);
        lineEdit_spx->setObjectName("lineEdit_spx");

        gridLayout->addWidget(lineEdit_spx, 0, 1, 1, 1);

        label_spz = new QLabel(layoutWidget1);
        label_spz->setObjectName("label_spz");

        gridLayout->addWidget(label_spz, 2, 0, 1, 1);

        lineEdit_epz = new QLineEdit(layoutWidget1);
        lineEdit_epz->setObjectName("lineEdit_epz");

        gridLayout->addWidget(lineEdit_epz, 5, 1, 1, 1);

        lineEdit_epy = new QLineEdit(layoutWidget1);
        lineEdit_epy->setObjectName("lineEdit_epy");

        gridLayout->addWidget(lineEdit_epy, 4, 1, 1, 1);

        lineEdit_rad = new QLineEdit(layoutWidget1);
        lineEdit_rad->setObjectName("lineEdit_rad");

        gridLayout->addWidget(lineEdit_rad, 6, 1, 1, 1);

        label_spy = new QLabel(layoutWidget1);
        label_spy->setObjectName("label_spy");

        gridLayout->addWidget(label_spy, 1, 0, 1, 1);

        label_epx = new QLabel(layoutWidget1);
        label_epx->setObjectName("label_epx");

        gridLayout->addWidget(label_epx, 3, 0, 1, 1);

        label_epy = new QLabel(layoutWidget1);
        label_epy->setObjectName("label_epy");

        gridLayout->addWidget(label_epy, 4, 0, 1, 1);

        label_epz = new QLabel(layoutWidget1);
        label_epz->setObjectName("label_epz");

        gridLayout->addWidget(label_epz, 5, 0, 1, 1);

        label_rad = new QLabel(layoutWidget1);
        label_rad->setObjectName("label_rad");

        gridLayout->addWidget(label_rad, 6, 0, 1, 1);

        layoutWidget2 = new QWidget(Dialog_Bogen);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 410, 321, 48));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_uzs = new QRadioButton(layoutWidget2);
        radioButton_uzs->setObjectName("radioButton_uzs");

        verticalLayout->addWidget(radioButton_uzs);

        radioButton_guzs = new QRadioButton(layoutWidget2);
        radioButton_guzs->setObjectName("radioButton_guzs");

        verticalLayout->addWidget(radioButton_guzs);

        QWidget::setTabOrder(lineEdit_spx, lineEdit_spy);
        QWidget::setTabOrder(lineEdit_spy, lineEdit_spz);
        QWidget::setTabOrder(lineEdit_spz, lineEdit_epx);
        QWidget::setTabOrder(lineEdit_epx, lineEdit_epy);
        QWidget::setTabOrder(lineEdit_epy, lineEdit_epz);
        QWidget::setTabOrder(lineEdit_epz, lineEdit_rad);
        QWidget::setTabOrder(lineEdit_rad, radioButton_uzs);
        QWidget::setTabOrder(radioButton_uzs, radioButton_guzs);
        QWidget::setTabOrder(radioButton_guzs, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_abbrechen);

        retranslateUi(Dialog_Bogen);

        QMetaObject::connectSlotsByName(Dialog_Bogen);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Bogen)
    {
        Dialog_Bogen->setWindowTitle(QCoreApplication::translate("Dialog_Bogen", "Dialog", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_Bogen", "Abbrechen", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_Bogen", "OK", nullptr));
        label_spx->setText(QCoreApplication::translate("Dialog_Bogen", "Startpunkt X", nullptr));
        label_spz->setText(QCoreApplication::translate("Dialog_Bogen", "Startpunkt Z", nullptr));
        label_spy->setText(QCoreApplication::translate("Dialog_Bogen", "Startpunkt Y", nullptr));
        label_epx->setText(QCoreApplication::translate("Dialog_Bogen", "Endpunkt X", nullptr));
        label_epy->setText(QCoreApplication::translate("Dialog_Bogen", "Endpunkt Y", nullptr));
        label_epz->setText(QCoreApplication::translate("Dialog_Bogen", "Endpunkt Z", nullptr));
        label_rad->setText(QCoreApplication::translate("Dialog_Bogen", "Radius", nullptr));
        radioButton_uzs->setText(QCoreApplication::translate("Dialog_Bogen", "im Uhrzeigersinn", nullptr));
        radioButton_guzs->setText(QCoreApplication::translate("Dialog_Bogen", "gegen den Uhrzeigersinn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Bogen: public Ui_Dialog_Bogen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_BOGEN_H
