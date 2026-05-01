/********************************************************************************
** Form generated from reading UI file 'dialog_programmkopf.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMMKOPF_H
#define UI_DIALOG_PROGRAMMKOPF_H

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

class Ui_Dialog_Programmkopf
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_laenge;
    QLabel *label_sicherheitsabstand;
    QLineEdit *lineEdit_sicherheitsabstand;
    QLabel *label_ay;
    QLabel *label_ax;
    QLabel *label_laenge;
    QLabel *label_breite;
    QLabel *label_kommentar1;
    QLabel *label_dicke_var;
    QLineEdit *lineEdit_kommentar1;
    QLineEdit *lineEdit_dicke;
    QLineEdit *lineEdit_ax;
    QLabel *label_Ausfuehrbedingung;
    QLabel *label_bezeichnung;
    QLabel *label_ay_var;
    QLabel *label_dicke;
    QLabel *label_Ausfuehrbedingung_var;
    QLineEdit *lineEdit_ay;
    QLabel *label_laenge_var;
    QLabel *label_breite_var;
    QLineEdit *lineEdit_breite;
    QLabel *label_kommentar1_var;
    QLineEdit *lineEdit__bezeichnung;
    QLabel *label_ax_var;
    QLineEdit *lineEdit_AFB;
    QLabel *label__bezeichnung_var;
    QLabel *label__sicherheitsabstand_var;
    QLineEdit *lineEdit_schabl;
    QLabel *label_schabl_var;
    QLabel *label_schabl;

    void setupUi(QDialog *Dialog_Programmkopf)
    {
        if (Dialog_Programmkopf->objectName().isEmpty())
            Dialog_Programmkopf->setObjectName("Dialog_Programmkopf");
        Dialog_Programmkopf->resize(435, 480);
        Dialog_Programmkopf->setModal(true);
        layoutWidget = new QWidget(Dialog_Programmkopf);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(110, 440, 321, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName("pushButton_Abbrechen");

        horizontalLayout_2->addWidget(pushButton_Abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout_2->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout_2->addWidget(pushButton_OK);

        widget = new QWidget(Dialog_Programmkopf);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 10, 411, 411));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_laenge = new QLineEdit(widget);
        lineEdit_laenge->setObjectName("lineEdit_laenge");
        lineEdit_laenge->setFrame(true);

        gridLayout->addWidget(lineEdit_laenge, 0, 2, 1, 1);

        label_sicherheitsabstand = new QLabel(widget);
        label_sicherheitsabstand->setObjectName("label_sicherheitsabstand");

        gridLayout->addWidget(label_sicherheitsabstand, 4, 0, 1, 1);

        lineEdit_sicherheitsabstand = new QLineEdit(widget);
        lineEdit_sicherheitsabstand->setObjectName("lineEdit_sicherheitsabstand");

        gridLayout->addWidget(lineEdit_sicherheitsabstand, 4, 2, 1, 1);

        label_ay = new QLabel(widget);
        label_ay->setObjectName("label_ay");

        gridLayout->addWidget(label_ay, 8, 0, 1, 1);

        label_ax = new QLabel(widget);
        label_ax->setObjectName("label_ax");

        gridLayout->addWidget(label_ax, 7, 0, 1, 1);

        label_laenge = new QLabel(widget);
        label_laenge->setObjectName("label_laenge");

        gridLayout->addWidget(label_laenge, 0, 0, 1, 1);

        label_breite = new QLabel(widget);
        label_breite->setObjectName("label_breite");

        gridLayout->addWidget(label_breite, 1, 0, 1, 1);

        label_kommentar1 = new QLabel(widget);
        label_kommentar1->setObjectName("label_kommentar1");

        gridLayout->addWidget(label_kommentar1, 3, 0, 1, 1);

        label_dicke_var = new QLabel(widget);
        label_dicke_var->setObjectName("label_dicke_var");
        label_dicke_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_dicke_var, 2, 1, 1, 1);

        lineEdit_kommentar1 = new QLineEdit(widget);
        lineEdit_kommentar1->setObjectName("lineEdit_kommentar1");

        gridLayout->addWidget(lineEdit_kommentar1, 3, 2, 1, 1);

        lineEdit_dicke = new QLineEdit(widget);
        lineEdit_dicke->setObjectName("lineEdit_dicke");

        gridLayout->addWidget(lineEdit_dicke, 2, 2, 1, 1);

        lineEdit_ax = new QLineEdit(widget);
        lineEdit_ax->setObjectName("lineEdit_ax");

        gridLayout->addWidget(lineEdit_ax, 7, 2, 1, 1);

        label_Ausfuehrbedingung = new QLabel(widget);
        label_Ausfuehrbedingung->setObjectName("label_Ausfuehrbedingung");

        gridLayout->addWidget(label_Ausfuehrbedingung, 6, 0, 1, 1);

        label_bezeichnung = new QLabel(widget);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout->addWidget(label_bezeichnung, 5, 0, 1, 1);

        label_ay_var = new QLabel(widget);
        label_ay_var->setObjectName("label_ay_var");
        label_ay_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ay_var, 8, 1, 1, 1);

        label_dicke = new QLabel(widget);
        label_dicke->setObjectName("label_dicke");

        gridLayout->addWidget(label_dicke, 2, 0, 1, 1);

        label_Ausfuehrbedingung_var = new QLabel(widget);
        label_Ausfuehrbedingung_var->setObjectName("label_Ausfuehrbedingung_var");
        label_Ausfuehrbedingung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Ausfuehrbedingung_var, 6, 1, 1, 1);

        lineEdit_ay = new QLineEdit(widget);
        lineEdit_ay->setObjectName("lineEdit_ay");

        gridLayout->addWidget(lineEdit_ay, 8, 2, 1, 1);

        label_laenge_var = new QLabel(widget);
        label_laenge_var->setObjectName("label_laenge_var");
        label_laenge_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_laenge_var, 0, 1, 1, 1);

        label_breite_var = new QLabel(widget);
        label_breite_var->setObjectName("label_breite_var");
        label_breite_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_breite_var, 1, 1, 1, 1);

        lineEdit_breite = new QLineEdit(widget);
        lineEdit_breite->setObjectName("lineEdit_breite");

        gridLayout->addWidget(lineEdit_breite, 1, 2, 1, 1);

        label_kommentar1_var = new QLabel(widget);
        label_kommentar1_var->setObjectName("label_kommentar1_var");
        label_kommentar1_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_kommentar1_var, 3, 1, 1, 1);

        lineEdit__bezeichnung = new QLineEdit(widget);
        lineEdit__bezeichnung->setObjectName("lineEdit__bezeichnung");

        gridLayout->addWidget(lineEdit__bezeichnung, 5, 2, 1, 1);

        label_ax_var = new QLabel(widget);
        label_ax_var->setObjectName("label_ax_var");
        label_ax_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ax_var, 7, 1, 1, 1);

        lineEdit_AFB = new QLineEdit(widget);
        lineEdit_AFB->setObjectName("lineEdit_AFB");

        gridLayout->addWidget(lineEdit_AFB, 6, 2, 1, 1);

        label__bezeichnung_var = new QLabel(widget);
        label__bezeichnung_var->setObjectName("label__bezeichnung_var");
        label__bezeichnung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label__bezeichnung_var, 5, 1, 1, 1);

        label__sicherheitsabstand_var = new QLabel(widget);
        label__sicherheitsabstand_var->setObjectName("label__sicherheitsabstand_var");
        label__sicherheitsabstand_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label__sicherheitsabstand_var, 4, 1, 1, 1);

        lineEdit_schabl = new QLineEdit(widget);
        lineEdit_schabl->setObjectName("lineEdit_schabl");

        gridLayout->addWidget(lineEdit_schabl, 9, 2, 1, 1);

        label_schabl_var = new QLabel(widget);
        label_schabl_var->setObjectName("label_schabl_var");
        label_schabl_var->setLayoutDirection(Qt::LeftToRight);
        label_schabl_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_schabl_var, 9, 1, 1, 1);

        label_schabl = new QLabel(widget);
        label_schabl->setObjectName("label_schabl");

        gridLayout->addWidget(label_schabl, 9, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_laenge, lineEdit_breite);
        QWidget::setTabOrder(lineEdit_breite, lineEdit_dicke);
        QWidget::setTabOrder(lineEdit_dicke, lineEdit_kommentar1);
        QWidget::setTabOrder(lineEdit_kommentar1, lineEdit_sicherheitsabstand);
        QWidget::setTabOrder(lineEdit_sicherheitsabstand, lineEdit__bezeichnung);
        QWidget::setTabOrder(lineEdit__bezeichnung, lineEdit_AFB);
        QWidget::setTabOrder(lineEdit_AFB, lineEdit_ax);
        QWidget::setTabOrder(lineEdit_ax, lineEdit_ay);
        QWidget::setTabOrder(lineEdit_ay, lineEdit_schabl);
        QWidget::setTabOrder(lineEdit_schabl, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Programmkopf);

        QMetaObject::connectSlotsByName(Dialog_Programmkopf);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programmkopf)
    {
        Dialog_Programmkopf->setWindowTitle(QCoreApplication::translate("Dialog_Programmkopf", "Programmkopf", nullptr));
        pushButton_Abbrechen->setText(QCoreApplication::translate("Dialog_Programmkopf", "Abbrechen", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Dialog_Programmkopf", "Speichern", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Programmkopf", "OK", nullptr));
        label_sicherheitsabstand->setText(QCoreApplication::translate("Dialog_Programmkopf", "Sicherheitsabstand", nullptr));
        label_ay->setText(QCoreApplication::translate("Dialog_Programmkopf", "Y-Versatz", nullptr));
        label_ax->setText(QCoreApplication::translate("Dialog_Programmkopf", "X-Versatz", nullptr));
        label_laenge->setText(QCoreApplication::translate("Dialog_Programmkopf", "Laenge", nullptr));
        label_breite->setText(QCoreApplication::translate("Dialog_Programmkopf", "Breite", nullptr));
        label_kommentar1->setText(QCoreApplication::translate("Dialog_Programmkopf", "Kommentar", nullptr));
        label_dicke_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "*[D]", nullptr));
        label_Ausfuehrbedingung->setText(QCoreApplication::translate("Dialog_Programmkopf", "Ausfuehrbedingung", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_Programmkopf", "Bezeichnung", nullptr));
        label_ay_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[AY]", nullptr));
        label_dicke->setText(QCoreApplication::translate("Dialog_Programmkopf", "Dicke", nullptr));
        label_Ausfuehrbedingung_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[AFB]", nullptr));
        label_laenge_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "*[L]", nullptr));
        label_breite_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "*[B]", nullptr));
        label_kommentar1_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[KOM]", nullptr));
        label_ax_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[AX]", nullptr));
        label__bezeichnung_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[BEZ]", nullptr));
        label__sicherheitsabstand_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[SIA]", nullptr));
        label_schabl_var->setText(QCoreApplication::translate("Dialog_Programmkopf", "[SH]", nullptr));
        label_schabl->setText(QCoreApplication::translate("Dialog_Programmkopf", "<html><head/><body><p>Schablonenh\303\266he</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programmkopf: public Ui_Dialog_Programmkopf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMMKOPF_H
