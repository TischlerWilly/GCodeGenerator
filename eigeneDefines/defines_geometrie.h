#ifndef DEFINES_GEOMETRIE_H
#define DEFINES_GEOMETRIE_H

#define TRZ_PA         "/"     //Trennt einzelne Parameter
#define TRZ_EL         ";"     //Trennt Geometrieelemente


#define PUNKT       "p"
    // x / y / z

#define STRECKE     "s"
    // x-Start / y-Start / z-Start
    // x-Ende  / y-Ende  / z-Ende

#define BOGEN       "b"
    // x-Start / y-Start / z-Start
    // x-Ende  / y-Ende  / z-Ende
    // Radius  / Richtung
                 //0 = im uhrzeigersinn
                 //1 = gegen den Uhrzeigersinn
    // x-Mittelpunkt / y-Mittelpunkt
    // einen Mittelpunkt in Z gibt es nicht, da der Boden nur 2,5-dimensional ist
    // heißt der Bogen geht von Start nach Ende mit linearer Tiefenzustellung
#define KREIS       "k"
    // x-Mitte / y-Mitte / z-Mitte
    // Radius
    // ausgefüllt (ja/nein)



#endif // DEFINES_GEOMETRIE_H
