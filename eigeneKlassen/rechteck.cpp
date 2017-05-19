#include "rechteck.h"

rechteck::rechteck()
{
    //ctor
    set_bezugspunkt_nummer(1);
    set_einfuegepunkt(0,0);
    set_laenge(50);
    set_breite(50);
}

rechteck::~rechteck()
{
    //dtor
}

void rechteck::set_laenge(float neue_laenge)
{
    laenge = neue_laenge;
    switch(bezugspunkt)
    {
        case LINKS:
        case UNTEN_LINKS:
        case OBEN_LINKS:
            eckpunkt_unten_links.x = einfuegepunkt.x;
            eckpunkt_oben_links.x = einfuegepunkt.x;
            eckpunkt_links_mitte.x = einfuegepunkt.x;
            eckpunkt_unten_rechts.x = einfuegepunkt.x + neue_laenge;
            eckpunkt_oben_rechts.x = einfuegepunkt.x + neue_laenge;
            eckpunkt_rechts_mitte.x = einfuegepunkt.x + neue_laenge;
            mittelpunkt.x = einfuegepunkt.x + neue_laenge/2;
            eckpunkt_oben_mitte.x = einfuegepunkt.x + neue_laenge/2;
            eckpunkt_unten_mitte.x = einfuegepunkt.x + neue_laenge/2;
            break;
        case RECHTS:
        case UNTEN_RECHTS:
        case OBEN_RECHTS:
            eckpunkt_unten_links.x = einfuegepunkt.x - neue_laenge;
            eckpunkt_oben_links.x = einfuegepunkt.x - neue_laenge;
            eckpunkt_links_mitte.x = einfuegepunkt.x - neue_laenge;
            eckpunkt_unten_rechts.x = einfuegepunkt.x;
            eckpunkt_oben_rechts.x = einfuegepunkt.x;
            eckpunkt_rechts_mitte.x = einfuegepunkt.x;
            mittelpunkt.x = einfuegepunkt.x - neue_laenge/2;
            eckpunkt_oben_mitte.x = einfuegepunkt.x - neue_laenge/2;
            eckpunkt_unten_mitte.x = einfuegepunkt.x - neue_laenge/2;
            break;
        case OBEN:
        case UNTEN:
        case MITTE:
            eckpunkt_unten_links.x = einfuegepunkt.x - neue_laenge/2;
            eckpunkt_links_mitte.x = einfuegepunkt.x - neue_laenge/2;
            eckpunkt_oben_links.x = einfuegepunkt.x - neue_laenge/2;
            eckpunkt_unten_rechts.x = einfuegepunkt.x + neue_laenge/2;
            eckpunkt_rechts_mitte.x = einfuegepunkt.x + neue_laenge/2;
            eckpunkt_oben_rechts.x = einfuegepunkt.x + neue_laenge/2;
            mittelpunkt.x = einfuegepunkt.x;
            eckpunkt_oben_mitte.x = einfuegepunkt.x;
            eckpunkt_unten_mitte.x = einfuegepunkt.x;
            break;
    }
}
void rechteck::set_breite(float neue_breite)
{
    breite = neue_breite;
    switch(bezugspunkt)
    {
        case UNTEN:
        case UNTEN_LINKS:
        case UNTEN_RECHTS:
            eckpunkt_unten_links.y = einfuegepunkt.y;
            eckpunkt_unten_rechts.y = einfuegepunkt.y;
            eckpunkt_unten_mitte.y = einfuegepunkt.y;
            eckpunkt_oben_rechts.y = einfuegepunkt.y + neue_breite;
            eckpunkt_oben_links.y = einfuegepunkt.y + neue_breite;
            eckpunkt_oben_mitte.y = einfuegepunkt.y + neue_breite;
            mittelpunkt.y = einfuegepunkt.y + neue_breite/2;
            eckpunkt_links_mitte.y = einfuegepunkt.y + neue_breite/2;
            eckpunkt_rechts_mitte.y = einfuegepunkt.y + neue_breite/2;
            break;
        case OBEN:
        case OBEN_LINKS:
        case OBEN_RECHTS:
            eckpunkt_unten_links.y = einfuegepunkt.y - neue_breite;
            eckpunkt_unten_rechts.y = einfuegepunkt.y - neue_breite;
            eckpunkt_unten_mitte.y = einfuegepunkt.y - neue_breite;
            eckpunkt_oben_rechts.y = einfuegepunkt.y;
            eckpunkt_oben_links.y = einfuegepunkt.y;
            eckpunkt_oben_mitte.y = einfuegepunkt.y;
            mittelpunkt.y = einfuegepunkt.y - neue_breite/2;
            eckpunkt_links_mitte.y = einfuegepunkt.y - neue_breite/2;
            eckpunkt_rechts_mitte.y = einfuegepunkt.y - neue_breite/2;
            break;
        case LINKS:
        case RECHTS:
        case MITTE:
            eckpunkt_unten_links.y = einfuegepunkt.y - neue_breite/2;
            eckpunkt_unten_rechts.y = einfuegepunkt.y - neue_breite/2;
            eckpunkt_unten_mitte.y = einfuegepunkt.y - neue_breite/2;
            eckpunkt_oben_rechts.y = einfuegepunkt.y + neue_breite/2;
            eckpunkt_oben_links.y = einfuegepunkt.y + neue_breite/2;
            eckpunkt_oben_mitte.y = einfuegepunkt.y + neue_breite/2;
            mittelpunkt.y = einfuegepunkt.y;
            eckpunkt_links_mitte.y = einfuegepunkt.y;
            eckpunkt_rechts_mitte.y = einfuegepunkt.y;
            break;
    }
}
void rechteck::set_einfuegepunkt(float x, float y)
{
    einfuegepunkt.x = x;
    einfuegepunkt.y = y;
}
void rechteck::set_einfuegepunkt(punkt neuer_einfuegepunkt)
{
    einfuegepunkt.x = neuer_einfuegepunkt.x;
    einfuegepunkt.y = neuer_einfuegepunkt.y;
}
void rechteck::set_bezugspunkt_nummer(int neuer_bzugspunkt)
{
    bezugspunkt = neuer_bzugspunkt;
}
//------------------------------------------------------------------------------------------------------


