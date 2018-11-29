#include "gcode.h"


gcode::gcode(programmtext t_neu)
{
    set_prgtext(t_neu);
}

void gcode::set_prgtext(programmtext t_neu)
{
    t = t_neu;
}

void gcode::set_wkz(werkzeug w_neu)
{
    w = w_neu;
}

QString gcode::get_gcode()
{
    eintauchvorschub = 0;
    vorschub = 0;
    drehzahl = 0;
    zustellmass = 0;
    aktives_wkz = NICHT_DEFINIERT;

    t.aktualisieren_fkon_ein_aus(true);
    text_zeilenweise klartext =t.get_klartext_zeilenweise();
    QString gc;//gcode
    //QString abfahrtyp;

    for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
    {
        QString zeile_kt;//zeile klartext
        zeile_kt = klartext.zeile(i);
        gc += "(";
        gc += klammern_wecklassen(zeile_kt);
        gc += ")";
        gc += "\n";

        if(zeile_kt.contains(PROGRAMMKOPF_DIALOG))
        {
            gc += get_prgkopf(zeile_kt);
        }else if(zeile_kt.contains(PROGRAMMENDE_DIALOG))
        {
            gc += get_prgende(zeile_kt);
            break; //Ende der Ausgabe = Ende der For-Schleife
        }else if(zeile_kt.contains(KOMMENTAR_DIALOG))
        {
            gc += get_kom(zeile_kt);
        }else if(zeile_kt.contains(RECHTECKTASCHE_DIALOG))
        {
            QString fehlertext;
            gc += get_rta(zeile_kt, &fehlertext, 0 , 0);
            if(!fehlertext.isEmpty())
            {
                return fehlertext;
            }
        }else if(zeile_kt.contains(KREISTASCHE_DIALOG))
        {
            QString fehlertext;
            gc += get_kta(zeile_kt, &fehlertext, 0 , 0);
            if(!fehlertext.isEmpty())
            {
                return fehlertext;
            }
        }else if(zeile_kt.contains(BOHREN_DIALOG))
        {
            QString fehlertext;
            gc += get_bohrung(zeile_kt, &fehlertext, 0 , 0);
            if(!fehlertext.isEmpty())
            {
                return fehlertext;
            }
        }else if(zeile_kt.contains(FRAESERAUFRUF_DIALOG))
        {
            text_zeilenweise tmp_klartext;
            text_zeilenweise tmp_geo;
            tmp_klartext.zeile_anhaengen(zeile_kt);
            tmp_geo.zeile_anhaengen(t.get_fkon().get_text_zeilenweise().zeile(i));
            for(   ; i<=klartext.zeilenanzahl() ; i++)//i von der umfassenden Schleife wird weiter gezählt
            {
                zeile_kt = klartext.zeile(i);
                if(zeile_kt.contains(FRAESERGERADE_DIALOG)  || \
                   zeile_kt.contains(FRAESERBOGEN_DIALOG)      )
                {
                    tmp_klartext.zeile_anhaengen(zeile_kt);
                    tmp_geo.zeile_anhaengen(t.get_fkon().get_text_zeilenweise().zeile(i));
                }else if(zeile_kt.contains(FRAESERABFAHREN_DIALOG))
                {
                    tmp_klartext.zeile_anhaengen(zeile_kt);
                    tmp_geo.zeile_anhaengen(t.get_fkon().get_text_zeilenweise().zeile(i));
                    break;
                }
            }
            geometrietext g;
            g.set_text(tmp_geo.get_text());
            QString fehlertext;
            gc += get_fkon(tmp_klartext, g, &fehlertext, 0 , 0);
            if(!fehlertext.isEmpty())
            {
                return fehlertext;
            }
        }



    }
    return gc;
}

QString gcode::klammern_wecklassen(QString text)
{
    QString tmp;
    for(int i = 0; i<text.length() ; i++)
    {
        if(  (text.at(i)!='(')  &&  (text.at(i)!=')')  )
        {
            tmp += text.at(i);
        }
    }
    return tmp;
}

QString gcode::werkzeugdaten(QString werkzeugname)
{
    QString daten;
    text_zeilenweise tz = w.get_werkzeuge_zeilenweise();
    for(uint i=1; i <= tz.zeilenanzahl() ; i++)
    {
        QString zeile = tz.zeile(i);
        if(zeile.contains(werkzeugname))
        {
            daten = zeile;
            break;
        }
    }
    return daten;
}

QString gcode::get_prgkopf(QString zeile_klartext)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    QString gc;
    gc += "(";
    gc += klammern_wecklassen(text_mitte(zeile_klartext, KOMMENTAR, ENDE_EINTRAG));
    gc += ")";
    gc += "\n";
    return gc;
}

QString gcode::get_prgende(QString zeile_klartext)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    QString gc;
    gc += "G00";
    gc += " X";
    gc += text_mitte(zeile_klartext, POSITION_X, ENDE_EINTRAG);
    gc += " Y";
    gc += text_mitte(zeile_klartext, POSITION_Y, ENDE_EINTRAG);
    gc += " Z";
    gc += text_mitte(zeile_klartext, POSITION_Z, ENDE_EINTRAG);
    gc += "\n";
    gc += "M30";
    return gc;
}

QString gcode::get_kom(QString zeile_klartext)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    QString gc;
    gc += "(";
    gc += klammern_wecklassen(text_mitte(zeile_klartext, KOMMENTAR, ENDE_EINTRAG));
    gc += ")";
    gc += "\n";
    return gc;
}

