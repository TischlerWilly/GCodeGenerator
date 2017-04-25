#include "bogen.h"

bogen::bogen()
{
    fehler = true;
}

bogen::bogen(punkt3d startpunkt, punkt3d endpunkt)
{
    set_startpunkt(startpunkt);
    set_endpunkt(endpunkt);
}

bogen::bogen(punkt3d startpunkt, punkt3d endpunkt, \
             float radiuswert, bool im_uhrzeigersinn)
{
    set_startpunkt(startpunkt);
    set_endpunkt(endpunkt);
    set_radius(radiuswert, im_uhrzeigersinn);
}

void bogen::set_startpunkt(punkt3d startpunkt)
{
    startp = startpunkt;
}

void bogen::set_endpunkt(punkt3d endpunkt)
{
    endp = endpunkt;
}


void bogen::set_radius(float radiuswert, bool im_uhrzeigersinn)
{
    radius = radiuswert;
    bogen_im_uzs = im_uhrzeigersinn;
    punkt2d pstart(startp); //Z-Werte sollen hier ignoriert werden
    punkt2d pende(endp);    //Z-Werte sollen hier ignoriert werden
    strecke stre_spep;
    stre_spep.set_start(startp);
    stre_spep.set_ende(endp);
    float laenge = stre_spep.laenge2dim();
    if(  pstart==pende  ||  radiuswert<=0  )
    {
        fehler = true;
        fehlertext = "Fehler! Start und Endpunkt sind deckungsgleich";
    }else if( radiuswert <= laenge/2)
    {
        fehler = true;
        fehlertext = "Fehler! Radius zu klein für Punktabstand Start-Ende";
    }else
    {
        fehler = false;

        double a = stre_spep.laenge2dim()/2; //Hälfte des Abstandes von
                                             //Start und Endpunkt
        double r = radiuswert;
        double x = sqrt(r*r - a*a)*2; //Länge der Mittelsenkrechtenn zu stre_spep

        strecke stre_tmp = stre_spep;
        stre_tmp.drenen_um_mittelpunkt_2d(90,true);
        stre_tmp.set_laenge_2d(x, strecke_bezugspunkt_mitte);

        if(im_uhrzeigersinn == false)
        {
            mittelp.set_x(stre_tmp.startp().x());
            mittelp.set_y(stre_tmp.startp().y());
        }else
        {
            mittelp.set_x(stre_tmp.endp().x());
            mittelp.set_y(stre_tmp.endp().y());
        }
    }
}
