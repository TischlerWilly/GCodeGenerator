#ifndef RECHTECK3D_H
#define RECHTECK3D_H

#ifndef UNTEN_LINKS
#define UNTEN_LINKS     1
#endif
#ifndef UNTEN_RECHTS
#define UNTEN_RECHTS    2
#endif
#ifndef OBEN_RECHTS
#define OBEN_RECHTS     3
#endif
#ifndef OBEN_LINKS
#define OBEN_LINKS      4
#endif
#ifndef MITTE
#define MITTE           5
#endif
#ifndef LINKS
#define LINKS           6
#endif
#ifndef RECHTS
#define RECHTS          7
#endif
#ifndef OBEN
#define OBEN            8
#endif
#ifndef UNTEN
#define UNTEN           9
#endif

#include "darstellungsatribute.h"
#include "punkt3d.h"
#include "../eigeneFunktionen/geometrie.h"

class rechteck3d : public darstellungsatribute
{
public:
    rechteck3d();
    rechteck3d(QString geotext);

    inline  void    set_einfuegepunkt(punkt3d p)
    {
        einfuegepunkt = p;
    }
    inline  void    set_einfuegepunkt(double x, double y, double z)
    {
        einfuegepunkt.set_x(x);
        einfuegepunkt.set_y(y);
        einfuegepunkt.set_z(z);
    }
    inline  void    set_bezugspunkt(int nummer_des_punktes)
    {
        bezugspunkt = nummer_des_punktes;
    }
    inline  void    set_bezugspunkt(QString nummer_des_punktes)
    {
        bezugspunkt = nummer_des_punktes.toInt();
    }
            void    set_z(double z);
            void    set_laenge(double neue_laenge);
    inline  void    set_laenge(QString neue_laenge)
    {
        set_laenge(neue_laenge.toDouble());
    }
            void    set_breite(double neue_breite);
    inline  void    set_breite(QString neue_breite)
    {
        set_breite(neue_breite.toDouble());
    }
            void    set_rad(double neuer_radius);
    inline  void    set_rad(QString neuer_radius)
    {
        set_rad(neuer_radius.toDouble());
    }
            void    set_drewi(double neuer_drehwinkel);
    inline  void    set_drewi(QString neuer_drehwinkel)
    {
        set_drewi(neuer_drehwinkel.toDouble());
    }

            punkt3d bezpunkt();
    inline  int     bezpunkt_num()
    {
        return bezugspunkt;
    }
    inline  QString bezpunkt_num_qstring()
    {
        return int_to_qstring(bezugspunkt);
    }
    inline  punkt3d einfpunkt()
    {
        return einfuegepunkt;
    }
    inline  double  l()
    {
        return laenge;
    }
    inline  QString l_qstring()
    {
        return double_to_qstring(laenge);
    }
    inline  double  b()
    {
        return breite;
    }
    inline  QString b_qstring()
    {
        return double_to_qstring(breite);
    }
    inline  punkt3d obl(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return obli;
        }else
        {
            return drehen(mitte, obli, drehwinkel, true);
        }
    }
    inline  punkt3d ob(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return oben;
        }else
        {
            return drehen(mitte, oben, drehwinkel, true);
        }
    }
    inline  punkt3d obr(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return obre;
        }else
        {
            return drehen(mitte, obre, drehwinkel, true);
        }
    }
    inline  punkt3d li(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return links;
        }else
        {
            return drehen(mitte, links, drehwinkel, true);
        }
    }
    inline  punkt3d mi()
    {
        return mitte;
    }
    inline  punkt3d re(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return rechts;
        }else
        {
            return drehen(mitte, rechts, drehwinkel, true);
        }
    }
    inline  punkt3d unl(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return unli;
        }else
        {
            return drehen(mitte, unli, drehwinkel, true);
        }
    }
    inline  punkt3d un(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return unten;
        }else
        {
            return drehen(mitte, unten, drehwinkel, true);
        }
    }
    inline  punkt3d unr(bool ungedreht = true)
    {
        if(ungedreht)
        {
            return unre;
        }else
        {
            return drehen(mitte, unre, drehwinkel, true);
        }
    }
    inline  double  rad()
    {
        return radius;
    }
    inline  QString rad_qstring()
    {
        return double_to_qstring(radius);
    }
    inline  double  drewi()
    {
        return drehwinkel;
    }
    inline  QString drewi_qstring()
    {
        return double_to_qstring(drehwinkel);
    }

    void    verschieben_um(double xversatz, double yversatz);

private:
    punkt3d obli,   oben,   obre;
    punkt3d links,  mitte,  rechts;
    punkt3d unli,   unten,  unre;
    punkt3d einfuegepunkt;
    int bezugspunkt;
    double laenge, breite;
    double radius;
    double drehwinkel;



};

#endif // RECHTECK3D_H
