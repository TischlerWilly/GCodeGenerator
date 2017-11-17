/********************************************************************************
** Form generated from reading UI file 'dialog_kreistasche.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_KREISTASCHE_H
#define UI_DIALOG_KREISTASCHE_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Kreistasche
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_Speichern;
    QPushButton *pushButton_OK;
    QTabWidget *tabWidget;
    QWidget *tab_allgemein;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QComboBox *comboBox_Werkzeug;
    QLabel *label_Werkzeug_var;
    QLabel *label_Taschendurchmesser_var;
    QLabel *label_posY_var;
    QLabel *label_Taschendurchmesser;
    QLineEdit *lineEdit_Zustellung;
    QLabel *label_Zustellung;
    QLineEdit *lineEdit_posY;
    QLabel *label_Taschentiefe;
    QLineEdit *lineEdit_Taschendurchmesser;
    QLineEdit *lineEdit_Taschentiefe;
    QLineEdit *lineEdit_posX;
    QLabel *label_Gegenlauf;
    QLineEdit *lineEdit_Gegenlauf;
    QLabel *label_Werkzeug;
    QLabel *label_posX;
    QLabel *label_Gegenlauf_var;
    QLabel *label_posY;
    QLabel *label_posX_var;
    QLabel *label_Taschentiefe_var;
    QLabel *label_Zustellung_var;
    QWidget *tab_Technologie;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_Ausraeumen_var;
    QLabel *label_Vorschub;
    QLabel *label_Ausfuehbedingung;
    QLineEdit *lineEdit_Drehzahl;
    QLabel *label_Drehzahl_var;
    QLineEdit *lineEdit_Kommentar;
    QLineEdit *lineEdit_Anfahrvorschub;
    QLabel *label_Kommentar_var;
    QLineEdit *lineEdit_Vorschub;
    QLineEdit *lineEdit_Ausfuehbedingung;
    QLabel *label_Vorschub_var;
    QLabel *label_Ausfuehbedingung_var;
    QLabel *label_Kommentar;
    QLabel *label_Ausraeumen;
    QLineEdit *lineEdit_Ausraeumen;
    QLabel *label_Anfahrvorschub_var;
    QLabel *label_Anfahrvorschub;
    QLabel *label_Drehzahl;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLabel *label_bezeichnung;
    QWidget *tab_Werkzeug;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QLabel *label_wkz_Vorschub_XY;
    QLabel *label_wkz_Kommentar;
    QLabel *label_wkz_Nummer;
    QLabel *label_wkz_Vorschub_XY_wert;
    QLabel *label_wkz_Name;
    QLabel *label_wkz_Eintauschvorschub;
    QLabel *label_AUTO_Werte;
    QLabel *label_wkz_Name_wert;
    QLabel *label_wkz_Durchmesser;
    QLabel *label_wkz_Drehrichtung_wert;
    QLabel *label_wkz_Nutzlaenge;
    QLabel *label_wkz_Drehrichtung;
    QLabel *label_wkz_Eintauschvorschub_wert;
    QLabel *label_wkz_Kommentar_wert;
    QLabel *label_wkz_Drehzahl;
    QLabel *label_wkz_Nummer_wert;
    QLabel *label_wkz_Drehzahl_wert;
    QLabel *label_wkz_Durchmesser_wert;
    QLabel *label_wkz_Nutzlaenge_wert;
    QFrame *line;

    void setupUi(QDialog *Dialog_Kreistasche)
    {
        if (Dialog_Kreistasche->objectName().isEmpty())
            Dialog_Kreistasche->setObjectName(QString::fromUtf8("Dialog_Kreistasche"));
        Dialog_Kreistasche->resize(631, 563);
        layoutWidget = new QWidget(Dialog_Kreistasche);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 520, 421, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget);
        pushButton_Speichern->setObjectName(QString::fromUtf8("pushButton_Speichern"));

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        tabWidget = new QTabWidget(Dialog_Kreistasche);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 611, 501));
        tab_allgemein = new QWidget();
        tab_allgemein->setObjectName(QString::fromUtf8("tab_allgemein"));
        layoutWidget1 = new QWidget(tab_allgemein);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 601, 471));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Werkzeug = new QComboBox(layoutWidget1);
        comboBox_Werkzeug->setObjectName(QString::fromUtf8("comboBox_Werkzeug"));

        gridLayout->addWidget(comboBox_Werkzeug, 0, 2, 1, 1);

        label_Werkzeug_var = new QLabel(layoutWidget1);
        label_Werkzeug_var->setObjectName(QString::fromUtf8("label_Werkzeug_var"));
        label_Werkzeug_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Werkzeug_var, 0, 1, 1, 1);

        label_Taschendurchmesser_var = new QLabel(layoutWidget1);
        label_Taschendurchmesser_var->setObjectName(QString::fromUtf8("label_Taschendurchmesser_var"));
        label_Taschendurchmesser_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Taschendurchmesser_var, 3, 1, 1, 1);

        label_posY_var = new QLabel(layoutWidget1);
        label_posY_var->setObjectName(QString::fromUtf8("label_posY_var"));
        label_posY_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posY_var, 2, 1, 1, 1);

        label_Taschendurchmesser = new QLabel(layoutWidget1);
        label_Taschendurchmesser->setObjectName(QString::fromUtf8("label_Taschendurchmesser"));

        gridLayout->addWidget(label_Taschendurchmesser, 3, 0, 1, 1);

        lineEdit_Zustellung = new QLineEdit(layoutWidget1);
        lineEdit_Zustellung->setObjectName(QString::fromUtf8("lineEdit_Zustellung"));

        gridLayout->addWidget(lineEdit_Zustellung, 5, 2, 1, 1);

        label_Zustellung = new QLabel(layoutWidget1);
        label_Zustellung->setObjectName(QString::fromUtf8("label_Zustellung"));

        gridLayout->addWidget(label_Zustellung, 5, 0, 1, 1);

        lineEdit_posY = new QLineEdit(layoutWidget1);
        lineEdit_posY->setObjectName(QString::fromUtf8("lineEdit_posY"));

        gridLayout->addWidget(lineEdit_posY, 2, 2, 1, 1);

        label_Taschentiefe = new QLabel(layoutWidget1);
        label_Taschentiefe->setObjectName(QString::fromUtf8("label_Taschentiefe"));

        gridLayout->addWidget(label_Taschentiefe, 4, 0, 1, 1);

        lineEdit_Taschendurchmesser = new QLineEdit(layoutWidget1);
        lineEdit_Taschendurchmesser->setObjectName(QString::fromUtf8("lineEdit_Taschendurchmesser"));

        gridLayout->addWidget(lineEdit_Taschendurchmesser, 3, 2, 1, 1);

        lineEdit_Taschentiefe = new QLineEdit(layoutWidget1);
        lineEdit_Taschentiefe->setObjectName(QString::fromUtf8("lineEdit_Taschentiefe"));

        gridLayout->addWidget(lineEdit_Taschentiefe, 4, 2, 1, 1);

        lineEdit_posX = new QLineEdit(layoutWidget1);
        lineEdit_posX->setObjectName(QString::fromUtf8("lineEdit_posX"));

        gridLayout->addWidget(lineEdit_posX, 1, 2, 1, 1);

        label_Gegenlauf = new QLabel(layoutWidget1);
        label_Gegenlauf->setObjectName(QString::fromUtf8("label_Gegenlauf"));

        gridLayout->addWidget(label_Gegenlauf, 6, 0, 1, 1);

        lineEdit_Gegenlauf = new QLineEdit(layoutWidget1);
        lineEdit_Gegenlauf->setObjectName(QString::fromUtf8("lineEdit_Gegenlauf"));

        gridLayout->addWidget(lineEdit_Gegenlauf, 6, 2, 1, 1);

        label_Werkzeug = new QLabel(layoutWidget1);
        label_Werkzeug->setObjectName(QString::fromUtf8("label_Werkzeug"));

        gridLayout->addWidget(label_Werkzeug, 0, 0, 1, 1);

        label_posX = new QLabel(layoutWidget1);
        label_posX->setObjectName(QString::fromUtf8("label_posX"));

        gridLayout->addWidget(label_posX, 1, 0, 1, 1);

        label_Gegenlauf_var = new QLabel(layoutWidget1);
        label_Gegenlauf_var->setObjectName(QString::fromUtf8("label_Gegenlauf_var"));
        label_Gegenlauf_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Gegenlauf_var, 6, 1, 1, 1);

        label_posY = new QLabel(layoutWidget1);
        label_posY->setObjectName(QString::fromUtf8("label_posY"));

        gridLayout->addWidget(label_posY, 2, 0, 1, 1);

        label_posX_var = new QLabel(layoutWidget1);
        label_posX_var->setObjectName(QString::fromUtf8("label_posX_var"));
        label_posX_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posX_var, 1, 1, 1, 1);

        label_Taschentiefe_var = new QLabel(layoutWidget1);
        label_Taschentiefe_var->setObjectName(QString::fromUtf8("label_Taschentiefe_var"));
        label_Taschentiefe_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Taschentiefe_var, 4, 1, 1, 1);

        label_Zustellung_var = new QLabel(layoutWidget1);
        label_Zustellung_var->setObjectName(QString::fromUtf8("label_Zustellung_var"));
        label_Zustellung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Zustellung_var, 5, 1, 1, 1);

        tabWidget->addTab(tab_allgemein, QString());
        tab_Technologie = new QWidget();
        tab_Technologie->setObjectName(QString::fromUtf8("tab_Technologie"));
        layoutWidget2 = new QWidget(tab_Technologie);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 591, 451));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Ausraeumen_var = new QLabel(layoutWidget2);
        label_Ausraeumen_var->setObjectName(QString::fromUtf8("label_Ausraeumen_var"));
        label_Ausraeumen_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Ausraeumen_var, 0, 1, 1, 1);

        label_Vorschub = new QLabel(layoutWidget2);
        label_Vorschub->setObjectName(QString::fromUtf8("label_Vorschub"));

        gridLayout_3->addWidget(label_Vorschub, 2, 0, 1, 1);

        label_Ausfuehbedingung = new QLabel(layoutWidget2);
        label_Ausfuehbedingung->setObjectName(QString::fromUtf8("label_Ausfuehbedingung"));

        gridLayout_3->addWidget(label_Ausfuehbedingung, 6, 0, 1, 1);

        lineEdit_Drehzahl = new QLineEdit(layoutWidget2);
        lineEdit_Drehzahl->setObjectName(QString::fromUtf8("lineEdit_Drehzahl"));

        gridLayout_3->addWidget(lineEdit_Drehzahl, 3, 2, 1, 1);

        label_Drehzahl_var = new QLabel(layoutWidget2);
        label_Drehzahl_var->setObjectName(QString::fromUtf8("label_Drehzahl_var"));
        label_Drehzahl_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Drehzahl_var, 3, 1, 1, 1);

        lineEdit_Kommentar = new QLineEdit(layoutWidget2);
        lineEdit_Kommentar->setObjectName(QString::fromUtf8("lineEdit_Kommentar"));

        gridLayout_3->addWidget(lineEdit_Kommentar, 4, 2, 1, 1);

        lineEdit_Anfahrvorschub = new QLineEdit(layoutWidget2);
        lineEdit_Anfahrvorschub->setObjectName(QString::fromUtf8("lineEdit_Anfahrvorschub"));

        gridLayout_3->addWidget(lineEdit_Anfahrvorschub, 1, 2, 1, 1);

        label_Kommentar_var = new QLabel(layoutWidget2);
        label_Kommentar_var->setObjectName(QString::fromUtf8("label_Kommentar_var"));
        label_Kommentar_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Kommentar_var, 4, 1, 1, 1);

        lineEdit_Vorschub = new QLineEdit(layoutWidget2);
        lineEdit_Vorschub->setObjectName(QString::fromUtf8("lineEdit_Vorschub"));

        gridLayout_3->addWidget(lineEdit_Vorschub, 2, 2, 1, 1);

        lineEdit_Ausfuehbedingung = new QLineEdit(layoutWidget2);
        lineEdit_Ausfuehbedingung->setObjectName(QString::fromUtf8("lineEdit_Ausfuehbedingung"));

        gridLayout_3->addWidget(lineEdit_Ausfuehbedingung, 6, 2, 1, 1);

        label_Vorschub_var = new QLabel(layoutWidget2);
        label_Vorschub_var->setObjectName(QString::fromUtf8("label_Vorschub_var"));
        label_Vorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Vorschub_var, 2, 1, 1, 1);

        label_Ausfuehbedingung_var = new QLabel(layoutWidget2);
        label_Ausfuehbedingung_var->setObjectName(QString::fromUtf8("label_Ausfuehbedingung_var"));
        label_Ausfuehbedingung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Ausfuehbedingung_var, 6, 1, 1, 1);

        label_Kommentar = new QLabel(layoutWidget2);
        label_Kommentar->setObjectName(QString::fromUtf8("label_Kommentar"));

        gridLayout_3->addWidget(label_Kommentar, 4, 0, 1, 1);

        label_Ausraeumen = new QLabel(layoutWidget2);
        label_Ausraeumen->setObjectName(QString::fromUtf8("label_Ausraeumen"));

        gridLayout_3->addWidget(label_Ausraeumen, 0, 0, 1, 1);

        lineEdit_Ausraeumen = new QLineEdit(layoutWidget2);
        lineEdit_Ausraeumen->setObjectName(QString::fromUtf8("lineEdit_Ausraeumen"));

        gridLayout_3->addWidget(lineEdit_Ausraeumen, 0, 2, 1, 1);

        label_Anfahrvorschub_var = new QLabel(layoutWidget2);
        label_Anfahrvorschub_var->setObjectName(QString::fromUtf8("label_Anfahrvorschub_var"));
        label_Anfahrvorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Anfahrvorschub_var, 1, 1, 1, 1);

        label_Anfahrvorschub = new QLabel(layoutWidget2);
        label_Anfahrvorschub->setObjectName(QString::fromUtf8("label_Anfahrvorschub"));

        gridLayout_3->addWidget(label_Anfahrvorschub, 1, 0, 1, 1);

        label_Drehzahl = new QLabel(layoutWidget2);
        label_Drehzahl->setObjectName(QString::fromUtf8("label_Drehzahl"));

        gridLayout_3->addWidget(label_Drehzahl, 3, 0, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget2);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout_3->addWidget(lineEdit_bezeichnung, 5, 2, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget2);
        label_bezeichnung_var->setObjectName(QString::fromUtf8("label_bezeichnung_var"));

        gridLayout_3->addWidget(label_bezeichnung_var, 5, 1, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget2);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout_3->addWidget(label_bezeichnung, 5, 0, 1, 1);

        tabWidget->addTab(tab_Technologie, QString());
        tab_Werkzeug = new QWidget();
        tab_Werkzeug->setObjectName(QString::fromUtf8("tab_Werkzeug"));
        layoutWidget3 = new QWidget(tab_Werkzeug);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 581, 451));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_wkz_Vorschub_XY = new QLabel(layoutWidget3);
        label_wkz_Vorschub_XY->setObjectName(QString::fromUtf8("label_wkz_Vorschub_XY"));

        gridLayout_2->addWidget(label_wkz_Vorschub_XY, 9, 0, 1, 1);

        label_wkz_Kommentar = new QLabel(layoutWidget3);
        label_wkz_Kommentar->setObjectName(QString::fromUtf8("label_wkz_Kommentar"));

        gridLayout_2->addWidget(label_wkz_Kommentar, 5, 0, 1, 1);

        label_wkz_Nummer = new QLabel(layoutWidget3);
        label_wkz_Nummer->setObjectName(QString::fromUtf8("label_wkz_Nummer"));

        gridLayout_2->addWidget(label_wkz_Nummer, 0, 0, 1, 1);

        label_wkz_Vorschub_XY_wert = new QLabel(layoutWidget3);
        label_wkz_Vorschub_XY_wert->setObjectName(QString::fromUtf8("label_wkz_Vorschub_XY_wert"));

        gridLayout_2->addWidget(label_wkz_Vorschub_XY_wert, 9, 1, 1, 1);

        label_wkz_Name = new QLabel(layoutWidget3);
        label_wkz_Name->setObjectName(QString::fromUtf8("label_wkz_Name"));

        gridLayout_2->addWidget(label_wkz_Name, 1, 0, 1, 1);

        label_wkz_Eintauschvorschub = new QLabel(layoutWidget3);
        label_wkz_Eintauschvorschub->setObjectName(QString::fromUtf8("label_wkz_Eintauschvorschub"));

        gridLayout_2->addWidget(label_wkz_Eintauschvorschub, 8, 0, 1, 1);

        label_AUTO_Werte = new QLabel(layoutWidget3);
        label_AUTO_Werte->setObjectName(QString::fromUtf8("label_AUTO_Werte"));

        gridLayout_2->addWidget(label_AUTO_Werte, 7, 0, 1, 1);

        label_wkz_Name_wert = new QLabel(layoutWidget3);
        label_wkz_Name_wert->setObjectName(QString::fromUtf8("label_wkz_Name_wert"));

        gridLayout_2->addWidget(label_wkz_Name_wert, 1, 1, 1, 1);

        label_wkz_Durchmesser = new QLabel(layoutWidget3);
        label_wkz_Durchmesser->setObjectName(QString::fromUtf8("label_wkz_Durchmesser"));

        gridLayout_2->addWidget(label_wkz_Durchmesser, 3, 0, 1, 1);

        label_wkz_Drehrichtung_wert = new QLabel(layoutWidget3);
        label_wkz_Drehrichtung_wert->setObjectName(QString::fromUtf8("label_wkz_Drehrichtung_wert"));

        gridLayout_2->addWidget(label_wkz_Drehrichtung_wert, 2, 1, 1, 1);

        label_wkz_Nutzlaenge = new QLabel(layoutWidget3);
        label_wkz_Nutzlaenge->setObjectName(QString::fromUtf8("label_wkz_Nutzlaenge"));

        gridLayout_2->addWidget(label_wkz_Nutzlaenge, 4, 0, 1, 1);

        label_wkz_Drehrichtung = new QLabel(layoutWidget3);
        label_wkz_Drehrichtung->setObjectName(QString::fromUtf8("label_wkz_Drehrichtung"));

        gridLayout_2->addWidget(label_wkz_Drehrichtung, 2, 0, 1, 1);

        label_wkz_Eintauschvorschub_wert = new QLabel(layoutWidget3);
        label_wkz_Eintauschvorschub_wert->setObjectName(QString::fromUtf8("label_wkz_Eintauschvorschub_wert"));

        gridLayout_2->addWidget(label_wkz_Eintauschvorschub_wert, 8, 1, 1, 1);

        label_wkz_Kommentar_wert = new QLabel(layoutWidget3);
        label_wkz_Kommentar_wert->setObjectName(QString::fromUtf8("label_wkz_Kommentar_wert"));

        gridLayout_2->addWidget(label_wkz_Kommentar_wert, 5, 1, 1, 1);

        label_wkz_Drehzahl = new QLabel(layoutWidget3);
        label_wkz_Drehzahl->setObjectName(QString::fromUtf8("label_wkz_Drehzahl"));

        gridLayout_2->addWidget(label_wkz_Drehzahl, 10, 0, 1, 1);

        label_wkz_Nummer_wert = new QLabel(layoutWidget3);
        label_wkz_Nummer_wert->setObjectName(QString::fromUtf8("label_wkz_Nummer_wert"));

        gridLayout_2->addWidget(label_wkz_Nummer_wert, 0, 1, 1, 1);

        label_wkz_Drehzahl_wert = new QLabel(layoutWidget3);
        label_wkz_Drehzahl_wert->setObjectName(QString::fromUtf8("label_wkz_Drehzahl_wert"));

        gridLayout_2->addWidget(label_wkz_Drehzahl_wert, 10, 1, 1, 1);

        label_wkz_Durchmesser_wert = new QLabel(layoutWidget3);
        label_wkz_Durchmesser_wert->setObjectName(QString::fromUtf8("label_wkz_Durchmesser_wert"));

        gridLayout_2->addWidget(label_wkz_Durchmesser_wert, 3, 1, 1, 1);

        label_wkz_Nutzlaenge_wert = new QLabel(layoutWidget3);
        label_wkz_Nutzlaenge_wert->setObjectName(QString::fromUtf8("label_wkz_Nutzlaenge_wert"));

        gridLayout_2->addWidget(label_wkz_Nutzlaenge_wert, 4, 1, 1, 1);

        line = new QFrame(layoutWidget3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 6, 0, 1, 2);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 3);
        tabWidget->addTab(tab_Werkzeug, QString());
        QWidget::setTabOrder(tabWidget, comboBox_Werkzeug);
        QWidget::setTabOrder(comboBox_Werkzeug, lineEdit_posX);
        QWidget::setTabOrder(lineEdit_posX, lineEdit_posY);
        QWidget::setTabOrder(lineEdit_posY, lineEdit_Taschendurchmesser);
        QWidget::setTabOrder(lineEdit_Taschendurchmesser, lineEdit_Taschentiefe);
        QWidget::setTabOrder(lineEdit_Taschentiefe, lineEdit_Zustellung);
        QWidget::setTabOrder(lineEdit_Zustellung, lineEdit_Gegenlauf);
        QWidget::setTabOrder(lineEdit_Gegenlauf, lineEdit_Ausraeumen);
        QWidget::setTabOrder(lineEdit_Ausraeumen, lineEdit_Anfahrvorschub);
        QWidget::setTabOrder(lineEdit_Anfahrvorschub, lineEdit_Vorschub);
        QWidget::setTabOrder(lineEdit_Vorschub, lineEdit_Drehzahl);
        QWidget::setTabOrder(lineEdit_Drehzahl, lineEdit_Kommentar);
        QWidget::setTabOrder(lineEdit_Kommentar, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_Ausfuehbedingung);
        QWidget::setTabOrder(lineEdit_Ausfuehbedingung, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_Speichern);
        QWidget::setTabOrder(pushButton_Speichern, pushButton_OK);

        retranslateUi(Dialog_Kreistasche);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_Kreistasche);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Kreistasche)
    {
        Dialog_Kreistasche->setWindowTitle(QApplication::translate("Dialog_Kreistasche", "Kreistasche", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Kreistasche", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_Speichern->setText(QApplication::translate("Dialog_Kreistasche", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Kreistasche", "OK", 0, QApplication::UnicodeUTF8));
        label_Werkzeug_var->setText(QApplication::translate("Dialog_Kreistasche", "[WKZ]", 0, QApplication::UnicodeUTF8));
        label_Taschendurchmesser_var->setText(QApplication::translate("Dialog_Kreistasche", "[*DM]", 0, QApplication::UnicodeUTF8));
        label_posY_var->setText(QApplication::translate("Dialog_Kreistasche", "[*Y]", 0, QApplication::UnicodeUTF8));
        label_Taschendurchmesser->setText(QApplication::translate("Dialog_Kreistasche", "Durchmesser", 0, QApplication::UnicodeUTF8));
        label_Zustellung->setText(QApplication::translate("Dialog_Kreistasche", "Zustellung", 0, QApplication::UnicodeUTF8));
        label_Taschentiefe->setText(QApplication::translate("Dialog_Kreistasche", "Tiefe", 0, QApplication::UnicodeUTF8));
        label_Gegenlauf->setText(QApplication::translate("Dialog_Kreistasche", "Gegenlauf", 0, QApplication::UnicodeUTF8));
        label_Werkzeug->setText(QApplication::translate("Dialog_Kreistasche", "Werkzeug", 0, QApplication::UnicodeUTF8));
        label_posX->setText(QApplication::translate("Dialog_Kreistasche", "Mittelpunkt X", 0, QApplication::UnicodeUTF8));
        label_Gegenlauf_var->setText(QApplication::translate("Dialog_Kreistasche", "[GEGL]", 0, QApplication::UnicodeUTF8));
        label_posY->setText(QApplication::translate("Dialog_Kreistasche", "Mittelpunkt Y", 0, QApplication::UnicodeUTF8));
        label_posX_var->setText(QApplication::translate("Dialog_Kreistasche", "[*X]", 0, QApplication::UnicodeUTF8));
        label_Taschentiefe_var->setText(QApplication::translate("Dialog_Kreistasche", "[*TT]", 0, QApplication::UnicodeUTF8));
        label_Zustellung_var->setText(QApplication::translate("Dialog_Kreistasche", "[ZUST]", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_allgemein), QApplication::translate("Dialog_Kreistasche", "allgemein", 0, QApplication::UnicodeUTF8));
        label_Ausraeumen_var->setText(QApplication::translate("Dialog_Kreistasche", "[AUSR]", 0, QApplication::UnicodeUTF8));
        label_Vorschub->setText(QApplication::translate("Dialog_Kreistasche", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_Ausfuehbedingung->setText(QApplication::translate("Dialog_Kreistasche", "Ausf\303\274hbedingung", 0, QApplication::UnicodeUTF8));
        label_Drehzahl_var->setText(QApplication::translate("Dialog_Kreistasche", "[N]", 0, QApplication::UnicodeUTF8));
        label_Kommentar_var->setText(QApplication::translate("Dialog_Kreistasche", "[KOM]", 0, QApplication::UnicodeUTF8));
        label_Vorschub_var->setText(QApplication::translate("Dialog_Kreistasche", "[F]", 0, QApplication::UnicodeUTF8));
        label_Ausfuehbedingung_var->setText(QApplication::translate("Dialog_Kreistasche", "[AFB]", 0, QApplication::UnicodeUTF8));
        label_Kommentar->setText(QApplication::translate("Dialog_Kreistasche", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_Ausraeumen->setText(QApplication::translate("Dialog_Kreistasche", "Ausr\303\244umen", 0, QApplication::UnicodeUTF8));
        label_Anfahrvorschub_var->setText(QApplication::translate("Dialog_Kreistasche", "[FAN]", 0, QApplication::UnicodeUTF8));
        label_Anfahrvorschub->setText(QApplication::translate("Dialog_Kreistasche", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_Drehzahl->setText(QApplication::translate("Dialog_Kreistasche", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_bezeichnung_var->setText(QApplication::translate("Dialog_Kreistasche", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_Kreistasche", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Technologie), QApplication::translate("Dialog_Kreistasche", "Technologie", 0, QApplication::UnicodeUTF8));
        label_wkz_Vorschub_XY->setText(QApplication::translate("Dialog_Kreistasche", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_wkz_Kommentar->setText(QApplication::translate("Dialog_Kreistasche", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_wkz_Nummer->setText(QApplication::translate("Dialog_Kreistasche", "Nummer", 0, QApplication::UnicodeUTF8));
        label_wkz_Vorschub_XY_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Name->setText(QApplication::translate("Dialog_Kreistasche", "Name", 0, QApplication::UnicodeUTF8));
        label_wkz_Eintauschvorschub->setText(QApplication::translate("Dialog_Kreistasche", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_AUTO_Werte->setText(QApplication::translate("Dialog_Kreistasche", "AUTO-Werte:", 0, QApplication::UnicodeUTF8));
        label_wkz_Name_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Durchmesser->setText(QApplication::translate("Dialog_Kreistasche", "Durchmesser", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehrichtung_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Nutzlaenge->setText(QApplication::translate("Dialog_Kreistasche", "Nutzl\303\244nge", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehrichtung->setText(QApplication::translate("Dialog_Kreistasche", "Drehrichtung", 0, QApplication::UnicodeUTF8));
        label_wkz_Eintauschvorschub_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Kommentar_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehzahl->setText(QApplication::translate("Dialog_Kreistasche", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_wkz_Nummer_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Drehzahl_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Durchmesser_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        label_wkz_Nutzlaenge_wert->setText(QApplication::translate("Dialog_Kreistasche", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Werkzeug), QApplication::translate("Dialog_Kreistasche", "Werkzeug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Kreistasche: public Ui_Dialog_Kreistasche {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_KREISTASCHE_H
