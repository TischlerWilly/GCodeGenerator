#ifndef PROGRAMMTEXT_H
#define PROGRAMMTEXT_H

#include <QString>
#include <math.h>
#include "../myDefines.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "text_zeilenweise.h"
#include "wenndannsonst.h"
#include "rechtecktasche.h"
#include "geometrietext.h"
#include "werkzeug.h"
#include "tabelle_tz3.h"


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
        warnungen_sind_eingeschaltet = einschalten;
    }
    inline  QString             get_text()
    {
        return text.get_text();
    }
    inline  text_zeilenweise    get_text_zeilenweise()
    {
        return text;
    }
            QString             get_klartext();
    inline  text_zeilenweise    get_klartext_zeilenweise()
    {
        return klartext;
    }
            QString             get_variablen();
    inline  text_zeilenweise    get_variablen_zeilenweise()
    {
        return var;
    }
    inline  QString             get_anzeigetext()
    {
        return anzeigetext.get_text();
    }
    inline  text_zeilenweise    get_anzeigetext_zeilenweise()
    {
        return anzeigetext;
    }
    inline  QString             get_anzeigetext_zeile(uint zeilennummer)
    {
        return anzeigetext.zeile(zeilennummer);
    }

    inline  geometrietext       get_geo()
    {
        return geo;
    }
    inline  geometrietext       get_fkon()
    {
        return fkon;
    }
    inline  geometrietext       get_maschinengeo()
    {
        return maschinengeo;
    }
    inline  geometrietext       get_fraeserdarst()
    {
        return fraeserdarst;
    }

    inline  float   get_werkstuecklaenge()
    {
        return werkstuecklaenge;
    }
    inline  float   get_werkstueckbreite()
    {
        return werkstueckbreite;
    }
    inline  float   get_werkstueckdicke()
    {
        return werkstueckdicke;
    }
    inline  float   get_sicherheitsabstand()
    {
        return sicherheitsabstand;
    }
    inline  float   get_min_x()
    {
        return min_x;
    }
    inline  float   get_max_x()
    {
        return max_x;
    }
    inline  float   get_min_y()
    {
        return min_y;
    }
    inline  float   get_max_y()
    {
        return max_y;
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
            aktualisieren_eingeschaltet = true;
            aktualisiere_klartext_var_geo();
            aktualisiere_anzeigetext();
            aktualisiere_fkon();
        }else
        {
            aktualisieren_eingeschaltet = false;
        }
    }

    inline  void aktualisieren_fkon_ein_aus(bool einschalten)
    {
        if(einschalten)
        {
            aktualisieren_fkon_eingeschaltet = true;
            aktualisiere_fkon();
        }else
        {
            aktualisieren_fkon_eingeschaltet = false;
        }
    }
    inline  bool ist_aktualisieren_fkon_ein()
    {
        return aktualisieren_fkon_eingeschaltet;
    }
    inline void aktualisieren()
    {
        aktualisiere_klartext_var_geo();
        aktualisiere_fkon();
        aktualisiere_anzeigetext();
    }

    void cad_sortieren(uint zeinumbeg, uint zeinumend);
    void linien_zu_fkon(uint zeinumbeg, uint zeinumend, text_zeilenweise defaultwerte_Dialoge);
    void fkon_zu_linien(uint zeinumbeg, uint zeinumend);
    void fkon_richtung_wechseln(uint zeinumbeg, uint zeinumend);

    bool cagleich(punkt3d p1, punkt3d p2, double tolleranz);

private:
    text_zeilenweise    text;           //Programm-Rohtext (mit Formeln und Variablen)
    text_zeilenweise    klartext;       //Programm-Klartext (Formeln und Variablen sind nun Zahlen)
    text_zeilenweise    var;            //Variablen
    text_zeilenweise    anzeigetext;    //Programmliste
    geometrietext       geo;            //Geometrieen zur Darstellung
    geometrietext       fkon;           //Fräskonturen
    werkzeug            w;              //Werkzeug
    geometrietext       maschinengeo;   //Maschinengeometrie
    geometrietext       fraeserdarst;   //Darstellung des Fräsers

    float   werkstuecklaenge;
    float   werkstueckbreite;
    float   werkstueckdicke;
    float   sicherheitsabstand;
    float   versatz_x;
    float   versatz_y;
    float   versatz_z;
    bool    hat_programmkopf;
    bool    hat_programmende;
    float   min_x, min_y, max_x, max_y;
    uint    anz_faufr, anz_fabfa;
    bool    warnungen_sind_eingeschaltet;
    bool    warnung_frDial;
    bool    aktualisieren_eingeschaltet;
    bool    aktualisieren_fkon_eingeschaltet;

            void    clear_ausser_text();
    inline  void    set_werkstuecklaenge(float neue_laenge)
    {
        werkstuecklaenge = neue_laenge;
    }
    inline  void    set_werkstueckbreite(float neue_breite)
    {
        werkstueckbreite = neue_breite;
    }
    inline  void    set_werkstueckdicke(float neue_dicke)
    {
        werkstueckdicke = neue_dicke;
    }
    inline  void    set_versatz_x(float versatz)
    {
        versatz_x = versatz;
    }
    inline  void    set_versatz_y(float versatz)
    {
        versatz_y = versatz;
    }
    inline  void    set_versatz_z(float versatz)
    {
        versatz_z = versatz;
    }
            void    set_sicherheitsabstand(float neuer_Abstand);

            void    aktualisiere_klartext_var_geo();
            void    aktualisiere_anzeigetext();
            void    aktualisiere_wkz();
            void    aktualisiere_fkon();
            void    aktualisiere_fraeserdarst();





};

#endif // PROGRAMMTEXT_H
