#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QStringList>

//---------------------------------------------------Konstruktor / Dekonstruktor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_windowtitle();

    //Defaultwerte:
    kopierterEintrag_t              = NICHT_DEFINIERT;
    kopiertesWerkzeug               = NICHT_DEFINIERT;
    tooltable_path                  = NICHT_DEFINIERT;
    vorlage_pkopf                   = NICHT_DEFINIERT;
    vorlage_pende                   = NICHT_DEFINIERT;
    vorlage_kommentar               = NICHT_DEFINIERT;
    vorlage_variable                = NICHT_DEFINIERT;
    vorlage_Ktasche                 = NICHT_DEFINIERT;
    vorlage_Rtasche                 = NICHT_DEFINIERT;
    vorlage_Faufruf                 = NICHT_DEFINIERT;
    vorlage_Fgerade                 = NICHT_DEFINIERT;
    vorlage_Fbogen                  = NICHT_DEFINIERT;
    vorlage_Fabfa                   = NICHT_DEFINIERT;
    vorlage_werkzeug                = NICHT_DEFINIERT;
    vorlage_dbohren                 = NICHT_DEFINIERT;
    vorlage_schleilin               = NICHT_DEFINIERT;
    vorlage_schleiend               = NICHT_DEFINIERT;
    settings_anz_undo_t             = "10";
    settings_anz_undo_w             = "30";
    aktives_wkz                     = NICHT_DEFINIERT;
    letzte_geoefnete_dateien.set_anz_eintreage(ANZAHL_LETZTER_DATEIEN);
    dxf_klasse_wstnp                = "werkstuecknullpunkt";
    dxf_klasse_geo                  = "fraeskontur";
    dxf_klasse_geo_beachten         = "ja";
    pfad_import_dxf                 = QDir::homePath();
    pfad_import_ggf                 = QDir::homePath() + "/Dokumente/CNC-Programme";
    pfad_oefne_ggf                  = QDir::homePath() + "/Dokumente/CNC-Programme";
    speichern_unter_flag            = false;
    tt.clear();
    anz_neue_dateien                = 0;//Zählung neuer Dateien mit 0 beginnen und dann raufzählen

    vorschaufenster.setParent(ui->tab_Programmliste);

    hideElemets_noFileIsOpen();

    QDir dir(QDir::homePath() + PFAD_ZUM_PROGRAMMORDNER);
    if(!dir.exists())
    {
        QString nachricht;
        nachricht = "Programmpfad nicht gefunden. Pfad \"";
        nachricht += QDir::homePath() + PFAD_ZUM_PROGRAMMORDNER;
        nachricht += "\" wird angelegt";
        QMessageBox mb;
        mb.setText(nachricht);
        mb.exec();
        dir.mkdir(QDir::homePath() + PFAD_ZUM_PROGRAMMORDNER);
        dir.mkdir(QDir::homePath() + PFAD_ZU_DEN_WERKZEUGBILDERN);

        QFile file(QDir::homePath() + WKZ_FILE);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
        {
            QMessageBox mb;
            mb.setText("Fehler beim Datei-Zugriff");
            mb.exec();
        }else
        {

            file.write(werkzeug_dialog.getDefault().toUtf8());
            QMessageBox mb;
            mb.setText("Neue, Werkzeugdatei wurde erzeugt.");
            mb.exec();
        }
        file.close();
    }

    QString msg = this->loadConfig();
    if(msg != "OK")
    {
        QMessageBox mb;
        mb.setText(msg);
        mb.exec();
    }
    if(konfiguration_ini_ist_vorhanden == false)
    {
        //Sicherheitsabfrage:
        QMessageBox mb;
        mb.setWindowTitle("Konnte Konfiguratiosdatei nicht finden!");
        mb.setText("Die Konfigurationsdatei ist nicht vorhanden oder konnte nicht gelesen werden.Soll eine neue Konfigurationsdatei erstellt werden?");
        mb.setStandardButtons(QMessageBox::Yes);
        mb.addButton(QMessageBox::No);
        mb.setDefaultButton(QMessageBox::No);
        if(mb.exec() == QMessageBox::Yes)
        {
            saveConfig();
            loadConfig();
        }else
        {
            QMessageBox mb2;
            mb2.setText("Konfiguration wurde nicht angelegt.");
            mb2.exec();
        }
    }

    on_pushButton_WKZ_Laden_clicked();
    ladeWerkzeugnamen();
    loadConfig_letzte_Dateien();

    //SLOT(slotSaveConfig():
    connect(&dsettings, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&pkopf, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&pende, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&kommentar, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));   
    connect(&variable, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&ktasche, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&rtasche, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&faufruf, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&fgerade, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&fbogen, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&fabfa, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&werkzeug_dialog, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&dbohren, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&dschleilin, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));
    connect(&dschleiend, SIGNAL(signalSaveConfig(QString)), this, SLOT(slotSaveConfig(QString)));

    connect(&pkopf, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&pende, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&kommentar, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&variable, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&ktasche, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&rtasche, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&faufruf, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&fgerade, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&fbogen, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&fabfa, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&werkzeug_dialog, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&dbohren, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&dschleilin, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&dschleiend, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));

    connect(&pkopf, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&pende, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&kommentar, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&variable, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&ktasche, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&rtasche, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&faufruf, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&fgerade, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&fbogen, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&fabfa, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&werkzeug_dialog, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&dbohren, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&dschleilin, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&dschleiend, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));

    connect(&dkreis, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&dstrecke, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));
    connect(&dbogen, SIGNAL(sendDialogData(QString)), this, SLOT(getDialogData(QString)));

    connect(&dkreis, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&dstrecke, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));
    connect(&dbogen, SIGNAL(sendDialogDataModifyed(QString)), this, SLOT(getDialogDataModify(QString)));

    connect(&dstrecke, SIGNAL(sendBraucheVariablen(QString)), this, SLOT(slotAnfrageVariablenZeile(QString)));
    connect(&dkreis, SIGNAL(sendBraucheVariablen(QString)), this, SLOT(slotAnfrageVariablenZeile(QString)));
    connect(&dbogen, SIGNAL(sendBraucheVariablen(QString)), this, SLOT(slotAnfrageVariablenZeile(QString)));

    connect(&ktasche, SIGNAL(signalBraucheWerkzeugdaten(QString,QString)), this, SLOT(slotAnfrageWerkzeugdaten(QString,QString)));
    connect(&rtasche, SIGNAL(signalBraucheWerkzeugdaten(QString,QString)), this, SLOT(slotAnfrageWerkzeugdaten(QString,QString)));
    connect(&dbohren, SIGNAL(signalBraucheWerkzeugdaten(QString,QString)), this, SLOT(slotAnfrageWerkzeugdaten(QString,QString)));
    connect(&variablenwerte_anzeigen, SIGNAL(brauche_variablen()), this, SLOT(slotAnfrageVariablen()));
    connect(&vorschaufenster, SIGNAL(sende_maus_pos(QPoint)), this, SLOT(slot_maus_pos(QPoint)));

    connect(this, SIGNAL(sendTextToImportGGF(QString)), &import_ggf, SLOT(getText(QString)));
    connect(&import_ggf, SIGNAL(sendData(QString)), this, SLOT(getImportGGF(QString)));

    aktualisiere_letzte_dateien_menu();

    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------Konfiguration
QString MainWindow::loadConfig()
{
    QString returnString = "OK";

    QFile file(QDir::homePath() + INI_FILE);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        konfiguration_ini_ist_vorhanden = false;
        returnString = "Konnte Konfiguratiosdatei nicht finden!\nBitte ueberpruefen Sie die Einstellungen.";
    } else
    {
        konfiguration_ini_ist_vorhanden = true;
        while(!file.atEnd())
        {
            QString line = file.readLine();
            konfiguration_ini += line;
        }
        file.close();
        //Konfiguration Zeilenweise auswerten:
        for (QStringList::iterator it = konfiguration_ini.begin(); it != konfiguration_ini.end(); ++it)
            {
                QString text = *it;

                //-----------------------------------------------------Settings:
                if(text.contains(SETTINGS_PFAD_WERKZEUGE))
                {
                    tooltable_path = selektiereEintrag(text, SETTINGS_PFAD_WERKZEUGE, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_ANZ_UNDO_T))
                {
                    settings_anz_undo_t = selektiereEintrag(text, SETTINGS_ANZ_UNDO_T, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_ANZ_UNDO_W))
                {
                    settings_anz_undo_w = selektiereEintrag(text, SETTINGS_ANZ_UNDO_W, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_DXF_KLASSE_WSTNP))
                {
                    dxf_klasse_wstnp = selektiereEintrag(text, SETTINGS_DXF_KLASSE_WSTNP, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_DXF_KLASSE_GEO))
                {
                    dxf_klasse_geo = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_DXF_KLASSE_GEO_BEACHTEN))
                {
                    dxf_klasse_geo_beachten = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO_BEACHTEN, ENDE_ZEILE);
                }else if(text.contains(SETTINGS_FKON_BERECHNEN))
                {
                    fkon_berechnen = selektiereEintrag(text, SETTINGS_FKON_BERECHNEN, ENDE_ZEILE);
                    if(fkon_berechnen == "ja")
                    {
                        tt.aktualisieren_fkon_ein_aus(true);
                    }else
                    {
                        tt.aktualisieren_fkon_ein_aus(false);
                    }
                }
                //-----------------------------------------------------Dialoge:
                if(text.contains(PROGRAMMKOPF_DIALOG))
                {
                    vorlage_pkopf = selektiereEintrag(text, PROGRAMMKOPF_DIALOG, ENDE_ZEILE);
                }else if(text.contains(PROGRAMMENDE_DIALOG))
                {
                    vorlage_pende = selektiereEintrag(text, PROGRAMMENDE_DIALOG, ENDE_ZEILE);
                }else if(text.contains(KOMMENTAR_DIALOG))
                {
                    vorlage_kommentar = selektiereEintrag(text, KOMMENTAR_DIALOG, ENDE_ZEILE);
                }else if(text.contains(VARIABLE_DIALOG))
                {
                    vorlage_variable = selektiereEintrag(text, VARIABLE_DIALOG, ENDE_ZEILE);
                }else if(text.contains(KREISTASCHE_DIALOG))
                {
                    vorlage_Ktasche = selektiereEintrag(text, KREISTASCHE_DIALOG, ENDE_ZEILE);
                }else if(text.contains(RECHTECKTASCHE_DIALOG))
                {
                    vorlage_Rtasche = selektiereEintrag(text, RECHTECKTASCHE_DIALOG, ENDE_ZEILE);
                }else if(text.contains(FRAESERAUFRUF_DIALOG))
                {
                    vorlage_Faufruf = selektiereEintrag(text, FRAESERAUFRUF_DIALOG, ENDE_ZEILE);
                }else if(text.contains(FRAESERGERADE_DIALOG))
                {
                    vorlage_Fgerade = selektiereEintrag(text, FRAESERGERADE_DIALOG, ENDE_ZEILE);
                }else if(text.contains(FRAESERBOGEN_DIALOG))
                {
                    vorlage_Fbogen = selektiereEintrag(text, FRAESERBOGEN_DIALOG, ENDE_ZEILE);
                }else if(text.contains(FRAESERABFAHREN_DIALOG))
                {
                    vorlage_Fabfa = selektiereEintrag(text, FRAESERABFAHREN_DIALOG, ENDE_ZEILE);
                }else if(text.contains(WERKZEUG_DIALOG))
                {
                    vorlage_werkzeug = selektiereEintrag(text, WERKZEUG_DIALOG, ENDE_ZEILE);
                }else if(text.contains(BOHREN_DIALOG))
                {
                    vorlage_dbohren = selektiereEintrag(text, BOHREN_DIALOG, ENDE_ZEILE);
                }else if(text.contains(SCHLEIFELINEAR_DIALOG))
                {
                    vorlage_schleilin = selektiereEintrag(text, SCHLEIFELINEAR_DIALOG, ENDE_ZEILE);
                }else if(text.contains(SCHLEIFENENDE_DIALOG))
                {
                    vorlage_schleiend = selektiereEintrag(text, SCHLEIFENENDE_DIALOG, ENDE_ZEILE);
                }
            }
    }

    return returnString;
}

