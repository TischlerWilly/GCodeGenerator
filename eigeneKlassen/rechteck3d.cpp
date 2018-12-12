#include "rechteck3d.h"

rechteck3d::rechteck3d()
{
    set_bezugspunkt(MITTE);
    set_einfuegepunkt(0,0,0);
    set_laenge(0);
    set_breite(0);
    set_rad(0);
    set_drewi(0);
}
rechteck3d::rechteck3d(QString geotext)
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
    set_farbe(tz.zeile(10));
    set_farbe_fuellung(tz.zeile(11));
    set_linienbreite(tz.zeile(12).toInt());
    set_stil(tz.zeile(13));
}

void rechteck3d::set_z(double z)
{
    obli.set_z(z);
    oben.set_z(z);
    obre.set_z(z);
    links.set_z(z);
    mitte.set_z(z);
    rechts.set_z(z);
    unli.set_z(z);
    unten.set_z(z);
    unre.set_z(z);
}

void rechteck3d::set_laenge(double neue_laenge)
{
    laenge = neue_laenge;
    switch(bezugspunkt)
    {
        case LINKS:
        case UNTEN_LINKS:
        case OBEN_LINKS:
            unli.set_x(einfuegepunkt.x());
            obli.set_x(einfuegepunkt.x());
            links.set_x(einfuegepunkt.x());
            unre.set_x(einfuegepunkt.x() + neue_laenge);
            obre.set_x(einfuegepunkt.x() + neue_laenge);
            rechts.set_x(einfuegepunkt.x() + neue_laenge);
            mitte.set_x(einfuegepunkt.x() + neue_laenge/2);
            oben.set_x(einfuegepunkt.x() + neue_laenge/2);
            unten.set_x(einfuegepunkt.x() + neue_laenge/2);
            break;
        case RECHTS:
        case UNTEN_RECHTS:
        case OBEN_RECHTS:
            unli.set_x(einfuegepunkt.x() - neue_laenge);
            obli.set_x(einfuegepunkt.x() - neue_laenge);
            links.set_x(einfuegepunkt.x() - neue_laenge);
            unre.set_x(einfuegepunkt.x());
            obre.set_x(einfuegepunkt.x());
            rechts.set_x(einfuegepunkt.x());
            mitte.set_x(einfuegepunkt.x() - neue_laenge/2);
            oben.set_x(einfuegepunkt.x() - neue_laenge/2);
            unten.set_x(einfuegepunkt.x() - neue_laenge/2);
            break;
        case OBEN:
        case UNTEN:
        case MITTE:
            unli.set_x(einfuegepunkt.x() - neue_laenge/2);
            obli.set_x(einfuegepunkt.x() - neue_laenge/2);
            links.set_x(einfuegepunkt.x() - neue_laenge/2);
            unre.set_x(einfuegepunkt.x() + neue_laenge/2);
            obre.set_x(einfuegepunkt.x() + neue_laenge/2);
            rechts.set_x(einfuegepunkt.x() + neue_laenge/2);
            mitte.set_x(einfuegepunkt.x());
            oben.set_x(einfuegepunkt.x());
            unten.set_x(einfuegepunkt.x());
            break;
    }
}

void rechteck3d::set_breite(double neue_breite)
{
    breite = neue_breite;
    switch(bezugspunkt)
    {
        case UNTEN:
        case UNTEN_LINKS:
        case UNTEN_RECHTS:
            unli.set_y(einfuegepunkt.y());
            unre.set_y(einfuegepunkt.y());
            unten.set_y(einfuegepunkt.y());
            obre.set_y(einfuegepunkt.y() + neue_breite);
            obli.set_y(einfuegepunkt.y() + neue_breite);
            oben.set_y(einfuegepunkt.y() + neue_breite);
            mitte.set_y(einfuegepunkt.y() + neue_breite/2);
            links.set_y(einfuegepunkt.y() + neue_breite/2);
            rechts.set_y(einfuegepunkt.y() + neue_breite/2);
            break;
        case OBEN:
        case OBEN_LINKS:
        case OBEN_RECHTS:
            unli.set_y(einfuegepunkt.y() - neue_breite);
            unre.set_y(einfuegepunkt.y() - neue_breite);
            unten.set_y(einfuegepunkt.y() - neue_breite);
            obre.set_y(einfuegepunkt.y());
            obli.set_y(einfuegepunkt.y());
            oben.set_y(einfuegepunkt.y());
            mitte.set_y(einfuegepunkt.y() - neue_breite/2);
            links.set_y(einfuegepunkt.y() - neue_breite/2);
            rechts.set_y(einfuegepunkt.y() - neue_breite/2);
            break;
        case LINKS:
        case RECHTS:
        case MITTE:
            unli.set_y(einfuegepunkt.y() - neue_breite/2);
            unre.set_y(einfuegepunkt.y() - neue_breite/2);
            unten.set_y(einfuegepunkt.y() - neue_breite/2);
            obre.set_y(einfuegepunkt.y() + neue_breite/2);
            obli.set_y(einfuegepunkt.y() + neue_breite/2);
            oben.set_y(einfuegepunkt.y() + neue_breite/2);
            mitte.set_y(einfuegepunkt.y());
            links.set_y(einfuegepunkt.y());
            rechts.set_y(einfuegepunkt.y());
            break;
    }
}

punkt3d rechteck3d::bezpunkt()
{
    switch(bezugspunkt)
    {
        case UNTEN_LINKS:
            return unli;
        case UNTEN_RECHTS:
            return unre;
        case OBEN_RECHTS:
            return obre;
        case OBEN_LINKS:
            return obli;
        case MITTE:
            return mitte;
        case LINKS:
            return links;
        case RECHTS:
            return rechts;
        case OBEN:
            return oben;
        case UNTEN:
            return unten;
        default:
            punkt3d p(0,0,0);
            return p;
    }
}

void rechteck3d::set_rad(double neuer_radius)
{
    radius = neuer_radius;
}

void rechteck3d::set_drewi(double neuer_drehwinkel)
{
    drehwinkel = neuer_drehwinkel;
}

void rechteck3d::verschieben_um(double xversatz, double yversatz)
{
    obli.verschieben_um(xversatz, yversatz);
    oben.verschieben_um(xversatz, yversatz);
    obre.verschieben_um(xversatz, yversatz);
    links.verschieben_um(xversatz, yversatz);
    mitte.verschieben_um(xversatz, yversatz);
    rechts.verschieben_um(xversatz, yversatz);
    unli.verschieben_um(xversatz, yversatz);
    unten.verschieben_um(xversatz, yversatz);
    unre.verschieben_um(xversatz, yversatz);
    einfuegepunkt.verschieben_um(xversatz, yversatz);
}
