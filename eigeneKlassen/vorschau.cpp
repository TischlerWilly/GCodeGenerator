#include "vorschau.h"

vorschau::vorschau(QWidget *parent) :
    QWidget(parent)
{
    this->resize(500, 500);
    this->setWindowTitle("Vorschau");
    wstd.set_bezugspunkt_nummer(MITTE);
    wstd.set_einfuegepunkt(width()/2 , height()/2);
    t.warnungen_einschalten(false);
    this->setMouseTracking(true);
    zf = 1;
    npv.x = 0;
    npv.y = 0;
    mrg = false;
    this->setCursor(Qt::CrossCursor);
}


void vorschau::paintEvent(QPaintEvent *)
{
    werkstueck_darstellung_berechnen();
    QPainter painter(this);

    //Hintergrund:
    painter.setBrush( Qt::white);
    painter.setPen(Qt::black);
    painter.drawRect(0, 0, width(), height());

    //Maschine darstellen:
    text_zeilenweise geotext = t.get_maschinengeo().get_text_zeilenweise();
    for(uint i=1;i<=geotext.zeilenanzahl();i++)
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(geotext.zeile(i));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneGeotext(spalten.zeile(ii), 0);
        }
    }

    //Bearbeitungen darstellen:
    geotext = t.get_geo().get_text_zeilenweise();
    for(uint i=1;i<=geotext.zeilenanzahl();i++)
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(geotext.zeile(i));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneGeotext(spalten.zeile(ii), i);
        }
    }

    //Fräskontur darstellen:
    text_zeilenweise fkontext = t.get_fkon().get_text_zeilenweise();
    for(uint i=1;i<=fkontext.zeilenanzahl();i++)
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(fkontext.zeile(i));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneFkon(spalten.zeile(ii), i);
        }
    }

    //Fräser darstellen:
    text_zeilenweise fraeserdarsttext = t.get_fraeserdarst().get_text_zeilenweise();
    for(uint i=1;i<=fraeserdarsttext.zeilenanzahl();i++)
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(fraeserdarsttext.zeile(i));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneGeotext(spalten.zeile(ii), i);
        }
    }

    //Aktuelle Zeile noch einmal rot überzeichen, da bereits wieder überdeckt
    //durch deckungsgleiche Elemente in späteren Zeilen:
    if(aktuelle_zeilennummer <= geotext.zeilenanzahl() && \
            !t.get_klartext_zeilenweise().zeile(aktuelle_zeilennummer).contains(PROGRAMMKOPF_DIALOG))
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(geotext.zeile(aktuelle_zeilennummer));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneGeotext(spalten.zeile(ii), aktuelle_zeilennummer);
        }
    }
    if(aktuelle_zeilennummer <= fkontext.zeilenanzahl() && \
            !t.get_klartext_zeilenweise().zeile(aktuelle_zeilennummer).contains(PROGRAMMKOPF_DIALOG))
    {
        text_zeilenweise spalten;
        spalten.set_trennzeichen(TRZ_EL_);
        spalten.set_text(fkontext.zeile(aktuelle_zeilennummer));

        for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
        {
            zeichneFkon(spalten.zeile(ii), aktuelle_zeilennummer);
        }
    }
}

