#ifndef GCODE_H
#define GCODE_H

#include "text_zeilenweise.h"
#include "../eigeneFunktionen/umwandeln.h"
#include "programmtext.h"
#include "../myDefines.h"

class gcode
{
public:
    gcode(programmtext t_neu);
    void set_prgtext(programmtext t_neu);
    void set_wkz(werkzeug w_neu);

    QString get_gcode();


private:
    programmtext t;
    werkzeug w;
    double eintauchvorschub;
    double vorschub;
    double drehzahl;
    double zustellmass;
    QString aktives_wkz;

    QString klammern_wecklassen(QString text);
    QString werkzeugdaten(QString werkzeugname);

    QString get_prgkopf(QString zeile_klartext);
    QString get_prgende(QString zeile_klartext);
    QString get_kom(QString zeile_klartext);
    QString get_rta(QString zeile_klartext, QString* fehlertext, double ax, double ay);
    QString get_kta(QString zeile_klartext, QString* fehlertext, double ax, double ay);
    QString get_bohrung(QString zeile_klartext, QString* fehlertext, double ax, double ay);
    QString get_fkon(text_zeilenweise klartext, geometrietext fkon, \
                     QString* fehlertext, double ax, double ay);
};

#endif // GCODE_H