QString gcode::get_rta(QString zeile_klartext, QString* fehlertext, double ax, double ay)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    //ax = X-versatz
    //ay = Y-Versatz
    QString gc;
    fehlertext->clear();

    QString werkzeugname = text_mitte(zeile_klartext, WKZ_NAME, ENDE_EINTRAG);
    if(aktives_wkz == NICHT_DEFINIERT)
    {
        aktives_wkz = werkzeugname;
    }else if(aktives_wkz != werkzeugname)
    {
        *fehlertext = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
        return *fehlertext;
    }
    rechtecktasche tasche_tmp;
    QString tmp;
    tmp = text_mitte(zeile_klartext, BEZUGSPUNKT, ENDE_EINTRAG);
    tasche_tmp.set_bezugspunkt_nummer(tmp.toInt());

    punkt p;
    tmp = text_mitte(zeile_klartext, POSITION_X, ENDE_EINTRAG);
    p.x = tmp.toFloat() + ax;
    tmp = text_mitte(zeile_klartext, POSITION_Y, ENDE_EINTRAG);
    p.y = tmp.toFloat() + ay;
    tasche_tmp.set_einfuegepunkt(p);

    tmp = text_mitte(zeile_klartext, TASCHENLAENGE, ENDE_EINTRAG);
    tasche_tmp.set_laenge(tmp.toFloat());
    tmp = text_mitte(zeile_klartext, TASCHENBREITE, ENDE_EINTRAG);
    tasche_tmp.set_breite(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, TASCHENTIEFE, ENDE_EINTRAG);
    tasche_tmp.set_tiefe(tmp.toFloat());

    tasche_tmp.set_sicherheitsabstand(t.get_sicherheitsabstand());

    //Fräserdurchmesser:
    tmp = werkzeugname;
    QString werkzeug;
    werkzeug = werkzeugdaten(tmp);
    tmp = text_mitte(werkzeug, WKZ_DURCHMESSER, ENDE_EINTRAG);
    tasche_tmp.set_durchmesser_fraeser(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, RADIUS, ENDE_EINTRAG);
    tasche_tmp.set_radius_taschenecken(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, ZUSTELLUNG, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
    }
    tasche_tmp.set_zustellmass(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, AUSRAEUMEN, ENDE_EINTRAG);
    tasche_tmp.set_ausraeumen(tmp.toInt());

    tmp = text_mitte(zeile_klartext, BEZUGSHOEHE, ENDE_EINTRAG);
    tasche_tmp.set_bezugshoehe(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, VORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
    }
    tasche_tmp.set_vorschubgeschwindigkeit(tmp.toInt());

    tmp = text_mitte(zeile_klartext, ANFAHRVORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
    }
    tasche_tmp.set_anfahrvorschub(tmp.toInt());

    tmp = text_mitte(zeile_klartext, WINKEL, ENDE_EINTRAG);
    tasche_tmp.set_drehwinkel(tmp.toFloat());

    QString drehrichtung_fraeser;
    drehrichtung_fraeser = text_mitte(werkzeug, WKZ_DREHRICHTUNG, ENDE_EINTRAG);
    QString im_gegenlauf;
    im_gegenlauf = text_mitte(zeile_klartext, GEGENLAUF, ENDE_EINTRAG);
    if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_RECHTS)
    {
        if(im_gegenlauf.toInt()  == true)
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
        }else
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
        }
    }else if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_LINKS)
    {
        if(im_gegenlauf.toInt()  == false)
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
        }else
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
        }
    }else
    {
        *fehlertext  = "(Ausgabe nicht moeglich weil Drehrichtung Fraeser \"";
        *fehlertext += werkzeugname;
        *fehlertext += "\" unbekannt)";
        return *fehlertext;
    }

    if(text_mitte(werkzeug, WKZ_KANN_BOHREN, ENDE_EINTRAG) == "1")
    {
        tasche_tmp.set_fraeser_kabo(true);
    }else
    {
        tasche_tmp.set_fraeser_kabo(false);
    }

    std::string tasche = tasche_tmp.get_gcode();
    tmp = QString::fromStdString(tasche);
    gc += tmp;
    gc += "\n";

    return gc;
}