void vorschau::zeichneGeotext(QString geometrieElement, uint i)
{
    QPainter painter(this);
    painter.setBrush( Qt::white);
    painter.setPen(Qt::black);

    text_zeilenweise element;
    element.set_trennzeichen(TRZ_PA_);
    element.set_text(geometrieElement);

    if(element.get_text().contains(PUNKT))
    {
        punkt2d p2;
        p2.set_x(element.zeile(2).toDouble()*sf*zf);
        p2.set_y(element.zeile(3).toDouble()*sf*zf);
        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(6).toInt());
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(5)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);
        painter.drawPoint(n.x-npv.x+p2.x(), \
                          n.y-npv.y-p2.y());
        painter.setPen(pen_alt);
    }else if(element.get_text().contains(STRECKE))
    {
        punkt2d startpunkt, endpunkt;
        startpunkt.set_x(element.zeile(2).toDouble()*sf*zf);
        startpunkt.set_y(element.zeile(3).toDouble()*sf*zf);
        endpunkt.set_x(element.zeile(5).toDouble()*sf*zf);
        endpunkt.set_y(element.zeile(6).toDouble()*sf*zf);

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(9).toInt());
        pen.setStyle(set_linienstil(element.zeile(10)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(8)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        painter.drawLine(n.x-npv.x+startpunkt.x(), \
                         n.y-npv.y-startpunkt.y(), \
                         n.x-npv.x+endpunkt.x(), \
                         n.y-npv.y-endpunkt.y());

        painter.setPen(pen_alt);
    }else if(element.get_text().contains(BOGEN))
    {
        double rad = element.zeile(8).toDouble()*sf*zf;
        punkt2d mipu;
        mipu.set_x(element.zeile(10).toDouble()*sf*zf);//Mittelpunkt in X
        mipu.set_y(element.zeile(11).toDouble()*sf*zf);//Mittelpunkt in Y
        punkt2d obli;
        obli.set_x(mipu.x()-rad);
        obli.set_y(mipu.y()+rad);

        punkt2d mp;
        mp.set_x(element.zeile(10).toDouble());//Mittelpunkt in X
        mp.set_y(element.zeile(11).toDouble());//Mittelpunkt in Y
        punkt2d sp;
        sp.set_x(element.zeile(2).toDouble());//Start in X
        sp.set_y(element.zeile(3).toDouble());//Start in Y
        punkt2d ep;
        ep.set_x(element.zeile(5).toDouble());//Ende in X
        ep.set_y(element.zeile(6).toDouble());//Ende in Y
        double stawi=0, bogwi=0;

        if(element.zeile(9) == "nein")//Bogen gegen den Uhrzeigersinn
        {
            stawi = winkel(sp.x(),   \
                           sp.y(),   \
                           mp.x(),   \
                           mp.y());
            bogwi = winkel(sp.x(),   \
                           sp.y(),   \
                           mp.x(),   \
                           mp.y(),   \
                           ep.x(),   \
                           ep.y());
        }else//Bogen im Uhrzeigersinn
        {
            stawi = winkel(ep.x(),   \
                           ep.y(),   \
                           mp.x(),   \
                           mp.y());
            bogwi = winkel(ep.x(),   \
                           ep.y(),   \
                           mp.x(),   \
                           mp.y(),   \
                           sp.x(),   \
                           sp.y());
        }
        if(bogwi<0)
        {
            bogwi = 360+bogwi;
        }

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(13).toInt());
        pen.setStyle(set_linienstil(element.zeile(14)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(12)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        painter.drawArc(n.x-npv.x+obli.x(),\
                        n.y-npv.y-obli.y(),\
                        rad*2,\
                        rad*2,\
                        stawi*16,\
                        bogwi*16);

        painter.setPen(pen_alt);
    }else if(element.get_text().contains(KREIS))
    {
        double rad = element.zeile(5).toDouble()*sf*zf;
        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(8).toInt());
        pen.setStyle(set_linienstil(element.zeile(9)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(6)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        QBrush brush = painter.brush();
        QBrush brush_alt = painter.brush();
        brush.setColor(set_farbe(element.zeile(7)));
        painter.setBrush(brush);

        painter.drawEllipse(n.x-npv.x+(element.zeile(2).toDouble()*sf*zf)-rad,\
                            n.y-npv.y-(element.zeile(3).toDouble()*sf*zf)-rad,\
                            rad*2,\
                            rad*2);

        painter.setPen(pen_alt);
        painter.setBrush(brush_alt);
    }else if(element.get_text().contains(ZYLINDER))
    {
        double rad = element.zeile(5).toDouble()*sf*zf;
        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(9).toInt());
        pen.setStyle(set_linienstil(element.zeile(10)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(7)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        QBrush brush = painter.brush();
        QBrush brush_alt = painter.brush();
        brush.setColor(set_farbe(element.zeile(8)));
        painter.setBrush(brush);

        painter.drawEllipse(n.x-npv.x+(element.zeile(2).toDouble()*sf*zf)-rad,\
                            n.y-npv.y-(element.zeile(3).toDouble()*sf*zf)-rad,\
                            rad*2,\
                            rad*2);

        painter.setPen(pen_alt);
        painter.setBrush(brush_alt);
    }else if(element.get_text().contains(RECHTECK3D))
    {
        rechteck3d r;
        int bezpunkt = element.zeile(2).toInt();
        if(bezpunkt == UNTEN_LINKS)
        {
            bezpunkt = OBEN_LINKS;
        }else if(bezpunkt == UNTEN)
        {
            bezpunkt = OBEN;
        }else if(bezpunkt == UNTEN_RECHTS)
        {
            bezpunkt = OBEN_RECHTS;
        }else if(bezpunkt == OBEN_LINKS)
        {
            bezpunkt = UNTEN_LINKS;
        }else if(bezpunkt == OBEN)
        {
            bezpunkt = UNTEN;
        }else if(bezpunkt == OBEN_RECHTS)
        {
            bezpunkt = UNTEN_RECHTS;
        }
        r.set_bezugspunkt(bezpunkt);
        r.set_einfuegepunkt(n.x-npv.x+element.zeile(3).toDouble()*sf*zf,\
                            n.y-npv.y-element.zeile(4).toDouble()*sf*zf,\
                            element.zeile(5).toDouble()*sf*zf);
        r.set_laenge(element.zeile(6).toDouble()*sf*zf);
        r.set_breite(element.zeile(7).toDouble()*sf*zf);
        r.set_rad(element.zeile(8).toDouble()*sf*zf);
        r.set_drewi(element.zeile(9).toDouble());

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(12).toInt());
        pen.setStyle(set_linienstil(element.zeile(13)));
        pen.setCapStyle(Qt::RoundCap);
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(10)));
        }
        painter.setPen(pen);

        QBrush brush = painter.brush();
        QBrush brush_alt = painter.brush();
        brush.setColor(set_farbe(element.zeile(11)));
        painter.setBrush(brush);

        if(r.rad()==0)
        {
            //Rechteck mit eckigen Ecken:
            QPainterPath pp;
            pp.moveTo(r.unl(false).x(),\
                      r.unl(false).y());
            pp.lineTo(r.unr(false).x(),\
                      r.unr(false).y());
            pp.lineTo(r.obr(false).x(),\
                      r.obr(false).y());
            pp.lineTo(r.obl(false).x(),\
                      r.obl(false).y());
            pp.closeSubpath();
            painter.drawPath(pp);

        }else
        {
            //Rechteck runden Ecken:
            punkt2d mitpu = r.mi();
            //mitpu.set_y(mitpu.y()-r.b());
            QPainterPath pp;

            punkt2d p2;
            //Startpunkt:
            p2.set_x(r.unl().x());
            p2.set_y((r.mi().y()+r.b()/2)-r.rad());
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.moveTo(p2.x(), p2.y());
            //Rundung links unten:
            p2.set_x(r.unl().x());
            p2.set_y((r.mi().y()+r.b()/2)-r.rad()*2);
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 180+r.drewi(), 90);
            //Linie nach rechts unten:
            p2.set_x(r.unr().x()-r.rad());
            p2.set_y((r.mi().y()+r.b()/2));
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung rechts unten:
            p2.set_x(r.unr().x()-r.rad()*2);
            p2.set_y((r.mi().y()+r.b()/2)-r.rad()*2);
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 270+r.drewi(), 90);
            //Linie nach rechts oben:
            p2.set_x(r.obr().x());
            p2.set_y((r.mi().y()-r.b()/2)+r.rad());
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung rechts oben
            p2.set_x(r.unr().x()-r.rad()*2);
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 0+r.drewi(), 90);
            //Linie nach links oben:
            p2.set_x(r.obl().x()+r.rad());
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung links oben
            p2.set_x(r.obl().x());
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 90+r.drewi(), 90);

            pp.closeSubpath();
            painter.drawPath(pp);
        }

        painter.setPen(pen_alt);
        painter.setBrush(brush_alt);
    }else if(element.get_text().contains(WUERFEL))
    {
        rechteck3d r;
        int bezpunkt = element.zeile(2).toInt();
        if(bezpunkt == UNTEN_LINKS)
        {
            bezpunkt = OBEN_LINKS;
        }else if(bezpunkt == UNTEN)
        {
            bezpunkt = OBEN;
        }else if(bezpunkt == UNTEN_RECHTS)
        {
            bezpunkt = OBEN_RECHTS;
        }else if(bezpunkt == OBEN_LINKS)
        {
            bezpunkt = UNTEN_LINKS;
        }else if(bezpunkt == OBEN)
        {
            bezpunkt = UNTEN;
        }else if(bezpunkt == OBEN_RECHTS)
        {
            bezpunkt = UNTEN_RECHTS;
        }
        r.set_bezugspunkt(bezpunkt);
        r.set_einfuegepunkt(n.x-npv.x+element.zeile(3).toDouble()*sf*zf,\
                            n.y-npv.y-element.zeile(4).toDouble()*sf*zf,\
                            element.zeile(5).toDouble()*sf*zf);
        r.set_laenge(element.zeile(6).toDouble()*sf*zf);
        r.set_breite(element.zeile(7).toDouble()*sf*zf);
        r.set_rad(element.zeile(8).toDouble()*sf*zf);
        r.set_drewi(element.zeile(9).toDouble());

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(13).toInt());
        pen.setStyle(set_linienstil(element.zeile(14)));
        pen.setCapStyle(Qt::RoundCap);
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(11)));
        }
        painter.setPen(pen);

        QBrush brush = painter.brush();
        QBrush brush_alt = painter.brush();
        brush.setColor(set_farbe(element.zeile(12)));
        painter.setBrush(brush);

        if(r.rad()==0)
        {
            //Rechteck mit eckigen Ecken:
            QPainterPath pp;
            pp.moveTo(r.unl(false).x(),\
                      r.unl(false).y());
            pp.lineTo(r.unr(false).x(),\
                      r.unr(false).y());
            pp.lineTo(r.obr(false).x(),\
                      r.obr(false).y());
            pp.lineTo(r.obl(false).x(),\
                      r.obl(false).y());
            pp.closeSubpath();
            painter.drawPath(pp);

        }else
        {
            //Rechteck runden Ecken:
            punkt2d mitpu = r.mi();
            //mitpu.set_y(mitpu.y()-r.b());
            QPainterPath pp;

            punkt2d p2;
            //Startpunkt:
            p2.set_x(r.unl().x());
            p2.set_y((r.mi().y()+r.b()/2)-r.rad());
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.moveTo(p2.x(), p2.y());
            //Rundung links unten:
            p2.set_x(r.unl().x());
            p2.set_y((r.mi().y()+r.b()/2)-r.rad()*2);
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 180+r.drewi(), 90);
            //Linie nach rechts unten:
            p2.set_x(r.unr().x()-r.rad());
            p2.set_y((r.mi().y()+r.b()/2));
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung rechts unten:
            p2.set_x(r.unr().x()-r.rad()*2);
            p2.set_y((r.mi().y()+r.b()/2)-r.rad()*2);
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 270+r.drewi(), 90);
            //Linie nach rechts oben:
            p2.set_x(r.obr().x());
            p2.set_y((r.mi().y()-r.b()/2)+r.rad());
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung rechts oben
            p2.set_x(r.unr().x()-r.rad()*2);
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 0+r.drewi(), 90);
            //Linie nach links oben:
            p2.set_x(r.obl().x()+r.rad());
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen(mitpu,\
                        p2,\
                        r.drewi(),\
                        true);
            pp.lineTo(p2.x(),p2.y());
            //Rundung links oben
            p2.set_x(r.obl().x());
            p2.set_y((r.mi().y()-r.b()/2));
            p2 = drehen_arcTo(p2,\
                        r.rad()*2,\
                        r.rad()*2,\
                        r.drewi(),\
                        mitpu);
            pp.arcTo(p2.x(), p2.y(), r.rad()*2, r.rad()*2, 90+r.drewi(), 90);

            pp.closeSubpath();
            painter.drawPath(pp);
        }

        painter.setPen(pen_alt);
        painter.setBrush(brush_alt);
    }

}

