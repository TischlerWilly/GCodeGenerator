#include "geometrie.h"

punkt drehen(punkt drehzentrum, punkt alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.x = drehzentrum.x + (alter_punkt.x - drehzentrum.x)\
                *cos_d(drehwinkel) - (alter_punkt.y - drehzentrum.y)*sin_d(drehwinkel);
        neuer_punkt.y = drehzentrum.y + (alter_punkt.x - drehzentrum.x)\
                *sin_d(drehwinkel) + (alter_punkt.y - drehzentrum.y)*cos_d(drehwinkel);
        return neuer_punkt;
    }
}

punkt2d drehen(punkt2d drehzentrum, punkt2d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt2d neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.set_x(\
                           drehzentrum.x() + (alter_punkt.x() - drehzentrum.x())\
                           *cos_d(drehwinkel) - (alter_punkt.y() - drehzentrum.y())\
                           *sin_d(drehwinkel)\
                           );
        neuer_punkt.set_y(\
                          drehzentrum.y() + (alter_punkt.x() - drehzentrum.x())\
                          *sin_d(drehwinkel) + (alter_punkt.y() - drehzentrum.y())\
                          *cos_d(drehwinkel)\
                          );
        return neuer_punkt;
    }
}

punkt3d drehen(punkt3d drehzentrum, punkt3d alter_punkt, \
             float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt3d neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.set_x(\
                           drehzentrum.x() + (alter_punkt.x() - drehzentrum.x())\
                           *cos_d(drehwinkel) - (alter_punkt.y() - drehzentrum.y())\
                           *sin_d(drehwinkel)\
                           );
        neuer_punkt.set_y(\
                          drehzentrum.y() + (alter_punkt.x() - drehzentrum.x())\
                          *sin_d(drehwinkel) + (alter_punkt.y() - drehzentrum.y())\
                          *cos_d(drehwinkel)\
                          );
        return neuer_punkt;
    }
}
punkt drehen_ij(punkt drehzentrum, float drehwinkel, bool drehrichtung_im_uhrzeigersinn, \
                punkt bezugspunkt_ij, punkt punkt_ij)
{
    if(drehwinkel == 0)
    {
        return punkt_ij;
    }else{
        bezugspunkt_ij = drehen(drehzentrum, bezugspunkt_ij, \
                                drehwinkel, drehrichtung_im_uhrzeigersinn);
        punkt p;
        p.x = 0;
        p.y = 0;
        punkt_ij = drehen(p, punkt_ij, drehwinkel, drehrichtung_im_uhrzeigersinn);
        return punkt_ij;
    }
}

double winkel(double endpunkt_x, double endpunkt_y,\
              double mittelpunkt_x, double mittelpunkt_y)
{
    //berechnet wird immer der Winkel zur gedachten waagerechten Grundlinie
    //im Gegenuhrzeigersinn
    punkt3d mipu;
    mipu.set_x(mittelpunkt_x);
    mipu.set_y(mittelpunkt_y);
    punkt3d enpu;
    enpu.set_x(endpunkt_x);
    enpu.set_y(endpunkt_y);
    strecke s;
    s.set_start(mipu);
    s.set_ende(enpu);

    double hypthenuse = s.laenge2dim();
    double gegenkathete = mittelpunkt_y - endpunkt_y;

    double wi =  asin(gegenkathete/hypthenuse)/M_PI*180*-1;//Weil sonst Ergebnis in Bogenmaß;

    if(endpunkt_x - mittelpunkt_x < 0   &&\
       wi > 0)
    {
        wi = 180-wi;
    }

    if(endpunkt_x - mittelpunkt_x < 0   &&\
       wi < 0)
    {
        wi = 180-wi;
    }else if(mittelpunkt_x - endpunkt_x < 0   &&\
             wi < 0)
    {
        wi = 360+wi;
    }else if(wi == 0)
    {
        if(mittelpunkt_x < endpunkt_x)
        {
            wi = 0;
        }else
        {
            wi = 180;
        }
    }
    if(wi == -90)
    {
        wi = 270;
    }

    return wi;
}

double winkel(double endpunkt1_x, double endpunkt1_y,\
              double mittelpunkt_x, double mittelpunkt_y,\
              double endpunkt2_x, double endpunkt2_y)
{
    double w1 = winkel(endpunkt1_x, endpunkt1_y,\
                       mittelpunkt_x, mittelpunkt_y);

    double w2 = winkel(endpunkt2_x, endpunkt2_y,\
                       mittelpunkt_x, mittelpunkt_y);
    if(w2 == 0)
    {
        w2=360;
    }
    return w2-w1;
}

