/********************************************************************************
** Form generated from reading UI file 'dialog_programmkopf.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMMKOPF_H
#define UI_DIALOG_PROGRAMMKOPF_H

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

class Ui_Dialog_Programmkopf
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_laenge;
    QLabel *label_breite;
    QLabel *label_dicke;
    QLabel *label_kommentar1;
    QLabel *label_sicherheitsabstand;
    QLabel *label_bezeichnung;
    QLabel *label_Ausfuehrbedingung;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_laenge_var;
    QLabel *label_breite_var;
    QLabel *label_dicke_var;
    QLabel *label_kommentar1_var;
    QLabel *label__sicherheitsabstand_var;
    QLabel *label__bezeichnung_var;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_laenge;
    QLineEdit *lineEdit_breite;
    QLineEdit *lineEdit_dicke;
    QLineEdit *lineEdit_kommentar1;
    QLineEdit *lineEdit_sicherheitsabstand;
    QLineEdit *lineEdit__bezeichnung;
    QLineEdit *lineEdit_AFB;

    void setupUi(QDialog *Dialog_Programmkopf)
    {
        if (Dialog_Programmkopf->objectName().isEmpty())
            Dialog_Programmkopf->setObjectName(QString::fromUtf8("Dialog_Programmkopf"));
        Dialog_Programmkopf->resize(435, 405);
        Dialog_Programmkopf->setModal(true);
        layoutWidget = new QWidget(Dialog_Programmkopf);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 370, 321, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout_2->addWidget(pushButton_Abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout_2->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout_2->addWidget(pushButton_OK);

        layoutWidget1 = new QWidget(Dialog_Programmkopf);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 11, 411, 291));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_laenge = new QLabel(layoutWidget1);
        label_laenge->setObjectName(QString::fromUtf8("label_laenge"));

        verticalLayout_2->addWidget(label_laenge);

        label_breite = new QLabel(layoutWidget1);
        label_breite->setObjectName(QString::fromUtf8("label_breite"));

        verticalLayout_2->addWidget(label_breite);

        label_dicke = new QLabel(layoutWidget1);
        label_dicke->setObjectName(QString::fromUtf8("label_dicke"));

        verticalLayout_2->addWidget(label_dicke);

        label_kommentar1 = new QLabel(layoutWidget1);
        label_kommentar1->setObjectName(QString::fromUtf8("label_kommentar1"));

        verticalLayout_2->addWidget(label_kommentar1);

        label_sicherheitsabstand = new QLabel(layoutWidget1);
        label_sicherheitsabstand->setObjectName(QString::fromUtf8("label_sicherheitsabstand"));

        verticalLayout_2->addWidget(label_sicherheitsabstand);

        label_bezeichnung = new QLabel(layoutWidget1);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        verticalLayout_2->addWidget(label_bezeichnung);

        label_Ausfuehrbedingung = new QLabel(layoutWidget1);
        label_Ausfuehrbedingung->setObjectName(QString::fromUtf8("label_Ausfuehrbedingung"));

        verticalLayout_2->addWidget(label_Ausfuehrbedingung);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_laenge_var = new QLabel(layoutWidget1);
        label_laenge_var->setObjectName(QString::fromUtf8("label_laenge_var"));
        label_laenge_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_laenge_var);

        label_breite_var = new QLabel(layoutWidget1);
        label_breite_var->setObjectName(QString::fromUtf8("label_breite_var"));
        label_breite_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_breite_var);

        label_dicke_var = new QLabel(layoutWidget1);
        label_dicke_var->setObjectName(QString::fromUtf8("label_dicke_var"));
        label_dicke_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_dicke_var);

        label_kommentar1_var = new QLabel(layoutWidget1);
        label_kommentar1_var->setObjectName(QString::fromUtf8("label_kommentar1_var"));
        label_kommentar1_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_kommentar1_var);

        label__sicherheitsabstand_var = new QLabel(layoutWidget1);
        label__sicherheitsabstand_var->setObjectName(QString::fromUtf8("label__sicherheitsabstand_var"));

        verticalLayout_4->addWidget(label__sicherheitsabstand_var);

        label__bezeichnung_var = new QLabel(layoutWidget1);
        label__bezeichnung_var->setObjectName(QString::fromUtf8("label__bezeichnung_var"));

        verticalLayout_4->addWidget(label__bezeichnung_var);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_laenge = new QLineEdit(layoutWidget1);
        lineEdit_laenge->setObjectName(QString::fromUtf8("lineEdit_laenge"));
        lineEdit_laenge->setFrame(true);

        verticalLayout->addWidget(lineEdit_laenge);

        lineEdit_breite = new QLineEdit(layoutWidget1);
        lineEdit_breite->setObjectName(QString::fromUtf8("lineEdit_breite"));

        verticalLayout->addWidget(lineEdit_breite);

        lineEdit_dicke = new QLineEdit(layoutWidget1);
        lineEdit_dicke->setObjectName(QString::fromUtf8("lineEdit_dicke"));

        verticalLayout->addWidget(lineEdit_dicke);

        lineEdit_kommentar1 = new QLineEdit(layoutWidget1);
        lineEdit_kommentar1->setObjectName(QString::fromUtf8("lineEdit_kommentar1"));

        verticalLayout->addWidget(lineEdit_kommentar1);

        lineEdit_sicherheitsabstand = new QLineEdit(layoutWidget1);
        lineEdit_sicherheitsabstand->setObjectName(QString::fromUtf8("lineEdit_sicherheitsabstand"));

        verticalLayout->addWidget(lineEdit_sicherheitsabstand);

        lineEdit__bezeichnung = new QLineEdit(layoutWidget1);
        lineEdit__bezeichnung->setObjectName(QString::fromUtf8("lineEdit__bezeichnung"));

        verticalLayout->addWidget(lineEdit__bezeichnung);

        lineEdit_AFB = new QLineEdit(layoutWidget1);
        lineEdit_AFB->setObjectName(QString::fromUtf8("lineEdit_AFB"));

        verticalLayout->addWidget(lineEdit_AFB);


        horizontalLayout->addLayout(verticalLayout);

        QWidget::setTabOrder(lineEdit_laenge, lineEdit_breite);
        QWidget::setTabOrder(lineEdit_breite, lineEdit_dicke);
        QWidget::setTabOrder(lineEdit_dicke, lineEdit_kommentar1);
        QWidget::setTabOrder(lineEdit_kommentar1, lineEdit_sicherheitsabstand);
        QWidget::setTabOrder(lineEdit_sicherheitsabstand, lineEdit__bezeichnung);
        QWidget::setTabOrder(lineEdit__bezeichnung, lineEdit_AFB);
        QWidget::setTabOrder(lineEdit_AFB, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Programmkopf);

        QMetaObject::connectSlotsByName(Dialog_Programmkopf);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programmkopf)
    {
        Dialog_Programmkopf->setWindowTitle(QApplication::translate("Dialog_Programmkopf", "Programmkopf", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Programmkopf", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Dialog_Programmkopf", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Programmkopf", "OK", 0, QApplication::UnicodeUTF8));
        label_laenge->setText(QApplication::translate("Dialog_Programmkopf", "Laenge", 0, QApplication::UnicodeUTF8));
        label_breite->setText(QApplication::translate("Dialog_Programmkopf", "Breite", 0, QApplication::UnicodeUTF8));
        label_dicke->setText(QApplication::translate("Dialog_Programmkopf", "Dicke", 0, QApplication::UnicodeUTF8));
        label_kommentar1->setText(QApplication::translate("Dialog_Programmkopf", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_sicherheitsabstand->setText(QApplication::translate("Dialog_Programmkopf", "Sicherheitsabstand", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_Programmkopf", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        label_Ausfuehrbedingung->setText(QApplication::translate("Dialog_Programmkopf", "Ausfuehrbedingung", 0, QApplication::UnicodeUTF8));
        label_laenge_var->setText(QApplication::translate("Dialog_Programmkopf", "*[L]", 0, QApplication::UnicodeUTF8));
        label_breite_var->setText(QApplication::translate("Dialog_Programmkopf", "*[B]", 0, QApplication::UnicodeUTF8));
        label_dicke_var->setText(QApplication::translate("Dialog_Programmkopf", "*[D]", 0, QApplication::UnicodeUTF8));
        label_kommentar1_var->setText(QApplication::translate("Dialog_Programmkopf", "[KOM]", 0, QApplication::UnicodeUTF8));
        label__sicherheitsabstand_var->setText(QApplication::translate("Dialog_Programmkopf", "[SIA]", 0, QApplication::UnicodeUTF8));
        label__bezeichnung_var->setText(QApplication::translate("Dialog_Programmkopf", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_Programmkopf", "[AFB]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programmkopf: public Ui_Dialog_Programmkopf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMMKOPF_H