void vorschau::zeichneFkon(QString geometrieElement, uint i)
{
    QPainter painter(this);
    painter.setBrush( Qt::white);
    painter.setPen(Qt::black);

    text_zeilenweise element;
    element.set_trennzeichen(TRZ_PA_);
    element.set_text(geometrieElement);

    if(element.get_text().contains(STRECKE))
    {
        punkt2d startpunkt, endpunkt;
        startpunkt.set_x(element.zeile(2).toDouble()*sf*zf);
        startpunkt.set_y(element.zeile(3).toDouble()*sf*zf);
        endpunkt.set_x(element.zeile(5).toDouble()*sf*zf);
        endpunkt.set_y(element.zeile(6).toDouble()*sf*zf);

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(9).toInt());
        pen.setStyle(set_linienstil(element.zeile(10)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(8)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        painter.drawLine(n.x-npv.x+startpunkt.x(), \
                         n.y-npv.y-startpunkt.y(), \
                         n.x-npv.x+endpunkt.x(), \
                         n.y-npv.y-endpunkt.y());

        painter.setPen(pen_alt);
    }else if(element.get_text().contains(BOGEN))
    {
        double rad = element.zeile(8).toDouble()*sf*zf;
        punkt2d mipu;
        mipu.set_x(element.zeile(10).toDouble()*sf*zf);//Mittelpunkt in X
        mipu.set_y(element.zeile(11).toDouble()*sf*zf);//Mittelpunkt in Y
        punkt2d obli;
        obli.set_x(mipu.x()-rad);
        obli.set_y(mipu.y()+rad);

        punkt2d mp;
        mp.set_x(element.zeile(10).toDouble());//Mittelpunkt in X
        mp.set_y(element.zeile(11).toDouble());//Mittelpunkt in Y
        punkt2d sp;
        sp.set_x(element.zeile(2).toDouble());//Start in X
        sp.set_y(element.zeile(3).toDouble());//Start in Y
        punkt2d ep;
        ep.set_x(element.zeile(5).toDouble());//Ende in X
        ep.set_y(element.zeile(6).toDouble());//Ende in Y
        double stawi=0, bogwi=0;

        if(element.zeile(9) == "nein")//Bogen gegen den Uhrzeigersinn
        {
            stawi = winkel(sp.x(),   \
                           sp.y(),   \
                           mp.x(),   \
                           mp.y());
            bogwi = winkel(sp.x(),   \
                           sp.y(),   \
                           mp.x(),   \
                           mp.y(),   \
                           ep.x(),   \
                           ep.y());
        }else//Bogen im Uhrzeigersinn
        {
            stawi = winkel(ep.x(),   \
                           ep.y(),   \
                           mp.x(),   \
                           mp.y());
            bogwi = winkel(ep.x(),   \
                           ep.y(),   \
                           mp.x(),   \
                           mp.y(),   \
                           sp.x(),   \
                           sp.y());
        }
        if(bogwi<0)
        {
            bogwi = 360+bogwi;
        }

        QPen pen, pen_alt;
        pen_alt = painter.pen();
        pen.setWidth(element.zeile(13).toInt());
        pen.setStyle(set_linienstil(element.zeile(14)));
        if(i==aktuelle_zeilennummer)
        {
            pen.setColor(Qt::red);
        }else
        {
            pen.setColor(set_farbe(element.zeile(12)));
        }
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);

        painter.drawArc(n.x-npv.x+obli.x(),\
                        n.y-npv.y-obli.y(),\
                        rad*2,\
                        rad*2,\
                        stawi*16,\
                        bogwi*16);

        painter.setPen(pen_alt);
    }
}

