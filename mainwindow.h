#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QColor>
#include <QBrush>
#include <QListWidgetItem>
#include <QRect>
#include "Dialoge/dialog_settings.h"
#include "Dialoge/dialog_programmkopf.h"
#include "Dialoge/dialog_programmende.h"
#include "Dialoge/dialog_kommentar.h"
#include "Dialoge/dialog_variable.h"
#include "Dialoge/dialog_kreistasche.h"
#include "Dialoge/dialog_rechtecktasche.h"
#include "Dialoge/dialog_werkzeug.h"
#include "myDefines.h"
#include "eigeneKlassen/wenndannsonst.h"
#include "eigeneKlassen/rechtecktasche.h"
#include "eigeneKlassen/vorschau.h"
#include "eigeneKlassen/programmtext.h"
#include "eigeneKlassen/text_zeilenweise.h"
#include "eigeneKlassen/werkzeug.h"
#include "Dialoge/dialog_variablenwerte_anzeigen.h"
#include "eigeneKlassen/undo_redo.h"
#include "eigeneKlassen/undo_redo_wkz.h"
#include "Dialoge/dialog_fraeser_aufruf.h"
#include "Dialoge/dialog_fraeser_gerade.h"
#include "Dialoge/dialog_fraeser_bogen.h"
#include "Dialoge/dialog_fraeser_abfahren.h"
#include "Dialoge/dialog_programmlisten.h"
#include "Dialoge/dialog_import_ggf.h"
#include "eigeneKlassen/letzte_dateien.h"
#include "Dialoge/dialog_kreis.h"
#include "Dialoge/dialog_strecke.h"
#include "Dialoge/dialog_bogen.h"
#include "Dialoge/dialog_bohren.h"
#include "ToDo.h"


#define INDEX_PROGRAMMLISTE 0
#define INDEX_WERKZEUGLISTE 2

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionEinstellungen_triggered();
    void on_actionWerkzeugliste_triggered();
    void on_actionMakeProgrammkopf_triggered();
    void on_actionEntfernen_triggered();
    void on_actionKopieren_triggered();
    void on_actionEinfuegen_triggered();
    void on_actionAusschneiden_triggered();
    void on_actionAendern_triggered();
    void on_actionMakeKommentar_triggered();
    void on_actionMakeProgrammende_triggered();
    void on_listWidget_Programmliste_doubleClicked(const QModelIndex &index);
    void on_actionDateiNeu_triggered();
    void on_actionDateiSchliessen_triggered();
    void on_actionDateiSpeichern_triggered();
    void on_actionDateiOefnen_triggered();
    void actionLetzteDateiOefnenTriggered();
    void on_actionDateiSpeichern_unter_triggered();
    void on_actionEin_Ausblenden_triggered();
    void resizeEvent(QResizeEvent *event);
    void on_actionMakeVariable_triggered();
    void on_actionMakeKreistasche_triggered();
    void on_pushButton_WKZ_Neu_clicked();
    void on_listWidget_Werkzeug_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_WKZ_Speichern_clicked();
    void on_pushButton_WKZ_Laden_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_WKZ_Export_an_EMC2_clicked();
    void on_actionMakeRechtecktasche_triggered();
    void on_actionGCode_berechnen_triggered();
    void on_actionProgrammliste_anzeigen_triggered();
    void on_actionWerkzeugliste_anzeigen_triggered();
    void on_actionVariablenwert_anzeigen_triggered();
    void on_pushButton_Aktualisieren_GCode_clicked();
    void on_actionGCode_exportieren_triggered();
    void on_pushButton_Exportieren_GCODE_clicked();
    void on_listWidget_Programmliste_currentRowChanged(int currentRow);
    void on_actionAuswahl_Ausblenden_triggered();
    void on_actionAuswahl_Einblenden_triggered();
    void on_actionRueckgaengig_triggered();
    void on_actionWiederholen_triggered();
    void on_actionMakeFraeser_Aufruf_triggered();
    void on_actionMakeGerade_Fraesbahn_triggered();
    void on_actionMakeGebogene_Fraesbahn_triggered();
    void on_actionMakeAbfahren_triggered();
    void on_actionTestfunktion_triggered();
    void on_import_GGF_triggered();
    void on_import_DXF_triggered();
    void on_actionKreis_in_Kreistasche_umwandeln_triggered();
    void on_actionMakeKreis_triggered();
    void on_actionKreistasche_in_Kreis_umwandeln_triggered();
    void on_actionInfo_triggered();
    void on_actionMakeStrecke_triggered();
    void on_actionMakeBogen_triggered();
    void on_actionMaschine_speichern_triggered();
    void on_actionMaschinengeometrie_bearbeiten_triggered();
    void on_actionCAD_sortieren_triggered();
    void on_actionLinien_in_Fraeskonturen_umwandeln_triggered();
    void on_actionFraeskonturen_in_Linien_umwandeln_triggered();
    void on_actionFraesrichtung_umkehren_triggered();
    void on_actionFraesStartpunkt_vor_triggered();
    void on_actionFraesStartpunkt_nach_triggered();
    void on_action4_Eck_in_Rechtecktasche_umwandeln_triggered();
    void on_actionRechtecktasche_in_4_Eck_umwandeln_triggered();
    void on_actionVerastzvariablen_triggered();
    void on_actionMakeBohren_triggered();
    void on_actionSpiegeln_vertikel_triggered();
    void on_actionSpiegeln_horizontal_triggered();
    void on_actionKreis_in_Bohrung_umwandeln_triggered();
    void on_actionBohrung_in_Kreis_umwandeln_triggered();
    void on_actionKreistasche_in_Bohrung_umwandeln_triggered();
    void on_actionBohrung_in_Kreistasche_umwandeln_triggered();

