#include "rechtecktasche.h"

rechtecktasche::rechtecktasche()
{
    //ctor
    set_bezugspunkt_nummer(MITTE);
    set_einfuegepunkt(0,0);
    set_laenge(5);
    set_breite(5);
    set_tiefe(5);
    set_zustellmass(0);
    set_radius_taschenecken(0);
    set_durchmesser_fraeser(10);
    set_sicherheitsabstand(10);
    set_vorschubgeschwindigkeit(500);
    set_anfahrvorschub(500);
    set_drehwinkel(0);
    set_fraesbahn_in_uhrzeigersinn(1);
    set_anz_nachkommastellen(2);
    set_fraeser_kabo(false);
}

rechtecktasche::~rechtecktasche()
{
    //dtor
}

void rechtecktasche::set_tiefe(float neue_tiefe)
{
    tiefe = neue_tiefe;
}
int rechtecktasche::set_zustellmass(float neues_Zustellmass)
{
    int fehlerwert = 0;
    if(neues_Zustellmass < 0)
    {
        neues_Zustellmass = - neues_Zustellmass;
        fehlerwert = 1;
    }
    zustellmass = neues_Zustellmass;
    return fehlerwert;
}
int rechtecktasche::set_radius_fraeser(float neuer_radius)
{
    int fehlerwert = 0;
    if(neuer_radius <= 0)
    {
        neuer_radius = 1;
        fehlerwert = 1;
    }
    if(neuer_radius*2 > get_laenge())
    {
        neuer_radius = 1;
        fehlerwert = 2;
    }
    if(neuer_radius*2 > get_breite())
    {
        neuer_radius = 1;
        fehlerwert = 3;
    }
    radius_freaser = neuer_radius;
    durchmesser_freaser = neuer_radius*2;
    return fehlerwert;
}
int rechtecktasche::set_durchmesser_fraeser(float neuer_durchmesser)
{
    return set_radius_fraeser(neuer_durchmesser/2);
}
int rechtecktasche::set_radius_taschenecken(float neuer_radius)
{
    int fehlerwert = 0;
    if(neuer_radius*2 >= get_laenge())
    {
        neuer_radius = get_laenge()/2;
        fehlerwert = 1;
    }
    if(neuer_radius*2 >= get_breite())
    {
        neuer_radius = get_breite()/2;
        fehlerwert = 2;
    }
    radius_taschenecken = neuer_radius;
    return fehlerwert;
}
int rechtecktasche::set_sicherheitsabstand(float neuer_abstand)
{
    int fehlerwert = 0;
    if(neuer_abstand == 0)
    {
        neuer_abstand = 1;
        fehlerwert = 1;
    }
    if(neuer_abstand < 0)
    {
        neuer_abstand = - neuer_abstand;
        fehlerwert = 2;
    }
    sicherheitsabstand = neuer_abstand;
    return fehlerwert;
}
void rechtecktasche::set_bezugshoehe(float neue_hoehe)
{
    bezugshoehe = neue_hoehe;
}
void rechtecktasche::set_ausraeumen(bool ja_ausraeumen)
{
    ausraeumen = ja_ausraeumen;
}
void rechtecktasche::set_vorschubgeschwindigkeit(int f)
{
    vorschubgeschwindigkeit = f;
}
void rechtecktasche::set_anfahrvorschub(int f)
{
    anfahrvorschub = f;
}
void rechtecktasche::set_drehwinkel(float neuer_winkel)
{
    drehwinkel = neuer_winkel;
}
void rechtecktasche::set_fraesbahn_in_uhrzeigersinn(bool ist_im_uhrzeigersinn)
{
    fraesbahn_im_uhrzeigersinn = ist_im_uhrzeigersinn;
}
void rechtecktasche::set_anz_nachkommastellen(int anz_neu)
{
    anz_nachkommastellen = anz_neu;
}
//------------------------------------------------------------------------------------------------------


