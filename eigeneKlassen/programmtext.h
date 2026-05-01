#ifndef PROGRAMMTEXT_H
#define PROGRAMMTEXT_H

#include <QString>
#include <math.h>
#include "../myDefines.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "text_zeilenweise.h"
#include "text_zw.h"
#include "wenndannsonst.h"
#include "rechtecktasche.h"
#include "geometrietext.h"
#include "werkzeug.h"
#include "tabelle_tz3.h"
#include "../Dialoge/dialog_variable.h"


class programmtext
{
public:
    programmtext();
            void                set_text(QString neuer_Text);
            void                set_wkz(werkzeug wkz);
            void                set_maschinengeometrie(text_zeilenweise tz);
            void                clear();
    inline  void                warnungen_einschalten(bool einschalten)
    {
        Warnungen_sind_eingeschaltet = einschalten;
    }
    text_zw    text();
            QString             get_klartext();
    inline  text_zeilenweise    get_klartext_zeilenweise()
    {
        return Klartext;
    }
            QString             get_variablen();
    inline  text_zeilenweise    get_variablen_zeilenweise()
    {
        return Var;
    }
    inline  QString             get_anzeigetext()
    {
        return Anzeigetext.get_text();
    }
    inline  text_zeilenweise    get_anzeigetext_zeilenweise()
    {
        return Anzeigetext;
    }
    inline  QString             get_anzeigetext_zeile(uint zeilennummer)
    {
        return Anzeigetext.zeile(zeilennummer);
    }

    inline  geometrietext       get_geo()
    {
        return Geo;
    }
    inline  geometrietext       get_fkon()
    {
        return Fkon;
    }
    inline  geometrietext       get_maschinengeo()
    {
        return Maschinengeo;
    }
    inline  geometrietext       get_fraeserdarst()
    {
        return Fraeserdarst;
    }

    inline  float   wst_laenge()
    {
        return Wst_laenge;
    }
    inline  float   wst_breite()
    {
        return Wst_breite;
    }
    inline  float   wst_dicke()
    {
        return Wst_dicke;
    }
    inline  float   get_sicherheitsabstand()
    {
        return Sicherheitsabstand;
    }
    inline  float   get_min_x()
    {
        return Min_x;
    }
    inline  float   get_max_x()
    {
        return Max_x;
    }
    inline  float   get_min_y()
    {
        return Min_y;
    }
    inline  float   get_max_y()
    {
        return Max_y;
    }

    inline  float   get_ax()
    {
        return Versatz_x;
    }
    inline  float   get_ay()
    {
        return Versatz_y;
    }
    inline  float   get_az()
    {
        return Versatz_z;
    }
    inline  QString   get_ax_qstring()
    {
        return double_to_qstring(Versatz_x);
    }
    inline  QString   get_ay_qstring()
    {
        return double_to_qstring(Versatz_y);
    }
    inline  QString   get_az_qstring()
    {
        return double_to_qstring(Versatz_z);
    }

