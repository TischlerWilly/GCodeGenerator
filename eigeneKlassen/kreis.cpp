#include "kreis.h"

kreis::kreis()
{
    set_mittelpunkt(0,0,0);
    set_radius(0);
}

kreis::kreis(QString geotext)
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
    set_farbe(tz.zeile(6));
    set_farbe_fuellung(tz.zeile(7));
    set_linienbreite(tz.zeile(8).toInt());
    set_stil(tz.zeile(9));
}

void kreis::verschieben_um(double xversatz, double yversatz)
{
    mittelp.verschieben_um(xversatz, yversatz);
}

QString kreis::get_text()
{
    QString msg = KREIS;
    msg += TRZ_PA;
    msg += mittelp.x_QString();
    msg += TRZ_PA;
    msg += mittelp.y_QString();
    msg += TRZ_PA;
    msg += mittelp.z_QString();
    msg += TRZ_PA;
    msg += radius_QString();
    msg += TRZ_PA;
    msg += get_farbe();
    msg += TRZ_PA;
    msg += get_farbe_fuellung();
    msg += TRZ_PA;
    msg += get_linienbreite_qstring();
    msg += TRZ_PA;
    msg += get_stil();

    return msg;
}