float rechtecktasche::get_tiefe()
{
    return tiefe;
}
float rechtecktasche::get_zustellmass()
{
    return zustellmass;
}
float rechtecktasche::get_radius_fraeser()
{
    return radius_freaser;
}
float rechtecktasche::get_radius_taschenecken()
{
    return radius_taschenecken;
}
float rechtecktasche::get_sicherheitsabstand()
{
    return sicherheitsabstand;
}
float rechtecktasche::get_bezugshoehe()
{
    return bezugshoehe;
}
float rechtecktasche::get_durchmesser_fraeser()
{
    return durchmesser_freaser;
}
bool rechtecktasche::get_ausraemen_Wert()
{
    return ausraeumen;
}
int rechtecktasche::get_vorschubgeschwindigkeit()
{
    return vorschubgeschwindigkeit;
}
int rechtecktasche::get_anfahrvorschub()
{
    return anfahrvorschub;
}
rechteck rechtecktasche::get_rechteck()
{
    rechteck r;
    r.set_bezugspunkt_nummer(get_bezugspunkt_nummer());
    r.set_einfuegepunkt(get_einfuegepunkt());
    r.set_laenge(get_laenge());
    r.set_breite(get_breite());

    return r;
}
float rechtecktasche::get_drehwinkel()
{
    return drehwinkel;
}
bool rechtecktasche::get_fraesbahn_im_uhrzeigersinn()
{
    return fraesbahn_im_uhrzeigersinn;
}
int rechtecktasche::get_anz_nachkommastellen()
{
    return anz_nachkommastellen;
}

//--------------------------------------------------------------------------------------------------------------------------------

