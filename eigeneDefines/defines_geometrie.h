#ifndef DEFINES_GEOMETRIE_H
#define DEFINES_GEOMETRIE_H

#define TRZ_PA         "/"     //Trennt einzelne Parameter
#define TRZ_EL         ";"     //Trennt Geometrieelemente


#define PUNKT       "p"
/*
x
y
z
Farbe des Punktes
Breite des Punktes = Punktgröße
*/
#define STRECKE     "strecke"
/*
x-Start
y-Start
z-Start
x-Ende
y-Ende
z-Ende
Farbe der Linie
Breite der Linie
Stil der Linie
*/
#define BOGEN       "bogen"
/*
x-Start
y-Start
z-Start
x-Ende
y-Ende
z-Ende
Radius
Richtung
    0 = im uhrzeigersinn
    1 = gegen den Uhrzeigersinn
x-Mittelpunkt
y-Mittelpunkt
    einen Mittelpunkt in Z gibt es nicht, da der Boden nur 2,5-dimensional ist
    heißt der Bogen geht von Start nach Ende mit linearer Tiefenzustellung
Farbe der Linie
Breite der Linie
Stil der Linie
*/
#define KREIS       "kreis"
/*
x-Mitte
y-Mitte
z-Mitte
Radius
Farbe der Linie
Farbe der Füllung
Breite der Linie
Stil der Linie
*/
#define ZYLINDER    "zylinder"
/*
x-Mitte der Grundfläche
y-Mitte der Grundfläche
z-Mitte der Grundfläche
Radius der Grundfläche
Höhe
Farbe der Linie
Farbe der Füllung
Breite der Linie
Stil der Linie
*/
#define RECHTECK3D  "rechteck3d"
/*
Bezugspunkt
x-Einfügepunkt
y-Einfügepunkt
z-Einfügepunkt
Länge
Breite
Eckenradius
Drehwinkel
Farbe der Linie
Farbe der Füllung
Breite der Linie
Stil der Linie
*/
#define WUERFEL     "wuerfel"
/*
Bezugspunkt-Nummer
x-Einfügepunkt
y-Einfügepunkt
z-Einfügepunkt
Länge
Breite
Eckenradius
Drehwinkel
Höhe
Farbe der Linie
Farbe der Füllung
Breite der Linie
Stil der Linie
*/


#endif // DEFINES_GEOMETRIE_H
