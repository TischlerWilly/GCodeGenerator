#ifndef DARSTELLUNGSATRIBUTE_H
#define DARSTELLUNGSATRIBUTE_H

#include <QString>
#include "../eigeneFunktionen/umwandeln.h"

class darstellungsatribute
{
public:
    darstellungsatribute();

    inline void set_farbe(QString neue_farbe)
    {
        farbe = neue_farbe;
    }
    inline void set_farbe_fuellung(QString neue_farbe)
    {
        farbe_fuellung = neue_farbe;
    }
    inline void set_stil(QString neuer_stil)
    {
        stil = neuer_stil;
    }
    inline void set_breite(int neue_breite)
    {
        breite = neue_breite;
    }

    inline QString get_farbe()
    {
        return farbe;
    }
    inline QString get_farbe_fuellung()
    {
        return farbe_fuellung;
    }
    inline QString get_stil()
    {
        return stil;
    }
    inline int get_breite()
    {
        return breite;
    }
    inline QString get_breite_qstring()
    {
        return int_to_qstring(breite);
    }

private:
    QString farbe;
    QString farbe_fuellung;
    QString stil;
    int     breite;
};

#define FARBE_KEINE     "keine"
#define FARBE_SCHWARZ   "schwarz"
#define FARBE_WEISS     "weiss"
#define FARBE_BLAU      "blau"
#define FARBE_ROT       "rot"
#define FARBE_GRUEN     "gruen"
#define FARBE_GELB      "gelb"
#define FARBE_GRAU      "grau"

#define STIL_TRANSPARENT    "transparent"
#define STIL_DURCHGEHEND    "durchgehend"
#define STIL_GESTRICHELT    "gestrichelt"
#define STIL_GEPUNKTET      "gepunktet"
#define STIL_STRICHP        "strichpunkt"
#define STIL_STRICHPP       "strichpp"


#endif // DARSTELLUNGSATRIBUTE_H