void vorschau::werkstueck_darstellung_berechnen()
{
    int randabstand = 10;
    float maximallaenge = t.get_max_x() - t.get_min_x();
    float maximalbreite = t.get_max_y() - t.get_min_y();

    float bildlaenge = width()-randabstand*2;
    float bildbreite = height()-randabstand*2;

    float faktor_laenge = bildlaenge/maximallaenge;
    float faktor_breite = bildbreite/maximalbreite;

    if(faktor_laenge < faktor_breite)
    {
        set_sf(faktor_laenge);
    }else
    {
        set_sf(faktor_breite);
    }

    float laenge = wst.get_laenge() * get_sf() * zf;
    float breite = wst.get_breite() * get_sf() * zf;

    wstd.set_laenge(laenge);
    wstd.set_breite(breite);

    punkt basispunkt;
    basispunkt.x = randabstand;
    basispunkt.y = height()-randabstand;

    n.x = basispunkt.x - t.get_min_x()*sf * zf;
    n.y = basispunkt.y + t.get_min_y()*sf * zf;

}

void vorschau::slot_aktualisieren(programmtext t_neu, int aktive_zeile)
{
    t = t_neu;
    wst.set_laenge(t.get_werkstuecklaenge());
    wst.set_breite(t.get_werkstueckbreite());
    aktuelle_zeilennummer = aktive_zeile;
    werkstueck_darstellung_berechnen();
    this->update();

}

