#ifndef GEOMETRIE_H
#define GEOMETRIE_H

#include <math.h>
#include "../eigeneStruncts/punkt.h"
#include "../eigeneMakros/makro_geometrie.h"
#include "../eigeneKlassen/punkt2d.h"



punkt drehen(punkt drehzentrum, punkt alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn);
punkt2d drehen(punkt2d drehzentrum, punkt2d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn);

punkt drehen_ij(punkt drehzentrum, float drehwinkel, \
                bool drehrichtung_im_uhrzeigersinn, \
                punkt bezugspunkt_ij, punkt punkt_ij);

punkt kreismittelpunkt(punkt start, punkt ende, float radius, bool im_uzs);

#endif // GEOMETRIE_H