QString MainWindow::saveConfig()
{
    QString returnString = "OK";

    //Daten in QString schreiben:
    QString inhaltVonKonfiguration;

    inhaltVonKonfiguration =        BEGIN_EINSTELLUNGEN;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------Einstellungen:
    inhaltVonKonfiguration +=       SETTINGS_PFAD_WERKZEUGE;
    if(tooltable_path == NICHT_DEFINIERT  ||  tooltable_path.isEmpty())
    {
        returnString = "Pfad zur Werkzeugtabelle konnt nicht gefunden werden!\nBitte ueberpruefen Sie die Einstellungen.\n";
    }else
    {
        inhaltVonKonfiguration +=   tooltable_path;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_ANZ_UNDO_T;
    inhaltVonKonfiguration +=       settings_anz_undo_t;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_ANZ_UNDO_W;
    inhaltVonKonfiguration +=       settings_anz_undo_w;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_DXF_KLASSE_WSTNP;
    inhaltVonKonfiguration +=       dxf_klasse_wstnp;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_DXF_KLASSE_GEO;
    inhaltVonKonfiguration +=       dxf_klasse_geo;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_DXF_KLASSE_GEO_BEACHTEN;
    inhaltVonKonfiguration +=       dxf_klasse_geo_beachten;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------
    inhaltVonKonfiguration +=       SETTINGS_FKON_BERECHNEN;
    inhaltVonKonfiguration +=       fkon_berechnen;
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";
    //----------------------------------------------------

    inhaltVonKonfiguration +=       ENDE_EINSTELLUNGEN;
    inhaltVonKonfiguration +=       "\n";


    inhaltVonKonfiguration +=       BEGIN_DIALOGE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Programmkopf:
    inhaltVonKonfiguration +=       PROGRAMMKOPF_DIALOG;
    if(vorlage_pkopf == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   LAENGE;
        inhaltVonKonfiguration +=               "250";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BREITE;
        inhaltVonKonfiguration +=               "250";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DICKE;
        inhaltVonKonfiguration +=               "19";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   SICHERHEITSABSTAND;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Programmkopf";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VERSATZ_X;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VERSATZ_Y;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VERSATZ_Z;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_pkopf;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Programmende:
    inhaltVonKonfiguration +=       PROGRAMMENDE_DIALOG;
    if(vorlage_pende == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   MODUS;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Z;
        inhaltVonKonfiguration +=   "50";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=   "Programmende";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_pende;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Kommentar:
    inhaltVonKonfiguration +=       KOMMENTAR_DIALOG;
    if(vorlage_kommentar == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=   "----------";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_kommentar;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Variable:
    inhaltVonKonfiguration +=       VARIABLE_DIALOG;
    if(vorlage_variable == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WERT;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_variable;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Kreistasche:
    inhaltVonKonfiguration +=       KREISTASCHE_DIALOG;
    if(vorlage_Ktasche == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   WKZ_NAME;
        inhaltVonKonfiguration +=               "WKZ1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DURCHMESSER;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   TASCHENTIEFE;
        inhaltVonKonfiguration +=               "2";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ZUSTELLUNG;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSRAEUMEN;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   GEGENLAUF;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANFAHRVORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DREHZAHL;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Kreistasche";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Ktasche;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Rechtecktasche:
    inhaltVonKonfiguration +=       RECHTECKTASCHE_DIALOG;
    if(vorlage_Rtasche == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   WKZ_NAME;
        inhaltVonKonfiguration +=               "WKZ1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   TASCHENLAENGE;
        inhaltVonKonfiguration +=               "25";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   TASCHENBREITE;
        inhaltVonKonfiguration +=               "15";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   TASCHENTIEFE;
        inhaltVonKonfiguration +=               "2";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   RADIUS;
        inhaltVonKonfiguration +=               "5";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ZUSTELLUNG;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   GEGENLAUF;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WINKEL;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSRAEUMEN;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANFAHRVORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DREHZAHL;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZUGSPUNKT;
        inhaltVonKonfiguration +=               BEZUGSPUNKT_MITTE;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Rechtecktasche";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Rtasche;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Fraeseraufruf:
    inhaltVonKonfiguration +=       FRAESERAUFRUF_DIALOG;
    if(vorlage_Faufruf == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   WKZ_NAME;
        inhaltVonKonfiguration +=               "WKZ1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BAHNRORREKTUR;
        inhaltVonKonfiguration +=               BAHNRORREKTUR_keine;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Z;
        inhaltVonKonfiguration +=               "D-2";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ECKENRUNDENGLOBAL;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KANTENDICKE;
        inhaltVonKonfiguration +=               "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANFAHRVORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DREHZAHL;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANFAHRTYP;
        inhaltVonKonfiguration +=               ANABFAHRTYP_KEIN;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ABFAHRTYP;
        inhaltVonKonfiguration +=               ANABFAHRTYP_KEIN;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Aufruf Fraeser";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_DURCHMESSER;
        inhaltVonKonfiguration +=               "10";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ZUSTELLUNG;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Faufruf;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Fraeser_Gerade:
    inhaltVonKonfiguration +=       FRAESERGERADE_DIALOG;
    if(vorlage_Fgerade == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "X";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "Y";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Z;
        inhaltVonKonfiguration +=               "Z";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   RADIUS;
        inhaltVonKonfiguration +=   "ERG";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=   "--- gerade Fraesbahn";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Fgerade;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Fraeser_Bogen:
    inhaltVonKonfiguration +=       FRAESERBOGEN_DIALOG;
    if(vorlage_Fbogen == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "X+20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "Y+20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Z;
        inhaltVonKonfiguration +=               "Z";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   RADIUS;
        inhaltVonKonfiguration +=   "15";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BOGENRICHTUNG;
        inhaltVonKonfiguration +=   BOGENRICHTUNG_IM_UZS;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=   "--- gebogene Fraesbahn";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Fbogen;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Fraeser_Abfahren:
    inhaltVonKonfiguration +=       FRAESERABFAHREN_DIALOG;
    if(vorlage_Fabfa == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=   "Abfahren Fraeser";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=   "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_Fabfa;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Werkzeug:
    inhaltVonKonfiguration +=       WERKZEUG_DIALOG;
    if(vorlage_werkzeug == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   WKZ_NAME;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_Nummer;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_STECKPLATZ;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_X;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_Y;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_Z;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_A;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_B;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_C;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_U;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_V;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_OFFSET_W;
        inhaltVonKonfiguration +=   "0";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_DURCHMESSER;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_FRONTWINKEL;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_RUECKWINKEL;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_RICHTUNG;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_KOMMENTAR;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_DREHRICHTUNG;
        inhaltVonKonfiguration +=   WKZ_DREHRICHTUNG_UNBEKANNT;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_NUTZLAENGE;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_EINTAUCHVORSCHUB;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_VORSCHUB;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   WKZ_DREHZAHL;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_werkzeug;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Dialog Bohren:
    inhaltVonKonfiguration +=       BOHREN_DIALOG;
    if(vorlage_dbohren == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   WKZ_NAME;
        inhaltVonKonfiguration +=               "WKZ1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DURCHMESSER;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_X;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   POSITION_Y;
        inhaltVonKonfiguration +=               "20";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BOHRTIEFE;
        inhaltVonKonfiguration +=               "5";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANBOHRTI;
        inhaltVonKonfiguration +=               "2";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   RESTBOHRTI;
        inhaltVonKonfiguration +=               "2";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ZUSTELLUNG;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANFAHRVORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VORSCHUB;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   DREHZAHL;
        inhaltVonKonfiguration +=               AUTOMATISCH;
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Bohrung";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_dbohren;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Schleife linear:
    inhaltVonKonfiguration +=       SCHLEIFELINEAR_DIALOG;
    if(vorlage_schleilin == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   ANZ_X;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   ANZ_Y;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VERSATZ_X;
        inhaltVonKonfiguration +=               "10";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   VERSATZ_Y;
        inhaltVonKonfiguration +=               "10";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   KOMMENTAR;
        inhaltVonKonfiguration +=               "";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Schleife linear";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_schleilin;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //----------------------------------------------------Schleifenende:
    inhaltVonKonfiguration +=       SCHLEIFENENDE_DIALOG;
    if(vorlage_schleiend == NICHT_DEFINIERT)
    {
        inhaltVonKonfiguration +=   BEZEICHNUNG;
        inhaltVonKonfiguration +=               "Schleifenende";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
        inhaltVonKonfiguration +=   AUSFUEHRBEDINGUNG;
        inhaltVonKonfiguration +=               "1";
        inhaltVonKonfiguration +=   ENDE_EINTRAG;
    }else
    {
        inhaltVonKonfiguration +=   vorlage_schleiend;
    }
    inhaltVonKonfiguration +=       ENDE_ZEILE;
    inhaltVonKonfiguration +=       "\n";

    //-------------------------------------------
    inhaltVonKonfiguration +=       ENDE_DIALOGE;
    inhaltVonKonfiguration +=       "\n";
    //---------------------------------------------------------------------------------------------------------

    //Daten Speichern:
    QFile file(QDir::homePath() + INI_FILE);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
    {
        QMessageBox mb;
        mb.setText("Fehler beim Zugriff auf die Datei \"konfiguration.ini\"");
        mb.exec();
    } else
    {
        file.remove(); //lösche alte Datei wenn vorhanden
        file.close(); //beende Zugriff
        file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
        file.write(inhaltVonKonfiguration.toUtf8()); //fülle Datei mit Inhalt
        file.close(); //beende Zugriff
        QMessageBox mb;
        mb.setText("Konfiguration wurde erfolgreich geschrieben.");
        mb.exec();
    }
    return returnString;
}

void MainWindow::loadConfig_letzte_Dateien()
{
    QFile file(QDir::homePath() + PFAD_LETZTE_DATEIEN);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString tmp;
        while(!file.atEnd())
        {
            tmp += QString::fromUtf8(file.readLine());
        }
        file.close();
        text_zeilenweise tz;
        tz.set_text(tmp);
        QString liste;
        //Reihenfolge umdrehen:
        for(uint i=tz.zeilenanzahl(); i>0;i--)
        {
            liste += tz.zeile(i);
            liste += "\n";
        }
        liste = liste.left(liste.length() - 1);//letzets Zeichen löschen = "\n"
        letzte_geoefnete_dateien.set_text(liste);
    }
}

void MainWindow::slotSaveConfig(QString text)
{
    //Sicherheitsabfrage:
    QMessageBox mb;
    mb.setWindowTitle("Konfiguration speichern");
    mb.setText("Sind Sie sicher, dass die Konfoguration gespeichert werden soll?");
    mb.setStandardButtons(QMessageBox::Yes);
    mb.addButton(QMessageBox::No);
    mb.setDefaultButton(QMessageBox::No);
    if(mb.exec() == QMessageBox::Yes)
    {
        //Daten vom Dialog in lokale Variabeln speichern:
        //------------------------------------------------Settings:
        if(text.contains(SETTINGS_PFAD_WERKZEUGE))
        {
            tooltable_path = selektiereEintrag(text, SETTINGS_PFAD_WERKZEUGE, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_ANZ_UNDO_T))
        {
            settings_anz_undo_t = selektiereEintrag(text, SETTINGS_ANZ_UNDO_T, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_ANZ_UNDO_W))
        {
            settings_anz_undo_w = selektiereEintrag(text, SETTINGS_ANZ_UNDO_W, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_DXF_KLASSE_WSTNP))
        {
            dxf_klasse_wstnp = selektiereEintrag(text, SETTINGS_DXF_KLASSE_WSTNP, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_DXF_KLASSE_GEO))
        {
            dxf_klasse_geo = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_DXF_KLASSE_GEO_BEACHTEN))
        {
            dxf_klasse_geo_beachten = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO_BEACHTEN, ENDE_ZEILE);
        }
        if(text.contains(SETTINGS_FKON_BERECHNEN))
        {
            fkon_berechnen = selektiereEintrag(text, SETTINGS_FKON_BERECHNEN, ENDE_ZEILE);
        }
        //------------------------------------------------Dialoge:
        if(text.contains(PROGRAMMKOPF_DIALOG))
        {
            vorlage_pkopf = selektiereEintrag(text, PROGRAMMKOPF_DIALOG, ENDE_ZEILE);
        }else if(text.contains(PROGRAMMENDE_DIALOG))
        {
            vorlage_pende = selektiereEintrag(text, PROGRAMMENDE_DIALOG, ENDE_ZEILE);
        }else if(text.contains(KOMMENTAR_DIALOG))
        {
            vorlage_kommentar = selektiereEintrag(text, KOMMENTAR_DIALOG, ENDE_ZEILE);
        }else if(text.contains(VARIABLE_DIALOG))
        {
            vorlage_variable = selektiereEintrag(text, VARIABLE_DIALOG, ENDE_ZEILE);
        }else if(text.contains(KREISTASCHE_DIALOG))
        {
            vorlage_Ktasche = selektiereEintrag(text, KREISTASCHE_DIALOG, ENDE_ZEILE);
        }else if(text.contains(RECHTECKTASCHE_DIALOG))
        {
            vorlage_Rtasche = selektiereEintrag(text, RECHTECKTASCHE_DIALOG, ENDE_ZEILE);
        }else if(text.contains(FRAESERAUFRUF_DIALOG))
        {
            vorlage_Faufruf = selektiereEintrag(text, FRAESERAUFRUF_DIALOG, ENDE_ZEILE);
        }else if(text.contains(FRAESERGERADE_DIALOG))
        {
            vorlage_Fgerade = selektiereEintrag(text, FRAESERGERADE_DIALOG, ENDE_ZEILE);
        }else if(text.contains(FRAESERBOGEN_DIALOG))
        {
            vorlage_Fbogen = selektiereEintrag(text, FRAESERBOGEN_DIALOG, ENDE_ZEILE);
        }else if(text.contains(FRAESERABFAHREN_DIALOG))
        {
            vorlage_Fabfa = selektiereEintrag(text, FRAESERABFAHREN_DIALOG, ENDE_ZEILE);
        }else if(text.contains(WERKZEUG_DIALOG))
        {
            vorlage_werkzeug = selektiereEintrag(text, WERKZEUG_DIALOG, ENDE_ZEILE);
        }else if(text.contains(BOHREN_DIALOG))
        {
            vorlage_dbohren = selektiereEintrag(text, BOHREN_DIALOG, ENDE_ZEILE);
        }else if(text.contains(SCHLEIFELINEAR_DIALOG))
        {
            vorlage_schleilin = selektiereEintrag(text, SCHLEIFELINEAR_DIALOG, ENDE_ZEILE);
        }else if(text.contains(SCHLEIFENENDE_DIALOG))
        {
            vorlage_schleiend = selektiereEintrag(text, SCHLEIFENENDE_DIALOG, ENDE_ZEILE);
        }

        //Daten in Datei sichern:
        saveConfig();
        //Konfiguration neu laden:
        loadConfig();
        //Anzeige aktualisieren:
        tt.get_prgtext()->aktualisieren();
        vorschauAktualisieren();
    }else
    {
        QMessageBox mb2;
        mb2.setText("Konfiguration wurde nicht geaendert.");
        mb2.exec();
    }
}

QString MainWindow::loadToollistInQStringlist(QString filename)
{
    QString returnString = "OK";


    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        returnString = "Konnte Werkzeugtabelle nicht finden!\nBitte ueberpruefen Sie die Einstellungen.";
    }else
    {        
        while(!file.atEnd())
        {
            QString line = file.readLine();
            tool_tbl += line;            
        }        
        file.close();
    }

    return returnString;
}

//---------------------------------------------------Werkzeug
void MainWindow::on_pushButton_WKZ_Neu_clicked()
{
    if(ui->tabWidget->currentIndex() != INDEX_WERKZEUGLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Werkzeug!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &werkzeug_dialog, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_werkzeug;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_pushButton_WKZ_Speichern_clicked()
{
    //Sicherhietsabfrage:
    QMessageBox mb;
    mb.setWindowTitle("Werkzeugdaten speichern");
    mb.setText("Sind Sie sicher, dass Sie die vorhandenen Daten ueberschreiben wollen?");
    mb.setStandardButtons(QMessageBox::Yes);
    mb.addButton(QMessageBox::No);
    mb.setDefaultButton(QMessageBox::No);

    int mb_returnwert = mb.exec();
    if(mb_returnwert == QMessageBox::No)
    {
        //Abbruch:
        return;
    }

    //Werkzeugliste in String schreiben:
    QString inhaltWerkzeugdatei = w.get_werkzeuge();

    //Daten Speichern:
    QFile file(QDir::homePath() + WKZ_FILE);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
    {
        QMessageBox mb;
        mb.setText("Fehler beim Zugriff auf die Datei \"konfiguration.ini\"");
        mb.exec();
    } else
    {
        file.remove(); //lösche alte Datei wenn vorhanden
        file.close(); //beende Zugriff
        file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
        file.write(inhaltWerkzeugdatei.toUtf8()); //fülle Datei mit Inhalt
        file.close(); //beende Zugriff
        QMessageBox mb;
        mb.setText("Werkzeugdatei wurde erfolgreich geschrieben.");
        mb.exec();
    }
}

void MainWindow::on_pushButton_WKZ_Laden_clicked()
{
    ui->listWidget_Werkzeug->clear();

    QFile file(QDir::homePath() + WKZ_FILE);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox mb;
        mb.setText("Konnte Werkzeugdatei nicht finden!");
        mb.exec();

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
        {
            QMessageBox mb;
            mb.setText("Fehler beim Datei-Zugriff");
            mb.exec();
        }else
        {
            file.write(werkzeug_dialog.getDefault().toUtf8());
            QMessageBox mb;
            mb.setText("Neue, Werkzeugdatei wurde erzeugt.");
            mb.exec();
            file.close();

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QMessageBox mb;
                mb.setText("Konnte Werkzeugdatei nicht finden!");
                mb.exec();
            }else
            {
                text_zeilenweise tz;
                while(!file.atEnd())
                {
                    QString line = file.readLine();
                    if(line.right(1) == "\n")
                    {
                        line = line.left(line.length()-1);
                    }
                    if(tz.zeilenanzahl() == 0)
                    {
                        tz.set_text(line);
                    }else
                    {
                        tz.zeilen_anhaengen(line);
                    }
                }
                w.set_werkezuge(tz.get_text());
                aktualisiere_anzeigetext_wkz();
            }
        }
        file.close();
    } else
    {
        text_zeilenweise tz;
        while(!file.atEnd())
        {
            QString line = file.readLine();
            if(line.right(1) == "\n")
            {
                line = line.left(line.length()-1);
            }
            if(tz.zeilenanzahl() == 0)
            {
                tz.set_text(line);
            }else
            {
                tz.zeilen_anhaengen(line);
            }
        }
        w.set_werkezuge(tz.get_text());
        aktualisiere_anzeigetext_wkz();
        file.close();
    }
}

void MainWindow::on_pushButton_WKZ_Export_an_EMC2_clicked()
{
    if(hat_werkzeugliste_fehler())
    {
        return;
    }

    //Prüfen ob Einstellungen stimmen:
    if(tooltable_path == NICHT_DEFINIERT  ||  tooltable_path.isEmpty())
    {
        QMessageBox mb;
        mb.setText("Pfad zur Werkzeugtabelle konnt nicht gefunden werden!\nBitte ueberpruefen Sie die Einstellungen.\n");
        mb.exec();
        //Abbruch:
        return;
    }

    //Sicherhietsabfrage:
    QMessageBox mb;
    mb.setWindowTitle("Werkzeugdaten an EMC2 exportieren");
    mb.setText("Sind Sie sicher, dass Sie die vorhandenen Daten ueberschreiben wollen?");
    mb.setStandardButtons(QMessageBox::Yes);
    mb.addButton(QMessageBox::No);
    mb.setDefaultButton(QMessageBox::No);

    int mb_returnwert = mb.exec();
    if(mb_returnwert == QMessageBox::No)
    {
        //Abbruch:
        return;
    }

    //Backup von alter Werkzeugdatei speichern
    QFile file(tooltable_path);
    file.remove(tooltable_path + DATEIENDUNG_BACKUP);//altes Backup löschen
    file.copy(tooltable_path + DATEIENDUNG_BACKUP);//neues Backup anlegen

    //Inhalt für die Datei in string schreiben:
    QString inhalt_Werkzeugdatei;
    QString zeile;
    text_zeilenweise tz = w.get_werkzeuge_zeilenweise();
    for(uint i = 1; i <= tz.zeilenanzahl(); i++)
    {
        zeile = tz.zeile(i);
        if(selektiereEintrag(zeile, WKZ_Nummer, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_Nummer;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_Nummer, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_STECKPLATZ, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_STECKPLATZ;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_STECKPLATZ, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_X, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_X;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_X, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_Y, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_Y;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_Y, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_Z, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_Z;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_Z, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_A, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_A;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_A, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_B, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_B;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_B, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_C, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_C;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_C, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_U, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_U;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_U, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_V, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_V;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_V, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_OFFSET_W, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_OFFSET_W;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_OFFSET_W, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_DURCHMESSER;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_FRONTWINKEL, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_FRONTWINKEL;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_FRONTWINKEL, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_RUECKWINKEL, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_RUECKWINKEL;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_RUECKWINKEL, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        if(selektiereEintrag(zeile, WKZ_RICHTUNG, WKZ_ENDE_EINTRAG) != "") //Wenn hier Daten vorliegen
        {
            inhalt_Werkzeugdatei += EMC2_WKZ_RICHTUNG;
            inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_RICHTUNG, WKZ_ENDE_EINTRAG);
            inhalt_Werkzeugdatei += " ";
        }
        inhalt_Werkzeugdatei += EMC2_WKZ_KOMMENTAR;
        inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_NAME, WKZ_ENDE_EINTRAG);
        inhalt_Werkzeugdatei += "/";
        inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_DREHRICHTUNG, WKZ_ENDE_EINTRAG);
        inhalt_Werkzeugdatei += "/";
        inhalt_Werkzeugdatei += selektiereEintrag(zeile, WKZ_KOMMENTAR, WKZ_ENDE_EINTRAG);
        inhalt_Werkzeugdatei += "\n";
    }

    //Kommas durch Punkte ersetzen:
    inhalt_Werkzeugdatei.replace(",", ".");


    //Werkzeugdatei überschreiben
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
    {
        QMessageBox mb;
        mb.setText("Fehler beim Zugriff auf die Werkzeugdatei");
        mb.exec();
    } else
    {
        file.remove(); //lösche alte Datei wenn vorhanden
        file.close(); //beende Zugriff
        file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
        file.write(inhalt_Werkzeugdatei.toUtf8()); //fülle Datei mit Inhalt
        file.close(); //beende Zugriff
        QMessageBox mb;
        mb.setText("Werkzeugdatei wurde erfolgreich geschrieben.");
        mb.exec();
    }
}

bool MainWindow::hat_werkzeugliste_fehler()
{
    //alle Einträge wieder schwarz einfärben wenn nicht schon sind:
    for(int i = 0; i < ui->listWidget_Werkzeug->count(); i++)
    {
        QColor farbe(0,0,0);//schwarz
        ui->listWidget_Werkzeug->item(i)->setForeground(QBrush(farbe));
    }

    text_zeilenweise tz = w.get_werkzeuge_zeilenweise();

    //Prüfen, ob Werkzeugnumern doppelt vergeben sind
    for(uint i = 1; i <= tz.zeilenanzahl(); i++)
    {
        QString zeile = tz.zeile(i);
        QString nummer = text_mitte(zeile, WKZ_Nummer, ENDE_EINTRAG);
        for(uint j=i+1; j<=tz.zeilenanzahl() ; j++)
        {
            QString zeile2 = tz.zeile(j);
            QString nummer2 = text_mitte(zeile2, WKZ_Nummer, ENDE_EINTRAG);
            if(nummer == nummer2)
            {
                QColor farbe(205,0,0);//rot
                ui->listWidget_Werkzeug->item(i-1)->setForeground(QBrush(farbe));
                ui->listWidget_Werkzeug->item(j-1)->setForeground(QBrush(farbe));
                QMessageBox mb;
                mb.setText("Fehler!\n Werkzeugnummern " + nummer + " doppelt vorhanden");
                mb.exec();
                return true;//Fehler gefunden
            }
        }
    }
    //Prüfen, ob Werkzeugnamen doppelt vergeben sind
    for(uint i = 1; i <= tz.zeilenanzahl(); i++)
    {
        QString zeile = tz.zeile(i);
        QString tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
        for(uint j=i+1; j<=tz.zeilenanzahl() ; j++)
        {
            QString zeile2 = tz.zeile(j);
            QString tmp2 = text_mitte(zeile2, WKZ_NAME, ENDE_EINTRAG);
            if(tmp == tmp2)
            {
                QColor farbe(205,0,0);//rot
                ui->listWidget_Werkzeug->item(i-1)->setForeground(QBrush(farbe));
                ui->listWidget_Werkzeug->item(j-1)->setForeground(QBrush(farbe));
                QMessageBox mb;
                mb.setText("Fehler!\n Werkzeugname " + tmp + " doppelt vorhanden");
                mb.exec();
                return true;//Fehler gefunden
            }
        }
    }
    //Prüfen, ob Werkzeugsteckplätze doppelt belegt sind
    for(uint i = 1; i <= tz.zeilenanzahl(); i++)
    {
        QString zeile = tz.zeile(i);
        QString tmp = text_mitte(zeile, WKZ_STECKPLATZ, ENDE_EINTRAG);
        for(uint j=i+1; j<=tz.zeilenanzahl() ; j++)
        {
            QString zeile2 = tz.zeile(j);
            QString tmp2 = text_mitte(zeile2, WKZ_STECKPLATZ, ENDE_EINTRAG);
            if(tmp == tmp2)
            {
                QColor farbe(205,0,0);//rot
                ui->listWidget_Werkzeug->item(i-1)->setForeground(QBrush(farbe));
                ui->listWidget_Werkzeug->item(j-1)->setForeground(QBrush(farbe));
                QMessageBox mb;
                mb.setText("Fehler!\n Werkzeugsteckplatz " + tmp + " doppelt belegt");
                mb.exec();
                return true;//Fehler gefunden
            }
        }
    }
    return false; //keine Fehler gefunden
}

bool MainWindow::ladeWerkzeugnamen()
{
    werkzeugnamen.clear();
    //Prüfen, ob Werkzeug vorhanden ist:
    if(ui->listWidget_Werkzeug->count() == 0)
    {
        QMessageBox mb;
        mb.setText("Kein Werkzeug in der Liste gefunden!");
        mb.exec();
        return true; //Ein Fehler ist aufgetreten
    }else
    {
        for(int i = 0; i < ui->listWidget_Werkzeug->count(); i++)
        {
            QString tmp = w.zeile(i+1);
            if(tmp != LISTENENDE)
            {
                werkzeugnamen.append(selektiereEintrag(tmp , WKZ_NAME, WKZ_ENDE_EINTRAG));
            }
        }
        //-------------------------------------------------------------
        wkznamen_nur_bohrer.clear();
        text_zeilenweise tz = w.get_werkzeuge_zeilenweise();
        for(uint i=1; i<=tz.zeilenanzahl() ;i++)
        {
            QString kannbohren = selektiereEintrag(tz.zeile(i), WKZ_KANN_BOHREN, ENDE_EINTRAG);
            if(kannbohren == "1")
            {
                wkznamen_nur_bohrer.append(selektiereEintrag(tz.zeile(i), WKZ_NAME, ENDE_EINTRAG));
            }
        }
        //-------------------------------------------------------------
        wkznamen_nur_fraeser.clear();
        //text_zeilenweise tz = w.get_werkzeuge_zeilenweise();
        for(uint i=1; i<=tz.zeilenanzahl() ;i++)
        {
            QString kannfraesen = selektiereEintrag(tz.zeile(i), WKZ_KANN_FRAESEN, ENDE_EINTRAG);
            if(kannfraesen == "1")
            {
                wkznamen_nur_fraeser.append(selektiereEintrag(tz.zeile(i), WKZ_NAME, ENDE_EINTRAG));
            }
        }
        //-------------------------------------------------------------
        return false; //Kein Fehler ist aufgetreten
    }
}

void MainWindow::slotAnfrageWerkzeugnamen(QString dialogName)
{
    if(dialogName == KREISTASCHE_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugNamen(QStringList)), &ktasche, SLOT(getWerkzeugNamen(QStringList)));
        emit sendWerkzeugNamen(werkzeugnamen);
    }else if(dialogName == RECHTECKTASCHE_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugNamen(QStringList)), &rtasche, SLOT(getWerkzeugNamen(QStringList)));
        emit sendWerkzeugNamen(werkzeugnamen);
    }else if(dialogName == BOHREN_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugNamen(QStringList)), &dbohren, SLOT(getWerkzeugNamen(QStringList)));
        emit sendWerkzeugNamen(wkznamen_nur_bohrer);
    }
}

void MainWindow::slotAnfrageWerkzeugdaten(QString Werkzeugname, QString Dialog)
{
    disconnect(this, SIGNAL(sendWerkzeugdaten(QString)));
    QString daten = werkzeugdaten(Werkzeugname);

    if(Dialog == KREISTASCHE_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugdaten(QString)), &ktasche, SLOT(getWerkzeugdaten(QString)));
        emit sendWerkzeugdaten(daten);
    }else if(Dialog == RECHTECKTASCHE_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugdaten(QString)), &rtasche, SLOT(getWerkzeugdaten(QString)));
        emit sendWerkzeugdaten(daten);
    }else if(Dialog == BOHREN_DIALOG)
    {
        connect(this, SIGNAL(sendWerkzeugdaten(QString)), &dbohren, SLOT(getWerkzeugdaten(QString)));
        emit sendWerkzeugdaten(daten);
    }
}

QString MainWindow::werkzeugdaten(QString werkzeugname)
{
    QString daten;
    text_zeilenweise tz = w.get_werkzeuge_zeilenweise();
    for(uint i=1; i <= tz.zeilenanzahl() ; i++)
    {
        QString zeile = tz.zeile(i);
        if(zeile.contains(werkzeugname))
        {
            daten = zeile;
            break;
        }
    }
    return daten;
}

//---------------------------------------------------Ändern Funktionen

void MainWindow::on_actionEntfernen_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }

            if(items_menge == 1)
            {
                QString tmp = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
                if(tmp == LISTENENDE)
                {
                    return;
                }
                tt.get_prgtext()->zeile_loeschen(ui->listWidget_Programmliste->currentRow()+1);
                aktualisiere_anzeigetext();
            }else
            {
                tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
            }

        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was geloescht werden kann!");
            mb.exec();
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        if((ui->listWidget_Werkzeug->currentIndex().isValid())  &&  (ui->listWidget_Werkzeug->currentItem()->isSelected()))
        {
            QString tmp = w.zeile(ui->listWidget_Werkzeug->currentRow()+1);
            if(tmp == LISTENENDE)
            {
                return;
            }
            w.zeile_loeschen(ui->listWidget_Werkzeug->currentRow()+1);
            aktualisiere_anzeigetext_wkz();
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was geloescht werden kann!");
            mb.exec();
        }
    }
    vorschauAktualisieren();
    update_windowtitle();
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionKopieren_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }

            if(items_menge==1)
            {
                QString tmp = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
                if(tmp == LISTENENDE)
                {
                    return;
                }
                kopierterEintrag_t = tmp;
            }else
            {
                QString tmp = tt.get_prgtext()->zeilen(row_erstes+1, items_menge);
                kopierterEintrag_t = tmp;
            }

        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was kopiert werden kann!");
            mb.exec();
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        if((ui->listWidget_Werkzeug->currentIndex().isValid())  &&  (ui->listWidget_Werkzeug->currentItem()->isSelected()))
        {
            QString tmp = w.zeile(ui->listWidget_Werkzeug->currentRow()+1);
            if(tmp == LISTENENDE)
            {
                return;
            }
            kopiertesWerkzeug = tmp;
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was kopiert werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionEinfuegen_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if(kopierterEintrag_t != NICHT_DEFINIERT)
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }

            //Einfügen über ausgewähltem Eintrag:
            text_zeilenweise tmp_tz;
            tmp_tz.set_text(kopierterEintrag_t);
            if(tmp_tz.zeilenanzahl()==1)
            {
                tt.get_prgtext()->zeile_einfuegen(ui->listWidget_Programmliste->currentRow()-items_menge+1 \
                                                 , kopierterEintrag_t);
                int row = aktualisiere_anzeigetext()-items_menge+2 ;
                ui->listWidget_Programmliste->setCurrentRow(row);
            }else
            {
                tt.get_prgtext()->zeilen_einfuegen(row_erstes, kopierterEintrag_t);
                int row = aktualisiere_anzeigetext()-items_menge+2+tmp_tz.zeilenanzahl()-1 ;
                ui->listWidget_Programmliste->setCurrentRow(row);
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts kopiert!");
            mb.exec();
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        if(kopiertesWerkzeug != NICHT_DEFINIERT)
        {
            //Einfügen über ausgewähltem Eintrag:
            w.zeile_einfuegen(ui->listWidget_Werkzeug->currentRow() , kopiertesWerkzeug);
            aktualisiere_anzeigetext_wkz();
            //neu eingefügte Zeile aktivieren:
            int row = aktualisiere_anzeigetext_wkz();
            ui->listWidget_Werkzeug->item(row)->setSelected(true);
            ui->listWidget_Werkzeug->setCurrentRow(row);

        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts kopiert!");
            mb.exec();
        }
        //Dialog öffnen zum Bearbeiten des eingefügten Werkzeuges:
        QListWidgetItem *item = ui->listWidget_Werkzeug->currentItem();
        on_listWidget_Werkzeug_itemDoubleClicked(item);
    }
    vorschauAktualisieren();
    update_windowtitle();
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionAusschneiden_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }

            if(items_menge==1)
            {
                QString tmp = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
                if(tmp == LISTENENDE)
                {
                    return;
                }
                kopierterEintrag_t = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
                tt.get_prgtext()->zeile_loeschen(ui->listWidget_Programmliste->currentRow()+1);
                aktualisiere_anzeigetext();
            }else
            {
                //Zeilen kopieren:
                QString tmp = tt.get_prgtext()->zeilen(row_erstes+1, items_menge);
                kopierterEintrag_t = tmp;
                //Zeilen löschen:
                tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
            }

        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was ausgeschnitten werden kann!");
            mb.exec();
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        if((ui->listWidget_Werkzeug->currentIndex().isValid())  &&  (ui->listWidget_Werkzeug->currentItem()->isSelected()))
        {
            QString tmp = w.zeile(ui->listWidget_Werkzeug->currentRow()+1);
            if(tmp == LISTENENDE)
            {
                return;
            }
            kopiertesWerkzeug = w.zeile(ui->listWidget_Werkzeug->currentRow()+1);
            w.zeile_loeschen(ui->listWidget_Werkzeug->currentRow()+1);
            aktualisiere_anzeigetext_wkz();
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was ausgeschnitten werden kann!");
            mb.exec();
        }
    }
    vorschauAktualisieren();
    update_windowtitle();
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionAendern_triggered()
{
    disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
    disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);

    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was geaendert werden kann!");
                mb.exec();
                return;
            }
            //ermitteln an welches Unterfenster der string gehen soll und die Zeile Übergeben:
            if(programmzeile.contains(PROGRAMMKOPF_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString,bool)), &pkopf, SLOT(getDialogData(QString,bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(PROGRAMMENDE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString,bool)), &pende, SLOT(getDialogData(QString,bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(KOMMENTAR_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &kommentar, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(VARIABLE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &variable, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(KREISTASCHE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &ktasche, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(programmzeile, true, werkzeugnamen);
            }else if(programmzeile.contains(RECHTECKTASCHE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(programmzeile, true, werkzeugnamen);
            }else if(programmzeile.contains(FRAESERAUFRUF_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList, werkzeug)), &faufruf, SLOT(getDialogData(QString, bool, QStringList, werkzeug)));
                emit sendDialogData(programmzeile, true, werkzeugnamen, w);
            }else if(programmzeile.contains(FRAESERGERADE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &fgerade, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(FRAESERBOGEN_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &fbogen, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(FRAESERABFAHREN_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &fabfa, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(KREIS))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dkreis, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(STRECKE))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dstrecke, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(BOGEN))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dbogen, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(BOHREN_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &dbohren, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(programmzeile, true, wkznamen_nur_bohrer);
            }else if(programmzeile.contains(SCHLEIFELINEAR_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dschleilin, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }else if(programmzeile.contains(SCHLEIFENENDE_DIALOG))
            {
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dschleiend, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(programmzeile, true);
            }
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        //text aus der aktiven Zeile in string speichern:
       QString werkzeugzeile;
       if(ui->listWidget_Werkzeug->currentIndex().isValid()  &&  (ui->listWidget_Werkzeug->currentItem()->isSelected()))
       {
           werkzeugzeile = w.zeile(ui->listWidget_Werkzeug->currentRow()+1);
           if(werkzeugzeile == LISTENENDE)
           {
               return;
           }
       } else
       {
           QMessageBox mb;
           mb.setText("Sie haben noch nichts ausgewaelt was geaendert werden kann!");
           mb.exec();
           return;
       }
        connect(this, SIGNAL(sendDialogData(QString, bool)), &werkzeug_dialog, SLOT(getDialogData(QString, bool)));
        emit sendDialogData(werkzeugzeile, true);
    }
}

void MainWindow::on_listWidget_Programmliste_doubleClicked(const QModelIndex &index)
{
    QModelIndex index2 = index; //Zeile nur da, damit keine Warnung vom Compiler, dass Variable ungenutzt ist
    emit on_actionAendern_triggered();
}

void MainWindow::on_listWidget_Werkzeug_itemDoubleClicked(QListWidgetItem *item)
{
    item = item; //Zeile nur da, damit keine Warnung vom Compiler, dass Variable ungenutzt ist
    emit on_actionAendern_triggered();
}

void MainWindow::getImportGGF(QString text)
{
    QString tmp = kopierterEintrag_t;
    kopierterEintrag_t = text;
    on_actionEinfuegen_triggered();
    kopierterEintrag_t = tmp;
}

//---------------------------------------------------Dialoge
void MainWindow::getDialogData(QString text)
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        text_zeilenweise at = tt.get_prgtext()->get_anzeigetext_zeilenweise();
        if(at.zeilenanzahl() == 0)
        {
            tt.get_prgtext()->zeile_anhaengen(text);
            aktualisiere_anzeigetext();
            pruefe_benutzereingaben(ui->listWidget_Programmliste->currentRow()+1);
        }else
        {
            //Zeile über aktiver Zeile einfügen:
            tt.get_prgtext()->zeile_einfuegen(ui->listWidget_Programmliste->currentRow(), text);
            //aktualisieren und Element darunter aktivieren:
            int row = aktualisiere_anzeigetext() + 1;
            ui->listWidget_Programmliste->setCurrentRow(row);
            pruefe_benutzereingaben(ui->listWidget_Programmliste->currentRow());
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        text_zeilenweise at = w.get_anzeigetext_zeilenweise();
        if(at.zeilenanzahl() == 0)
        {
            w.zeile_anhaengen(text);
            aktualisiere_anzeigetext_wkz();
        }else
        {
            //Zeile über aktiver Zeile einfügen:
            w.zeile_einfuegen(ui->listWidget_Werkzeug->currentRow(), text);
            //aktualisieren und Element darunter aktivieren:
            int row = aktualisiere_anzeigetext_wkz() + 1;
            ui->listWidget_Werkzeug->item(row)->setSelected(true);
            ui->listWidget_Werkzeug->setCurrentRow(row);
        }
        ladeWerkzeugnamen();
        hat_werkzeugliste_fehler();
    }
    vorschauAktualisieren();
    update_windowtitle();
}

void MainWindow::getDialogDataModify(QString text)
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QString text_alt = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
        if(text != text_alt)
        {
            if(elementIstEingeblendet())
            {
                tt.get_prgtext()->zeile_ersaetzen(ui->listWidget_Programmliste->currentRow()+1, text);
                aktualisiere_anzeigetext();
                pruefe_benutzereingaben(ui->listWidget_Programmliste->currentRow()+1);
            }else
            {
                tt.get_prgtext()->zeile_ersaetzen(ui->listWidget_Programmliste->currentRow()+1, "//"+text);
                aktualisiere_anzeigetext();
            }
        }
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        w.zeile_ersaetzen(ui->listWidget_Werkzeug->currentRow()+1, text);
        aktualisiere_anzeigetext_wkz();
        ladeWerkzeugnamen();
        hat_werkzeugliste_fehler();
    }
    vorschauAktualisieren();
    update_windowtitle();
}

void MainWindow::on_actionEinstellungen_triggered()
{
    disconnect(this, SIGNAL(sendDialogData(QString,bool)), 0, 0);
    connect(this, SIGNAL(sendDialogData(QString,bool)), &dsettings, SLOT(getDialogData(QString,bool)));
    QString msg;
    msg =  SETTINGS_PFAD_WERKZEUGE;
    msg += tooltable_path;
    msg += ENDE_ZEILE;
    msg += SETTINGS_ANZ_UNDO_T;
    msg += settings_anz_undo_t;
    msg += ENDE_ZEILE;
    msg += SETTINGS_ANZ_UNDO_W;
    msg += settings_anz_undo_w;
    msg += ENDE_ZEILE;
    msg += SETTINGS_DXF_KLASSE_WSTNP;
    msg += dxf_klasse_wstnp;
    msg += ENDE_ZEILE;
    msg += SETTINGS_DXF_KLASSE_GEO;
    msg += dxf_klasse_geo;
    msg += ENDE_ZEILE;
    msg += SETTINGS_DXF_KLASSE_GEO_BEACHTEN;
    msg += dxf_klasse_geo_beachten;
    msg += ENDE_ZEILE;
    msg += SETTINGS_FKON_BERECHNEN;
    msg += fkon_berechnen;
    msg += ENDE_ZEILE;
    emit sendDialogData(msg, false);
}

void MainWindow::on_actionWerkzeugliste_triggered()
{
    tool_tbl.clear();
    this->loadConfig();
    QString msg = this->loadToollistInQStringlist(tooltable_path);
    if(msg != "OK")
    {
        QMessageBox mb;
        mb.setText(msg);
        mb.exec();
    }else
    {
        QString text;
        for (int i = 0; i<tool_tbl.size() ; ++i)
            {

            text += tool_tbl.at(i);
            }
        QMessageBox mb;
        mb.setText(text);
        mb.exec();
    }

}

void MainWindow::on_actionMakeProgrammkopf_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString,bool)), &pkopf, SLOT(getDialogData(QString,bool)));
        QString msg = vorlage_pkopf;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeKommentar_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &kommentar, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_kommentar;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeProgrammende_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &pende, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_pende;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeVariable_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &variable, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_variable;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeKreistasche_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &ktasche, SLOT(getDialogData(QString, bool, QStringList)));
        QString msg = vorlage_Ktasche;
        emit sendDialogData(msg, false, wkznamen_nur_fraeser);
    }
}

