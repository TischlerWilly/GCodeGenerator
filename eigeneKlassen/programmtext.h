#ifndef PROGRAMMTEXT_H
#define PROGRAMMTEXT_H

#include <QString>
#include <math.h>
#include "../myDefines.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "text_zeilenweise.h"
#include "wenndannsonst.h"
#include "rechtecktasche.h"


class programmtext
{
public:
    programmtext();
    void set_text(QString neuer_Text);
    void clear();
    QString get_text();
    text_zeilenweise get_text_zeilenweise();
    QString get_klartext();
    text_zeilenweise get_klartext_zeilenweise();
    QString get_variablen();
    text_zeilenweise get_variablen_zeilenweise();
    QString get_anzeigetext();
    text_zeilenweise get_anzeigetext_zeilenweise();
    QString get_anzeigetext_zeile(uint zeilennummer);
    void warnungen_einschalten(bool einschalten);

    float get_werkstuecklaenge();
    float get_werkstueckbreite();
    float get_werkstueckdicke();
    float get_sicherheitsabstand();
    float get_min_x();
    float get_max_x();
    float get_min_y();
    float get_max_y();

    QString zeile(uint zeilennummer);
    QString zeilen(uint zeilennummer_beginn, uint zeilenmenge);
    int zeile_loeschen(uint zeilennummer);
    int zeilen_loeschen(uint zeilennummer_beginn, uint zeilenmenge);
    int zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext);
    int zeilen_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext);
    void zeile_anhaengen(QString zeilentext);
    int zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext);

private:
    text_zeilenweise text;
    text_zeilenweise klartext;
    text_zeilenweise var;
    text_zeilenweise anzeigetext;

    void clear_ausser_text();
    void set_werkstuecklaenge(float neue_laenge);
    void set_werkstueckbreite(float neue_breite);
    void set_werkstueckdicke(float neue_dicke);
    void set_sicherheitsabstand(float neuer_Abstand);
    void aktualisiere_klartext_und_var();
    void aktualisiere_anzeigetext();

    float werkstuecklaenge;
    float werkstueckbreite;
    float werkstueckdicke;
    float sicherheitsabstand;
    bool hat_programmkopf;
    bool hat_programmende;
    bool warnungen_sind_eingeschaltet;
    float min_x, min_y, max_x, max_y;
    uint anz_faufr, anz_fabfa;
    bool warnung_frDial;




};

#endif // PROGRAMMTEXT_H
