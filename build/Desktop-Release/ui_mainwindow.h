/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinstellungen;
    QAction *actionWerkzeugliste;
    QAction *actionAendern;
    QAction *actionDateiSpeichern;
    QAction *actionDateiOefnen;
    QAction *actionDateiSchliessen;
    QAction *actionGCode_berechnen;
    QAction *actionGCode_exportieren;
    QAction *actionEntfernen;
    QAction *actionKopieren;
    QAction *actionAusschneiden;
    QAction *actionEinfuegen;
    QAction *actionMakeProgrammkopf;
    QAction *actionMakeProgrammende;
    QAction *actionMakeKreistasche;
    QAction *actionMakeRechtecktasche;
    QAction *actionMakeKommentar;
    QAction *actionDateiNeu;
    QAction *actionDateiSpeichern_unter;
    QAction *actionMakeVariable;
    QAction *actionEin_Ausblenden;
    QAction *actionVorschaufenster_anzeigen;
    QAction *actionProgrammliste_anzeigen;
    QAction *actionWerkzeugliste_anzeigen;
    QAction *actionVariablenwert_anzeigen;
    QAction *actionAuswahl_Einblenden;
    QAction *actionAuswahl_Ausblenden;
    QAction *actionRueckgaengig;
    QAction *actionWiederholen;
    QAction *actionMakeFraeser_Aufruf;
    QAction *actionMakeGerade_Fraesbahn;
    QAction *actionMakeGebogene_Fraesbahn;
    QAction *actionMakeAbfahren;
    QAction *actionTestfunktion;
    QAction *actionLetzte_Dateien;
    QAction *import_GGF;
    QAction *import_DXF;
    QAction *actionKreis_in_Kreistasche_umwandeln;
    QAction *actionMakeKreis;
    QAction *actionKreistasche_in_Kreis_umwandeln;
    QAction *actionInfo;
    QAction *actionMakeStrecke;
    QAction *actionMakeBogen;
    QAction *actionMaschine_speichern;
    QAction *actionMaschinengeometrie_bearbeiten;
    QAction *actionCAD_sortieren;
    QAction *actionLinien_in_Fraeskonturen_umwandeln;
    QAction *actionFraeskonturen_in_Linien_umwandeln;
    QAction *actionFraesrichtung_umkehren;
    QAction *actionFraesStartpunkt_vor;
    QAction *actionFraesStartpunkt_nach;
    QAction *action4_Eck_in_Rechtecktasche_umwandeln;
    QAction *actionRechtecktasche_in_4_Eck_umwandeln;
    QAction *actionVerastzvariablen;
    QAction *actionMakeBohren;
    QAction *actionSpiegeln_vertikel;
    QAction *actionSpiegeln_horizontal;
    QAction *actionKreis_in_Bohrung_umwandeln;
    QAction *actionBohrung_in_Kreis_umwandeln;
    QAction *actionKreistasche_in_Bohrung_umwandeln;
    QAction *actionBohrung_in_Kreistasche_umwandeln;
    QAction *actionNaechste_offen_Datei;
    QAction *actionLetzte_offene_Datei;
    QAction *actionMakeSchleife_linear;
    QAction *actionMakeSchleifenende;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_Programmliste;
    QListWidget *listWidget_Programmliste;
    QWidget *tab_GCode;
    QPlainTextEdit *plainTextEdit_GCode;
    QWidget *layoutWidget;
    QHBoxLayout *layout_GCODE_buttons;
    QPushButton *pushButton_Aktualisieren_GCode;
    QPushButton *pushButton_Exportieren_GCODE;
    QWidget *tab_Werkzeug;
    QListWidget *listWidget_Werkzeug;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_WKZ_Neu;
    QPushButton *pushButton_WKZ_Speichern;
    QPushButton *pushButton_WKZ_Laden;
    QPushButton *pushButton_WKZ_Export_an_EMC2;
    QMenuBar *menuBar;
    QMenu *menuMen;
    QMenu *menuBearbeiten;
    QMenu *menuDatei;
    QMenu *menuLetzte_Dateien;
    QMenu *menuImport;
    QMenu *menuOffene_Dateien;
    QMenu *menuHinzufuegen;
    QMenu *menuUmwandeln;
    QMenu *menuCAD;
    QMenu *menuManipulation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 375);
        actionEinstellungen = new QAction(MainWindow);
        actionEinstellungen->setObjectName("actionEinstellungen");
        actionWerkzeugliste = new QAction(MainWindow);
        actionWerkzeugliste->setObjectName("actionWerkzeugliste");
        actionAendern = new QAction(MainWindow);
        actionAendern->setObjectName("actionAendern");
        actionDateiSpeichern = new QAction(MainWindow);
        actionDateiSpeichern->setObjectName("actionDateiSpeichern");
        actionDateiOefnen = new QAction(MainWindow);
        actionDateiOefnen->setObjectName("actionDateiOefnen");
        actionDateiSchliessen = new QAction(MainWindow);
        actionDateiSchliessen->setObjectName("actionDateiSchliessen");
        actionGCode_berechnen = new QAction(MainWindow);
        actionGCode_berechnen->setObjectName("actionGCode_berechnen");
        actionGCode_exportieren = new QAction(MainWindow);
        actionGCode_exportieren->setObjectName("actionGCode_exportieren");
        actionEntfernen = new QAction(MainWindow);
        actionEntfernen->setObjectName("actionEntfernen");
        actionKopieren = new QAction(MainWindow);
        actionKopieren->setObjectName("actionKopieren");
        actionAusschneiden = new QAction(MainWindow);
        actionAusschneiden->setObjectName("actionAusschneiden");
        actionEinfuegen = new QAction(MainWindow);
        actionEinfuegen->setObjectName("actionEinfuegen");
        actionMakeProgrammkopf = new QAction(MainWindow);
        actionMakeProgrammkopf->setObjectName("actionMakeProgrammkopf");
        actionMakeProgrammende = new QAction(MainWindow);
        actionMakeProgrammende->setObjectName("actionMakeProgrammende");
        actionMakeKreistasche = new QAction(MainWindow);
        actionMakeKreistasche->setObjectName("actionMakeKreistasche");
        actionMakeRechtecktasche = new QAction(MainWindow);
        actionMakeRechtecktasche->setObjectName("actionMakeRechtecktasche");
        actionMakeKommentar = new QAction(MainWindow);
        actionMakeKommentar->setObjectName("actionMakeKommentar");
        actionDateiNeu = new QAction(MainWindow);
        actionDateiNeu->setObjectName("actionDateiNeu");
        actionDateiSpeichern_unter = new QAction(MainWindow);
        actionDateiSpeichern_unter->setObjectName("actionDateiSpeichern_unter");
        actionMakeVariable = new QAction(MainWindow);
        actionMakeVariable->setObjectName("actionMakeVariable");
        actionEin_Ausblenden = new QAction(MainWindow);
        actionEin_Ausblenden->setObjectName("actionEin_Ausblenden");
        actionVorschaufenster_anzeigen = new QAction(MainWindow);
        actionVorschaufenster_anzeigen->setObjectName("actionVorschaufenster_anzeigen");
        actionVorschaufenster_anzeigen->setCheckable(false);
        actionProgrammliste_anzeigen = new QAction(MainWindow);
        actionProgrammliste_anzeigen->setObjectName("actionProgrammliste_anzeigen");
        actionWerkzeugliste_anzeigen = new QAction(MainWindow);
        actionWerkzeugliste_anzeigen->setObjectName("actionWerkzeugliste_anzeigen");
        actionVariablenwert_anzeigen = new QAction(MainWindow);
        actionVariablenwert_anzeigen->setObjectName("actionVariablenwert_anzeigen");
        actionAuswahl_Einblenden = new QAction(MainWindow);
        actionAuswahl_Einblenden->setObjectName("actionAuswahl_Einblenden");
        actionAuswahl_Ausblenden = new QAction(MainWindow);
        actionAuswahl_Ausblenden->setObjectName("actionAuswahl_Ausblenden");
        actionRueckgaengig = new QAction(MainWindow);
        actionRueckgaengig->setObjectName("actionRueckgaengig");
        actionWiederholen = new QAction(MainWindow);
        actionWiederholen->setObjectName("actionWiederholen");
        actionMakeFraeser_Aufruf = new QAction(MainWindow);
        actionMakeFraeser_Aufruf->setObjectName("actionMakeFraeser_Aufruf");
        actionMakeGerade_Fraesbahn = new QAction(MainWindow);
        actionMakeGerade_Fraesbahn->setObjectName("actionMakeGerade_Fraesbahn");
        actionMakeGebogene_Fraesbahn = new QAction(MainWindow);
        actionMakeGebogene_Fraesbahn->setObjectName("actionMakeGebogene_Fraesbahn");
        actionMakeAbfahren = new QAction(MainWindow);
        actionMakeAbfahren->setObjectName("actionMakeAbfahren");
        actionTestfunktion = new QAction(MainWindow);
        actionTestfunktion->setObjectName("actionTestfunktion");
        actionLetzte_Dateien = new QAction(MainWindow);
        actionLetzte_Dateien->setObjectName("actionLetzte_Dateien");
        import_GGF = new QAction(MainWindow);
        import_GGF->setObjectName("import_GGF");
        import_DXF = new QAction(MainWindow);
        import_DXF->setObjectName("import_DXF");
        actionKreis_in_Kreistasche_umwandeln = new QAction(MainWindow);
        actionKreis_in_Kreistasche_umwandeln->setObjectName("actionKreis_in_Kreistasche_umwandeln");
        actionMakeKreis = new QAction(MainWindow);
        actionMakeKreis->setObjectName("actionMakeKreis");
        actionKreistasche_in_Kreis_umwandeln = new QAction(MainWindow);
        actionKreistasche_in_Kreis_umwandeln->setObjectName("actionKreistasche_in_Kreis_umwandeln");
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        actionMakeStrecke = new QAction(MainWindow);
        actionMakeStrecke->setObjectName("actionMakeStrecke");
        actionMakeBogen = new QAction(MainWindow);
        actionMakeBogen->setObjectName("actionMakeBogen");
        actionMaschine_speichern = new QAction(MainWindow);
        actionMaschine_speichern->setObjectName("actionMaschine_speichern");
        actionMaschinengeometrie_bearbeiten = new QAction(MainWindow);
        actionMaschinengeometrie_bearbeiten->setObjectName("actionMaschinengeometrie_bearbeiten");
        actionCAD_sortieren = new QAction(MainWindow);
        actionCAD_sortieren->setObjectName("actionCAD_sortieren");
        actionLinien_in_Fraeskonturen_umwandeln = new QAction(MainWindow);
        actionLinien_in_Fraeskonturen_umwandeln->setObjectName("actionLinien_in_Fraeskonturen_umwandeln");
        actionFraeskonturen_in_Linien_umwandeln = new QAction(MainWindow);
        actionFraeskonturen_in_Linien_umwandeln->setObjectName("actionFraeskonturen_in_Linien_umwandeln");
        actionFraesrichtung_umkehren = new QAction(MainWindow);
        actionFraesrichtung_umkehren->setObjectName("actionFraesrichtung_umkehren");
        actionFraesStartpunkt_vor = new QAction(MainWindow);
        actionFraesStartpunkt_vor->setObjectName("actionFraesStartpunkt_vor");
        actionFraesStartpunkt_nach = new QAction(MainWindow);
        actionFraesStartpunkt_nach->setObjectName("actionFraesStartpunkt_nach");
        action4_Eck_in_Rechtecktasche_umwandeln = new QAction(MainWindow);
        action4_Eck_in_Rechtecktasche_umwandeln->setObjectName("action4_Eck_in_Rechtecktasche_umwandeln");
        actionRechtecktasche_in_4_Eck_umwandeln = new QAction(MainWindow);
        actionRechtecktasche_in_4_Eck_umwandeln->setObjectName("actionRechtecktasche_in_4_Eck_umwandeln");
        actionVerastzvariablen = new QAction(MainWindow);
        actionVerastzvariablen->setObjectName("actionVerastzvariablen");
        actionMakeBohren = new QAction(MainWindow);
        actionMakeBohren->setObjectName("actionMakeBohren");
        actionSpiegeln_vertikel = new QAction(MainWindow);
        actionSpiegeln_vertikel->setObjectName("actionSpiegeln_vertikel");
        actionSpiegeln_horizontal = new QAction(MainWindow);
        actionSpiegeln_horizontal->setObjectName("actionSpiegeln_horizontal");
        actionKreis_in_Bohrung_umwandeln = new QAction(MainWindow);
        actionKreis_in_Bohrung_umwandeln->setObjectName("actionKreis_in_Bohrung_umwandeln");
        actionBohrung_in_Kreis_umwandeln = new QAction(MainWindow);
        actionBohrung_in_Kreis_umwandeln->setObjectName("actionBohrung_in_Kreis_umwandeln");
        actionKreistasche_in_Bohrung_umwandeln = new QAction(MainWindow);
        actionKreistasche_in_Bohrung_umwandeln->setObjectName("actionKreistasche_in_Bohrung_umwandeln");
        actionBohrung_in_Kreistasche_umwandeln = new QAction(MainWindow);
        actionBohrung_in_Kreistasche_umwandeln->setObjectName("actionBohrung_in_Kreistasche_umwandeln");
        actionNaechste_offen_Datei = new QAction(MainWindow);
        actionNaechste_offen_Datei->setObjectName("actionNaechste_offen_Datei");
        actionLetzte_offene_Datei = new QAction(MainWindow);
        actionLetzte_offene_Datei->setObjectName("actionLetzte_offene_Datei");
        actionMakeSchleife_linear = new QAction(MainWindow);
        actionMakeSchleife_linear->setObjectName("actionMakeSchleife_linear");
        actionMakeSchleifenende = new QAction(MainWindow);
        actionMakeSchleifenende->setObjectName("actionMakeSchleifenende");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 681, 281));
        tabWidget->setMaximumSize(QSize(681, 641));
        tab_Programmliste = new QWidget();
        tab_Programmliste->setObjectName("tab_Programmliste");
        listWidget_Programmliste = new QListWidget(tab_Programmliste);
        listWidget_Programmliste->setObjectName("listWidget_Programmliste");
        listWidget_Programmliste->setGeometry(QRect(5, 11, 241, 221));
        listWidget_Programmliste->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tabWidget->addTab(tab_Programmliste, QString());
        tab_GCode = new QWidget();
        tab_GCode->setObjectName("tab_GCode");
        plainTextEdit_GCode = new QPlainTextEdit(tab_GCode);
        plainTextEdit_GCode->setObjectName("plainTextEdit_GCode");
        plainTextEdit_GCode->setGeometry(QRect(10, 50, 661, 551));
        layoutWidget = new QWidget(tab_GCode);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 251, 31));
        layout_GCODE_buttons = new QHBoxLayout(layoutWidget);
        layout_GCODE_buttons->setSpacing(6);
        layout_GCODE_buttons->setContentsMargins(11, 11, 11, 11);
        layout_GCODE_buttons->setObjectName("layout_GCODE_buttons");
        layout_GCODE_buttons->setContentsMargins(0, 0, 0, 0);
        pushButton_Aktualisieren_GCode = new QPushButton(layoutWidget);
        pushButton_Aktualisieren_GCode->setObjectName("pushButton_Aktualisieren_GCode");

        layout_GCODE_buttons->addWidget(pushButton_Aktualisieren_GCode);

        pushButton_Exportieren_GCODE = new QPushButton(layoutWidget);
        pushButton_Exportieren_GCODE->setObjectName("pushButton_Exportieren_GCODE");

        layout_GCODE_buttons->addWidget(pushButton_Exportieren_GCODE);

        tabWidget->addTab(tab_GCode, QString());
        tab_Werkzeug = new QWidget();
        tab_Werkzeug->setObjectName("tab_Werkzeug");
        listWidget_Werkzeug = new QListWidget(tab_Werkzeug);
        listWidget_Werkzeug->setObjectName("listWidget_Werkzeug");
        listWidget_Werkzeug->setGeometry(QRect(10, 50, 661, 551));
        layoutWidget1 = new QWidget(tab_Werkzeug);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 471, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_WKZ_Neu = new QPushButton(layoutWidget1);
        pushButton_WKZ_Neu->setObjectName("pushButton_WKZ_Neu");

        horizontalLayout->addWidget(pushButton_WKZ_Neu);

        pushButton_WKZ_Speichern = new QPushButton(layoutWidget1);
        pushButton_WKZ_Speichern->setObjectName("pushButton_WKZ_Speichern");

        horizontalLayout->addWidget(pushButton_WKZ_Speichern);

        pushButton_WKZ_Laden = new QPushButton(layoutWidget1);
        pushButton_WKZ_Laden->setObjectName("pushButton_WKZ_Laden");

        horizontalLayout->addWidget(pushButton_WKZ_Laden);

        pushButton_WKZ_Export_an_EMC2 = new QPushButton(layoutWidget1);
        pushButton_WKZ_Export_an_EMC2->setObjectName("pushButton_WKZ_Export_an_EMC2");

        horizontalLayout->addWidget(pushButton_WKZ_Export_an_EMC2);

        tabWidget->addTab(tab_Werkzeug, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        menuMen = new QMenu(menuBar);
        menuMen->setObjectName("menuMen");
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName("menuBearbeiten");
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName("menuDatei");
        menuLetzte_Dateien = new QMenu(menuDatei);
        menuLetzte_Dateien->setObjectName("menuLetzte_Dateien");
        menuImport = new QMenu(menuDatei);
        menuImport->setObjectName("menuImport");
        menuOffene_Dateien = new QMenu(menuDatei);
        menuOffene_Dateien->setObjectName("menuOffene_Dateien");
        menuHinzufuegen = new QMenu(menuBar);
        menuHinzufuegen->setObjectName("menuHinzufuegen");
        menuUmwandeln = new QMenu(menuBar);
        menuUmwandeln->setObjectName("menuUmwandeln");
        menuCAD = new QMenu(menuBar);
        menuCAD->setObjectName("menuCAD");
        menuManipulation = new QMenu(menuBar);
        menuManipulation->setObjectName("menuManipulation");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuBar->addAction(menuHinzufuegen->menuAction());
        menuBar->addAction(menuCAD->menuAction());
        menuBar->addAction(menuUmwandeln->menuAction());
        menuBar->addAction(menuManipulation->menuAction());
        menuBar->addAction(menuMen->menuAction());
        menuMen->addAction(actionInfo);
        menuMen->addAction(actionEinstellungen);
        menuMen->addAction(actionWerkzeugliste);
        menuMen->addAction(actionProgrammliste_anzeigen);
        menuMen->addAction(actionWerkzeugliste_anzeigen);
        menuMen->addAction(actionVariablenwert_anzeigen);
        menuMen->addAction(actionTestfunktion);
        menuBearbeiten->addAction(actionAendern);
        menuBearbeiten->addSeparator();
        menuBearbeiten->addAction(actionEinfuegen);
        menuBearbeiten->addAction(actionKopieren);
        menuBearbeiten->addAction(actionAusschneiden);
        menuBearbeiten->addAction(actionEntfernen);
        menuBearbeiten->addSeparator();
        menuBearbeiten->addAction(actionEin_Ausblenden);
        menuBearbeiten->addAction(actionAuswahl_Einblenden);
        menuBearbeiten->addAction(actionAuswahl_Ausblenden);
        menuBearbeiten->addSeparator();
        menuBearbeiten->addAction(actionRueckgaengig);
        menuBearbeiten->addAction(actionWiederholen);
        menuDatei->addAction(actionDateiNeu);
        menuDatei->addAction(actionDateiOefnen);
        menuDatei->addAction(menuLetzte_Dateien->menuAction());
        menuDatei->addAction(menuOffene_Dateien->menuAction());
        menuDatei->addAction(actionNaechste_offen_Datei);
        menuDatei->addAction(actionLetzte_offene_Datei);
        menuDatei->addAction(menuImport->menuAction());
        menuDatei->addAction(actionDateiSpeichern);
        menuDatei->addAction(actionDateiSpeichern_unter);
        menuDatei->addAction(actionDateiSchliessen);
        menuDatei->addSeparator();
        menuDatei->addAction(actionMaschine_speichern);
        menuDatei->addAction(actionMaschinengeometrie_bearbeiten);
        menuDatei->addSeparator();
        menuDatei->addAction(actionGCode_berechnen);
        menuDatei->addAction(actionGCode_exportieren);
        menuImport->addAction(import_GGF);
        menuImport->addAction(import_DXF);
        menuHinzufuegen->addAction(actionMakeProgrammkopf);
        menuHinzufuegen->addAction(actionMakeProgrammende);
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeKommentar);
        menuHinzufuegen->addAction(actionMakeVariable);
        menuHinzufuegen->addAction(actionMakeSchleife_linear);
        menuHinzufuegen->addAction(actionMakeSchleifenende);
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeKreistasche);
        menuHinzufuegen->addAction(actionMakeRechtecktasche);
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeBohren);
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeFraeser_Aufruf);
        menuHinzufuegen->addAction(actionMakeGerade_Fraesbahn);
        menuHinzufuegen->addAction(actionMakeGebogene_Fraesbahn);
        menuHinzufuegen->addAction(actionMakeAbfahren);
        menuUmwandeln->addAction(actionKreis_in_Kreistasche_umwandeln);
        menuUmwandeln->addAction(actionKreistasche_in_Kreis_umwandeln);
        menuUmwandeln->addSeparator();
        menuUmwandeln->addAction(actionKreis_in_Bohrung_umwandeln);
        menuUmwandeln->addAction(actionBohrung_in_Kreis_umwandeln);
        menuUmwandeln->addSeparator();
        menuUmwandeln->addAction(actionKreistasche_in_Bohrung_umwandeln);
        menuUmwandeln->addAction(actionBohrung_in_Kreistasche_umwandeln);
        menuUmwandeln->addSeparator();
        menuUmwandeln->addAction(action4_Eck_in_Rechtecktasche_umwandeln);
        menuUmwandeln->addAction(actionRechtecktasche_in_4_Eck_umwandeln);
        menuUmwandeln->addSeparator();
        menuUmwandeln->addAction(actionLinien_in_Fraeskonturen_umwandeln);
        menuUmwandeln->addAction(actionFraeskonturen_in_Linien_umwandeln);
        menuCAD->addAction(actionMakeKreis);
        menuCAD->addAction(actionMakeBogen);
        menuCAD->addAction(actionMakeStrecke);
        menuManipulation->addAction(actionCAD_sortieren);
        menuManipulation->addAction(actionFraesrichtung_umkehren);
        menuManipulation->addAction(actionFraesStartpunkt_vor);
        menuManipulation->addAction(actionFraesStartpunkt_nach);
        menuManipulation->addSeparator();
        menuManipulation->addAction(actionVerastzvariablen);
        menuManipulation->addSeparator();
        menuManipulation->addAction(actionSpiegeln_vertikel);
        menuManipulation->addAction(actionSpiegeln_horizontal);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionEinstellungen->setText(QCoreApplication::translate("MainWindow", "Einstellungen", nullptr));
        actionWerkzeugliste->setText(QCoreApplication::translate("MainWindow", "Werkzeutabelle aus EMC2 anzeigen", nullptr));