void MainWindow::on_actionMakeRechtecktasche_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
        QString msg = vorlage_Rtasche;
        emit sendDialogData(msg, false, wkznamen_nur_fraeser);
    }
}

void MainWindow::on_actionMakeFraeser_Aufruf_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList, werkzeug)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool, QStringList, werkzeug)), &faufruf, SLOT(getDialogData(QString, bool, QStringList, werkzeug)));
        QString msg = vorlage_Faufruf;
        emit sendDialogData(msg, false, wkznamen_nur_fraeser, w);
    }
}

void MainWindow::on_actionMakeGerade_Fraesbahn_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &fgerade, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_Fgerade;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeGebogene_Fraesbahn_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &fbogen, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_Fbogen;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeAbfahren_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &fabfa, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_Fabfa;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeKreis_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &dkreis, SLOT(getDialogData(QString, bool)));
        kreis k;
        k.set_farbe(FARBE_GRUEN);
        emit sendDialogData(k.get_text(), false);
    }
}

void MainWindow::on_actionMakeStrecke_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &dstrecke, SLOT(getDialogData(QString, bool)));
        strecke s;
        s.set_farbe(FARBE_GRUEN);
        emit sendDialogData(s.get_text(), false);
    }
}

void MainWindow::on_actionMakeBogen_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &dbogen, SLOT(getDialogData(QString, bool)));
        bogen b;
        b.set_farbe(FARBE_GRUEN);
        emit sendDialogData(b.get_text(), false);
    }
}

void MainWindow::on_actionMakeBohren_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &dbohren, SLOT(getDialogData(QString, bool, QStringList)));
        QString msg = vorlage_dbohren;
        emit sendDialogData(msg, false, wkznamen_nur_bohrer);
    }
}

void MainWindow::on_actionMakeSchleife_linear_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &dschleilin, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_schleilin;
        emit sendDialogData(msg, false);
    }
}

void MainWindow::on_actionMakeSchleifenende_triggered()
{
    if(ui->tabWidget->currentIndex() != INDEX_PROGRAMMLISTE)
    {
        QMessageBox mb;
        mb.setText("Bitte wechseln Sie zuerst in den TAB Programmliste!");
        mb.exec();
    }else
    {
        disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
        connect(this, SIGNAL(sendDialogData(QString, bool)), &dschleiend, SLOT(getDialogData(QString, bool)));
        QString msg = vorlage_schleiend;
        emit sendDialogData(msg, false);
    }
}

//---------------------------------------------------Datei
void MainWindow::on_actionDateiNeu_triggered()
{
    int max = ANZAHL_OFFENER_DATEIEN;
    if(tt.get_size() >= max)
    {
        QString msg;
        msg += "Bitter zuerst eine Datei schliessen!\n";
        msg += "Es koennen maximal ";
        msg += int_to_qstring(max);
        msg += " Dateien gleichzeitig offen sein!";
        QMessageBox mb;
        mb.setText(msg);
        mb.exec();
        return;
    }
    programmtext t;
    t.set_text("");
    QString name = "Unbekannt ";
    anz_neue_dateien++;
    name += int_to_qstring(anz_neue_dateien);
    undo_redo tmpur;
    tmpur.set_groesse_max(settings_anz_undo_t.toInt());
    tt.add(t, name, tmpur);
    update_gui();
    ui->listWidget_Programmliste->item(0)->setSelected(true);
    ui->listWidget_Programmliste->setCurrentRow(0);
}

void MainWindow::on_actionDateiOefnen_triggered()
{
    int max = ANZAHL_OFFENER_DATEIEN;
    if(tt.get_size() >= max)
    {
        QString msg;
        msg += "Bitter zuerst eine Datei schliessen!\n";
        msg += "Es koennen maximal ";
        msg += int_to_qstring(max);
        msg += " Dateien gleichzeitig offen sein!";
        QMessageBox mb;
        mb.setText(msg);
        mb.exec();
        return;
    }else
    {
        //Dialog öffnen zum Wählen der Datei:
        QString pfad = QFileDialog::getOpenFileName(this, tr("Waehle GecodeGernerator-Datei"), \
                                                    pfad_oefne_ggf, tr("ggf Dateien (*.ggf)"));
        if(!pfad.isEmpty())
        {
            openFile(pfad);
        }
    }
}

void MainWindow::aktuelisiere_letzte_dateien_inifile()
{
    if(tt.dateien_sind_offen() == true)
    {
        letzte_geoefnete_dateien.datei_merken(tt.get_prgname());
    }
    //Daten Speichern:
    QFile inifile(QDir::homePath() + PFAD_LETZTE_DATEIEN);
    if (!inifile.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
    {
        QMessageBox mb;
        mb.setText("Fehler beim Zugriff auf die Datei \"letzte_dateien.ini\"");
        mb.exec();
    } else
    {
        inifile.remove(); //lösche alte Datei wenn vorhanden
        inifile.close(); //beende Zugriff
        inifile.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
        inifile.write(letzte_geoefnete_dateien.get_text().toUtf8()); //fülle Datei mit Inhalt
        inifile.close(); //beende Zugriff
    }
}

void MainWindow::aktualisiere_letzte_dateien_menu()
{
    ui->menuLetzte_Dateien->clear();

    text_zeilenweise namen;
    namen.set_text(letzte_geoefnete_dateien.get_text());
    for(uint i=1; i<=namen.zeilenanzahl() ;i++)
    {
        oefneLetzteDateien[i-1] = new QAction(namen.zeile(i), this);
        ui->menuLetzte_Dateien->addAction(oefneLetzteDateien[i-1]);
        oefneLetzteDateien[i-1]->setData(namen.zeile(i));
        connect(oefneLetzteDateien[i-1], SIGNAL(triggered()), \
                this, SLOT(actionLetzteDateiOefnenTriggered()));
    }

}

void MainWindow::aktualisiere_offene_dateien_menu()
{
    ui->menuOffene_Dateien->clear();

    text_zeilenweise namen;
    namen = tt.get_names();
    for(uint i=1; i<=namen.zeilenanzahl() ;i++)
    {
        OffeneDateieFokus[i-1] = new QAction(namen.zeile(i), this);
        ui->menuOffene_Dateien->addAction(OffeneDateieFokus[i-1]);
        OffeneDateieFokus[i-1]->setData(namen.zeile(i));
        connect(OffeneDateieFokus[i-1], SIGNAL(triggered(bool)),        \
                this, SLOT(actionFokuswechselOffeneDateiTriggered())    );
    }
}

void MainWindow::actionFokuswechselOffeneDateiTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString msg = action->data().toString();
        tt.set_current_index(msg);
        update_gui();
    }
}

void MainWindow::actionLetzteDateiOefnenTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString msg = action->data().toString();
        int max = ANZAHL_OFFENER_DATEIEN;
        if(tt.get_size() >= max)
        {
            QString msg;
            msg += "Bitter zuerst eine Datei schliessen!\n";
            msg += "Es koennen maximal ";
            msg += int_to_qstring(max);
            msg += " Dateien gleichzeitig offen sein!";
            QMessageBox mb;
            mb.setText(msg);
            mb.exec();
            return;
        }else
        {
            openFile(msg);
        }
    }

}

void MainWindow::openFile(QString pfad)
{
    //Prüfen, ob Datei bereits geöffnet ist:
    if(tt.isopen(pfad))
    {
        tt.set_current_index(pfad);
        update_gui();
    }else
    {
        //Maschinengeometrie laden:
        text_zeilenweise maschinengeometrie;
        QFile fileMaschiene(QDir::homePath() + QDir::separator() + CAD_Maschine);
        if (fileMaschiene.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!fileMaschiene.atEnd())
            {
                QString line = fileMaschiene.readLine();
                if(line.right(1) == "\n")
                {
                    line = line.left(line.length()-1);
                }
                if(maschinengeometrie.zeilenanzahl() == 0)
                {
                    maschinengeometrie.set_text(line);
                }else
                {
                    maschinengeometrie.zeilen_anhaengen(line);
                }
            }
            maschinengeometrie = kompatiblitaetspruefung(maschinengeometrie);
        }

        QFile file(pfad);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //Programmdatei laden:
            QFileInfo info = pfad;
            pfad_oefne_ggf = info.path();
            QApplication::setOverrideCursor(Qt::WaitCursor);
            text_zeilenweise tz;
            while(!file.atEnd())
            {
                QString line = file.readLine();
                if(line.right(1) == "\n")
                {
                    line = line.left(line.length()-1);
                }
                if(tz.zeilenanzahl() == 0)
                {
                    tz.set_text(line);
                }else
                {
                    tz.zeilen_anhaengen(line);
                }
            }
            tz = kompatiblitaetspruefung(tz);
            programmtext t;
            t.set_text(tz.get_text());
            t.aktualisieren_fkon_ein_aus(tt.get_aktualisieren_fkon_ein_aus());
            undo_redo tmpur;
            tmpur.set_groesse_max(settings_anz_undo_t.toInt());
            tt.add(t, pfad, tmpur);
            tt.get_prgtext()->set_maschinengeometrie(tz);
            file.close();

            aktuelisiere_letzte_dateien_inifile();
            aktualisiere_letzte_dateien_menu();
            tt.get_prgtext()->wurde_gespeichert();
            update_gui();
            QApplication::restoreOverrideCursor();
        }else
        {
            if(!file.exists())
            {
                QMessageBox mb;
                mb.setText("Datei existiert nicht mehr oder wurde verschoben oder umbenannt!");
                mb.exec();
            }else
            {
                QMessageBox mb;
                mb.setText("Datei existiert, konnte jedoch nicht geoeffnet werden!");
                mb.exec();
            }
            letzte_geoefnete_dateien.datei_vergessen(pfad);
            aktualisiere_letzte_dateien_menu();
            aktuelisiere_letzte_dateien_inifile();
        }
    }
}

text_zeilenweise MainWindow::kompatiblitaetspruefung(text_zeilenweise dateiinhalt)
{
    QString versionsinfo = PROGRAMMNAME;
    if(!dateiinhalt.zeile(1).contains(versionsinfo))//Programmversion 1
    {
        //Kompatibilität zur aktuellen Version wieder herstellen:
        for(uint i=1; i<=dateiinhalt.zeilenanzahl() ;i++)
        {
            QString zeile = dateiinhalt.zeile(i);
            zeile.replace("punkt", "cadpunkt");
            zeile.replace("strecke", "cadstrecke");
            zeile.replace("bogen", "cadbogen");
            zeile.replace("kreis", "cadkreis");
            zeile.replace("zylinder", "cadzylinder");
            zeile.replace("rechteck3d", "cadrechteck3d");
            zeile.replace("wuerfel", "cadwuerfel");
            dateiinhalt.zeile_ersaetzen(i, zeile);
        }
    }else
    {
        //ab Version 2 ist die Programmversion in den GGF-Dateien hinterlegt
        versionsinfo = dateiinhalt.zeile(1);
        //und muss vor weiterem Gebrauch entfernt werden:
        dateiinhalt.zeile_loeschen(1);
    }

    return dateiinhalt;
}

void MainWindow::on_import_GGF_triggered()
{
    //Dialog öffnen zum Wählen der Datei:
    QString dateipfad = QFileDialog::getOpenFileName(this, tr("Waehle GecodeGernerator-Datei"), \
                                                     pfad_import_ggf, tr("ggf Dateien (*.ggf)"));
    if(!dateipfad.isEmpty())
    {
        QFileInfo info = dateipfad;
        pfad_import_ggf = info.path();

        QFile file(dateipfad);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //QApplication::setOverrideCursor(Qt::WaitCursor);
            text_zeilenweise tz;
            while(!file.atEnd())
            {
                QString line = file.readLine();
                if(line.contains(PROGRAMMKOPF_DIALOG) ||\
                   line.contains(PROGRAMMENDE_DIALOG))
                {
                    continue;
                }
                if(line.contains(LISTENENDE))
                {
                    break;
                }
                if(line.right(1) == "\n")
                {
                    line = line.left(line.length()-1);
                }
                if(tz.zeilenanzahl() == 0)
                {
                    tz.set_text(line);
                }else
                {
                    tz.zeilen_anhaengen(line);
                }
            }
            file.close();
            tz = kompatiblitaetspruefung(tz);

            emit sendTextToImportGGF(tz.get_text());

            //QApplication::restoreOverrideCursor();
        }
    }
}

void MainWindow::on_import_DXF_triggered()
{
    //Dialog öffnen zum Wählen der Datei:
    QString dateipfad = QFileDialog::getOpenFileName(this, tr("Waehle GecodeGernerator-Datei"), \
                                                     pfad_import_dxf , tr("DXF Dateien (*.dxf)"));
    if(!dateipfad.isEmpty())
    {
        QFileInfo info = dateipfad;
        pfad_import_dxf = info.path();

        QFile file(dateipfad);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //QApplication::setOverrideCursor(Qt::WaitCursor);
            text_zeilenweise tz;
            bool bin_im_geometriebereich = false;
            uint zeilennummer = 0;
            QString dxfversion;
            //DXF 2000 von LibrecAD 1.0.2 == "dxflib 2.2.0.0"
            //DXF 2007 von LibreCAD 2.0.9 == "dxfrw 0.6.3"
            const QString dxf2000 = "dxflib 2.2.0.0";
            const QString dxf2007 = "dxfrw 0.6.3";

            while(!file.atEnd())
            {
                zeilennummer++;
                QString line = file.readLine();
                if(line.right(1) == "\n")
                {
                    line = line.left(line.length()-1);
                }
                if(zeilennummer == 2)
                {
                    dxfversion = line;
                }
                if(line.contains("ENTITIES"))
                {
                    bin_im_geometriebereich = true;
                }else if(line.contains("ENDSEC"))
                {
                    bin_im_geometriebereich = false;
                }
                if(bin_im_geometriebereich)
                {
                    tz.zeilen_anhaengen(line);
                }
            }
            file.close();

            if(dxfversion != dxf2000 && \
               dxfversion != dxf2007)
            {
                QMessageBox mb;
                mb.setText("Diese DXF-Version wird nicht unterstuetzt!");
                mb.exec();
                return;
            }

            punkt3d np; //Nullpunkt
            uint anz_np = 0;

            for(uint i=1; i<=tz.zeilenanzahl() ;i++)
            {
                QString klasse;
                if(dxfversion == dxf2000)
                {
                    klasse = tz.zeile(i+8);
                }else if(dxfversion == dxf2007)
                {
                    klasse = tz.zeile(i+6);
                }
                if(tz.zeile(i).contains("POINT") && klasse==dxf_klasse_wstnp)
                {
                    anz_np++;
                    if(dxfversion == dxf2000)
                    {
                        np.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                        np.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                    }else if(dxfversion == dxf2007)
                    {
                        np.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                        np.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                    }
                }
            }

            uint anz_importierter_geometrieen = 0;

            for(uint i=1; i<=tz.zeilenanzahl() ;i++)
            {
                if(tz.zeile(i).contains("LINE") && !tz.zeile(i).contains("POLY"))
                {
                    QString klasse;
                    if(dxfversion == dxf2000)
                    {
                        klasse = tz.zeile(i+8);
                    }else if(dxfversion == dxf2007)
                    {
                        klasse = tz.zeile(i+6);
                    }
                    if(dxf_klasse_geo_beachten != "ja")
                    {
                        klasse = dxf_klasse_geo;
                    }

                    if(klasse == dxf_klasse_geo && anz_np!=1)
                    {
                        strecke s;
                        punkt3d p;
                        if(dxfversion == dxf2000)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            p.set_z(0);
                            s.set_start(p);
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+22), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+24), 2));
                            s.set_ende(p);
                        }else if(dxfversion == dxf2007)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            p.set_z(0);
                            s.set_start(p);
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+20), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+22), 2));
                            s.set_ende(p);
                        }
                        s.set_farbe(FARBE_GRUEN);
                        getDialogData(s.get_text());
                        anz_importierter_geometrieen++;
                    }else if(klasse == dxf_klasse_geo)
                    {
                        strecke s;
                        punkt3d p;
                        if(dxfversion == dxf2000)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16),2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18),2).toDouble()-np.y());
                            p.set_z(0);
                            s.set_start(p);
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+22),2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+24),2).toDouble()-np.y());
                            s.set_ende(p);
                        }else if(dxfversion == dxf2007)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16),2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18),2).toDouble()-np.y());
                            p.set_z(0);
                            s.set_start(p);
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+20),2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+22),2).toDouble()-np.y());
                            s.set_ende(p);
                        }
                        s.set_farbe(FARBE_GRUEN);
                        getDialogData(s.get_text());
                        anz_importierter_geometrieen++;
                    }
                }else if(tz.zeile(i).contains("CIRCLE"))
                {
                    QString klasse;
                    if(dxfversion == dxf2000)
                    {
                        klasse = tz.zeile(i+8);
                    }else if(dxfversion == dxf2007)
                    {
                        klasse = tz.zeile(i+6);
                    }
                    if(dxf_klasse_geo_beachten != "ja")
                    {
                        klasse = dxf_klasse_geo;
                    }

                    if(klasse == dxf_klasse_geo && anz_np!=1)
                    {
                        kreis k;
                        punkt3d p;
                        if(dxfversion == dxf2000)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            p.set_z(0);
                            k.set_mittelpunkt(p);
                            k.set_radius(genauigkeit_reduzieren(tz.zeile(i+22), 2));
                        }else if(dxfversion == dxf2007)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            p.set_z(0);
                            k.set_mittelpunkt(p);
                            k.set_radius(genauigkeit_reduzieren(tz.zeile(i+20), 2));
                        }
                        k.set_farbe(FARBE_GRUEN);
                        getDialogData(k.get_text());
                        anz_importierter_geometrieen++;
                    }else if(klasse == dxf_klasse_geo)
                    {
                        kreis k;
                        punkt3d p;
                        if(dxfversion == dxf2000)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2).toDouble()-np.y());
                            p.set_z(0);
                            k.set_mittelpunkt(p);
                            k.set_radius(genauigkeit_reduzieren(tz.zeile(i+22), 2));
                        }else if(dxfversion == dxf2007)
                        {
                            p.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2).toDouble()-np.x());
                            p.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2).toDouble()-np.y());
                            p.set_z(0);
                            k.set_mittelpunkt(p);
                            k.set_radius(genauigkeit_reduzieren(tz.zeile(i+20), 2));
                        }
                        k.set_farbe(FARBE_GRUEN);
                        getDialogData(k.get_text());
                        anz_importierter_geometrieen++;
                    }
                }else if(tz.zeile(i).contains("ARC"))//Bogen
                {
                    QString klasse;
                    if(dxfversion == dxf2000)
                    {
                        klasse = tz.zeile(i+6);
                    }else if(dxfversion == dxf2007)
                    {
                        klasse = tz.zeile(i+6);
                    }
                    if(dxf_klasse_geo_beachten != "ja")
                    {
                        klasse = dxf_klasse_geo;
                    }

                    if(klasse == dxf_klasse_geo && anz_np!=1)
                    {
                        punkt2d mipu;
                        double rad;
                        double stawi;
                        double endwi;
                        double gesamtwinkel;
                        if(dxfversion == dxf2000)
                        {
                            mipu.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            mipu.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            rad = genauigkeit_reduzieren(tz.zeile(i+22), 2).toDouble();
                            stawi = genauigkeit_reduzieren(tz.zeile(i+26), 2).toDouble();
                            endwi = genauigkeit_reduzieren(tz.zeile(i+28), 2).toDouble();
                        }else if(dxfversion == dxf2007)
                        {
                            mipu.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2));
                            mipu.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2));
                            rad = genauigkeit_reduzieren(tz.zeile(i+20), 2).toDouble();
                            stawi = genauigkeit_reduzieren(tz.zeile(i+24), 2).toDouble();
                            endwi = genauigkeit_reduzieren(tz.zeile(i+26), 2).toDouble();
                        }
                        if(stawi < endwi)
                        {
                            gesamtwinkel = endwi - stawi;
                        }else
                        {
                            gesamtwinkel = 360-(stawi-endwi);
                        }
                        if(gesamtwinkel<180)
                        {
                            bogen b(mipu,rad,stawi,endwi);
                            b.set_farbe(FARBE_GRUEN);
                            getDialogData(b.get_text());
                            anz_importierter_geometrieen++;
                        }else
                        {
                            bogen b(mipu,rad,stawi,stawi+gesamtwinkel/2);
                            b.set_farbe(FARBE_GRUEN);
                            getDialogData(b.get_text());
                            anz_importierter_geometrieen++;
                            bogen b2(mipu,rad,stawi+gesamtwinkel/2,endwi);
                            b2.set_farbe(FARBE_GRUEN);
                            getDialogData(b2.get_text());
                            anz_importierter_geometrieen++;
                        }
                    }else if(klasse == dxf_klasse_geo)
                    {
                        punkt2d mipu;
                        double rad;
                        double stawi;
                        double endwi;
                        double gesamtwinkel;
                        if(dxfversion == dxf2000)
                        {
                            mipu.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2).toDouble()-np.x());
                            mipu.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2).toDouble()-np.y());
                            rad = genauigkeit_reduzieren(tz.zeile(i+22), 2).toDouble();
                            stawi = genauigkeit_reduzieren(tz.zeile(i+26), 2).toDouble();
                            endwi = genauigkeit_reduzieren(tz.zeile(i+28), 2).toDouble();
                        }else if(dxfversion == dxf2007)
                        {
                            mipu.set_x(genauigkeit_reduzieren(tz.zeile(i+16), 2).toDouble()-np.x());
                            mipu.set_y(genauigkeit_reduzieren(tz.zeile(i+18), 2).toDouble()-np.y());
                            rad = genauigkeit_reduzieren(tz.zeile(i+20), 2).toDouble();
                            stawi = genauigkeit_reduzieren(tz.zeile(i+24), 2).toDouble();
                            endwi = genauigkeit_reduzieren(tz.zeile(i+26), 2).toDouble();
                        }

                        if(stawi < endwi)
                        {
                            gesamtwinkel = endwi - stawi;
                        }else
                        {
                            gesamtwinkel = 360-(stawi-endwi);
                        }
                        if(gesamtwinkel<180)
                        {
                            bogen b(mipu,rad,stawi,endwi);
                            b.set_farbe(FARBE_GRUEN);
                            getDialogData(b.get_text());
                            anz_importierter_geometrieen++;
                        }else
                        {
                            bogen b(mipu,rad,stawi,stawi+gesamtwinkel/2);
                            b.set_farbe(FARBE_GRUEN);
                            getDialogData(b.get_text());
                            anz_importierter_geometrieen++;
                            bogen b2(mipu,rad,stawi+gesamtwinkel/2,endwi);
                            b2.set_farbe(FARBE_GRUEN);
                            getDialogData(b2.get_text());
                            anz_importierter_geometrieen++;
                        }

                    }
                }
            }

            if(anz_importierter_geometrieen == 0)
            {
                QString msg;
                msg = "Es wurden keine geeigneten Geometrieen in der Zeichnung gefunden.";
                msg += " ";
                msg += "Bitte ueberpruefen Sie den Inhalt der Zeichnung und die Programmeinstellungen.";

                QMessageBox mb;
                mb.setText(msg);
                mb.exec();
            }else
            {
                QString msg;
                msg = "Es wurden ";
                msg += int_to_qstring(anz_importierter_geometrieen);
                msg += " Geometrien importiert";

                QMessageBox mb;
                mb.setText(msg);
                mb.exec();
            }

            //QApplication::restoreOverrideCursor();
        }

    }
}

