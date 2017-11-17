/********************************************************************************
** Form generated from reading UI file 'dialog_programmlisten.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMMLISTEN_H
#define UI_DIALOG_PROGRAMMLISTEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Programmlisten
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QPlainTextEdit *plainTextEdit_programmtext;
    QWidget *tab_2;
    QPlainTextEdit *plainTextEdit_klartext;
    QWidget *tab_3;
    QPlainTextEdit *plainTextEdit_variablen;
    QWidget *tab_4;
    QPlainTextEdit *plainTextEdit_geometrietext;
    QWidget *tab_5;
    QPlainTextEdit *plainTextEdit_fkon;

    void setupUi(QDialog *Dialog_Programmlisten)
    {
        if (Dialog_Programmlisten->objectName().isEmpty())
            Dialog_Programmlisten->setObjectName(QString::fromUtf8("Dialog_Programmlisten"));
        Dialog_Programmlisten->resize(622, 589);
        tabWidget = new QTabWidget(Dialog_Programmlisten);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 601, 571));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        plainTextEdit_programmtext = new QPlainTextEdit(tab);
        plainTextEdit_programmtext->setObjectName(QString::fromUtf8("plainTextEdit_programmtext"));
        plainTextEdit_programmtext->setGeometry(QRect(10, 10, 581, 521));
        plainTextEdit_programmtext->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_programmtext->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plainTextEdit_klartext = new QPlainTextEdit(tab_2);
        plainTextEdit_klartext->setObjectName(QString::fromUtf8("plainTextEdit_klartext"));
        plainTextEdit_klartext->setGeometry(QRect(10, 10, 581, 521));
        plainTextEdit_klartext->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_klartext->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        plainTextEdit_variablen = new QPlainTextEdit(tab_3);
        plainTextEdit_variablen->setObjectName(QString::fromUtf8("plainTextEdit_variablen"));
        plainTextEdit_variablen->setGeometry(QRect(10, 10, 581, 521));
        plainTextEdit_variablen->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_variablen->setReadOnly(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        plainTextEdit_geometrietext = new QPlainTextEdit(tab_4);
        plainTextEdit_geometrietext->setObjectName(QString::fromUtf8("plainTextEdit_geometrietext"));
        plainTextEdit_geometrietext->setGeometry(QRect(10, 10, 581, 521));
        plainTextEdit_geometrietext->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_geometrietext->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_geometrietext->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_geometrietext->setReadOnly(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        plainTextEdit_fkon = new QPlainTextEdit(tab_5);
        plainTextEdit_fkon->setObjectName(QString::fromUtf8("plainTextEdit_fkon"));
        plainTextEdit_fkon->setGeometry(QRect(10, 10, 581, 521));
        plainTextEdit_fkon->setLineWrapMode(QPlainTextEdit::NoWrap);
        tabWidget->addTab(tab_5, QString());

        retranslateUi(Dialog_Programmlisten);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_Programmlisten);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programmlisten)
    {
        Dialog_Programmlisten->setWindowTitle(QApplication::translate("Dialog_Programmlisten", "Programmlisten anzeigen", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog_Programmlisten", "Programmtext", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog_Programmlisten", "Klartext", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dialog_Programmlisten", "Variablen", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Dialog_Programmlisten", "Geometrietext", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Dialog_Programmlisten", "Fraeskonturen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programmlisten: public Ui_Dialog_Programmlisten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMMLISTEN_H
