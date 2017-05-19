#include "geometrie.h"

punkt drehen(punkt drehzentrum, punkt alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.x = drehzentrum.x + (alter_punkt.x - drehzentrum.x)\
                *cos_d(drehwinkel) - (alter_punkt.y - drehzentrum.y)*sin_d(drehwinkel);
        neuer_punkt.y = drehzentrum.y + (alter_punkt.x - drehzentrum.x)\
                *sin_d(drehwinkel) + (alter_punkt.y - drehzentrum.y)*cos_d(drehwinkel);
        return neuer_punkt;
    }
}

punkt2d drehen(punkt2d drehzentrum, punkt2d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt2d neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.set_x(\
                           drehzentrum.x() + (alter_punkt.x() - drehzentrum.x())\
                           *cos_d(drehwinkel) - (alter_punkt.y() - drehzentrum.y())\
                           *sin_d(drehwinkel)\
                           );
        neuer_punkt.set_y(\
                          drehzentrum.y() + (alter_punkt.x() - drehzentrum.x())\
                          *sin_d(drehwinkel) + (alter_punkt.y() - drehzentrum.y())\
                          *cos_d(drehwinkel)\
                          );
        return neuer_punkt;
    }
}

punkt3d drehen(punkt3d drehzentrum, punkt3d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt3d neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.set_x(\
                           drehzentrum.x() + (alter_punkt.x() - drehzentrum.x())\
                           *cos_d(drehwinkel) - (alter_punkt.y() - drehzentrum.y())\
                           *sin_d(drehwinkel)\
                           );
        neuer_punkt.set_y(\
                          drehzentrum.y() + (alter_punkt.x() - drehzentrum.x())\
                          *sin_d(drehwinkel) + (alter_punkt.y() - drehzentrum.y())\
                          *cos_d(drehwinkel)\
                          );
        return neuer_punkt;
    }
}
punkt drehen_ij(punkt drehzentrum, float drehwinkel, bool drehrichtung_im_uhrzeigersinn, \
                punkt bezugspunkt_ij, punkt punkt_ij)
{
    if(drehwinkel == 0)
    {
        return punkt_ij;
    }else{
        bezugspunkt_ij = drehen(drehzentrum, bezugspunkt_ij, \
                                drehwinkel, drehrichtung_im_uhrzeigersinn);
        punkt p;
        p.x = 0;
        p.y = 0;
        punkt_ij = drehen(p, punkt_ij, drehwinkel, drehrichtung_im_uhrzeigersinn);
        return punkt_ij;
    }
}

