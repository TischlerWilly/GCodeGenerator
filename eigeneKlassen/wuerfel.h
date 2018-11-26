#ifndef WUERFEL_H
#define WUERFEL_H

#include "rechteck3d.h"

class wuerfel : public rechteck3d
{
public:
    wuerfel();
    wuerfel(QString geotext);
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

#endif // WUERFEL_H