bool MainWindow::on_actionDateiSchliessen_triggered()
{
    //Sicherheitsabfrage:
    if(tt.get_prgtext()->get_hat_ungesicherte_inhalte() == true)
    {
        QFileInfo info;
        info = tt.get_prgname();
        QString dateiname = info.baseName();
        QString msg;

        if(dateiname == NICHT_DEFINIERT)
        {
            msg = "Soll die neue Datei vor dem Schliessen gespeichert werden?";
        }else
        {
            msg = "Soll die Datei \"";
            msg += dateiname;
            msg += "\" vor dem Schliessen gespeichert werden?";
        }
        QMessageBox mb;
        mb.setWindowTitle("Datei schliessen");
        mb.setText(msg);
        mb.setStandardButtons(QMessageBox::Yes);
        mb.addButton(QMessageBox::No);
        mb.addButton(QMessageBox::Abort);
        mb.setDefaultButton(QMessageBox::Abort);

        int mb_returnwert = mb.exec();
        if(mb_returnwert == QMessageBox::Yes)
        {
            if(on_actionDateiSpeichern_triggered() == false)//Speichern nicht erfolgreich abgeschlossen
            {
                return false;//Funktion nicht erfolgreich abgeschlossen
            }
        }else if(mb_returnwert == QMessageBox::No)
        {
            ;//nichts tun = nicht speichern
        }else if(mb_returnwert == QMessageBox::Abort)
        {
            return false;//Funktion nicht erfolgreich abgeschlossen
        }
    }
    //Datei schließen:
    tt.del();
    ui->listWidget_Programmliste->clear();
    aktualisiere_offene_dateien_menu();
    //GUI aktualisieren:
    update_gui();

    return true;//Funktion erfolgreich abgeschlossen
}

bool MainWindow::on_actionDateiSpeichern_triggered()
{
    if(tt.dateien_sind_offen() == false)
    {
        return true;//Funktion erfolgreich beendet
    }
    QString fileName;
    if((tt.get_prgname().contains("Unbekannt ") && tt.get_prgname().length() <= 13)  ||  speichern_unter_flag == true)
    {
        //Dialog öffnen zum Wählen des Speicherortes und des Namens:
        fileName = QFileDialog::getSaveFileName(this, tr("Datei Speichern"), \
                                                pfad_oefne_ggf, tr("ggf Dateien (*.ggf)"));
        if(!fileName.isEmpty())
        {
            QFileInfo info = fileName;
            pfad_oefne_ggf = info.path();
            if(!fileName.contains(DATEIENDUNG_EIGENE))
            {
                fileName += DATEIENDUNG_EIGENE;
            }
            if(fileName == DATEIENDUNG_EIGENE)//Wenn der Speichen-Dialog abgebrochen wurde
            {
                return false;//Funktion nicht erfolgreich beendet
            }else
            {
                tt.set_prgname(fileName);
            }
        }else //Speichen-Dialog wurde abgebrochen
        {
            return false;//Funktion nicht erfolgreich beendet
        }
    }else
    {
        //Namen der offenen Datei verwenden:

        fileName = tt.get_prgname();
        if(!fileName.contains(DATEIENDUNG_EIGENE))
        {
            fileName += DATEIENDUNG_EIGENE;
        }
    }

    //Programmliste in String schreiben
    QString dateiInhalt = dateitext_ggf();

    //Datei füllen und speichern
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
        {
            QMessageBox mb;
            mb.setText("Fehler beim Dateizugriff");
            mb.exec();
            return false;//Funktion nicht erfolgreich beendet
        } else
        {
            file.remove(); //lösche alte Datei wenn vorhanden
            file.close(); //beende Zugriff
            file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
            file.write(dateiInhalt.toUtf8()); //fülle Datei mit Inhalt
            file.close(); //beende Zugriff
            QFileInfo info = tt.get_prgname();
            QString tmp = PROGRAMMNAME;
            tmp += " ( " + info.baseName() + " )";
            this->setWindowTitle(tmp);
            tt.get_prgtext()->wurde_gespeichert();
            aktuelisiere_letzte_dateien_inifile();
            aktualisiere_letzte_dateien_menu();
        }
    }
    return true;//Funktion erfolgreich beendet
}

void MainWindow::on_actionDateiSpeichern_unter_triggered()
{
    speichern_unter_flag = true;
    on_actionDateiSpeichern_triggered();
    speichern_unter_flag = false;
    QFileInfo info = tt.get_prgname();
    QString tmp = PROGRAMMNAME;
    tmp += " ( " + info.baseName() + " )";
    this->setWindowTitle(tmp);
}

void MainWindow::on_actionMaschine_speichern_triggered()
{
    if(tt.dateien_sind_offen() == false)
    {
        return;
    }
    bool nur_cad = true;
    //for(uint i=1; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ;i++) //letzte ist "..." desshalb i< und nicht i<=
    for(uint i=1; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ;i++) //letzte ist "..." desshalb i< und nicht i<=
    {
        QString zeile = tt.get_prgtext()->get_text_zeilenweise().zeile(i);
        if(zeile.contains(BOGEN)     || \
           zeile.contains(STRECKE)   || \
           zeile.contains(KREIS)        )
        {
            nur_cad = true;
        }else
        {
            nur_cad = false;
            break;
        }
    }
    if(nur_cad == false)
    {
        QMessageBox mb;
        mb.setText("Das offene Dokument darf nur CAD enthalten!");
        mb.exec();
    }
    QString fileName = QDir::homePath() + QDir::separator() + CAD_Maschine;
    //Programmliste in String schreiben
    QString dateiInhalt = dateitext_ggf();
    //Datei füllen und speichern
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
        {
            QMessageBox mb;
            mb.setText("Fehler beim Dateizugriff");
            mb.exec();
        } else
        {
            file.remove(); //lösche alte Datei wenn vorhanden
            file.close(); //beende Zugriff
            file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
            file.write(dateiInhalt.toUtf8()); //fülle Datei mit Inhalt
            file.close(); //beende Zugriff

            QMessageBox mb;
            mb.setText("Speichern erfolgreich.");
            mb.exec();

            on_actionDateiSchliessen_triggered();
        }
    }

}

QString MainWindow::dateitext_ggf()
{
    QString dateiInhalt;
    dateiInhalt  = PROGRAMMNAME;
    dateiInhalt += " Version 2\n";
    dateiInhalt += tt.get_prgtext()->get_text();

    return dateiInhalt;
}

void MainWindow::on_actionMaschinengeometrie_bearbeiten_triggered()
{
    QFile file(QDir::homePath() + QDir::separator() + CAD_Maschine);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        text_zeilenweise tz;

        while(!file.atEnd())
        {
            QString line = file.readLine();
            if(line.right(1) == "\n")
            {
                line = line.left(line.length()-1);
            }
            if(tz.zeilenanzahl() == 0)
            {
                tz.set_text(line);
            }else
            {
                tz.zeilen_anhaengen(line);
            }
        }
        tt.get_prgtext()->set_text(tz.get_text());
        file.close();
        aktualisiere_anzeigetext();
        showElements_aFileIsOpen();
        vorschauAktualisieren();
        //tt.get_prgtext()->wurde_gespeichert();
        QApplication::restoreOverrideCursor();
    }else
    {
        QMessageBox mb;
        mb.setText("Maschinen-CAD-Datei wurde nicht gefunden!");
        mb.exec();
    }
}

void MainWindow::on_actionNaechste_offen_Datei_triggered()
{
    tt.set_index_nach();
    update_gui();
}

void MainWindow::on_actionLetzte_offene_Datei_triggered()
{
    tt.set_index_vor();
    update_gui();
}

//---------------------------------------------------Sichtbarkeiten
void MainWindow::hideElemets_noFileIsOpen()
{
    ui->listWidget_Programmliste->hide();
    ui->pushButton_Aktualisieren_GCode->hide();
    ui->pushButton_Exportieren_GCODE->hide();
    ui->plainTextEdit_GCode->hide();
    //Menü Datei:
    ui->actionDateiSpeichern->setDisabled(true);
    ui->actionDateiSpeichern_unter->setDisabled(true);
    ui->actionDateiSchliessen->setDisabled(true);
    ui->actionGCode_berechnen->setDisabled(true);
    ui->actionGCode_exportieren->setDisabled(true);
    ui->menuImport->setDisabled(true);
    ui->import_GGF->setDisabled(true);
    ui->import_DXF->setDisabled(true);
    ui->actionMaschine_speichern->setDisabled(true);
    ui->actionMaschinengeometrie_bearbeiten->setEnabled(true);
    //Menü Bearbeiten:
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        ui->actionAendern->setDisabled(true);
        ui->actionEinfuegen->setDisabled(true);
        ui->actionKopieren->setDisabled(true);
        ui->actionAusschneiden->setDisabled(true);
        ui->actionEntfernen->setDisabled(true);
    }
    ui->actionEin_Ausblenden->setDisabled(true);
    ui->actionAuswahl_Einblenden->setDisabled(true);
    ui->actionAuswahl_Ausblenden->setDisabled(true);
    //Menü CAM:
    ui->actionMakeProgrammkopf->setDisabled(true);
    ui->actionMakeProgrammende->setDisabled(true);
    ui->actionMakeKommentar->setDisabled(true);
    ui->actionMakeVariable->setDisabled(true);
    ui->actionMakeKreistasche->setDisabled(true);
    ui->actionMakeRechtecktasche->setDisabled(true);
    ui->actionMakeFraeser_Aufruf->setDisabled(true);
    ui->actionMakeGerade_Fraesbahn->setDisabled(true);
    ui->actionMakeGebogene_Fraesbahn->setDisabled(true);
    ui->actionMakeAbfahren->setDisabled(true);
    ui->actionMakeBohren->setDisabled(true);
    //Menü CAD:
    ui->actionMakeKreis->setDisabled(true);
    ui->actionMakeStrecke->setDisabled(true);
    ui->actionMakeBogen->setDisabled(true);
    //Menü Umwandeln:
    ui->actionKreistasche_in_Kreis_umwandeln->setDisabled(true);
    ui->actionKreis_in_Kreistasche_umwandeln->setDisabled(true);
    ui->actionLinien_in_Fraeskonturen_umwandeln->setDisabled(true);
    ui->actionFraeskonturen_in_Linien_umwandeln->setDisabled(true);
    ui->action4_Eck_in_Rechtecktasche_umwandeln->setDisabled(true);
    ui->actionRechtecktasche_in_4_Eck_umwandeln->setDisabled(true);
    ui->actionKreis_in_Bohrung_umwandeln->setDisabled(true);
    ui->actionBohrung_in_Kreis_umwandeln->setDisabled(true);
    ui->actionKreistasche_in_Bohrung_umwandeln->setDisabled(true);
    ui->actionBohrung_in_Kreistasche_umwandeln->setDisabled(true);
    //Menü Manipulation:
    ui->actionCAD_sortieren->setDisabled(true);
    ui->actionFraesrichtung_umkehren->setDisabled(true);
    ui->actionFraesStartpunkt_vor->setDisabled(true);
    ui->actionFraesStartpunkt_nach->setDisabled(true);
    ui->actionVerastzvariablen->setDisabled(true);
    ui->actionSpiegeln_horizontal->setDisabled(true);
    ui->actionSpiegeln_vertikel->setDisabled(true);
    //Menü Diverses:
    ui->actionVorschaufenster_anzeigen->setDisabled(true);
    ui->actionProgrammliste_anzeigen->setDisabled(true);
    ui->actionVariablenwert_anzeigen->setDisabled(true);
    //anderes:
    vorschaufenster.hide();
}

void MainWindow::showElements_aFileIsOpen()
{
    ui->listWidget_Programmliste->show();
    ui->pushButton_Aktualisieren_GCode->show();
    ui->pushButton_Exportieren_GCODE->show();
    ui->plainTextEdit_GCode->show();
    //Menü Datei:
    ui->actionDateiSpeichern->setEnabled(true);
    ui->actionDateiSpeichern_unter->setEnabled(true);
    ui->actionDateiSchliessen->setEnabled(true);
    ui->actionGCode_berechnen->setEnabled(true);
    ui->actionGCode_exportieren->setEnabled(true);
    ui->menuImport->setEnabled(true);
    ui->import_GGF->setEnabled(true);
    ui->import_DXF->setEnabled(true);
    ui->actionMaschine_speichern->setEnabled(true);
    ui->actionMaschinengeometrie_bearbeiten->setDisabled(true);
    //Menü Bearbeiten:
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        ui->actionAendern->setEnabled(true);
        ui->actionEinfuegen->setEnabled(true);
        ui->actionKopieren->setEnabled(true);
        ui->actionAusschneiden->setEnabled(true);
        ui->actionEntfernen->setEnabled(true);
    }
    ui->actionEin_Ausblenden->setEnabled(true);
    ui->actionAuswahl_Einblenden->setEnabled(true);
    ui->actionAuswahl_Ausblenden->setEnabled(true);
    //Menü CAM:
    ui->actionMakeProgrammkopf->setEnabled(true);
    ui->actionMakeProgrammende->setEnabled(true);
    ui->actionMakeKommentar->setEnabled(true);
    ui->actionMakeVariable->setEnabled(true);
    ui->actionMakeKreistasche->setEnabled(true);
    ui->actionMakeRechtecktasche->setEnabled(true);
    ui->actionMakeFraeser_Aufruf->setEnabled(true);
    ui->actionMakeGerade_Fraesbahn->setEnabled(true);
    ui->actionMakeGebogene_Fraesbahn->setEnabled(true);
    ui->actionMakeAbfahren->setEnabled(true);
    ui->actionMakeBohren->setEnabled(true);
    //Menü CAD:
    ui->actionMakeKreis->setEnabled(true);
    ui->actionMakeStrecke->setEnabled(true);
    ui->actionMakeBogen->setEnabled(true);
    //Menü Umwandeln:
    ui->actionKreistasche_in_Kreis_umwandeln->setEnabled(true);
    ui->actionKreis_in_Kreistasche_umwandeln->setEnabled(true);
    ui->actionLinien_in_Fraeskonturen_umwandeln->setEnabled(true);
    ui->actionFraeskonturen_in_Linien_umwandeln->setEnabled(true);
    ui->action4_Eck_in_Rechtecktasche_umwandeln->setEnabled(true);
    ui->actionRechtecktasche_in_4_Eck_umwandeln->setEnabled(true);
    ui->actionKreis_in_Bohrung_umwandeln->setEnabled(true);
    ui->actionBohrung_in_Kreis_umwandeln->setEnabled(true);
    ui->actionKreistasche_in_Bohrung_umwandeln->setEnabled(true);
    ui->actionBohrung_in_Kreistasche_umwandeln->setEnabled(true);
    //Menü Manipulation:
    ui->actionCAD_sortieren->setEnabled(true);
    ui->actionFraesrichtung_umkehren->setEnabled(true);
    ui->actionFraesStartpunkt_vor->setEnabled(true);
    ui->actionFraesStartpunkt_nach->setEnabled(true);
    ui->actionVerastzvariablen->setEnabled(true);
    ui->actionSpiegeln_horizontal->setEnabled(true);
    ui->actionSpiegeln_vertikel->setEnabled(true);
    //Menü Diverses:
    ui->actionVorschaufenster_anzeigen->setEnabled(true);
    ui->actionProgrammliste_anzeigen->setEnabled(true);
    ui->actionVariablenwert_anzeigen->setEnabled(true);
    //anderes:
    vorschaufenster.show();
}

bool MainWindow::elementIstEingeblendet()
{
    QString tmp = tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
    if(tmp.left(2) == "//")
    {
        return false;
    }else
    {
        return true;
    }
}

bool MainWindow::elementIstEingeblendet(QString zeilentext)
{
    if(zeilentext.left(2) == "//")
    {
        return false;
    }else
    {
        return true;
    }
}

bool MainWindow::elementIstEingeblendet(QListWidgetItem *item)
{
    QString tmp = item->text();
    if(tmp.left(2) == "//")
    {
        return false;
    }else
    {
        return true;
    }
}

void MainWindow::elementEinblenden()
{
    uint i = ui->listWidget_Programmliste->currentRow()+1;
    QString tmp_t = tt.get_prgtext()->zeile(i);
    int length_t = tmp_t.length();
    tmp_t = tmp_t.right(length_t-2);
    tt.get_prgtext()->zeile_ersaetzen(i, tmp_t);

    QString tmp = ui->listWidget_Programmliste->currentItem()->text();
    int length = tmp.length();
    tmp = tmp.right(length-2);
    ui->listWidget_Programmliste->currentItem()->setText(tmp);

    vorschauAktualisieren();
}

void MainWindow::elementAusblenden()
{
    uint i = ui->listWidget_Programmliste->currentRow()+1;
    QString tmp_t = tt.get_prgtext()->zeile(i);
    tmp_t = "//" + tmp_t;
    tt.get_prgtext()->zeile_ersaetzen(i, tmp_t);

    QString tmp = ui->listWidget_Programmliste->currentItem()->text();
    QString newText = "//";
    newText += tmp;
    ui->listWidget_Programmliste->currentItem()->setText(newText);

    vorschauAktualisieren();
}

void MainWindow::elementEinblendenSichtbarMachen()
{
    QColor farbe(0,0,0);//schwarz
    ui->listWidget_Programmliste->currentItem()->setForeground(QBrush(farbe));
}

void MainWindow::elementEinblendenSichtbarMachen(QListWidgetItem *item)
{
    QColor farbe(0,0,0);//schwarz
    item->setForeground(QBrush(farbe));
}

void MainWindow::elementAusblendenSichtbarMachen()
{
    QColor farbe(180,205,205);//grau
    ui->listWidget_Programmliste->currentItem()->setForeground(QBrush(farbe));
}

void MainWindow::elementAusblendenSichtbarMachen(QListWidgetItem *item)
{
    QColor farbe(180,205,205);//grau
    item->setForeground(QBrush(farbe));
}

void MainWindow::on_actionEin_Ausblenden_triggered()
{
    tt.get_prgtext()->warnungen_einschalten(false);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            int row_letztes = row_erstes + items_menge-1;

            int menge_ausgeblendet = 0;
            int menge_eingeblendet = 0;
            for(int i=row_erstes ; i<=row_letztes ; i++)
            {
                QString zeilentext = tt.get_prgtext()->zeile(i+1);
                if(elementIstEingeblendet(zeilentext))
                {
                    menge_eingeblendet++;
                }else
                {
                    menge_ausgeblendet++;
                }
            }
            if(menge_eingeblendet == items_menge)
            {
                on_actionAuswahl_Ausblenden_triggered();
            }else if(menge_ausgeblendet == items_menge)
            {
                on_actionAuswahl_Einblenden_triggered();
            }
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was ausgeblendet werden kann!");
            mb.exec();
        }
    }else
    {
        QMessageBox mb;
        mb.setText("Dieser Befehl kann nur im TAB Programmliste verwendet werden!");
        mb.exec();
    }
    tt.get_prgtext()->warnungen_einschalten(true);
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionAuswahl_Ausblenden_triggered()
{
    tt.get_prgtext()->warnungen_einschalten(false);
    QApplication::setOverrideCursor(Qt::WaitCursor); 
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            int row_letztes = row_erstes + items_menge-1;

            tt.get_prgtext()->aktualisieren_ein_aus(false);
            for(int i=row_erstes ; i<=row_letztes ; i++)
            {
                QString zeilentext =tt.get_prgtext()->zeile(i+1);
                if(elementIstEingeblendet(zeilentext))
                {
                   tt.get_prgtext()->zeile_ersaetzen(i+1,"//"+zeilentext);
                    QColor farbe(180,205,205);//grau
                    ui->listWidget_Programmliste->item(i)->setForeground(QBrush(farbe));
                }                
            }
            tt.get_prgtext()->aktualisieren_ein_aus(true);
            aktualisiere_anzeigetext();
            vorschauAktualisieren();
            for(int i=row_erstes ; i<=row_letztes ; i++)
            {
                ui->listWidget_Programmliste->item(i)->setSelected(true);
            }           
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was ausgeblendet werden kann!");
            mb.exec();
        }
    }else
    {
        QMessageBox mb;
        mb.setText("Dieser Befehl kann nur im TAB Programmliste verwendet werden!");
        mb.exec();
    }
    tt.get_prgtext()->warnungen_einschalten(true);
    QApplication::restoreOverrideCursor();

}

void MainWindow::on_actionAuswahl_Einblenden_triggered()
{
   tt.get_prgtext()->warnungen_einschalten(false);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            int row_letztes = row_erstes + items_menge-1;

           tt.get_prgtext()->aktualisieren_ein_aus(false);
            for(int i=row_erstes ; i<=row_letztes ; i++)
            {
                QString zeilentext =tt.get_prgtext()->zeile(i+1);
                if(!elementIstEingeblendet(zeilentext))
                {
                    int laenge = zeilentext.length();
                    zeilentext = zeilentext.right(laenge-2);
                   tt.get_prgtext()->zeile_ersaetzen(i+1, zeilentext);
                    QColor farbe(180,205,205);//grau
                    ui->listWidget_Programmliste->item(i)->setForeground(QBrush(farbe));
                }
            }
           tt.get_prgtext()->aktualisieren_ein_aus(true);
            aktualisiere_anzeigetext();
            vorschauAktualisieren();
            for(int i=row_erstes ; i<=row_letztes ; i++)
            {
                ui->listWidget_Programmliste->item(i)->setSelected(true);
            }        
        } else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was ausgeblendet werden kann!");
            mb.exec();
        }
    }else
    {
        QMessageBox mb;
        mb.setText("Dieser Befehl kann nur im TAB Programmliste verwendet werden!");
        mb.exec();
    }
   tt.get_prgtext()->warnungen_einschalten(true);
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == INDEX_PROGRAMMLISTE)
    {
        if(tt.dateien_sind_offen() == false)
        {
            //Menü Bearbeiten:
            ui->actionAendern->setDisabled(true);
            ui->actionEinfuegen->setDisabled(true);
            ui->actionKopieren->setDisabled(true);
            ui->actionAusschneiden->setDisabled(true);
            ui->actionEntfernen->setDisabled(true);
            //ui->actionEin_Ausblenden->setDisabled(true);
        }
    }else if(index == INDEX_WERKZEUGLISTE)
    {
        //Menü Bearbeiten:
        ui->actionAendern->setEnabled(true);
        ui->actionEinfuegen->setEnabled(true);
        ui->actionKopieren->setEnabled(true);
        ui->actionAusschneiden->setEnabled(true);
        ui->actionEntfernen->setEnabled(true);
        //ui->actionEin_Ausblenden->setEnabled(true);
    }
}

