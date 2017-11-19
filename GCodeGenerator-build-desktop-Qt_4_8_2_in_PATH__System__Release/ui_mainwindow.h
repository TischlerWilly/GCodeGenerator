/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Nov 19 13:45:16 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QMenu *menuHinzufuegen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 723);
        actionEinstellungen = new QAction(MainWindow);
        actionEinstellungen->setObjectName(QString::fromUtf8("actionEinstellungen"));
        actionWerkzeugliste = new QAction(MainWindow);
        actionWerkzeugliste->setObjectName(QString::fromUtf8("actionWerkzeugliste"));
        actionAendern = new QAction(MainWindow);
        actionAendern->setObjectName(QString::fromUtf8("actionAendern"));
        actionDateiSpeichern = new QAction(MainWindow);
        actionDateiSpeichern->setObjectName(QString::fromUtf8("actionDateiSpeichern"));
        actionDateiOefnen = new QAction(MainWindow);
        actionDateiOefnen->setObjectName(QString::fromUtf8("actionDateiOefnen"));
        actionDateiSchliessen = new QAction(MainWindow);
        actionDateiSchliessen->setObjectName(QString::fromUtf8("actionDateiSchliessen"));
        actionGCode_berechnen = new QAction(MainWindow);
        actionGCode_berechnen->setObjectName(QString::fromUtf8("actionGCode_berechnen"));
        actionGCode_exportieren = new QAction(MainWindow);
        actionGCode_exportieren->setObjectName(QString::fromUtf8("actionGCode_exportieren"));
        actionEntfernen = new QAction(MainWindow);
        actionEntfernen->setObjectName(QString::fromUtf8("actionEntfernen"));
        actionKopieren = new QAction(MainWindow);
        actionKopieren->setObjectName(QString::fromUtf8("actionKopieren"));
        actionAusschneiden = new QAction(MainWindow);
        actionAusschneiden->setObjectName(QString::fromUtf8("actionAusschneiden"));
        actionEinfuegen = new QAction(MainWindow);
        actionEinfuegen->setObjectName(QString::fromUtf8("actionEinfuegen"));
        actionMakeProgrammkopf = new QAction(MainWindow);
        actionMakeProgrammkopf->setObjectName(QString::fromUtf8("actionMakeProgrammkopf"));
        actionMakeProgrammende = new QAction(MainWindow);
        actionMakeProgrammende->setObjectName(QString::fromUtf8("actionMakeProgrammende"));
        actionMakeKreistasche = new QAction(MainWindow);
        actionMakeKreistasche->setObjectName(QString::fromUtf8("actionMakeKreistasche"));
        actionMakeRechtecktasche = new QAction(MainWindow);
        actionMakeRechtecktasche->setObjectName(QString::fromUtf8("actionMakeRechtecktasche"));
        actionMakeKommentar = new QAction(MainWindow);
        actionMakeKommentar->setObjectName(QString::fromUtf8("actionMakeKommentar"));
        actionDateiNeu = new QAction(MainWindow);
        actionDateiNeu->setObjectName(QString::fromUtf8("actionDateiNeu"));
        actionDateiSpeichern_unter = new QAction(MainWindow);
        actionDateiSpeichern_unter->setObjectName(QString::fromUtf8("actionDateiSpeichern_unter"));
        actionMakeVariable = new QAction(MainWindow);
        actionMakeVariable->setObjectName(QString::fromUtf8("actionMakeVariable"));
        actionEin_Ausblenden = new QAction(MainWindow);
        actionEin_Ausblenden->setObjectName(QString::fromUtf8("actionEin_Ausblenden"));
        actionVorschaufenster_anzeigen = new QAction(MainWindow);
        actionVorschaufenster_anzeigen->setObjectName(QString::fromUtf8("actionVorschaufenster_anzeigen"));
        actionVorschaufenster_anzeigen->setCheckable(false);
        actionProgrammliste_anzeigen = new QAction(MainWindow);
        actionProgrammliste_anzeigen->setObjectName(QString::fromUtf8("actionProgrammliste_anzeigen"));
        actionWerkzeugliste_anzeigen = new QAction(MainWindow);
        actionWerkzeugliste_anzeigen->setObjectName(QString::fromUtf8("actionWerkzeugliste_anzeigen"));
        actionVariablenwert_anzeigen = new QAction(MainWindow);
        actionVariablenwert_anzeigen->setObjectName(QString::fromUtf8("actionVariablenwert_anzeigen"));
        actionAuswahl_Einblenden = new QAction(MainWindow);
        actionAuswahl_Einblenden->setObjectName(QString::fromUtf8("actionAuswahl_Einblenden"));
        actionAuswahl_Ausblenden = new QAction(MainWindow);
        actionAuswahl_Ausblenden->setObjectName(QString::fromUtf8("actionAuswahl_Ausblenden"));
        actionRueckgaengig = new QAction(MainWindow);
        actionRueckgaengig->setObjectName(QString::fromUtf8("actionRueckgaengig"));
        actionWiederholen = new QAction(MainWindow);
        actionWiederholen->setObjectName(QString::fromUtf8("actionWiederholen"));
        actionMakeFraeser_Aufruf = new QAction(MainWindow);
        actionMakeFraeser_Aufruf->setObjectName(QString::fromUtf8("actionMakeFraeser_Aufruf"));
        actionMakeGerade_Fraesbahn = new QAction(MainWindow);
        actionMakeGerade_Fraesbahn->setObjectName(QString::fromUtf8("actionMakeGerade_Fraesbahn"));
        actionMakeGebogene_Fraesbahn = new QAction(MainWindow);
        actionMakeGebogene_Fraesbahn->setObjectName(QString::fromUtf8("actionMakeGebogene_Fraesbahn"));
        actionMakeAbfahren = new QAction(MainWindow);
        actionMakeAbfahren->setObjectName(QString::fromUtf8("actionMakeAbfahren"));
        actionTestfunktion = new QAction(MainWindow);
        actionTestfunktion->setObjectName(QString::fromUtf8("actionTestfunktion"));
        actionLetzte_Dateien = new QAction(MainWindow);
        actionLetzte_Dateien->setObjectName(QString::fromUtf8("actionLetzte_Dateien"));
        import_GGF = new QAction(MainWindow);
        import_GGF->setObjectName(QString::fromUtf8("import_GGF"));
        import_DXF = new QAction(MainWindow);
        import_DXF->setObjectName(QString::fromUtf8("import_DXF"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 681, 641));
        tabWidget->setMaximumSize(QSize(681, 641));
        tab_Programmliste = new QWidget();
        tab_Programmliste->setObjectName(QString::fromUtf8("tab_Programmliste"));
        listWidget_Programmliste = new QListWidget(tab_Programmliste);
        listWidget_Programmliste->setObjectName(QString::fromUtf8("listWidget_Programmliste"));
        listWidget_Programmliste->setGeometry(QRect(5, 11, 241, 591));
        listWidget_Programmliste->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tabWidget->addTab(tab_Programmliste, QString());
        tab_GCode = new QWidget();
        tab_GCode->setObjectName(QString::fromUtf8("tab_GCode"));
        plainTextEdit_GCode = new QPlainTextEdit(tab_GCode);
        plainTextEdit_GCode->setObjectName(QString::fromUtf8("plainTextEdit_GCode"));
        plainTextEdit_GCode->setGeometry(QRect(10, 50, 661, 551));
        layoutWidget = new QWidget(tab_GCode);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 251, 29));
        layout_GCODE_buttons = new QHBoxLayout(layoutWidget);
        layout_GCODE_buttons->setSpacing(6);
        layout_GCODE_buttons->setContentsMargins(11, 11, 11, 11);
        layout_GCODE_buttons->setObjectName(QString::fromUtf8("layout_GCODE_buttons"));
        layout_GCODE_buttons->setContentsMargins(0, 0, 0, 0);
        pushButton_Aktualisieren_GCode = new QPushButton(layoutWidget);
        pushButton_Aktualisieren_GCode->setObjectName(QString::fromUtf8("pushButton_Aktualisieren_GCode"));

        layout_GCODE_buttons->addWidget(pushButton_Aktualisieren_GCode);

        pushButton_Exportieren_GCODE = new QPushButton(layoutWidget);
        pushButton_Exportieren_GCODE->setObjectName(QString::fromUtf8("pushButton_Exportieren_GCODE"));

        layout_GCODE_buttons->addWidget(pushButton_Exportieren_GCODE);

        tabWidget->addTab(tab_GCode, QString());
        tab_Werkzeug = new QWidget();
        tab_Werkzeug->setObjectName(QString::fromUtf8("tab_Werkzeug"));
        listWidget_Werkzeug = new QListWidget(tab_Werkzeug);
        listWidget_Werkzeug->setObjectName(QString::fromUtf8("listWidget_Werkzeug"));
        listWidget_Werkzeug->setGeometry(QRect(10, 50, 661, 551));
        layoutWidget1 = new QWidget(tab_Werkzeug);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 471, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_WKZ_Neu = new QPushButton(layoutWidget1);
        pushButton_WKZ_Neu->setObjectName(QString::fromUtf8("pushButton_WKZ_Neu"));

        horizontalLayout->addWidget(pushButton_WKZ_Neu);

        pushButton_WKZ_Speichern = new QPushButton(layoutWidget1);
        pushButton_WKZ_Speichern->setObjectName(QString::fromUtf8("pushButton_WKZ_Speichern"));

        horizontalLayout->addWidget(pushButton_WKZ_Speichern);

        pushButton_WKZ_Laden = new QPushButton(layoutWidget1);
        pushButton_WKZ_Laden->setObjectName(QString::fromUtf8("pushButton_WKZ_Laden"));

        horizontalLayout->addWidget(pushButton_WKZ_Laden);

        pushButton_WKZ_Export_an_EMC2 = new QPushButton(layoutWidget1);
        pushButton_WKZ_Export_an_EMC2->setObjectName(QString::fromUtf8("pushButton_WKZ_Export_an_EMC2"));

        horizontalLayout->addWidget(pushButton_WKZ_Export_an_EMC2);

        tabWidget->addTab(tab_Werkzeug, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 25));
        menuMen = new QMenu(menuBar);
        menuMen->setObjectName(QString::fromUtf8("menuMen"));
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QString::fromUtf8("menuBearbeiten"));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menuLetzte_Dateien = new QMenu(menuDatei);
        menuLetzte_Dateien->setObjectName(QString::fromUtf8("menuLetzte_Dateien"));
        menuImport = new QMenu(menuDatei);
        menuImport->setObjectName(QString::fromUtf8("menuImport"));
        menuHinzufuegen = new QMenu(menuBar);
        menuHinzufuegen->setObjectName(QString::fromUtf8("menuHinzufuegen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuBar->addAction(menuHinzufuegen->menuAction());
        menuBar->addAction(menuMen->menuAction());
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
        menuDatei->addAction(menuImport->menuAction());
        menuDatei->addAction(actionDateiSpeichern);
        menuDatei->addAction(actionDateiSpeichern_unter);
        menuDatei->addAction(actionDateiSchliessen);
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
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeKreistasche);
        menuHinzufuegen->addAction(actionMakeRechtecktasche);
        menuHinzufuegen->addSeparator();
        menuHinzufuegen->addAction(actionMakeFraeser_Aufruf);
        menuHinzufuegen->addAction(actionMakeGerade_Fraesbahn);
        menuHinzufuegen->addAction(actionMakeGebogene_Fraesbahn);
        menuHinzufuegen->addAction(actionMakeAbfahren);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionEinstellungen->setText(QApplication::translate("MainWindow", "Einstellungen", 0, QApplication::UnicodeUTF8));
        actionWerkzeugliste->setText(QApplication::translate("MainWindow", "Werkzeutabelle aus EMC2 anzeigen", 0, QApplication::UnicodeUTF8));
        actionWerkzeugliste->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionAendern->setText(QApplication::translate("MainWindow", "Aendern", 0, QApplication::UnicodeUTF8));
        actionAendern->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        actionDateiSpeichern->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        actionDateiSpeichern->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionDateiOefnen->setText(QApplication::translate("MainWindow", "Oefnen", 0, QApplication::UnicodeUTF8));
        actionDateiOefnen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionDateiSchliessen->setText(QApplication::translate("MainWindow", "Schliessen", 0, QApplication::UnicodeUTF8));
        actionDateiSchliessen->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionGCode_berechnen->setText(QApplication::translate("MainWindow", "GCode berechnen", 0, QApplication::UnicodeUTF8));
        actionGCode_exportieren->setText(QApplication::translate("MainWindow", "GCode exportieren", 0, QApplication::UnicodeUTF8));
        actionEntfernen->setText(QApplication::translate("MainWindow", "Entfernen", 0, QApplication::UnicodeUTF8));
        actionEntfernen->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionKopieren->setText(QApplication::translate("MainWindow", "Kopieren", 0, QApplication::UnicodeUTF8));
        actionKopieren->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionAusschneiden->setText(QApplication::translate("MainWindow", "Ausschneiden", 0, QApplication::UnicodeUTF8));
        actionAusschneiden->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionEinfuegen->setText(QApplication::translate("MainWindow", "Einfuegen", 0, QApplication::UnicodeUTF8));
        actionEinfuegen->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionMakeProgrammkopf->setText(QApplication::translate("MainWindow", "Programmkopf", 0, QApplication::UnicodeUTF8));
        actionMakeProgrammende->setText(QApplication::translate("MainWindow", "Programmende", 0, QApplication::UnicodeUTF8));
        actionMakeKreistasche->setText(QApplication::translate("MainWindow", "Kreistasche", 0, QApplication::UnicodeUTF8));
        actionMakeRechtecktasche->setText(QApplication::translate("MainWindow", "Rechtecktasche", 0, QApplication::UnicodeUTF8));
        actionMakeKommentar->setText(QApplication::translate("MainWindow", "Kommentar", 0, QApplication::UnicodeUTF8));
        actionDateiNeu->setText(QApplication::translate("MainWindow", "Neu", 0, QApplication::UnicodeUTF8));
        actionDateiNeu->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionDateiSpeichern_unter->setText(QApplication::translate("MainWindow", "Speichern unter", 0, QApplication::UnicodeUTF8));
        actionDateiSpeichern_unter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionMakeVariable->setText(QApplication::translate("MainWindow", "Variable", 0, QApplication::UnicodeUTF8));
        actionEin_Ausblenden->setText(QApplication::translate("MainWindow", "Ein/Ausblenden", 0, QApplication::UnicodeUTF8));
        actionEin_Ausblenden->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionVorschaufenster_anzeigen->setText(QApplication::translate("MainWindow", "Vorschaufenster anzeigen", 0, QApplication::UnicodeUTF8));
        actionProgrammliste_anzeigen->setText(QApplication::translate("MainWindow", "Programmliste anzeigen", 0, QApplication::UnicodeUTF8));
        actionWerkzeugliste_anzeigen->setText(QApplication::translate("MainWindow", "Werkzeugliste anzeigen", 0, QApplication::UnicodeUTF8));
        actionVariablenwert_anzeigen->setText(QApplication::translate("MainWindow", "Variablenwert anzeigen", 0, QApplication::UnicodeUTF8));
        actionAuswahl_Einblenden->setText(QApplication::translate("MainWindow", "Auswahl Einblenden", 0, QApplication::UnicodeUTF8));
        actionAuswahl_Ausblenden->setText(QApplication::translate("MainWindow", "Auswahl Ausblenden", 0, QApplication::UnicodeUTF8));
        actionRueckgaengig->setText(QApplication::translate("MainWindow", "Rueckgaengig", 0, QApplication::UnicodeUTF8));
        actionRueckgaengig->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionWiederholen->setText(QApplication::translate("MainWindow", "Wiederholen", 0, QApplication::UnicodeUTF8));
        actionWiederholen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionMakeFraeser_Aufruf->setText(QApplication::translate("MainWindow", "Fraeser-Aufruf", 0, QApplication::UnicodeUTF8));
        actionMakeGerade_Fraesbahn->setText(QApplication::translate("MainWindow", "gerade Fraesbahn", 0, QApplication::UnicodeUTF8));
        actionMakeGebogene_Fraesbahn->setText(QApplication::translate("MainWindow", "gebogene Fraesbahn", 0, QApplication::UnicodeUTF8));
        actionMakeAbfahren->setText(QApplication::translate("MainWindow", "Abfahren", 0, QApplication::UnicodeUTF8));
        actionTestfunktion->setText(QApplication::translate("MainWindow", "Testfunktion", 0, QApplication::UnicodeUTF8));
        actionLetzte_Dateien->setText(QApplication::translate("MainWindow", "letzte Dateien", 0, QApplication::UnicodeUTF8));
        import_GGF->setText(QApplication::translate("MainWindow", "aus GGF-Datei", 0, QApplication::UnicodeUTF8));
        import_DXF->setText(QApplication::translate("MainWindow", "aus DXF-Datei", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Programmliste), QApplication::translate("MainWindow", "Programmliste", 0, QApplication::UnicodeUTF8));
        pushButton_Aktualisieren_GCode->setText(QApplication::translate("MainWindow", "Aktualisieren", 0, QApplication::UnicodeUTF8));
        pushButton_Exportieren_GCODE->setText(QApplication::translate("MainWindow", "Exportieren", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_GCode), QApplication::translate("MainWindow", "G-Code", 0, QApplication::UnicodeUTF8));
        pushButton_WKZ_Neu->setText(QApplication::translate("MainWindow", "Neues Werkzeug", 0, QApplication::UnicodeUTF8));
        pushButton_WKZ_Speichern->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_WKZ_Laden->setText(QApplication::translate("MainWindow", "Neu Laden", 0, QApplication::UnicodeUTF8));
        pushButton_WKZ_Export_an_EMC2->setText(QApplication::translate("MainWindow", "Export an EMC2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Werkzeug), QApplication::translate("MainWindow", "Werkzeug", 0, QApplication::UnicodeUTF8));
        menuMen->setTitle(QApplication::translate("MainWindow", "Diverses", 0, QApplication::UnicodeUTF8));
        menuBearbeiten->setTitle(QApplication::translate("MainWindow", "Bearbeiten", 0, QApplication::UnicodeUTF8));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0, QApplication::UnicodeUTF8));
        menuLetzte_Dateien->setTitle(QApplication::translate("MainWindow", "erneut Oefnen", 0, QApplication::UnicodeUTF8));
        menuImport->setTitle(QApplication::translate("MainWindow", "Import", 0, QApplication::UnicodeUTF8));
        menuHinzufuegen->setTitle(QApplication::translate("MainWindow", "Hinzufuegen", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
