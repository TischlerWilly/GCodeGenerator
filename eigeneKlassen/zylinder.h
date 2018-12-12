#ifndef ZYLINDER_H
#define ZYLINDER_H

#include "kreis.h"

class zylinder : public kreis
{
public:
    zylinder();
    zylinder(QString geotext);
    inline  zylinder(punkt3d mittelpunkt, double radius, double zylinderhoehe)
    {
        set_mittelpunkt(mittelpunkt);
        set_radius(radius);
        set_hoehe(zylinderhoehe);
    }
    inline  void    set_hoehe(double neue_hoehe)
    {
        hoehe = neue_hoehe;
    }
    inline  void    set_hoehe(QString neue_hoehe)
    {
        hoehe = neue_hoehe.toDouble();
    }

    inline  double  get_hoehe()
    {
        return hoehe;
    }
    inline  QString get_hoehe_qstring()
    {
        return double_to_qstring(hoehe);
    }

private:
    double hoehe;
};

#endif // ZYLINDER_H
