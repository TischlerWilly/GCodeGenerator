#ifndef PUNKT2D_H
#define PUNKT2D_H

#include <QString>
#include "../eigeneFunktionen/umwandeln.h"
#include "punkt3d.h"
#include "darstellungsatribute.h"

class punkt2d : public darstellungsatribute
{
public:
    punkt2d();
    inline  punkt2d(double x, double y)
    {
        x_param = x;
        y_param = y;
    }
            punkt2d(punkt3d p);

    inline  void    set_x(double wert)
    {
        x_param = wert;
    }
    inline  void    set_y(double wert)
    {
        y_param = wert;
    }
    inline  void    set_x(QString wert)
    {
        x_param = wert.toDouble();
    }
    inline  void    set_y(QString wert)
    {
        y_param = wert.toDouble();
    }

    inline  double  x()
    {
        return x_param;
    }
    inline  double  y()
    {
        return y_param;
    }
    inline  QString x_QString()
    {
        return double_to_qstring(x_param);
    }
    inline  QString y_QString()
    {
        return double_to_qstring(y_param);
    }

private:
    double  x_param, y_param;

};

//-------------------Funktionen nicht innerhalb der Klasse:
punkt2d operator +(punkt2d p1, punkt2d p2);
punkt2d operator -(punkt2d p1, punkt2d p2);
punkt2d operator *(punkt2d p1, double faktor);
punkt2d operator *(double faktor, punkt2d p1);
punkt2d operator /(punkt2d p1, double divisor);
bool operator ==(punkt2d p1, punkt2d p2);
bool operator !=(punkt2d p1, punkt2d p2);

#endif // PUNKT2D_H