string rechtecktasche::get_gcode()
{
    string returnstring = "";

    //Fräser über Taschenmittelpunkt bringen:
    returnstring += "G00";//Eilgang
    returnstring += " ";
    returnstring += "X";
    returnstring += float_to_string(get_mittelpunkt_x());
    returnstring += " ";
    returnstring += "Y";
    returnstring += float_to_string(get_mittelpunkt_y());
    returnstring += " ";
    returnstring += "Z";
    returnstring += float_to_string(get_bezugshoehe() + get_sicherheitsabstand());
    returnstring += " (Beginn der Rechtecktasche)";
    returnstring += "\n";

    //temporäres Rechteck für Fräsbahn auf mitte Fräser erstellen:
    rechteck tmp;
    tmp.set_bezugspunkt_nummer(MITTE);
    tmp.set_einfuegepunkt(get_mittelpunkt());
    tmp.set_laenge(get_laenge() - get_durchmesser_fraeser());
    tmp.set_breite(get_breite() - get_durchmesser_fraeser());

    float aktuelle_zustellung = get_zustellmass();
    if(aktuelle_zustellung == 0)
    {
        aktuelle_zustellung = get_tiefe();
    }
    if(aktuelle_zustellung > get_tiefe())
    {
        aktuelle_zustellung = get_tiefe();
    }
    float tiefe_vor_zustellung;
    tiefe_vor_zustellung = get_bezugshoehe() + 2; //2mm über dem Werkstück
    while(aktuelle_zustellung <= get_tiefe())
    {
        if(get_ausraemen_Wert()==true)
        {
            returnstring += get_gcode_ausraumen(tmp, \
                                                get_radius_taschenecken()-get_radius_fraeser(), \
                                                tiefe_vor_zustellung, \
                                                get_bezugshoehe()-aktuelle_zustellung);
        }else{
            if(get_fraesbahn_im_uhrzeigersinn() == true)
            {
                returnstring += get_rechteckbahn_UZS(tmp, \
                                                     get_radius_taschenecken()-get_radius_fraeser(), \
                                                     tiefe_vor_zustellung, \
                                                     get_bezugshoehe()-aktuelle_zustellung);
            }else{
                returnstring += get_rechteckbahn_GUZS(tmp,
                                                      get_radius_taschenecken()-get_radius_fraeser(), \
                                                      tiefe_vor_zustellung, \
                                                      get_bezugshoehe()-aktuelle_zustellung);
            }

        }
        tiefe_vor_zustellung = get_bezugshoehe() - aktuelle_zustellung;
        if(get_zustellmass() == 0) break;//while-Schleife verlassen nach dem ersten Durchlauf wenn keine Zustellung!
        if(aktuelle_zustellung == get_tiefe()) break;//while-Schleife verlassen, weil nicht weiter zugestellt werden muss!
        if(aktuelle_zustellung + get_zustellmass() < get_tiefe())
        {
            aktuelle_zustellung = aktuelle_zustellung + get_zustellmass();
        }else
        {
            aktuelle_zustellung = get_tiefe();
        }
    }
    //Abfahren:
    if(tmp.get_laenge() > radius_freaser*2  &&
       tmp.get_breite() > radius_freaser*2)
    {
        if(get_fraesbahn_im_uhrzeigersinn() == true)
        {   //Abfahren im Uhrzeigersinn:
            punkt p_xy;
            p_xy.x = tmp.get_mittelpunkt_x() - get_radius_fraeser();
            p_xy.y = tmp.get_eckpunkt_unten_rechts_y() + get_radius_fraeser();
            p_xy = drehen(tmp.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
            punkt p_ij;
            p_ij.x = 0;
            p_ij.y = +get_radius_fraeser();
            punkt bezugspunkt_ij;
            bezugspunkt_ij.x =tmp.get_mittelpunkt_x();
            bezugspunkt_ij.y =tmp.get_eckpunkt_unten_rechts_y();
            p_ij = drehen_ij(tmp.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
            returnstring += "G02";
            returnstring += " ";
            returnstring += "X";
            returnstring += float_to_string(p_xy.x);
            returnstring += " ";
            returnstring += "Y";
            returnstring += float_to_string(p_xy.y);
            returnstring += " ";
            returnstring += "Z";
            returnstring += float_to_string(get_bezugshoehe() + get_sicherheitsabstand());
            returnstring += " ";
            returnstring +="I";
            returnstring += float_to_string(p_ij.x);
            returnstring += " ";
            returnstring += "J";
            returnstring += float_to_string(p_ij.y);
            returnstring += " (Abfahren)";
            returnstring += "\n";
        }else{
            //Abfahren im Gegen-Uhrzeigersinn:
            punkt p_xy;
            p_xy.x = tmp.get_mittelpunkt_x() + get_radius_fraeser();
            p_xy.y = tmp.get_eckpunkt_unten_rechts_y() + get_radius_fraeser();
            p_xy = drehen(tmp.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
            punkt p_ij;
            p_ij.x = 0;
            p_ij.y = +get_radius_fraeser();
            punkt bezugspunkt_ij;
            bezugspunkt_ij.x =tmp.get_mittelpunkt_x();
            bezugspunkt_ij.y =tmp.get_eckpunkt_unten_rechts_y();
            p_ij = drehen_ij(tmp.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
            returnstring += "G03";
            returnstring += " ";
            returnstring += "X";
            returnstring += float_to_string(p_xy.x);
            returnstring += " ";
            returnstring += "Y";
            returnstring += float_to_string(p_xy.y);
            returnstring += " ";
            returnstring += "Z";
            returnstring += float_to_string(get_bezugshoehe() + get_sicherheitsabstand());
            returnstring += " ";
            returnstring +="I";
            returnstring += float_to_string(p_ij.x);
            returnstring += " ";
            returnstring += "J";
            returnstring += float_to_string(p_ij.y);
            returnstring += " (Abfahren)";
            returnstring += "\n";
        }
    }else
    {
        returnstring += "G01";
        returnstring += " ";
        returnstring += "Z";
        returnstring += float_to_string(get_bezugshoehe() + get_sicherheitsabstand());
        returnstring += " (Abfahren)";
        returnstring += "\n";
    }
    return returnstring;
}

string rechtecktasche::get_gcode_ausraumen(rechteck r, float radius, \
                                           float tiefe_vor_eintauchen, float tiefe_nach_eintauchen)
{
    //Das an die Funktioen übergebene Rechteck beschreibt die größe der Fräsbahn auf Mitte des Fräsers
    int anzahl_der_parallelbahnen = 0;
    float l = r.get_laenge();
    float b = r.get_breite();
    float dm = get_durchmesser_fraeser();
    //float rad = get_radius_fraeser();
    float ueberlappung = 1; //Überlappung der einzelnen Fräsbahnen
    float kleinerer_wert;
    if(l<b)
    {
        kleinerer_wert = l;
    }else{
        //b<=l
        kleinerer_wert = b;
    }
    kleinerer_wert = kleinerer_wert/2;
    anzahl_der_parallelbahnen = aufrunden(kleinerer_wert/(dm-ueberlappung));
    l = l-((dm-ueberlappung)*2*anzahl_der_parallelbahnen);
    b = b-((dm-ueberlappung)*2*anzahl_der_parallelbahnen);
    string gcode;
    rechteck tmp;
    tmp.set_bezugspunkt_nummer(MITTE);
    tmp.set_einfuegepunkt(get_mittelpunkt());
    float tmp_radius;
    int i = 0;
    while(anzahl_der_parallelbahnen >= 0)
    {
        float tal = r.get_laenge() - anzahl_der_parallelbahnen * (dm-ueberlappung)*2;
        float tab = r.get_breite() - anzahl_der_parallelbahnen * (dm-ueberlappung)*2;
        if(  (tal <= 0)  ||  (tab <= 0)  )
        {
            tal = tal+dm;
            tab = tab+dm;
            if(  (tal <= 0)  ||  (tab <= 0)  )
            {
                anzahl_der_parallelbahnen--;
                continue;
            }
        }
        tmp.set_laenge(tal);
        tmp.set_breite(tab);
        tmp_radius = radius - (anzahl_der_parallelbahnen * (dm-ueberlappung));
        if(tmp_radius < 0)
        {
            tmp_radius = 0;
        }
        float tiefe_vor_tmp;
        if(i==0)
        {
            tiefe_vor_tmp = tiefe_vor_eintauchen;
        }else{
            tiefe_vor_tmp = tiefe_nach_eintauchen;
        }
        if(get_fraesbahn_im_uhrzeigersinn() == true)
        {
            gcode += get_rechteckbahn_UZS(tmp, tmp_radius, tiefe_vor_tmp, tiefe_nach_eintauchen);
        }else{
            gcode += get_rechteckbahn_GUZS(tmp, tmp_radius, tiefe_vor_tmp, tiefe_nach_eintauchen);
        }
        anzahl_der_parallelbahnen--;
        i++;
    }
    return gcode;
}

string rechtecktasche::get_rechteckbahn_UZS(rechteck r, float radius, \
                                            float tiefe_vor_eintauchen, float tiefe_nach_eintauchen)
{
    //Das an die Funktioen übergebene Rechteck beschreibt die größe der Fräsbahn auf Mitte des Fräsers
    string gcode;
    punkt startpunkt;
    if(r.get_laenge()-radius*2 > radius_freaser*2  &&
       r.get_breite()-radius*2 > radius_freaser*2)
    {
        startpunkt.y = r.get_eckpunkt_unten_links_y() + get_radius_fraeser();
        startpunkt.x = r.get_mittelpunkt_x() + get_radius_fraeser();
    }else
    {
        if(fraeser_kabo == true)
        {
            startpunkt.y = r.get_eckpunkt_unten_links_y();
            startpunkt.x = r.get_mittelpunkt_x();
        }else
        {
            startpunkt.y = r.get_eckpunkt_unten_links_y() + get_radius_fraeser();
            startpunkt.x = r.get_mittelpunkt_x() + get_radius_fraeser();
        }
    }


    //Fräser zum Startpunkt bringen:
    {
    punkt p_xy;
    p_xy.x = startpunkt.x;
    p_xy.y = startpunkt.y;
    p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
    gcode += "G01";//geradlinige interpolation
    gcode += " ";
    gcode += "X";
    gcode += float_to_string(p_xy.x);
    gcode += " ";
    gcode += "Y";
    gcode += float_to_string(p_xy.y);
    gcode += " ";
    gcode += "Z";
    gcode += float_to_string(tiefe_vor_eintauchen);
    gcode += " ";
    gcode += "F";
    if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
    {
        gcode += int_to_string(get_vorschubgeschwindigkeit());
    }else{
        gcode += int_to_string(get_anfahrvorschub());
    }
    gcode += " (Startpunkt)";
    gcode += "\n";
    if(tiefe_vor_eintauchen != tiefe_nach_eintauchen)
    {
        gcode += "(Tiefenaenderung)\n";
    }
    }

    //Eintauchen:
    if(r.get_laenge()-radius*2 > radius_freaser*2  &&
       r.get_breite()-radius*2 > radius_freaser*2)
    {
    punkt p_xy;
    p_xy.x = r.get_mittelpunkt_x();
    p_xy.y = r.get_eckpunkt_unten_links_y();
    p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
    punkt p_ij;
    p_ij.x = -get_radius_fraeser();
    p_ij.y = 0;
    punkt bezugspunkt_ij;
    bezugspunkt_ij.x =startpunkt.x;
    bezugspunkt_ij.y =startpunkt.x;
    p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
    gcode += "G02"; //Kreisbeweging CW
    gcode += " ";
    gcode += "X";
    gcode += float_to_string(p_xy.x);
    gcode += " ";
    gcode += "Y";
    gcode += float_to_string(p_xy.y);
    gcode += " ";
    gcode += "Z";
    gcode += float_to_string(tiefe_nach_eintauchen);
    gcode += " ";
    gcode +="I";
    gcode += float_to_string(p_ij.x);
    gcode += " ";
    gcode += "J";
    gcode += float_to_string(p_ij.y);
    gcode += " ";
    gcode += "F";
    if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
    {
        gcode += int_to_string(get_vorschubgeschwindigkeit());
    }else{
        gcode += int_to_string(get_anfahrvorschub());
    }
    gcode += " (unten Mitte am Konturanfang)";
    gcode += "\n";
    }else
    {
        if(fraeser_kabo == true)
        {
            gcode += "G01";
            gcode += " ";
            gcode += "Z";
            gcode += float_to_string(tiefe_nach_eintauchen);
            gcode += "F";
            if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
            {
                gcode += int_to_string(get_vorschubgeschwindigkeit());
            }else{
                gcode += int_to_string(get_anfahrvorschub());
            }
            gcode += " (unten Mitte am Konturanfang)";
            gcode += "\n";
        }else
        {
            punkt p_xy;
            p_xy.x = r.get_mittelpunkt_x();
            p_xy.y = r.get_eckpunkt_unten_links_y();
            p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
            punkt p_ij;
            p_ij.x = -get_radius_fraeser();
            p_ij.y = 0;
            punkt bezugspunkt_ij;
            bezugspunkt_ij.x =startpunkt.x;
            bezugspunkt_ij.y =startpunkt.x;
            p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
            gcode += "G02"; //Kreisbeweging CW
            gcode += " ";
            gcode += "X";
            gcode += float_to_string(p_xy.x);
            gcode += " ";
            gcode += "Y";
            gcode += float_to_string(p_xy.y);
            gcode += " ";
            gcode += "Z";
            gcode += float_to_string(tiefe_nach_eintauchen);
            gcode += " ";
            gcode +="I";
            gcode += float_to_string(p_ij.x);
            gcode += " ";
            gcode += "J";
            gcode += float_to_string(p_ij.y);
            gcode += " ";
            gcode += "F";
            if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
            {
                gcode += int_to_string(get_vorschubgeschwindigkeit());
            }else{
                gcode += int_to_string(get_anfahrvorschub());
            }
            gcode += " (unten Mitte am Konturanfang)";
            gcode += "\n";
        }
    }

    if(radius > 0)
    {   //links unten mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_links_x()+ radius;
        p_xy.y = r.get_eckpunkt_unten_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_unten_links_x();
        p_xy.y = r.get_eckpunkt_unten_links_y() + radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = 0;
        p_ij.y = radius;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_unten_links_x()+ radius;
        bezugspunkt_ij.y =r.get_eckpunkt_unten_links_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G02";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten links)";
        gcode += "\n";
    }else{
        //links unten eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_links_x();
        p_xy.y = r.get_eckpunkt_unten_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten links)";
        gcode += "\n";
        }

    if(radius > 0)
    {   //links oben mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_links_x();
        p_xy.y = r.get_eckpunkt_oben_links_y() - radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_oben_links_x() + radius;
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = +radius;
        p_ij.y = 0;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_unten_links_x();
        bezugspunkt_ij.y =r.get_eckpunkt_oben_links_y() - radius;
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G02";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben links)";
        gcode += "\n";
    }else{
        //links oben eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_links_x();
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben links)";
        gcode += "\n";
    }

    if(radius > 0)
    {   //rechts oben mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_rechts_x() - radius;
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_oben_rechts_x();
        p_xy.y = r.get_eckpunkt_oben_rechts_y() - radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = 0;
        p_ij.y = -radius;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_oben_rechts_x() - radius;
        bezugspunkt_ij.y =r.get_eckpunkt_oben_links_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G02";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        //gcode += "0";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben rechts)";
        gcode += "\n";
    }else{
        //rechts oben eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_rechts_x();
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben rechts)";
        gcode += "\n";
    }
    if(radius > 0)
    {   //rechts unten mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_rechts_x();
        p_xy.y = r.get_eckpunkt_unten_rechts_y() + radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_unten_rechts_x() - radius;
        p_xy.y = r.get_eckpunkt_unten_rechts_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = -radius;
        p_ij.y = 0;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_oben_rechts_x();
        bezugspunkt_ij.y =r.get_eckpunkt_unten_rechts_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G02";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten rechts)";
        gcode += "\n";
    }else{
        //rechts unten eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_rechts_x();
        p_xy.y = r.get_eckpunkt_unten_rechts_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten rechts)";
        gcode += "\n";
    }

    //unten mitte:
    punkt p_xy;
    p_xy.x = r.get_mittelpunkt_x();
    p_xy.y = r.get_eckpunkt_unten_rechts_y();
    p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
    gcode += "G01";
    gcode += " ";
    gcode += "X";
    gcode += float_to_string(p_xy.x);
    gcode += " ";
    gcode += "Y";
    gcode += float_to_string(p_xy.y);
    gcode += " ";
    gcode += "F";
    gcode += int_to_string(get_vorschubgeschwindigkeit());
    gcode += " (unten Mitte am Konturende)";
    gcode += "\n";

    return gcode;

}

