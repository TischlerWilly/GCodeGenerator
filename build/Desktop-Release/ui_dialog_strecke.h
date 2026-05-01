/********************************************************************************
** Form generated from reading UI file 'dialog_strecke.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STRECKE_H
#define UI_DIALOG_STRECKE_H

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

class Ui_Dialog_strecke
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_epx;
    QLabel *label_spx;
    QLineEdit *lineEdit_spx;
    QLabel *label_spy;
    QLineEdit *lineEdit_spy;
    QLineEdit *lineEdit_spz;
    QLineEdit *lineEdit_epy;
    QLineEdit *lineEdit_epz;
    QLabel *label_spz;
    QLabel *label_epx;
    QLabel *label_epy;
    QLabel *label_epz;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_strecke)
    {
        if (Dialog_strecke->objectName().isEmpty())
            Dialog_strecke->setObjectName("Dialog_strecke");
        Dialog_strecke->resize(335, 324);
        Dialog_strecke->setModal(true);
        layoutWidget = new QWidget(Dialog_strecke);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 311, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_epx = new QLineEdit(layoutWidget);
        lineEdit_epx->setObjectName("lineEdit_epx");

        gridLayout->addWidget(lineEdit_epx, 3, 1, 1, 1);

        label_spx = new QLabel(layoutWidget);
        label_spx->setObjectName("label_spx");

        gridLayout->addWidget(label_spx, 0, 0, 1, 1);

        lineEdit_spx = new QLineEdit(layoutWidget);
        lineEdit_spx->setObjectName("lineEdit_spx");

        gridLayout->addWidget(lineEdit_spx, 0, 1, 1, 1);

        label_spy = new QLabel(layoutWidget);
        label_spy->setObjectName("label_spy");

        gridLayout->addWidget(label_spy, 1, 0, 1, 1);

        lineEdit_spy = new QLineEdit(layoutWidget);
        lineEdit_spy->setObjectName("lineEdit_spy");

        gridLayout->addWidget(lineEdit_spy, 1, 1, 1, 1);

        lineEdit_spz = new QLineEdit(layoutWidget);
        lineEdit_spz->setObjectName("lineEdit_spz");

        gridLayout->addWidget(lineEdit_spz, 2, 1, 1, 1);

        lineEdit_epy = new QLineEdit(layoutWidget);
        lineEdit_epy->setObjectName("lineEdit_epy");

        gridLayout->addWidget(lineEdit_epy, 4, 1, 1, 1);

        lineEdit_epz = new QLineEdit(layoutWidget);
        lineEdit_epz->setObjectName("lineEdit_epz");

        gridLayout->addWidget(lineEdit_epz, 5, 1, 1, 1);

        label_spz = new QLabel(layoutWidget);
        label_spz->setObjectName("label_spz");

        gridLayout->addWidget(label_spz, 2, 0, 1, 1);

        label_epx = new QLabel(layoutWidget);
        label_epx->setObjectName("label_epx");

        gridLayout->addWidget(label_epx, 3, 0, 1, 1);

        label_epy = new QLabel(layoutWidget);
        label_epy->setObjectName("label_epy");

        gridLayout->addWidget(label_epy, 4, 0, 1, 1);

        label_epz = new QLabel(layoutWidget);
        label_epz->setObjectName("label_epz");

        gridLayout->addWidget(label_epz, 5, 0, 1, 1);

        layoutWidget1 = new QWidget(Dialog_strecke);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 280, 311, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget1);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_ok = new QPushButton(layoutWidget1);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        QWidget::setTabOrder(lineEdit_spx, lineEdit_spy);
        QWidget::setTabOrder(lineEdit_spy, lineEdit_spz);
        QWidget::setTabOrder(lineEdit_spz, lineEdit_epx);
        QWidget::setTabOrder(lineEdit_epx, lineEdit_epy);
        QWidget::setTabOrder(lineEdit_epy, lineEdit_epz);
        QWidget::setTabOrder(lineEdit_epz, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_abbrechen);

        retranslateUi(Dialog_strecke);

        QMetaObject::connectSlotsByName(Dialog_strecke);
    } // setupUi

    void retranslateUi(QDialog *Dialog_strecke)
    {
        Dialog_strecke->setWindowTitle(QCoreApplication::translate("Dialog_strecke", "Dialog", nullptr));
        label_spx->setText(QCoreApplication::translate("Dialog_strecke", "Startpunkt X", nullptr));
        label_spy->setText(QCoreApplication::translate("Dialog_strecke", "Startpunkt Y", nullptr));
        label_spz->setText(QCoreApplication::translate("Dialog_strecke", "Startpunkt Z", nullptr));
        label_epx->setText(QCoreApplication::translate("Dialog_strecke", "Endpunkt X", nullptr));
        label_epy->setText(QCoreApplication::translate("Dialog_strecke", "Endpunkt Y", nullptr));
        label_epz->setText(QCoreApplication::translate("Dialog_strecke", "Endpunkt Z", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_strecke", "Abbrechen", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_strecke", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_strecke: public Ui_Dialog_strecke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STRECKE_H
