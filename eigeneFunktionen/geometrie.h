#ifndef GEOMETRIE_H
#define GEOMETRIE_H

#include <math.h>
#include "../eigeneStruncts/punkt.h"
#include "../eigeneMakros/makro_geometrie.h"
#include "../eigeneKlassen/punkt2d.h"
#include "../eigeneKlassen/strecke.h"



punkt drehen(punkt drehzentrum, punkt alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn);
punkt2d drehen(punkt2d drehzentrum, punkt2d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn);
punkt3d drehen(punkt3d drehzentrum, punkt3d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn);

punkt drehen_ij(punkt drehzentrum, float drehwinkel, \
                bool drehrichtung_im_uhrzeigersinn, \
                punkt bezugspunkt_ij, punkt punkt_ij);

double winkel(double endpunkt_x, double endpunkt_y,\
              double mittelpunkt_x, double mittelpunkt_y);

#endif // GEOMETRIE_H