string rechtecktasche::get_rechteckbahn_GUZS(rechteck r, float radius, float tiefe_vor_eintauchen, \
                                             float tiefe_nach_eintauchen)
{
    //Das an die Funktioen übergebene Rechteck beschreibt die größe der Fräsbahn auf Mitte des Fräsers
    string gcode;
    punkt startpunkt;
    if(r.get_laenge()-radius*2 > radius_freaser*2  &&
       r.get_breite()-radius*2 > radius_freaser*2)
    {
        startpunkt.y = r.get_eckpunkt_unten_links_y() + get_radius_fraeser();
        startpunkt.x = r.get_mittelpunkt_x() - get_radius_fraeser();
    }else
    {
        if(fraeser_kabo == true)
        {
            startpunkt.y = r.get_eckpunkt_unten_links_y();
            startpunkt.x = r.get_mittelpunkt_x();
        }else
        {
            startpunkt.y = r.get_eckpunkt_unten_links_y() + get_radius_fraeser();
            startpunkt.x = r.get_mittelpunkt_x() - get_radius_fraeser();
        }
    }


    //Fräser zum Startpunkt bringen:
    {
    punkt p_xy;
    p_xy.x = startpunkt.x;
    p_xy.y = startpunkt.y;
    p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
    gcode += "G01";//geradlinige interpolation
    gcode += " ";
    gcode += "X";
    gcode += float_to_string(p_xy.x);
    gcode += " ";
    gcode += "Y";
    gcode += float_to_string(p_xy.y);
    gcode += " ";
    gcode += "Z";
    gcode += float_to_string(tiefe_vor_eintauchen);
    gcode += " ";
    gcode += "F";
    if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
    {
        gcode += int_to_string(get_vorschubgeschwindigkeit());
    }else{
        gcode += int_to_string(get_anfahrvorschub());
    }
    gcode += " (Startpunkt)";
    gcode += "\n";
    if(tiefe_vor_eintauchen != tiefe_nach_eintauchen)
    {
        gcode += "(Tiefenaenderung)\n";
    }
    }

    //Eintauchen:
    if(r.get_laenge()-radius*2 > radius_freaser*2  &&
       r.get_breite()-radius*2 > radius_freaser*2)
    {
        punkt p_xy;
        p_xy.x = r.get_mittelpunkt_x();
        p_xy.y = r.get_eckpunkt_unten_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = get_radius_fraeser();
        p_ij.y = 0;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =startpunkt.x;
        bezugspunkt_ij.y =startpunkt.x;
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G03"; //Kreisbeweging ACW
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "Z";
        gcode += float_to_string(tiefe_nach_eintauchen);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
        {
            gcode += int_to_string(get_vorschubgeschwindigkeit());
        }else{
            gcode += int_to_string(get_anfahrvorschub());
        }
        gcode += " (unten Mitte am Konturanfang)";
        gcode += "\n";
    }else
    {
        if(fraeser_kabo == true)
        {
            gcode += "G01";
            gcode += " ";
            gcode += "Z";
            gcode += float_to_string(tiefe_nach_eintauchen);
            gcode += "F";
            if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
            {
                gcode += int_to_string(get_vorschubgeschwindigkeit());
            }else{
                gcode += int_to_string(get_anfahrvorschub());
            }
            gcode += " (unten Mitte am Konturanfang)";
            gcode += "\n";
        }else
        {
            punkt p_xy;
            p_xy.x = r.get_mittelpunkt_x();
            p_xy.y = r.get_eckpunkt_unten_links_y();
            p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
            punkt p_ij;
            p_ij.x = get_radius_fraeser();
            p_ij.y = 0;
            punkt bezugspunkt_ij;
            bezugspunkt_ij.x =startpunkt.x;
            bezugspunkt_ij.y =startpunkt.x;
            p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
            gcode += "G03"; //Kreisbeweging ACW
            gcode += " ";
            gcode += "X";
            gcode += float_to_string(p_xy.x);
            gcode += " ";
            gcode += "Y";
            gcode += float_to_string(p_xy.y);
            gcode += " ";
            gcode += "Z";
            gcode += float_to_string(tiefe_nach_eintauchen);
            gcode += " ";
            gcode +="I";
            gcode += float_to_string(p_ij.x);
            gcode += " ";
            gcode += "J";
            gcode += float_to_string(p_ij.y);
            gcode += " ";
            gcode += "F";
            if(tiefe_vor_eintauchen == tiefe_nach_eintauchen)
            {
                gcode += int_to_string(get_vorschubgeschwindigkeit());
            }else{
                gcode += int_to_string(get_anfahrvorschub());
            }
            gcode += " (unten Mitte am Konturanfang)";
            gcode += "\n";
        }
    }


    if(radius > 0)
    {   //rechts unten mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_rechts_x()- radius;
        p_xy.y = r.get_eckpunkt_unten_rechts_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_unten_rechts_x();
        p_xy.y = r.get_eckpunkt_unten_rechts_y() + radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = 0;
        p_ij.y = radius;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_unten_rechts_x() + radius;
        bezugspunkt_ij.y =r.get_eckpunkt_unten_rechts_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G03";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten links)";
        gcode += "\n";
    }else{
        //rechts unten eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_rechts_x();
        p_xy.y = r.get_eckpunkt_unten_rechts_y() + radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten links)";
        gcode += "\n";
        }

    if(radius > 0)
    {   //rechts oben mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_rechts_x();
        p_xy.y = r.get_eckpunkt_oben_rechts_y() - radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_oben_rechts_x() - radius;
        p_xy.y = r.get_eckpunkt_oben_rechts_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = -radius;
        p_ij.y = 0;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_unten_rechts_x();
        bezugspunkt_ij.y =r.get_eckpunkt_oben_rechts_y() - radius;
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G03";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben links)";
        gcode += "\n";
    }else{
        //rechts oben eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_unten_rechts_x();
        p_xy.y = r.get_eckpunkt_oben_rechts_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben links)";
        gcode += "\n";
    }

    if(radius > 0)
    {   //links oben mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_links_x() + radius;
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_oben_links_x();
        p_xy.y = r.get_eckpunkt_oben_links_y() - radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = 0;
        p_ij.y = -radius;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_oben_links_x() + radius;
        bezugspunkt_ij.y =r.get_eckpunkt_oben_links_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G03";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben rechts)";
        gcode += "\n";
    }else{
        //links oben eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_links_x();
        p_xy.y = r.get_eckpunkt_oben_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (oben rechts)";
        gcode += "\n";
    }
    if(radius > 0)
    {   //links unten mit Rundung:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_links_x();
        p_xy.y = r.get_eckpunkt_unten_links_y() + radius;
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += "\n";

        p_xy.x = r.get_eckpunkt_unten_links_x() + radius;
        p_xy.y = r.get_eckpunkt_unten_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        punkt p_ij;
        p_ij.x = radius;
        p_ij.y = 0;
        punkt bezugspunkt_ij;
        bezugspunkt_ij.x =r.get_eckpunkt_oben_links_x();
        bezugspunkt_ij.y =r.get_eckpunkt_unten_links_y();
        p_ij = drehen_ij(r.get_mittelpunkt(), get_drehwinkel(), 0,bezugspunkt_ij, p_ij);
        gcode += "G03";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode +="I";
        gcode += float_to_string(p_ij.x);
        gcode += " ";
        gcode += "J";
        gcode += float_to_string(p_ij.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten rechts)";
        gcode += "\n";
    }else{
        //links unten eckig:
        punkt p_xy;
        p_xy.x = r.get_eckpunkt_oben_links_x();
        p_xy.y = r.get_eckpunkt_unten_links_y();
        p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
        gcode += "G01";
        gcode += " ";
        gcode += "X";
        gcode += float_to_string(p_xy.x);
        gcode += " ";
        gcode += "Y";
        gcode += float_to_string(p_xy.y);
        gcode += " ";
        gcode += "F";
        gcode += int_to_string(get_vorschubgeschwindigkeit());
        gcode += " (unten rechts)";
        gcode += "\n";
    }

    //unten mitte:
    punkt p_xy;
    p_xy.x = r.get_mittelpunkt_x();
    p_xy.y = r.get_eckpunkt_unten_rechts_y();
    p_xy = drehen(r.get_mittelpunkt(), p_xy, get_drehwinkel(), 0);
    gcode += "G01";
    gcode += " ";
    gcode += "X";
    gcode += float_to_string(p_xy.x);
    gcode += " ";
    gcode += "Y";
    gcode += float_to_string(p_xy.y);
    gcode += " ";
    gcode += "F";
    gcode += int_to_string(get_vorschubgeschwindigkeit());
    gcode += " (unten Mitte am Konturende)";
    gcode += "\n";

    return gcode;

}