float rechteck::get_laenge()
{
    return laenge;
}
float rechteck::get_breite()
{
    return breite;
}
float rechteck::get_einfuegepunkt_x()
{
    return einfuegepunkt.x;
}
float rechteck::get_einfuegepunkt_y()
{
    return einfuegepunkt.y;
}
punkt rechteck::get_einfuegepunkt()
{
    return einfuegepunkt;
}
int rechteck::get_bezugspunkt_nummer()
{
    return bezugspunkt;
}
float rechteck::get_bezugspunkt_x()
{
    switch(bezugspunkt)
    {
        case UNTEN_LINKS:
            return eckpunkt_unten_links.x;
        case UNTEN_RECHTS:
            return eckpunkt_unten_rechts.x;
        case OBEN_RECHTS:
            return eckpunkt_oben_rechts.x;
        case OBEN_LINKS:
            return eckpunkt_oben_links.x;
        case MITTE:
            return mittelpunkt.x;
        case LINKS:
            return eckpunkt_links_mitte.x;
        case RECHTS:
            return eckpunkt_rechts_mitte.x;
        case OBEN:
            return eckpunkt_oben_mitte.x;
        case UNTEN:
            return eckpunkt_unten_mitte.x;
    }
    return 0;
}
float rechteck::get_bezugspunkt_y()
{
    switch(bezugspunkt)
    {
        case UNTEN_LINKS:
            return eckpunkt_unten_links.y;
        case UNTEN_RECHTS:
            return eckpunkt_unten_rechts.y;
        case OBEN_RECHTS:
            return eckpunkt_oben_rechts.y;
        case OBEN_LINKS:
            return eckpunkt_oben_links.y;
        case MITTE:
            return mittelpunkt.y;
    case LINKS:
        return eckpunkt_links_mitte.y;
    case RECHTS:
        return eckpunkt_rechts_mitte.y;
    case OBEN:
        return eckpunkt_oben_mitte.y;
    case UNTEN:
        return eckpunkt_unten_mitte.y;
    }
    return 0;
}
punkt rechteck::get_bezugspunkt()
{
    switch(bezugspunkt)
    {
        case UNTEN_LINKS:
            return eckpunkt_unten_links;
        case UNTEN_RECHTS:
            return eckpunkt_unten_rechts;
        case OBEN_RECHTS:
            return eckpunkt_oben_rechts;
        case OBEN_LINKS:
            return eckpunkt_oben_links;
        case MITTE:
            return mittelpunkt;
        case LINKS:
            return eckpunkt_links_mitte;
        case RECHTS:
            return eckpunkt_rechts_mitte;
        case OBEN:
            return eckpunkt_oben_mitte;
        case UNTEN:
            return eckpunkt_unten_mitte;
    }
    punkt tmp;
    tmp.x = 0;
    tmp.y = 0;
    return tmp;
}
float rechteck::get_eckpunkt_unten_links_x()
{
    return eckpunkt_unten_links.x;
}
float rechteck::get_eckpunkt_unten_links_y()
{
    return eckpunkt_unten_links.y;
}
punkt rechteck::get_eckpunkt_unten_links()
{
    return eckpunkt_unten_links;
}
float rechteck::get_eckpunkt_unten_rechts_x()
{
    return eckpunkt_unten_rechts.x;
}
float rechteck::get_eckpunkt_unten_rechts_y()
{
    return eckpunkt_unten_rechts.y;
}
punkt rechteck::get_eckpunkt_unten_rechts()
{
    return eckpunkt_unten_rechts;
}
float rechteck::get_eckpunkt_oben_rechts_x()
{
    return eckpunkt_oben_rechts.x;
}
float rechteck::get_eckpunkt_oben_rechts_y()
{
    return eckpunkt_oben_rechts.y;
}
punkt rechteck::get_eckpunkt_oben_rechts()
{
    return eckpunkt_oben_rechts;
}
float rechteck::get_eckpunkt_oben_links_x()
{
    return eckpunkt_oben_links.x;
}
float rechteck::get_eckpunkt_oben_links_y()
{
    return eckpunkt_oben_links.y;
}
punkt rechteck::get_eckpunkt_oben_links()
{
    return eckpunkt_oben_links;
}
float rechteck::get_mittelpunkt_x()
{
    return mittelpunkt.x;
}
float rechteck::get_mittelpunkt_y()
{
    return mittelpunkt.y;
}
punkt rechteck::get_mittelpunkt()
{
    return mittelpunkt;
}
float rechteck::get_eckpunkt_links_mitte_x()
{
    return eckpunkt_links_mitte.x;
}
float rechteck::get_eckpunkt_links_mitte_y()
{
    return eckpunkt_links_mitte.y;
}
punkt rechteck::get_eckpunkt_links_mitte()
{
    return eckpunkt_links_mitte;
}
float rechteck::get_eckpunkt_rechts_mitte_x()
{
    return eckpunkt_rechts_mitte.x;
}
float rechteck::get_eckpunkt_rechts_mitte_y()
{
    return eckpunkt_rechts_mitte.y;
}
punkt rechteck::get_eckpunkt_rechts_mitte()
{
    return eckpunkt_rechts_mitte;
}
float rechteck::get_eckpunkt_oben_mitte_x()
{
    return eckpunkt_oben_mitte.x;
}
float rechteck::get_eckpunkt_oben_mitte_y()
{
    return eckpunkt_oben_mitte.y;
}
punkt rechteck::get_eckpunkt_oben_mitte()
{
    return eckpunkt_oben_mitte;
}
float rechteck::get_eckpunkt_unten_mitte_x()
{
    return eckpunkt_unten_mitte.x;
}
float rechteck::get_eckpunkt_unten_mitte_y()
{
    return eckpunkt_unten_mitte.y;
}
punkt rechteck::get_eckpunkt_unten_mitte()
{
    return eckpunkt_unten_mitte;
}


















