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

double winkel(double endpunkt_x, double endpunkt_y,\
              double mittelpunkt_x, double mittelpunkt_y)
{
    //berechnet wird immer der Winkel zur gedachten waagerechten Grundlinie
    //im Gegenuhrzeigersinn
    punkt3d mipu;
    mipu.set_x(mittelpunkt_x);
    mipu.set_y(mittelpunkt_y);
    punkt3d enpu;
    enpu.set_x(endpunkt_x);
    enpu.set_y(endpunkt_y);
    strecke s;
    s.set_start(mipu);
    s.set_ende(enpu);

    double hypthenuse = s.laenge2dim();
    double gegenkathete = mittelpunkt_y - endpunkt_y;

    double wi =  asin(gegenkathete/hypthenuse)/M_PI*180*-1;//Weil sonst Ergebnis in Bogenmaß;

    if(endpunkt_x - mittelpunkt_x < 0   &&\
       wi > 0)
    {
        wi = 180-wi;
    }

    if(endpunkt_x - mittelpunkt_x < 0   &&\
       wi < 0)
    {
        wi = 180-wi;
    }else if(mittelpunkt_x - endpunkt_x < 0   &&\
             wi < 0)
    {
        wi = 360+wi;
    }else if(wi == 0)
    {
        if(mittelpunkt_x < endpunkt_x)
        {
            wi = 0;
        }else
        {
            wi = 180;
        }
    }
    if(wi == -90)
    {
        wi = 270;
    }

    return wi;
}

double winkel(double endpunkt1_x, double endpunkt1_y,\
              double mittelpunkt_x, double mittelpunkt_y,\
              double endpunkt2_x, double endpunkt2_y)
{
    double w1 = winkel(endpunkt1_x, endpunkt1_y,\
                       mittelpunkt_x, mittelpunkt_y);

    double w2 = winkel(endpunkt2_x, endpunkt2_y,\
                       mittelpunkt_x, mittelpunkt_y);
    if(w2 == 0)
    {
        w2=360;
    }
    return w2-w1;
}