#if QT_CONFIG(shortcut)
        actionWerkzeugliste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAendern->setText(QCoreApplication::translate("MainWindow", "\303\204ndern", nullptr));
#if QT_CONFIG(shortcut)
        actionAendern->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDateiSpeichern->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
#if QT_CONFIG(shortcut)
        actionDateiSpeichern->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDateiOefnen->setText(QCoreApplication::translate("MainWindow", "\303\226fnen", nullptr));
#if QT_CONFIG(shortcut)
        actionDateiOefnen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDateiSchliessen->setText(QCoreApplication::translate("MainWindow", "Schliessen", nullptr));
#if QT_CONFIG(shortcut)
        actionDateiSchliessen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGCode_berechnen->setText(QCoreApplication::translate("MainWindow", "GCode berechnen", nullptr));
        actionGCode_exportieren->setText(QCoreApplication::translate("MainWindow", "GCode exportieren", nullptr));
        actionEntfernen->setText(QCoreApplication::translate("MainWindow", "Entfernen", nullptr));
#if QT_CONFIG(shortcut)
        actionEntfernen->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKopieren->setText(QCoreApplication::translate("MainWindow", "Kopieren", nullptr));
#if QT_CONFIG(shortcut)
        actionKopieren->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAusschneiden->setText(QCoreApplication::translate("MainWindow", "Ausschneiden", nullptr));