QString gcode::get_kta(QString zeile_klartext, QString *fehlertext, double ax, double ay)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    QString gc;
    fehlertext->clear();

    QString werkzeugname = text_mitte(zeile_klartext, WKZ_NAME, ENDE_EINTRAG);
    if(aktives_wkz == NICHT_DEFINIERT)
    {
        aktives_wkz = werkzeugname;
    }else if(aktives_wkz != werkzeugname)
    {
        *fehlertext = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
        return *fehlertext;
    }
    rechtecktasche tasche_tmp;
    QString tmp;
    tasche_tmp.set_bezugspunkt_nummer(MITTE);

    punkt p;
    tmp = text_mitte(zeile_klartext, POSITION_X, ENDE_EINTRAG);
    p.x = tmp.toFloat() + ax;
    tmp = text_mitte(zeile_klartext, POSITION_Y, ENDE_EINTRAG);
    p.y = tmp.toFloat() + ay;
    tasche_tmp.set_einfuegepunkt(p);

    tmp = text_mitte(zeile_klartext, DURCHMESSER, ENDE_EINTRAG);
    tasche_tmp.set_laenge(tmp.toFloat());
    tasche_tmp.set_breite(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, TASCHENTIEFE, ENDE_EINTRAG);
    tasche_tmp.set_tiefe(tmp.toFloat());

    tasche_tmp.set_sicherheitsabstand(t.get_sicherheitsabstand());

    //Fräserdurchmesser:
    tmp = werkzeugname;
    QString werkzeug;
    werkzeug = werkzeugdaten(tmp);
    tmp = text_mitte(werkzeug, WKZ_DURCHMESSER, ENDE_EINTRAG);
    tasche_tmp.set_durchmesser_fraeser(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, DURCHMESSER, ENDE_EINTRAG);
    tasche_tmp.set_radius_taschenecken(tmp.toFloat()/2);

    tmp = text_mitte(zeile_klartext, ZUSTELLUNG, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
    }
    tasche_tmp.set_zustellmass(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, AUSRAEUMEN, ENDE_EINTRAG);
    tasche_tmp.set_ausraeumen(tmp.toInt());

    tmp = text_mitte(zeile_klartext, BEZUGSHOEHE, ENDE_EINTRAG);
    tasche_tmp.set_bezugshoehe(tmp.toFloat());

    tmp = text_mitte(zeile_klartext, VORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
    }
    tasche_tmp.set_vorschubgeschwindigkeit(tmp.toInt());

    tmp = text_mitte(zeile_klartext, ANFAHRVORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
    }
    tasche_tmp.set_anfahrvorschub(tmp.toInt());

    tasche_tmp.set_drehwinkel(0);

    QString drehrichtung_fraeser;
    drehrichtung_fraeser = text_mitte(werkzeug, WKZ_DREHRICHTUNG, ENDE_EINTRAG);
    QString im_gegenlauf;
    im_gegenlauf = text_mitte(zeile_klartext, GEGENLAUF, ENDE_EINTRAG);
    if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_RECHTS)
    {
        if(im_gegenlauf.toInt()  == true)
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
        }else
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
        }
    }else if(drehrichtung_fraeser == WKZ_DREHRICHTUNG_LINKS)
    {
        if(im_gegenlauf.toInt()  == false)
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(true);
        }else
        {
            tasche_tmp.set_fraesbahn_in_uhrzeigersinn(false);
        }
    }else
    {
        *fehlertext  = "(Ausgabe nicht moeglich weil Drehrichtung Fraeser \"";
        *fehlertext += werkzeugname;
        *fehlertext += "\" unbekannt)";
        return *fehlertext;
    }

    if(text_mitte(werkzeug, WKZ_KANN_BOHREN, ENDE_EINTRAG) == "1")
    {
        tasche_tmp.set_fraeser_kabo(true);
    }else
    {
        tasche_tmp.set_fraeser_kabo(false);
    }

    std::string tasche = tasche_tmp.get_gcode();
    tmp = QString::fromStdString(tasche);
    gc += tmp;
    gc += "\n";

    return gc;
}