void trimmen(QString *geo1, QString *geo2)
{
    //die Funktion kann derzeit nur Strecken trimmen!

    QString a = *geo1;
    QString b = *geo2;
    if(a.contains(STRECKE) && b.contains(STRECKE))
    {
        strecke s1(a);
        strecke s2(b);

        if(s1.endp() == s2.startp())
        {
            return;
        }

        punkt3d schnittpunkt;
        schnittpunkt.set_z(s1.endp().z());
        //Schnittpunkt der beiden Geraden berechnen:
        if(s1.startp().x()!=s1.endp().x()  &&  s2.startp().x()!=s2.endp().x())//sonst div/0 möglich
        {
            //Geradengleichungen aufstellen y = m*x + t:
            //m = (y2-y1):(x2-x1)
            double m1 = (  s1.endp().y()-s1.startp().y()  )  /  (  s1.endp().x()-s1.startp().x()  );
            double m2 = (  s2.endp().y()-s2.startp().y()  )  /  (  s2.endp().x()-s2.startp().x()  );
            //t = y1 - (m1*x1)
            double t1 = s1.startp().y()  -  (m1*s1.startp().x());
            double t2 = s2.startp().y()  -  (m2*s2.startp().x());
            //Geradengleichungen gleichsetzen:
            //m1*x+t1 = m2*x+t2     /-m2*x
            //(m1-m2)*x+t1 = t2     /-t1
            //(m1-m2)*x = t2-t1     / :(m1-m2)
            //x = (t2-t1):(m1-m2)
            double x = (t2-t1)/(m1-m2);
            //x in eine der beiden Gleichungen einsetzen:
            double y = m1*x+t1;

            schnittpunkt.set_x(x);
            schnittpunkt.set_y(y);
            s1.set_ende(schnittpunkt);
            s2.set_start(schnittpunkt);
        }else
        {
            if(s1.startp().x()==s1.endp().x()  &&  s2.startp().x()!=s2.endp().x())//s1 ist senkrecht
            {
                //heißt x von s1 ist bekannt
                //Geradengleichungen aufstellen für s2     y = m*x + t:
                double m = (  s2.endp().y()-s2.startp().y()  )  /  (  s2.endp().x()-s2.startp().x()  );
                //t = y1 - (m*x)
                double t = s2.startp().y()  -  (m*s2.startp().x());
                double x = s1.startp().x();
                //x in die Gleichung einsetzen:
                double y = m*x+t;

                schnittpunkt.set_x(x);
                schnittpunkt.set_y(y);
                s1.set_ende(schnittpunkt);
                s2.set_start(schnittpunkt);
            }else if(s1.startp().x()!=s1.endp().x()  &&  s2.startp().x()==s2.endp().x())//s2 ist senkrecht
            {
                //heißt x von s2 ist bekannt
                //Geradengleichungen aufstellen für s1     y = m*x + t:
                double m = (  s1.endp().y()-s1.startp().y()  )  /  (  s1.endp().x()-s1.startp().x()  );
                //t = y - (m*x)
                double t = s1.startp().y()  -  (m*s1.startp().x());
                double x = s2.startp().x();
                //x in die Gleichung einsetzen:
                double y = m*x+t;

                schnittpunkt.set_x(x);
                schnittpunkt.set_y(y);
                s1.set_ende(schnittpunkt);
                s2.set_start(schnittpunkt);
            }else
            {
                //beide geraden sind senkrecht
                //soetwas sollte nicht an die Funktion übergeben werden
            }
        }

        //Werte zurück in die geo-QStrings schreiben:
        *geo1 = s1.get_text();
        *geo2 = s2.get_text();

        //QMessageBox mb;
        //mb.setText("m1: " + double_to_qstring(m1) + "\nm2: " + double_to_qstring(m2));
        //mb.exec();
    }else if(a.contains(STRECKE) && b.contains(BOGEN))
    {
        strecke s(a);
        bogen b(b);

        //Kreisformel aufstellen:
        //  mx = Kreismittelpunkt X-Wert
        //  my = Kreismittelpunkt Y-Wert
        //  r  = Kreisradius
        //  (x-mx)²+(y-my)²=r²
        double mx = b.mitte().x();
        double my = b.mitte().y();
        double r  = b.rad();

        //Geradenformel aufstellen:
        //  y = m*x+n
        //  m = (y2-y1)/(x2-x1) =Steigung
        //    x1 = X-Wert der vom Startpunkt der Strecke
        //    x2 = X-Wert der vom Endpunkt der Strecke
        //    y1 = Y-Wert der vom Startpunkt der Strecke
        //    y2 = Y-Wert der vom Endpunkt der Strecke
        double x1= s.startp().x();
        double x2= s.endp().x();
        double y1= s.startp().y();
        double y2= s.endp().y();
        double m = (y2-y1)/(x2-x1);
        //  n = Länge -->N bekommt man raus indem man m in die Geradenformel einsetzt
        //               mit den Werten von einem der Punkte
        //    y1 = m*x1+n   /-m*x1
        //    n = y1-m*x1
        double n = y1-m*x1;

        //Geradenformel in Kreisformel einsetzen:
        //  (x-mx)²+(   y   -my)²=r²
        //  (x-mx)²+((m*x+n)-my)²=r²

        //Lösung mit ABC-Formel eritteln:
        //  allgemeine Form:
        //  a*x² + b*x + c = 0
        //    Formel Umstellen:
        //    (x-mx)²+((m*x+n)-my)² = r²    //Wurzel ziehen??







        //Werte zurück in die geo-QStrings schreiben:
        *geo1 = s.get_text();
        //*geo2 = b.get_text();

    }else if(a.contains(BOGEN) && b.contains(STRECKE))
    {

    }


}
