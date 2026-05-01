/********************************************************************************
** Form generated from reading UI file 'dialog_kreis.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_KREIS_H
#define UI_DIALOG_KREIS_H

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

class Ui_Dialog_Kreis
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_x;
    QLabel *label_y;
    QLabel *label_z;
    QLabel *label_r;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QLineEdit *lineEdit_z;
    QLineEdit *lineEdit_r;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Kreis)
    {
        if (Dialog_Kreis->objectName().isEmpty())
            Dialog_Kreis->setObjectName("Dialog_Kreis");
        Dialog_Kreis->resize(334, 274);
        Dialog_Kreis->setModal(true);
        layoutWidget = new QWidget(Dialog_Kreis);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 311, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_x = new QLabel(layoutWidget);
        label_x->setObjectName("label_x");

        gridLayout->addWidget(label_x, 0, 0, 1, 1);

        label_y = new QLabel(layoutWidget);
        label_y->setObjectName("label_y");

        gridLayout->addWidget(label_y, 1, 0, 1, 1);

        label_z = new QLabel(layoutWidget);
        label_z->setObjectName("label_z");

        gridLayout->addWidget(label_z, 2, 0, 1, 1);

        label_r = new QLabel(layoutWidget);
        label_r->setObjectName("label_r");

        gridLayout->addWidget(label_r, 3, 0, 1, 1);

        lineEdit_x = new QLineEdit(layoutWidget);
        lineEdit_x->setObjectName("lineEdit_x");

        gridLayout->addWidget(lineEdit_x, 0, 1, 1, 1);

        lineEdit_y = new QLineEdit(layoutWidget);
        lineEdit_y->setObjectName("lineEdit_y");

        gridLayout->addWidget(lineEdit_y, 1, 1, 1, 1);

        lineEdit_z = new QLineEdit(layoutWidget);
        lineEdit_z->setObjectName("lineEdit_z");

        gridLayout->addWidget(lineEdit_z, 2, 1, 1, 1);

        lineEdit_r = new QLineEdit(layoutWidget);
        lineEdit_r->setObjectName("lineEdit_r");

        gridLayout->addWidget(lineEdit_r, 3, 1, 1, 1);

        layoutWidget1 = new QWidget(Dialog_Kreis);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 230, 311, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget1);
        pushButton_Abbrechen->setObjectName("pushButton_Abbrechen");

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_OK = new QPushButton(layoutWidget1);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout->addWidget(pushButton_OK);

        QWidget::setTabOrder(lineEdit_x, lineEdit_y);
        QWidget::setTabOrder(lineEdit_y, lineEdit_z);
        QWidget::setTabOrder(lineEdit_z, lineEdit_r);
        QWidget::setTabOrder(lineEdit_r, pushButton_OK);
        QWidget::setTabOrder(pushButton_OK, pushButton_Abbrechen);

        retranslateUi(Dialog_Kreis);

        QMetaObject::connectSlotsByName(Dialog_Kreis);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Kreis)
    {
        Dialog_Kreis->setWindowTitle(QCoreApplication::translate("Dialog_Kreis", "Kreis", nullptr));
        label_x->setText(QCoreApplication::translate("Dialog_Kreis", "Mittelpunkt X-Wert", nullptr));
        label_y->setText(QCoreApplication::translate("Dialog_Kreis", "Mittelpunkt Y_Wert", nullptr));
        label_z->setText(QCoreApplication::translate("Dialog_Kreis", "Mittelpunkt Z-Wert", nullptr));
        label_r->setText(QCoreApplication::translate("Dialog_Kreis", "Radius", nullptr));
        pushButton_Abbrechen->setText(QCoreApplication::translate("Dialog_Kreis", "Abbrechen", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Kreis", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Kreis: public Ui_Dialog_Kreis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_KREIS_H
