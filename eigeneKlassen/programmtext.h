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


class programmtext
{
public:
    programmtext();
            void                set_text(QString neuer_Text);
            void                set_wkz(werkzeug wkz);
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





private:
    text_zeilenweise    text;
    text_zeilenweise    klartext;
    text_zeilenweise    var;
    text_zeilenweise    anzeigetext;
    geometrietext       geo;
    werkzeug            w;

    float   werkstuecklaenge;
    float   werkstueckbreite;
    float   werkstueckdicke;
    float   sicherheitsabstand;
    bool    hat_programmkopf;
    bool    hat_programmende;
    float   min_x, min_y, max_x, max_y;
    uint    anz_faufr, anz_fabfa;
    bool    warnungen_sind_eingeschaltet;
    bool    warnung_frDial;

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
            void    set_sicherheitsabstand(float neuer_Abstand);

            void    aktualisiere_klartext_var_geo();
            void    aktualisiere_anzeigetext();
            void    aktualisiere_wkz();





};

#endif // PROGRAMMTEXT_H
