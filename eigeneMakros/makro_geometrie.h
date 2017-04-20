#ifndef MAKROS_GEOMETRIE_H
#define MAKROS_GEOMETRIE_H

//Die Funktionen für Sinus und Cosinus etc arbeiten mit Bogenaß!!!
//Die folgenden Makros rechnen das um in Grad-Angaben
#define sqr(x) ((x)*(x))
#define sin_d(x) (sin((x)*M_PI/180))
#define cos_d(x) (cos((x)*M_PI/180))
#define tan_d(x) (tan((x)*M_PI/180))
#define asin_d(x) (asin(x)*180/M_PI)
#define acos_d(x) (acos(x)*180/M_PI)
#define atan_d(x) (atan(x)*180/M_PI)




#endif // MAKROS_GEOMETRIE_H
