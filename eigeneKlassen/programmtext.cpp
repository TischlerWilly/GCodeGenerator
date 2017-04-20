#include "programmtext.h"

//------------------------------------------------------------
//public:
programmtext::programmtext()
{
    clear();
    warnungen_einschalten(true);
}

void programmtext::set_text(QString neuer_Text)
{
    text.set_text(neuer_Text);
    QString tmp = text.get_text();
    if(!tmp.contains(LISTENENDE))
    {
        text.zeile_anhaengen(LISTENENDE);
    }
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
}

void programmtext::clear()
{
    text.clear();
    klartext.clear();
    var.clear();
    anzeigetext.clear();
    werkstuecklaenge = 0;
    werkstueckbreite = 0;
    hat_programmkopf = false;
    hat_programmende = false;
    sicherheitsabstand = 5;
    min_x = 0;
    min_y = 0;
    max_x = 0;
    max_y = 0;
    anz_faufr = 0;
    anz_fabfa = 0;
    warnung_frDial = false;
}

void programmtext::clear_ausser_text()
{
    klartext.clear();
    var.clear();
    anzeigetext.clear();
    werkstuecklaenge = 0;
    werkstueckbreite = 0;
    hat_programmkopf = false;
    hat_programmende = false;
    sicherheitsabstand = 5;
    min_x = 0;
    min_y = 0;
    max_x = 0;
    max_y = 0;
    anz_faufr = 0;
    anz_fabfa = 0;
    warnung_frDial = false;
}

QString programmtext::get_text()
{
    return text.get_text();
}

text_zeilenweise programmtext::get_text_zeilenweise()
{
    return text;
}

QString programmtext::get_klartext()
{
    QString returnstring;
    for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
    {
        QString tmp = klartext.zeile(i);
        if(!tmp.isEmpty())
        {
            returnstring += tmp;
        }
    }
    return returnstring;
}

text_zeilenweise programmtext::get_klartext_zeilenweise()
{
    return klartext;
}

QString programmtext::get_variablen()
{
    QString returnstring;
    for(uint i=1 ; i<=var.zeilenanzahl() ; i++)
    {
        QString tmp = var.zeile(i);
        if(!tmp.isEmpty())
        {
            returnstring += tmp;
        }
    }
    return returnstring;
}

text_zeilenweise programmtext::get_variablen_zeilenweise()
{
    return var;
}

QString programmtext::get_anzeigetext()
{
    return anzeigetext.get_text();
}

text_zeilenweise programmtext::get_anzeigetext_zeilenweise()
{
    return anzeigetext;
}

QString programmtext::get_anzeigetext_zeile(uint zeilennummer)
{
    return anzeigetext.zeile(zeilennummer);
}

void programmtext::warnungen_einschalten(bool einschalten)
{
    warnungen_sind_eingeschaltet = einschalten;
}

//---------------------------------------

float programmtext::get_werkstuecklaenge()
{
    return werkstuecklaenge;
}

float programmtext::get_werkstueckbreite()
{
    return werkstueckbreite;
}

float programmtext::get_werkstueckdicke()
{
    return werkstueckdicke;
}

float programmtext::get_sicherheitsabstand()
{
    return sicherheitsabstand;
}

float programmtext::get_min_x()
{
    return min_x;
}

float programmtext::get_max_x()
{
    return max_x;
}

float programmtext::get_min_y()
{
    return min_y;
}

float programmtext::get_max_y()
{
    return max_y;
}

//---------------------------------------
QString programmtext::zeile(uint zeilennummer)
{
    if(zeilennummer > text.zeilenanzahl())
    {
        return "Fehler! Ungueltige Zeilennummer";
    }else
    {
        return text.zeile(zeilennummer);
    }
}

QString programmtext::zeilen(uint zeilennummer_beginn, uint zeilenmenge)
{
    if(zeilennummer_beginn+zeilenmenge-1  > text.zeilenanzahl())
    {
        return "Fehler! Ungueltige Zeilennummer";
    }else
    {
        QString tmp;
        for(uint i=zeilennummer_beginn ; i<zeilennummer_beginn+zeilenmenge; i++)
        {
            if(!text.zeile(i).contains(LISTENENDE))
            {
                if(i!=zeilennummer_beginn)
                {
                    tmp += "\n";
                }
                tmp += text.zeile(i);
            }
        }
        return tmp;
    }
}