//---------------------------------------------------generell MainWindow
void MainWindow::closeEvent(QCloseEvent *ce)
{
    while(tt.dateien_sind_offen() == true)
    {
        if(on_actionDateiSchliessen_triggered() == false)
        {
            break;
        }
    }
    if(tt.dateien_sind_offen() == true)
    {
        ce->ignore();
    }else
    {
        ce->accept();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QRect rect_main =  this->geometry();
    int hoehe = rect_main.height();
    int breite = rect_main.width();
    ui->tabWidget->setFixedSize(breite-20, hoehe-80);
    QRect rect_tabWidget =  ui->tabWidget->geometry();
    hoehe = rect_tabWidget.height();
    breite = rect_tabWidget.width();
    ui->plainTextEdit_GCode->setFixedSize(breite-20, hoehe-85);
    ui->listWidget_Werkzeug->setFixedSize(breite-20, hoehe-85);

    vorschaufenster.move(ui->tab_Programmliste->width()/3,10);
    vorschaufenster.setFixedWidth(ui->tab_Programmliste->width()-ui->tab_Programmliste->width()/3-13);
    vorschaufenster.setFixedHeight(ui->tab_Programmliste->height()-30);
    ui->listWidget_Programmliste->setFixedWidth(ui->tab_Programmliste->width()/3-10);
    ui->listWidget_Programmliste->setFixedHeight(ui->tab_Programmliste->height()-30);

    QMainWindow::resizeEvent(event);
}

//---------------------------------------------------G-Code

void MainWindow::on_actionGCode_berechnen_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    gcode gc(*tt.get_prgtext());
    gc.set_wkz(w);


    bool tmp_fkon_ein =tt.get_prgtext()->ist_aktualisieren_fkon_ein();
    if(tmp_fkon_ein == false)
    {
       tt.aktualisieren_fkon_ein_aus(true);
    }

    ui->plainTextEdit_GCode->clear();
    ui->tabWidget->setCurrentWidget(ui->tab_GCode);//Tab G-Code aktivieren
    aktives_wkz = NICHT_DEFINIERT;
    double eintauchvorschub = 0;
    double vorschub = 0;
    double drehzahl = 0;
    double zustellmass = 0;

    text_zeilenweise klartext =tt.get_prgtext()->get_klartext_zeilenweise();
    QString gcode;
    QString abfahrtyp;

    for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
    {
        gcode += "(";
        QString zeile = klartext.zeile(i);
        gcode += klammern_wecklassen(zeile);
        gcode += ")";
        gcode += "\n";

        if(zeile.contains(PROGRAMMKOPF_DIALOG))
        {
            gcode += "(";
            gcode += klammern_wecklassen(text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG));
            gcode += ")";
            gcode += "\n";
        }else if(zeile.contains(PROGRAMMENDE_DIALOG))
        {
            gcode += "G00";
            gcode += " X";
            gcode += text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            gcode += " Y";
            gcode += text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            gcode += " Z";
            gcode += text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
            gcode += "\n";
            gcode += "M30";
            break; //Ende der Ausgabe = Ende der For-Schleife
        }else if(zeile.contains(KOMMENTAR_DIALOG))
        {
            gcode += "(";
            gcode += klammern_wecklassen(text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG));
            gcode += ")";
            gcode += "\n";
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            QString werkzeugname = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            if(aktives_wkz == NICHT_DEFINIERT)
            {
                aktives_wkz = werkzeugname;
            }else if(aktives_wkz != werkzeugname)
            {
                QString tmp = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
                ui->plainTextEdit_GCode->clear();
                ui->plainTextEdit_GCode->insertPlainText(tmp);
                QApplication::restoreOverrideCursor();
                return;
            }
            rechtecktasche tasche_tmp;
            QString tmp;
            tmp = text_mitte(zeile, BEZUGSPUNKT, ENDE_EINTRAG);
            tasche_tmp.set_bezugspunkt_nummer(tmp.toInt());

            punkt p;
            tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            p.x = tmp.toFloat();
            tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            p.y = tmp.toFloat();
            tasche_tmp.set_einfuegepunkt(p);

            tmp = text_mitte(zeile, TASCHENLAENGE, ENDE_EINTRAG);
            tasche_tmp.set_laenge(tmp.toFloat());
            tmp = text_mitte(zeile, TASCHENBREITE, ENDE_EINTRAG);
            tasche_tmp.set_breite(tmp.toFloat());

            tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
            tasche_tmp.set_tiefe(tmp.toFloat());

            tasche_tmp.set_sicherheitsabstand(tt.get_prgtext()->get_sicherheitsabstand());


            //Fräserdurchmesser:
            //tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            tmp = werkzeugname;
            QString werkzeug;
            werkzeug = werkzeugdaten(tmp);
            tmp = text_mitte(werkzeug, WKZ_DURCHMESSER, ENDE_EINTRAG);
            tasche_tmp.set_durchmesser_fraeser(tmp.toFloat());

            tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
            tasche_tmp.set_radius_taschenecken(tmp.toFloat());

            tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
            }
            tasche_tmp.set_zustellmass(tmp.toFloat());

            tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
            tasche_tmp.set_ausraeumen(tmp.toInt());

            tmp = text_mitte(zeile, BEZUGSHOEHE, ENDE_EINTRAG);
            tasche_tmp.set_bezugshoehe(tmp.toFloat());

            tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
            }
            tasche_tmp.set_vorschubgeschwindigkeit(tmp.toInt());

            tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
            }
            tasche_tmp.set_anfahrvorschub(tmp.toInt());

            tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
            tasche_tmp.set_drehwinkel(tmp.toFloat());

            QString drehrichtung_fraeser;
            drehrichtung_fraeser = text_mitte(werkzeug, WKZ_DREHRICHTUNG, ENDE_EINTRAG);
            QString im_gegenlauf;
            im_gegenlauf = text_mitte(zeile, GEGENLAUF, ENDE_EINTRAG);
            if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_RECHTS)
            {
                if(im_gegenlauf.toInt()  == true)
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
                }else
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
                }
            }else if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_LINKS)
            {
                if(im_gegenlauf.toInt()  == false)
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
                }else
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
                }
            }else
            {
                //G-Code ausgabe abbreche mit Fehlermeldung
                //"(Ausgabe nicht moeglich weil Drehrichtung Fraeser unbekannt)"
                ui->plainTextEdit_GCode->insertPlainText("(Ausgabe nicht moeglich weil Drehrichtung Fraeser unbekannt)");
                QApplication::restoreOverrideCursor();
                return ;
            }

            if(text_mitte(werkzeug, WKZ_KANN_BOHREN, ENDE_EINTRAG) == "1")
            {
                tasche_tmp.set_fraeser_kabo(true);
            }else
            {
                tasche_tmp.set_fraeser_kabo(false);
            }

            std::string tasche = tasche_tmp.get_gcode();
            tmp = QString::fromStdString(tasche);
            gcode += tmp;
            gcode += "\n";
        }else if(zeile.contains(KREISTASCHE_DIALOG))
        {
            QString werkzeugname = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            if(aktives_wkz == NICHT_DEFINIERT)
            {
                aktives_wkz = werkzeugname;
            }else if(aktives_wkz != werkzeugname)
            {
                QString tmp = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
                ui->plainTextEdit_GCode->clear();
                ui->plainTextEdit_GCode->insertPlainText(tmp);
                QApplication::restoreOverrideCursor();
                return;
            }
            rechtecktasche tasche_tmp;
            QString tmp;
            tasche_tmp.set_bezugspunkt_nummer(MITTE);

            punkt p;
            tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            p.x = tmp.toFloat();
            tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            p.y = tmp.toFloat();
            tasche_tmp.set_einfuegepunkt(p);

            tmp = text_mitte(zeile, DURCHMESSER, ENDE_EINTRAG);
            tasche_tmp.set_laenge(tmp.toFloat());
            tasche_tmp.set_breite(tmp.toFloat());

            tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
            tasche_tmp.set_tiefe(tmp.toFloat());

            tasche_tmp.set_sicherheitsabstand(tt.get_prgtext()->get_sicherheitsabstand());


            //Fräserdurchmesser:
            tmp = werkzeugname;
            QString werkzeug;
            werkzeug = werkzeugdaten(tmp);
            tmp = text_mitte(werkzeug, WKZ_DURCHMESSER, ENDE_EINTRAG);
            tasche_tmp.set_durchmesser_fraeser(tmp.toFloat());

            tmp = text_mitte(zeile, DURCHMESSER, ENDE_EINTRAG);
            tasche_tmp.set_radius_taschenecken(tmp.toFloat()/2);

            tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
            }
            tasche_tmp.set_zustellmass(tmp.toFloat());

            tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
            tasche_tmp.set_ausraeumen(tmp.toInt());

            tmp = text_mitte(zeile, BEZUGSHOEHE, ENDE_EINTRAG);
            tasche_tmp.set_bezugshoehe(tmp.toFloat());

            tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
            }
            tasche_tmp.set_vorschubgeschwindigkeit(tmp.toInt());

            tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
            }
            tasche_tmp.set_anfahrvorschub(tmp.toInt());

            tasche_tmp.set_drehwinkel(0);

            QString drehrichtung_fraeser;
            drehrichtung_fraeser = text_mitte(werkzeug, WKZ_DREHRICHTUNG, ENDE_EINTRAG);
            QString im_gegenlauf;
            im_gegenlauf = text_mitte(zeile, GEGENLAUF, ENDE_EINTRAG);
            if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_RECHTS)
            {
                if(im_gegenlauf.toInt()  == true)
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
                }else
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
                }
            }else if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_LINKS)
            {
                if(im_gegenlauf.toInt()  == false)
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
                }else
                {
                    tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
                }
            }else
            {
                //G-Code ausgabe abbreche mit Fehlermeldung
                //"(Ausgabe nicht moeglich weil Drehrichtung Fraeser unbekannt)"
                ui->plainTextEdit_GCode->insertPlainText("(Ausgabe nicht moeglich weil Drehrichtung Fraeser unbekannt)");
                QApplication::restoreOverrideCursor();
                return ;
            }

            if(text_mitte(werkzeug, WKZ_KANN_BOHREN, ENDE_EINTRAG) == "1")
            {
                tasche_tmp.set_fraeser_kabo(true);
            }else
            {
                tasche_tmp.set_fraeser_kabo(false);
            }

            std::string tasche = tasche_tmp.get_gcode();
            tmp = QString::fromStdString(tasche);
            gcode += tmp;
            gcode += "\n";
        }else if(zeile.contains(BOHREN_DIALOG))
        {
            QString werkzeugname = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            if(aktives_wkz == NICHT_DEFINIERT)
            {
                aktives_wkz = werkzeugname;
            }else if(aktives_wkz != werkzeugname)
            {
                QString tmp = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
                ui->plainTextEdit_GCode->clear();
                ui->plainTextEdit_GCode->insertPlainText(tmp);
                QApplication::restoreOverrideCursor();
                return;
            }
            //Vorschübe setzen etc.:
            QString tmp;
            QString werkzeug = werkzeugdaten(werkzeugname);
            tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_ANBOHRVORSCHUB, ENDE_EINTRAG);
            }
            eintauchvorschub = tmp.toDouble();
            tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_BOHRVORSCHUB, ENDE_EINTRAG);
            }
            vorschub = tmp.toDouble();
            tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_DREHZAHL, ENDE_EINTRAG);
            }
            drehzahl = tmp.toDouble();
            tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_BOZUTI, ENDE_EINTRAG);
            }
            zustellmass = tmp.toDouble();

            tmp = text_mitte(zeile, ANBOHRTI, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_BOANBOTI, ENDE_EINTRAG);
            }
            double anboti = tmp.toDouble();

            tmp = text_mitte(zeile, RESTBOHRTI, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_BOREBOTI, ENDE_EINTRAG);
            }
            double reboti = tmp.toDouble();

            double boti = text_mitte(zeile, BOHRTIEFE, ENDE_EINTRAG).toDouble();

            if(boti != 0)
            {
                //Anfahrpunkt:
                punkt3d startpunkt;
                startpunkt.set_x(text_mitte(zeile, POSITION_X, ENDE_EINTRAG));
                startpunkt.set_y(text_mitte(zeile, POSITION_Y, ENDE_EINTRAG));
                startpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());
                gcode += "G0 X";
                gcode += double_to_qstring(runden(startpunkt.x(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(startpunkt.y(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(startpunkt.z(),2));
                gcode += " (Beginn der Bohrung)";
                gcode += "\n";

                if(boti < 0)
                {
                    boti =tt.get_prgtext()->get_werkstueckdicke() - boti; //z.B. boti == -2 --> 19 - -2 == 19+2 == 21
                }
                if(zustellmass <= 0)
                {
                    zustellmass = boti;
                }
                if(anboti <= 0)
                {
                    anboti = zustellmass;
                }
                if(anboti > boti)
                {
                    anboti = zustellmass;
                }
                if(reboti <= 0)
                {
                    reboti = 0;
                }
                if(reboti > boti)
                {
                    reboti = 0;
                }
                double z;
                QString ausfahren;
                ausfahren += "G1 Z";
                ausfahren += double_to_qstring(runden(tt.get_prgtext()->get_werkstueckdicke()+2,2));
                ausfahren += " F";
                ausfahren += double_to_qstring(eintauchvorschub);
                ausfahren += "\n";

                if(boti > anboti + reboti)
                {
                    //Anbohren:
                    z =tt.get_prgtext()->get_werkstueckdicke() - anboti;
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(z,2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += " (Anbohren)";
                    gcode += "\n";
                    gcode += ausfahren;

                    if(reboti > 0)
                    {
                        double restmass;
                        restmass = boti - anboti - reboti;
                        restmass = restmass - zustellmass;

                        while(restmass > 0)
                        {
                            //Zustellen:
                            z =tt.get_prgtext()->get_werkstueckdicke() - boti + reboti + restmass;
                            gcode += "G1 Z";
                            gcode += double_to_qstring(runden(z,2));
                            gcode += " F";
                            gcode += double_to_qstring(vorschub);
                            gcode += " (Zustellen)";
                            gcode += "\n";
                            gcode += ausfahren;
                            restmass = restmass - zustellmass;
                        }
                        //letzte Zustellung:
                        z =tt.get_prgtext()->get_werkstueckdicke() - boti + reboti;
                        gcode += "G1 Z";
                        gcode += double_to_qstring(runden(z,2));
                        gcode += " F";
                        gcode += double_to_qstring(vorschub);
                        gcode += " (letzte Zustellung)";
                        gcode += "\n";
                        gcode += ausfahren;

                        //Restborung:
                        z =tt.get_prgtext()->get_werkstueckdicke() - boti;
                        gcode += "G1 Z";
                        gcode += double_to_qstring(runden(z,2));
                        gcode += " F";
                        gcode += double_to_qstring(vorschub);
                        gcode += " (Restbohrmass)";
                        gcode += "\n";
                        gcode += ausfahren;
                    }else
                    {
                        double restmass;
                        restmass = boti - anboti;
                        restmass = restmass - zustellmass;

                        while(restmass > 0)
                        {
                            //Zustellen:
                            z =tt.get_prgtext()->get_werkstueckdicke() - boti + reboti + restmass;
                            gcode += "G1 Z";
                            gcode += double_to_qstring(runden(z,2));
                            gcode += " F";
                            gcode += double_to_qstring(vorschub);
                            gcode += " (Zustellen)";
                            gcode += "\n";
                            gcode += ausfahren;
                            restmass = restmass - zustellmass;
                        }
                        //Restborung:
                        z =tt.get_prgtext()->get_werkstueckdicke() - boti;
                        gcode += "G1 Z";
                        gcode += double_to_qstring(runden(z,2));
                        gcode += " F";
                        gcode += double_to_qstring(vorschub);
                        gcode += " (Restbohrtiefe)";
                        gcode += "\n";
                        gcode += ausfahren;
                    }
                }else if(boti == anboti + reboti)
                {
                    //heißt keine Zustellungen:
                    //Anbohren:
                    z =tt.get_prgtext()->get_werkstueckdicke() - anboti;
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(z,2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += " (Anbohren)";
                    gcode += "\n";
                    gcode += ausfahren;
                    if(reboti > 0)
                    {
                        //Restborung:
                        z =tt.get_prgtext()->get_werkstueckdicke() - boti;
                        gcode += "G1 Z";
                        gcode += double_to_qstring(runden(z,2));
                        gcode += " F";
                        gcode += double_to_qstring(vorschub);
                        gcode += " (Restbohrmass)";
                        gcode += "\n";
                        gcode += ausfahren;
                    }
                }else if(boti-anboti > 0)
                {
                    //heißt keine Zustellungen und kein definiertes Restbohrmaß:
                    //Anbohren:
                    z =tt.get_prgtext()->get_werkstueckdicke() - anboti;
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(z,2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += " (Anbohren)";
                    gcode += "\n";
                    gcode += ausfahren;
                    //Restborung:
                    z =tt.get_prgtext()->get_werkstueckdicke() - boti;
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(z,2));
                    gcode += " F";
                    gcode += double_to_qstring(vorschub);
                    gcode += " (Resttiefe)";
                    gcode += "\n";
                    gcode += ausfahren;
                }else
                {
                    //heiß Bohrung in einem Zug:
                    //Restborung:
                    z =tt.get_prgtext()->get_werkstueckdicke() - boti;
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(z,2));
                    gcode += " F";
                    gcode += double_to_qstring(vorschub);
                    gcode += "\n";
                    gcode += ausfahren;
                }

                //Abfahrpunkt:
                gcode += "G0 X";
                gcode += double_to_qstring(runden(startpunkt.x(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(startpunkt.y(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(startpunkt.z(),2));
                gcode += " (Abfahren)";
                gcode += "\n";

                gcode += "\n";
            }
        }else if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            QString werkzeugname = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            if(aktives_wkz == NICHT_DEFINIERT)
            {
                aktives_wkz = werkzeugname;
            }else if(aktives_wkz != werkzeugname)
            {
                QString tmp =  "Werkzeugwechsel werden derzeit nicht unterstuetzt!\n";
                        tmp += "Bitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.\n";
                        //tmp += aktives_wkz + " != " + werkzeugname;
                ui->plainTextEdit_GCode->clear();
                ui->plainTextEdit_GCode->insertPlainText(tmp);
                QApplication::restoreOverrideCursor();
                return;
            }
            QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            //Vorschübe setzen etc.:
            QString tmp;
            QString werkzeug = werkzeugdaten(werkzeugname);
            tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
            }
            eintauchvorschub = tmp.toDouble();
            tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
            }
            vorschub = tmp.toDouble();
            tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_DREHZAHL, ENDE_EINTRAG);
            }
            drehzahl = tmp.toDouble(); 
            tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
            }
            zustellmass = tmp.toDouble();

            QString anfahrtyp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);
            abfahrtyp = text_mitte(zeile, ABFAHRTYP, ENDE_EINTRAG);//brauchen wir später für das Abfahren

            if(zustellmass > 0)
            {
                //Gesamttiefe ermitteln:
                double tiefe_min =tt.get_prgtext()->get_werkstueckdicke();
                for(uint ii=i ; \
                    ii<=klartext.zeilenanzahl() && !klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG); \
                    ii++)
                {
                    double tmp = text_mitte(klartext.zeile(ii), POSITION_Z, ENDE_EINTRAG).toDouble();
                    if(tmp < tiefe_min)
                    {
                        tiefe_min = tmp;
                    }
                }
                double fraestiefe_max =tt.get_prgtext()->get_werkstueckdicke()- tiefe_min;
                double verschiebung_z = fraestiefe_max - zustellmass;

                for(uint ii=i ; \
                    verschiebung_z > 0;
                    ii++)
                {
                    QString zeile = klartext.zeile(ii); //die Variable "zeile" wird hier überladen
                    QMessageBox mb;
                    mb.setText(zeile);
                    //mb.exec();
                    if(ii == i)//Auftuf Fräser
                    {
                        if(anfahrtyp == ANABFAHRTYP_KEIN)
                        {
                            QString zeile_fkon2;
                            if(i+1<=tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeilenanzahl())//wenn es Zeilen dannach gibt
                            {
                                uint ii = i+1;
                                zeile_fkon2 =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                                while(klartext.zeile(ii).isEmpty()  &&  ii+1<=tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeilenanzahl()  )
                                {
                                    ii++;
                                    zeile_fkon2 =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                                }
                            }
                            text_zeilenweise fkon_tz2;
                            fkon_tz2.set_trennzeichen(TRZ_EL_);
                            fkon_tz2.set_text(zeile_fkon2);
                            text_zeilenweise geoelement2;
                            geoelement2.set_trennzeichen(TRZ_PA_);
                            geoelement2.set_text(fkon_tz2.zeile(1));

                            if(fkon_tz2.zeile(1).contains(STRECKE))
                            {
                                //Anfahrpunkt:
                                punkt3d startpunkt;
                                startpunkt.set_x(geoelement2.zeile(2).toDouble());
                                startpunkt.set_y(geoelement2.zeile(3).toDouble());
                                startpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());
                                gcode += "G0 X";
                                gcode += double_to_qstring(runden(startpunkt.x(),2));
                                gcode += " Y";
                                gcode += double_to_qstring(runden(startpunkt.y(),2));
                                gcode += " Z";
                                gcode += double_to_qstring(runden(startpunkt.z() + verschiebung_z,2));
                                gcode += "\n";

                                //Eintauchen:
                                startpunkt.set_z(geoelement2.zeile(4).toDouble());
                                gcode += "G1 Z";
                                gcode += double_to_qstring(runden(startpunkt.z() + verschiebung_z,2));
                                gcode += " F";
                                gcode += double_to_qstring(eintauchvorschub);
                                gcode += "\n";
                            }else if(fkon_tz2.zeile(1).contains(BOGEN))
                            {
                                //Anfahrpunkt:
                                punkt3d startpunkt;
                                startpunkt.set_x(geoelement2.zeile(2).toDouble());
                                startpunkt.set_y(geoelement2.zeile(3).toDouble());
                                startpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());
                                gcode += "G0 X";
                                gcode += double_to_qstring(runden(startpunkt.x(),2));
                                gcode += " Y";
                                gcode += double_to_qstring(runden(startpunkt.y(),2));
                                gcode += " Z";
                                gcode += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                                gcode += "\n";

                                //Eintauchen:
                                startpunkt.set_z(geoelement2.zeile(4).toDouble());
                                gcode += "G1 Z";
                                gcode += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                                gcode += " F";
                                gcode += double_to_qstring(eintauchvorschub);
                                gcode += "\n";
                            }
                        }else if(fkon_tz.zeile(1).contains(STRECKE))
                        {
                            //Anfahrpunkt:
                            punkt3d startpunkt;
                            startpunkt.set_x(geoelement.zeile(2).toDouble());
                            startpunkt.set_y(geoelement.zeile(3).toDouble());
                            startpunkt.set_z(geoelement.zeile(4).toDouble());
                            gcode += "G0 X";
                            gcode += double_to_qstring(runden(startpunkt.x(),2));
                            gcode += " Y";
                            gcode += double_to_qstring(runden(startpunkt.y(),2));
                            gcode += " Z";
                            gcode += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                            gcode += "\n";

                            gcode += "G1 X";
                            gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                            gcode += " Y";
                            gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                            gcode += " Z";
                            gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gcode += " F";
                            gcode += double_to_qstring(eintauchvorschub);
                            gcode += "\n";
                        }else if(fkon_tz.zeile(1).contains(BOGEN))
                        {
                            //Anfahrpunkt:
                            punkt3d startpunkt;
                            startpunkt.set_x(geoelement.zeile(2).toDouble());
                            startpunkt.set_y(geoelement.zeile(3).toDouble());
                            startpunkt.set_z(geoelement.zeile(4).toDouble());
                            gcode += "G0 X";
                            gcode += double_to_qstring(runden(startpunkt.x(),2));
                            gcode += " Y";
                            gcode += double_to_qstring(runden(startpunkt.y(),2));
                            gcode += " Z";
                            gcode += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                            gcode += "\n";

                            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                            if(geoelement.zeile(9) == "ja")
                            {
                                gcode += "G2";
                            }else
                            {
                                gcode += "G3";
                            }
                            gcode += " X";
                            gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                            gcode += " Y";
                            gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                            gcode += " Z";
                            gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gcode += " I";
                            gcode += double_to_qstring(runden(I,2));
                            gcode += " J";
                            gcode += double_to_qstring(runden(J,2));
                            gcode += " F";
                            gcode += double_to_qstring(eintauchvorschub);
                            gcode += "\n";
                        }
                    }else if(klartext.zeile(ii).contains(FRAESERGERADE_DIALOG))
                    {
                        QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                        text_zeilenweise fkon_tz;
                        fkon_tz.set_trennzeichen(TRZ_EL_);
                        fkon_tz.set_text(zeile_fkon);
                        text_zeilenweise geoelement;
                        geoelement.set_trennzeichen(TRZ_PA_);
                        geoelement.set_text(fkon_tz.zeile(1));

                        gcode += "G1 X";
                        gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                        gcode += " Y";
                        gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                        gcode += " Z";
                        gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble() + verschiebung_z,2));
                        gcode += " F";
                        gcode += double_to_qstring(vorschub);
                        gcode += "\n";

                        if(fkon_tz.zeilenanzahl()==3)
                        {
                            geoelement.set_text(fkon_tz.zeile(2));
                            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                            if(geoelement.zeile(9) == "ja")
                            {
                                gcode += "G2";
                            }else
                            {
                                gcode += "G3";
                            }
                            gcode += " X";
                            gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                            gcode += " Y";
                            gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                            gcode += " Z";
                            gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gcode += " I";
                            gcode += double_to_qstring(runden(I,2));
                            gcode += " J";
                            gcode += double_to_qstring(runden(J,2));
                            gcode += " F";
                            gcode += double_to_qstring(eintauchvorschub);
                            gcode += "\n";
                        }
                    }else if(klartext.zeile(ii).contains(FRAESERBOGEN_DIALOG))
                    {
                        QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                        text_zeilenweise fkon_tz;
                        fkon_tz.set_trennzeichen(TRZ_EL_);
                        fkon_tz.set_text(zeile_fkon);
                        text_zeilenweise geoelement;
                        geoelement.set_trennzeichen(TRZ_PA_);
                        geoelement.set_text(fkon_tz.zeile(1));

                        double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                        double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                        if(geoelement.zeile(9) == "ja")
                        {
                            gcode += "G2";
                        }else
                        {
                            gcode += "G3";
                        }
                        gcode += " X";
                        gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                        gcode += " Y";
                        gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                        gcode += " Z";
                        gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble() + verschiebung_z,2));
                        gcode += " I";
                        gcode += double_to_qstring(runden(I,2));
                        gcode += " J";
                        gcode += double_to_qstring(runden(J,2));
                        gcode += " F";
                        gcode += double_to_qstring(eintauchvorschub);
                        gcode += "\n";
                    }else if(klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG))
                    {
                        punkt3d endpunkt;
                        endpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());

                        if(abfahrtyp == ANABFAHRTYP_KEIN)
                        {
                            gcode += "G1 Z";
                            gcode += double_to_qstring(runden(endpunkt.z() + verschiebung_z,2));
                            gcode += " F";
                            gcode += double_to_qstring(eintauchvorschub);
                            gcode += "\n";
                        }else
                        {
                            QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                            text_zeilenweise fkon_tz;
                            fkon_tz.set_trennzeichen(TRZ_EL_);
                            fkon_tz.set_text(zeile_fkon);
                            text_zeilenweise geoelement;
                            geoelement.set_trennzeichen(TRZ_PA_);
                            geoelement.set_text(fkon_tz.zeile(1));

                            if(fkon_tz.zeile(1).contains(STRECKE))
                            {
                                gcode += "G1 X";
                                gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                                gcode += " Y";
                                gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                                gcode += " Z";
                                gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                                gcode += " F";
                                gcode += double_to_qstring(eintauchvorschub);
                                gcode += "\n";
                            }else if(fkon_tz.zeile(1).contains(BOGEN))
                            {
                                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                                if(geoelement.zeile(9) == "ja")
                                {
                                    gcode += "G2";
                                }else
                                {
                                    gcode += "G3";
                                }
                                gcode += " X";
                                gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                                gcode += " Y";
                                gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                                gcode += " Z";
                                gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                                gcode += " I";
                                gcode += double_to_qstring(runden(I,2));
                                gcode += " J";
                                gcode += double_to_qstring(runden(J,2));
                                gcode += " F";
                                gcode += double_to_qstring(eintauchvorschub);
                                gcode += "\n";
                            }
                        }
                    }

                    if(klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG))
                    {
                        verschiebung_z = verschiebung_z - zustellmass;
                        ii = i-1;
                    }
                }
            }

            if(anfahrtyp == ANABFAHRTYP_KEIN)
            {
                QString zeile_fkon2;
                if(i+1<=tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeilenanzahl())//wenn es Zeilen dannach gibt
                {
                    uint ii = i+1;
                    zeile_fkon2 =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                    while(klartext.zeile(ii).isEmpty()  &&  ii+1<=tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeilenanzahl()  )
                    {
                        ii++;
                        zeile_fkon2 =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(ii);
                    }
                }
                text_zeilenweise fkon_tz2;
                fkon_tz2.set_trennzeichen(TRZ_EL_);
                fkon_tz2.set_text(zeile_fkon2);
                text_zeilenweise geoelement2;
                geoelement2.set_trennzeichen(TRZ_PA_);
                geoelement2.set_text(fkon_tz2.zeile(1));

                if(fkon_tz2.zeile(1).contains(STRECKE))
                {
                    //Anfahrpunkt:
                    punkt3d startpunkt;
                    startpunkt.set_x(geoelement2.zeile(2).toDouble());
                    startpunkt.set_y(geoelement2.zeile(3).toDouble());
                    startpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());
                    gcode += "G0 X";
                    gcode += double_to_qstring(runden(startpunkt.x(),2));
                    gcode += " Y";
                    gcode += double_to_qstring(runden(startpunkt.y(),2));
                    gcode += " Z";
                    gcode += double_to_qstring(runden(startpunkt.z(),2));
                    gcode += "\n";

                    //Eintauchen:
                    startpunkt.set_z(geoelement2.zeile(4).toDouble());
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(startpunkt.z(),2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += "\n";
                }else if(fkon_tz2.zeile(1).contains(BOGEN))
                {
                    //Anfahrpunkt:
                    punkt3d startpunkt;
                    startpunkt.set_x(geoelement2.zeile(2).toDouble());
                    startpunkt.set_y(geoelement2.zeile(3).toDouble());
                    startpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());
                    gcode += "G0 X";
                    gcode += double_to_qstring(runden(startpunkt.x(),2));
                    gcode += " Y";
                    gcode += double_to_qstring(runden(startpunkt.y(),2));
                    gcode += " Z";
                    gcode += double_to_qstring(runden(startpunkt.z(),2));
                    gcode += "\n";

                    //Eintauchen:
                    startpunkt.set_z(geoelement2.zeile(4).toDouble());
                    gcode += "G1 Z";
                    gcode += double_to_qstring(runden(startpunkt.z(),2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += "\n";
                }
            }else if(fkon_tz.zeile(1).contains(STRECKE))
            {
                //Anfahrpunkt:
                punkt3d startpunkt;
                startpunkt.set_x(geoelement.zeile(2).toDouble());
                startpunkt.set_y(geoelement.zeile(3).toDouble());
                startpunkt.set_z(geoelement.zeile(4).toDouble());
                gcode += "G0 X";
                gcode += double_to_qstring(runden(startpunkt.x(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(startpunkt.y(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(startpunkt.z(),2));
                gcode += "\n";

                gcode += "G1 X";
                gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gcode += " F";
                gcode += double_to_qstring(eintauchvorschub);
                gcode += "\n";
            }else if(fkon_tz.zeile(1).contains(BOGEN))
            {
                //Anfahrpunkt:
                punkt3d startpunkt;
                startpunkt.set_x(geoelement.zeile(2).toDouble());
                startpunkt.set_y(geoelement.zeile(3).toDouble());
                startpunkt.set_z(geoelement.zeile(4).toDouble());
                gcode += "G0 X";
                gcode += double_to_qstring(runden(startpunkt.x(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(startpunkt.y(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(startpunkt.z(),2));
                gcode += "\n";

                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                if(geoelement.zeile(9) == "ja")
                {
                    gcode += "G2";
                }else
                {
                    gcode += "G3";
                }
                gcode += " X";
                gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gcode += " I";
                gcode += double_to_qstring(runden(I,2));
                gcode += " J";
                gcode += double_to_qstring(runden(J,2));
                gcode += " F";
                gcode += double_to_qstring(eintauchvorschub);
                gcode += "\n";
            }

        }else if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            gcode += "G1 X";
            gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
            gcode += " Y";
            gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
            gcode += " Z";
            gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
            gcode += " F";
            gcode += double_to_qstring(vorschub);
            gcode += "\n";

            if(fkon_tz.zeilenanzahl()==3)
            {
                geoelement.set_text(fkon_tz.zeile(2));
                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                if(geoelement.zeile(9) == "ja")
                {
                    gcode += "G2";
                }else
                {
                    gcode += "G3";
                }
                gcode += " X";
                gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                gcode += " Y";
                gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                gcode += " Z";
                gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gcode += " I";
                gcode += double_to_qstring(runden(I,2));
                gcode += " J";
                gcode += double_to_qstring(runden(J,2));
                gcode += " F";
                gcode += double_to_qstring(eintauchvorschub);
                gcode += "\n";
            }
        }else if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

            if(geoelement.zeile(9) == "ja")
            {
                gcode += "G2";
            }else
            {
                gcode += "G3";
            }
            gcode += " X";
            gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
            gcode += " Y";
            gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
            gcode += " Z";
            gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
            gcode += " I";
            gcode += double_to_qstring(runden(I,2));
            gcode += " J";
            gcode += double_to_qstring(runden(J,2));
            gcode += " F";
            gcode += double_to_qstring(eintauchvorschub);
            gcode += "\n";

        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            punkt3d endpunkt;
            endpunkt.set_z(tt.get_prgtext()->get_werkstueckdicke() +tt.get_prgtext()->get_sicherheitsabstand());

            if(abfahrtyp == ANABFAHRTYP_KEIN)
            {
                gcode += "G1 Z";
                gcode += double_to_qstring(runden(endpunkt.z(),2));
                gcode += " F";
                gcode += double_to_qstring(eintauchvorschub);
                gcode += "\n";
            }else
            {
                QString zeile_fkon =tt.get_prgtext()->get_fkon().get_text_zeilenweise().zeile(i);
                text_zeilenweise fkon_tz;
                fkon_tz.set_trennzeichen(TRZ_EL_);
                fkon_tz.set_text(zeile_fkon);
                text_zeilenweise geoelement;
                geoelement.set_trennzeichen(TRZ_PA_);
                geoelement.set_text(fkon_tz.zeile(1));

                if(fkon_tz.zeile(1).contains(STRECKE))
                {
                    gcode += "G1 X";
                    gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                    gcode += " Y";
                    gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                    gcode += " Z";
                    gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += "\n";
                }else if(fkon_tz.zeile(1).contains(BOGEN))
                {
                    double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                    double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                    if(geoelement.zeile(9) == "ja")
                    {
                        gcode += "G2";
                    }else
                    {
                        gcode += "G3";
                    }
                    gcode += " X";
                    gcode += double_to_qstring(runden(geoelement.zeile(5).toDouble(),2));
                    gcode += " Y";
                    gcode += double_to_qstring(runden(geoelement.zeile(6).toDouble(),2));
                    gcode += " Z";
                    gcode += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                    gcode += " I";
                    gcode += double_to_qstring(runden(I,2));
                    gcode += " J";
                    gcode += double_to_qstring(runden(J,2));
                    gcode += " F";
                    gcode += double_to_qstring(eintauchvorschub);
                    gcode += "\n";
                }
            }
        }
    }

    ui->plainTextEdit_GCode->insertPlainText(gcode);

    if(tmp_fkon_ein == false)
    {
       tt.aktualisieren_fkon_ein_aus(false);
    }

    QApplication::restoreOverrideCursor();
}

void MainWindow::on_pushButton_Aktualisieren_GCode_clicked()
{
    on_actionGCode_berechnen_triggered();
}

void MainWindow::on_actionGCode_exportieren_triggered()
{
    QString fileName;
    on_actionDateiSpeichern_triggered();
    fileName = tt.get_prgname();
    if(fileName == NICHT_DEFINIERT)
    {
        QMessageBox mb;
        mb.setText("Export wurde abgebrochen");
        mb.exec();
        return;
    }

    //Dateiendung ändern:
    if(fileName.contains(DATEIENDUNG_EIGENE))
    {
        QString endung = DATEIENDUNG_EIGENE;
        QString tmp;
        for(int i = 0 ; i<(fileName.length()-endung.length()) ; i++)
        {
            tmp += fileName.at(i);
        }
        fileName = tmp + DATEIENDUNG_GCODE;
    }else
    {
        fileName = fileName + DATEIENDUNG_GCODE;
    }

    //Programmliste in String schreiben
    QString dateiInhalt = ui->plainTextEdit_GCode->toPlainText();
    //Datei füllen und speichern
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Wenn es nicht möglich ist die Datei zu öffnen oder neu anzulegen
    {
        QMessageBox mb;
        mb.setText("Fehler beim Zugriff auf Datei:\n" + fileName);
        mb.exec();
    } else
    {
        file.remove(); //lösche alte Datei wenn vorhanden
        file.close(); //beende Zugriff
        file.open(QIODevice::WriteOnly | QIODevice::Text); //lege Datei neu an
        file.write(dateiInhalt.toUtf8()); //fülle Datei mit Inhalt
        file.close(); //beende Zugriff
        QMessageBox mb;
        mb.setText("G-Code erfolgreich exportiert.\nDatei wurde gespeichert.");
        mb.exec();
    }

}

void MainWindow::on_pushButton_Exportieren_GCODE_clicked()
{
    on_actionGCode_exportieren_triggered();
}

//---------------------------------------------------Vorschaufenster

void MainWindow::vorschauAktualisieren()
{
    connect(this, SIGNAL(sendVorschauAktualisieren(programmtext,int)), &vorschaufenster, SLOT(slot_aktualisieren(programmtext,int)));
    emit sendVorschauAktualisieren(*tt.get_prgtext(), ui->listWidget_Programmliste->currentRow()+1);
}

void MainWindow::on_listWidget_Programmliste_currentRowChanged(int currentRow)
{
    connect(this, SIGNAL(sendAktiveProgrammzeile(int)), &vorschaufenster, SLOT(slot_aktives_Element_einfaerben(int)));
    emit sendAktiveProgrammzeile(currentRow+1);
}

//---------------------------------------------------Umwandeln:
void MainWindow::on_actionKreis_in_Kreistasche_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(KREIS))
            {
                kreis k(programmzeile);
                QString msg = vorlage_Ktasche;
                QString alt;
                alt  = POSITION_X;
                alt += text_mitte(vorlage_Ktasche, POSITION_X, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_X + k.mitte2d().x_QString() + ENDE_EINTRAG);

                alt  = POSITION_Y;
                alt += text_mitte(vorlage_Ktasche, POSITION_Y, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_Y + k.mitte2d().y_QString() + ENDE_EINTRAG);

                alt  = DURCHMESSER;
                alt += text_mitte(vorlage_Ktasche, DURCHMESSER, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, DURCHMESSER + double_to_qstring(k.radius()*2) + ENDE_EINTRAG);

                disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &ktasche, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(msg, true, wkznamen_nur_fraeser);
            }else
            {
                QMessageBox mb;
                mb.setText("Die aktive Zeile enthaellt keinen Kreis!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionKreis_in_Bohrung_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(KREIS))
            {
                kreis k(programmzeile);
                QString msg = vorlage_dbohren;
                QString alt;
                alt  = POSITION_X;
                alt += text_mitte(vorlage_dbohren, POSITION_X, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_X + k.mitte2d().x_QString() + ENDE_EINTRAG);

                alt  = POSITION_Y;
                alt += text_mitte(vorlage_dbohren, POSITION_Y, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_Y + k.mitte2d().y_QString() + ENDE_EINTRAG);

                alt  = DURCHMESSER;
                alt += text_mitte(vorlage_dbohren, DURCHMESSER, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, DURCHMESSER + double_to_qstring(k.radius()*2) + ENDE_EINTRAG);

                //werkzeug mit richtigem DM finden:
                QString wkzname = w.get_bohrwkzname(k.radius()*2);
                if(!wkzname.isEmpty())
                {
                    alt  = WKZ_NAME;
                    alt += text_mitte(vorlage_dbohren, WKZ_NAME, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, WKZ_NAME + wkzname + ENDE_EINTRAG);
                }else
                {
                    QMessageBox mb;
                    mb.setText(tr("Es wurde kein Werkzeug mit passemdem DM gefunden!\nBitte ein passendes Werkzeug wählen."));
                    mb.exec();
                }

                disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &dbohren, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(msg, true, wkznamen_nur_bohrer);
            }else
            {
                QMessageBox mb;
                mb.setText("Die aktive Zeile enthaellt keinen Kreis!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionKreistasche_in_Kreis_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(KREISTASCHE_DIALOG))
            {
                kreis k;
                k.set_farbe(FARBE_GRUEN);

                punkt3d mipu;
                mipu.set_x(text_mitte(programmzeile, POSITION_X, ENDE_EINTRAG));
                mipu.set_y(text_mitte(programmzeile, POSITION_Y, ENDE_EINTRAG));
                k.set_mittelpunkt(mipu);
                k.set_radius(ausdruck_auswerten("(" + \
                                                text_mitte(programmzeile, DURCHMESSER, ENDE_EINTRAG) + \
                                                ")/2"));

                disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dkreis, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(k.get_text(), true);
            }else
            {
                QMessageBox mb;
                mb.setText("Die aktive Zeile enthaellt keine Kreistasche!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionBohrung_in_Kreis_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(BOHREN_DIALOG))
            {
                kreis k;
                k.set_farbe(FARBE_GRUEN);

                punkt3d mipu;
                mipu.set_x(text_mitte(programmzeile, POSITION_X, ENDE_EINTRAG));
                mipu.set_y(text_mitte(programmzeile, POSITION_Y, ENDE_EINTRAG));
                k.set_mittelpunkt(mipu);
                k.set_radius(ausdruck_auswerten("(" + \
                                                text_mitte(programmzeile, DURCHMESSER, ENDE_EINTRAG) + \
                                                ")/2"));

                disconnect(this, SIGNAL(sendDialogData(QString, bool)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool)), &dkreis, SLOT(getDialogData(QString, bool)));
                emit sendDialogData(k.get_text(), true);
            }else
            {
                QMessageBox mb;
                mb.setText(tr("Die aktive Zeile enthaellt keine Bohrung!"));
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionKreistasche_in_Bohrung_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(KREISTASCHE_DIALOG))
            {
                QString msg = vorlage_dbohren;
                QString alt;
                QString neu;
                alt  = POSITION_X;
                alt += text_mitte(vorlage_dbohren, POSITION_X, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = POSITION_X;
                neu += text_mitte(programmzeile, POSITION_X, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = POSITION_Y;
                alt += text_mitte(vorlage_dbohren, POSITION_Y, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = POSITION_Y;
                neu += text_mitte(programmzeile, POSITION_Y, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = BOHRTIEFE;
                alt += text_mitte(vorlage_dbohren, BOHRTIEFE, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = BOHRTIEFE;
                neu += text_mitte(programmzeile, TASCHENTIEFE, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = DURCHMESSER;
                alt += text_mitte(vorlage_dbohren, DURCHMESSER, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = DURCHMESSER;
                neu += text_mitte(programmzeile, DURCHMESSER, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                //werkzeug mit richtigem DM finden:
                QString wkzname = w.get_bohrwkzname(text_mitte(programmzeile, DURCHMESSER, ENDE_EINTRAG).toDouble());
                if(!wkzname.isEmpty())
                {
                    alt  = WKZ_NAME;
                    alt += text_mitte(vorlage_dbohren, WKZ_NAME, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, WKZ_NAME + wkzname + ENDE_EINTRAG);
                }else
                {
                    QMessageBox mb;
                    mb.setText(tr("Es wurde kein Werkzeug mit passemdem DM gefunden!\nBitte ein passendes Werkzeug waehlen."));
                    mb.exec();
                }

                disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &dbohren, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(msg, true, wkznamen_nur_bohrer);
            }else
            {
                QMessageBox mb;
                mb.setText("Die aktive Zeile enthaellt keine Kreistasche!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionBohrung_in_Kreistasche_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(BOHREN_DIALOG))
            {
                QString msg = vorlage_Ktasche;
                QString alt;
                QString neu;
                alt  = POSITION_X;
                alt += text_mitte(vorlage_Ktasche, POSITION_X, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = POSITION_X;
                neu += text_mitte(programmzeile, POSITION_X, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = POSITION_Y;
                alt += text_mitte(vorlage_Ktasche, POSITION_Y, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = POSITION_Y;
                neu += text_mitte(programmzeile, POSITION_Y, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = TASCHENTIEFE;
                alt += text_mitte(vorlage_Ktasche, TASCHENTIEFE, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = TASCHENTIEFE;
                neu += text_mitte(programmzeile, BOHRTIEFE, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                alt  = DURCHMESSER;
                alt += text_mitte(vorlage_Ktasche, DURCHMESSER, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                neu  = DURCHMESSER;
                neu += text_mitte(programmzeile, DURCHMESSER, ENDE_EINTRAG);
                neu += ENDE_EINTRAG;
                msg.replace(alt, neu);

                disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &ktasche, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(msg, true, wkznamen_nur_fraeser);
            }else
            {
                QMessageBox mb;
                mb.setText(tr("Die aktive Zeile enthaellt keine Bohrung!"));
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionLinien_in_Fraeskonturen_umwandeln_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge >= 1)
            {
                text_zeilenweise defaultwerte_Dialoge;
                defaultwerte_Dialoge.zeile_anhaengen(FRAESERAUFRUF_DIALOG + vorlage_Faufruf + ENDE_ZEILE);
                defaultwerte_Dialoge.zeile_anhaengen(FRAESERABFAHREN_DIALOG + vorlage_Fabfa + ENDE_ZEILE);
                defaultwerte_Dialoge.zeile_anhaengen(FRAESERGERADE_DIALOG + vorlage_Fgerade + ENDE_ZEILE);
                defaultwerte_Dialoge.zeile_anhaengen(FRAESERBOGEN_DIALOG + vorlage_Fbogen + ENDE_ZEILE);
               tt.get_prgtext()->linien_zu_fkon(row_erstes+1, row_erstes+items_menge, defaultwerte_Dialoge);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                vorschauAktualisieren();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionFraeskonturen_in_Linien_umwandeln_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge == 1)
            {
                uint ibeg = 0;
                uint iend = 0;
                bool gefunden = false;
                for(int i = row_erstes; i>=0 ; i--)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        ibeg = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                gefunden = false;
                for(uint i = row_erstes; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ; i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        iend = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                //Sicherheitsabfrage: Genau 1x Faufr und 1x Fabfah in der Auswahl?
                //Oder anders ausgedrückt: Wurde ein Teil eine Fräskontur aktiviert oder z.B. ein Kommentar
                uint anzaufr = 0;
                uint anzabfa = 0;
                for(uint i=ibeg; i<=iend ;i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        anzaufr++;
                    }else if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        anzabfa++;
                    }
                }
                if(anzaufr!=1 || anzabfa!=1)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                }else
                {
                   tt.get_prgtext()->fkon_zu_linien(ibeg+1, iend+1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                    vorschauAktualisieren();
                }
            }
            if(items_menge > 1)
            {
                QMessageBox mb;
                mb.setText("Bitte nur eine Zeile der Fraeskontur markieren!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_action4_Eck_in_Rechtecktasche_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();
        int row_erstes = 0;//Nummer des ersten Elementes
        for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
        {
            if(ui->listWidget_Programmliste->item(i)->isSelected())
            {
                row_erstes = i;
                break;
            }
        }
        if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
        {
            items_menge = items_menge-1;
        }
        text_zeilenweise auswahl;
        for(int i=row_erstes; i<row_erstes+items_menge ;i++)
        {
            auswahl.zeile_anhaengen(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1));
        }
        //AX + AY + Schablonenhöhe wieder abzeihen:
        for(uint i=1; i<=auswahl.zeilenanzahl() ;i++)
        {
            QString zeile = auswahl.zeile(i);
            if(zeile.contains(STRECKE))
            {
                strecke s(zeile);
                punkt3d p1;
                p1 = s.startp();
                p1.set_x(p1.x()-tt.get_prgtext()->get_ax());
                p1.set_y(p1.y()-tt.get_prgtext()->get_ay());
                p1.set_z(p1.z()-tt.get_prgtext()->get_az());
                punkt3d p2;
                p2 = s.endp();
                p2.set_x(p2.x()-tt.get_prgtext()->get_ax());
                p2.set_y(p2.y()-tt.get_prgtext()->get_ay());
                p2.set_z(p2.z()-tt.get_prgtext()->get_az());
                s.set_start(p1);
                s.set_ende(p2);
                zeile = s.get_text();
            }else if(zeile.contains(BOGEN))
            {
                bogen b(zeile);
                punkt3d p1;
                p1 = b.start();
                p1.set_x(p1.x()-tt.get_prgtext()->get_ax());
                p1.set_y(p1.y()-tt.get_prgtext()->get_ay());
                p1.set_z(p1.z()-tt.get_prgtext()->get_az());
                punkt3d p2;
                p2 = b.ende();
                p2.set_x(p2.x()-tt.get_prgtext()->get_ax());
                p2.set_y(p2.y()-tt.get_prgtext()->get_ay());
                p2.set_z(p2.z()-tt.get_prgtext()->get_az());
                b.set_startpunkt(p1);
                b.set_endpunkt(p2);
                b.aktualisieren();
                zeile = b.get_text();
            }else if(zeile.contains(KREIS))
            {
                kreis k(zeile);
                punkt3d p1;
                p1 = k.mitte3d();
                p1.set_x(p1.x()-tt.get_prgtext()->get_ax());
                p1.set_y(p1.y()-tt.get_prgtext()->get_ay());
                p1.set_z(p1.z()-tt.get_prgtext()->get_az());
                k.set_mittelpunkt(p1);
                zeile = k.get_text();
            }

            auswahl.zeile_ersaetzen(i, zeile);
        }

        if(items_menge==4)//evtl. 4eck (4 Linien) oder Kreis aus 4 Bögen(Eckenradius = tal/2)
        {
            //Prüfen ob die Auswahl nur Strecken enthällt:
            bool linien = true;
            bool boegen = true;
            for(uint i=1; i<=auswahl.zeilenanzahl() ;i++)
            {
                if(!auswahl.zeile(i).contains(STRECKE))
                {
                    linien = false;
                }
                if(!auswahl.zeile(i).contains(BOGEN))
                {
                    boegen = false;
                }
            }
            if(linien==false)
            {
                if(boegen==false)
                {
                    QMessageBox mb;
                    mb.setText("Die 4 aktivierten Zellen enthalten nicht ausschließlich Strecken oder Boegen!");
                    mb.exec();
                    return;
                }else
                {
                    bogen b1(auswahl.zeile(1));
                    bogen b2(auswahl.zeile(2));
                    bogen b3(auswahl.zeile(3));
                    bogen b4(auswahl.zeile(4));

                    if(cagleich(b1.mitte(), b2.mitte(), 0.1)  && \
                       cagleich(b1.mitte(), b3.mitte(), 0.1)  && \
                       cagleich(b1.mitte(), b4.mitte(), 0.1)     )
                    {
                        QString msg = vorlage_Rtasche;
                        QString alt;
                        alt  = BEZUGSPUNKT;
                        alt += text_mitte(vorlage_Rtasche, BEZUGSPUNKT, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        QString bezpu = BEZUGSPUNKT_MITTE;
                        msg.replace(alt, BEZUGSPUNKT + bezpu + ENDE_EINTRAG);

                        alt  = POSITION_X;
                        alt += text_mitte(vorlage_Rtasche, POSITION_X, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        msg.replace(alt, POSITION_X + b1.mitte().x_QString() + ENDE_EINTRAG);

                        alt  = POSITION_Y;
                        alt += text_mitte(vorlage_Rtasche, POSITION_Y, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        msg.replace(alt, POSITION_Y + b1.mitte().y_QString() + ENDE_EINTRAG);

                        QString tal = double_to_qstring(b1.rad()*2);
                        alt  = TASCHENLAENGE;
                        alt += text_mitte(vorlage_Rtasche, TASCHENLAENGE, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        msg.replace(alt, TASCHENLAENGE + tal + ENDE_EINTRAG);

                        alt  = TASCHENBREITE;
                        alt += text_mitte(vorlage_Rtasche, TASCHENBREITE, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        msg.replace(alt, TASCHENBREITE + tal + ENDE_EINTRAG);

                        alt  = RADIUS;
                        alt += text_mitte(vorlage_Rtasche, RADIUS, ENDE_EINTRAG);
                        alt += ENDE_EINTRAG;
                        msg.replace(alt, RADIUS + b1.rad_qString() + ENDE_EINTRAG);

                        disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                        connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
                        emit sendDialogData(msg, true, werkzeugnamen);

                       tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge-1);
                        aktualisiere_anzeigetext();
                        ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die 4 aktivierten Boegen haben nicht den selben Mittelpunkt!");
                        mb.exec();
                        return;
                    }
                }

            }else
            {
                strecke s1(auswahl.zeile(1));
                strecke s2(auswahl.zeile(2));
                strecke s3(auswahl.zeile(3));
                strecke s4(auswahl.zeile(4));
                //Prüfen ob die Endpunkte der Strecken deckungsgleich sind:
                strecke sa,sb,sc,sd;
                sa = s1;
                if(s1.endp()==s2.startp())
                {
                    sb=s2;
                }else if(sa.endp()==s2.endp())
                {
                    sb=s2;
                    sb.richtung_unkehren();
                }else if(sa.endp()==s3.startp())
                {
                    sb=s3;
                }else if(sa.endp()==s3.endp())
                {
                    sb=s3;
                    sb.richtung_unkehren();
                }else if(sa.endp()==s4.startp())
                {
                    sb=s4;
                }else if(sa.endp()==s4.endp())
                {
                    sb=s4;
                    sb.richtung_unkehren();
                }else
                {
                    QMessageBox mb;
                    mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                    mb.exec();
                    return;
                }

                if(  (sb.startp()==s2.startp()  &&  sb.endp()==s2.endp())  ||  \
                     (sb.startp()==s2.endp()  &&  sb.endp()==s2.startp())      )
                {
                    //sa==s1
                    //sb==s2
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s3,s4
                    if(sb.endp()==s3.startp())
                    {
                        sc=s3;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s3.endp())
                    {
                        sc=s3;
                    }else if(sb.endp()==s4.startp())
                    {
                        sc=s4;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s4.endp())
                    {
                        sc=s4;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    if(  (sc.startp()==s3.startp()  &&  sc.endp()==s3.endp())  ||  \
                         (sc.startp()==s3.endp()  &&  sc.endp()==s3.startp())      )
                    {
                        //sa==s1
                        //sb==s2
                        //sc==s3
                        //sd==...
                        //nicht zugewiesen: s4
                        sd=s4;
                    }else if(  (sc.startp()==s4.startp()  &&  sc.endp()==s4.endp())  ||  \
                               (sc.startp()==s4.endp()  &&  sc.endp()==s4.startp())      )
                    {
                        //sa==s1
                        //sb==s2
                        //sc==s4
                        //sd==...
                        //nicht zugewiesen: s3
                        sd=s3;
                    }

                    if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }else if(  (sb.startp()==s3.startp()  &&  sb.endp()==s3.endp())  ||  \
                           (sb.startp()==s3.endp()  &&  sb.endp()==s3.startp())      )
                {
                    //sa==s1
                    //sb==s3
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s2,s4
                    if(sb.endp()==s2.startp())
                    {
                        sc=s2;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s2.endp())
                    {
                        sc=s2;
                    }else if(sb.endp()==s4.startp())
                    {
                        sc=s4;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s4.endp())
                    {
                        sc=s4;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    if(  (sc.startp()==s2.startp()  &&  sc.endp()==s2.endp())  ||  \
                         (sc.startp()==s2.endp()  &&  sc.endp()==s2.startp())      )
                    {
                        //sa==s1
                        //sb==s3
                        //sc==s2
                        //sd==...
                        //nicht zugewiesen: s4
                        sd=s4;
                    }else if(  (sc.startp()==s4.startp()  &&  sc.endp()==s4.endp())  ||  \
                               (sc.startp()==s4.endp()  &&  sc.endp()==s4.startp())      )
                    {
                        //sa==s1
                        //sb==s3
                        //sc==s4
                        //sd==...
                        //nicht zugewiesen: s2
                        sd=s2;
                    }

                    if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }else if(  (sb.startp()==s4.startp()  &&  sb.endp()==s4.endp())  ||  \
                           (sb.startp()==s4.endp()  &&  sb.endp()==s4.startp())      )
                {
                    //sa==s1
                    //sb==s4
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s2,s3
                    if(sb.endp()==s2.startp())
                    {
                        sc=s2;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s2.endp())
                    {
                        sc=s2;
                    }else if(sb.endp()==s3.startp())
                    {
                        sc=s3;
                        sc.richtung_unkehren();
                    }else if(sb.endp()==s3.endp())
                    {
                        sc=s3;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    if(  (sc.startp()==s2.startp()  &&  sc.endp()==s2.endp())  ||  \
                         (sc.startp()==s2.endp()  &&  sc.endp()==s2.startp())      )
                    {
                        //sa==s1
                        //sb==s4
                        //sc==s2
                        //sd==...
                        //nicht zugewiesen: s3
                        sd=s3;
                    }else if(  (sc.startp()==s3.startp()  &&  sc.endp()==s3.endp())  ||  \
                               (sc.startp()==s3.endp()  &&  sc.endp()==s3.startp())      )
                    {
                        //sa==s1
                        //sb==s4
                        //sc==s3
                        //sd==...
                        //nicht zugewiesen: s2
                        sd=s2;
                    }

                    if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(sd.startp()==sa.startp()  &&  sd.endp()==sc.startp())
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }

                //sa,sb,sc und sd konnten korrekt zugewiesen werden
                //Prüfen ob 4eck einen rechten winkel hat:
                double wi = winkel(sd.endp().x(), sd.endp().y(), \
                                   sd.startp().x(), sd.startp().y(),
                                   sa.endp().x(), sa.endp().y());
                if(wi > 89.9  &&  wi < 90.1)
                {
                    //die strecken sa,sb,sc und sd beschreiben ein rechteck :-)
                    //Rechteck in rta umwandeln:
                    strecke diag;//Diagonale
                    diag.set_start(sa.startp());
                    diag.set_ende(sb.endp());

                    QString msg = vorlage_Rtasche;
                    QString alt;
                    alt  = BEZUGSPUNKT;
                    alt += text_mitte(vorlage_Rtasche, BEZUGSPUNKT, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    QString bezpu = BEZUGSPUNKT_MITTE;
                    msg.replace(alt, BEZUGSPUNKT + bezpu + ENDE_EINTRAG);

                    alt  = POSITION_X;
                    alt += text_mitte(vorlage_Rtasche, POSITION_X, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, POSITION_X + diag.get_mittelpunkt2d().x_QString() + ENDE_EINTRAG);

                    alt  = POSITION_Y;
                    alt += text_mitte(vorlage_Rtasche, POSITION_Y, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, POSITION_Y + diag.get_mittelpunkt2d().y_QString() + ENDE_EINTRAG);

                    alt  = TASCHENLAENGE;
                    alt += text_mitte(vorlage_Rtasche, TASCHENLAENGE, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, TASCHENLAENGE + sa.laenge2dim_QString() + ENDE_EINTRAG);

                    alt  = TASCHENBREITE;
                    alt += text_mitte(vorlage_Rtasche, TASCHENBREITE, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, TASCHENBREITE + sb.laenge2dim_QString() + ENDE_EINTRAG);

                    alt  = RADIUS;
                    alt += text_mitte(vorlage_Rtasche, RADIUS, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    QString r = "0";
                    msg.replace(alt, RADIUS + r + ENDE_EINTRAG);

                    double drewi = winkel(sa.endp().x(), sa.endp().y(), \
                                          sa.startp().x(), sa.startp().y());

                    alt  = WINKEL;
                    alt += text_mitte(vorlage_Rtasche, WINKEL, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, WINKEL + double_to_qstring(drewi) + ENDE_EINTRAG);

                    disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                    connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
                    emit sendDialogData(msg, true, werkzeugnamen);

                   tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge-1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);

                }else
                {
                    QMessageBox mb;
                    mb.setText("Die 4 Geraden sind nicht rechtwinklig zu einander!");
                    mb.exec();
                    return;
                }
            }
        }else if(items_menge==8)//evtl 4eck mit Radius (4 Linien + 4 Viertelkreisbögen)
        {
            text_zeilenweise tzstrecken, tzboegen;
            uint anz_s=0;
            uint anz_b=0;
            for(uint i=1; i<=auswahl.zeilenanzahl() ;i++)
            {
                if(auswahl.zeile(i).contains(STRECKE))
                {
                    tzstrecken.zeile_anhaengen(auswahl.zeile(i));
                    anz_s++;
                }else if(auswahl.zeile(i).contains(BOGEN))
                {
                    tzboegen.zeile_anhaengen(auswahl.zeile(i));
                    anz_b++;
                }
            }
            if(anz_s!=4  ||  anz_b!=4)
            {
                QMessageBox mb;
                mb.setText("Die 8 aktivierten Zellen enthalten nicht 4 Strecken und 4 Boegen!");
                mb.exec();
                return;
            }
            bogen b1(tzboegen.zeile(1));
            bogen b2(tzboegen.zeile(2));
            bogen b3(tzboegen.zeile(3));
            bogen b4(tzboegen.zeile(4));

            if(cagleich(b1.rad(), b2.rad(), 0.1)  && \
               cagleich(b1.rad(), b3.rad(), 0.1)  && \
               cagleich(b1.rad(), b4.rad(), 0.1)     )
            {
                strecke s1(tzstrecken.zeile(1));
                strecke s2(tzstrecken.zeile(2));
                strecke s3(tzstrecken.zeile(3));
                strecke s4(tzstrecken.zeile(4));
                strecke_bezugspunkt sbezpu = strecke_bezugspunkt_mitte;
                s1.set_laenge_2d(s1.laenge2dim()+b1.rad()*2, sbezpu);
                s2.set_laenge_2d(s2.laenge2dim()+b1.rad()*2, sbezpu);
                s3.set_laenge_2d(s3.laenge2dim()+b1.rad()*2, sbezpu);
                s4.set_laenge_2d(s4.laenge2dim()+b1.rad()*2, sbezpu);

                //Prüfen ob die Endpunkte der Strecken deckungsgleich sind:
                strecke sa,sb,sc,sd;
                double tol = 0.1;
                sa = s1;
                if(cagleich(sa.endp(), s2.startp(), tol))
                {
                    sb=s2;
                }else if(cagleich(sa.endp(), s2.endp(), tol))
                {
                    sb=s2;
                    sb.richtung_unkehren();
                }else if(cagleich(sa.endp(), s3.startp(), tol))
                {
                    sb=s3;
                }else if(cagleich(sa.endp(), s3.endp(), tol))
                {
                    sb=s3;
                    sb.richtung_unkehren();
                }else if(cagleich(sa.endp(), s4.startp(), tol))
                {
                    sb=s4;
                }else if(cagleich(sa.endp(), s4.endp(), tol))
                {
                    sb=s4;
                    sb.richtung_unkehren();
                }else
                {
                    QMessageBox mb;
                    mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                    mb.exec();
                    return;
                }

                if(  (cagleich(sb.startp(), s2.startp(), tol)  && \
                      cagleich(sb.endp(), s2.endp(), tol))  ||  \
                     (cagleich(sb.startp(), s2.endp(), tol)  &&  \
                      cagleich(sb.endp(), s2.startp(), tol))      )
                {
                    //sa==s1
                    //sb==s2
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s3,s4
                    if(cagleich(sb.endp(), s3.startp(), tol))
                    {
                        sc=s3;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s3.endp(), tol))
                    {
                        sc=s3;
                    }else if(cagleich(sb.endp(), s4.startp(), tol))
                    {
                        sc=s4;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s4.endp(), tol))
                    {
                        sc=s4;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    if(  (cagleich(sc.startp(), s3.startp(), tol)  &&
                          cagleich(sc.endp(), s3.endp(), tol))  ||  \
                         (cagleich(sc.startp(), s3.endp(), tol)  &&  \
                          cagleich(sc.endp(), s3.startp(), tol))      )
                    {
                        //sa==s1
                        //sb==s2
                        //sc==s3
                        //sd==...
                        //nicht zugewiesen: s4
                        sd=s4;
                    }else if(  (cagleich(sc.startp(), s4.startp(), tol)  &&
                                cagleich(sc.endp(), s4.endp(), tol))  ||  \
                               (cagleich(sc.startp(), s4.endp(), tol)  &&  \
                                cagleich(sc.endp(), s4.startp(), tol))      )
                          {
                        //sa==s1
                        //sb==s2
                        //sc==s4
                        //sd==...
                        //nicht zugewiesen: s3
                        sd=s3;
                    }

                    if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                       cagleich(sd.endp(), sc.startp(), tol))
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                           cagleich(sd.endp(), sc.startp(), tol))
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }else if(  (cagleich(sb.startp(), s3.startp(), tol)  && \
                            cagleich(sb.endp(), s3.endp(), tol))  ||  \
                           (cagleich(sb.startp(), s3.endp(), tol)  &&  \
                            cagleich(sb.endp(), s3.startp(), tol))      )
                      {
                    //sa==s1
                    //sb==s3
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s2,s4
                    if(cagleich(sb.endp(), s2.startp(), tol))
                    {
                        sc=s2;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s2.endp(), tol))
                    {
                        sc=s2;
                    }else if(cagleich(sb.endp(), s4.startp(), tol))
                    {
                        sc=s4;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s4.endp(), tol))
                    {
                        sc=s4;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    if(  (cagleich(sc.startp(), s2.startp(), tol)  &&  \
                          cagleich(sc.endp(), s2.endp(), tol))  ||  \
                         (cagleich(sc.startp(), s2.endp(), tol)  &&  \
                          cagleich(sc.endp(), s2.startp(), tol))      )
                    {
                        //sa==s1
                        //sb==s3
                        //sc==s2
                        //sd==...
                        //nicht zugewiesen: s4
                        sd=s4;
                    }else if(  (cagleich(sc.startp(), s4.startp(), tol)  &&  \
                                cagleich(sc.endp(), s4.endp(), tol))  ||  \
                               (cagleich(sc.startp(), s4.endp(), tol)  &&  \
                                cagleich(sc.endp(), s4.startp(), tol))      )
                    {
                        //sa==s1
                        //sb==s3
                        //sc==s4
                        //sd==...
                        //nicht zugewiesen: s2
                        sd=s2;
                    }

                    if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                       cagleich(sd.endp(), sc.startp(), tol))
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                           cagleich(sd.endp(), sc.startp(), tol))
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }else if(  (cagleich(sb.startp(), s4.startp(), tol)  && \
                            cagleich(sb.endp(), s4.endp(), tol))  ||  \
                           (cagleich(sb.startp(), s4.endp(), tol)  &&  \
                            cagleich(sb.endp(), s4.startp(), tol))      )
                      {
                    //sa==s1
                    //sb==s4
                    //sc==...
                    //sd==...
                    //nicht zugewiesen: s2,s3
                    if(cagleich(sb.endp(), s2.startp(), tol))
                    {
                        sc=s2;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s2.endp(), tol))
                    {
                        sc=s2;
                    }else if(cagleich(sb.endp(), s3.startp(), tol))
                    {
                        sc=s3;
                        sc.richtung_unkehren();
                    }else if(cagleich(sb.endp(), s3.endp(), tol))
                    {
                        sc=s3;
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                        mb.exec();
                        return;
                    }

                    cagleich(sc.endp(), s2.startp(), tol);

                    if(  (cagleich(sc.startp(), s2.startp(), tol)  &&  \
                          cagleich(sc.endp(), s2.endp(), tol))  ||  \
                         (cagleich(sc.startp(), s2.endp(), tol)  &&  \
                          cagleich(sc.endp(), s2.startp(), tol))      )
                    {
                        //sa==s1
                        //sb==s4
                        //sc==s2
                        //sd==...
                        //nicht zugewiesen: s3
                        sd=s3;
                    }else if(  (cagleich(sc.startp(), s3.startp(), tol)  &&  \
                                cagleich(sc.endp(), s3.endp(), tol))  ||  \
                               (cagleich(sc.startp(), s3.endp(), tol)  &&  \
                                cagleich(sc.endp(), s3.startp(), tol))      )
                    {
                        //sa==s1
                        //sb==s4
                        //sc==s3
                        //sd==...
                        //nicht zugewiesen: s2
                        sd=s2;
                    }

                    if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                       cagleich(sd.endp(), sc.startp(), tol))
                    {
                        ;
                        //richtig zugewiesen
                    }else
                    {
                        sd.richtung_unkehren();
                        if(cagleich(sd.startp(), sa.startp(), tol)  &&  \
                           cagleich(sd.endp(), sc.startp(), tol))
                        {
                            ;
                            //richtig zugewiesen
                        }else
                        {
                            QMessageBox mb;
                            mb.setText("Die Endpunkte der verlaengerten Strecken sind nicht kongruent!");
                            mb.exec();
                            return;
                        }
                    }
                }

                //sa,sb,sc und sd konnten korrekt zugewiesen werden
                //Prüfen ob 4eck einen rechten winkel hat:
                double wi = winkel(sd.endp().x(), sd.endp().y(), \
                                   sd.startp().x(), sd.startp().y(),
                                   sa.endp().x(), sa.endp().y());
                if(wi > 89.9  &&  wi < 90.1)
                {
                    //die strecken sa,sb,sc und sd beschreiben ein rechteck :-)
                    //Rechteck in rta umwandeln:
                    strecke diag;//Diagonale
                    diag.set_start(sa.startp());
                    diag.set_ende(sb.endp());

                    QString msg = vorlage_Rtasche;
                    QString alt;
                    alt  = BEZUGSPUNKT;
                    alt += text_mitte(vorlage_Rtasche, BEZUGSPUNKT, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    QString bezpu = BEZUGSPUNKT_MITTE;
                    msg.replace(alt, BEZUGSPUNKT + bezpu + ENDE_EINTRAG);

                    alt  = POSITION_X;
                    alt += text_mitte(vorlage_Rtasche, POSITION_X, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, POSITION_X + diag.get_mittelpunkt2d().x_QString() + ENDE_EINTRAG);

                    alt  = POSITION_Y;
                    alt += text_mitte(vorlage_Rtasche, POSITION_Y, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, POSITION_Y + diag.get_mittelpunkt2d().y_QString() + ENDE_EINTRAG);

                    alt  = TASCHENLAENGE;
                    alt += text_mitte(vorlage_Rtasche, TASCHENLAENGE, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, TASCHENLAENGE + sa.laenge2dim_QString() + ENDE_EINTRAG);

                    alt  = TASCHENBREITE;
                    alt += text_mitte(vorlage_Rtasche, TASCHENBREITE, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, TASCHENBREITE + sb.laenge2dim_QString() + ENDE_EINTRAG);

                    alt  = RADIUS;
                    alt += text_mitte(vorlage_Rtasche, RADIUS, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    QString r = b1.rad_qString();
                    msg.replace(alt, RADIUS + r + ENDE_EINTRAG);

                    double drewi = winkel(sa.endp().x(), sa.endp().y(), \
                                          sa.startp().x(), sa.startp().y());

                    alt  = WINKEL;
                    alt += text_mitte(vorlage_Rtasche, WINKEL, ENDE_EINTRAG);
                    alt += ENDE_EINTRAG;
                    msg.replace(alt, WINKEL + double_to_qstring(drewi) + ENDE_EINTRAG);

                    disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                    connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
                    emit sendDialogData(msg, true, werkzeugnamen);

                   tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge-1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);

                }else
                {
                    QMessageBox mb;
                    mb.setText("Die 4 Geraden sind nicht rechtwinklig zu einander!");
                    mb.exec();
                    return;
                }
            }else
            {
                QMessageBox mb;
                mb.setText("Die Radien der 4 Boegen sind nicht gleich!");
                mb.exec();
                return;
            }

        }else if(items_menge==6)//evtl 4eck mit Radius (2 Linien + 4 Viertelkreisbögen)
        {
            text_zeilenweise tzstrecken, tzboegen;
            uint anz_s=0;
            uint anz_b=0;
            for(uint i=1; i<=auswahl.zeilenanzahl() ;i++)
            {
                if(auswahl.zeile(i).contains(STRECKE))
                {
                    tzstrecken.zeile_anhaengen(auswahl.zeile(i));
                    anz_s++;
                }else if(auswahl.zeile(i).contains(BOGEN))
                {
                    tzboegen.zeile_anhaengen(auswahl.zeile(i));
                    anz_b++;
                }
            }
            if(anz_s!=2  ||  anz_b!=4)
            {
                QMessageBox mb;
                mb.setText("Die 6 aktivierten Zellen enthalten nicht 4 Strecken und 2 Boegen!");
                mb.exec();
                return;
            }
            bogen b1(tzboegen.zeile(1));
            bogen b2(tzboegen.zeile(2));
            bogen b3(tzboegen.zeile(3));
            bogen b4(tzboegen.zeile(4));

            if(cagleich(b1.rad(), b2.rad(), 0.1)  && \
               cagleich(b1.rad(), b3.rad(), 0.1)  && \
               cagleich(b1.rad(), b4.rad(), 0.1)     )
            {
                strecke sa(tzstrecken.zeile(1));
                strecke sc(tzstrecken.zeile(2));
                strecke_bezugspunkt sbezpu = strecke_bezugspunkt_mitte;
                sa.set_laenge_2d(sa.laenge2dim()+b1.rad()*2, sbezpu);
                sc.set_laenge_2d(sc.laenge2dim()+b1.rad()*2, sbezpu);

                if(!cagleich(sa.laenge2dim(), sc.laenge2dim(),0.1))
                {
                    QMessageBox mb;
                    mb.setText("Die Laengen der beiden Strecken sind nicht gleich!");
                    mb.exec();
                    return;
                }

                //Prüfen ob sa und sc parallel sind:
                strecke sb, sd;
                sb.set_start(sa.endp());
                sb.set_ende(sc.endp());
                sd.set_start(sa.startp());
                sd.set_ende(sc.startp());
                if(!cagleich(sb.laenge2dim(), sd.laenge2dim(),0.1))
                {
                    QMessageBox mb;
                    mb.setText("Die beiden Strecken sind nicht parallel!");
                    mb.exec();
                    return;
                }

                //Prüfen ob 4eck einen rechten winkel hat:
                double wi = winkel(sd.endp().x(), sd.endp().y(), \
                                   sd.startp().x(), sd.startp().y(),
                                   sa.endp().x(), sa.endp().y());
                if(wi > 89.9  &&  wi < 90.1)
                {
                    ;
                    //die strecken sa,sb,sc und sd beschreiben ein rechteck :-)
                }else
                {
                    //evtl. verlaufen sa und sc nicht in die selbe Richtung und
                    //der Winkel ist desshalb nicht 90°
                    sc.richtung_unkehren();
                    sb.set_start(sa.endp());
                    sb.set_ende(sc.endp());
                    sd.set_start(sa.startp());
                    sd.set_ende(sc.startp());

                    wi = winkel(sd.endp().x(), sd.endp().y(), \
                                sd.startp().x(), sd.startp().y(),
                                sa.endp().x(), sa.endp().y());
                    if(wi > 89.9  &&  wi < 90.1)
                    {
                        ;
                        //die strecken sa,sb,sc und sd beschreiben ein rechteck :-)
                    }else
                    {
                        QMessageBox mb;
                        mb.setText("Die 2 Geraden und 4 Boegen beschreiben kein rechtwinkliges 4eck!");
                        mb.exec();
                        return;
                    }
                }
                //die strecken sa,sb,sc und sd beschreiben ein rechteck :-)
                //Rechteck in rta umwandeln:
                strecke diag;//Diagonale
                diag.set_start(sa.startp());
                diag.set_ende(sb.endp());

                QString msg = vorlage_Rtasche;
                QString alt;
                alt  = BEZUGSPUNKT;
                alt += text_mitte(vorlage_Rtasche, BEZUGSPUNKT, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                QString bezpu = BEZUGSPUNKT_MITTE;
                msg.replace(alt, BEZUGSPUNKT + bezpu + ENDE_EINTRAG);

                alt  = POSITION_X;
                alt += text_mitte(vorlage_Rtasche, POSITION_X, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_X + diag.get_mittelpunkt2d().x_QString() + ENDE_EINTRAG);

                alt  = POSITION_Y;
                alt += text_mitte(vorlage_Rtasche, POSITION_Y, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, POSITION_Y + diag.get_mittelpunkt2d().y_QString() + ENDE_EINTRAG);

                alt  = TASCHENLAENGE;
                alt += text_mitte(vorlage_Rtasche, TASCHENLAENGE, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, TASCHENLAENGE + sa.laenge2dim_QString() + ENDE_EINTRAG);

                alt  = TASCHENBREITE;
                alt += text_mitte(vorlage_Rtasche, TASCHENBREITE, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, TASCHENBREITE + sb.laenge2dim_QString() + ENDE_EINTRAG);

                alt  = RADIUS;
                alt += text_mitte(vorlage_Rtasche, RADIUS, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                QString r = b1.rad_qString();
                msg.replace(alt, RADIUS + r + ENDE_EINTRAG);

                double drewi = winkel(sa.endp().x(), sa.endp().y(), \
                                      sa.startp().x(), sa.startp().y());

                alt  = WINKEL;
                alt += text_mitte(vorlage_Rtasche, WINKEL, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                msg.replace(alt, WINKEL + double_to_qstring(drewi) + ENDE_EINTRAG);

                disconnect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), 0, 0);
                connect(this, SIGNAL(sendDialogData(QString, bool, QStringList)), &rtasche, SLOT(getDialogData(QString, bool, QStringList)));
                emit sendDialogData(msg, true, werkzeugnamen);

               tt.get_prgtext()->zeilen_loeschen(row_erstes+1, items_menge-1);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
            }else
            {
                QMessageBox mb;
                mb.setText("Die Radien der 4 Boegen sind nicht gleich!");
                mb.exec();
                return;
            }

        }else
        {
            QMessageBox mb;
            mb.setText("Das Programm kann die aktivierten Zellen leider nicht umwandeln!");
            mb.exec();
        }
    }
}

void MainWindow::on_actionRechtecktasche_in_4_Eck_umwandeln_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
        int items_menge = items.count();

        if(items_menge==1)
        {
            //text aus der aktiven Zeile in string speichern:
            QString programmzeile;
            if(ui->listWidget_Programmliste->currentIndex().isValid()  &&  \
                    (ui->listWidget_Programmliste->currentItem()->isSelected()))
            {
                programmzeile =tt.get_prgtext()->zeile(ui->listWidget_Programmliste->currentRow()+1);
            } else
            {
                QMessageBox mb;
                mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
                mb.exec();
                return;
            }
            //Inhalt der Programmzeile prüfen:
            if(programmzeile.contains(RECHTECKTASCHE_DIALOG))
            {
                uint zeilennummer = ui->listWidget_Programmliste->currentRow()+1;
               tt.get_prgtext()->rta_zu_cad(zeilennummer);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(zeilennummer-1);
                vorschauAktualisieren();
            }else
            {
                QMessageBox mb;
                mb.setText("Die aktive Zeile enthaellt keine Rechtecktasche!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Bitte nur eine Zeile zum Umwandeln aktivieren!");
            mb.exec();
        }
    }
}
//---------------------------------------------------Manipulation:
void MainWindow::on_actionCAD_sortieren_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge > 1)
            {
               tt.get_prgtext()->cad_sortieren(row_erstes+1, row_erstes+items_menge, 3);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                vorschauAktualisieren();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was sortiert werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionFraesrichtung_umkehren_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge == 1)
            {
                uint ibeg = 0;
                uint iend = 0;
                bool gefunden = false;
                for(int i = row_erstes; i>=0 ; i--)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        ibeg = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                gefunden = false;
                for(uint i = row_erstes; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ; i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        iend = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                //Sicherheitsabfrage: Genau 1x Faufr und 1x Fabfah in der Auswahl?
                //Oder anders ausgedrückt: Wurde ein Teil eine Fräskontur aktiviert oder z.B. ein Kommentar
                uint anzaufr = 0;
                uint anzabfa = 0;
                for(uint i=ibeg; i<=iend ;i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        anzaufr++;
                    }else if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        anzabfa++;
                    }
                }
                if(anzaufr!=1 || anzabfa!=1)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                }else
                {
                   tt.get_prgtext()->fkon_richtung_wechseln(ibeg+1, iend+1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                    vorschauAktualisieren();
                }
            }
            if(items_menge > 1)
            {
                QMessageBox mb;
                mb.setText("Bitte nur eine Zeile der Fraeskontur markieren!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionFraesStartpunkt_vor_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge == 1)
            {
                uint ibeg = 0;
                uint iend = 0;
                bool gefunden = false;
                for(int i = row_erstes; i>=0 ; i--)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        ibeg = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                gefunden = false;
                for(uint i = row_erstes; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ; i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        iend = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                //Sicherheitsabfrage: Genau 1x Faufr und 1x Fabfah in der Auswahl?
                //Oder anders ausgedrückt: Wurde ein Teil eine Fräskontur aktiviert oder z.B. ein Kommentar
                uint anzaufr = 0;
                uint anzabfa = 0;
                for(uint i=ibeg; i<=iend ;i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        anzaufr++;
                    }else if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        anzabfa++;
                    }
                }
                if(anzaufr!=1 || anzabfa!=1)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                }else
                {
                   tt.get_prgtext()->fkon_vor(ibeg+1, iend+1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                    vorschauAktualisieren();
                }
            }
            if(items_menge > 1)
            {
                QMessageBox mb;
                mb.setText("Bitte nur eine Zeile der Fraeskontur markieren!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionFraesStartpunkt_nach_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge == 1)
            {
                uint ibeg = 0;
                uint iend = 0;
                bool gefunden = false;
                for(int i = row_erstes; i>=0 ; i--)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        ibeg = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                gefunden = false;
                for(uint i = row_erstes; i<tt.get_prgtext()->get_text_zeilenweise().zeilenanzahl() ; i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        iend = i;
                        gefunden = true;
                        break;
                    }
                }
                if(gefunden == false)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                    QApplication::restoreOverrideCursor();
                    return;
                }
                //Sicherheitsabfrage: Genau 1x Faufr und 1x Fabfah in der Auswahl?
                //Oder anders ausgedrückt: Wurde ein Teil eine Fräskontur aktiviert oder z.B. ein Kommentar
                uint anzaufr = 0;
                uint anzabfa = 0;
                for(uint i=ibeg; i<=iend ;i++)
                {
                    if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERAUFRUF_DIALOG))
                    {
                        anzaufr++;
                    }else if(tt.get_prgtext()->get_klartext_zeilenweise().zeile(i+1).contains(FRAESERABFAHREN_DIALOG))
                    {
                        anzabfa++;
                    }
                }
                if(anzaufr!=1 || anzabfa!=1)
                {
                    QMessageBox mb;
                    mb.setText("Auswahl ungueltig!\nBitte eine Zeile innerhalb einer Fraeskontur aktivieren.");
                    mb.exec();
                }else
                {
                   tt.get_prgtext()->fkon_nach(ibeg+1, iend+1);
                    aktualisiere_anzeigetext();
                    ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                    vorschauAktualisieren();
                }
            }
            if(items_menge > 1)
            {
                QMessageBox mb;
                mb.setText("Bitte nur eine Zeile der Fraeskontur markieren!");
                mb.exec();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionVerastzvariablen_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge >= 1)
            {
               tt.get_prgtext()->versatzvar(row_erstes+1, row_erstes+items_menge);
                aktualisiere_anzeigetext();
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                vorschauAktualisieren();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionSpiegeln_vertikel_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge >= 1)
            {
               tt.get_prgtext()->spiegeln_verti(row_erstes+1, row_erstes+items_menge);
                aktualisiere_anzeigetext();
                //Heraus bekommen wie viele Fräseraufrufe betroffen sind:
                text_zeilenweise faufruf_zeinum;
                for(int i=row_erstes; i<row_erstes+items_menge ;i++)
                {
                    QString zeile =tt.get_prgtext()->get_text_zeilenweise().zeile(i+1);
                    if(zeile.contains(FRAESERAUFRUF_DIALOG))
                    {
                        faufruf_zeinum.zeile_anhaengen(int_to_qstring(i));
                    }
                }
                //Fräsrichtung umkehren:
                for(uint i=1; i<=faufruf_zeinum.zeilenanzahl() ;i++)
                {
                    ui->listWidget_Programmliste->setCurrentRow(faufruf_zeinum.zeile(i).toInt());
                    on_actionFraesrichtung_umkehren_triggered();
                }
                //Vorherige Auswahl wieder herstellen:
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                for(int i=row_erstes; i<row_erstes+items_menge ;i++)
                {
                    ui->listWidget_Programmliste->item(i)->setSelected(true);
                }
                vorschauAktualisieren();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_actionSpiegeln_horizontal_triggered()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        if((ui->listWidget_Programmliste->currentIndex().isValid())  &&  \
                (ui->listWidget_Programmliste->currentItem()->isSelected()))
        {
            QList<QListWidgetItem*> items = ui->listWidget_Programmliste->selectedItems();
            int items_menge = items.count();
            int row_erstes = 0;//Nummer des ersten Elementes
            for(int i=0; i<ui->listWidget_Programmliste->count() ;i++)
            {
                if(ui->listWidget_Programmliste->item(i)->isSelected())
                {
                    row_erstes = i;
                    break;
                }
            }
            if(tt.get_prgtext()->get_text_zeilenweise().zeile(row_erstes+items_menge) == LISTENENDE)
            {
                items_menge = items_menge-1;
            }
            if(items_menge >= 1)
            {
               tt.get_prgtext()->spiegeln_hori(row_erstes+1, row_erstes+items_menge);
                aktualisiere_anzeigetext();
                //Heraus bekommen wie viele Fräseraufrufe betroffen sind:
                text_zeilenweise faufruf_zeinum;
                for(int i=row_erstes; i<row_erstes+items_menge ;i++)
                {
                    QString zeile =tt.get_prgtext()->get_text_zeilenweise().zeile(i+1);
                    if(zeile.contains(FRAESERAUFRUF_DIALOG))
                    {
                        faufruf_zeinum.zeile_anhaengen(int_to_qstring(i));
                    }
                }
                //Fräsrichtung umkehren:
                for(uint i=1; i<=faufruf_zeinum.zeilenanzahl() ;i++)
                {
                    ui->listWidget_Programmliste->setCurrentRow(faufruf_zeinum.zeile(i).toInt());
                    on_actionFraesrichtung_umkehren_triggered();
                }
                //Vorherige Auswahl wieder herstellen:
                ui->listWidget_Programmliste->setCurrentRow(row_erstes);
                for(int i=row_erstes; i<row_erstes+items_menge ;i++)
                {
                    ui->listWidget_Programmliste->item(i)->setSelected(true);
                }
                vorschauAktualisieren();
            }
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben noch nichts ausgewaelt was umgewandelt werden kann!");
            mb.exec();
        }
    }
    QApplication::restoreOverrideCursor();
}
//---------------------------------------------------nicht zugeordnet
int MainWindow::loadToolInteger(QString keyword, int index)
{
    int returnInt = 0;
    QString text = tool_tbl.at(index);
    if(text.contains(keyword))
    {
        int indexBegin = text.indexOf(keyword);
        QString tmp = text.mid(indexBegin+1 , 10);
        QString tmp2;
        for(int i=0; i<10 ;i++)
        {
            if( tmp[i] == '0' || tmp[i] == '1' || tmp[i] == '2' || tmp[i] == '3' || tmp[i] == '4' || tmp[i] == '5' || tmp[i] == '6' || tmp[i] == '7' || tmp[i] == '8' || tmp[i] == '9')
            {
                tmp2 += tmp[i];
            }else break; //tmp2 beinhaltet jetzt die Zahl als QString
        }
        returnInt = tmp2.toInt();//Umwandlung von QString in int
    }
    return returnInt;
}

int MainWindow::aktualisiere_anzeigetext(bool undo_redo_on)
{
    int row;
    if(ui->listWidget_Programmliste->currentIndex().isValid())
    {
        row = ui->listWidget_Programmliste->currentRow();
    }else
    {
        row = 0;
    }
    ui->listWidget_Programmliste->clear();
    text_zeilenweise tmp;
    tmp =tt.get_prgtext()->get_anzeigetext_zeilenweise();
    if(tmp.zeilenanzahl() == 0)
    {
        return -1;
    }
    for(uint i=1 ; i<=tmp.zeilenanzahl() ; i++)
    {
        ui->listWidget_Programmliste->addItem(tmp.zeile(i));
    }
    for(int row = 0; row < ui->listWidget_Programmliste->count(); row++)
    {
        QListWidgetItem *item = ui->listWidget_Programmliste->item(row);
        if(elementIstEingeblendet(item))
        {
            elementEinblendenSichtbarMachen(item);
        }else
        {
            elementAusblendenSichtbarMachen(item);
        }
    }
    if(row >= (int)tmp.zeilenanzahl())
    {
        row = row-1;
    }
    ui->listWidget_Programmliste->setCurrentRow(row);

    if(undo_redo_on == true)
    {
        tt.get_prg_undo_redo()->neu(*tt.get_prgtext());
    }
    return row;
}

int MainWindow::aktualisiere_anzeigetext_wkz(bool undo_redo_on)
{
    int row;
    if(ui->listWidget_Werkzeug->currentIndex().isValid())
    {
        row = ui->listWidget_Werkzeug->currentRow();
    }else
    {
        row = 0;
    }
    ui->listWidget_Werkzeug->clear();
    text_zeilenweise tmp;
    tmp = w.get_anzeigetext_zeilenweise();
    if(tmp.zeilenanzahl() == 0)
    {
        return -1;
    }
    for(uint i=1 ; i<=tmp.zeilenanzahl() ; i++)
    {
        ui->listWidget_Werkzeug->addItem(tmp.zeile(i));
    }
    if(row >= (int)tmp.zeilenanzahl())
    {
        row = row-1;
    }
    ui->listWidget_Werkzeug->item(row)->setSelected(true);
    ui->listWidget_Werkzeug->setCurrentRow(row);
    if(undo_redo_on == true)
    {
        ur_wkz.neu(w);
    }
    return row;
}

void MainWindow::on_actionProgrammliste_anzeigen_triggered()
{
    QString tmp_text;
    tmp_text = "";
    text_zeilenweise te =tt.get_prgtext()->get_text_zeilenweise();
    for(uint i=1 ; i<=te.zeilenanzahl() ; i++)
    {
        tmp_text += QString::fromStdString(int_to_string(i));
        tmp_text += "--";
        tmp_text += te.zeile(i);
        tmp_text += "\n";
    }

    QString tmp_klartext;
    tmp_klartext = "";
    text_zeilenweise kl =tt.get_prgtext()->get_klartext_zeilenweise();
    for(uint i=1 ; i<=kl.zeilenanzahl() ; i++)
    {
        tmp_klartext += QString::fromStdString(int_to_string(i));
        tmp_klartext += "--";
        tmp_klartext += kl.zeile(i);
        tmp_klartext += "\n";
    }

    QString tmp_var;
    tmp_var += "";
    text_zeilenweise v =tt.get_prgtext()->get_variablen_zeilenweise();
    for(uint i=1 ; i<=v.zeilenanzahl() ; i++)
    {
        tmp_var += QString::fromStdString(int_to_string(i));
        tmp_var += "--";
        tmp_var += v.zeile(i);
        tmp_var += "\n";
    }

    QString tmp_geom;
    tmp_geom = "";
    text_zeilenweise g =tt.get_prgtext()->get_geo().get_text_zeilenweise();
    for(uint i=1 ; i<=g.zeilenanzahl() ; i++)
    {
        tmp_geom += QString::fromStdString(int_to_string(i));
        tmp_geom += "--";
        tmp_geom += g.zeile(i);
        tmp_geom += "\n";
    }

    QString tmp_fkon;
    tmp_fkon = "";
    text_zeilenweise fk =tt.get_prgtext()->get_fkon().get_text_zeilenweise();
    for(uint i=1 ; i<=fk.zeilenanzahl() ; i++)
    {
        tmp_fkon += QString::fromStdString(int_to_string(i));
        tmp_fkon += "--";
        tmp_fkon += fk.zeile(i);
        tmp_fkon += "\n";
    }

    connect( this, \
             SIGNAL(send_an_programmlisten(QString,QString,QString,QString,QString)),\
             &programmlisten,\
             SLOT(daten_anzeigen(QString,QString,QString,QString,QString)));
    emit send_an_programmlisten(tmp_text,\
                                tmp_klartext,\
                                tmp_var,\
                                tmp_geom,\
                                tmp_fkon);
}

void MainWindow::on_actionWerkzeugliste_anzeigen_triggered()
{
    QString tmp_liste;
    tmp_liste = "\n---------------------------Komplette Liste:\n";
    text_zeilenweise te = w.get_werkzeuge_zeilenweise();
    for(uint i=1 ; i<=te.zeilenanzahl() ; i++)
    {
        tmp_liste += QString::fromStdString(int_to_string(i));
        tmp_liste += "--";
        tmp_liste += te.zeile(i);
        tmp_liste += "\n";
    }

    QString tmp_namen;
    tmp_namen = "\n---------------------------Werkzeugnamen:\n";
    text_zeilenweise na = w.get_anzeigetext_zeilenweise();
    for(uint i=1 ; i<=na.zeilenanzahl() ; i++)
    {
        tmp_namen += QString::fromStdString(int_to_string(i));
        tmp_namen += "--";
        tmp_namen += na.zeile(i);
        tmp_namen += "\n";
    }

    QMessageBox mb;
    mb.setText(tmp_liste + tmp_namen);
    mb.exec();
}

void MainWindow::pruefe_benutzereingaben(int zeilennummer)
{
    QMessageBox mb;
    text_zeilenweise tz_prg =tt.get_prgtext()->get_text_zeilenweise();
    QString programmzeile = tz_prg.zeile(zeilennummer);
    text_zeilenweise tz_kt =tt.get_prgtext()->get_klartext_zeilenweise();
    QString klartextzeile = tz_kt.zeile(zeilennummer);
    if(programmzeile.contains(RECHTECKTASCHE_DIALOG))
    {
        QString tmp = text_mitte(programmzeile, WKZ_NAME, ENDE_EINTRAG);
        QString wkz = w.get_werkzeug(tmp);
        tmp = text_mitte(wkz, WKZ_DURCHMESSER, ENDE_EINTRAG);
        float wkz_dm = tmp.toFloat();
        tmp = text_mitte(klartextzeile, TASCHENLAENGE, ENDE_EINTRAG);
        float tal = tmp.toFloat();
        if(tal<wkz_dm)
        {
            mb.setText("Achtung!\nTaschenlaenge ist kleiner als Fraeserdurchmesser");
            mb.exec();
        }
        tmp = text_mitte(klartextzeile, TASCHENBREITE, ENDE_EINTRAG);
        float tab = tmp.toFloat();
        if(tab<wkz_dm)
        {
            mb.setText("Achtung!\nTaschenbreite ist kleiner als Fraeserdurchmesser");
            mb.exec();
        }
        tmp = text_mitte(klartextzeile, TASCHENTIEFE, ENDE_EINTRAG);
        float tati = tmp.toFloat();
        tmp = text_mitte(wkz, WKZ_NUTZLAENGE, ENDE_EINTRAG);
        float wkz_nutzl = tmp.toFloat();
        if(tati>wkz_nutzl)
        {
            mb.setText("Achtung!\nTaschentiefe ist groesser als Nutzlaenge des Fraesers");
            mb.exec();
        }
        tmp = text_mitte(klartextzeile, RADIUS, ENDE_EINTRAG);
        float eckrad = tmp.toFloat();
        float mindim;
        if(tab < tal)
        {
            mindim = tab;
        }else
        {
            mindim = tal;
        }
        if(eckrad*2 > mindim)
        {
            mb.setText("Achtung!\nEckradien der Tasche ist groesser als Laenge oder Breite der Tasche!");
            mb.exec();
        }

    }else if(programmzeile.contains(KREISTASCHE_DIALOG))
    {
        QString tmp = text_mitte(programmzeile, WKZ_NAME, ENDE_EINTRAG);
        QString wkz = w.get_werkzeug(tmp);
        tmp = text_mitte(wkz, WKZ_DURCHMESSER, ENDE_EINTRAG);
        float wkz_dm = tmp.toFloat();
        tmp = text_mitte(klartextzeile, DURCHMESSER, ENDE_EINTRAG);
        float dm = tmp.toFloat();
        if(dm<wkz_dm)
        {
            mb.setText("Achtung!\nTaschendurchmesser ist kleiner als Fraeserdurchmesser");
            mb.exec();
        }
        tmp = text_mitte(klartextzeile, TASCHENTIEFE, ENDE_EINTRAG);
        float tati = tmp.toFloat();
        tmp = text_mitte(wkz, WKZ_NUTZLAENGE, ENDE_EINTRAG);
        float wkz_nutzl = tmp.toFloat();
        if(tati>wkz_nutzl)
        {
            mb.setText("Achtung!\nTaschentiefe ist groesser als Nutzlaenge des Fraesers");
            mb.exec();
        }
    }
}

QString MainWindow::klammern_wecklassen(QString text)
{
    QString tmp;
    for(int i = 0; i<text.length() ; i++)
    {
        if(  (text.at(i)!='(')  &&  (text.at(i)!=')')  )
        {
            tmp += text.at(i);
        }
    }
    return tmp;
}

void MainWindow::slotAnfrageVariablen()
{
    connect(this, SIGNAL(sendVariablen(text_zeilenweise)), &variablenwerte_anzeigen, SLOT(slot_bekomme_variablen(text_zeilenweise)));
    emit sendVariablen(tt.get_prgtext()->get_variablen_zeilenweise());
}

void MainWindow::slotAnfrageVariablenZeile(QString kennung)
{
    QString var;
    text_zeilenweise tz =tt.get_prgtext()->get_variablen_zeilenweise();
    var = tz.zeile(ui->listWidget_Programmliste->currentRow());

    disconnect(this, SIGNAL(sendVariablenZeile(QString)), 0, 0);

    if(kennung == STRECKE)
    {
        connect(this, SIGNAL(sendVariablenZeile(QString)), &dstrecke, SLOT(getVariablen(QString)));
        emit sendVariablenZeile(var);
    }else if(kennung == KREIS)
    {
        connect(this, SIGNAL(sendVariablenZeile(QString)), &dkreis, SLOT(getVariablen(QString)));
        emit sendVariablenZeile(var);
    }else if(kennung == BOGEN)
    {
        connect(this, SIGNAL(sendVariablenZeile(QString)), &dbogen, SLOT(getVariablen(QString)));
        emit sendVariablenZeile(var);
    }
}

void MainWindow::on_actionVariablenwert_anzeigen_triggered()
{
    variablenwerte_anzeigen.show();
}

void MainWindow::on_actionRueckgaengig_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        //t = ur.undo();
        *tt.get_prgtext() = tt.get_prg_undo_redo()->undo();
        aktualisiere_anzeigetext(false);
        vorschauAktualisieren();
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        w = ur_wkz.undo();
        aktualisiere_anzeigetext_wkz(false);
    }
}

void MainWindow::on_actionWiederholen_triggered()
{
    if(ui->tabWidget->currentIndex() == INDEX_PROGRAMMLISTE)
    {
        //t = ur.redo();
        *tt.get_prgtext() = tt.get_prg_undo_redo()->redo();
        aktualisiere_anzeigetext(false);
        vorschauAktualisieren();
    }else if(ui->tabWidget->currentIndex() == INDEX_WERKZEUGLISTE)
    {
        w = ur_wkz.redo();
        aktualisiere_anzeigetext_wkz(false);
    }
}

void MainWindow::on_actionInfo_triggered()
{
    QString msg;
    msg  = PROGRAMMNAME;
    msg += "\n";
    msg += "Autor: Oliver Schuft";
    msg += "\n";
    msg += "Repositorry: ";
    msg += "https://github.com/TischlerWilly/GCodeGenerator.git";

    QMessageBox mb;
    mb.setText(msg);
    mb.exec();
}

void MainWindow::slot_maus_pos(QPoint p)
{
    int x = p.x();
    int y = p.y();
    QString x_ = QString::fromStdString(int_to_string(x));
    QString y_ = QString::fromStdString(int_to_string(y));
    ui->statusBar->showMessage("X:" + x_ + " / Y:" + y_);
}

void MainWindow::update_gui()
{
    if(tt.dateien_sind_offen())
    {
        showElements_aFileIsOpen();
        aktualisiere_anzeigetext();
        vorschauAktualisieren();
    }else
    {
        hideElemets_noFileIsOpen();
        vorschaufenster.hide();
    }
    if(tt.get_size() > 1)
    {
        ui->actionNaechste_offen_Datei->setEnabled(true);
        ui->actionLetzte_offene_Datei->setEnabled(true);
    }else
    {
        ui->actionNaechste_offen_Datei->setDisabled(true);
        ui->actionLetzte_offene_Datei->setDisabled(true);
    }
    aktualisiere_offene_dateien_menu();
    update_windowtitle();
}

void MainWindow::update_windowtitle()
{
    if(tt.dateien_sind_offen())
    {
        QString name = tt.get_prgname();
        if(name == NICHT_DEFINIERT)
        {
            name = "Neue Datei";
        }else
        {
            QFileInfo info = name;
            name = info.baseName();
        }
        if(tt.get_prgtext()->get_hat_ungesicherte_inhalte() == true)
        {
            name += "*";
        }
        QString fenstertitel = PROGRAMMNAME;
        fenstertitel += " ( " + name + " )";
        this->setWindowTitle(fenstertitel);
    }else
    {
        QString titel = PROGRAMMNAME;
        titel += " ";
        titel += PROGRAMMVERSION;
        this->setWindowTitle(titel);
    }
}

//---------------------------------------------------

void MainWindow::on_actionTestfunktion_triggered()
{
    QMessageBox mb;
    mb.setText("Die Testfunktion ist derzeit nicht in Verwendung.");
    mb.exec();
}








