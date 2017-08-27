#include "strecke.h"

strecke::strecke()
{
    punkt3d p;
    p.set_x(0);
    p.set_y(0);
    p.set_z(0);
    set_start(p);
    set_ende(p);
    laenge2d = 0;
    laenge3d = 0;
}

strecke::strecke(QString geotext)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(TRZ_PA_);
    tz.set_text(geotext);
    punkt3d p;
    p.set_x(tz.zeile(2).toDouble());
    p.set_y(tz.zeile(3).toDouble());
    p.set_z(tz.zeile(4).toDouble());
    set_start(p);
    p.set_x(tz.zeile(5).toDouble());
    p.set_y(tz.zeile(6).toDouble());
    p.set_z(tz.zeile(7).toDouble());
    set_ende(p);
    set_farbe(tz.zeile(8));
    set_breite(tz.zeile(9).toInt());
    set_stil(tz.zeile(10));
}

void strecke::set_start(punkt3d startpunkt)
{
    start = startpunkt;
    laenge_berechnen();
}

void strecke::set_ende(punkt3d endpunkt)
{
    ende = endpunkt;
    laenge_berechnen();
}

void strecke::richtung_unkehren()
{
    punkt3d tmp = start;
    start = ende;
    ende = tmp;
}

void strecke::laenge_berechnen()
{
    punkt3d p3 = ende-start;
    laenge3d = sqrt(p3.x()*p3.x() + p3.y()*p3.y() + p3.z()*p3.z());
                //Wurzel aus (a²+b²+c²)

    punkt2d sp(start);
    punkt2d ep(ende);
    punkt2d p2 = ep-sp;
    laenge2d = sqrt(p2.x()*p2.x() + p2.y()*p2.y()); //Wurzel aus (a²+b²)
}

punkt3d strecke::get_mittelpunkt3d()
{
    return start + ((ende-start)/2);
}

punkt2d strecke::get_mittelpunkt2d()
{
    punkt2d sta(start);
    punkt2d end(ende);
    return sta + ((end-sta)/2);
}

void strecke::drenen_um_mittelpunkt_2d(float drehwinkel, \
                                    bool drehrichtung_im_uhrzeigersinn)
{
    punkt2d sp(start);
    punkt2d ep(ende);
    punkt2d mp = get_mittelpunkt2d();
    sp = drehen(mp, sp, drehwinkel, drehrichtung_im_uhrzeigersinn);
    ep = drehen(mp, ep, drehwinkel, drehrichtung_im_uhrzeigersinn);
    punkt3d tmp;
    tmp.set_x(sp.x());
    tmp.set_y(sp.y());
    tmp.set_z(start.z());
    set_start(tmp);
    tmp.set_x(ep.x());
    tmp.set_y(ep.y());
    tmp.set_z(ende.z());
    set_ende(tmp);
}

void strecke::drenen_um_startpunkt_2d(float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    punkt2d sp(start);
    punkt2d ep(ende);
    ep = drehen(sp, ep, drehwinkel, drehrichtung_im_uhrzeigersinn);
    punkt3d tmp;
    tmp.set_x(ep.x());
    tmp.set_y(ep.y());
    tmp.set_z(ende.z());
    set_ende(tmp);
}

void strecke::drenen_um_endpunkt_2d(float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    punkt2d sp(start);
    punkt2d ep(ende);
    sp = drehen(ep, sp, drehwinkel, drehrichtung_im_uhrzeigersinn);
    punkt3d tmp;
    tmp.set_x(sp.x());
    tmp.set_y(sp.y());
    tmp.set_z(start.z());
    set_start(tmp);
}

void strecke::set_laenge_2d(float neue_laenge, strecke_bezugspunkt bezugspunkt)
{
    float skalfakt = neue_laenge/laenge2d;

    switch(bezugspunkt)
    {
    case strecke_bezugspunkt_start:
    {
        punkt2d sp(start);
        punkt2d ep(ende);
        punkt2d p2;
        punkt3d p3;
        p2 = ep-sp;
        p2 = p2*skalfakt;
        ep = sp+p2;
        p3.set_x(ep.x());
        p3.set_y(ep.y());
        p3.set_z(ende.z());
        set_ende(p3);
        laenge_berechnen();
    }
        break;
    case strecke_bezugspunkt_mitte:
    {
        punkt2d mp = get_mittelpunkt2d();
        punkt2d sp(start);
        punkt2d ep(ende);

        punkt2d p2e;//Endpunkt
        punkt3d p3e;//Endpunkt
        p2e = ep-mp;
        p2e = p2e*skalfakt;
        ep = mp+p2e;
        p3e.set_x(ep.x());
        p3e.set_y(ep.y());
        p3e.set_z(ende.z());
        set_ende(p3e);

        punkt2d p2s; //Startpunkt
        punkt3d p3s; //Startpunkt
        p2s = sp-mp;
        p2s = p2s*skalfakt;
        sp = mp+p2s;
        p3s.set_x(sp.x());
        p3s.set_y(sp.y());
        p3s.set_z(start.z());
        set_start(p3s);

        laenge_berechnen();
    }
        break;
    case strecke_bezugspunkt_ende:
    {
        punkt2d sp(start);
        punkt2d ep(ende);
        punkt2d p2;
        punkt3d p3;
        p2 = sp-ep;
        p2 = p2*skalfakt;
        sp = ep+p2;
        p3.set_x(sp.x());
        p3.set_y(sp.y());
        p3.set_z(start.z());
        set_start(p3);
        laenge_berechnen();
    }
        break;
    }
}

QString strecke::get_text()
{
    QString msg = STRECKE;
    msg += TRZ_PA;
    msg += startp().x_QString();
    msg += TRZ_PA;
    msg += startp().y_QString();
    msg += TRZ_PA;
    msg += startp().z_QString();
    msg += TRZ_PA;
    msg += endp().x_QString();
    msg += TRZ_PA;
    msg += endp().y_QString();
    msg += TRZ_PA;
    msg += endp().z_QString();
    msg += TRZ_PA;
    msg += get_farbe();
    msg += TRZ_PA;
    msg += get_breite_qstring();
    msg += TRZ_PA;
    msg += get_stil();

    return msg;
}
