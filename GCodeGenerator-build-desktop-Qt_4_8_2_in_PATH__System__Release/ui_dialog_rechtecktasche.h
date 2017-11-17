/********************************************************************************
** Form generated from reading UI file 'dialog_rechtecktasche.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_RECHTECKTASCHE_H
#define UI_DIALOG_RECHTECKTASCHE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Rechtecktasche
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_allgemein;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_Werkzeug_var;
    QComboBox *comboBox_Werkzeug;
    QLabel *label_posY;
    QLabel *label_breite;
    QLabel *label_posX;
    QLabel *label_Werkzeug;
    QLabel *label_tiefe;
    QLabel *label_Zustellung;
    QLabel *label_laenge;
    QLabel *label_radius;
    QLabel *label_Gegenlauf;
    QLabel *label_posX_var;
    QLabel *label_posY_var;
    QLabel *label_laenge_var;
    QLabel *label_breite_var;
    QLabel *label_tiefe_var;
    QLabel *label_radius_var;
    QLabel *label_Zustellung_var;
    QLabel *label_Gegenlauf_var;
    QLineEdit *lineEdit_posX;
    QLineEdit *lineEdit_posY;
    QLineEdit *lineEdit_laenge;
    QLineEdit *lineEdit_breite;
    QLineEdit *lineEdit_tiefe;
    QLineEdit *lineEdit_radius;
    QLineEdit *lineEdit_Zustellung;
    QLineEdit *lineEdit_Gegenlauf;
    QWidget *tab_Bezugspunkt;
    QRadioButton *radioButton_oben_links;
    QRadioButton *radioButton_oben_rechts;
    QRadioButton *radioButton_mitte;
    QRadioButton *radioButton_unten_links;
    QRadioButton *radioButton_unten_rechts;
    QLabel *label;
    QRadioButton *radioButton_links;
    QRadioButton *radioButton_unten;
    QRadioButton *radioButton_oben;
    QRadioButton *radioButton_rechts;
    QWidget *tab_Technologie;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_Drehzahl_var;
    QLabel *label_Vorschub;
    QLineEdit *lineEdit_Vorschub;
    QLabel *label_Eintauchvorschub_var;
    QLabel *label_Kommentar;
    QLabel *label_winkel;
    QLabel *label_ausraeumen_var;
    QLabel *label_ausraeumen;
    QLineEdit *lineEdit_Eintauchvorschub;
    QLabel *label_Kommentar_var;
    QLineEdit *lineEdit_Kommentar;
    QLabel *label_winkel_var;
    QLineEdit *lineEdit_Ausfuehrbedingung;
    QLineEdit *lineEdit_Drehzahl;
    QLabel *label_Ausfuehrbedingung;
    QLineEdit *lineEdit_ausraeumen;
    QLineEdit *lineEdit_winkel;
    QLabel *label_Eintauchvorschub;
    QLabel *label_Vorschub_var;
    QLabel *label_Drehzahl;
    QLabel *label_Ausfuehrbedingung_var;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label__bezeichnung_var;
    QLabel *label_bezeichnung;
    QWidget *tab_Werkzeug;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_wkz_Kommentar;
    QLabel *label_wkz_Nutzlaenge;
    QLabel *label_wkz_Nummer_wert;
    QFrame *line;
    QLabel *label_wkz_Durchmesser;
    QLabel *label_wkz_Name;
    QLabel *label_wkz_Drehrichtung;
    QLabel *label_wkz_Nummer;
    QLabel *label_40;
    QLabel *label_wkz_Eintauschvorschub;
    QLabel *label_wkz_Vorschub_XY;
    QLabel *label_wkz_Drehzahl;
    QLabel *label_wkz_Name_wert;
    QLabel *label_wkz_Drehrichtung_wert;
    QLabel *label_wkz_Durchmesser_wert;
    QLabel *label_wkz_Nutzlaenge_wert;
    QLabel *label_wkz_Kommentar_wert;
    QLabel *label_49;
    QLabel *label_wkz_Eintauschvorschub_wert;
    QLabel *label_wkz_Vorschub_XY_wert;
    QLabel *label_wkz_Drehzahl_wert;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_Speichern;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Rechtecktasche)
    {
        if (Dialog_Rechtecktasche->objectName().isEmpty())
            Dialog_Rechtecktasche->setObjectName(QString::fromUtf8("Dialog_Rechtecktasche"));
        Dialog_Rechtecktasche->resize(660, 563);
        Dialog_Rechtecktasche->setModal(true);
        tabWidget = new QTabWidget(Dialog_Rechtecktasche);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 641, 501));
        tab_allgemein = new QWidget();
        tab_allgemein->setObjectName(QString::fromUtf8("tab_allgemein"));
        layoutWidget = new QWidget(tab_allgemein);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 601, 451));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_Werkzeug_var = new QLabel(layoutWidget);
        label_Werkzeug_var->setObjectName(QString::fromUtf8("label_Werkzeug_var"));
        label_Werkzeug_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Werkzeug_var, 0, 1, 1, 1);

        comboBox_Werkzeug = new QComboBox(layoutWidget);
        comboBox_Werkzeug->setObjectName(QString::fromUtf8("comboBox_Werkzeug"));

        gridLayout->addWidget(comboBox_Werkzeug, 0, 2, 1, 1);

        label_posY = new QLabel(layoutWidget);
        label_posY->setObjectName(QString::fromUtf8("label_posY"));

        gridLayout->addWidget(label_posY, 2, 0, 1, 1);

        label_breite = new QLabel(layoutWidget);
        label_breite->setObjectName(QString::fromUtf8("label_breite"));

        gridLayout->addWidget(label_breite, 4, 0, 1, 1);

        label_posX = new QLabel(layoutWidget);
        label_posX->setObjectName(QString::fromUtf8("label_posX"));

        gridLayout->addWidget(label_posX, 1, 0, 1, 1);

        label_Werkzeug = new QLabel(layoutWidget);
        label_Werkzeug->setObjectName(QString::fromUtf8("label_Werkzeug"));

        gridLayout->addWidget(label_Werkzeug, 0, 0, 1, 1);

        label_tiefe = new QLabel(layoutWidget);
        label_tiefe->setObjectName(QString::fromUtf8("label_tiefe"));

        gridLayout->addWidget(label_tiefe, 5, 0, 1, 1);

        label_Zustellung = new QLabel(layoutWidget);
        label_Zustellung->setObjectName(QString::fromUtf8("label_Zustellung"));

        gridLayout->addWidget(label_Zustellung, 7, 0, 1, 1);

        label_laenge = new QLabel(layoutWidget);
        label_laenge->setObjectName(QString::fromUtf8("label_laenge"));

        gridLayout->addWidget(label_laenge, 3, 0, 1, 1);

        label_radius = new QLabel(layoutWidget);
        label_radius->setObjectName(QString::fromUtf8("label_radius"));

        gridLayout->addWidget(label_radius, 6, 0, 1, 1);

        label_Gegenlauf = new QLabel(layoutWidget);
        label_Gegenlauf->setObjectName(QString::fromUtf8("label_Gegenlauf"));

        gridLayout->addWidget(label_Gegenlauf, 8, 0, 1, 1);

        label_posX_var = new QLabel(layoutWidget);
        label_posX_var->setObjectName(QString::fromUtf8("label_posX_var"));
        label_posX_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posX_var, 1, 1, 1, 1);

        label_posY_var = new QLabel(layoutWidget);
        label_posY_var->setObjectName(QString::fromUtf8("label_posY_var"));
        label_posY_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posY_var, 2, 1, 1, 1);

        label_laenge_var = new QLabel(layoutWidget);
        label_laenge_var->setObjectName(QString::fromUtf8("label_laenge_var"));
        label_laenge_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_laenge_var, 3, 1, 1, 1);

        label_breite_var = new QLabel(layoutWidget);
        label_breite_var->setObjectName(QString::fromUtf8("label_breite_var"));
        label_breite_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_breite_var, 4, 1, 1, 1);

        label_tiefe_var = new QLabel(layoutWidget);
        label_tiefe_var->setObjectName(QString::fromUtf8("label_tiefe_var"));
        label_tiefe_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_tiefe_var, 5, 1, 1, 1);

        label_radius_var = new QLabel(layoutWidget);
        label_radius_var->setObjectName(QString::fromUtf8("label_radius_var"));
        label_radius_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_radius_var, 6, 1, 1, 1);

        label_Zustellung_var = new QLabel(layoutWidget);
        label_Zustellung_var->setObjectName(QString::fromUtf8("label_Zustellung_var"));
        label_Zustellung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Zustellung_var, 7, 1, 1, 1);

        label_Gegenlauf_var = new QLabel(layoutWidget);
        label_Gegenlauf_var->setObjectName(QString::fromUtf8("label_Gegenlauf_var"));
        label_Gegenlauf_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Gegenlauf_var, 8, 1, 1, 1);

        lineEdit_posX = new QLineEdit(layoutWidget);
        lineEdit_posX->setObjectName(QString::fromUtf8("lineEdit_posX"));

        gridLayout->addWidget(lineEdit_posX, 1, 2, 1, 1);

        lineEdit_posY = new QLineEdit(layoutWidget);
        lineEdit_posY->setObjectName(QString::fromUtf8("lineEdit_posY"));

        gridLayout->addWidget(lineEdit_posY, 2, 2, 1, 1);

        lineEdit_laenge = new QLineEdit(layoutWidget);
        lineEdit_laenge->setObjectName(QString::fromUtf8("lineEdit_laenge"));

        gridLayout->addWidget(lineEdit_laenge, 3, 2, 1, 1);

        lineEdit_breite = new QLineEdit(layoutWidget);
        lineEdit_breite->setObjectName(QString::fromUtf8("lineEdit_breite"));

        gridLayout->addWidget(lineEdit_breite, 4, 2, 1, 1);

        lineEdit_tiefe = new QLineEdit(layoutWidget);
        lineEdit_tiefe->setObjectName(QString::fromUtf8("lineEdit_tiefe"));

        gridLayout->addWidget(lineEdit_tiefe, 5, 2, 1, 1);

        lineEdit_radius = new QLineEdit(layoutWidget);
        lineEdit_radius->setObjectName(QString::fromUtf8("lineEdit_radius"));

        gridLayout->addWidget(lineEdit_radius, 6, 2, 1, 1);

        lineEdit_Zustellung = new QLineEdit(layoutWidget);
        lineEdit_Zustellung->setObjectName(QString::fromUtf8("lineEdit_Zustellung"));

        gridLayout->addWidget(lineEdit_Zustellung, 7, 2, 1, 1);

        lineEdit_Gegenlauf = new QLineEdit(layoutWidget);
        lineEdit_Gegenlauf->setObjectName(QString::fromUtf8("lineEdit_Gegenlauf"));

        gridLayout->addWidget(lineEdit_Gegenlauf, 8, 2, 1, 1);

        tabWidget->addTab(tab_allgemein, QString());
        tab_Bezugspunkt = new QWidget();
        tab_Bezugspunkt->setObjectName(QString::fromUtf8("tab_Bezugspunkt"));
        radioButton_oben_links = new QRadioButton(tab_Bezugspunkt);
        radioButton_oben_links->setObjectName(QString::fromUtf8("radioButton_oben_links"));
        radioButton_oben_links->setGeometry(QRect(30, 50, 107, 20));
        radioButton_oben_rechts = new QRadioButton(tab_Bezugspunkt);
        radioButton_oben_rechts->setObjectName(QString::fromUtf8("radioButton_oben_rechts"));
        radioButton_oben_rechts->setGeometry(QRect(480, 50, 107, 20));
        radioButton_mitte = new QRadioButton(tab_Bezugspunkt);
        radioButton_mitte->setObjectName(QString::fromUtf8("radioButton_mitte"));
        radioButton_mitte->setGeometry(QRect(260, 220, 107, 20));
        radioButton_unten_links = new QRadioButton(tab_Bezugspunkt);
        radioButton_unten_links->setObjectName(QString::fromUtf8("radioButton_unten_links"));
        radioButton_unten_links->setGeometry(QRect(30, 400, 107, 20));
        radioButton_unten_rechts = new QRadioButton(tab_Bezugspunkt);
        radioButton_unten_rechts->setObjectName(QString::fromUtf8("radioButton_unten_rechts"));
        radioButton_unten_rechts->setGeometry(QRect(480, 400, 107, 20));
        label = new QLabel(tab_Bezugspunkt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 571, 16));
        radioButton_links = new QRadioButton(tab_Bezugspunkt);
        radioButton_links->setObjectName(QString::fromUtf8("radioButton_links"));
        radioButton_links->setGeometry(QRect(40, 220, 107, 20));
        radioButton_unten = new QRadioButton(tab_Bezugspunkt);
        radioButton_unten->setObjectName(QString::fromUtf8("radioButton_unten"));
        radioButton_unten->setGeometry(QRect(260, 400, 107, 20));
        radioButton_oben = new QRadioButton(tab_Bezugspunkt);
        radioButton_oben->setObjectName(QString::fromUtf8("radioButton_oben"));
        radioButton_oben->setGeometry(QRect(260, 40, 107, 20));
        radioButton_rechts = new QRadioButton(tab_Bezugspunkt);
        radioButton_rechts->setObjectName(QString::fromUtf8("radioButton_rechts"));
        radioButton_rechts->setGeometry(QRect(480, 220, 107, 20));
        tabWidget->addTab(tab_Bezugspunkt, QString());
        tab_Technologie = new QWidget();
        tab_Technologie->setObjectName(QString::fromUtf8("tab_Technologie"));
        layoutWidget1 = new QWidget(tab_Technologie);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 601, 451));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Drehzahl_var = new QLabel(layoutWidget1);
        label_Drehzahl_var->setObjectName(QString::fromUtf8("label_Drehzahl_var"));
        label_Drehzahl_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Drehzahl_var, 4, 1, 1, 1);

        label_Vorschub = new QLabel(layoutWidget1);
        label_Vorschub->setObjectName(QString::fromUtf8("label_Vorschub"));

        gridLayout_2->addWidget(label_Vorschub, 3, 0, 1, 1);

        lineEdit_Vorschub = new QLineEdit(layoutWidget1);
        lineEdit_Vorschub->setObjectName(QString::fromUtf8("lineEdit_Vorschub"));

        gridLayout_2->addWidget(lineEdit_Vorschub, 3, 2, 1, 1);

        label_Eintauchvorschub_var = new QLabel(layoutWidget1);
        label_Eintauchvorschub_var->setObjectName(QString::fromUtf8("label_Eintauchvorschub_var"));
        label_Eintauchvorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Eintauchvorschub_var, 2, 1, 1, 1);

        label_Kommentar = new QLabel(layoutWidget1);
        label_Kommentar->setObjectName(QString::fromUtf8("label_Kommentar"));

        gridLayout_2->addWidget(label_Kommentar, 5, 0, 1, 1);

        label_winkel = new QLabel(layoutWidget1);
        label_winkel->setObjectName(QString::fromUtf8("label_winkel"));

        gridLayout_2->addWidget(label_winkel, 0, 0, 1, 1);

        label_ausraeumen_var = new QLabel(layoutWidget1);
        label_ausraeumen_var->setObjectName(QString::fromUtf8("label_ausraeumen_var"));
        label_ausraeumen_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_ausraeumen_var, 1, 1, 1, 1);

        label_ausraeumen = new QLabel(layoutWidget1);
        label_ausraeumen->setObjectName(QString::fromUtf8("label_ausraeumen"));

        gridLayout_2->addWidget(label_ausraeumen, 1, 0, 1, 1);

        lineEdit_Eintauchvorschub = new QLineEdit(layoutWidget1);
        lineEdit_Eintauchvorschub->setObjectName(QString::fromUtf8("lineEdit_Eintauchvorschub"));

        gridLayout_2->addWidget(lineEdit_Eintauchvorschub, 2, 2, 1, 1);

        label_Kommentar_var = new QLabel(layoutWidget1);
        label_Kommentar_var->setObjectName(QString::fromUtf8("label_Kommentar_var"));
        label_Kommentar_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Kommentar_var, 5, 1, 1, 1);

        lineEdit_Kommentar = new QLineEdit(layoutWidget1);
        lineEdit_Kommentar->setObjectName(QString::fromUtf8("lineEdit_Kommentar"));

        gridLayout_2->addWidget(lineEdit_Kommentar, 5, 2, 1, 1);

        label_winkel_var = new QLabel(layoutWidget1);
        label_winkel_var->setObjectName(QString::fromUtf8("label_winkel_var"));
        label_winkel_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_winkel_var, 0, 1, 1, 1);

        lineEdit_Ausfuehrbedingung = new QLineEdit(layoutWidget1);
        lineEdit_Ausfuehrbedingung->setObjectName(QString::fromUtf8("lineEdit_Ausfuehrbedingung"));

        gridLayout_2->addWidget(lineEdit_Ausfuehrbedingung, 7, 2, 1, 1);

        lineEdit_Drehzahl = new QLineEdit(layoutWidget1);
        lineEdit_Drehzahl->setObjectName(QString::fromUtf8("lineEdit_Drehzahl"));

        gridLayout_2->addWidget(lineEdit_Drehzahl, 4, 2, 1, 1);

        label_Ausfuehrbedingung = new QLabel(layoutWidget1);
        label_Ausfuehrbedingung->setObjectName(QString::fromUtf8("label_Ausfuehrbedingung"));

        gridLayout_2->addWidget(label_Ausfuehrbedingung, 7, 0, 1, 1);

        lineEdit_ausraeumen = new QLineEdit(layoutWidget1);
        lineEdit_ausraeumen->setObjectName(QString::fromUtf8("lineEdit_ausraeumen"));

        gridLayout_2->addWidget(lineEdit_ausraeumen, 1, 2, 1, 1);

        lineEdit_winkel = new QLineEdit(layoutWidget1);
        lineEdit_winkel->setObjectName(QString::fromUtf8("lineEdit_winkel"));

        gridLayout_2->addWidget(lineEdit_winkel, 0, 2, 1, 1);

        label_Eintauchvorschub = new QLabel(layoutWidget1);
        label_Eintauchvorschub->setObjectName(QString::fromUtf8("label_Eintauchvorschub"));

        gridLayout_2->addWidget(label_Eintauchvorschub, 2, 0, 1, 1);

        label_Vorschub_var = new QLabel(layoutWidget1);
        label_Vorschub_var->setObjectName(QString::fromUtf8("label_Vorschub_var"));
        label_Vorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Vorschub_var, 3, 1, 1, 1);

        label_Drehzahl = new QLabel(layoutWidget1);
        label_Drehzahl->setObjectName(QString::fromUtf8("label_Drehzahl"));

        gridLayout_2->addWidget(label_Drehzahl, 4, 0, 1, 1);

        label_Ausfuehrbedingung_var = new QLabel(layoutWidget1);
        label_Ausfuehrbedingung_var->setObjectName(QString::fromUtf8("label_Ausfuehrbedingung_var"));
        label_Ausfuehrbedingung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_Ausfuehrbedingung_var, 7, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget1);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout_2->addWidget(lineEdit_bezeichnung, 6, 2, 1, 1);

        label__bezeichnung_var = new QLabel(layoutWidget1);
        label__bezeichnung_var->setObjectName(QString::fromUtf8("label__bezeichnung_var"));

        gridLayout_2->addWidget(label__bezeichnung_var, 6, 1, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget1);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout_2->addWidget(label_bezeichnung, 6, 0, 1, 1);

        tabWidget->addTab(tab_Technologie, QString());
        tab_Werkzeug = new QWidget();
        tab_Werkzeug->setObjectName(QString::fromUtf8("tab_Werkzeug"));
        layoutWidget2 = new QWidget(tab_Werkzeug);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 601, 451));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_wkz_Kommentar = new QLabel(layoutWidget2);
        label_wkz_Kommentar->setObjectName(QString::fromUtf8("label_wkz_Kommentar"));

        gridLayout_3->addWidget(label_wkz_Kommentar, 5, 0, 1, 1);

        label_wkz_Nutzlaenge = new QLabel(layoutWidget2);
        label_wkz_Nutzlaenge->setObjectName(QString::fromUtf8("label_wkz_Nutzlaenge"));

        gridLayout_3->addWidget(label_wkz_Nutzlaenge, 4, 0, 1, 1);

        label_wkz_Nummer_wert = new QLabel(layoutWidget2);
        label_wkz_Nummer_wert->setObjectName(QString::fromUtf8("label_wkz_Nummer_wert"));

        gridLayout_3->addWidget(label_wkz_Nummer_wert, 0, 1, 1, 1);

        line = new QFrame(layoutWidget2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 6, 0, 1, 2);

        label_wkz_Durchmesser = new QLabel(layoutWidget2);
        label_wkz_Durchmesser->setObjectName(QString::fromUtf8("label_wkz_Durchmesser"));

        gridLayout_3->addWidget(label_wkz_Durchmesser, 3, 0, 1, 1);

        label_wkz_Name = new QLabel(layoutWidget2);
        label_wkz_Name->setObjectName(QString::fromUtf8("label_wkz_Name"));

        gridLayout_3->addWidget(label_wkz_Name, 1, 0, 1, 1);

        label_wkz_Drehrichtung = new QLabel(layoutWidget2);
        label_wkz_Drehrichtung->setObjectName(QString::fromUtf8("label_wkz_Drehrichtung"));

        gridLayout_3->addWidget(label_wkz_Drehrichtung, 2, 0, 1, 1);

        label_wkz_Nummer = new QLabel(layoutWidget2);
        label_wkz_Nummer->setObjectName(QString::fromUtf8("label_wkz_Nummer"));

        gridLayout_3->addWidget(label_wkz_Nummer, 0, 0, 1, 1);

        label_40 = new QLabel(layoutWidget2);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_3->addWidget(label_40, 7, 0, 1, 1);

        label_wkz_Eintauschvorschub = new QLabel(layoutWidget2);
        label_wkz_Eintauschvorschub->setObjectName(QString::fromUtf8("label_wkz_Eintauschvorschub"));

        gridLayout_3->addWidget(label_wkz_Eintauschvorschub, 8, 0, 1, 1);

        label_wkz_Vorschub_XY = new QLabel(layoutWidget2);
        label_wkz_Vorschub_XY->setObjectName(QString::fromUtf8("label_wkz_Vorschub_XY"));

        gridLayout_3->addWidget(label_wkz_Vorschub_XY, 9, 0, 1, 1);

        label_wkz_Drehzahl = new QLabel(layoutWidget2);
        label_wkz_Drehzahl->setObjectName(QString::fromUtf8("label_wkz_Drehzahl"));

        gridLayout_3->addWidget(label_wkz_Drehzahl, 10, 0, 1, 1);

        label_wkz_Name_wert = new QLabel(layoutWidget2);
        label_wkz_Name_wert->setObjectName(QString::fromUtf8("label_wkz_Name_wert"));

        gridLayout_3->addWidget(label_wkz_Name_wert, 1, 1, 1, 1);

        label_wkz_Drehrichtung_wert = new QLabel(layoutWidget2);
        label_wkz_Drehrichtung_wert->setObjectName(QString::fromUtf8("label_wkz_Drehrichtung_wert"));

        gridLayout_3->addWidget(label_wkz_Drehrichtung_wert, 2, 1, 1, 1);

        label_wkz_Durchmesser_wert = new QLabel(layoutWidget2);
        label_wkz_Durchmesser_wert->setObjectName(QString::fromUtf8("label_wkz_Durchmesser_wert"));

        gridLayout_3->addWidget(label_wkz_Durchmesser_wert, 3, 1, 1, 1);

        label_wkz_Nutzlaenge_wert = new QLabel(layoutWidget2);
        label_wkz_Nutzlaenge_wert->setObjectName(QString::fromUtf8("label_wkz_Nutzlaenge_wert"));

        gridLayout_3->addWidget(label_wkz_Nutzlaenge_wert, 4, 1, 1, 1);

        label_wkz_Kommentar_wert = new QLabel(layoutWidget2);
        label_wkz_Kommentar_wert->setObjectName(QString::fromUtf8("label_wkz_Kommentar_wert"));

        gridLayout_3->addWidget(label_wkz_Kommentar_wert, 5, 1, 1, 1);

        label_49 = new QLabel(layoutWidget2);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_3->addWidget(label_49, 7, 1, 1, 1);

        label_wkz_Eintauschvorschub_wert = new QLabel(layoutWidget2);
        label_wkz_Eintauschvorschub_wert->setObjectName(QString::fromUtf8("label_wkz_Eintauschvorschub_wert"));

        gridLayout_3->addWidget(label_wkz_Eintauschvorschub_wert, 8, 1, 1, 1);

        label_wkz_Vorschub_XY_wert = new QLabel(layoutWidget2);
        label_wkz_Vorschub_XY_wert->setObjectName(QString::fromUtf8("label_wkz_Vorschub_XY_wert"));

        gridLayout_3->addWidget(label_wkz_Vorschub_XY_wert, 9, 1, 1, 1);

        label_wkz_Drehzahl_wert = new QLabel(layoutWidget2);
        label_wkz_Drehzahl_wert->setObjectName(QString::fromUtf8("label_wkz_Drehzahl_wert"));

        gridLayout_3->addWidget(label_wkz_Drehzahl_wert, 10, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 3);
        tabWidget->addTab(tab_Werkzeug, QString());
        layoutWidget3 = new QWidget(Dialog_Rechtecktasche);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(180, 520, 441, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget3);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget3);
        pushButton_Speichern->setObjectName(QString::fromUtf8("pushButton_Speichern"));

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget3);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        QWidget::setTabOrder(comboBox_Werkzeug, lineEdit_posX);
        QWidget::setTabOrder(lineEdit_posX, lineEdit_posY);
        QWidget::setTabOrder(lineEdit_posY, lineEdit_laenge);
        QWidget::setTabOrder(lineEdit_laenge, lineEdit_breite);
        QWidget::setTabOrder(lineEdit_breite, lineEdit_tiefe);
        QWidget::setTabOrder(lineEdit_tiefe, lineEdit_radius);
        QWidget::setTabOrder(lineEdit_radius, lineEdit_Zustellung);
        QWidget::setTabOrder(lineEdit_Zustellung, lineEdit_Gegenlauf);
        QWidget::setTabOrder(lineEdit_Gegenlauf, lineEdit_winkel);
        QWidget::setTabOrder(lineEdit_winkel, lineEdit_ausraeumen);
        QWidget::setTabOrder(lineEdit_ausraeumen, lineEdit_Eintauchvorschub);
        QWidget::setTabOrder(lineEdit_Eintauchvorschub, lineEdit_Vorschub);
        QWidget::setTabOrder(lineEdit_Vorschub, lineEdit_Drehzahl);
        QWidget::setTabOrder(lineEdit_Drehzahl, lineEdit_Kommentar);
        QWidget::setTabOrder(lineEdit_Kommentar, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_Ausfuehrbedingung);
        QWidget::setTabOrder(lineEdit_Ausfuehrbedingung, tabWidget);
        QWidget::setTabOrder(tabWidget, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_Speichern);
        QWidget::setTabOrder(pushButton_Speichern, pushButton_OK);
        QWidget::setTabOrder(pushButton_OK, radioButton_oben_links);
        QWidget::setTabOrder(radioButton_oben_links, radioButton_oben_rechts);
        QWidget::setTabOrder(radioButton_oben_rechts, radioButton_mitte);
        QWidget::setTabOrder(radioButton_mitte, radioButton_unten_links);
        QWidget::setTabOrder(radioButton_unten_links, radioButton_unten_rechts);

        retranslateUi(Dialog_Rechtecktasche);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog_Rechtecktasche);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Rechtecktasche)
    {
        Dialog_Rechtecktasche->setWindowTitle(QApplication::translate("Dialog_Rechtecktasche", "Rechtecktasche", 0, QApplication::UnicodeUTF8));
        label_Werkzeug_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[WKZ]", 0, QApplication::UnicodeUTF8));
        label_posY->setText(QApplication::translate("Dialog_Rechtecktasche", "Bezugspunkt Y", 0, QApplication::UnicodeUTF8));
        label_breite->setText(QApplication::translate("Dialog_Rechtecktasche", "Taschenbreite", 0, QApplication::UnicodeUTF8));
        label_posX->setText(QApplication::translate("Dialog_Rechtecktasche", "Bezugspunkt X", 0, QApplication::UnicodeUTF8));
        label_Werkzeug->setText(QApplication::translate("Dialog_Rechtecktasche", "Werkzeug", 0, QApplication::UnicodeUTF8));
        label_tiefe->setText(QApplication::translate("Dialog_Rechtecktasche", "Taschentiefe", 0, QApplication::UnicodeUTF8));
        label_Zustellung->setText(QApplication::translate("Dialog_Rechtecktasche", "Zustellma\303\237", 0, QApplication::UnicodeUTF8));
        label_laenge->setText(QApplication::translate("Dialog_Rechtecktasche", "Taschenl\303\244nge", 0, QApplication::UnicodeUTF8));
        label_radius->setText(QApplication::translate("Dialog_Rechtecktasche", "Eckenradius", 0, QApplication::UnicodeUTF8));
        label_Gegenlauf->setText(QApplication::translate("Dialog_Rechtecktasche", "Gegenlauf", 0, QApplication::UnicodeUTF8));
        label_posX_var->setText(QApplication::translate("Dialog_Rechtecktasche", "*[X]", 0, QApplication::UnicodeUTF8));
        label_posY_var->setText(QApplication::translate("Dialog_Rechtecktasche", "*[Y]", 0, QApplication::UnicodeUTF8));
        label_laenge_var->setText(QApplication::translate("Dialog_Rechtecktasche", "*[TL]", 0, QApplication::UnicodeUTF8));
        label_breite_var->setText(QApplication::translate("Dialog_Rechtecktasche", "*[TB]", 0, QApplication::UnicodeUTF8));
        label_tiefe_var->setText(QApplication::translate("Dialog_Rechtecktasche", "*[TT]", 0, QApplication::UnicodeUTF8));
        label_radius_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[RAD]", 0, QApplication::UnicodeUTF8));
        label_Zustellung_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[ZUST]", 0, QApplication::UnicodeUTF8));
        label_Gegenlauf_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[GEGL]", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_allgemein), QApplication::translate("Dialog_Rechtecktasche", "allgemein", 0, QApplication::UnicodeUTF8));
        radioButton_oben_links->setText(QApplication::translate("Dialog_Rechtecktasche", "oben links", 0, QApplication::UnicodeUTF8));
        radioButton_oben_rechts->setText(QApplication::translate("Dialog_Rechtecktasche", "oben rechts", 0, QApplication::UnicodeUTF8));
        radioButton_mitte->setText(QApplication::translate("Dialog_Rechtecktasche", "mitte", 0, QApplication::UnicodeUTF8));
        radioButton_unten_links->setText(QApplication::translate("Dialog_Rechtecktasche", "unten links", 0, QApplication::UnicodeUTF8));
        radioButton_unten_rechts->setText(QApplication::translate("Dialog_Rechtecktasche", "unten rechts", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_Rechtecktasche", "Lage des Bezugspunkten / Lage des Einf\303\274gepunktes der Tasche", 0, QApplication::UnicodeUTF8));
        radioButton_links->setText(QApplication::translate("Dialog_Rechtecktasche", "links", 0, QApplication::UnicodeUTF8));
        radioButton_unten->setText(QApplication::translate("Dialog_Rechtecktasche", "unten", 0, QApplication::UnicodeUTF8));
        radioButton_oben->setText(QApplication::translate("Dialog_Rechtecktasche", "oben", 0, QApplication::UnicodeUTF8));
        radioButton_rechts->setText(QApplication::translate("Dialog_Rechtecktasche", "rechts", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Bezugspunkt), QApplication::translate("Dialog_Rechtecktasche", "Bezugspunkt", 0, QApplication::UnicodeUTF8));
        label_Drehzahl_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[N]", 0, QApplication::UnicodeUTF8));
        label_Vorschub->setText(QApplication::translate("Dialog_Rechtecktasche", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_Eintauchvorschub_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[FAN]", 0, QApplication::UnicodeUTF8));
        label_Kommentar->setText(QApplication::translate("Dialog_Rechtecktasche", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_winkel->setText(QApplication::translate("Dialog_Rechtecktasche", "Drehwinkel", 0, QApplication::UnicodeUTF8));
        label_ausraeumen_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[AUSR]", 0, QApplication::UnicodeUTF8));
        label_ausraeumen->setText(QApplication::translate("Dialog_Rechtecktasche", "Ausr\303\244umen", 0, QApplication::UnicodeUTF8));
        label_Kommentar_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[KOM]", 0, QApplication::UnicodeUTF8));
        label_winkel_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[W]", 0, QApplication::UnicodeUTF8));
        label_Ausfuehrbedingung->setText(QApplication::translate("Dialog_Rechtecktasche", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_Eintauchvorschub->setText(QApplication::translate("Dialog_Rechtecktasche", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_Vorschub_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[F]", 0, QApplication::UnicodeUTF8));
        label_Drehzahl->setText(QApplication::translate("Dialog_Rechtecktasche", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_Ausfuehrbedingung_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[AFB]", 0, QApplication::UnicodeUTF8));
        label__bezeichnung_var->setText(QApplication::translate("Dialog_Rechtecktasche", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_Rechtecktasche", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Technologie), QApplication::translate("Dialog_Rechtecktasche", "Technologie", 0, QApplication::UnicodeUTF8));
        label_wkz_Kommentar->setText(QApplication::translate("Dialog_Rechtecktasche", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_wkz_Nutzlaenge->setText(QApplication::translate("Dialog_Rechtecktasche", "Nutzl\303\244nge", 0, QApplication::UnicodeUTF8));
        label_wkz_Nummer_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Durchmesser->setText(QApplication::translate("Dialog_Rechtecktasche", "Durchmesser", 0, QApplication::UnicodeUTF8));
        label_wkz_Name->setText(QApplication::translate("Dialog_Rechtecktasche", "Name", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehrichtung->setText(QApplication::translate("Dialog_Rechtecktasche", "Drehrichtung", 0, QApplication::UnicodeUTF8));
        label_wkz_Nummer->setText(QApplication::translate("Dialog_Rechtecktasche", "Nummer", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("Dialog_Rechtecktasche", "AUTO-Werte:", 0, QApplication::UnicodeUTF8));
        label_wkz_Eintauschvorschub->setText(QApplication::translate("Dialog_Rechtecktasche", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_wkz_Vorschub_XY->setText(QApplication::translate("Dialog_Rechtecktasche", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehzahl->setText(QApplication::translate("Dialog_Rechtecktasche", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_wkz_Name_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehrichtung_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Durchmesser_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Nutzlaenge_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Kommentar_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Eintauschvorschub_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Vorschub_XY_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehzahl_wert->setText(QApplication::translate("Dialog_Rechtecktasche", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Werkzeug), QApplication::translate("Dialog_Rechtecktasche", "Werkzeug", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Rechtecktasche", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_Speichern->setText(QApplication::translate("Dialog_Rechtecktasche", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Rechtecktasche", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Rechtecktasche: public Ui_Dialog_Rechtecktasche {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_RECHTECKTASCHE_H
