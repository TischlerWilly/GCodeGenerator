/********************************************************************************
** Form generated from reading UI file 'dialog_kreistasche.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_KREISTASCHE_H
#define UI_DIALOG_KREISTASCHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

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
            Dialog_Kreistasche->setObjectName("Dialog_Kreistasche");
        Dialog_Kreistasche->resize(631, 563);
        Dialog_Kreistasche->setModal(true);
        layoutWidget = new QWidget(Dialog_Kreistasche);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 520, 421, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName("pushButton_Abbrechen");

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_Speichern = new QPushButton(layoutWidget);
        pushButton_Speichern->setObjectName("pushButton_Speichern");

        horizontalLayout->addWidget(pushButton_Speichern);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName("pushButton_OK");

        horizontalLayout->addWidget(pushButton_OK);

        tabWidget = new QTabWidget(Dialog_Kreistasche);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 611, 501));
        tab_allgemein = new QWidget();
        tab_allgemein->setObjectName("tab_allgemein");
        layoutWidget1 = new QWidget(tab_allgemein);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 601, 471));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Werkzeug = new QComboBox(layoutWidget1);
        comboBox_Werkzeug->setObjectName("comboBox_Werkzeug");

        gridLayout->addWidget(comboBox_Werkzeug, 0, 2, 1, 1);

        label_Werkzeug_var = new QLabel(layoutWidget1);
        label_Werkzeug_var->setObjectName("label_Werkzeug_var");
        label_Werkzeug_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Werkzeug_var, 0, 1, 1, 1);

        label_Taschendurchmesser_var = new QLabel(layoutWidget1);
        label_Taschendurchmesser_var->setObjectName("label_Taschendurchmesser_var");
        label_Taschendurchmesser_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Taschendurchmesser_var, 3, 1, 1, 1);

        label_posY_var = new QLabel(layoutWidget1);
        label_posY_var->setObjectName("label_posY_var");
        label_posY_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posY_var, 2, 1, 1, 1);

        label_Taschendurchmesser = new QLabel(layoutWidget1);
        label_Taschendurchmesser->setObjectName("label_Taschendurchmesser");

        gridLayout->addWidget(label_Taschendurchmesser, 3, 0, 1, 1);

        lineEdit_Zustellung = new QLineEdit(layoutWidget1);
        lineEdit_Zustellung->setObjectName("lineEdit_Zustellung");

        gridLayout->addWidget(lineEdit_Zustellung, 5, 2, 1, 1);

        label_Zustellung = new QLabel(layoutWidget1);
        label_Zustellung->setObjectName("label_Zustellung");

        gridLayout->addWidget(label_Zustellung, 5, 0, 1, 1);

        lineEdit_posY = new QLineEdit(layoutWidget1);
        lineEdit_posY->setObjectName("lineEdit_posY");

        gridLayout->addWidget(lineEdit_posY, 2, 2, 1, 1);

        label_Taschentiefe = new QLabel(layoutWidget1);
        label_Taschentiefe->setObjectName("label_Taschentiefe");

        gridLayout->addWidget(label_Taschentiefe, 4, 0, 1, 1);

        lineEdit_Taschendurchmesser = new QLineEdit(layoutWidget1);
        lineEdit_Taschendurchmesser->setObjectName("lineEdit_Taschendurchmesser");

        gridLayout->addWidget(lineEdit_Taschendurchmesser, 3, 2, 1, 1);

        lineEdit_Taschentiefe = new QLineEdit(layoutWidget1);
        lineEdit_Taschentiefe->setObjectName("lineEdit_Taschentiefe");

        gridLayout->addWidget(lineEdit_Taschentiefe, 4, 2, 1, 1);

        lineEdit_posX = new QLineEdit(layoutWidget1);
        lineEdit_posX->setObjectName("lineEdit_posX");

        gridLayout->addWidget(lineEdit_posX, 1, 2, 1, 1);

        label_Gegenlauf = new QLabel(layoutWidget1);
        label_Gegenlauf->setObjectName("label_Gegenlauf");

        gridLayout->addWidget(label_Gegenlauf, 6, 0, 1, 1);

        lineEdit_Gegenlauf = new QLineEdit(layoutWidget1);
        lineEdit_Gegenlauf->setObjectName("lineEdit_Gegenlauf");

        gridLayout->addWidget(lineEdit_Gegenlauf, 6, 2, 1, 1);

        label_Werkzeug = new QLabel(layoutWidget1);
        label_Werkzeug->setObjectName("label_Werkzeug");

        gridLayout->addWidget(label_Werkzeug, 0, 0, 1, 1);

        label_posX = new QLabel(layoutWidget1);
        label_posX->setObjectName("label_posX");

        gridLayout->addWidget(label_posX, 1, 0, 1, 1);

        label_Gegenlauf_var = new QLabel(layoutWidget1);
        label_Gegenlauf_var->setObjectName("label_Gegenlauf_var");
        label_Gegenlauf_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Gegenlauf_var, 6, 1, 1, 1);

        label_posY = new QLabel(layoutWidget1);
        label_posY->setObjectName("label_posY");

        gridLayout->addWidget(label_posY, 2, 0, 1, 1);

        label_posX_var = new QLabel(layoutWidget1);
        label_posX_var->setObjectName("label_posX_var");
        label_posX_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_posX_var, 1, 1, 1, 1);

        label_Taschentiefe_var = new QLabel(layoutWidget1);
        label_Taschentiefe_var->setObjectName("label_Taschentiefe_var");
        label_Taschentiefe_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Taschentiefe_var, 4, 1, 1, 1);

        label_Zustellung_var = new QLabel(layoutWidget1);
        label_Zustellung_var->setObjectName("label_Zustellung_var");
        label_Zustellung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Zustellung_var, 5, 1, 1, 1);

        tabWidget->addTab(tab_allgemein, QString());
        tab_Technologie = new QWidget();
        tab_Technologie->setObjectName("tab_Technologie");
        layoutWidget2 = new QWidget(tab_Technologie);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 10, 591, 451));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Ausraeumen_var = new QLabel(layoutWidget2);
        label_Ausraeumen_var->setObjectName("label_Ausraeumen_var");
        label_Ausraeumen_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Ausraeumen_var, 0, 1, 1, 1);

        label_Vorschub = new QLabel(layoutWidget2);
        label_Vorschub->setObjectName("label_Vorschub");

        gridLayout_3->addWidget(label_Vorschub, 2, 0, 1, 1);

        label_Ausfuehbedingung = new QLabel(layoutWidget2);
        label_Ausfuehbedingung->setObjectName("label_Ausfuehbedingung");

        gridLayout_3->addWidget(label_Ausfuehbedingung, 6, 0, 1, 1);

        lineEdit_Drehzahl = new QLineEdit(layoutWidget2);
        lineEdit_Drehzahl->setObjectName("lineEdit_Drehzahl");

        gridLayout_3->addWidget(lineEdit_Drehzahl, 3, 2, 1, 1);

        label_Drehzahl_var = new QLabel(layoutWidget2);
        label_Drehzahl_var->setObjectName("label_Drehzahl_var");
        label_Drehzahl_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Drehzahl_var, 3, 1, 1, 1);

        lineEdit_Kommentar = new QLineEdit(layoutWidget2);
        lineEdit_Kommentar->setObjectName("lineEdit_Kommentar");

        gridLayout_3->addWidget(lineEdit_Kommentar, 4, 2, 1, 1);

        lineEdit_Anfahrvorschub = new QLineEdit(layoutWidget2);
        lineEdit_Anfahrvorschub->setObjectName("lineEdit_Anfahrvorschub");

        gridLayout_3->addWidget(lineEdit_Anfahrvorschub, 1, 2, 1, 1);

        label_Kommentar_var = new QLabel(layoutWidget2);
        label_Kommentar_var->setObjectName("label_Kommentar_var");
        label_Kommentar_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Kommentar_var, 4, 1, 1, 1);

        lineEdit_Vorschub = new QLineEdit(layoutWidget2);
        lineEdit_Vorschub->setObjectName("lineEdit_Vorschub");

        gridLayout_3->addWidget(lineEdit_Vorschub, 2, 2, 1, 1);

        lineEdit_Ausfuehbedingung = new QLineEdit(layoutWidget2);
        lineEdit_Ausfuehbedingung->setObjectName("lineEdit_Ausfuehbedingung");

        gridLayout_3->addWidget(lineEdit_Ausfuehbedingung, 6, 2, 1, 1);

        label_Vorschub_var = new QLabel(layoutWidget2);
        label_Vorschub_var->setObjectName("label_Vorschub_var");
        label_Vorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Vorschub_var, 2, 1, 1, 1);

        label_Ausfuehbedingung_var = new QLabel(layoutWidget2);
        label_Ausfuehbedingung_var->setObjectName("label_Ausfuehbedingung_var");
        label_Ausfuehbedingung_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Ausfuehbedingung_var, 6, 1, 1, 1);

        label_Kommentar = new QLabel(layoutWidget2);
        label_Kommentar->setObjectName("label_Kommentar");

        gridLayout_3->addWidget(label_Kommentar, 4, 0, 1, 1);

        label_Ausraeumen = new QLabel(layoutWidget2);
        label_Ausraeumen->setObjectName("label_Ausraeumen");

        gridLayout_3->addWidget(label_Ausraeumen, 0, 0, 1, 1);

        lineEdit_Ausraeumen = new QLineEdit(layoutWidget2);
        lineEdit_Ausraeumen->setObjectName("lineEdit_Ausraeumen");

        gridLayout_3->addWidget(lineEdit_Ausraeumen, 0, 2, 1, 1);

        label_Anfahrvorschub_var = new QLabel(layoutWidget2);
        label_Anfahrvorschub_var->setObjectName("label_Anfahrvorschub_var");
        label_Anfahrvorschub_var->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_Anfahrvorschub_var, 1, 1, 1, 1);

        label_Anfahrvorschub = new QLabel(layoutWidget2);
        label_Anfahrvorschub->setObjectName("label_Anfahrvorschub");

        gridLayout_3->addWidget(label_Anfahrvorschub, 1, 0, 1, 1);

        label_Drehzahl = new QLabel(layoutWidget2);
        label_Drehzahl->setObjectName("label_Drehzahl");

        gridLayout_3->addWidget(label_Drehzahl, 3, 0, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget2);
        lineEdit_bezeichnung->setObjectName("lineEdit_bezeichnung");

        gridLayout_3->addWidget(lineEdit_bezeichnung, 5, 2, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget2);
        label_bezeichnung_var->setObjectName("label_bezeichnung_var");

        gridLayout_3->addWidget(label_bezeichnung_var, 5, 1, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget2);
        label_bezeichnung->setObjectName("label_bezeichnung");

        gridLayout_3->addWidget(label_bezeichnung, 5, 0, 1, 1);

        tabWidget->addTab(tab_Technologie, QString());
        tab_Werkzeug = new QWidget();
        tab_Werkzeug->setObjectName("tab_Werkzeug");
        layoutWidget3 = new QWidget(tab_Werkzeug);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 10, 581, 451));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_wkz_Vorschub_XY = new QLabel(layoutWidget3);
        label_wkz_Vorschub_XY->setObjectName("label_wkz_Vorschub_XY");

        gridLayout_2->addWidget(label_wkz_Vorschub_XY, 9, 0, 1, 1);

        label_wkz_Kommentar = new QLabel(layoutWidget3);
        label_wkz_Kommentar->setObjectName("label_wkz_Kommentar");

        gridLayout_2->addWidget(label_wkz_Kommentar, 5, 0, 1, 1);

        label_wkz_Nummer = new QLabel(layoutWidget3);
        label_wkz_Nummer->setObjectName("label_wkz_Nummer");

        gridLayout_2->addWidget(label_wkz_Nummer, 0, 0, 1, 1);

        label_wkz_Vorschub_XY_wert = new QLabel(layoutWidget3);
        label_wkz_Vorschub_XY_wert->setObjectName("label_wkz_Vorschub_XY_wert");

        gridLayout_2->addWidget(label_wkz_Vorschub_XY_wert, 9, 1, 1, 1);

        label_wkz_Name = new QLabel(layoutWidget3);
        label_wkz_Name->setObjectName("label_wkz_Name");

        gridLayout_2->addWidget(label_wkz_Name, 1, 0, 1, 1);

        label_wkz_Eintauschvorschub = new QLabel(layoutWidget3);
        label_wkz_Eintauschvorschub->setObjectName("label_wkz_Eintauschvorschub");

        gridLayout_2->addWidget(label_wkz_Eintauschvorschub, 8, 0, 1, 1);

        label_AUTO_Werte = new QLabel(layoutWidget3);
        label_AUTO_Werte->setObjectName("label_AUTO_Werte");

        gridLayout_2->addWidget(label_AUTO_Werte, 7, 0, 1, 1);

        label_wkz_Name_wert = new QLabel(layoutWidget3);
        label_wkz_Name_wert->setObjectName("label_wkz_Name_wert");

        gridLayout_2->addWidget(label_wkz_Name_wert, 1, 1, 1, 1);

        label_wkz_Durchmesser = new QLabel(layoutWidget3);
        label_wkz_Durchmesser->setObjectName("label_wkz_Durchmesser");

        gridLayout_2->addWidget(label_wkz_Durchmesser, 3, 0, 1, 1);

        label_wkz_Drehrichtung_wert = new QLabel(layoutWidget3);
        label_wkz_Drehrichtung_wert->setObjectName("label_wkz_Drehrichtung_wert");

        gridLayout_2->addWidget(label_wkz_Drehrichtung_wert, 2, 1, 1, 1);

        label_wkz_Nutzlaenge = new QLabel(layoutWidget3);
        label_wkz_Nutzlaenge->setObjectName("label_wkz_Nutzlaenge");

        gridLayout_2->addWidget(label_wkz_Nutzlaenge, 4, 0, 1, 1);

        label_wkz_Drehrichtung = new QLabel(layoutWidget3);
        label_wkz_Drehrichtung->setObjectName("label_wkz_Drehrichtung");

        gridLayout_2->addWidget(label_wkz_Drehrichtung, 2, 0, 1, 1);

        label_wkz_Eintauschvorschub_wert = new QLabel(layoutWidget3);
        label_wkz_Eintauschvorschub_wert->setObjectName("label_wkz_Eintauschvorschub_wert");

        gridLayout_2->addWidget(label_wkz_Eintauschvorschub_wert, 8, 1, 1, 1);

        label_wkz_Kommentar_wert = new QLabel(layoutWidget3);
        label_wkz_Kommentar_wert->setObjectName("label_wkz_Kommentar_wert");

        gridLayout_2->addWidget(label_wkz_Kommentar_wert, 5, 1, 1, 1);

        label_wkz_Drehzahl = new QLabel(layoutWidget3);
        label_wkz_Drehzahl->setObjectName("label_wkz_Drehzahl");

        gridLayout_2->addWidget(label_wkz_Drehzahl, 10, 0, 1, 1);

        label_wkz_Nummer_wert = new QLabel(layoutWidget3);
        label_wkz_Nummer_wert->setObjectName("label_wkz_Nummer_wert");

        gridLayout_2->addWidget(label_wkz_Nummer_wert, 0, 1, 1, 1);

        label_wkz_Drehzahl_wert = new QLabel(layoutWidget3);
        label_wkz_Drehzahl_wert->setObjectName("label_wkz_Drehzahl_wert");

        gridLayout_2->addWidget(label_wkz_Drehzahl_wert, 10, 1, 1, 1);

        label_wkz_Durchmesser_wert = new QLabel(layoutWidget3);
        label_wkz_Durchmesser_wert->setObjectName("label_wkz_Durchmesser_wert");

        gridLayout_2->addWidget(label_wkz_Durchmesser_wert, 3, 1, 1, 1);

        label_wkz_Nutzlaenge_wert = new QLabel(layoutWidget3);
        label_wkz_Nutzlaenge_wert->setObjectName("label_wkz_Nutzlaenge_wert");

        gridLayout_2->addWidget(label_wkz_Nutzlaenge_wert, 4, 1, 1, 1);

        line = new QFrame(layoutWidget3);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

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
        Dialog_Kreistasche->setWindowTitle(QCoreApplication::translate("Dialog_Kreistasche", "Kreistasche", nullptr));
        pushButton_Abbrechen->setText(QCoreApplication::translate("Dialog_Kreistasche", "Abbrechen", nullptr));
        pushButton_Speichern->setText(QCoreApplication::translate("Dialog_Kreistasche", "Speichern", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_Kreistasche", "OK", nullptr));
        label_Werkzeug_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[WKZ]", nullptr));
        label_Taschendurchmesser_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[*DM]", nullptr));
        label_posY_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[*Y]", nullptr));
        label_Taschendurchmesser->setText(QCoreApplication::translate("Dialog_Kreistasche", "Durchmesser", nullptr));
        label_Zustellung->setText(QCoreApplication::translate("Dialog_Kreistasche", "Zustellung", nullptr));
        label_Taschentiefe->setText(QCoreApplication::translate("Dialog_Kreistasche", "Tiefe", nullptr));
        label_Gegenlauf->setText(QCoreApplication::translate("Dialog_Kreistasche", "Gegenlauf", nullptr));
        label_Werkzeug->setText(QCoreApplication::translate("Dialog_Kreistasche", "Werkzeug", nullptr));
        label_posX->setText(QCoreApplication::translate("Dialog_Kreistasche", "Mittelpunkt X", nullptr));
        label_Gegenlauf_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[GEGL]", nullptr));
        label_posY->setText(QCoreApplication::translate("Dialog_Kreistasche", "Mittelpunkt Y", nullptr));
        label_posX_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[*X]", nullptr));
        label_Taschentiefe_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[*TT]", nullptr));
        label_Zustellung_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[ZUST]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_allgemein), QCoreApplication::translate("Dialog_Kreistasche", "allgemein", nullptr));
        label_Ausraeumen_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[AUSR]", nullptr));
        label_Vorschub->setText(QCoreApplication::translate("Dialog_Kreistasche", "Vorschub XY", nullptr));
        label_Ausfuehbedingung->setText(QCoreApplication::translate("Dialog_Kreistasche", "Ausf\303\274hbedingung", nullptr));
        label_Drehzahl_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[N]", nullptr));
        label_Kommentar_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[KOM]", nullptr));
        label_Vorschub_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[F]", nullptr));
        label_Ausfuehbedingung_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[AFB]", nullptr));
        label_Kommentar->setText(QCoreApplication::translate("Dialog_Kreistasche", "Kommentar", nullptr));
        label_Ausraeumen->setText(QCoreApplication::translate("Dialog_Kreistasche", "Ausr\303\244umen", nullptr));
        label_Anfahrvorschub_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[FAN]", nullptr));
        label_Anfahrvorschub->setText(QCoreApplication::translate("Dialog_Kreistasche", "Eintauchvorschub", nullptr));
        label_Drehzahl->setText(QCoreApplication::translate("Dialog_Kreistasche", "Drehzahl", nullptr));
        label_bezeichnung_var->setText(QCoreApplication::translate("Dialog_Kreistasche", "[BEZ]", nullptr));
        label_bezeichnung->setText(QCoreApplication::translate("Dialog_Kreistasche", "Bezeichnung", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Technologie), QCoreApplication::translate("Dialog_Kreistasche", "Technologie", nullptr));
        label_wkz_Vorschub_XY->setText(QCoreApplication::translate("Dialog_Kreistasche", "Vorschub XY", nullptr));
        label_wkz_Kommentar->setText(QCoreApplication::translate("Dialog_Kreistasche", "Kommentar", nullptr));
        label_wkz_Nummer->setText(QCoreApplication::translate("Dialog_Kreistasche", "Nummer", nullptr));
        label_wkz_Vorschub_XY_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Name->setText(QCoreApplication::translate("Dialog_Kreistasche", "Name", nullptr));
        label_wkz_Eintauschvorschub->setText(QCoreApplication::translate("Dialog_Kreistasche", "Eintauchvorschub", nullptr));
        label_AUTO_Werte->setText(QCoreApplication::translate("Dialog_Kreistasche", "AUTO-Werte:", nullptr));
        label_wkz_Name_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Durchmesser->setText(QCoreApplication::translate("Dialog_Kreistasche", "Durchmesser", nullptr));
        label_wkz_Drehrichtung_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Nutzlaenge->setText(QCoreApplication::translate("Dialog_Kreistasche", "Nutzl\303\244nge", nullptr));
        label_wkz_Drehrichtung->setText(QCoreApplication::translate("Dialog_Kreistasche", "Drehrichtung", nullptr));
        label_wkz_Eintauschvorschub_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Kommentar_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Drehzahl->setText(QCoreApplication::translate("Dialog_Kreistasche", "Drehzahl", nullptr));
        label_wkz_Nummer_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Drehzahl_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Durchmesser_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        label_wkz_Nutzlaenge_wert->setText(QCoreApplication::translate("Dialog_Kreistasche", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Werkzeug), QCoreApplication::translate("Dialog_Kreistasche", "Werkzeug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Kreistasche: public Ui_Dialog_Kreistasche {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_KREISTASCHE_H