void vorschau::slot_aktives_Element_einfaerben(int zeilennummer)
{
    //Element aus dieser Zeile farbig markieren
    aktuelle_zeilennummer = zeilennummer;
    werkstueck_darstellung_berechnen();
    this->update();
}

punkt vorschau::drehen_arcTo(punkt oben_links, float laenge, float breite, \
                             float drehwinkel, punkt drehzentrum)
{
    punkt mittelpunkt;
    mittelpunkt.x = oben_links.x + laenge/2;
    mittelpunkt.y = oben_links.y + breite/2;

    mittelpunkt = drehen(drehzentrum, mittelpunkt, drehwinkel, true);

    punkt p;
    p.x = mittelpunkt.x - laenge/2;
    p.y = mittelpunkt.y - breite/2;

    return p;
}

punkt2d vorschau::drehen_arcTo(punkt2d oben_links, double laenge, double breite, \
                               double drehwinkel, punkt2d drehzentrum)
{
    punkt2d mittelpunkt;
    mittelpunkt.set_x(oben_links.x() + laenge/2);
    mittelpunkt.set_y(oben_links.y() + breite/2);

    mittelpunkt = drehen(drehzentrum, mittelpunkt, drehwinkel, true);

    punkt2d p2;
    p2.set_x(mittelpunkt.x() - laenge/2);
    p2.set_y(mittelpunkt.y() - breite/2);

    return p2;
}

