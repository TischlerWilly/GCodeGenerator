#include "punkt2d.h"

punkt2d::punkt2d()
{
    set_x(0);
    set_y(0);
}

punkt2d::punkt2d(punkt3d p)
{
    set_x(p.x());
    set_y(p.y());
}

//-------------------Funktionen nicht innerhalb der Klasse:
punkt2d operator +(punkt2d p1, punkt2d p2)
{
    punkt2d p3;
    p3.set_x(p1.x() + p2.x());
    p3.set_y(p1.y() + p2.y());
    return p3;
}

punkt2d operator -(punkt2d p1, punkt2d p2)
{
    punkt2d p3;
    p3.set_x(p1.x() - p2.x());
    p3.set_y(p1.y() - p2.y());
    return p3;
}

punkt2d operator *(punkt2d p1, double fakror)
{
    punkt2d p2;
    p2.set_x(p1.x() * fakror);
    p2.set_y(p1.y() * fakror);
    return p2;
}

punkt2d operator *(double fakror, punkt2d p1)
{
    punkt2d p2;
    p2.set_x(p1.x() * fakror);
    p2.set_y(p1.y() * fakror);
    return p2;
}

punkt2d operator /(punkt2d p1, double divisor)
{
    punkt2d p2;
    p2.set_x(p1.x() / divisor);
    p2.set_y(p1.y() / divisor);
    return p2;
}

bool operator ==(punkt2d p1, punkt2d p2)
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
    return returnbool;
}

bool operator !=(punkt2d p1, punkt2d p2)
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
    if(returnbool == true)
    {
        return false;
    }else
    {
        return true;
    }
}







