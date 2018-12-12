#include "punkt3d.h"

punkt3d::punkt3d()
{
    set_x(0);
    set_y(0);
    set_z(0);
}
punkt3d::punkt3d(QString geotext)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(TRZ_PA_);
    tz.set_text(geotext);
    set_x(tz.zeile(2).toDouble());
    set_y(tz.zeile(3).toDouble());
    set_z(tz.zeile(4).toDouble());
    set_farbe(tz.zeile(5));
    set_linienbreite(tz.zeile(6).toInt());
}

void punkt3d::verschieben_um(double xversatz, double yversatz)
{
    x_param += xversatz;
    y_param += yversatz;
}

//-------------------Funktionen nicht innerhalb der Klasse:
punkt3d operator +(punkt3d p1, punkt3d p2)
{
    punkt3d p3;
    p3.set_x(p1.x() + p2.x());
    p3.set_y(p1.y() + p2.y());
    p3.set_z(p1.z() + p2.z());
    return p3;
}

punkt3d operator -(punkt3d p1, punkt3d p2)
{
    punkt3d p3;
    p3.set_x(p1.x() - p2.x());
    p3.set_y(p1.y() - p2.y());
    p3.set_z(p1.z() - p2.z());
    return p3;
}

punkt3d operator *(punkt3d p1, double fakror)
{
    punkt3d p2;
    p2.set_x(p1.x() * fakror);
    p2.set_y(p1.y() * fakror);
    p2.set_z(p1.z() * fakror);
    return p2;
}

punkt3d operator *(double fakror, punkt3d p1)
{
    punkt3d p2;
    p2.set_x(p1.x() * fakror);
    p2.set_y(p1.y() * fakror);
    p2.set_z(p1.z() * fakror);
    return p2;
}

punkt3d operator /(punkt3d p1, double divisor)
{
    punkt3d p2;
    p2.set_x(p1.x() / divisor);
    p2.set_y(p1.y() / divisor);
    p2.set_z(p1.z() / divisor);
    return p2;
}

bool operator ==(punkt3d p1, punkt3d p2)
{
    bool returnbool = true;
    if(p1.x() != p2.x())
    {
        returnbool = false;
    }
    if(p1.y() != p2.y())
    {
        returnbool = false;
    }
    if(p1.z() != p2.z())
    {
        returnbool = false;
    }
    return returnbool;
}

bool operator !=(punkt3d p1, punkt3d p2)
{
    bool returnbool = true;
    if(p1.x() != p2.x())
    {
        returnbool = false;
    }
    if(p1.y() != p2.y())
    {
        returnbool = false;
    }
    if(p1.z() != p2.z())
    {
        returnbool = false;
    }
    if(returnbool == true)
    {
        return false;
    }else
    {
        return true;
    }
}