//-------------------------------------------------------------
float vorschau::get_sf()
{
    return sf;
}

//-------------------------------------------------------------
void vorschau::set_sf(float neuer_faktor)
{
    sf = neuer_faktor;
}

void vorschau::zoom(bool dichter)
{
    if(dichter == true)
    {
        zf = zf + zf/25;
    }else
    {
        if(zf > 1)
        {
            zf = zf - zf/25;
        }else
        {
            //npv.x = 0;
            //npv.y = 0;
        }
    }

}

void vorschau::mouseMoveEvent(QMouseEvent *event)
{
    if(mrg)
    {
        npv.x = npv.x + maus_pos_alt_x-event->x();
        npv.y = npv.y + maus_pos_alt_y-event->y();
        maus_pos_alt_x = event->x();
        maus_pos_alt_y = event->y();
        this->update();
    }

    QPoint p = this->mapFromGlobal(QCursor::pos());
    int abst_nullp_x = p.x() - n.x+npv.x;
    int abst_nullp_y = p.y() - n.y+npv.y;

    QPoint p_real;
    p_real.setX(abst_nullp_x/sf/zf);
    p_real.setY(abst_nullp_y/sf*-1/zf);

    emit sende_maus_pos(p_real);
}

void vorschau::wheelEvent(QWheelEvent *event)
{
    QPoint mauspos = event->pos();
    mauspos.setY(this->height()-mauspos.y());
    QPoint wstpos;
    wstpos.setX(  (mauspos.x() - n.x+npv.x)  /sf/zf  );
    wstpos.setY(  (n.x+npv.y - mauspos.y())  /sf/zf  );

    int i = event->delta();
    if(i<0)
    {
        zoom(false);
    }else
    {
        zoom(true);
    }

    QPoint wstposneu;
    wstposneu.setX(  (mauspos.x() - n.x+npv.x)  /sf/zf  );
    wstposneu.setY(  (n.x+npv.y - mauspos.y())  /sf/zf  );
    int xversmm = wstposneu.x() - wstpos.x();
    int yversmm = wstposneu.y() - wstpos.y();
    int xverspixel = xversmm*sf*zf;
    int yverspixel = yversmm*sf*zf;
    npv.x = npv.x-xverspixel;
    npv.y = npv.y-yverspixel;
    if(zf<=1)
    {
        npv.x = 0;
        npv.y = 0;
    }
    this->update();
}

