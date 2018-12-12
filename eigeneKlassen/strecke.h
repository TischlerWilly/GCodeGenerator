#ifndef STRECKE_H
#define STRECKE_H

#include <QString>
#include <math.h>
#include <QMessageBox>
#include "punkt3d.h"
#include "punkt2d.h"
#include "darstellungsatribute.h"
#include "../eigeneFunktionen/geometrie.h"
#include "text_zeilenweise.h"
#include "../eigeneDefines/defines_geometrie.h"

enum strecke_bezugspunkt{strecke_bezugspunkt_start, \
                         strecke_bezugspunkt_mitte, \
                         strecke_bezugspunkt_ende};

class strecke : public darstellungsatribute
{
public:
    strecke();
    strecke(QString geotext);
            void    set_start(punkt3d startpunkt);
            void    set_ende(punkt3d endpunkt);
            void    richtung_unkehren();
            void    drenen_um_startpunkt_2d(float drehwinkel, \
                                             bool drehrichtung_im_uhrzeigersinn);
            void    drenen_um_endpunkt_2d(float drehwinkel, \
                                             bool drehrichtung_im_uhrzeigersinn);
            void    drenen_um_mittelpunkt_2d(float drehwinkel, \
                                             bool drehrichtung_im_uhrzeigersinn);
            void    set_laenge_2d(float neue_laenge, \
                       strecke_bezugspunkt bezugspunkt = strecke_bezugspunkt_mitte);
            void    verschieben_um(double xversatz, double yversatz);


    inline punkt3d startp()
    {
        return start;
    }
    inline punkt3d endp()
    {
        return ende;
    }  
    inline double laenge3dim()
    {
        return laenge3d;
    }
    inline double laenge2dim()
    {
        return laenge2d;
    }
    inline QString laenge3dim_QString()
    {
        return float_to_qstring(laenge3d);
    }
    inline QString laenge2dim_QString()
    {
        return float_to_qstring(laenge2d);
    }

    punkt3d get_mittelpunkt3d();
    punkt2d get_mittelpunkt2d();

    QString get_text();

private:
    punkt3d start, ende;
    double laenge3d, laenge2d;

    void laenge_berechnen();



};

#endif // STRECKE_H
