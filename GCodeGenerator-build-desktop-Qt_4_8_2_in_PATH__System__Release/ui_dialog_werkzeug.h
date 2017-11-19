/********************************************************************************
** Form generated from reading UI file 'dialog_werkzeug.ui'
**
** Created: Sat Nov 18 22:23:19 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_WERKZEUG_H
#define UI_DIALOG_WERKZEUG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Werkzeug
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_Allgemein;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_Kommentar;
    QLineEdit *lineEdit_Kommentar;
    QComboBox *comboBox_Drehrichtung;
    QLineEdit *lineEdit_Werkzeugnummer;
    QLabel *label_Durchmesser;
    QLabel *label_Werkzeugnummer;
    QLabel *label_Steckplatz;
    QLineEdit *lineEdit_Durchmesser;
    QLineEdit *lineEdit_Steckplatz;
    QLabel *label_Drehrichtung;
    QLineEdit *lineEdit_Werkzeugname;
    QLabel *label_Werkzeugname;
    QLabel *label_Nutzlaenge;
    QLineEdit *lineEdit__Nutzlaenge;
    QLabel *label_bild;
    QPushButton *pushButton_bild_info;
    QWidget *tab_Offset;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_Offset_X;
    QLabel *label_Offset_Y;
    QLineEdit *lineEdit_Offset_Y;
    QLabel *label_Offset_Z;
    QLineEdit *lineEdit_Offset_Z;
    QLabel *label_Offset_A;
    QLineEdit *lineEdit_Offset_A;
    QLabel *label_Offset_B;
    QLineEdit *lineEdit_Offset_B;
    QLabel *label_Offset_C;
    QLineEdit *lineEdit_Offset_C;
    QLabel *label_Offset_U;
    QLineEdit *lineEdit_Offset_U;
    QLabel *label_Offset_V;
    QLineEdit *lineEdit_Offset_V;
    QLabel *label_Offset_W;
    QLineEdit *lineEdit_Offset_W;
    QLineEdit *lineEdit_Offset_X;
    QWidget *tab_Drehmaschine;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_Frontwinkel;
    QLineEdit *lineEdit_Frontwinkel;
    QLabel *label_Rueckwinkel;
    QLineEdit *lineEdit_Rueckwinkel;
    QLabel *label_Richtung;
    QLineEdit *lineEdit_Richtung;
    QWidget *tab_AUTO_Werte;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QLabel *label_Eintauchvorschub;
    QLineEdit *lineEdit_Eintauchvorschub;
    QLabel *label_Vorschub_XY;
    QLineEdit *lineEdit_Vorschub_XY;
    QLabel *label_Drehzahl;
    QLineEdit *lineEdit_Drehzahl;
    QLabel *label_zustelltiefe;
    QLineEdit *lineEdit_zustelltiefe;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_Speichern;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Werkzeug)
    {
        if (Dialog_Werkzeug->objectName().isEmpty())
            Dialog_Werkzeug->setObjectName(QString::fromUtf8("Dialog_Werkzeug"));
        Dialog_Werkzeug->resize(489, 546);
        Dialog_Werkzeug->setModal(true);
        tabWidget = new QTabWidget(Dialog_Werkzeug);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 471, 491));
        tab_Allgemein = new QWidget();
        tab_Allgemein->setObjectName(QString::fromUtf8("tab_Allgemein"));
        layoutWidget = new QWidget(tab_Allgemein);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 441, 231));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Kommentar = new QLabel(layoutWidget);
        label_Kommentar->setObjectName(QString::fromUtf8("label_Kommentar"));

        gridLayout_4->addWidget(label_Kommentar, 6, 0, 1, 1);

        lineEdit_Kommentar = new QLineEdit(layoutWidget);
        lineEdit_Kommentar->setObjectName(QString::fromUtf8("lineEdit_Kommentar"));

        gridLayout_4->addWidget(lineEdit_Kommentar, 6, 1, 1, 1);

        comboBox_Drehrichtung = new QComboBox(layoutWidget);
        comboBox_Drehrichtung->setObjectName(QString::fromUtf8("comboBox_Drehrichtung"));

        gridLayout_4->addWidget(comboBox_Drehrichtung, 5, 1, 1, 1);

        lineEdit_Werkzeugnummer = new QLineEdit(layoutWidget);
        lineEdit_Werkzeugnummer->setObjectName(QString::fromUtf8("lineEdit_Werkzeugnummer"));

        gridLayout_4->addWidget(lineEdit_Werkzeugnummer, 1, 1, 1, 1);

        label_Durchmesser = new QLabel(layoutWidget);
        label_Durchmesser->setObjectName(QString::fromUtf8("label_Durchmesser"));

        gridLayout_4->addWidget(label_Durchmesser, 3, 0, 1, 1);

        label_Werkzeugnummer = new QLabel(layoutWidget);
        label_Werkzeugnummer->setObjectName(QString::fromUtf8("label_Werkzeugnummer"));

        gridLayout_4->addWidget(label_Werkzeugnummer, 1, 0, 1, 1);

        label_Steckplatz = new QLabel(layoutWidget);
        label_Steckplatz->setObjectName(QString::fromUtf8("label_Steckplatz"));

        gridLayout_4->addWidget(label_Steckplatz, 2, 0, 1, 1);

        lineEdit_Durchmesser = new QLineEdit(layoutWidget);
        lineEdit_Durchmesser->setObjectName(QString::fromUtf8("lineEdit_Durchmesser"));

        gridLayout_4->addWidget(lineEdit_Durchmesser, 3, 1, 1, 1);

        lineEdit_Steckplatz = new QLineEdit(layoutWidget);
        lineEdit_Steckplatz->setObjectName(QString::fromUtf8("lineEdit_Steckplatz"));

        gridLayout_4->addWidget(lineEdit_Steckplatz, 2, 1, 1, 1);

        label_Drehrichtung = new QLabel(layoutWidget);
        label_Drehrichtung->setObjectName(QString::fromUtf8("label_Drehrichtung"));

        gridLayout_4->addWidget(label_Drehrichtung, 5, 0, 1, 1);

        lineEdit_Werkzeugname = new QLineEdit(layoutWidget);
        lineEdit_Werkzeugname->setObjectName(QString::fromUtf8("lineEdit_Werkzeugname"));

        gridLayout_4->addWidget(lineEdit_Werkzeugname, 0, 1, 1, 1);

        label_Werkzeugname = new QLabel(layoutWidget);
        label_Werkzeugname->setObjectName(QString::fromUtf8("label_Werkzeugname"));

        gridLayout_4->addWidget(label_Werkzeugname, 0, 0, 1, 1);

        label_Nutzlaenge = new QLabel(layoutWidget);
        label_Nutzlaenge->setObjectName(QString::fromUtf8("label_Nutzlaenge"));

        gridLayout_4->addWidget(label_Nutzlaenge, 4, 0, 1, 1);

        lineEdit__Nutzlaenge = new QLineEdit(layoutWidget);
        lineEdit__Nutzlaenge->setObjectName(QString::fromUtf8("lineEdit__Nutzlaenge"));

        gridLayout_4->addWidget(lineEdit__Nutzlaenge, 4, 1, 1, 1);

        label_bild = new QLabel(tab_Allgemein);
        label_bild->setObjectName(QString::fromUtf8("label_bild"));
        label_bild->setGeometry(QRect(81, 244, 301, 201));
        pushButton_bild_info = new QPushButton(tab_Allgemein);
        pushButton_bild_info->setObjectName(QString::fromUtf8("pushButton_bild_info"));
        pushButton_bild_info->setGeometry(QRect(410, 330, 41, 27));
        tabWidget->addTab(tab_Allgemein, QString());
        tab_Offset = new QWidget();
        tab_Offset->setObjectName(QString::fromUtf8("tab_Offset"));
        layoutWidget1 = new QWidget(tab_Offset);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 431, 431));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Offset_X = new QLabel(layoutWidget1);
        label_Offset_X->setObjectName(QString::fromUtf8("label_Offset_X"));

        gridLayout->addWidget(label_Offset_X, 0, 0, 1, 1);

        label_Offset_Y = new QLabel(layoutWidget1);
        label_Offset_Y->setObjectName(QString::fromUtf8("label_Offset_Y"));

        gridLayout->addWidget(label_Offset_Y, 1, 0, 1, 1);

        lineEdit_Offset_Y = new QLineEdit(layoutWidget1);
        lineEdit_Offset_Y->setObjectName(QString::fromUtf8("lineEdit_Offset_Y"));

        gridLayout->addWidget(lineEdit_Offset_Y, 1, 1, 1, 1);

        label_Offset_Z = new QLabel(layoutWidget1);
        label_Offset_Z->setObjectName(QString::fromUtf8("label_Offset_Z"));

        gridLayout->addWidget(label_Offset_Z, 2, 0, 1, 1);

        lineEdit_Offset_Z = new QLineEdit(layoutWidget1);
        lineEdit_Offset_Z->setObjectName(QString::fromUtf8("lineEdit_Offset_Z"));

        gridLayout->addWidget(lineEdit_Offset_Z, 2, 1, 1, 1);

        label_Offset_A = new QLabel(layoutWidget1);
        label_Offset_A->setObjectName(QString::fromUtf8("label_Offset_A"));

        gridLayout->addWidget(label_Offset_A, 3, 0, 1, 1);

        lineEdit_Offset_A = new QLineEdit(layoutWidget1);
        lineEdit_Offset_A->setObjectName(QString::fromUtf8("lineEdit_Offset_A"));

        gridLayout->addWidget(lineEdit_Offset_A, 3, 1, 1, 1);

        label_Offset_B = new QLabel(layoutWidget1);
        label_Offset_B->setObjectName(QString::fromUtf8("label_Offset_B"));

        gridLayout->addWidget(label_Offset_B, 4, 0, 1, 1);

        lineEdit_Offset_B = new QLineEdit(layoutWidget1);
        lineEdit_Offset_B->setObjectName(QString::fromUtf8("lineEdit_Offset_B"));

        gridLayout->addWidget(lineEdit_Offset_B, 4, 1, 1, 1);

        label_Offset_C = new QLabel(layoutWidget1);
        label_Offset_C->setObjectName(QString::fromUtf8("label_Offset_C"));

        gridLayout->addWidget(label_Offset_C, 5, 0, 1, 1);

        lineEdit_Offset_C = new QLineEdit(layoutWidget1);
        lineEdit_Offset_C->setObjectName(QString::fromUtf8("lineEdit_Offset_C"));

        gridLayout->addWidget(lineEdit_Offset_C, 5, 1, 1, 1);

        label_Offset_U = new QLabel(layoutWidget1);
        label_Offset_U->setObjectName(QString::fromUtf8("label_Offset_U"));

        gridLayout->addWidget(label_Offset_U, 6, 0, 1, 1);

        lineEdit_Offset_U = new QLineEdit(layoutWidget1);
        lineEdit_Offset_U->setObjectName(QString::fromUtf8("lineEdit_Offset_U"));

        gridLayout->addWidget(lineEdit_Offset_U, 6, 1, 1, 1);

        label_Offset_V = new QLabel(layoutWidget1);
        label_Offset_V->setObjectName(QString::fromUtf8("label_Offset_V"));

        gridLayout->addWidget(label_Offset_V, 7, 0, 1, 1);

        lineEdit_Offset_V = new QLineEdit(layoutWidget1);
        lineEdit_Offset_V->setObjectName(QString::fromUtf8("lineEdit_Offset_V"));

        gridLayout->addWidget(lineEdit_Offset_V, 7, 1, 1, 1);

        label_Offset_W = new QLabel(layoutWidget1);
        label_Offset_W->setObjectName(QString::fromUtf8("label_Offset_W"));

        gridLayout->addWidget(label_Offset_W, 8, 0, 1, 1);

        lineEdit_Offset_W = new QLineEdit(layoutWidget1);
        lineEdit_Offset_W->setObjectName(QString::fromUtf8("lineEdit_Offset_W"));

        gridLayout->addWidget(lineEdit_Offset_W, 8, 1, 1, 1);

        lineEdit_Offset_X = new QLineEdit(layoutWidget1);
        lineEdit_Offset_X->setObjectName(QString::fromUtf8("lineEdit_Offset_X"));

        gridLayout->addWidget(lineEdit_Offset_X, 0, 1, 1, 1);

        tabWidget->addTab(tab_Offset, QString());
        tab_Drehmaschine = new QWidget();
        tab_Drehmaschine->setObjectName(QString::fromUtf8("tab_Drehmaschine"));
        layoutWidget2 = new QWidget(tab_Drehmaschine);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 12, 441, 111));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Frontwinkel = new QLabel(layoutWidget2);
        label_Frontwinkel->setObjectName(QString::fromUtf8("label_Frontwinkel"));

        gridLayout_3->addWidget(label_Frontwinkel, 0, 0, 1, 1);

        lineEdit_Frontwinkel = new QLineEdit(layoutWidget2);
        lineEdit_Frontwinkel->setObjectName(QString::fromUtf8("lineEdit_Frontwinkel"));

        gridLayout_3->addWidget(lineEdit_Frontwinkel, 0, 1, 1, 1);

        label_Rueckwinkel = new QLabel(layoutWidget2);
        label_Rueckwinkel->setObjectName(QString::fromUtf8("label_Rueckwinkel"));

        gridLayout_3->addWidget(label_Rueckwinkel, 1, 0, 1, 1);

        lineEdit_Rueckwinkel = new QLineEdit(layoutWidget2);
        lineEdit_Rueckwinkel->setObjectName(QString::fromUtf8("lineEdit_Rueckwinkel"));

        gridLayout_3->addWidget(lineEdit_Rueckwinkel, 1, 1, 1, 1);

        label_Richtung = new QLabel(layoutWidget2);
        label_Richtung->setObjectName(QString::fromUtf8("label_Richtung"));

        gridLayout_3->addWidget(label_Richtung, 2, 0, 1, 1);

        lineEdit_Richtung = new QLineEdit(layoutWidget2);
        lineEdit_Richtung->setObjectName(QString::fromUtf8("lineEdit_Richtung"));

        gridLayout_3->addWidget(lineEdit_Richtung, 2, 1, 1, 1);

        tabWidget->addTab(tab_Drehmaschine, QString());
        tab_AUTO_Werte = new QWidget();
        tab_AUTO_Werte->setObjectName(QString::fromUtf8("tab_AUTO_Werte"));
        layoutWidget3 = new QWidget(tab_AUTO_Werte);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 12, 451, 191));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Eintauchvorschub = new QLabel(layoutWidget3);
        label_Eintauchvorschub->setObjectName(QString::fromUtf8("label_Eintauchvorschub"));

        gridLayout_2->addWidget(label_Eintauchvorschub, 0, 0, 1, 1);

        lineEdit_Eintauchvorschub = new QLineEdit(layoutWidget3);
        lineEdit_Eintauchvorschub->setObjectName(QString::fromUtf8("lineEdit_Eintauchvorschub"));

        gridLayout_2->addWidget(lineEdit_Eintauchvorschub, 0, 1, 1, 1);

        label_Vorschub_XY = new QLabel(layoutWidget3);
        label_Vorschub_XY->setObjectName(QString::fromUtf8("label_Vorschub_XY"));

        gridLayout_2->addWidget(label_Vorschub_XY, 1, 0, 1, 1);

        lineEdit_Vorschub_XY = new QLineEdit(layoutWidget3);
        lineEdit_Vorschub_XY->setObjectName(QString::fromUtf8("lineEdit_Vorschub_XY"));

        gridLayout_2->addWidget(lineEdit_Vorschub_XY, 1, 1, 1, 1);

        label_Drehzahl = new QLabel(layoutWidget3);
        label_Drehzahl->setObjectName(QString::fromUtf8("label_Drehzahl"));

        gridLayout_2->addWidget(label_Drehzahl, 2, 0, 1, 1);

        lineEdit_Drehzahl = new QLineEdit(layoutWidget3);
        lineEdit_Drehzahl->setObjectName(QString::fromUtf8("lineEdit_Drehzahl"));

        gridLayout_2->addWidget(lineEdit_Drehzahl, 2, 1, 1, 1);

        label_zustelltiefe = new QLabel(layoutWidget3);
        label_zustelltiefe->setObjectName(QString::fromUtf8("label_zustelltiefe"));

        gridLayout_2->addWidget(label_zustelltiefe, 3, 0, 1, 1);

        lineEdit_zustelltiefe = new QLineEdit(layoutWidget3);
        lineEdit_zustelltiefe->setObjectName(QString::fromUtf8("lineEdit_zustelltiefe"));

        gridLayout_2->addWidget(lineEdit_zustelltiefe, 3, 1, 1, 1);

        tabWidget->addTab(tab_AUTO_Werte, QString());
        layoutWidget4 = new QWidget(Dialog_Werkzeug);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 500, 471, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget4);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget4);
        pushButton_Speichern->setObjectName(QString::fromUtf8("pushButton_Speichern"));

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget4);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        QWidget::setTabOrder(tabWidget, lineEdit_Werkzeugname);
        QWidget::setTabOrder(lineEdit_Werkzeugname, lineEdit_Werkzeugnummer);
        QWidget::setTabOrder(lineEdit_Werkzeugnummer, lineEdit_Steckplatz);
        QWidget::setTabOrder(lineEdit_Steckplatz, lineEdit_Durchmesser);
        QWidget::setTabOrder(lineEdit_Durchmesser, lineEdit__Nutzlaenge);
        QWidget::setTabOrder(lineEdit__Nutzlaenge, comboBox_Drehrichtung);
        QWidget::setTabOrder(comboBox_Drehrichtung, lineEdit_Kommentar);
        QWidget::setTabOrder(lineEdit_Kommentar, lineEdit_Offset_X);
        QWidget::setTabOrder(lineEdit_Offset_X, lineEdit_Offset_Y);
        QWidget::setTabOrder(lineEdit_Offset_Y, lineEdit_Offset_Z);
        QWidget::setTabOrder(lineEdit_Offset_Z, lineEdit_Offset_A);
        QWidget::setTabOrder(lineEdit_Offset_A, lineEdit_Offset_B);
        QWidget::setTabOrder(lineEdit_Offset_B, lineEdit_Offset_C);
        QWidget::setTabOrder(lineEdit_Offset_C, lineEdit_Offset_U);
        QWidget::setTabOrder(lineEdit_Offset_U, lineEdit_Offset_V);
        QWidget::setTabOrder(lineEdit_Offset_V, lineEdit_Offset_W);
        QWidget::setTabOrder(lineEdit_Offset_W, lineEdit_Frontwinkel);
        QWidget::setTabOrder(lineEdit_Frontwinkel, lineEdit_Rueckwinkel);
        QWidget::setTabOrder(lineEdit_Rueckwinkel, lineEdit_Richtung);
        QWidget::setTabOrder(lineEdit_Richtung, lineEdit_Eintauchvorschub);
        QWidget::setTabOrder(lineEdit_Eintauchvorschub, lineEdit_Vorschub_XY);
        QWidget::setTabOrder(lineEdit_Vorschub_XY, lineEdit_Drehzahl);
        QWidget::setTabOrder(lineEdit_Drehzahl, lineEdit_zustelltiefe);
        QWidget::setTabOrder(lineEdit_zustelltiefe, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_Speichern);
        QWidget::setTabOrder(pushButton_Speichern, pushButton_OK);
        QWidget::setTabOrder(pushButton_OK, pushButton_bild_info);

        retranslateUi(Dialog_Werkzeug);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_Werkzeug);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Werkzeug)
    {
        Dialog_Werkzeug->setWindowTitle(QApplication::translate("Dialog_Werkzeug", "Werkzeug", 0, QApplication::UnicodeUTF8));
        label_Kommentar->setText(QApplication::translate("Dialog_Werkzeug", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_Durchmesser->setText(QApplication::translate("Dialog_Werkzeug", "Durchmesser", 0, QApplication::UnicodeUTF8));
        label_Werkzeugnummer->setText(QApplication::translate("Dialog_Werkzeug", "Werkzeugnummer", 0, QApplication::UnicodeUTF8));
        label_Steckplatz->setText(QApplication::translate("Dialog_Werkzeug", "Steckplatz", 0, QApplication::UnicodeUTF8));
        label_Drehrichtung->setText(QApplication::translate("Dialog_Werkzeug", "Drehrichtung", 0, QApplication::UnicodeUTF8));
        label_Werkzeugname->setText(QApplication::translate("Dialog_Werkzeug", "Name", 0, QApplication::UnicodeUTF8));
        label_Nutzlaenge->setText(QApplication::translate("Dialog_Werkzeug", "Nutzl\303\244nge", 0, QApplication::UnicodeUTF8));
        label_bild->setText(QString());
        pushButton_bild_info->setText(QApplication::translate("Dialog_Werkzeug", "???", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Allgemein), QApplication::translate("Dialog_Werkzeug", "Allgemeines", 0, QApplication::UnicodeUTF8));
        label_Offset_X->setText(QApplication::translate("Dialog_Werkzeug", "Offset X", 0, QApplication::UnicodeUTF8));
        label_Offset_Y->setText(QApplication::translate("Dialog_Werkzeug", "Offset Y", 0, QApplication::UnicodeUTF8));
        label_Offset_Z->setText(QApplication::translate("Dialog_Werkzeug", "Offset Z", 0, QApplication::UnicodeUTF8));
        label_Offset_A->setText(QApplication::translate("Dialog_Werkzeug", "Offset A", 0, QApplication::UnicodeUTF8));
        label_Offset_B->setText(QApplication::translate("Dialog_Werkzeug", "Offset B", 0, QApplication::UnicodeUTF8));
        label_Offset_C->setText(QApplication::translate("Dialog_Werkzeug", "Offset C", 0, QApplication::UnicodeUTF8));
        label_Offset_U->setText(QApplication::translate("Dialog_Werkzeug", "Offset U", 0, QApplication::UnicodeUTF8));
        label_Offset_V->setText(QApplication::translate("Dialog_Werkzeug", "Offset V", 0, QApplication::UnicodeUTF8));
        label_Offset_W->setText(QApplication::translate("Dialog_Werkzeug", "Offset W", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Offset), QApplication::translate("Dialog_Werkzeug", "Offset", 0, QApplication::UnicodeUTF8));
        label_Frontwinkel->setText(QApplication::translate("Dialog_Werkzeug", "Frontwinkel", 0, QApplication::UnicodeUTF8));
        label_Rueckwinkel->setText(QApplication::translate("Dialog_Werkzeug", "R\303\274ckwinkel", 0, QApplication::UnicodeUTF8));
        label_Richtung->setText(QApplication::translate("Dialog_Werkzeug", "Richtung", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Drehmaschine), QApplication::translate("Dialog_Werkzeug", "Drehmaschine", 0, QApplication::UnicodeUTF8));
        label_Eintauchvorschub->setText(QApplication::translate("Dialog_Werkzeug", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_Vorschub_XY->setText(QApplication::translate("Dialog_Werkzeug", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_Drehzahl->setText(QApplication::translate("Dialog_Werkzeug", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_zustelltiefe->setText(QApplication::translate("Dialog_Werkzeug", "Zustelltiefe", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_AUTO_Werte), QApplication::translate("Dialog_Werkzeug", "AUTO-Werte", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Werkzeug", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_Speichern->setText(QApplication::translate("Dialog_Werkzeug", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Werkzeug", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Werkzeug: public Ui_Dialog_Werkzeug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_WERKZEUG_H
