#ifndef KREIS_H
#define KREIS_H

#include "punkt3d.h"
#include "punkt2d.h"

class kreis
{
public:
    kreis();
    inline  kreis(punkt3d mittelpunkt, double radius, bool ist_ausgefuellt)
    {
        set_mittelpunkt(mittelpunkt);
        set_radius(radius);
        set_ausgefuellt(ist_ausgefuellt);
    }

    inline  void    set_mittelpunkt(punkt3d mittelpunkt)
    {
        mittelp = mittelpunkt;
    }
    inline  void    set_mittelpunkt(double x, double y, double z)
    {
        mittelp.set_x(x);
        mittelp.set_y(y);
        mittelp.set_z(z);
    }
    inline  void    set_radius(double radius)
    {
        rad = radius;
    }
    inline  void    set_ausgefuellt(bool ist_ausgefuellt)
    {
        ausgefuellt = ist_ausgefuellt;
    }

    inline  punkt3d     mitte3d()
    {
        return mittelp;
    }
    inline  punkt2d     mitte2d()
    {
        return punkt2d(mittelp.x(), mittelp.y());
    }
    inline  double      radius()
    {
        return rad;
    }
    inline  QString     radius_QString()
    {
        return double_to_qstring(rad);
    }
    inline  bool        ist_ausgefuellt()
    {
        return ausgefuellt;
    }
    inline  QString     ist_ausgefuellt_QString()
    {
        if(ausgefuellt == true)
        {
            return "ja";
        }else
        {
            return "nein";
        }
    }

private:
    punkt3d     mittelp;
    double      rad;
    bool        ausgefuellt;

};

#endif // KREIS_H
