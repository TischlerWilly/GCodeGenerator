#include "wuerfel.h"

wuerfel::wuerfel()
{
    set_bezugspunkt(MITTE);
    set_einfuegepunkt(0,0,0);
    set_laenge(0);
    set_breite(0);
    set_rad(0);
    set_drewi(0);
    set_hoehe(0);
}
wuerfel::wuerfel(QString geotext)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(TRZ_PA_);
    tz.set_text(geotext);
    set_bezugspunkt(tz.zeile(2).toInt());
    punkt3d p;
    p.set_x(tz.zeile(3).toDouble());
    p.set_y(tz.zeile(4).toDouble());
    p.set_z(tz.zeile(5).toDouble());
    set_einfuegepunkt(p);
    set_laenge(tz.zeile(6).toDouble());
    set_breite(tz.zeile(7).toDouble());
    set_rad(tz.zeile(8).toDouble());
    set_drewi(tz.zeile(9).toDouble());
    set_hoehe(tz.zeile(10).toDouble());
    set_farbe(tz.zeile(11));
    set_farbe_fuellung(tz.zeile(12));
    set_linienbreite(tz.zeile(13).toInt());
    set_stil(tz.zeile(14));
}