#if QT_CONFIG(shortcut)
        actionAusschneiden->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEinfuegen->setText(QCoreApplication::translate("MainWindow", "Einf\303\274gen", nullptr));
#if QT_CONFIG(shortcut)
        actionEinfuegen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMakeProgrammkopf->setText(QCoreApplication::translate("MainWindow", "Programmkopf", nullptr));
        actionMakeProgrammende->setText(QCoreApplication::translate("MainWindow", "Programmende", nullptr));
        actionMakeKreistasche->setText(QCoreApplication::translate("MainWindow", "Kreistasche", nullptr));
        actionMakeRechtecktasche->setText(QCoreApplication::translate("MainWindow", "Rechtecktasche", nullptr));
        actionMakeKommentar->setText(QCoreApplication::translate("MainWindow", "Kommentar", nullptr));
        actionDateiNeu->setText(QCoreApplication::translate("MainWindow", "Neu", nullptr));
#if QT_CONFIG(whatsthis)
        actionDateiNeu->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        actionDateiNeu->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDateiSpeichern_unter->setText(QCoreApplication::translate("MainWindow", "Speichern unter", nullptr));
#if QT_CONFIG(shortcut)
        actionDateiSpeichern_unter->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMakeVariable->setText(QCoreApplication::translate("MainWindow", "Variable", nullptr));
        actionEin_Ausblenden->setText(QCoreApplication::translate("MainWindow", "Ein/Ausblenden", nullptr));
