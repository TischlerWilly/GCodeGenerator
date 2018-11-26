#include "zylinder.h"

zylinder::zylinder()
{
    set_mittelpunkt(0,0,0);
    set_radius(0);
    set_hoehe(0);
}
zylinder::zylinder(QString geotext)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(TRZ_PA_);
    tz.set_text(geotext);
    punkt3d p;
    p.set_x(tz.zeile(2).toDouble());
    p.set_y(tz.zeile(3).toDouble());
    p.set_z(tz.zeile(4).toDouble());
    set_mittelpunkt(p);
    set_radius(tz.zeile(5).toDouble());
    set_hoehe(tz.zeile(6).toDouble());
    set_farbe(tz.zeile(7));
    set_farbe_fuellung(tz.zeile(8));
    set_linienbreite(tz.zeile(9).toInt());
    set_stil(tz.zeile(10));
}
