/********************************************************************************
** Form generated from reading UI file 'dialog_variablenwerte_anzeigen.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H
#define UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H

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

class Ui_Dialog_variablenwerte_anzeigen
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_bez;
    QLabel *label_zeilennummer;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_bez;
    QLineEdit *lineEdit_zeilennummer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_wert_beschriftungstext;
    QLabel *label_wert;

    void setupUi(QDialog *Dialog_variablenwerte_anzeigen)
    {
        if (Dialog_variablenwerte_anzeigen->objectName().isEmpty())
            Dialog_variablenwerte_anzeigen->setObjectName("Dialog_variablenwerte_anzeigen");
        Dialog_variablenwerte_anzeigen->resize(400, 211);
        Dialog_variablenwerte_anzeigen->setModal(true);
        layoutWidget = new QWidget(Dialog_variablenwerte_anzeigen);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 381, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_bez = new QLabel(layoutWidget);
        label_bez->setObjectName("label_bez");

        verticalLayout_2->addWidget(label_bez);

        label_zeilennummer = new QLabel(layoutWidget);
        label_zeilennummer->setObjectName("label_zeilennummer");

        verticalLayout_2->addWidget(label_zeilennummer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_bez = new QLineEdit(layoutWidget);
        lineEdit_bez->setObjectName("lineEdit_bez");

        verticalLayout->addWidget(lineEdit_bez);

        lineEdit_zeilennummer = new QLineEdit(layoutWidget);
        lineEdit_zeilennummer->setObjectName("lineEdit_zeilennummer");

        verticalLayout->addWidget(lineEdit_zeilennummer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_wert_beschriftungstext = new QLabel(layoutWidget);
        label_wert_beschriftungstext->setObjectName("label_wert_beschriftungstext");

        horizontalLayout_2->addWidget(label_wert_beschriftungstext);

        label_wert = new QLabel(layoutWidget);
        label_wert->setObjectName("label_wert");

        horizontalLayout_2->addWidget(label_wert);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Dialog_variablenwerte_anzeigen);

        QMetaObject::connectSlotsByName(Dialog_variablenwerte_anzeigen);
    } // setupUi

    void retranslateUi(QDialog *Dialog_variablenwerte_anzeigen)
    {
        Dialog_variablenwerte_anzeigen->setWindowTitle(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "Dialog", nullptr));
        label_bez->setText(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "Bezeichnung:", nullptr));
        label_zeilennummer->setText(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "Zeilennummer:", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "Aktualisieren", nullptr));
        label_wert_beschriftungstext->setText(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "Wert:", nullptr));
        label_wert->setText(QCoreApplication::translate("Dialog_variablenwerte_anzeigen", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_variablenwerte_anzeigen: public Ui_Dialog_variablenwerte_anzeigen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H