int programmtext::zeile_loeschen(uint zeilennummer)
{
    QString zeilentext = text.zeile(zeilennummer);
    if(zeilentext.contains(LISTENENDE))
    {
        return 0; //Listenende darf nicht gelöscht werden!
    }
    if(zeilennummer > text.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    text.zeile_loeschen(zeilennummer);
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

int programmtext::zeilen_loeschen(uint zeilennummer_beginn, uint zeilenmenge)
{
    if(zeilennummer_beginn+zeilenmenge-1 > text.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    for(uint i=zeilennummer_beginn+zeilenmenge-1; i>=zeilennummer_beginn ; i--)
    {
        QString tmp = text.zeile(i);
        if(!tmp.contains(LISTENENDE))
        {
            text.zeile_loeschen(i);
        }
    }

    //text.zeilen_loeschen(zeilennummer_beginn, zeilenmenge);
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

int programmtext::zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext)
{
    if(zeilentext == LISTENENDE)
    {
        return 0;
    }
    if(zeilennummer_vor_neuer_zeile > text.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer_vor_neuer_zeile == 0)
    {
        text.zeile_vorwegsetzen(zeilentext);
    }else
    {
        text.zeile_einfuegen(zeilennummer_vor_neuer_zeile, zeilentext);
    }
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

int programmtext::zeilen_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext)
{
    if(zeilennummer_vor_neuer_zeile > text.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    text_zeilenweise tz;
    tz.set_text(zeilentext);
    for(uint i=1 ; i<=tz.zeilenanzahl() ;i++)
    {
        QString zeile = tz.zeile(i);
        if(zeile == LISTENENDE)
        {
            return 0;
        }
        if(  (zeilennummer_vor_neuer_zeile == 0)  &&  (i==1)  )
        {
            text.zeile_vorwegsetzen(zeile);
        }else
        {
            text.zeile_einfuegen(zeilennummer_vor_neuer_zeile+i-1, zeile);
        }
    }
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

void programmtext::zeile_anhaengen(QString zeilentext)
{
    if(zeilentext == LISTENENDE)
    {
        return;
    }
    text.zeilen_anhaengen(zeilentext);
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
}

int programmtext::zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext)
{
    QString alter_text;
    alter_text = text.zeile(zeilennummer);
    if(alter_text == LISTENENDE)
    {
        return 0;
    }
    QString zeilentext = text.zeile(zeilennummer);
    if(zeilentext.contains(LISTENENDE))
    {
        return 0; //Listenende darf nicht gelöscht werden!
    }
    if(zeilennummer > text.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer == 0)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    text.zeile_ersaetzen(zeilennummer, neuer_zeilentext);
    aktualisiere_klartext_und_var();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

//------------------------------------------------------------
//private:
void programmtext::set_werkstuecklaenge(float neue_laenge)
{
    werkstuecklaenge = neue_laenge;
}

void programmtext::set_werkstueckbreite(float neue_breite)
{
    werkstueckbreite = neue_breite;
}

void programmtext::set_werkstueckdicke(float neue_dicke)
{
    werkstueckdicke = neue_dicke;
}

void programmtext::set_sicherheitsabstand(float neuer_Abstand)
{
    if(neuer_Abstand > 0)
    {
        sicherheitsabstand = neuer_Abstand;
    }else
    {
        sicherheitsabstand = 5;
    }
}

void programmtext::aktualisiere_klartext_und_var()
{
    clear_ausser_text();
    QString variablen;
    for(uint i=1 ; i<=text.zeilenanzahl() ; i++)
    {
        QString zeile = text.zeile(i);
        if(  (zeile.at(0) == '/')  &&  (zeile.at(1) == '/')  )
        {
            klartext.zeilen_anhaengen("");
            var.zeilen_anhaengen("");
            continue;//Ausgeblendete Zeile überspringen
        }
        if(  (anz_faufr > anz_fabfa)  &&  (i<text.zeilenanzahl())  )
        {
            if(  zeile.contains(FRAESERGERADE_DIALOG)  ||  zeile.contains(FRAESERBOGEN_DIALOG)  ||  zeile.contains(FRAESERABFAHREN_DIALOG)  )
            {
                ;
            }else
            {
                if(warnung_frDial == false)
                {
                    QMessageBox mb;
                    mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeser-Abfahren fehlt!");
                    mb.exec();
                    warnung_frDial = true;
                }
            }
        }
        if(zeile.contains(PROGRAMMKOPF_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                if(  (hat_programmkopf == true)  &&  (warnungen_sind_eingeschaltet == true)  )
                {
                    QMessageBox mb;
                    mb.setText("Achtung!\nProgrammkopf mehrfach vorhanden!");
                    mb.exec();
                }
                hat_programmkopf = true;
                QString zeile_klartext;
                zeile_klartext += PROGRAMMKOPF_DIALOG;
                zeile_klartext += LAENGE;
                tmp = text_mitte(zeile, LAENGE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                float l = tmp.toFloat();
                set_werkstuecklaenge(l);
                if(l>max_x)
                {
                    max_x = l;
                }
                if(!variablen.contains(LAENGE))
                {
                    variablen += LAENGE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, LAENGE, ENDE_EINTRAG);
                    variablen.replace(LAENGE+alterWert, LAENGE+tmp);
                }

                zeile_klartext += BREITE;
                tmp = text_mitte(zeile, BREITE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                float b = tmp.toFloat();
                set_werkstueckbreite(b);
                if(b>max_y)
                {
                    max_y = b;
                }
                if(!variablen.contains(BREITE))
                {
                    variablen += BREITE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, BREITE, ENDE_EINTRAG);
                    variablen.replace(BREITE+alterWert, BREITE+tmp);
                }

                zeile_klartext += DICKE;
                tmp = text_mitte(zeile, DICKE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                set_werkstueckdicke(tmp.toFloat());
                if(!variablen.contains(DICKE))
                {
                    variablen += DICKE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, DICKE, ENDE_EINTRAG);
                    variablen.replace(DICKE+alterWert, DICKE+tmp);
                }

                zeile_klartext += KOMMENTAR;
                tmp = text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                zeile_klartext += SICHERHEITSABSTAND;
                tmp = text_mitte(zeile, SICHERHEITSABSTAND, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                set_sicherheitsabstand(tmp.toFloat());

                zeile_klartext += BEZEICHNUNG;
                tmp = text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(PROGRAMMENDE_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                if(  (hat_programmende == true)  &&  (warnungen_sind_eingeschaltet == true)  )
                {
                    QMessageBox mb;
                    mb.setText("Achtung!\nProgramm hat mehr als ein Programmende!");
                    mb.exec();
                }
                hat_programmende = true;
                QString zeile_klartext;
                zeile_klartext += PROGRAMMENDE_DIALOG;
                tmp = text_mitte(zeile, MODUS, ENDE_EINTRAG);
                if(tmp == MODUS_PENDE_NULLPUNKT)
                {
                    zeile_klartext += POSITION_X;
                    zeile_klartext += "0";
                    zeile_klartext += ENDE_EINTRAG;

                    zeile_klartext += POSITION_Y;
                    zeile_klartext += "0";
                    zeile_klartext += ENDE_EINTRAG;

                    zeile_klartext += POSITION_Z;
                    zeile_klartext += QString::fromStdString(  float_to_string(werkstueckdicke+sicherheitsabstand)  );
                    zeile_klartext += ENDE_EINTRAG;

                }else if(tmp == MODUS_PENDE_BENUTZERDEF)
                {
                    QString tmp2;

                    zeile_klartext += POSITION_X;
                    tmp2 = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                    tmp2 = variablen_durch_werte_ersetzten(variablen, tmp2);//Variablen durch Werte ersetzen
                    tmp2 = ausdruck_auswerten(tmp2);
                    zeile_klartext += tmp2;
                    zeile_klartext += ENDE_EINTRAG;

                    zeile_klartext += POSITION_Y;
                    tmp2 = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                    tmp2 = variablen_durch_werte_ersetzten(variablen, tmp2);//Variablen durch Werte ersetzen
                    tmp2 = ausdruck_auswerten(tmp2);
                    zeile_klartext += tmp2;
                    zeile_klartext += ENDE_EINTRAG;

                    zeile_klartext += POSITION_Z;
                    tmp2 = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                    tmp2 = variablen_durch_werte_ersetzten(variablen, tmp2);//Variablen durch Werte ersetzen
                    tmp2 = ausdruck_auswerten(tmp2);
                    zeile_klartext += tmp2;
                    zeile_klartext += ENDE_EINTRAG;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(VARIABLE_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                tmp = text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
                QString bez = "[" + tmp + "]";
                QString wert = text_mitte(zeile, WERT, ENDE_EINTRAG);
                if(!variablen.contains(bez))
                {
                    variablen += bez;
                    variablen += wert;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, bez, ENDE_EINTRAG);
                    variablen.replace(bez+alterWert, bez+wert);
                }

                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(KOMMENTAR_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                QString zeile_klartext;
                zeile_klartext += KOMMENTAR_DIALOG;
                zeile_klartext += KOMMENTAR;
                zeile_klartext += text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG);
                zeile_klartext += ENDE_EINTRAG;

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                QString zeile_klartext;
                zeile_klartext += RECHTECKTASCHE_DIALOG;
                tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
                zeile_klartext += WKZ_NAME;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float x = tmp.toFloat();
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float y = tmp.toFloat();
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp);
                }

                tmp = text_mitte(zeile, TASCHENLAENGE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float tal = tmp.toFloat();
                zeile_klartext += TASCHENLAENGE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(TASCHENLAENGE))
                {
                    variablen += TASCHENLAENGE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, TASCHENLAENGE, ENDE_EINTRAG);
                    variablen.replace(TASCHENLAENGE+alterWert, TASCHENLAENGE+tmp);
                }

                tmp = text_mitte(zeile, TASCHENBREITE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float tab = tmp.toFloat();
                zeile_klartext += TASCHENBREITE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(TASCHENBREITE))
                {
                    variablen += TASCHENBREITE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, TASCHENBREITE, ENDE_EINTRAG);
                    variablen.replace(TASCHENBREITE+alterWert, TASCHENBREITE+tmp);
                }

                tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += TASCHENTIEFE;
                float taschentiefe = tmp.toFloat();
                if(taschentiefe >= 0)
                {
                    zeile_klartext += tmp;
                }else
                {
                    zeile_klartext += QString::fromStdString(float_to_string(-taschentiefe + get_werkstueckdicke()));
                }
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(TASCHENTIEFE))
                {
                    variablen += TASCHENTIEFE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, TASCHENTIEFE, ENDE_EINTRAG);
                    variablen.replace(TASCHENTIEFE+alterWert, TASCHENTIEFE+tmp);
                }

                tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += RADIUS;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += ZUSTELLUNG;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, GEGENLAUF, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += GEGENLAUF;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += WINKEL;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += AUSRAEUMEN;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ANFAHRVORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += VORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += DREHZAHL;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, BEZUGSPUNKT, ENDE_EINTRAG);
                zeile_klartext += BEZUGSPUNKT;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(variablen, DICKE, ENDE_EINTRAG);
                zeile_klartext += BEZUGSHOEHE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                if(x-tal/2 < min_x)
                {
                    min_x = x-tal/2;
                }
                if(x+tal/2 > max_x)
                {
                    max_x = x+tal/2;
                }
                if(y-tab/2 < min_y)
                {
                    min_y = y-tab/2;
                }
                if(y+tab/2 > max_y)
                {
                    max_y = y+tab/2;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(KREISTASCHE_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                QString zeile_klartext;
                zeile_klartext += KREISTASCHE_DIALOG;
                tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
                zeile_klartext += WKZ_NAME;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float x = tmp.toFloat();
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float y = tmp.toFloat();
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp);
                }

                tmp = text_mitte(zeile, DURCHMESSER, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float dm = tmp.toFloat();
                zeile_klartext += DURCHMESSER;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(DURCHMESSER))
                {
                    variablen += DURCHMESSER;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, DURCHMESSER, ENDE_EINTRAG);
                    variablen.replace(DURCHMESSER+alterWert, DURCHMESSER+tmp);
                }

                tmp = text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += TASCHENTIEFE;
                float taschentiefe = tmp.toFloat();
                if(taschentiefe >= 0)
                {
                    zeile_klartext += tmp;
                }else
                {
                    zeile_klartext += QString::fromStdString(float_to_string(-taschentiefe + get_werkstueckdicke()));
                }
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(TASCHENTIEFE))
                {
                    variablen += TASCHENTIEFE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, TASCHENTIEFE, ENDE_EINTRAG);
                    variablen.replace(TASCHENTIEFE+alterWert, TASCHENTIEFE+tmp);
                }

                tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += ZUSTELLUNG;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += AUSRAEUMEN;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, GEGENLAUF, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += GEGENLAUF;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ANFAHRVORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += VORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += DREHZAHL;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(variablen, DICKE, ENDE_EINTRAG);
                zeile_klartext += BEZUGSHOEHE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                if(x-dm/2 < min_x)
                {
                    min_x = x-dm/2;
                }
                if(x+dm/2 > max_x)
                {
                    max_x = x+dm/2;
                }
                if(y-dm/2 < min_y)
                {
                    min_y = y-dm/2;
                }
                if(y+dm/2 > max_y)
                {
                    max_y = y+dm/2;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                anz_faufr++;
                QString zeile_klartext;
                zeile_klartext += FRAESERAUFRUF_DIALOG;
                tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
                zeile_klartext += WKZ_NAME;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, BAHNRORREKTUR, ENDE_EINTRAG);
                zeile_klartext += BAHNRORREKTUR;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float x = tmp.toFloat();
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float y = tmp.toFloat();
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                //float z = tmp.toFloat();
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp);
                }

                tmp = text_mitte(zeile, ECKENRUNDENGLOBAL, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += ECKENRUNDENGLOBAL;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, KANTENDICKE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += KANTENDICKE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ANFAHRVORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ANFAHRVORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, VORSCHUB, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += VORSCHUB;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, DREHZAHL, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += DREHZAHL;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);
                zeile_klartext += ANFAHRTYP;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ABFAHRTYP, ENDE_EINTRAG);
                zeile_klartext += ABFAHRTYP;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;


                if(x < min_x)
                {
                    min_x = x;
                }
                if(x > max_x)
                {
                    max_x = x;
                }
                if(y < min_y)
                {
                    min_y = y;
                }
                if(y > max_y)
                {
                    max_y = y;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                if(anz_faufr-1 != anz_fabfa)
                {
                    if(warnung_frDial == false)
                    {
                        QMessageBox mb;
                        mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeskontur muss zwischen Freaser-Aufruf und Fraeser-Abfahren stehen!");
                        mb.exec();
                        warnung_frDial = true;
                    }
                }

                QString zeile_klartext;
                zeile_klartext += FRAESERGERADE_DIALOG;
                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float x = tmp.toFloat();
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float y = tmp.toFloat();
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                //float z = tmp.toFloat();
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp);
                }

                tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += RADIUS;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                if(x < min_x)
                {
                    min_x = x;
                }
                if(x > max_x)
                {
                    max_x = x;
                }
                if(y < min_y)
                {
                    min_y = y;
                }
                if(y > max_y)
                {
                    max_y = y;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                if(anz_faufr-1 != anz_fabfa)
                {
                    if(warnung_frDial == false)
                    {
                        QMessageBox mb;
                        mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeskontur muss zwischen Freaser-Aufruf und Fraeser-Abfahren stehen!");
                        mb.exec();
                        warnung_frDial = true;
                    }
                }

                QString zeile_klartext;
                zeile_klartext += FRAESERBOGEN_DIALOG;
                tmp = text_mitte(zeile, BOGENRICHTUNG, ENDE_EINTRAG);
                zeile_klartext += BOGENRICHTUNG;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                QString richtung = tmp;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float x = tmp.toFloat();
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                float y = tmp.toFloat();
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                //float z = tmp.toFloat();
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp);
                }

                tmp = text_mitte(zeile, MODUS, ENDE_EINTRAG);
                zeile_klartext += MODUS;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                QString modus = tmp;

                if(modus == MODUS_RADIUS)
                {
                    tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                    zeile_klartext += RADIUS;
                    zeile_klartext += tmp;
                    zeile_klartext += ENDE_EINTRAG;
                    float r = tmp.toFloat();
                    //Mittelpunkt berechnen:
                    QString zeile_var = var.zeile(i-1);
                    tmp = text_mitte(zeile_var, POSITION_X, ENDE_EINTRAG);
                    punkt start;
                    start.x = tmp.toFloat();
                    tmp = text_mitte(zeile_var, POSITION_Y, ENDE_EINTRAG);
                    start.y = tmp.toFloat();
                    zeile_var = var.zeile(i);
                    tmp = text_mitte(zeile_var, POSITION_X, ENDE_EINTRAG);
                    punkt ende;
                    ende.x = tmp.toFloat();
                    tmp = text_mitte(zeile_var, POSITION_Y, ENDE_EINTRAG);
                    ende.y = tmp.toFloat();

                    bool ist_im_uzs = 0;
                    if(richtung == BOGENRICHTUNG_IM_UZS)
                    {
                        ist_im_uzs = true;
                    }else
                    {
                        ist_im_uzs = false;
                    }
                    punkt m = kreismittelpunkt(start, ende, r, ist_im_uzs);

                    zeile_klartext += MITTELPUNKT_X;
                    zeile_klartext += QString::fromStdString(float_to_string(m.x));
                    zeile_klartext += ENDE_EINTRAG;
                    zeile_klartext += MITTELPUNKT_Y;
                    zeile_klartext += QString::fromStdString(float_to_string(m.x));
                    zeile_klartext += ENDE_EINTRAG;

                }else if(modus == MODUS_MITTELPUNKT)
                {
                    tmp = text_mitte(zeile, MITTELPUNKT_X, ENDE_EINTRAG);
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                    zeile_klartext += MITTELPUNKT_X;
                    zeile_klartext += tmp;
                    zeile_klartext += ENDE_EINTRAG;

                    tmp = text_mitte(zeile, MITTELPUNKT_Y, ENDE_EINTRAG);
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                    zeile_klartext += MITTELPUNKT_Y;
                    zeile_klartext += tmp;
                    zeile_klartext += ENDE_EINTRAG;
                    //Radius berechnen:

                }

                if(x < min_x)
                {
                    min_x = x;
                }
                if(x > max_x)
                {
                    max_x = x;
                }
                if(y < min_y)
                {
                    min_y = y;
                }
                if(y > max_y)
                {
                    max_y = y;
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }
        //------------
        if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                if(anz_faufr-1 != anz_fabfa)
                {
                    if(warnung_frDial == false)
                    {
                        QMessageBox mb;
                        mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeser-Abfahren ohne dazu gehoerenden Fraeser-Aufruf!");
                        mb.exec();
                        warnung_frDial = true;
                    }
                }
                anz_fabfa++;
                QString zeile_klartext;
                zeile_klartext += FRAESERABFAHREN_DIALOG;

                klartext.zeilen_anhaengen(zeile_klartext);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
            }
        }
        //------------

    }
    //CAD-Parameter ergänzen:
    if(warnung_frDial == false)
    {
        for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
        {
            QString abtyp = NICHT_DEFINIERT; //brauchen wir an dieser Stelle, damit der Wert später beim Fräser-Abfahren verfügbar ist
            QString zeile = klartext.zeile(i), tmp;

            if(zeile.contains(FRAESERAUFRUF_DIALOG))
            {
                punkt startpKont, startpDial, folgepunkt;
                startpKont.x = 0;
                startpKont.y = 0;
                startpDial.x = 0;
                startpDial.y = 0;
                folgepunkt.x = 0;
                folgepunkt.y = 0;

                abtyp = text_mitte(zeile, ABFAHRTYP, ENDE_EINTRAG);
                QString antyp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                startpDial.x = tmp.toFloat();
                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                startpDial.y = tmp.toFloat();

                if(antyp != ANABFAHRTYP_KEIN)
                {
                    //Folgepunkt ermitteln:
                    if(i+1 <= klartext.zeilenanzahl()  )
                    {
                        uint j = i+1;
                        QString zeile_dannach = klartext.zeile(j);
                        while(zeile_dannach.isEmpty()  &&  j+1<=klartext.zeilenanzahl()  )
                        {
                            j++;
                            zeile_dannach = klartext.zeile(j);
                        }
                        if(zeile_dannach.contains(FRAESERGERADE_DIALOG))
                        {
                            tmp = text_mitte(zeile_dannach, POSITION_X, ENDE_EINTRAG);
                            folgepunkt.x = tmp.toFloat();
                            tmp = text_mitte(zeile_dannach, POSITION_Y, ENDE_EINTRAG);
                            folgepunkt.y = tmp.toFloat();
                        }else if(zeile_dannach.contains(FRAESERBOGEN_DIALOG))
                        {
                            //Noch programmieren!!!
                        }else if(zeile_dannach.contains(FRAESERABFAHREN_DIALOG))
                        {
                            zeile += CAD_BEGIN;
                            //Punkt am Startpunkt Aufruf Fräser:
                            zeile += CAD_PUNKT;
                            zeile += QString::fromStdString(float_to_string(startpDial.x));
                            zeile += "/";
                            zeile += QString::fromStdString(float_to_string(startpDial.y));
                            zeile += ENDE_EINTRAG;
                            zeile += CAD_ENDE;
                            klartext.zeile_ersaetzen(i, zeile);
                            continue;
                        }
                        if(antyp == ANABFAHRTYP_GARADE)
                        {
                            punkt richtvect;
                            richtvect.x = folgepunkt.x - startpDial.x;
                            richtvect.y = folgepunkt.y - startpDial.y;
                            float l = sqrt(richtvect.x*richtvect.x + richtvect.y*richtvect.y); //c²=a²+b²
                            tmp = text_mitte(text.zeile(i), WKZ_DURCHMESSER, ENDE_EINTRAG);
                            float fdm = tmp.toFloat();
                            float faktor = fdm/l*2;//Anfahrweg soll 2x Fräserdurchmesser betragen
                            if(faktor == 0)
                            {
                                QMessageBox mb;
                                mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!nFraeserdurchmesser darf nicht 0 sein!");
                                mb.exec();
                                return;
                            }
                            startpKont.x = startpDial.x - richtvect.x*faktor;
                            startpKont.y = startpDial.y - richtvect.y*faktor;

                            zeile += CAD_BEGIN;
                            //Strecke zum Startpunkt Aufruf Fräser:
                            zeile += CAD_STRECKE;
                            zeile += QString::fromStdString(float_to_string(startpKont.x));
                            zeile += "/";
                            zeile += QString::fromStdString(float_to_string(startpKont.y));
                            zeile += "/";
                            zeile += QString::fromStdString(float_to_string(startpDial.x));
                            zeile += "/";
                            zeile += QString::fromStdString(float_to_string(startpDial.y));
                            zeile += ENDE_EINTRAG;
                            zeile += CAD_ENDE;

                        }else //antyp == ANABFAHRTYP_KREISBOGEN
                        {
                            if(text_mitte(zeile, BAHNRORREKTUR,ENDE_EINTRAG) == BAHNRORREKTUR_rechts)
                            {
                                //Noch programmieren!!!
                            }else
                            {
                                //Noch programmieren!!!
                            }
                        }
                    }
                }else//wenn ANABFAHRTYP_KEIN
                {
                    zeile += CAD_BEGIN;
                    //Punkt am Startpunkt Aufruf Fräser:
                    zeile += CAD_PUNKT;
                    zeile += QString::fromStdString(float_to_string(startpDial.x));
                    zeile += "/";
                    zeile += QString::fromStdString(float_to_string(startpDial.y));
                    zeile += ENDE_EINTRAG;
                    zeile += CAD_ENDE;
                }





                klartext.zeile_ersaetzen(i, zeile);
            }
        }
    }
}

void programmtext::aktualisiere_anzeigetext()
{
    anzeigetext.clear();
    for(uint i=1 ; i<=text.zeilenanzahl() ; i++)
    {
        QString zeile = text.zeile(i);
        QString tmp;
        tmp = QString::fromStdString(int_to_string(i));
        tmp += ": ";
        //-----------------------
        if(zeile.contains(PROGRAMMKOPF_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(PROGRAMMENDE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(VARIABLE_DIALOG))
        {
            tmp += "Variable: ";
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(KOMMENTAR_DIALOG))
        {
            tmp += text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG);
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(KREISTASCHE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(LISTENENDE))
        {
            tmp += "...";
        }else
        {
            tmp += zeile;
        }
        //-----------------------
        if(  (zeile.at(0) == '/')  &&  (zeile.at(1) == '/')  )
        {
            tmp = "//" + tmp;
        }
        if(tmp.isEmpty())
        {
            tmp = " ";
        }
        if(i==1)
        {
            anzeigetext.set_text(tmp);
        }else
        {
            anzeigetext.zeile_anhaengen(tmp);
        }
    }
}