QString gcode::get_bohrung(QString zeile_klartext, QString *fehlertext, double ax, double ay)
{
    //es erfolgt keine erneute Prüfung ob zeile_klartext valide ist!!
    QString gc;
    fehlertext->clear();

    QString werkzeugname = text_mitte(zeile_klartext, WKZ_NAME, ENDE_EINTRAG);
    if(aktives_wkz == NICHT_DEFINIERT)
    {
        aktives_wkz = werkzeugname;
    }else if(aktives_wkz != werkzeugname)
    {
        *fehlertext = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
        return *fehlertext;
    }
    //Vorschübe setzen etc.:
    QString tmp;
    QString werkzeug = werkzeugdaten(werkzeugname);
    tmp = text_mitte(zeile_klartext, ANFAHRVORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_ANBOHRVORSCHUB, ENDE_EINTRAG);
    }
    eintauchvorschub = tmp.toDouble();
    tmp = text_mitte(zeile_klartext, VORSCHUB, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_BOHRVORSCHUB, ENDE_EINTRAG);
    }
    vorschub = tmp.toDouble();
    tmp = text_mitte(zeile_klartext, DREHZAHL, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_DREHZAHL, ENDE_EINTRAG);
    }
    drehzahl = tmp.toDouble();
    tmp = text_mitte(zeile_klartext, ZUSTELLUNG, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_BOZUTI, ENDE_EINTRAG);
    }
    zustellmass = tmp.toDouble();

    tmp = text_mitte(zeile_klartext, ANBOHRTI, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_BOANBOTI, ENDE_EINTRAG);
    }
    double anboti = tmp.toDouble();

    tmp = text_mitte(zeile_klartext, RESTBOHRTI, ENDE_EINTRAG);
    if(tmp == "AUTO")
    {
        tmp = text_mitte(werkzeug, WKZ_BOREBOTI, ENDE_EINTRAG);
    }
    double reboti = tmp.toDouble();

    double boti = text_mitte(zeile_klartext, BOHRTIEFE, ENDE_EINTRAG).toDouble();

    if(boti != 0)
    {
        //Anfahrpunkt:
        punkt3d startpunkt;
        startpunkt.set_x(text_mitte(zeile_klartext, POSITION_X, ENDE_EINTRAG).toDouble() + ax);
        startpunkt.set_y(text_mitte(zeile_klartext, POSITION_Y, ENDE_EINTRAG).toDouble() + ay);
        startpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());
        gc += "G0 X";
        gc += double_to_qstring(runden(startpunkt.x(),2));
        gc += " Y";
        gc += double_to_qstring(runden(startpunkt.y(),2));
        gc += " Z";
        gc += double_to_qstring(runden(startpunkt.z(),2));
        gc += " (Beginn der Bohrung)";
        gc += "\n";

        if(boti < 0)
        {
            boti =t.get_werkstueckdicke() - boti; //z.B. boti == -2 --> 19 - -2 == 19+2 == 21
        }
        if(zustellmass <= 0)
        {
            zustellmass = boti;
        }
        if(anboti <= 0)
        {
            anboti = zustellmass;
        }
        if(anboti > boti)
        {
            anboti = zustellmass;
        }
        if(reboti <= 0)
        {
            reboti = 0;
        }
        if(reboti > boti)
        {
            reboti = 0;
        }
        double z;
        QString ausfahren;
        ausfahren += "G1 Z";
        ausfahren += double_to_qstring(runden(t.get_werkstueckdicke()+2,2));
        ausfahren += " F";
        ausfahren += double_to_qstring(eintauchvorschub);
        ausfahren += "\n";

        if(boti > anboti + reboti)
        {
            //Anbohren:
            z =t.get_werkstueckdicke() - anboti;
            gc += "G1 Z";
            gc += double_to_qstring(runden(z,2));
            gc += " F";
            gc += double_to_qstring(eintauchvorschub);
            gc += " (Anbohren)";
            gc += "\n";
            gc += ausfahren;

            if(reboti > 0)
            {
                double restmass;
                restmass = boti - anboti - reboti;
                restmass = restmass - zustellmass;

                while(restmass > 0)
                {
                    //Zustellen:
                    z =t.get_werkstueckdicke() - boti + reboti + restmass;
                    gc += "G1 Z";
                    gc += double_to_qstring(runden(z,2));
                    gc += " F";
                    gc += double_to_qstring(vorschub);
                    gc += " (Zustellen)";
                    gc += "\n";
                    gc += ausfahren;
                    restmass = restmass - zustellmass;
                }
                //letzte Zustellung:
                z =t.get_werkstueckdicke() - boti + reboti;
                gc += "G1 Z";
                gc += double_to_qstring(runden(z,2));
                gc += " F";
                gc += double_to_qstring(vorschub);
                gc += " (letzte Zustellung)";
                gc += "\n";
                gc += ausfahren;

                //Restborung:
                z =t.get_werkstueckdicke() - boti;
                gc += "G1 Z";
                gc += double_to_qstring(runden(z,2));
                gc += " F";
                gc += double_to_qstring(vorschub);
                gc += " (Restbohrmass)";
                gc += "\n";
                gc += ausfahren;
            }else
            {
                double restmass;
                restmass = boti - anboti;
                restmass = restmass - zustellmass;

                while(restmass > 0)
                {
                    //Zustellen:
                    z =t.get_werkstueckdicke() - boti + reboti + restmass;
                    gc += "G1 Z";
                    gc += double_to_qstring(runden(z,2));
                    gc += " F";
                    gc += double_to_qstring(vorschub);
                    gc += " (Zustellen)";
                    gc += "\n";
                    gc += ausfahren;
                    restmass = restmass - zustellmass;
                }
                //Restborung:
                z =t.get_werkstueckdicke() - boti;
                gc += "G1 Z";
                gc += double_to_qstring(runden(z,2));
                gc += " F";
                gc += double_to_qstring(vorschub);
                gc += " (Restbohrtiefe)";
                gc += "\n";
                gc += ausfahren;
            }
        }else if(boti == anboti + reboti)
        {
            //heißt keine Zustellungen:
            //Anbohren:
            z =t.get_werkstueckdicke() - anboti;
            gc += "G1 Z";
            gc += double_to_qstring(runden(z,2));
            gc += " F";
            gc += double_to_qstring(eintauchvorschub);
            gc += " (Anbohren)";
            gc += "\n";
            gc += ausfahren;
            if(reboti > 0)
            {
                //Restborung:
                z =t.get_werkstueckdicke() - boti;
                gc += "G1 Z";
                gc += double_to_qstring(runden(z,2));
                gc += " F";
                gc += double_to_qstring(vorschub);
                gc += " (Restbohrmass)";
                gc += "\n";
                gc += ausfahren;
            }
        }else if(boti-anboti > 0)
        {
            //heißt keine Zustellungen und kein definiertes Restbohrmaß:
            //Anbohren:
            z =t.get_werkstueckdicke() - anboti;
            gc += "G1 Z";
            gc += double_to_qstring(runden(z,2));
            gc += " F";
            gc += double_to_qstring(eintauchvorschub);
            gc += " (Anbohren)";
            gc += "\n";
            gc += ausfahren;
            //Restborung:
            z =t.get_werkstueckdicke() - boti;
            gc += "G1 Z";
            gc += double_to_qstring(runden(z,2));
            gc += " F";
            gc += double_to_qstring(vorschub);
            gc += " (Resttiefe)";
            gc += "\n";
            gc += ausfahren;
        }else
        {
            //heiß Bohrung in einem Zug:
            //Restborung:
            z =t.get_werkstueckdicke() - boti;
            gc += "G1 Z";
            gc += double_to_qstring(runden(z,2));
            gc += " F";
            gc += double_to_qstring(vorschub);
            gc += "\n";
            gc += ausfahren;
        }

        //Abfahrpunkt:
        gc += "G0 X";
        gc += double_to_qstring(runden(startpunkt.x(),2));
        gc += " Y";
        gc += double_to_qstring(runden(startpunkt.y(),2));
        gc += " Z";
        gc += double_to_qstring(runden(startpunkt.z(),2));
        gc += " (Abfahren)";
        gc += "\n";

        gc += "\n";
    }

    return gc;
}