public slots:
    void getDialogData(QString text);
    void getDialogDataModify(QString text);
    void slotSaveConfig(QString text);
    void slotAnfrageWerkzeugnamen(QString dialogName);
    void slotAnfrageWerkzeugdaten(QString Werkzeugname, QString Dialog);
    void slotAnfrageVariablen();
    void slotAnfrageVariablenZeile(QString kennung);
    void slot_maus_pos(QPoint p);
    void getImportGGF(QString text);


signals:
    //void sendDialogData(QString text);
    void sendDialogData(QString text, bool openToChangeData);
    void sendDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen);
    void sendDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen, werkzeug wkz);
    void sendWerkzeugNamen(QStringList namen);
    void sendWerkzeugdaten(QString Werkzeugdaten);
    void sendVorschauAktualisieren(QString neuer_programmtext, int aktuelle_programmzeile);
    void sendVorschauAktualisieren(programmtext t_neu, int aktuelle_programmzeile);
    void sendVariablen(text_zeilenweise variablen);
    void sendVariablenZeile(QString var);
    void sendAktiveProgrammzeile(int zeilennummer);
    void send_an_programmlisten(QString prgtext, QString klartext, \
                        QString variabel, QString geotext, QString fkon);
    void sendTextToImportGGF(QString text);

private:
        //Objekte:
    Ui::MainWindow *ui;
    dialog_settings dsettings;
    Dialog_Programmkopf pkopf;
    Dialog_Programmende pende;
    Dialog_Kommentar kommentar;
    Dialog_Variable variable;
    Dialog_variablenwerte_anzeigen variablenwerte_anzeigen;
    Dialog_Kreistasche ktasche;
    Dialog_Kreis dkreis;
    Dialog_strecke dstrecke;
    Dialog_Bogen dbogen;
    Dialog_Rechtecktasche rtasche;
    Dialog_import_ggf import_ggf;
    Dialog_bohren dbohren;
    vorschau vorschaufenster;
    undo_redo ur;
    undo_redo_wkz ur_wkz;
    bool hat_ungesicherte_inhalte;
    Dialog_Werkzeug werkzeug_dialog;
    Dialog_Fraeser_Aufruf faufruf;
    Dialog_fraeser_gerade fgerade;
    Dialog_fraeser_bogen fbogen;
    Dialog_fraeser_abfahren fabfa;
    Dialog_Programmlisten programmlisten;



        //Variablen:
    QStringList     konfiguration_ini;
    bool            konfiguration_ini_ist_vorhanden;
    QStringList     tool_tbl;
    QString         tooltable_path;//Pfad zur Werkteugtabelle von EMC2
    QString         kopierterEintrag_t;
    QString         kopiertesWerkzeug;
    QString         vorlage_pkopf;
    QString         vorlage_pende;
    QString         vorlage_kommentar;
    QString         vorlage_variable;
    QString         vorlage_Ktasche;
    QString         vorlage_Rtasche;
    QString         vorlage_Faufruf;
    QString         vorlage_Fgerade;
    QString         vorlage_Fbogen;
    QString         vorlage_Fabfa;
    QString         vorlage_werkzeug;
    QString         vorlage_dbohren;
    bool            DateiIstOffen;
    QString         nameOfTheOpenFile;
    QString         nameOfTheOpenFile_backup;
    QStringList     werkzeugnamen;
    QStringList     wkznamen_nur_bohrer;
    QStringList     wkznamen_nur_fraeser;
    programmtext    t;
    werkzeug        w;
    QString         settings_anz_undo_t;
    QString         settings_anz_undo_w;
    QString         aktives_wkz;
    letzte_dateien  letzte_geoefnete_dateien;
    QAction *oefneLetzteDateien[ANZAHL_LETZTER_DATEIEN];
    QString         dxf_klasse_wstnp;
    QString         dxf_klasse_geo;
    QString         dxf_klasse_geo_beachten;
    QString         fkon_berechnen;
    QString         pfad_import_dxf;
    QString         pfad_import_ggf;
    QString         pfad_oefne_ggf;

        //Eigene Datentypen:


        //Funktionen:
    QString loadConfig();
    QString saveConfig();
    void loadConfig_letzte_Dateien();
    QString loadToollistInQStringlist(QString filename);
    int loadToolInteger(QString keyword, int index);
    void hideElemets_noFileIsOpen();
    void showElements_aFileIsOpen();
    void closeEvent(QCloseEvent *ce);
    bool elementIstEingeblendet();
    bool elementIstEingeblendet(QString zeilentext);
    bool elementIstEingeblendet(QListWidgetItem *item);
    void elementEinblendenSichtbarMachen();
    void elementEinblendenSichtbarMachen(QListWidgetItem *item);
    void elementAusblendenSichtbarMachen();
    void elementAusblendenSichtbarMachen(QListWidgetItem *item);
    void elementEinblenden();
    void elementAusblenden();
    bool ladeWerkzeugnamen();
    QString werkzeugdaten(QString werkzeugname);
    int aktualisiere_anzeigetext(bool undo_redo_on = true);
    int aktualisiere_anzeigetext_wkz(bool undo_redo_on = true);
    void vorschauAktualisieren();
    void pruefe_benutzereingaben(int zeilennummer);
    bool hat_werkzeugliste_fehler();
    QString klammern_wecklassen(QString text);
    void aktuelisiere_letzte_dateien_inifile();
    void aktualisiere_letzte_dateien_menu();
    void openFile(QString pfad);
    QString dateitext_ggf();

};

#endif // MAINWINDOW_H
