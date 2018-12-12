#ifndef KREIS_H
#define KREIS_H

#include "punkt3d.h"
#include "punkt2d.h"
#include "darstellungsatribute.h"
#include "../eigeneDefines/defines_geometrie.h"
#include "../eigeneKlassen/text_zeilenweise.h"

class kreis : public darstellungsatribute
{
public:
    kreis();
    kreis(QString geotext);
    inline  kreis(punkt3d mittelpunkt, double radius)
    {
        set_mittelpunkt(mittelpunkt);
        set_radius(radius);
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
    inline  void    set_radius(QString radius)
    {
        rad = radius.toDouble();
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

    void    verschieben_um(double xversatz, double yversatz);

    QString get_text();

private:
    punkt3d     mittelp;
    double      rad;

};

#endif // KREIS_H
