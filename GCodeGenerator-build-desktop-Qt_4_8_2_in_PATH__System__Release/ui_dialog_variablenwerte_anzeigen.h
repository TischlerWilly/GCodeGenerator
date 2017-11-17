/********************************************************************************
** Form generated from reading UI file 'dialog_variablenwerte_anzeigen.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H
#define UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
            Dialog_variablenwerte_anzeigen->setObjectName(QString::fromUtf8("Dialog_variablenwerte_anzeigen"));
        Dialog_variablenwerte_anzeigen->resize(400, 211);
        layoutWidget = new QWidget(Dialog_variablenwerte_anzeigen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_bez = new QLabel(layoutWidget);
        label_bez->setObjectName(QString::fromUtf8("label_bez"));

        verticalLayout_2->addWidget(label_bez);

        label_zeilennummer = new QLabel(layoutWidget);
        label_zeilennummer->setObjectName(QString::fromUtf8("label_zeilennummer"));

        verticalLayout_2->addWidget(label_zeilennummer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_bez = new QLineEdit(layoutWidget);
        lineEdit_bez->setObjectName(QString::fromUtf8("lineEdit_bez"));

        verticalLayout->addWidget(lineEdit_bez);

        lineEdit_zeilennummer = new QLineEdit(layoutWidget);
        lineEdit_zeilennummer->setObjectName(QString::fromUtf8("lineEdit_zeilennummer"));

        verticalLayout->addWidget(lineEdit_zeilennummer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_wert_beschriftungstext = new QLabel(layoutWidget);
        label_wert_beschriftungstext->setObjectName(QString::fromUtf8("label_wert_beschriftungstext"));

        horizontalLayout_2->addWidget(label_wert_beschriftungstext);

        label_wert = new QLabel(layoutWidget);
        label_wert->setObjectName(QString::fromUtf8("label_wert"));

        horizontalLayout_2->addWidget(label_wert);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Dialog_variablenwerte_anzeigen);

        QMetaObject::connectSlotsByName(Dialog_variablenwerte_anzeigen);
    } // setupUi

    void retranslateUi(QDialog *Dialog_variablenwerte_anzeigen)
    {
        Dialog_variablenwerte_anzeigen->setWindowTitle(QApplication::translate("Dialog_variablenwerte_anzeigen", "Dialog", 0, QApplication::UnicodeUTF8));
        label_bez->setText(QApplication::translate("Dialog_variablenwerte_anzeigen", "Bezeichnung:", 0, QApplication::UnicodeUTF8));
        label_zeilennummer->setText(QApplication::translate("Dialog_variablenwerte_anzeigen", "Zeilennummer:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog_variablenwerte_anzeigen", "Aktualisieren", 0, QApplication::UnicodeUTF8));
        label_wert_beschriftungstext->setText(QApplication::translate("Dialog_variablenwerte_anzeigen", "Wert:", 0, QApplication::UnicodeUTF8));
        label_wert->setText(QApplication::translate("Dialog_variablenwerte_anzeigen", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_variablenwerte_anzeigen: public Ui_Dialog_variablenwerte_anzeigen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VARIABLENWERTE_ANZEIGEN_H