#if QT_CONFIG(shortcut)
        actionEin_Ausblenden->setShortcut(QCoreApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        actionVorschaufenster_anzeigen->setText(QCoreApplication::translate("MainWindow", "Vorschaufenster anzeigen", nullptr));
        actionProgrammliste_anzeigen->setText(QCoreApplication::translate("MainWindow", "Programmliste anzeigen", nullptr));
        actionWerkzeugliste_anzeigen->setText(QCoreApplication::translate("MainWindow", "Werkzeugliste anzeigen", nullptr));
        actionVariablenwert_anzeigen->setText(QCoreApplication::translate("MainWindow", "Variablenwert anzeigen", nullptr));
        actionAuswahl_Einblenden->setText(QCoreApplication::translate("MainWindow", "Auswahl Einblenden", nullptr));
        actionAuswahl_Ausblenden->setText(QCoreApplication::translate("MainWindow", "Auswahl Ausblenden", nullptr));
        actionRueckgaengig->setText(QCoreApplication::translate("MainWindow", "R\303\274ckgaengig", nullptr));
#if QT_CONFIG(shortcut)
        actionRueckgaengig->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWiederholen->setText(QCoreApplication::translate("MainWindow", "Wiederholen", nullptr));
#if QT_CONFIG(shortcut)
        actionWiederholen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMakeFraeser_Aufruf->setText(QCoreApplication::translate("MainWindow", "Fr\303\244ser-Aufruf", nullptr));
        actionMakeGerade_Fraesbahn->setText(QCoreApplication::translate("MainWindow", "gerade Fr\303\244sbahn", nullptr));
        actionMakeGebogene_Fraesbahn->setText(QCoreApplication::translate("MainWindow", "gebogene Fr\303\244sbahn", nullptr));
        actionMakeAbfahren->setText(QCoreApplication::translate("MainWindow", "Abfahren", nullptr));
        actionTestfunktion->setText(QCoreApplication::translate("MainWindow", "Testfunktion", nullptr));
        actionLetzte_Dateien->setText(QCoreApplication::translate("MainWindow", "letzte Dateien", nullptr));
        import_GGF->setText(QCoreApplication::translate("MainWindow", "GGF", nullptr));
        import_DXF->setText(QCoreApplication::translate("MainWindow", "DXF", nullptr));
#if QT_CONFIG(shortcut)
        import_DXF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKreis_in_Kreistasche_umwandeln->setText(QCoreApplication::translate("MainWindow", "Kreis in Kreistasche umwandeln", nullptr));
        actionMakeKreis->setText(QCoreApplication::translate("MainWindow", "Kreis", nullptr));
        actionKreistasche_in_Kreis_umwandeln->setText(QCoreApplication::translate("MainWindow", "Kreistasche in Kreis umwandeln", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info / Handbuch", nullptr));
        actionMakeStrecke->setText(QCoreApplication::translate("MainWindow", "Strecke", nullptr));
        actionMakeBogen->setText(QCoreApplication::translate("MainWindow", "Bogen", nullptr));
        actionMaschine_speichern->setText(QCoreApplication::translate("MainWindow", "Maschinengeometrie speichern", nullptr));
        actionMaschinengeometrie_bearbeiten->setText(QCoreApplication::translate("MainWindow", "Maschinengeometrie bearbeiten", nullptr));
        actionCAD_sortieren->setText(QCoreApplication::translate("MainWindow", "CAD sortieren", nullptr));
        actionLinien_in_Fraeskonturen_umwandeln->setText(QCoreApplication::translate("MainWindow", "Linien in Fr\303\244skonturen umwandeln", nullptr));
        actionFraeskonturen_in_Linien_umwandeln->setText(QCoreApplication::translate("MainWindow", "Fr\303\244skonturen in Linien umwandeln", nullptr));
        actionFraesrichtung_umkehren->setText(QCoreApplication::translate("MainWindow", "Fr\303\244srichtung umkehren", nullptr));
#if QT_CONFIG(shortcut)
        actionFraesrichtung_umkehren->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFraesStartpunkt_vor->setText(QCoreApplication::translate("MainWindow", "Fr\303\244ser-Startpunkt vor", nullptr));
#if QT_CONFIG(shortcut)
        actionFraesStartpunkt_vor->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Right", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFraesStartpunkt_nach->setText(QCoreApplication::translate("MainWindow", "Fr\303\244ser-Startpunkt nach", nullptr));
#if QT_CONFIG(shortcut)
        actionFraesStartpunkt_nach->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Left", nullptr));
#endif // QT_CONFIG(shortcut)
        action4_Eck_in_Rechtecktasche_umwandeln->setText(QCoreApplication::translate("MainWindow", "4-Eck in Rechtecktasche umwandeln", nullptr));
        actionRechtecktasche_in_4_Eck_umwandeln->setText(QCoreApplication::translate("MainWindow", "Rechtecktasche in 4-Eck umwandeln", nullptr));
        actionVerastzvariablen->setText(QCoreApplication::translate("MainWindow", "Versatzvariablen einf\303\274gen", nullptr));
        actionMakeBohren->setText(QCoreApplication::translate("MainWindow", "Bohren", nullptr));
        actionSpiegeln_vertikel->setText(QCoreApplication::translate("MainWindow", "spiegeln vertikel (CAM)", nullptr));
        actionSpiegeln_horizontal->setText(QCoreApplication::translate("MainWindow", "spiegeln horizontal (CAM)", nullptr));
        actionKreis_in_Bohrung_umwandeln->setText(QCoreApplication::translate("MainWindow", "Kreis in Bohrung umwandeln", nullptr));
        actionBohrung_in_Kreis_umwandeln->setText(QCoreApplication::translate("MainWindow", "Bohrung in Kreis umwandeln", nullptr));
        actionKreistasche_in_Bohrung_umwandeln->setText(QCoreApplication::translate("MainWindow", "Kreistasche in Bohrung umwandeln", nullptr));
        actionBohrung_in_Kreistasche_umwandeln->setText(QCoreApplication::translate("MainWindow", "Bohrung in Kreistasche umwandeln", nullptr));
        actionNaechste_offen_Datei->setText(QCoreApplication::translate("MainWindow", "n\303\244chste offene Datei", nullptr));
#if QT_CONFIG(shortcut)
        actionNaechste_offen_Datei->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLetzte_offene_Datei->setText(QCoreApplication::translate("MainWindow", "letzte offene Datei", nullptr));
#if QT_CONFIG(shortcut)
        actionLetzte_offene_Datei->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMakeSchleife_linear->setText(QCoreApplication::translate("MainWindow", "Schleife linear", nullptr));
        actionMakeSchleifenende->setText(QCoreApplication::translate("MainWindow", "Schleifenende", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Programmliste), QCoreApplication::translate("MainWindow", "Programmliste", nullptr));
        pushButton_Aktualisieren_GCode->setText(QCoreApplication::translate("MainWindow", "Aktualisieren", nullptr));
        pushButton_Exportieren_GCODE->setText(QCoreApplication::translate("MainWindow", "Exportieren", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_GCode), QCoreApplication::translate("MainWindow", "G-Code", nullptr));
        pushButton_WKZ_Neu->setText(QCoreApplication::translate("MainWindow", "Neues Werkzeug", nullptr));
        pushButton_WKZ_Speichern->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
        pushButton_WKZ_Laden->setText(QCoreApplication::translate("MainWindow", "Neu Laden", nullptr));
        pushButton_WKZ_Export_an_EMC2->setText(QCoreApplication::translate("MainWindow", "Export an EMC2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Werkzeug), QCoreApplication::translate("MainWindow", "Werkzeug", nullptr));
        menuMen->setTitle(QCoreApplication::translate("MainWindow", "Diverses", nullptr));
        menuBearbeiten->setTitle(QCoreApplication::translate("MainWindow", "Bearbeiten", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuLetzte_Dateien->setTitle(QCoreApplication::translate("MainWindow", "erneut \303\226fnen", nullptr));
        menuImport->setTitle(QCoreApplication::translate("MainWindow", "Import", nullptr));
        menuOffene_Dateien->setTitle(QCoreApplication::translate("MainWindow", "offene Dateien", nullptr));
        menuHinzufuegen->setTitle(QCoreApplication::translate("MainWindow", "CAM", nullptr));
        menuUmwandeln->setTitle(QCoreApplication::translate("MainWindow", "Umwandeln", nullptr));
        menuCAD->setTitle(QCoreApplication::translate("MainWindow", "CAD", nullptr));
        menuManipulation->setTitle(QCoreApplication::translate("MainWindow", "Manipulation", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