QString gcode::get_fkon(text_zeilenweise klartext, geometrietext fkon,\
                        QString *fehlertext, double ax, double ay)
{
    //fkonzeilen_t = zeilen aus text die fkon enthalten
    //fkonzeilen_kt = zeilen aus klartext die fkon enthalten
    //es erfolgt keine erneute Prüfung ob fkonzeilen valide sind!!
    QString gc;//gcode
    QString abfahrtyp;

    for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
    {
        QString zeile = klartext.zeile(i);

        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            QString werkzeugname = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            if(aktives_wkz == NICHT_DEFINIERT)
            {
                aktives_wkz = werkzeugname;
            }else if(aktives_wkz != werkzeugname)
            {
                *fehlertext = "Werkzeugwechsel werden derzeit nicht unterstuetzt!\nBitte blenden Sie nur Bearbeitungen mit dem selben Werkzeug gleichzeitig ein.";
                return *fehlertext;
            }
            QString zeile_fkon = fkon.get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            //Vorschübe setzen etc.:
            QString tmp;
            QString werkzeug = werkzeugdaten(werkzeugname);
            tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG);
            }
            eintauchvorschub = tmp.toDouble();
            tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_VORSCHUB, ENDE_EINTRAG);
            }
            vorschub = tmp.toDouble();
            tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_DREHZAHL, ENDE_EINTRAG);
            }
            drehzahl = tmp.toDouble();
            tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
            if(tmp == "AUTO")
            {
                tmp = text_mitte(werkzeug, WKZ_ZUSTELLTIEFE, ENDE_EINTRAG);
            }
            zustellmass = tmp.toDouble();

            QString anfahrtyp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);
            abfahrtyp = text_mitte(zeile, ABFAHRTYP, ENDE_EINTRAG);//brauchen wir später für das Abfahren

            if(zustellmass > 0)
            {
                //Gesamttiefe ermitteln:
                double tiefe_min =t.get_werkstueckdicke();
                for(uint ii=i ; \
                    ii<=klartext.zeilenanzahl() && !klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG); \
                    ii++)
                {
                    double tmp = text_mitte(klartext.zeile(ii), POSITION_Z, ENDE_EINTRAG).toDouble();
                    if(tmp < tiefe_min)
                    {
                        tiefe_min = tmp;
                    }
                }
                double fraestiefe_max =t.get_werkstueckdicke()- tiefe_min;
                double verschiebung_z = fraestiefe_max - zustellmass;

                for(uint ii=i ; \
                    verschiebung_z > 0;
                    ii++)
                {
                    if(ii == i)//Auftuf Fräser
                    {
                        if(anfahrtyp == ANABFAHRTYP_KEIN)
                        {
                            QString zeile_fkon2;
                            if(i+1<=fkon.get_text_zeilenweise().zeilenanzahl())//wenn es Zeilen dannach gibt
                            {
                                uint ii = i+1;
                                zeile_fkon2 = fkon.get_text_zeilenweise().zeile(ii);
                                while(klartext.zeile(ii).isEmpty()  &&  ii+1<=fkon.get_text_zeilenweise().zeilenanzahl()  )
                                {
                                    ii++;
                                    zeile_fkon2 =fkon.get_text_zeilenweise().zeile(ii);
                                }
                            }
                            text_zeilenweise fkon_tz2;
                            fkon_tz2.set_trennzeichen(TRZ_EL_);
                            fkon_tz2.set_text(zeile_fkon2);
                            text_zeilenweise geoelement2;
                            geoelement2.set_trennzeichen(TRZ_PA_);
                            geoelement2.set_text(fkon_tz2.zeile(1));

                            if(fkon_tz2.zeile(1).contains(STRECKE))
                            {
                                //Anfahrpunkt:
                                punkt3d startpunkt;
                                startpunkt.set_x(geoelement2.zeile(2).toDouble() + ax);
                                startpunkt.set_y(geoelement2.zeile(3).toDouble() + ay);
                                startpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());
                                gc += "G0 X";
                                gc += double_to_qstring(runden(startpunkt.x(),2));
                                gc += " Y";
                                gc += double_to_qstring(runden(startpunkt.y(),2));
                                gc += " Z";
                                gc += double_to_qstring(runden(startpunkt.z() + verschiebung_z,2));
                                gc += "\n";

                                //Eintauchen:
                                startpunkt.set_z(geoelement2.zeile(4).toDouble());
                                gc += "G1 Z";
                                gc += double_to_qstring(runden(startpunkt.z() + verschiebung_z,2));
                                gc += " F";
                                gc += double_to_qstring(eintauchvorschub);
                                gc += "\n";
                            }else if(fkon_tz2.zeile(1).contains(BOGEN))
                            {
                                //Anfahrpunkt:
                                punkt3d startpunkt;
                                startpunkt.set_x(geoelement2.zeile(2).toDouble() + ax);
                                startpunkt.set_y(geoelement2.zeile(3).toDouble() + ay);
                                startpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());
                                gc += "G0 X";
                                gc += double_to_qstring(runden(startpunkt.x(),2));
                                gc += " Y";
                                gc += double_to_qstring(runden(startpunkt.y(),2));
                                gc += " Z";
                                gc += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                                gc += "\n";

                                //Eintauchen:
                                startpunkt.set_z(geoelement2.zeile(4).toDouble());
                                gc += "G1 Z";
                                gc += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                                gc += " F";
                                gc += double_to_qstring(eintauchvorschub);
                                gc += "\n";
                            }
                        }else if(fkon_tz.zeile(1).contains(STRECKE))
                        {
                            //Anfahrpunkt:
                            punkt3d startpunkt;
                            startpunkt.set_x(geoelement.zeile(2).toDouble() + ax);
                            startpunkt.set_y(geoelement.zeile(3).toDouble() + ay);
                            startpunkt.set_z(geoelement.zeile(4).toDouble());
                            gc += "G0 X";
                            gc += double_to_qstring(runden(startpunkt.x(),2));
                            gc += " Y";
                            gc += double_to_qstring(runden(startpunkt.y(),2));
                            gc += " Z";
                            gc += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                            gc += "\n";

                            gc += "G1 X";
                            gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                            gc += " Y";
                            gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                            gc += " Z";
                            gc += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gc += " F";
                            gc += double_to_qstring(eintauchvorschub);
                            gc += "\n";
                        }else if(fkon_tz.zeile(1).contains(BOGEN))
                        {
                            //Anfahrpunkt:
                            punkt3d startpunkt;
                            startpunkt.set_x(geoelement.zeile(2).toDouble() + ax);
                            startpunkt.set_y(geoelement.zeile(3).toDouble() + ay);
                            startpunkt.set_z(geoelement.zeile(4).toDouble());
                            gc += "G0 X";
                            gc += double_to_qstring(runden(startpunkt.x(),2));
                            gc += " Y";
                            gc += double_to_qstring(runden(startpunkt.y(),2));
                            gc += " Z";
                            gc += double_to_qstring(runden(startpunkt.z()+ verschiebung_z,2));
                            gc += "\n";

                            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                            if(geoelement.zeile(9) == "ja")
                            {
                                gc += "G2";
                            }else
                            {
                                gc += "G3";
                            }
                            gc += " X";
                            gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                            gc += " Y";
                            gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                            gc += " Z";
                            gc += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gc += " I";
                            gc += double_to_qstring(runden(I,2));
                            gc += " J";
                            gc += double_to_qstring(runden(J,2));
                            gc += " F";
                            gc += double_to_qstring(eintauchvorschub);
                            gc += "\n";
                        }
                    }else if(klartext.zeile(ii).contains(FRAESERGERADE_DIALOG))
                    {
                        QString zeile_fkon =t.get_text_zeilenweise().zeile(ii);
                        text_zeilenweise fkon_tz;
                        fkon_tz.set_trennzeichen(TRZ_EL_);
                        fkon_tz.set_text(zeile_fkon);
                        text_zeilenweise geoelement;
                        geoelement.set_trennzeichen(TRZ_PA_);
                        geoelement.set_text(fkon_tz.zeile(1));

                        gc += "G1 X";
                        gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                        gc += " Y";
                        gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                        gc += " Z";
                        gc += double_to_qstring(runden(geoelement.zeile(7).toDouble() + verschiebung_z,2));
                        gc += " F";
                        gc += double_to_qstring(vorschub);
                        gc += "\n";

                        if(fkon_tz.zeilenanzahl()==3)
                        {
                            geoelement.set_text(fkon_tz.zeile(2));
                            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                            if(geoelement.zeile(9) == "ja")
                            {
                                gc += "G2";
                            }else
                            {
                                gc += "G3";
                            }
                            gc += " X";
                            gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                            gc += " Y";
                            gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                            gc += " Z";
                            gc += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                            gc += " I";
                            gc += double_to_qstring(runden(I,2));
                            gc += " J";
                            gc += double_to_qstring(runden(J,2));
                            gc += " F";
                            gc += double_to_qstring(eintauchvorschub);
                            gc += "\n";
                        }
                    }else if(klartext.zeile(ii).contains(FRAESERBOGEN_DIALOG))
                    {
                        QString zeile_fkon =t.get_text_zeilenweise().zeile(ii);
                        text_zeilenweise fkon_tz;
                        fkon_tz.set_trennzeichen(TRZ_EL_);
                        fkon_tz.set_text(zeile_fkon);
                        text_zeilenweise geoelement;
                        geoelement.set_trennzeichen(TRZ_PA_);
                        geoelement.set_text(fkon_tz.zeile(1));

                        double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                        double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                        if(geoelement.zeile(9) == "ja")
                        {
                            gc += "G2";
                        }else
                        {
                            gc += "G3";
                        }
                        gc += " X";
                        gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                        gc += " Y";
                        gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                        gc += " Z";
                        gc += double_to_qstring(runden(geoelement.zeile(7).toDouble() + verschiebung_z,2));
                        gc += " I";
                        gc += double_to_qstring(runden(I,2));
                        gc += " J";
                        gc += double_to_qstring(runden(J,2));
                        gc += " F";
                        gc += double_to_qstring(eintauchvorschub);
                        gc += "\n";
                    }else if(klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG))
                    {
                        punkt3d endpunkt;
                        endpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());

                        if(abfahrtyp == ANABFAHRTYP_KEIN)
                        {
                            gc += "G1 Z";
                            gc += double_to_qstring(runden(endpunkt.z() + verschiebung_z,2));
                            gc += " F";
                            gc += double_to_qstring(eintauchvorschub);
                            gc += "\n";
                        }else
                        {
                            QString zeile_fkon =t.get_text_zeilenweise().zeile(ii);
                            text_zeilenweise fkon_tz;
                            fkon_tz.set_trennzeichen(TRZ_EL_);
                            fkon_tz.set_text(zeile_fkon);
                            text_zeilenweise geoelement;
                            geoelement.set_trennzeichen(TRZ_PA_);
                            geoelement.set_text(fkon_tz.zeile(1));

                            if(fkon_tz.zeile(1).contains(STRECKE))
                            {
                                gc += "G1 X";
                                gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                                gc += " Y";
                                gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                                gc += " Z";
                                gc += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                                gc += " F";
                                gc += double_to_qstring(eintauchvorschub);
                                gc += "\n";
                            }else if(fkon_tz.zeile(1).contains(BOGEN))
                            {
                                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                                if(geoelement.zeile(9) == "ja")
                                {
                                    gc += "G2";
                                }else
                                {
                                    gc += "G3";
                                }
                                gc += " X";
                                gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                                gc += " Y";
                                gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                                gc += " Z";
                                gc += double_to_qstring(runden(geoelement.zeile(7).toDouble()+ verschiebung_z,2));
                                gc += " I";
                                gc += double_to_qstring(runden(I,2));
                                gc += " J";
                                gc += double_to_qstring(runden(J,2));
                                gc += " F";
                                gc += double_to_qstring(eintauchvorschub);
                                gc += "\n";
                            }
                        }
                    }

                    if(klartext.zeile(ii).contains(FRAESERABFAHREN_DIALOG))
                    {
                        verschiebung_z = verschiebung_z - zustellmass;
                        ii = i-1;
                    }
                }
            }

            if(anfahrtyp == ANABFAHRTYP_KEIN)
            {
                QString zeile_fkon2;
                if(i+1<=fkon.get_text_zeilenweise().zeilenanzahl())//wenn es Zeilen dannach gibt
                {
                    uint ii = i+1;
                    zeile_fkon2 =fkon.get_text_zeilenweise().zeile(ii);
                    while(klartext.zeile(ii).isEmpty()  &&  fkon.get_text_zeilenweise().zeilenanzahl()  )
                    {
                        ii++;
                        zeile_fkon2 = fkon.get_text_zeilenweise().zeile(ii);
                    }
                }
                text_zeilenweise fkon_tz2;
                fkon_tz2.set_trennzeichen(TRZ_EL_);
                fkon_tz2.set_text(zeile_fkon2);
                text_zeilenweise geoelement2;
                geoelement2.set_trennzeichen(TRZ_PA_);
                geoelement2.set_text(fkon_tz2.zeile(1));

                if(fkon_tz2.zeile(1).contains(STRECKE))
                {
                    //Anfahrpunkt:
                    punkt3d startpunkt;
                    startpunkt.set_x(geoelement2.zeile(2).toDouble() + ax);
                    startpunkt.set_y(geoelement2.zeile(3).toDouble() + ay);
                    startpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());
                    gc += "G0 X";
                    gc += double_to_qstring(runden(startpunkt.x(),2));
                    gc += " Y";
                    gc += double_to_qstring(runden(startpunkt.y(),2));
                    gc += " Z";
                    gc += double_to_qstring(runden(startpunkt.z(),2));
                    gc += "\n";

                    //Eintauchen:
                    startpunkt.set_z(geoelement2.zeile(4).toDouble());
                    gc += "G1 Z";
                    gc += double_to_qstring(runden(startpunkt.z(),2));
                    gc += " F";
                    gc += double_to_qstring(eintauchvorschub);
                    gc += "\n";
                }else if(fkon_tz2.zeile(1).contains(BOGEN))
                {
                    //Anfahrpunkt:
                    punkt3d startpunkt;
                    startpunkt.set_x(geoelement2.zeile(2).toDouble() + ax);
                    startpunkt.set_y(geoelement2.zeile(3).toDouble() + ay);
                    startpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());
                    gc += "G0 X";
                    gc += double_to_qstring(runden(startpunkt.x(),2));
                    gc += " Y";
                    gc += double_to_qstring(runden(startpunkt.y(),2));
                    gc += " Z";
                    gc += double_to_qstring(runden(startpunkt.z(),2));
                    gc += "\n";

                    //Eintauchen:
                    startpunkt.set_z(geoelement2.zeile(4).toDouble());
                    gc += "G1 Z";
                    gc += double_to_qstring(runden(startpunkt.z(),2));
                    gc += " F";
                    gc += double_to_qstring(eintauchvorschub);
                    gc += "\n";
                }
            }else if(fkon_tz.zeile(1).contains(STRECKE))
            {
                //Anfahrpunkt:
                punkt3d startpunkt;
                startpunkt.set_x(geoelement.zeile(2).toDouble() + ax);
                startpunkt.set_y(geoelement.zeile(3).toDouble() + ay);
                startpunkt.set_z(geoelement.zeile(4).toDouble());
                gc += "G0 X";
                gc += double_to_qstring(runden(startpunkt.x(),2));
                gc += " Y";
                gc += double_to_qstring(runden(startpunkt.y(),2));
                gc += " Z";
                gc += double_to_qstring(runden(startpunkt.z(),2));
                gc += "\n";

                gc += "G1 X";
                gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                gc += " Y";
                gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                gc += " Z";
                gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gc += " F";
                gc += double_to_qstring(eintauchvorschub);
                gc += "\n";
            }else if(fkon_tz.zeile(1).contains(BOGEN))
            {
                //Anfahrpunkt:
                punkt3d startpunkt;
                startpunkt.set_x(geoelement.zeile(2).toDouble() + ax);
                startpunkt.set_y(geoelement.zeile(3).toDouble() + ay);
                startpunkt.set_z(geoelement.zeile(4).toDouble());
                gc += "G0 X";
                gc += double_to_qstring(runden(startpunkt.x(),2));
                gc += " Y";
                gc += double_to_qstring(runden(startpunkt.y(),2));
                gc += " Z";
                gc += double_to_qstring(runden(startpunkt.z(),2));
                gc += "\n";

                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                if(geoelement.zeile(9) == "ja")
                {
                    gc += "G2";
                }else
                {
                    gc += "G3";
                }
                gc += " X";
                gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                gc += " Y";
                gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                gc += " Z";
                gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gc += " I";
                gc += double_to_qstring(runden(I,2));
                gc += " J";
                gc += double_to_qstring(runden(J,2));
                gc += " F";
                gc += double_to_qstring(eintauchvorschub);
                gc += "\n";
            }
        }else if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            QString zeile_fkon =fkon.get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            gc += "G1 X";
            gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax, 2));
            gc += " Y";
            gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay, 2));
            gc += " Z";
            gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
            gc += " F";
            gc += double_to_qstring(vorschub);
            gc += "\n";

            if(fkon_tz.zeilenanzahl()==3)
            {
                geoelement.set_text(fkon_tz.zeile(2));
                double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                if(geoelement.zeile(9) == "ja")
                {
                    gc += "G2";
                }else
                {
                    gc += "G3";
                }
                gc += " X";
                gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                gc += " Y";
                gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                gc += " Z";
                gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                gc += " I";
                gc += double_to_qstring(runden(I,2));
                gc += " J";
                gc += double_to_qstring(runden(J,2));
                gc += " F";
                gc += double_to_qstring(eintauchvorschub);
                gc += "\n";
            }
        }else if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            QString zeile_fkon = fkon.get_text_zeilenweise().zeile(i);
            text_zeilenweise fkon_tz;
            fkon_tz.set_trennzeichen(TRZ_EL_);
            fkon_tz.set_text(zeile_fkon);
            text_zeilenweise geoelement;
            geoelement.set_trennzeichen(TRZ_PA_);
            geoelement.set_text(fkon_tz.zeile(1));

            double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
            double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

            if(geoelement.zeile(9) == "ja")
            {
                gc += "G2";
            }else
            {
                gc += "G3";
            }
            gc += " X";
            gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
            gc += " Y";
            gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
            gc += " Z";
            gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
            gc += " I";
            gc += double_to_qstring(runden(I,2));
            gc += " J";
            gc += double_to_qstring(runden(J,2));
            gc += " F";
            gc += double_to_qstring(eintauchvorschub);
            gc += "\n";
        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            punkt3d endpunkt;
            endpunkt.set_z(t.get_werkstueckdicke() +t.get_sicherheitsabstand());

            if(abfahrtyp == ANABFAHRTYP_KEIN)
            {
                gc += "G1 Z";
                gc += double_to_qstring(runden(endpunkt.z(),2));
                gc += " F";
                gc += double_to_qstring(eintauchvorschub);
                gc += "\n";
            }else
            {
                QString zeile_fkon =fkon.get_text_zeilenweise().zeile(i);
                text_zeilenweise fkon_tz;
                fkon_tz.set_trennzeichen(TRZ_EL_);
                fkon_tz.set_text(zeile_fkon);
                text_zeilenweise geoelement;
                geoelement.set_trennzeichen(TRZ_PA_);
                geoelement.set_text(fkon_tz.zeile(1));

                if(fkon_tz.zeile(1).contains(STRECKE))
                {
                    gc += "G1 X";
                    gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                    gc += " Y";
                    gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                    gc += " Z";
                    gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                    gc += " F";
                    gc += double_to_qstring(eintauchvorschub);
                    gc += "\n";
                }else if(fkon_tz.zeile(1).contains(BOGEN))
                {
                    double I = geoelement.zeile(10).toDouble() - geoelement.zeile(2).toDouble();
                    double J = geoelement.zeile(11).toDouble() - geoelement.zeile(3).toDouble();

                    if(geoelement.zeile(9) == "ja")
                    {
                        gc += "G2";
                    }else
                    {
                        gc += "G3";
                    }
                    gc += " X";
                    gc += double_to_qstring(runden(geoelement.zeile(5).toDouble() + ax,2));
                    gc += " Y";
                    gc += double_to_qstring(runden(geoelement.zeile(6).toDouble() + ay,2));
                    gc += " Z";
                    gc += double_to_qstring(runden(geoelement.zeile(7).toDouble(),2));
                    gc += " I";
                    gc += double_to_qstring(runden(I,2));
                    gc += " J";
                    gc += double_to_qstring(runden(J,2));
                    gc += " F";
                    gc += double_to_qstring(eintauchvorschub);
                    gc += "\n";
                }
            }

        }
    }

    return gc;
}
