/********************************************************************************
** Form generated from reading UI file 'dialog_werkzeug.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_WERKZEUG_H
#define UI_DIALOG_WERKZEUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_kann_bohren;
    QCheckBox *checkBox_kann_fraesen;
    QWidget *tab_Offset;
    QWidget *layoutWidget2;
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
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_3;
    QLabel *label_Frontwinkel;
    QLineEdit *lineEdit_Frontwinkel;
    QLabel *label_Rueckwinkel;
    QLineEdit *lineEdit_Rueckwinkel;
    QLabel *label_Richtung;
    QLineEdit *lineEdit_Richtung;
    QWidget *tab_AUTO_Werte;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_2;
    QLabel *label_Vorschub_XY;
    QLabel *label_Drehzahl;
    QLabel *label_Eintauchvorschub;
    QLabel *label_zustelltiefe;
    QLineEdit *lineEdit_Eintauchvorschub;
    QLineEdit *lineEdit_Drehzahl;
    QLineEdit *lineEdit_zustelltiefe;
    QLineEdit *lineEdit_Vorschub_XY;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_5;
    QLabel *label_anbohrvorschub;
    QLineEdit *lineEdit_anbohrvorschub;
    QLabel *label_restbohrtiefe;
    QLineEdit *lineEdit_bohrvorschub;
    QLabel *label_bohrvorschub;
    QLabel *label_anbohrtiefe;
    QLabel *label_bohrzustelltiefe;
    QLineEdit *lineEdit_anbohrtiefe;
    QLineEdit *lineEdit_bohrzustelltiefe;
    QLineEdit *lineEdit_restbohrtiefe;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_Speichern;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Werkzeug)
    {
        if (Dialog_Werkzeug->objectName().isEmpty())
            Dialog_Werkzeug->setObjectName("Dialog_Werkzeug");
        Dialog_Werkzeug->resize(489, 581);
        Dialog_Werkzeug->setModal(true);
        tabWidget = new QTabWidget(Dialog_Werkzeug);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 471, 531));
        tab_Allgemein = new QWidget();
        tab_Allgemein->setObjectName("tab_Allgemein");
        layoutWidget = new QWidget(tab_Allgemein);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 441, 231));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_Kommentar = new QLabel(layoutWidget);
        label_Kommentar->setObjectName("label_Kommentar");

        gridLayout_4->addWidget(label_Kommentar, 6, 0, 1, 1);

        lineEdit_Kommentar = new QLineEdit(layoutWidget);
        lineEdit_Kommentar->setObjectName("lineEdit_Kommentar");

        gridLayout_4->addWidget(lineEdit_Kommentar, 6, 2, 1, 1);

        comboBox_Drehrichtung = new QComboBox(layoutWidget);
        comboBox_Drehrichtung->setObjectName("comboBox_Drehrichtung");

        gridLayout_4->addWidget(comboBox_Drehrichtung, 5, 2, 1, 1);

        lineEdit_Werkzeugnummer = new QLineEdit(layoutWidget);
        lineEdit_Werkzeugnummer->setObjectName("lineEdit_Werkzeugnummer");

        gridLayout_4->addWidget(lineEdit_Werkzeugnummer, 1, 2, 1, 1);

        label_Durchmesser = new QLabel(layoutWidget);
        label_Durchmesser->setObjectName("label_Durchmesser");

        gridLayout_4->addWidget(label_Durchmesser, 3, 0, 1, 1);

        label_Werkzeugnummer = new QLabel(layoutWidget);
        label_Werkzeugnummer->setObjectName("label_Werkzeugnummer");

        gridLayout_4->addWidget(label_Werkzeugnummer, 1, 0, 1, 1);

        label_Steckplatz = new QLabel(layoutWidget);
        label_Steckplatz->setObjectName("label_Steckplatz");

        gridLayout_4->addWidget(label_Steckplatz, 2, 0, 1, 1);

        lineEdit_Durchmesser = new QLineEdit(layoutWidget);
        lineEdit_Durchmesser->setObjectName("lineEdit_Durchmesser");

        gridLayout_4->addWidget(lineEdit_Durchmesser, 3, 2, 1, 1);

        lineEdit_Steckplatz = new QLineEdit(layoutWidget);
        lineEdit_Steckplatz->setObjectName("lineEdit_Steckplatz");

        gridLayout_4->addWidget(lineEdit_Steckplatz, 2, 2, 1, 1);

        label_Drehrichtung = new QLabel(layoutWidget);
        label_Drehrichtung->setObjectName("label_Drehrichtung");

        gridLayout_4->addWidget(label_Drehrichtung, 5, 0, 1, 1);

        lineEdit_Werkzeugname = new QLineEdit(layoutWidget);
        lineEdit_Werkzeugname->setObjectName("lineEdit_Werkzeugname");

        gridLayout_4->addWidget(lineEdit_Werkzeugname, 0, 2, 1, 1);

        label_Werkzeugname = new QLabel(layoutWidget);
        label_Werkzeugname->setObjectName("label_Werkzeugname");

        gridLayout_4->addWidget(label_Werkzeugname, 0, 0, 1, 1);

        label_Nutzlaenge = new QLabel(layoutWidget);
        label_Nutzlaenge->setObjectName("label_Nutzlaenge");

        gridLayout_4->addWidget(label_Nutzlaenge, 4, 0, 1, 1);

        lineEdit__Nutzlaenge = new QLineEdit(layoutWidget);
        lineEdit__Nutzlaenge->setObjectName("lineEdit__Nutzlaenge");

        gridLayout_4->addWidget(lineEdit__Nutzlaenge, 4, 2, 1, 1);

        label_bild = new QLabel(tab_Allgemein);
        label_bild->setObjectName("label_bild");
        label_bild->setGeometry(QRect(81, 290, 301, 201));
        pushButton_bild_info = new QPushButton(tab_Allgemein);
        pushButton_bild_info->setObjectName("pushButton_bild_info");
        pushButton_bild_info->setGeometry(QRect(410, 360, 41, 27));
        layoutWidget1 = new QWidget(tab_Allgemein);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 247, 141, 48));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_kann_bohren = new QCheckBox(layoutWidget1);
        checkBox_kann_bohren->setObjectName("checkBox_kann_bohren");

        verticalLayout->addWidget(checkBox_kann_bohren);

        checkBox_kann_fraesen = new QCheckBox(layoutWidget1);
        checkBox_kann_fraesen->setObjectName("checkBox_kann_fraesen");

        verticalLayout->addWidget(checkBox_kann_fraesen);

        tabWidget->addTab(tab_Allgemein, QString());
        tab_Offset = new QWidget();
        tab_Offset->setObjectName("tab_Offset");
        layoutWidget2 = new QWidget(tab_Offset);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 20, 431, 431));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Offset_X = new QLabel(layoutWidget2);
        label_Offset_X->setObjectName("label_Offset_X");

        gridLayout->addWidget(label_Offset_X, 0, 0, 1, 1);

        label_Offset_Y = new QLabel(layoutWidget2);
        label_Offset_Y->setObjectName("label_Offset_Y");

        gridLayout->addWidget(label_Offset_Y, 1, 0, 1, 1);

        lineEdit_Offset_Y = new QLineEdit(layoutWidget2);
        lineEdit_Offset_Y->setObjectName("lineEdit_Offset_Y");

        gridLayout->addWidget(lineEdit_Offset_Y, 1, 1, 1, 1);

        label_Offset_Z = new QLabel(layoutWidget2);
        label_Offset_Z->setObjectName("label_Offset_Z");

        gridLayout->addWidget(label_Offset_Z, 2, 0, 1, 1);

        lineEdit_Offset_Z = new QLineEdit(layoutWidget2);
        lineEdit_Offset_Z->setObjectName("lineEdit_Offset_Z");

        gridLayout->addWidget(lineEdit_Offset_Z, 2, 1, 1, 1);

        label_Offset_A = new QLabel(layoutWidget2);
        label_Offset_A->setObjectName("label_Offset_A");

        gridLayout->addWidget(label_Offset_A, 3, 0, 1, 1);

        lineEdit_Offset_A = new QLineEdit(layoutWidget2);
        lineEdit_Offset_A->setObjectName("lineEdit_Offset_A");

        gridLayout->addWidget(lineEdit_Offset_A, 3, 1, 1, 1);

        label_Offset_B = new QLabel(layoutWidget2);
        label_Offset_B->setObjectName("label_Offset_B");

        gridLayout->addWidget(label_Offset_B, 4, 0, 1, 1);

        lineEdit_Offset_B = new QLineEdit(layoutWidget2);
        lineEdit_Offset_B->setObjectName("lineEdit_Offset_B");

        gridLayout->addWidget(lineEdit_Offset_B, 4, 1, 1, 1);

        label_Offset_C = new QLabel(layoutWidget2);
        label_Offset_C->setObjectName("label_Offset_C");

        gridLayout->addWidget(label_Offset_C, 5, 0, 1, 1);

        lineEdit_Offset_C = new QLineEdit(layoutWidget2);
        lineEdit_Offset_C->setObjectName("lineEdit_Offset_C");

        gridLayout->addWidget(lineEdit_Offset_C, 5, 1, 1, 1);

        label_Offset_U = new QLabel(layoutWidget2);
        label_Offset_U->setObjectName("label_Offset_U");

        gridLayout->addWidget(label_Offset_U, 6, 0, 1, 1);

        lineEdit_Offset_U = new QLineEdit(layoutWidget2);
        lineEdit_Offset_U->setObjectName("lineEdit_Offset_U");

        gridLayout->addWidget(lineEdit_Offset_U, 6, 1, 1, 1);

        label_Offset_V = new QLabel(layoutWidget2);
        label_Offset_V->setObjectName("label_Offset_V");

        gridLayout->addWidget(label_Offset_V, 7, 0, 1, 1);

        lineEdit_Offset_V = new QLineEdit(layoutWidget2);
        lineEdit_Offset_V->setObjectName("lineEdit_Offset_V");

        gridLayout->addWidget(lineEdit_Offset_V, 7, 1, 1, 1);

        label_Offset_W = new QLabel(layoutWidget2);
        label_Offset_W->setObjectName("label_Offset_W");

        gridLayout->addWidget(label_Offset_W, 8, 0, 1, 1);

        lineEdit_Offset_W = new QLineEdit(layoutWidget2);
        lineEdit_Offset_W->setObjectName("lineEdit_Offset_W");

        gridLayout->addWidget(lineEdit_Offset_W, 8, 1, 1, 1);

        lineEdit_Offset_X = new QLineEdit(layoutWidget2);
        lineEdit_Offset_X->setObjectName("lineEdit_Offset_X");

        gridLayout->addWidget(lineEdit_Offset_X, 0, 1, 1, 1);

        tabWidget->addTab(tab_Offset, QString());
        tab_Drehmaschine = new QWidget();
        tab_Drehmaschine->setObjectName("tab_Drehmaschine");
        layoutWidget3 = new QWidget(tab_Drehmaschine);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 12, 441, 111));
        gridLayout_3 = new QGridLayout(layoutWidget3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Frontwinkel = new QLabel(layoutWidget3);
        label_Frontwinkel->setObjectName("label_Frontwinkel");

        gridLayout_3->addWidget(label_Frontwinkel, 0, 0, 1, 1);

        lineEdit_Frontwinkel = new QLineEdit(layoutWidget3);
        lineEdit_Frontwinkel->setObjectName("lineEdit_Frontwinkel");

        gridLayout_3->addWidget(lineEdit_Frontwinkel, 0, 1, 1, 1);

        label_Rueckwinkel = new QLabel(layoutWidget3);
        label_Rueckwinkel->setObjectName("label_Rueckwinkel");

        gridLayout_3->addWidget(label_Rueckwinkel, 1, 0, 1, 1);

        lineEdit_Rueckwinkel = new QLineEdit(layoutWidget3);
        lineEdit_Rueckwinkel->setObjectName("lineEdit_Rueckwinkel");

        gridLayout_3->addWidget(lineEdit_Rueckwinkel, 1, 1, 1, 1);

        label_Richtung = new QLabel(layoutWidget3);
        label_Richtung->setObjectName("label_Richtung");

        gridLayout_3->addWidget(label_Richtung, 2, 0, 1, 1);

        lineEdit_Richtung = new QLineEdit(layoutWidget3);
        lineEdit_Richtung->setObjectName("lineEdit_Richtung");

        gridLayout_3->addWidget(lineEdit_Richtung, 2, 1, 1, 1);

        tabWidget->addTab(tab_Drehmaschine, QString());
        tab_AUTO_Werte = new QWidget();
        tab_AUTO_Werte->setObjectName("tab_AUTO_Werte");
        layoutWidget4 = new QWidget(tab_AUTO_Werte);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 32, 451, 201));
        gridLayout_2 = new QGridLayout(layoutWidget4);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Vorschub_XY = new QLabel(layoutWidget4);
        label_Vorschub_XY->setObjectName("label_Vorschub_XY");

        gridLayout_2->addWidget(label_Vorschub_XY, 1, 0, 1, 1);

        label_Drehzahl = new QLabel(layoutWidget4);
        label_Drehzahl->setObjectName("label_Drehzahl");

        gridLayout_2->addWidget(label_Drehzahl, 2, 0, 1, 1);

        label_Eintauchvorschub = new QLabel(layoutWidget4);
        label_Eintauchvorschub->setObjectName("label_Eintauchvorschub");

        gridLayout_2->addWidget(label_Eintauchvorschub, 0, 0, 1, 1);

        label_zustelltiefe = new QLabel(layoutWidget4);
        label_zustelltiefe->setObjectName("label_zustelltiefe");

        gridLayout_2->addWidget(label_zustelltiefe, 3, 0, 1, 1);

        lineEdit_Eintauchvorschub = new QLineEdit(layoutWidget4);
        lineEdit_Eintauchvorschub->setObjectName("lineEdit_Eintauchvorschub");

        gridLayout_2->addWidget(lineEdit_Eintauchvorschub, 0, 1, 1, 1);

        lineEdit_Drehzahl = new QLineEdit(layoutWidget4);
        lineEdit_Drehzahl->setObjectName("lineEdit_Drehzahl");

        gridLayout_2->addWidget(lineEdit_Drehzahl, 2, 1, 1, 1);

        lineEdit_zustelltiefe = new QLineEdit(layoutWidget4);
        lineEdit_zustelltiefe->setObjectName("lineEdit_zustelltiefe");

        gridLayout_2->addWidget(lineEdit_zustelltiefe, 3, 1, 1, 1);

        lineEdit_Vorschub_XY = new QLineEdit(layoutWidget4);
        lineEdit_Vorschub_XY->setObjectName("lineEdit_Vorschub_XY");

        gridLayout_2->addWidget(lineEdit_Vorschub_XY, 1, 1, 1, 1);

        label = new QLabel(tab_AUTO_Werte);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 62, 15));
        label_2 = new QLabel(tab_AUTO_Werte);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 260, 62, 15));
        line = new QFrame(tab_AUTO_Werte);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 240, 431, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        layoutWidget5 = new QWidget(tab_AUTO_Werte);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(10, 280, 451, 211));
        gridLayout_5 = new QGridLayout(layoutWidget5);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_anbohrvorschub = new QLabel(layoutWidget5);
        label_anbohrvorschub->setObjectName("label_anbohrvorschub");

        gridLayout_5->addWidget(label_anbohrvorschub, 0, 0, 1, 1);

        lineEdit_anbohrvorschub = new QLineEdit(layoutWidget5);
        lineEdit_anbohrvorschub->setObjectName("lineEdit_anbohrvorschub");

        gridLayout_5->addWidget(lineEdit_anbohrvorschub, 0, 1, 1, 1);

        label_restbohrtiefe = new QLabel(layoutWidget5);
        label_restbohrtiefe->setObjectName("label_restbohrtiefe");

        gridLayout_5->addWidget(label_restbohrtiefe, 4, 0, 1, 1);

        lineEdit_bohrvorschub = new QLineEdit(layoutWidget5);
        lineEdit_bohrvorschub->setObjectName("lineEdit_bohrvorschub");

        gridLayout_5->addWidget(lineEdit_bohrvorschub, 1, 1, 1, 1);

        label_bohrvorschub = new QLabel(layoutWidget5);
        label_bohrvorschub->setObjectName("label_bohrvorschub");

        gridLayout_5->addWidget(label_bohrvorschub, 1, 0, 1, 1);

        label_anbohrtiefe = new QLabel(layoutWidget5);
        label_anbohrtiefe->setObjectName("label_anbohrtiefe");

        gridLayout_5->addWidget(label_anbohrtiefe, 2, 0, 1, 1);

        label_bohrzustelltiefe = new QLabel(layoutWidget5);
        label_bohrzustelltiefe->setObjectName("label_bohrzustelltiefe");

        gridLayout_5->addWidget(label_bohrzustelltiefe, 3, 0, 1, 1);

        lineEdit_anbohrtiefe = new QLineEdit(layoutWidget5);
        lineEdit_anbohrtiefe->setObjectName("lineEdit_anbohrtiefe");

        gridLayout_5->addWidget(lineEdit_anbohrtiefe, 2, 1, 1, 1);

        lineEdit_bohrzustelltiefe = new QLineEdit(layoutWidget5);
        lineEdit_bohrzustelltiefe->setObjectName("lineEdit_bohrzustelltiefe");

        gridLayout_5->addWidget(lineEdit_bohrzustelltiefe, 3, 1, 1, 1);

        lineEdit_restbohrtiefe = new QLineEdit(layoutWidget5);
        lineEdit_restbohrtiefe->setObjectName("lineEdit_restbohrtiefe");

        gridLayout_5->addWidget(lineEdit_restbohrtiefe, 4, 1, 1, 1);

        tabWidget->addTab(tab_AUTO_Werte, QString());
        layoutWidget6 = new QWidget(Dialog_Werkzeug);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(10, 540, 471, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget6);
        pushButton_Abbrechen->setObjectName("pushButton_Abbrechen");

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget6);
        pushButton_Speichern->setObjectName("pushButton_Speichern");

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget6);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout->addWidget(pushButton_OK);

        QWidget::setTabOrder(tabWidget, lineEdit_Werkzeugname);
        QWidget::setTabOrder(lineEdit_Werkzeugname, lineEdit_Werkzeugnummer);
        QWidget::setTabOrder(lineEdit_Werkzeugnummer, lineEdit_Steckplatz);
        QWidget::setTabOrder(lineEdit_Steckplatz, lineEdit_Durchmesser);
        QWidget::setTabOrder(lineEdit_Durchmesser, lineEdit__Nutzlaenge);
        QWidget::setTabOrder(lineEdit__Nutzlaenge, comboBox_Drehrichtung);
        QWidget::setTabOrder(comboBox_Drehrichtung, lineEdit_Kommentar);
        QWidget::setTabOrder(lineEdit_Kommentar, checkBox_kann_bohren);
        QWidget::setTabOrder(checkBox_kann_bohren, checkBox_kann_fraesen);
        QWidget::setTabOrder(checkBox_kann_fraesen, lineEdit_Offset_X);
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
        Dialog_Werkzeug->setWindowTitle(QCoreApplication::translate("Dialog_Werkzeug", "Werkzeug", nullptr));
        label_Kommentar->setText(QCoreApplication::translate("Dialog_Werkzeug", "Kommentar", nullptr));
        label_Durchmesser->setText(QCoreApplication::translate("Dialog_Werkzeug", "Durchmesser", nullptr));
        label_Werkzeugnummer->setText(QCoreApplication::translate("Dialog_Werkzeug", "Werkzeugnummer", nullptr));
        label_Steckplatz->setText(QCoreApplication::translate("Dialog_Werkzeug", "Steckplatz", nullptr));
        label_Drehrichtung->setText(QCoreApplication::translate("Dialog_Werkzeug", "Drehrichtung", nullptr));
        label_Werkzeugname->setText(QCoreApplication::translate("Dialog_Werkzeug", "Name", nullptr));
        label_Nutzlaenge->setText(QCoreApplication::translate("Dialog_Werkzeug", "Nutzl\303\244nge", nullptr));
        label_bild->setText(QString());
        pushButton_bild_info->setText(QCoreApplication::translate("Dialog_Werkzeug", "???", nullptr));
        checkBox_kann_bohren->setText(QCoreApplication::translate("Dialog_Werkzeug", "kann bohren", nullptr));
        checkBox_kann_fraesen->setText(QCoreApplication::translate("Dialog_Werkzeug", "kann fr\303\244sen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Allgemein), QCoreApplication::translate("Dialog_Werkzeug", "Allgemeines", nullptr));
        label_Offset_X->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset X", nullptr));
        label_Offset_Y->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset Y", nullptr));
        label_Offset_Z->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset Z", nullptr));
        label_Offset_A->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset A", nullptr));
        label_Offset_B->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset B", nullptr));
        label_Offset_C->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset C", nullptr));
        label_Offset_U->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset U", nullptr));
        label_Offset_V->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset V", nullptr));
        label_Offset_W->setText(QCoreApplication::translate("Dialog_Werkzeug", "Offset W", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Offset), QCoreApplication::translate("Dialog_Werkzeug", "Offset", nullptr));
        label_Frontwinkel->setText(QCoreApplication::translate("Dialog_Werkzeug", "Frontwinkel", nullptr));
        label_Rueckwinkel->setText(QCoreApplication::translate("Dialog_Werkzeug", "R\303\274ckwinkel", nullptr));
        label_Richtung->setText(QCoreApplication::translate("Dialog_Werkzeug", "Richtung", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Drehmaschine), QCoreApplication::translate("Dialog_Werkzeug", "Drehmaschine", nullptr));
        label_Vorschub_XY->setText(QCoreApplication::translate("Dialog_Werkzeug", "Vorschub XY", nullptr));
        label_Drehzahl->setText(QCoreApplication::translate("Dialog_Werkzeug", "Drehzahl", nullptr));
        label_Eintauchvorschub->setText(QCoreApplication::translate("Dialog_Werkzeug", "Eintauchvorschub", nullptr));
        label_zustelltiefe->setText(QCoreApplication::translate("Dialog_Werkzeug", "Zustelltiefe", nullptr));
        label->setText(QCoreApplication::translate("Dialog_Werkzeug", "Fr\303\244sen:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_Werkzeug", "Bohren:", nullptr));
        label_anbohrvorschub->setText(QCoreApplication::translate("Dialog_Werkzeug", "Anbohrvorschub", nullptr));
        label_restbohrtiefe->setText(QCoreApplication::translate("Dialog_Werkzeug", "Restbohrtiefe", nullptr));
        label_bohrvorschub->setText(QCoreApplication::translate("Dialog_Werkzeug", "Bohrvorschub", nullptr));
        label_anbohrtiefe->setText(QCoreApplication::translate("Dialog_Werkzeug", "Anbohrtiefe", nullptr));
        label_bohrzustelltiefe->setText(QCoreApplication::translate("Dialog_Werkzeug", "Bohr-Zustelltiefe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_AUTO_Werte), QCoreApplication::translate("Dialog_Werkzeug", "AUTO-Werte", nullptr));
        pushButton_Abbrechen->setText(QCoreApplication::translate("Dialog_Werkzeug", "Abbrechen", nullptr));
        pushButton_Speichern->setText(QCoreApplication::translate("Dialog_Werkzeug", "Speichern", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Werkzeug", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Werkzeug: public Ui_Dialog_Werkzeug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_WERKZEUG_H
