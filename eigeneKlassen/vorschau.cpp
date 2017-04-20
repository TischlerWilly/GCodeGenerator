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

}


void vorschau::paintEvent(QPaintEvent *)
{
    werkstueck_darstellung_berechnen();
    QPainter painter(this);

    //Hintergrund:
    painter.setBrush( Qt::white);
    painter.setPen(Qt::black);
    painter.drawRect(0, 0, width(), height());

    //Werkstück darstellen:
    painter.setBrush(Qt::gray);
    painter.drawRect(n.x-npv.x, n.y-npv.y-wstd.get_breite(), wstd.get_laenge() , wstd.get_breite());

    //n darstellen:
    QPen pen, pen_alt;
    pen_alt = painter.pen();
    pen.setWidth(15);
    pen.setColor(Qt::red);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawPoint(n.x-npv.x, n.y-npv.y);
    painter.setPen(pen_alt);

    //Bearbeitungen darstellen:
    text_zeilenweise tz = t.get_klartext_zeilenweise();
    for(uint i=1 ; i<=tz.zeilenanzahl() ; i++)
    {
        if(i==aktuelle_zeilennummer)
        {
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            painter.setPen(pen);
        }else
        {
            QPen pen;
            pen.setColor(Qt::black);
            pen.setWidth(0);
            painter.setPen(pen);
        }
        QString zeile = tz.zeile(i);
        if(  (zeile.contains(PROGRAMMKOPF_DIALOG))  &&  (i==aktuelle_zeilennummer)  )
        {
            //Werkstück darstellen mit rotem Stift:
            painter.drawLine(n.x-npv.x, n.y-npv.y, n.x-npv.x+wstd.get_laenge(), n.y-npv.y);
            painter.drawLine(n.x-npv.x, n.y-npv.y-wstd.get_breite(), n.x-npv.x+wstd.get_laenge(), n.y-npv.y-wstd.get_breite());
            painter.drawLine(n.x-npv.x, n.y-npv.y, n.x-npv.x, n.y-npv.y-wstd.get_breite());
            painter.drawLine(n.x-npv.x+wstd.get_laenge(), n.y-npv.y, n.x-npv.x+wstd.get_laenge(), n.y-npv.y-wstd.get_breite());
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            //Rechteck mit realen Dimensionen:
            rechteck r;
            QString tmp = text_mitte(zeile, BEZUGSPUNKT, ENDE_EINTRAG);
            r.set_bezugspunkt_nummer(tmp.toInt());
            tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            QString tmp2 = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            r.set_einfuegepunkt(tmp.toFloat(), tmp2.toFloat());
            tmp = text_mitte(zeile, TASCHENLAENGE, ENDE_EINTRAG);
            r.set_laenge(tmp.toFloat());
            tmp = text_mitte(zeile, TASCHENBREITE, ENDE_EINTRAG);
            r.set_breite(tmp.toFloat());

            //Rechteck mit dargestellten Dimensionen:
            rechteck r2;
            r2.set_bezugspunkt_nummer(r.get_bezugspunkt_nummer());
            float epx = n.x-npv.x + (r.get_einfuegepunkt_x()*sf*zf);
            float epy = n.y-npv.y - (r.get_einfuegepunkt_y()*sf*zf);
            r2.set_einfuegepunkt(epx, epy);
            r2.set_laenge(r.get_laenge()*sf*zf);
            r2.set_breite(-r.get_breite()*sf*zf);


            painter.setBrush(Qt::blue);
            tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
            float tati = tmp.toFloat();
            tmp = text_mitte(zeile, BEZUGSHOEHE, ENDE_EINTRAG);
            float bezh = tmp.toFloat();
            tati = bezh-tati;
            if(tati < 0)
            {
                painter.setBrush(Qt::white);
            }

            tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
            float rad = tmp.toFloat();
            if(rad == 0)
            {
                //Rechteck miteckigen Ecken:
                QPainterPath pp;
                QString tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                float drehwi = tmp.toFloat();
                punkt unli;
                unli.x = r2.get_eckpunkt_unten_links_x();
                unli.y = r2.get_eckpunkt_unten_links_y();
                unli = drehen(r2.get_mittelpunkt(), unli, drehwi, true);
                pp.moveTo(unli.x, unli.y);
                punkt unre;
                unre.x = r2.get_eckpunkt_unten_rechts_x();
                unre.y = r2.get_eckpunkt_unten_rechts_y();
                unre = drehen(r2.get_mittelpunkt(), unre, drehwi, true);
                pp.lineTo(unre.x, unre.y);
                punkt obre;
                obre.x = r2.get_eckpunkt_oben_rechts_x();
                obre.y = r2.get_eckpunkt_oben_rechts_y();
                obre = drehen(r2.get_mittelpunkt(), obre, drehwi, true);
                pp.lineTo(obre.x, obre.y);
                punkt obli;
                obli.x = r2.get_eckpunkt_oben_links_x();
                obli.y = r2.get_eckpunkt_oben_links_y();
                obli = drehen(r2.get_mittelpunkt(), obli, drehwi, true);
                pp.lineTo(obli.x, obli.y);
                pp.closeSubpath();
                painter.drawPath(pp);

                tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                float afb_ausraeumen = tmp.toFloat();
                if(afb_ausraeumen == false)
                {
                    int diff = 10;
                    rechteck r3 = r2;
                    r3.set_bezugspunkt_nummer(MITTE);
                    r3.set_einfuegepunkt(r2.get_mittelpunkt());
                    r3.set_laenge(r3.get_laenge() - diff*2);
                    r3.set_breite(r3.get_breite() + diff*2);//+diff*2 weil breite einen Negativen Wert hat

                    QPainterPath pp;
                    QString tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                    float drehwi = tmp.toFloat();
                    punkt unli;
                    unli.x = r3.get_eckpunkt_unten_links_x();
                    unli.y = r3.get_eckpunkt_unten_links_y();
                    unli = drehen(r3.get_mittelpunkt(), unli, drehwi, true);
                    pp.moveTo(unli.x, unli.y);
                    punkt unre;
                    unre.x = r3.get_eckpunkt_unten_rechts_x();
                    unre.y = r3.get_eckpunkt_unten_rechts_y();
                    unre = drehen(r3.get_mittelpunkt(), unre, drehwi, true);
                    pp.lineTo(unre.x, unre.y);
                    punkt obre;
                    obre.x = r3.get_eckpunkt_oben_rechts_x();
                    obre.y = r3.get_eckpunkt_oben_rechts_y();
                    obre = drehen(r3.get_mittelpunkt(), obre, drehwi, true);
                    pp.lineTo(obre.x, obre.y);
                    punkt obli;
                    obli.x = r3.get_eckpunkt_oben_links_x();
                    obli.y = r3.get_eckpunkt_oben_links_y();
                    obli = drehen(r3.get_mittelpunkt(), obli, drehwi, true);
                    pp.lineTo(obli.x, obli.y);
                    pp.closeSubpath();

                    QBrush old_brush = painter.brush();
                    painter.setBrush(Qt::gray);
                    painter.drawPath(pp);
                    painter.setBrush(old_brush);
                }
            }else
            {
                //Rechteck runden Ecken:
                rad = rad*sf*zf;
                QPainterPath pp;
                QString tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                float drehwi = tmp.toFloat();
                punkt drehzentrum = r2.get_mittelpunkt();
                punkt p , obli;

                p.x = r2.get_eckpunkt_unten_links_x();
                p.y = r2.get_eckpunkt_unten_links_y() - rad;
                p = drehen(drehzentrum, p, drehwi, true);
                pp.moveTo(p.x, p.y);

                //Rundung links unten:
                obli.x = r2.get_eckpunkt_unten_links_x();
                obli.y = r2.get_eckpunkt_unten_links_y() - rad*2;
                obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                pp.arcTo(obli.x, obli.y, rad*2, rad*2, 180+drehwi, 90);
                //Linie nach rechts unten:
                p.x = r2.get_eckpunkt_unten_rechts_x() - rad;
                p.y = r2.get_eckpunkt_unten_rechts_y();
                p = drehen(drehzentrum, p, drehwi, true);
                pp.lineTo(p.x, p.y);
                //Rundung rechts unten:
                obli.x = r2.get_eckpunkt_unten_rechts_x() - rad*2;
                obli.y = r2.get_eckpunkt_unten_rechts_y() - rad*2;
                obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                pp.arcTo(obli.x, obli.y, rad*2, rad*2, 270+drehwi, 90);
                //Linie nach rechts oben:
                p.x = r2.get_eckpunkt_oben_rechts_x();
                p.y = r2.get_eckpunkt_oben_rechts_y() + rad;
                p = drehen(drehzentrum, p, drehwi, true);
                pp.lineTo(p.x, p.y);
                //Rundung rechts oben
                obli.x = r2.get_eckpunkt_oben_rechts_x() - rad*2;
                obli.y = r2.get_eckpunkt_oben_rechts_y();
                obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                pp.arcTo(obli.x, obli.y, rad*2, rad*2, 0+drehwi, 90);
                //Linie nach links oben:
                p.x = r2.get_eckpunkt_oben_links_x() + rad;
                p.y = r2.get_eckpunkt_oben_links_y();
                p = drehen(drehzentrum, p, drehwi, true);
                pp.lineTo(p.x, p.y);
                //Rundung links oben
                obli.x = r2.get_eckpunkt_oben_links_x();
                obli.y = r2.get_eckpunkt_oben_links_y();
                obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                pp.arcTo(obli.x, obli.y, rad*2, rad*2, 90+drehwi, 90);

                pp.closeSubpath();
                painter.drawPath(pp);

                tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                float afb_ausraeumen = tmp.toFloat();
                if(afb_ausraeumen == false)
                {
                    int diff = 10;
                    rechteck r3 = r2;
                    r3.set_bezugspunkt_nummer(MITTE);
                    r3.set_einfuegepunkt(r2.get_mittelpunkt());
                    r3.set_laenge(r3.get_laenge() - diff*2);
                    r3.set_breite(r3.get_breite() + diff*2);//+diff*2 weil breite einen Negativen Wert hat
                    rad = rad-diff;

                    QPainterPath pp;
                    QString tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                    float drehwi = tmp.toFloat();
                    punkt drehzentrum = r3.get_mittelpunkt();
                    punkt p , obli;

                    p.x = r3.get_eckpunkt_unten_links_x();
                    p.y = r3.get_eckpunkt_unten_links_y() - rad;
                    p = drehen(drehzentrum, p, drehwi, true);
                    pp.moveTo(p.x, p.y);

                    //Rundung links unten:
                    obli.x = r3.get_eckpunkt_unten_links_x();
                    obli.y = r3.get_eckpunkt_unten_links_y() - rad*2;
                    obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                    pp.arcTo(obli.x, obli.y, rad*2, rad*2, 180+drehwi, 90);
                    //Linie nach rechts unten:
                    p.x = r3.get_eckpunkt_unten_rechts_x() - rad;
                    p.y = r3.get_eckpunkt_unten_rechts_y();
                    p = drehen(drehzentrum, p, drehwi, true);
                    pp.lineTo(p.x, p.y);
                    //Rundung rechts unten:
                    obli.x = r3.get_eckpunkt_unten_rechts_x() - rad*2;
                    obli.y = r3.get_eckpunkt_unten_rechts_y() - rad*2;
                    obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                    pp.arcTo(obli.x, obli.y, rad*2, rad*2, 270+drehwi, 90);
                    //Linie nach rechts oben:
                    p.x = r3.get_eckpunkt_oben_rechts_x();
                    p.y = r3.get_eckpunkt_oben_rechts_y() + rad;
                    p = drehen(drehzentrum, p, drehwi, true);
                    pp.lineTo(p.x, p.y);
                    //Rundung rechts oben
                    obli.x = r3.get_eckpunkt_oben_rechts_x() - rad*2;
                    obli.y = r3.get_eckpunkt_oben_rechts_y();
                    obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                    pp.arcTo(obli.x, obli.y, rad*2, rad*2, 0+drehwi, 90);
                    //Linie nach links oben:
                    p.x = r3.get_eckpunkt_oben_links_x() + rad;
                    p.y = r3.get_eckpunkt_oben_links_y();
                    p = drehen(drehzentrum, p, drehwi, true);
                    pp.lineTo(p.x, p.y);
                    //Rundung links oben
                    obli.x = r3.get_eckpunkt_oben_links_x();
                    obli.y = r3.get_eckpunkt_oben_links_y();
                    obli = drehen_arcTo(obli, rad*2, rad*2, drehwi, drehzentrum);
                    pp.arcTo(obli.x, obli.y, rad*2, rad*2, 90+drehwi, 90);

                    pp.closeSubpath();

                    QBrush old_brush = painter.brush();
                    painter.setBrush(Qt::gray);
                    painter.drawPath(pp);
                    painter.setBrush(old_brush);
                }
            }

        }else if(zeile.contains(KREISTASCHE_DIALOG))
        {
            punkt mittelpunkt;
            float durchmesser;
            QString tmp;

            tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            mittelpunkt.x = tmp.toFloat();
            mittelpunkt.x = n.x-npv.x + (mittelpunkt.x * sf*zf);

            tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            mittelpunkt.y = tmp.toFloat();
            mittelpunkt.y = n.y-npv.y - (mittelpunkt.y * sf*zf);

            tmp = text_mitte(zeile, DURCHMESSER, ENDE_EINTRAG);
            durchmesser = tmp.toFloat();
            durchmesser = durchmesser * sf*zf;

            painter.setBrush(Qt::blue);
            tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
            float tati = tmp.toFloat();
            tmp = text_mitte(zeile, BEZUGSHOEHE, ENDE_EINTRAG);
            float bezh = tmp.toFloat();
            tati = bezh-tati;
            if(tati < 0)
            {
                painter.setBrush(Qt::white);
            }


            painter.drawRoundedRect(mittelpunkt.x-durchmesser/2, mittelpunkt.y-durchmesser/2, durchmesser, durchmesser, durchmesser, durchmesser, Qt::AbsoluteSize);

            tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
            float afb_ausraeumen = tmp.toFloat();
            if(afb_ausraeumen == false)
            {
                int diff = 10;
                durchmesser = durchmesser-diff*2;
                QBrush old_brush = painter.brush();
                painter.setBrush(Qt::gray);
                painter.drawRoundedRect(mittelpunkt.x-durchmesser/2, mittelpunkt.y-durchmesser/2, durchmesser, durchmesser, durchmesser, durchmesser, Qt::AbsoluteSize);
                painter.setBrush(old_brush);
            }
        }
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

    //Werkstückn auf dem Bildschirm:
    //n.x = (width()-wstd.get_laenge())/2;
    //n.y = (height()+wstd.get_breite())/2;
    punkt basispunkt;
    basispunkt.x = randabstand;
    basispunkt.y = height()-randabstand;

    n.x = basispunkt.x - t.get_min_x()*sf * zf;
    n.y = basispunkt.y + t.get_min_y()*sf * zf;
}

void vorschau::slot_aktualisieren(QString neuer_programmtext, int aktive_zeile)
{
    t.set_text(neuer_programmtext);
    wst.set_laenge(t.get_werkstuecklaenge());
    wst.set_breite(t.get_werkstueckbreite());
    aktuelle_zeilennummer = aktive_zeile;
    werkstueck_darstellung_berechnen();
    this->update();

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

punkt vorschau::drehen_arcTo(punkt oben_links, float laenge, float breite, float drehwinkel, punkt drehzentrum)
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