    QString     zeile(uint zeilennummer);
    QString     zeilen(uint zeilennummer_beginn, uint zeilenmenge);
    int         zeile_loeschen(uint zeilennummer);
    int         zeilen_loeschen(uint zeilennummer_beginn, uint zeilenmenge);
    int         zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, \
                                QString zeilentext);
    int         zeilen_einfuegen(uint zeilennummer_vor_neuer_zeile, \
                                 QString zeilentext);
    void        zeile_anhaengen(QString zeilentext);
    int         zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext);

    inline  void aktualisieren_ein_aus(bool einschalten)
    {
        if(einschalten)
        {
            Aktualisieren_eingeschaltet = true;
            aktualisieren();
        }else
        {
            Aktualisieren_eingeschaltet = false;
        }
    }

    inline  void aktualisieren_fkon_ein_aus(bool einschalten)
    {
        if(einschalten == true)
        {
            Aktualisieren_fkon_eingeschaltet = true;
            aktualisieren();
        }else
        {
            Aktualisieren_fkon_eingeschaltet = false;
            aktualisieren();
        }
    }
    inline bool get_aktualisieren_fkon_ein_aus()
    {
        return Aktualisieren_fkon_eingeschaltet;
    }

    inline  bool ist_aktualisieren_fkon_ein()
    {
        return Aktualisieren_fkon_eingeschaltet;
    }
    void aktualisieren();
    void wurde_gespeichert();
    bool get_hat_ungesicherte_inhalte();

    void cad_sortieren(uint zeinumbeg, uint zeinumend, uint anz_der_durchlaeufe);
    void linien_zu_fkon(uint zeinumbeg, uint zeinumend, text_zeilenweise defaultwerte_Dialoge);
    void fkon_zu_linien(uint zeinumbeg, uint zeinumend);
    void fkon_richtung_wechseln(uint zeinumbeg, uint zeinumend);
    void fkon_vor(uint zeinumbeg, uint zeinumend);
    void fkon_nach(uint zeinumbeg, uint zeinumend);
    void rta_zu_cad(uint zeinumakt);

    bool cagleich(punkt3d p1, punkt3d p2, double tolleranz);
    void versatzvar(uint zeinumbeg, uint zeinumend);
    void spiegeln_verti(uint zeinumbeg, uint zeinumend);
    void spiegeln_hori(uint zeinumbeg, uint zeinumend);

private:
    text_zw             Text;           //Programm-Rohtext (mit Formeln und Variablen)
    text_zw             Text_kopie;     //Zum Vergleichen ob sich die Datei geändert wurde seit dem Speichern
    text_zeilenweise    Klartext;       //Programm-Klartext (Formeln und Variablen sind nun Zahlen)
    text_zeilenweise    Var;            //Variablen
    text_zeilenweise    Anzeigetext;    //Programmliste
    geometrietext       Geo;            //Geometrieen zur Darstellung
    geometrietext       Fkon;           //Fräskonturen
    werkzeug            Wkz;              //Werkzeug
    geometrietext       Maschinengeo;   //Maschinengeometrie
    geometrietext       Fraeserdarst;   //Darstellung des Fräsers

    float   Wst_laenge;
    float   Wst_breite;
    float   Wst_dicke;
    float   Sicherheitsabstand;
    float   Versatz_x;
    float   Versatz_y;
    float   Versatz_z;
    bool    Hat_programmkopf;
    bool    Hat_programmende;
    float   Min_x, Min_y, Max_x, Max_y;
    uint    Anz_faufr, Anz_fabfa;
    bool    Warnungen_sind_eingeschaltet;
    bool    Warnung_frDial;
    bool    Aktualisieren_eingeschaltet;
    bool    Aktualisieren_fkon_eingeschaltet;

            void    clear_ausser_text();
    inline  void    set_wst_laenge(float neue_laenge)
    {
        Wst_laenge = neue_laenge;
    }
    inline  void    set_wst_breite(float neue_breite)
    {
        Wst_breite = neue_breite;
    }
    inline  void    set_wst_dicke(float neue_dicke)
    {
        Wst_dicke = neue_dicke;
    }
    inline  void    set_versatz_x(float versatz)
    {
        Versatz_x = versatz;
    }
    inline  void    set_versatz_y(float versatz)
    {
        Versatz_y = versatz;
    }
    inline  void    set_versatz_z(float versatz)
    {
        Versatz_z = versatz;
    }
            void    set_sicherheitsabstand(float neuer_Abstand);


            void    aktualisiere_klartext_var();
            void    aktualisiere_geo();
            void    aktualisiere_anzeigetext();
            void    aktualisiere_wkz();
            void    aktualisiere_fkon();
            void    aktualisiere_fraeserdarst();            
            void    aktualisiere_schleife_linear();
            void    aktualisiere_min_max();

            text_zeilenweise fkon_use_values(text_zeilenweise cam);





};

#endif // PROGRAMMTEXT_H
