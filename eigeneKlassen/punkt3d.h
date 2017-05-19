#ifndef PUNKT3D_H
#define PUNKT3D_H

#include <QString>
#include "../eigeneFunktionen/umwandeln.h"
#include "darstellungsatribute.h"

class punkt3d : public darstellungsatribute
{
public:
            punkt3d();
    inline  punkt3d(double x, double y, double z)
    {
        x_param = x;
        y_param = y;
        z_param = z;
    }

    inline  void    set_x(double wert)
    {
        x_param = wert;
    }
    inline  void    set_y(double wert)
    {
        y_param = wert;
    }
    inline  void    set_z(double wert)
    {
        z_param = wert;
    }
    inline  void    set_x(QString wert)
    {
        x_param = wert.toDouble();
    }
    inline  void    set_y(QString wert)
    {
        y_param = wert.toDouble();
    }
    inline  void    set_z(QString wert)
    {
        z_param = wert.toDouble();
    }

    inline  double  x()
    {
        return x_param;
    }
    inline  double  y()
    {
        return y_param;
    }
    inline  double  z()
    {
        return z_param;
    }
    inline  QString x_QString()
    {
        return double_to_qstring(x_param);
    }
    inline  QString y_QString()
    {
        return double_to_qstring(y_param);
    }
    inline  QString z_QString()
    {
        return double_to_qstring(z_param);
    }

private:
    double  x_param, y_param, z_param;
};

//-------------------Funktionen nicht innerhalb der Klasse:
punkt3d operator +(punkt3d p1, punkt3d p2);
punkt3d operator -(punkt3d p1, punkt3d p2);
punkt3d operator *(punkt3d p1, double faktor);
punkt3d operator *(double faktor, punkt3d p1);
punkt3d operator /(punkt3d p1, double divisor);
bool operator ==(punkt3d p1, punkt3d p2);
bool operator !=(punkt3d p1, punkt3d p2);

#endif // PUNKT3D_H
