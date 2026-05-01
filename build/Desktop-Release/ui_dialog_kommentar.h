/********************************************************************************
** Form generated from reading UI file 'dialog_kommentar.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_KOMMENTAR_H
#define UI_DIALOG_KOMMENTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Kommentar
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Kommentar;
    QLabel *label_AFB;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Kommentar_var;
    QLabel *label_AFB_var;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Kommentar;
    QLineEdit *lineEdit_AFB;

    void setupUi(QDialog *Dialog_Kommentar)
    {
        if (Dialog_Kommentar->objectName().isEmpty())
            Dialog_Kommentar->setObjectName("Dialog_Kommentar");
        Dialog_Kommentar->resize(498, 129);
        Dialog_Kommentar->setModal(true);
        layoutWidget = new QWidget(Dialog_Kommentar);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(191, 90, 301, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName("pushButton_Abbrechen");

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout->addWidget(pushButton_OK);

        layoutWidget1 = new QWidget(Dialog_Kommentar);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(11, 10, 481, 56));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_Kommentar = new QLabel(layoutWidget1);
        label_Kommentar->setObjectName("label_Kommentar");

        verticalLayout_3->addWidget(label_Kommentar);

        label_AFB = new QLabel(layoutWidget1);
        label_AFB->setObjectName("label_AFB");

        verticalLayout_3->addWidget(label_AFB);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Kommentar_var = new QLabel(layoutWidget1);
        label_Kommentar_var->setObjectName("label_Kommentar_var");

        verticalLayout_2->addWidget(label_Kommentar_var);

        label_AFB_var = new QLabel(layoutWidget1);
        label_AFB_var->setObjectName("label_AFB_var");

        verticalLayout_2->addWidget(label_AFB_var);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_Kommentar = new QLineEdit(layoutWidget1);
        lineEdit_Kommentar->setObjectName("lineEdit_Kommentar");

        verticalLayout->addWidget(lineEdit_Kommentar);

        lineEdit_AFB = new QLineEdit(layoutWidget1);
        lineEdit_AFB->setObjectName("lineEdit_AFB");

        verticalLayout->addWidget(lineEdit_AFB);


        horizontalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(lineEdit_Kommentar, lineEdit_AFB);
        QWidget::setTabOrder(lineEdit_AFB, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Kommentar);

        QMetaObject::connectSlotsByName(Dialog_Kommentar);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Kommentar)
    {
        Dialog_Kommentar->setWindowTitle(QCoreApplication::translate("Dialog_Kommentar", "Kommentar", nullptr));
        pushButton_Abbrechen->setText(QCoreApplication::translate("Dialog_Kommentar", "Abbrechen", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_Kommentar", "Speichern", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Kommentar", "OK", nullptr));
        label_Kommentar->setText(QCoreApplication::translate("Dialog_Kommentar", "Kommentar", nullptr));
        label_AFB->setText(QCoreApplication::translate("Dialog_Kommentar", "Ausf\303\274hrbedingung", nullptr));
        label_Kommentar_var->setText(QCoreApplication::translate("Dialog_Kommentar", "[KOM]", nullptr));
        label_AFB_var->setText(QCoreApplication::translate("Dialog_Kommentar", "[AFB]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Kommentar: public Ui_Dialog_Kommentar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_KOMMENTAR_H
