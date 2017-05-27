#ifndef DEFINES_GEOMETRIE_H
#define DEFINES_GEOMETRIE_H

#define TRZ_PA         "/"     //Trennt einzelne Parameter
#define TRZ_PA_        '/'
#define TRZ_EL         ";"     //Trennt Geometrieelemente
#define TRZ_EL_        ';'

#define PUNKT       "punkt"
/*
 2) x
 3) y
 4) z
 5) Farbe des Punktes
 6) Breite des Punktes = Punktgröße
*/
#define STRECKE     "strecke"
/*
 2) x-Start
 3) y-Start
 4) z-Start
 5) x-Ende
 6) y-Ende
 7) z-Ende
 8) Farbe der Linie
 9) Breite der Linie
10) Stil der Linie
*/
#define BOGEN       "bogen"
/*
 2) x-Start
 3) y-Start
 4) z-Start
 5) x-Ende
 6) y-Ende
 7) z-Ende
 8) Radius
 9) Richtung
    ja = im uhrzeigersinn
    nein = gegen den Uhrzeigersinn
10) x-Mittelpunkt
11) y-Mittelpunkt
    einen Mittelpunkt in Z gibt es nicht, da der Boden nur 2,5-dimensional ist
    heißt der Bogen geht von Start nach Ende mit linearer Tiefenzustellung
12) Farbe der Linie
13) Breite der Linie
14) Stil der Linie
*/
#define KREIS       "kreis"
/*
 2) x-Mitte
 3) y-Mitte
 4) z-Mitte
 5) Radius
 6) Farbe der Linie
 7) Farbe der Füllung
 8) Breite der Linie
 9) Stil der Linie
*/
#define ZYLINDER    "zylinder"
/*
 2) x-Mitte der Grundfläche
 3) y-Mitte der Grundfläche
 4) z-Mitte der Grundfläche
 5) Radius der Grundfläche
 6) Höhe
 7) Farbe der Linie
 8) Farbe der Füllung
 9) Breite der Linie
10) Stil der Linie
*/
#define RECHTECK3D  "rechteck3d"
/*
 2) Bezugspunkt
 3) x-Einfügepunkt
 4) y-Einfügepunkt
 5) z-Einfügepunkt
 6) Länge
 7) Breite
 8) Eckenradius
 9) Drehwinkel
10) Farbe der Linie
11) Farbe der Füllung
12) Breite der Linie
13) Stil der Linie
*/
#define WUERFEL     "wuerfel"
/*
 2) Bezugspunkt-Nummer
 3) x-Einfügepunkt
 4) y-Einfügepunkt
 5) z-Einfügepunkt
 6) Länge
 7) Breite
 8) Eckenradius
 9) Drehwinkel
10) Höhe
11) Farbe der Linie
12) Farbe der Füllung
13) Breite der Linie
14) Stil der Linie
*/


#endif // DEFINES_GEOMETRIE_H
