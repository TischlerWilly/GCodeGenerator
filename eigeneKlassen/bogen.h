#ifndef BOGEN_H
#define BOGEN_H

#include "punkt3d.h"
#include "punkt2d.h"
#include "strecke.h"
#include "darstellungsatribute.h"


class bogen : public darstellungsatribute
{
public:
    bogen();
    bogen(QString geotext);
    bogen(punkt3d startpunkt, punkt3d endpunkt);
    bogen(punkt3d startpunkt, punkt3d endpunkt, float radiuswert, bool im_uhrzeigersinn);
    bogen(punkt2d mipu, double rad, double startwinkel, double endwinkel);

    void set_startpunkt(punkt3d startpunkt);
    void set_endpunkt(punkt3d endpunkt);
    void set_radius(float radiuswert, bool im_uhrzeigersinn);
    inline void set_radius(QString radiuswert, bool im_uhrzeigersinn)
    {
        set_radius(radiuswert.toFloat(), im_uhrzeigersinn);
    }
    void set_radius(float radiuswert, punkt2d bogenrichtung);

    inline punkt3d start()
    {
        return startp;
    }
    inline punkt3d ende()
    {
        return endp;
    }
    inline punkt2d mitte()
    {
        if(fehler == false)
        {
            return mittelp;
        }else
        {
            punkt2d tmp;
            tmp.set_x(0);
            tmp.set_y(0);
            return tmp;
        }

    }
    inline double rad()
    {
        return radius;
    }
    inline QString rad_qString()
    {
        return double_to_qstring(radius);
    }
    inline bool im_uzs()
    {
        return bogen_im_uzs;
    }
    inline QString im_uzs_QString()
    {
        if(bogen_im_uzs == true)
        {
            return "ja";
        }else
        {
            return "nein";
        }
    }
    inline punkt2d mittelpunkt()
    {
        if(!fehler)
        {
            return mittelp;
        }else
        {
            punkt2d p;
            p.set_x(0);
            p.set_y(0);
            return p;
        }
    }
    inline bool hat_fehler()
    {
        return fehler;
    }
    inline QString  fehlermeldung()
    {
        return fehlertext;
    }

    QString get_text();

private:
    punkt3d startp, endp;
    double radius;
    bool bogen_im_uzs; //Bogen im Uhrzeigersinn

    punkt2d mittelp;
    bool fehler;
    QString fehlertext;



};

#endif // BOGEN_H