void vorschau::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton)
    {
        mrg = true;
        maus_pos_alt_x = event->x();
        maus_pos_alt_y = event->y();
    }else if(event->button() == Qt::RightButton)
    {
        QMenu m(this);
        m.addAction("Ansicht einpassen", this, SLOT(slot_zf_gleich_eins()), 0) ;
        m.exec(this->mapFrom(this, QCursor::pos()));
    }
}

void vorschau::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton)
    {
        mrg = false;
    }
}

void vorschau::slot_zf_gleich_eins()
{
    zf = 1;
    npv.x = 0;
    npv.y = 0;
    this->update();
}

QColor vorschau::set_farbe(QString farbe)
{
    QColor qfarbe = Qt::black;
    if(farbe == FARBE_KEINE)
    {
        qfarbe = Qt::transparent;
    }else if(farbe == FARBE_SCHWARZ)
    {
        qfarbe = Qt::black;
    }else if(farbe == FARBE_WEISS)
    {
        qfarbe = Qt::white;
    }else if(farbe == FARBE_BLAU)
    {
        qfarbe = Qt::blue;
    }else if(farbe == FARBE_ROT)
    {
        qfarbe = Qt::red;
    }else if(farbe == FARBE_GRUEN)
    {
        qfarbe = Qt::green;
    }else if(farbe == FARBE_GELB)
    {
        qfarbe = Qt::yellow;
    }else if(farbe == FARBE_GRAU)
    {
        qfarbe = Qt::gray;
    }

    return qfarbe;
}

Qt::PenStyle vorschau::set_linienstil(QString stil)
{
    Qt::PenStyle style = Qt::SolidLine;
    if(stil == STIL_TRANSPARENT)
    {
        style = Qt::NoPen;
    }else if(stil == STIL_TRANSPARENT)
    {
        style = Qt::NoPen;
    }else if(stil == STIL_DURCHGEHEND)
    {
        style = Qt::SolidLine;
    }else if(stil == STIL_GESTRICHELT)
    {
        style = Qt::DashLine;
    }else if(stil == STIL_GEPUNKTET)
    {
        style = Qt::DotLine;
    }else if(stil == STIL_STRICHP)
    {
        style = Qt::DashDotLine;
    }else if(stil == STIL_STRICHPP)
    {
        style = Qt::DashDotDotLine;
    }

    return style;
}
