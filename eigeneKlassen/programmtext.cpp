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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::clear()
{
    text.clear();
    clear_ausser_text();
}

void programmtext::clear_ausser_text()
{
    klartext.clear();
    var.clear();
    anzeigetext.clear();
    geo.clear();
    fkon.clear();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
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
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

//------------------------------------------------------------
//private:

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

void programmtext::aktualisiere_klartext_var_geo()
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
            if(  zeile.contains(FRAESERGERADE_DIALOG)  ||  \
                 zeile.contains(FRAESERBOGEN_DIALOG)   ||  \
                 zeile.contains(FRAESERABFAHREN_DIALOG)    )
            {
                ;
            }else
            {
                if(warnung_frDial == false)
                {
                    if(warnungen_sind_eingeschaltet)
                    {
                        QMessageBox mb;
                        mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + \
                                   "!\nFraeser-Abfahren fehlt!");
                        mb.exec();
                    }
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

                tmp = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG);
                zeile_klartext += WKZ_DURCHMESSER;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
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

                tmp = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG);
                zeile_klartext += WKZ_DURCHMESSER;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
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

                tmp = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG);
                zeile_klartext += WKZ_DURCHMESSER;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, BAHNRORREKTUR, ENDE_EINTRAG);
                zeile_klartext += BAHNRORREKTUR;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
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
                if(!variablen.contains(ECKENRUNDENGLOBAL))
                {
                    variablen += ECKENRUNDENGLOBAL;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, ECKENRUNDENGLOBAL, ENDE_EINTRAG);
                    variablen.replace(ECKENRUNDENGLOBAL+alterWert, ECKENRUNDENGLOBAL+tmp);
                }

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
                        if(warnungen_sind_eingeschaltet)
                        {
                            QMessageBox mb;
                            mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeskontur muss zwischen Freaser-Aufruf und Fraeser-Abfahren stehen!");
                            mb.exec();
                        }
                        warnung_frDial = true;
                    }
                }

                QString zeile_klartext;
                zeile_klartext += FRAESERGERADE_DIALOG;
                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
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
                        if(warnungen_sind_eingeschaltet)
                        {
                            QMessageBox mb;
                            mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeskontur muss zwischen Freaser-Aufruf und Fraeser-Abfahren stehen!");
                            mb.exec();
                        }
                        warnung_frDial = true;
                    }
                }

                QString zeile_klartext;
                zeile_klartext += FRAESERBOGEN_DIALOG;

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
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

                tmp = text_mitte(zeile, BOGENRICHTUNG, ENDE_EINTRAG);
                zeile_klartext += BOGENRICHTUNG;
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
                        if(warnungen_sind_eingeschaltet)
                        {
                            QMessageBox mb;
                            mb.setText("Fehler in Zeile " + QString::fromStdString(int_to_string(i)) + "!\nFraeser-Abfahren ohne dazu gehoerenden Fraeser-Aufruf!");
                            mb.exec();
                        }
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
        QString abtyp = NICHT_DEFINIERT; //brauchen wir an dieser Stelle, damit der Wert später
                                         //beim Fräser-Abfahren verfügbar ist
        float fdm=0;                     //Fräser-Durchmesser

        for(uint i=1 ; i<=klartext.zeilenanzahl() ; i++)
        {

            QString zeile = klartext.zeile(i), tmp;

            if(zeile.isEmpty())
            {
                geo.zeilenvorschub();
            }else if(zeile.contains(PROGRAMMKOPF_DIALOG))
            {
                punkt3d nullpunkt(0,0,0);
                nullpunkt.set_breite(15);
                geo.add_punkt(nullpunkt);

                rechteck3d rec;
                rec.set_bezugspunkt(UNTEN_LINKS);
                rec.set_einfuegepunkt(0,0,0);
                rec.set_laenge(text_mitte(zeile, LAENGE, ENDE_EINTRAG));
                rec.set_breite(text_mitte(zeile, BREITE, ENDE_EINTRAG));
                rec.set_farbe_fuellung(FARBE_GRAU);
                geo.add_rechteck(rec);

                geo.zeilenvorschub();
            }else if(zeile.contains(PROGRAMMENDE_DIALOG))
            {
                geo.zeilenvorschub();
            }else if(zeile.contains(VARIABLE_DIALOG))
            {
                geo.zeilenvorschub();
            }else if(zeile.contains(KOMMENTAR_DIALOG))
            {
                geo.zeilenvorschub();
            }else if(zeile.contains(KREISTASCHE_DIALOG))
            {
                zylinder z;
                punkt3d p3;
                p3.set_x(text_mitte(zeile, POSITION_X, ENDE_EINTRAG));
                p3.set_y(text_mitte(zeile, POSITION_Y, ENDE_EINTRAG));
                p3.set_z(werkstueckdicke);
                z.set_mittelpunkt(p3);
                z.set_hoehe(text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG));
                z.set_radius(text_mitte(zeile, DURCHMESSER, ENDE_EINTRAG));
                z.set_radius(z.radius()/2); //Zeile davor weist DM zu
                if(p3.z()-z.get_hoehe() <= 0)
                {//Wenn Tasche durchgefräst ist
                    z.set_farbe_fuellung(FARBE_WEISS);
                }else
                {
                     z.set_farbe_fuellung(FARBE_BLAU);
                }
                geo.add_zylinder(z);
                QString ausr = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                if(ausr.toInt() == false)
                {
                    double dmwkz = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG).toDouble();
                    double dmta = z.radius()-dmwkz;
                    if(dmta<0)
                    {
                        dmta = 0;
                    }
                    z.set_radius(dmta);
                    z.set_farbe_fuellung(FARBE_GRAU);
                    if(dmta > 0)
                    {
                        geo.add_zylinder(z);
                    }
                }
                geo.zeilenvorschub();
            }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
            {
                wuerfel wue;
                wue.set_bezugspunkt(text_mitte(zeile, BEZUGSPUNKT, ENDE_EINTRAG));
                punkt3d p3;
                p3.set_x(text_mitte(zeile, POSITION_X, ENDE_EINTRAG));
                p3.set_y(text_mitte(zeile, POSITION_Y, ENDE_EINTRAG));
                p3.set_z(werkstueckdicke);
                wue.set_einfuegepunkt(p3);
                wue.set_laenge(text_mitte(zeile, TASCHENLAENGE, ENDE_EINTRAG));
                wue.set_breite(text_mitte(zeile, TASCHENBREITE, ENDE_EINTRAG));
                wue.set_hoehe(text_mitte(zeile, TASCHENTIEFE, ENDE_EINTRAG));
                double rad = text_mitte(zeile, RADIUS, ENDE_EINTRAG).toDouble();
                double radwkz = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG).toDouble()/2;
                double radtasche;
                if(rad > radwkz)
                {
                    radtasche = rad;
                }else
                {
                    radtasche = radwkz;
                }
                wue.set_rad(radtasche);
                wue.set_drewi(text_mitte(zeile, WINKEL, ENDE_EINTRAG));
                if(p3.z()-wue.get_hoehe() <= 0)
                {//Wenn Tasche durchgefräst ist
                    wue.set_farbe_fuellung(FARBE_WEISS);
                }else
                {
                     wue.set_farbe_fuellung(FARBE_BLAU);
                }
                geo.add_wuerfel(wue);
                QString ausr = text_mitte(zeile, AUSRAEUMEN, ENDE_EINTRAG);
                if(ausr.toInt() == false)
                {
                    wuerfel wue2 = wue;
                    wue2.set_bezugspunkt(BEZUGSPUNKT_MITTE);
                    wue2.set_einfuegepunkt(wue.mi());
                    double l = wue.l()-radtasche*4;
                    if(l<0)
                    {
                        l=0;
                    }
                    wue2.set_laenge(l);
                    double b = wue.b()-radtasche*4;
                    if(b<0)
                    {
                        b=0;
                    }
                    wue2.set_breite(b);
                    double radwue2 = wue.rad()-radtasche*2;
                    if(radwue2 < 0)
                    {
                        radwue2 = 0;
                    }
                    wue2.set_rad(radwue2);
                    wue2.set_farbe_fuellung(FARBE_GRAU);
                    if(l>0 && b>0)
                    {
                        geo.add_wuerfel(wue2);
                    }
                }
                geo.zeilenvorschub();
            }else if(zeile.contains(FRAESERAUFRUF_DIALOG))
            {
                abtyp = text_mitte(zeile, ABFAHRTYP, ENDE_EINTRAG);
                QString antyp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);

                punkt3d startpDial;
                startpDial.set_x(text_mitte(zeile, POSITION_X, ENDE_EINTRAG));
                startpDial.set_y(text_mitte(zeile, POSITION_Y, ENDE_EINTRAG));
                startpDial.set_z(text_mitte(zeile, POSITION_Z, ENDE_EINTRAG));

                tmp = text_mitte(text.zeile(i), WKZ_DURCHMESSER, ENDE_EINTRAG);
                fdm = tmp.toFloat();
                if(fdm == 0)//Fräser-DM kann 0 sein wenn z.B. ungültiges Werkzeug gewählt ist
                {
                    fdm = 50;
                    QMessageBox mb;
                    mb.setText("Achtung!\nFraeserdurchmesser 0 in Zeile " + int_to_qstring(i) + "!");
                    mb.exec();
                }

                if(antyp == ANABFAHRTYP_KEIN)
                {
                    geo.add_punkt(startpDial);
                }else if(antyp == ANABFAHRTYP_GARADE)
                {
                    if(i+1 > klartext.zeilenanzahl()  ) //Wenn es keine Folgepunkt gibt
                    {   //kein Anfahrweg nötig
                        geo.add_punkt(startpDial);
                    }else
                    {
                        uint ii = i+1;
                        QString zeile_dannach = klartext.zeile(ii);
                        while(zeile_dannach.isEmpty()  &&  ii+1<=klartext.zeilenanzahl()  )
                        {
                            ii++;
                            zeile_dannach = klartext.zeile(ii);
                        }
                        if(zeile_dannach.contains(FRAESERGERADE_DIALOG))
                        {   //Anfahrweg ist Strecke
                            punkt3d folgepunkt;
                            folgepunkt.set_x(text_mitte(zeile_dannach, POSITION_X, ENDE_EINTRAG));
                            folgepunkt.set_y(text_mitte(zeile_dannach, POSITION_Y, ENDE_EINTRAG));
                            folgepunkt.set_z(text_mitte(zeile_dannach, POSITION_Z, ENDE_EINTRAG));
                            //Anfahrpunkt berechnen:
                            strecke s;
                            s.set_start(startpDial);
                            s.set_ende(folgepunkt);

                            strecke_bezugspunkt sb;
                            sb = strecke_bezugspunkt_ende;
                            //Startpunkt in X u Y setzen:
                            s.set_laenge_2d(s.laenge2dim()+fdm*2, sb);
                            //Startpunkt in Z setzen:
                            punkt3d startpunkt = s.startp();
                            startpunkt.set_z(werkstueckdicke + sicherheitsabstand);
                            s.set_start(startpunkt);
                            //Endpunkt setzen:
                            s.set_ende(startpDial);//Damit auch Z stimmt und weniger gerechent werden muss
                            geo.add_strecke(s);
                        }else if(zeile_dannach.contains(FRAESERBOGEN_DIALOG))
                        {
                            punkt3d endpu;
                            endpu.set_x(text_mitte(zeile_dannach, POSITION_X, ENDE_EINTRAG));
                            endpu.set_y(text_mitte(zeile_dannach, POSITION_Y, ENDE_EINTRAG));
                            endpu.set_z(text_mitte(zeile_dannach, POSITION_Z, ENDE_EINTRAG));
                            bool bogriuzs;
                            if(text_mitte(zeile_dannach, BOGENRICHTUNG, ENDE_EINTRAG) == BOGENRICHTUNG_IM_UZS)
                            {
                                bogriuzs = true;
                            }else
                            {
                                bogriuzs = false;
                            }
                            bogen b;
                            b.set_startpunkt(startpDial);
                            b.set_endpunkt(endpu);
                            b.set_radius(text_mitte(zeile_dannach, RADIUS, ENDE_EINTRAG), bogriuzs);
                            punkt3d startpu;
                            startpu.set_x(b.mittelpunkt().x());
                            startpu.set_y(b.mittelpunkt().y());
                            startpu.set_z(werkstueckdicke + sicherheitsabstand);
                            strecke s;
                            s.set_start(startpu);
                            s.set_ende(startpDial);
                            s.drenen_um_endpunkt_2d(90, -bogriuzs);
                            geo.add_strecke(s);
                        }else if(zeile_dannach.contains(FRAESERABFAHREN_DIALOG))
                        {   //kein Anfahrweg nötig
                            geo.add_punkt(startpDial);
                        }
                    }
                }else //antyp == ANABFAHRTYP_KREISBOGEN_LI oder ANABFAHRTYP_KREISBOGEN_RE
                {
                    if(i+1 > klartext.zeilenanzahl()  ) //Wenn es keine Folgepunkt gibt
                    {   //kein Anfahrweg nötig
                        geo.add_punkt(startpDial);
                    }else
                    {
                        uint ii = i+1;
                        QString zeile_dannach = klartext.zeile(ii);
                        while(zeile_dannach.isEmpty()  &&  ii+1<=klartext.zeilenanzahl()  )
                        {
                            ii++;
                            zeile_dannach = klartext.zeile(ii);
                        }
                        if(zeile_dannach.contains(FRAESERGERADE_DIALOG))
                        {
                            punkt3d folgepunkt;
                            folgepunkt.set_x(text_mitte(zeile_dannach, POSITION_X, ENDE_EINTRAG));
                            folgepunkt.set_y(text_mitte(zeile_dannach, POSITION_Y, ENDE_EINTRAG));
                            folgepunkt.set_z(text_mitte(zeile_dannach, POSITION_Z, ENDE_EINTRAG));
                            strecke s;
                            s.set_start(startpDial);
                            s.set_ende(folgepunkt);
                            tmp = text_mitte(text.zeile(i), WKZ_DURCHMESSER, ENDE_EINTRAG);
                            float fdm = tmp.toFloat();
                            if(fdm == 0)//Fräser-DM kann 0 sein wenn z.B. ungültiges Werkzeug gewählt ist
                            {
                                fdm = 50;
                                QMessageBox mb;
                                mb.setText("Achtung!\nFraeserdurchmesser 0 in Zeile " + int_to_qstring(i) + "!");
                                mb.exec();
                            }
                            strecke_bezugspunkt sb;
                            sb = strecke_bezugspunkt_start;
                            //Endpunkt in X u Y setzen:
                            s.set_laenge_2d(fdm*2, sb);
                            //Bahnkor ermitteln:
                            if(antyp == ANABFAHRTYP_KREISBOGEN_RE)
                            {
                                s.drenen_um_startpunkt_2d(90, true);
                                s.drenen_um_endpunkt_2d(90,false);
                                punkt3d p3;
                                p3.set_x(s.startp().x());
                                p3.set_y(s.startp().y());
                                p3.set_z(werkstueckdicke + sicherheitsabstand);
                                bogen b;
                                b.set_startpunkt(p3);
                                b.set_endpunkt(startpDial);
                                b.set_radius(fdm*2, true);
                                geo.add_bogen(b);
                            }else //if(antyp == ANABFAHRTYP_KREISBOGEN_LI)
                            {
                                s.drenen_um_startpunkt_2d(90, false);
                                s.drenen_um_endpunkt_2d(90,true);
                                punkt3d p3;
                                p3.set_x(s.startp().x());
                                p3.set_y(s.startp().y());
                                p3.set_z(werkstueckdicke + sicherheitsabstand);
                                bogen b;
                                b.set_startpunkt(p3);
                                b.set_endpunkt(startpDial);
                                b.set_radius(fdm*2, false);
                                geo.add_bogen(b);
                            }
                        }else if(zeile_dannach.contains(FRAESERBOGEN_DIALOG))
                        {
                            punkt3d folgepunkt;
                            folgepunkt.set_x(text_mitte(zeile_dannach, POSITION_X, ENDE_EINTRAG));
                            folgepunkt.set_y(text_mitte(zeile_dannach, POSITION_Y, ENDE_EINTRAG));
                            folgepunkt.set_z(text_mitte(zeile_dannach, POSITION_Z, ENDE_EINTRAG));
                            bogen b;
                            b.set_startpunkt(startpDial);
                            b.set_endpunkt(folgepunkt);
                            QString r = text_mitte(zeile_dannach, RADIUS, ENDE_EINTRAG);
                            bool uzs;
                            if(text_mitte(zeile_dannach, BOGENRICHTUNG, ENDE_EINTRAG) == BOGENRICHTUNG_IM_UZS)
                            {
                                uzs = true;
                            }else
                            {
                                uzs = false;
                            }
                            b.set_radius(r, uzs);
                            strecke s;
                            s.set_start(startpDial);
                            punkt3d mipu;
                            mipu.set_x(b.mittelpunkt().x());
                            mipu.set_y(b.mittelpunkt().y());
                            s.set_ende(mipu);
                            tmp = text_mitte(text.zeile(i), WKZ_DURCHMESSER, ENDE_EINTRAG);
                            float fdm = tmp.toFloat();
                            if(fdm == 0)//Fräser-DM kann 0 sein wenn z.B. ungültiges Werkzeug gewählt ist
                            {
                                fdm = 50;
                                QMessageBox mb;
                                mb.setText("Achtung!\nFraeserdurchmesser 0 in Zeile " + int_to_qstring(i) + "!");
                                mb.exec();
                            }
                            strecke_bezugspunkt sb;
                            sb = strecke_bezugspunkt_start;

                            if(antyp == ANABFAHRTYP_KREISBOGEN_RE)
                            {
                                if(!uzs)
                                {
                                    s.drenen_um_startpunkt_2d(180, false);
                                }
                                s.set_laenge_2d(fdm*2, sb);
                                s.drenen_um_endpunkt_2d(90, false);
                                punkt3d p3;
                                p3.set_x(s.startp().x());
                                p3.set_y(s.startp().y());
                                p3.set_z(werkstueckdicke + sicherheitsabstand);
                                bogen b;
                                b.set_startpunkt(p3);
                                b.set_endpunkt(startpDial);
                                b.set_radius(fdm*2, true);
                                geo.add_bogen(b);
                            }else //if(antyp == ANABFAHRTYP_KREISBOGEN_LI)
                            {
                                if(uzs)
                                {
                                    s.drenen_um_startpunkt_2d(180, false);
                                }
                                s.set_laenge_2d(fdm*2, sb);
                                s.drenen_um_endpunkt_2d(90, true);
                                punkt3d p3;
                                p3.set_x(s.startp().x());
                                p3.set_y(s.startp().y());
                                p3.set_z(werkstueckdicke + sicherheitsabstand);
                                bogen b;
                                b.set_startpunkt(p3);
                                b.set_endpunkt(startpDial);
                                b.set_radius(fdm*2, false);
                                geo.add_bogen(b);
                            }
                        }else if(zeile_dannach.contains(FRAESERABFAHREN_DIALOG))
                        {   //kein Anfahrweg nötig
                            geo.add_punkt(startpDial);
                        }
                    }
                }
                geo.zeilenvorschub();
            }else if(zeile.contains(FRAESERGERADE_DIALOG))
            {
                punkt3d startpunkt, endpunkt;
                endpunkt.set_x(text_mitte(klartext.zeile(i), POSITION_X, ENDE_EINTRAG));
                endpunkt.set_y(text_mitte(klartext.zeile(i), POSITION_Y, ENDE_EINTRAG));
                endpunkt.set_z(text_mitte(klartext.zeile(i), POSITION_Z, ENDE_EINTRAG));
                QString zeile_davor, zeile_danach;
                if(i > 1)//wenn es Zeilen vorab gibt
                {
                    uint ii = i-1;
                    zeile_davor = klartext.zeile(ii);
                    while(zeile_davor.isEmpty()  &&  ii-1>=1  )
                    {
                        ii--;
                        zeile_davor = klartext.zeile(ii);
                    }
                }
                if(i+1<=klartext.zeilenanzahl())//wenn es Zeilen dannach gibt
                {
                     uint ii = i+1;
                     zeile_danach = klartext.zeile(ii);
                     while(zeile_danach.isEmpty()  &&  ii+1<=klartext.zeilenanzahl()  )
                     {
                         ii++;
                         zeile_danach = klartext.zeile(ii);
                     }
                }


                if(!zeile_davor.contains(FRAESERGERADE_DIALOG))
                {
                     if(zeile_davor.contains(FRAESERAUFRUF_DIALOG) ||  \
                             zeile_davor.contains(FRAESERBOGEN_DIALOG) )
                     {
                         startpunkt.set_x(text_mitte(zeile_davor, POSITION_X, ENDE_EINTRAG));
                         startpunkt.set_y(text_mitte(zeile_davor, POSITION_Y, ENDE_EINTRAG));
                         startpunkt.set_z(text_mitte(zeile_davor, POSITION_Z, ENDE_EINTRAG));
                         strecke s;
                         s.set_start(startpunkt);
                         s.set_ende(endpunkt);

                         //Zeile danach prüfen:
                         if(zeile_danach.contains(FRAESERGERADE_DIALOG))
                         {
                             strecke s2;
                             s2.set_start(endpunkt);
                             punkt3d p3;
                             p3.set_x(text_mitte(zeile_danach, POSITION_X, ENDE_EINTRAG));
                             p3.set_y(text_mitte(zeile_danach, POSITION_Y, ENDE_EINTRAG));
                             p3.set_z(text_mitte(zeile_danach, POSITION_Z, ENDE_EINTRAG));
                             s2.set_ende(p3);
                             double rad_akt = text_mitte(klartext.zeile(i), RADIUS, ENDE_EINTRAG).toDouble();
                             strecke s3 = s;
                             strecke_bezugspunkt sb3 = strecke_bezugspunkt_start;
                             s3.set_laenge_2d(s.laenge2dim()+s2.laenge2dim(),sb3);


                             if(rad_akt > 0                     &&\
                                rad_akt < s.laenge2dim()        &&\
                                rad_akt < s2.laenge2dim()       &&\
                                s3.endp().x() != s2.endp().x()  &&\
                                s3.endp().y() != s2.endp().y()  )
                             {
                                 //---------------------------------------------------winkel berechnen:
                                 double wink = winkel(startpunkt.x(),\
                                                      startpunkt.y(),\
                                                      endpunkt.x(),\
                                                      endpunkt.y(),\
                                                      s2.endp().x(),\
                                                      s2.endp().y());
                                 if(wink<0)
                                 {
                                     wink = -1*wink;
                                 }
                                 double alpha = wink/2;
                                 double seite_a = rad_akt;
                                 double seite_b = seite_a/tan_d(alpha);
                                 //---------------------------------------------------

                                 strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                                 strecke_bezugspunkt sb2 = strecke_bezugspunkt_ende;
                                 s.set_laenge_2d(s.laenge2dim()-seite_b, sb);
                                 s2.set_laenge_2d(s2.laenge2dim()-seite_b, sb2);
                                 bogen b;
                                 b.set_startpunkt(s.endp());
                                 b.set_endpunkt(s2.startp());

                                 //------------------------------------------------------------------------
                                 b.set_radius(rad_akt, false);
                                 if(b.hat_fehler())
                                 {
                                     QMessageBox mb;
                                     mb.setText("Bogen hat Fehler");
                                     mb.exec();
                                 }
                                 //Ungenauigkeiten durch runden ausgleichen:
                                 if(b.mittelpunkt().x() <= endpunkt.x()+rad_akt/1.1  &&
                                    b.mittelpunkt().x() >= endpunkt.x()-rad_akt/1.1  &&
                                    b.mittelpunkt().y() <= endpunkt.y()+rad_akt/1.1  &&
                                    b.mittelpunkt().y() >= endpunkt.y()-rad_akt/1.1)
                                 {
                                     b.set_radius(rad_akt, true);
                                 }
                                 //------------------------------------------------------------------------

                                 geo.add_strecke(s);
                                 geo.add_bogen(b);
                             }else
                             {
                                 geo.add_strecke(s);
                             }
                         }else
                         {
                             geo.add_strecke(s);
                         }
                     }else
                     {
                         //Wenn es keinen Vorgänger gibt
                         //oder Vorgänger ist weder Gerade noch Bogen noch Fräser-Aufruf
                         //dann Strecke vom Nullpunkt beginnend:
                         strecke s;
                         s.set_start(startpunkt);
                         s.set_ende(endpunkt);
                         geo.add_strecke(s);
                         QString msg;
                         msg  = "Achtung!\n";
                         msg += "Beginn der geraden Fraesbahn in Zeile ";
                         msg +=  int_to_qstring(i);
                         msg += " undefiniert!";
                         QMessageBox mb;
                         mb.setText(msg);
                         mb.exec();
                     }
                }else //Zeile davor ist Gerade
                {
                     double rad_vor = text_mitte(zeile_davor, RADIUS, ENDE_EINTRAG).toDouble();
                     startpunkt.set_x(text_mitte(zeile_davor, POSITION_X, ENDE_EINTRAG));
                     startpunkt.set_y(text_mitte(zeile_davor, POSITION_Y, ENDE_EINTRAG));
                     startpunkt.set_z(text_mitte(zeile_davor, POSITION_Z, ENDE_EINTRAG));
                     strecke s;
                     s.set_start(startpunkt);
                     s.set_ende(endpunkt);

                     uint ii = geo.get_aktuelle_zeile()-1;
                     QString geo_zeile_davor = geo.get_text_zeilenweise().zeile(ii);

                     while(geo_zeile_davor==" "   &&  ii-1>=1  )
                     {
                         ii--;
                         geo_zeile_davor = geo.get_text_zeilenweise().zeile(ii);

                     }
                     text_zeilenweise geo_zeile_davor_tz;
                     geo_zeile_davor_tz.set_trennzeichen(TRZ_PA_);
                     geo_zeile_davor_tz.set_text(geo_zeile_davor);
                     if(!geo_zeile_davor_tz.zeile(1).contains(STRECKE))
                     {
                         QString msg;
                         msg  = "Achtung! Fehler im Quellcode!\n";
                         msg += "Unerwarteter Eintrag in geo!\n";
                         msg += "Fehler tritt in geo-Zeile ";
                         msg += int_to_qstring(ii);
                         msg += " auf.";
                         QMessageBox mb;
                         mb.setText(msg);
                         mb.exec();
                     }

                     strecke s2;
                     punkt3d p3;
                     p3.set_x(geo_zeile_davor_tz.zeile(2));
                     p3.set_y(geo_zeile_davor_tz.zeile(3));
                     p3.set_z(0);
                     s2.set_start(p3);
                     s2.set_ende(startpunkt);
                     //---------------------------------------------------winkel berechnen:
                     double wink = winkel(s2.startp().x(),\
                                          s2.startp().y(),\
                                          startpunkt.x(),\
                                          startpunkt.y(),\
                                          endpunkt.x(),\
                                          endpunkt.y());
                     if(wink<0)
                     {
                         wink = -1*wink;
                     }
                     double alpha = wink/2;
                     double seite_a = rad_vor;
                     double seite_b = seite_a/tan_d(alpha);
                     if(seite_b<0)
                     {
                         seite_b = -1*seite_b;
                     }
                     //---------------------------------------------------

                     strecke s3 = s2;//s3 prüft, ob die Geraden in einer Linie zueinander liegen
                     strecke_bezugspunkt sb3 = strecke_bezugspunkt_start;
                     s3.set_laenge_2d(s.laenge2dim()+s2.laenge2dim(),sb3);


                     //Wenn der Vorgänger eine Gerade ist und der Nachfolger nicht:
                     if(!zeile_danach.contains(FRAESERGERADE_DIALOG))
                     {
                         if(rad_vor > 0                     &&\
                            rad_vor < s2.laenge2dim()       &&\
                            rad_vor < s.laenge2dim()        &&\
                            s3.endp().x() != s.endp().x()   &&\
                            s3.endp().y() != s.endp().y()   )
                         {
                             strecke_bezugspunkt sb = strecke_bezugspunkt_ende;
                             s.set_laenge_2d(s.laenge2dim()-seite_b,sb);
                             geo.add_strecke(s);
                         }else
                         {
                             geo.add_strecke(s);
                         }
                     }else //Wenn der Vorgänger eine Gerade ist und der Nachfolger auch
                     {
                         if(rad_vor > 0                     &&\
                            rad_vor < s2.laenge2dim()       &&\
                            rad_vor < s.laenge2dim()        &&\
                            s3.endp().x() != s.endp().x()   &&\
                            s3.endp().y() != s.endp().y()   )
                         {
                             strecke_bezugspunkt sb = strecke_bezugspunkt_ende;
                             s.set_laenge_2d(s.laenge2dim()-seite_b,sb);
                         }
                         strecke s2;
                         s2.set_start(endpunkt);
                         punkt3d p3;
                         p3.set_x(text_mitte(zeile_danach, POSITION_X, ENDE_EINTRAG));
                         p3.set_y(text_mitte(zeile_danach, POSITION_Y, ENDE_EINTRAG));
                         p3.set_z(text_mitte(zeile_danach, POSITION_Z, ENDE_EINTRAG));
                         s2.set_ende(p3);
                         double rad_akt = text_mitte(klartext.zeile(i), RADIUS, ENDE_EINTRAG).toDouble();

                         strecke s3 = s;
                         strecke_bezugspunkt sb3 = strecke_bezugspunkt_start;
                         s3.set_laenge_2d(s.laenge2dim()+s2.laenge2dim(),sb3);

                         if(rad_akt > 0                     &&\
                            rad_akt < s.laenge2dim()        &&\
                            rad_akt < s2.laenge2dim()       &&\
                            s3.endp().x() != s2.endp().x()  &&\
                            s3.endp().y() != s2.endp().y()  )
                         {
                             //-------------------------------------------------winkel berechnen:
                             double wink = winkel(startpunkt.x(),\
                                                  startpunkt.y(),\
                                                  endpunkt.x(),\
                                                  endpunkt.y(),\
                                                  s2.endp().x(),\
                                                  s2.endp().y());
                             if(wink<0)
                             {
                                 wink = -1*wink;
                             }
                             double alpha = wink/2;
                             double seite_a = rad_akt;
                             double seite_b = seite_a/tan_d(alpha);
                             if(seite_b<0)
                             {
                                 seite_b = -1*seite_b;
                             }
                             //-------------------------------------------------

                             strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                             strecke_bezugspunkt sb2 = strecke_bezugspunkt_ende;
                             s.set_laenge_2d(s.laenge2dim()-seite_b, sb);
                             s2.set_laenge_2d(s2.laenge2dim()-seite_b, sb2);
                             bogen b;
                             b.set_startpunkt(s.endp());
                             b.set_endpunkt(s2.startp());

                             //------------------------------------------------------------------------
                             b.set_radius(rad_akt, false);
                             if(b.hat_fehler())
                             {
                                 QMessageBox mb;
                                 mb.setText("Bogen hat Fehler");
                                 mb.exec();
                             }
                             //Ungenauigkeiten durch runden ausgleichen:
                             if(b.mittelpunkt().x() <= endpunkt.x()+rad_akt/1.1  &&
                                b.mittelpunkt().x() >= endpunkt.x()-rad_akt/1.1  &&
                                b.mittelpunkt().y() <= endpunkt.y()+rad_akt/1.1  &&
                                b.mittelpunkt().y() >= endpunkt.y()-rad_akt/1.1)
                             {
                                 b.set_radius(rad_akt, true);
                             }
                             //------------------------------------------------------------------------

                             geo.add_strecke(s);
                             geo.add_bogen(b);
                         }else
                         {
                             geo.add_strecke(s);
                         }
                     }
                }
                geo.zeilenvorschub();
            }else if(zeile.contains(FRAESERBOGEN_DIALOG))
            {
                punkt3d startpunkt, endpunkt;
                endpunkt.set_x(text_mitte(klartext.zeile(i), POSITION_X, ENDE_EINTRAG));
                endpunkt.set_y(text_mitte(klartext.zeile(i), POSITION_Y, ENDE_EINTRAG));
                endpunkt.set_z(text_mitte(klartext.zeile(i), POSITION_Z, ENDE_EINTRAG));
                QString zeile_davor;
                if(i > 1)//wenn es Zeilen vorab gibt
                {
                    uint ii = i-1;
                    zeile_davor = klartext.zeile(ii);
                    while(zeile_davor.isEmpty()  &&  ii-1>=1  )
                    {
                        ii--;
                        zeile_davor = klartext.zeile(ii);
                    }
                }
                if(zeile_davor.contains(FRAESERAUFRUF_DIALOG)   ||  \
                   zeile_davor.contains(FRAESERBOGEN_DIALOG)    ||  \
                   zeile_davor.contains(FRAESERGERADE_DIALOG))
                {
                    startpunkt.set_x(text_mitte(zeile_davor, POSITION_X, ENDE_EINTRAG));
                    startpunkt.set_y(text_mitte(zeile_davor, POSITION_Y, ENDE_EINTRAG));
                    startpunkt.set_z(text_mitte(zeile_davor, POSITION_Z, ENDE_EINTRAG));
                }else
                {
                    //Wenn es keinen Vorgänger gibt
                    //oder Vorgänger ist weder Gerade noch Bogen noch Fräser-Aufruf
                    //dann Strecke vom Nullpunkt beginnend:
                    QString msg;
                    msg  = "Achtung!\n";
                    msg += "Beginn der geraden Fraesbahn in Zeile ";
                    msg +=  int_to_qstring(i);
                    msg += " undefiniert!";
                    QMessageBox mb;
                    mb.setText(msg);
                    mb.exec();
                }
                double rad_akt = text_mitte(zeile, RADIUS, ENDE_EINTRAG).toDouble();
                bool im_uzs;
                if(text_mitte(zeile, BOGENRICHTUNG, ENDE_EINTRAG) == BOGENRICHTUNG_IM_UZS)
                {
                    im_uzs = true;
                }else
                {
                    im_uzs = false;
                }
                bogen b;
                b.set_startpunkt(startpunkt);
                b.set_endpunkt(endpunkt);
                b.set_radius(rad_akt, im_uzs);
                geo.add_bogen(b);
                geo.zeilenvorschub();
            }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
            {
                QString zeile_davor, zeile_davor_davor;
                if(i > 1)//wenn es Zeilen vorab gibt
                {
                    uint ii = i-1;
                    zeile_davor = klartext.zeile(ii);
                    while(zeile_davor_davor.isEmpty()  &&  ii-1>=1  )
                    {
                        ii--;
                        if(zeile_davor.isEmpty())
                        {
                            zeile_davor = klartext.zeile(ii);
                        }else
                        {
                            zeile_davor_davor = klartext.zeile(ii);
                        }
                    }
                }
                punkt3d punkt_davor;
                punkt_davor.set_x(text_mitte(zeile_davor, POSITION_X, ENDE_EINTRAG));
                punkt_davor.set_y(text_mitte(zeile_davor, POSITION_Y, ENDE_EINTRAG));
                punkt_davor.set_z(text_mitte(zeile_davor, POSITION_Z, ENDE_EINTRAG));
                punkt3d punkt_davor_davor;
                punkt_davor_davor.set_x(text_mitte(zeile_davor_davor, POSITION_X, ENDE_EINTRAG));
                punkt_davor_davor.set_y(text_mitte(zeile_davor_davor, POSITION_Y, ENDE_EINTRAG));
                punkt_davor_davor.set_z(text_mitte(zeile_davor_davor, POSITION_Z, ENDE_EINTRAG));

                if(zeile_davor.contains(FRAESERAUFRUF_DIALOG))
                {
                    geo.add_punkt(punkt_davor);
                    geo.zeilenvorschub();
                    continue;
                }

                if(abtyp == ANABFAHRTYP_KEIN)
                {
                    geo.add_punkt(punkt_davor);
                }else if(abtyp == ANABFAHRTYP_GARADE)
                {
                    if(zeile_davor.contains(FRAESERGERADE_DIALOG))
                    {

                        strecke s;
                        s.set_start(punkt_davor_davor);
                        s.set_ende(punkt_davor);
                        strecke_bezugspunkt sb;
                        sb = strecke_bezugspunkt_start;
                        //Endpunkt in X u Y setzen:
                        s.set_laenge_2d(s.laenge2dim()+fdm*2, sb);
                        //Endpunkt in Z setzen:
                        punkt3d endpunkt = s.endp();
                        endpunkt.set_z(werkstueckdicke + sicherheitsabstand);
                        s.set_ende(endpunkt);
                        //Startpunkt setzen:
                        s.set_start(punkt_davor);//Damit auch Z stimmt und weniger gerechent werden muss
                        geo.add_strecke(s);
                    }else if(zeile_davor.contains(FRAESERBOGEN_DIALOG))
                    {
                        bool bogriuzs;
                        if(text_mitte(zeile_davor, BOGENRICHTUNG, ENDE_EINTRAG) == BOGENRICHTUNG_IM_UZS)
                        {
                            bogriuzs = true;
                        }else
                        {
                            bogriuzs = false;
                        }
                        bogen b;
                        b.set_startpunkt(punkt_davor_davor);
                        b.set_endpunkt(punkt_davor);
                        b.set_radius(text_mitte(zeile_davor, RADIUS, ENDE_EINTRAG), bogriuzs);
                        punkt3d endpu;
                        endpu.set_x(b.mittelpunkt().x());
                        endpu.set_y(b.mittelpunkt().y());
                        endpu.set_z(werkstueckdicke + sicherheitsabstand);
                        strecke s;
                        s.set_start(punkt_davor);
                        s.set_ende(endpu);
                        s.drenen_um_startpunkt_2d(-90, -bogriuzs);
                        geo.add_strecke(s);
                    }
                }else //abtyp == ANABFAHRTYP_KREISBOGEN_LI oder ANABFAHRTYP_KREISBOGEN_RE
                {
                    if(zeile_davor.contains(FRAESERGERADE_DIALOG))
                    {
                        strecke s;
                        s.set_start(punkt_davor);
                        s.set_ende(punkt_davor_davor);
                        strecke_bezugspunkt sb;
                        sb = strecke_bezugspunkt_start;
                        //Startpunkt in X u Y setzen:
                        s.set_laenge_2d(fdm*2, sb);

                        //Bahnkor ermitteln:
                        if(abtyp == ANABFAHRTYP_KREISBOGEN_RE)
                        {
                            s.drenen_um_startpunkt_2d(90, false);
                            s.drenen_um_endpunkt_2d(90,true);
                            punkt3d p3;
                            p3.set_x(s.startp().x());
                            p3.set_y(s.startp().y());
                            p3.set_z(werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(punkt_davor);
                            b.set_endpunkt(p3);
                            b.set_radius(fdm*2, true);
                            geo.add_bogen(b);
                        }else //if(antyp == ANABFAHRTYP_KREISBOGEN_LI)
                        {
                            s.drenen_um_startpunkt_2d(90, true);
                            s.drenen_um_endpunkt_2d(90,false);
                            punkt3d p3;
                            p3.set_x(s.startp().x());
                            p3.set_y(s.startp().y());
                            p3.set_z(werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(punkt_davor);
                            b.set_endpunkt(p3);
                            b.set_radius(fdm*2, false);
                            geo.add_bogen(b);
                        }

                    }else if(zeile_davor.contains(FRAESERBOGEN_DIALOG))
                    {
                        bogen b;
                        b.set_startpunkt(punkt_davor_davor);
                        b.set_endpunkt(punkt_davor);
                        QString r = text_mitte(zeile_davor, RADIUS, ENDE_EINTRAG);
                        bool uzs;
                        if(text_mitte(zeile_davor, BOGENRICHTUNG, ENDE_EINTRAG) == BOGENRICHTUNG_IM_UZS)
                        {
                            uzs = true;
                        }else
                        {
                            uzs = false;
                        }
                        b.set_radius(r, uzs);
                        strecke s;
                        s.set_start(punkt_davor);
                        punkt3d mipu;
                        mipu.set_x(b.mittelpunkt().x());
                        mipu.set_y(b.mittelpunkt().y());
                        s.set_ende(mipu);
                        strecke_bezugspunkt sb;
                        sb = strecke_bezugspunkt_start;
                        if(abtyp == ANABFAHRTYP_KREISBOGEN_RE)
                        {
                            if(!uzs)
                            {
                                s.drenen_um_startpunkt_2d(180, false);
                            }
                            s.set_laenge_2d(fdm*2, sb);
                            s.drenen_um_endpunkt_2d(90, true);
                            punkt3d p3;
                            p3.set_x(s.startp().x());
                            p3.set_y(s.startp().y());
                            p3.set_z(werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(p3);
                            b.set_endpunkt(punkt_davor);
                            b.set_radius(fdm*2, false);
                            geo.add_bogen(b);
                        }else //if(antyp == ANABFAHRTYP_KREISBOGEN_LI)
                        {
                            if(uzs)
                            {
                                s.drenen_um_startpunkt_2d(180, false);
                            }
                            s.set_laenge_2d(fdm*2, sb);
                            s.drenen_um_endpunkt_2d(90, false);
                            punkt3d p3;
                            p3.set_x(s.startp().x());
                            p3.set_y(s.startp().y());
                            p3.set_z(werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(p3);
                            b.set_endpunkt(punkt_davor);
                            b.set_radius(fdm*2, true);
                            geo.add_bogen(b);
                        }
                    }
                }
                geo.zeilenvorschub();
            }
        }


        //min und max berechnen:
        text_zeilenweise geotext = geo.get_text_zeilenweise();
        for(uint i=1;i<=geotext.zeilenanzahl();i++)
        {
            text_zeilenweise spalten;
            spalten.set_trennzeichen(TRZ_EL_);
            spalten.set_text(geotext.zeile(i));

            for(uint ii=1;ii<=spalten.zeilenanzahl();ii++)
            {
                text_zeilenweise element;
                element.set_trennzeichen(TRZ_PA_);
                element.set_text(spalten.zeile(ii));

                if(element.get_text().contains(PUNKT))
                {
                    double x = element.zeile(2).toDouble();
                    double y = element.zeile(3).toDouble();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(STRECKE))
                {
                    double x = element.zeile(2).toDouble();
                    double y = element.zeile(3).toDouble();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = element.zeile(5).toDouble();
                    y = element.zeile(6).toDouble();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(BOGEN))
                {
                    double x = element.zeile(2).toDouble();
                    double y = element.zeile(3).toDouble();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = element.zeile(5).toDouble();
                    y = element.zeile(6).toDouble();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(KREIS))
                {
                    double rad = element.zeile(5).toDouble();
                    double x = element.zeile(2).toDouble()-rad;
                    double y = element.zeile(3).toDouble()-rad;
                    if(x < min_x)
                    {
                        min_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }
                    x = x+rad*2;
                    y = y+rad*2;
                    if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(ZYLINDER))
                {
                    double rad = element.zeile(5).toDouble();
                    double x = element.zeile(2).toDouble()-rad;
                    double y = element.zeile(3).toDouble()-rad;
                    if(x < min_x)
                    {
                        min_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }
                    x = x+rad*2;
                    y = y+rad*2;
                    if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(RECHTECK3D))
                {
                    rechteck3d r;
                    r.set_bezugspunkt(element.zeile(2).toInt());
                    r.set_einfuegepunkt(element.zeile(3).toDouble(),\
                                        element.zeile(4).toDouble(),\
                                        element.zeile(5).toDouble());
                    r.set_laenge(element.zeile(6).toDouble());
                    r.set_breite(element.zeile(7).toDouble());
                    r.set_rad(element.zeile(8).toDouble());
                    r.set_drewi(element.zeile(9).toDouble());

                    double x = r.unl(false).x();
                    double y = r.unl(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.unr(false).x();
                    y = r.unr(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.obl(false).x();
                    y = r.obl(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.obr(false).x();
                    y = r.obr(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                }else if(element.get_text().contains(WUERFEL))
                {
                    rechteck3d r;
                    r.set_bezugspunkt(element.zeile(2).toInt());
                    r.set_einfuegepunkt(element.zeile(3).toDouble(),\
                                        element.zeile(4).toDouble(),\
                                        element.zeile(5).toDouble());
                    r.set_laenge(element.zeile(6).toDouble());
                    r.set_breite(element.zeile(7).toDouble());
                    r.set_rad(element.zeile(8).toDouble());
                    r.set_drewi(element.zeile(9).toDouble());

                    double x = r.unl(false).x();
                    double y = r.unl(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.unr(false).x();
                    y = r.unr(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.obl(false).x();
                    y = r.obl(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                    x = r.obr(false).x();
                    y = r.obr(false).y();
                    if(x < min_x)
                    {
                        min_x = x;
                    }else if(x > max_x)
                    {
                        max_x = x;
                    }
                    if(y < min_y)
                    {
                        min_y = y;
                    }else if(y > max_y)
                    {
                        max_y = y;
                    }
                }
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

void programmtext::set_wkz(werkzeug wkz)
{
    w = wkz;
    for(uint i=1; i<=text.zeilenanzahl() ;i++)
    {
        QString zeile = text.zeile(i);
        if( zeile.contains(WKZ_NAME) )
        {
            if(zeile.contains(WKZ_DURCHMESSER))
            {
                QString aktualles_wkz =  wkz.get_werkzeug(text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG));
                QString wkzdm = text_mitte(aktualles_wkz, WKZ_DURCHMESSER, ENDE_EINTRAG);
                QString wkzdmalt = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG);
                zeile.replace( WKZ_DURCHMESSER + wkzdmalt + ENDE_EINTRAG, \
                               WKZ_DURCHMESSER + wkzdm + ENDE_EINTRAG);
            }
        }
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::aktualisiere_fkon()
{
    QString bahnkorr = BAHNRORREKTUR_keine;
    QString wkz_aktuell = "";
    double wkz_dm = 0;
    double kantendicke = 0;

    for(uint i=1; i<=klartext.zeilenanzahl() ;i++)
    {
        QString zeile = klartext.zeile(i);

        //----------------------------------------
        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            //Werte neu setzen:
            bahnkorr = text_mitte(zeile, BAHNRORREKTUR, ENDE_EINTRAG);
            wkz_aktuell = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            wkz_dm = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG).toDouble();
            kantendicke = text_mitte(zeile, KANTENDICKE, ENDE_EINTRAG).toDouble();
        }
        //----------------------------------------

        if(zeile.isEmpty())
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(PROGRAMMKOPF_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(PROGRAMMENDE_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(VARIABLE_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(KOMMENTAR_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(KREISTASCHE_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            fkon.zeilenvorschub();
        }else if(zeile.contains(FRAESERAUFRUF_DIALOG)  || \
                 zeile.contains(FRAESERGERADE_DIALOG)  || \
                 zeile.contains(FRAESERBOGEN_DIALOG)   || \
                 zeile.contains(FRAESERABFAHREN_DIALOG)  )
        {
            text_zeilenweise geo_zeile;
            geo_zeile.set_trennzeichen(TRZ_EL_);
            geo_zeile.set_text(geo.get_text_zeilenweise().zeile(i));
            for(uint ii=1; ii<=geo_zeile.zeilenanzahl() ;ii++)
            {
                text_zeilenweise geo_element;
                geo_element.set_trennzeichen(TRZ_PA_);
                geo_element.set_text(geo_zeile.zeile(ii));

                if(bahnkorr == BAHNRORREKTUR_keine)
                {
                    //wkz_dm und kantendicke sind irrelevant
                    //es ändert sich nur die Linienfarbe für die Darstellung
                    if(geo_element.get_text().contains(STRECKE))
                    {
                        strecke s(geo_element.get_text());
                        s.set_farbe(FARBE_BLAU);
                        s.set_stil(STIL_GEPUNKTET);
                        fkon.add_strecke(s);
                    }else if(geo_element.get_text().contains(BOGEN))
                    {
                        bogen b(geo_element.get_text());
                        b.set_farbe(FARBE_BLAU);
                        b.set_stil(STIL_GEPUNKTET);
                        fkon.add_bogen(b);
                    }
                }else if(bahnkorr == BAHNRORREKTUR_links)
                {
                    double versatz = wkz_dm - kantendicke;

                    if(geo_element.get_text().contains(STRECKE))
                    {
                        strecke s(geo_element.get_text());
                        strecke strecke_sp = s;
                        strecke strecke_ep = s;
                        strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                        strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                        strecke_sp.set_laenge_2d(versatz, bezug_start);
                        strecke_ep.set_laenge_2d(versatz, bezug_ende);
                        strecke_sp.drenen_um_startpunkt_2d(90, false);
                        strecke_ep.drenen_um_endpunkt_2d(90, true);
                        punkt3d sp;
                        sp.set_x(strecke_sp.endp().x());
                        sp.set_y(strecke_sp.endp().y());
                        sp.set_z(s.startp().z());
                        punkt3d ep;
                        ep.set_x(strecke_ep.startp().x());
                        ep.set_y(strecke_ep.startp().y());
                        ep.set_z(s.endp().z());
                        s.set_start(sp);
                        s.set_ende(ep);
                        s.set_farbe(FARBE_BLAU);
                        s.set_stil(STIL_GEPUNKTET);
                        fkon.add_strecke(s);
                    }else if(geo_element.get_text().contains(BOGEN))
                    {
                        bogen b(geo_element.get_text());
                        if(b.im_uzs())
                        {
                            double rad_neu = b.rad() + versatz;
                            strecke strecke_sp;
                            strecke strecke_ep;
                            punkt3d mipu;
                            mipu.set_x(b.mitte().x());
                            mipu.set_y(b.mitte().y());
                            strecke_sp.set_start(b.start());
                            strecke_sp.set_ende(mipu);
                            strecke_ep.set_start(b.ende());
                            strecke_ep.set_ende(mipu);
                            //strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                            strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                            strecke_sp.set_laenge_2d(rad_neu, bezug_ende);
                            strecke_ep.set_laenge_2d(rad_neu, bezug_ende);
                            b.set_startpunkt(strecke_sp.startp());
                            b.set_endpunkt(strecke_ep.startp());
                            b.set_radius(rad_neu, b.im_uzs());
                            b.set_farbe(FARBE_BLAU);
                            b.set_stil(STIL_GEPUNKTET);
                            fkon.add_bogen(b);
                        }else
                        {
                            double rad_neu = b.rad() - versatz;
                            if(rad_neu > 0)
                            {
                                strecke strecke_sp;
                                strecke strecke_ep;
                                punkt3d mipu;
                                mipu.set_x(b.mitte().x());
                                mipu.set_y(b.mitte().y());
                                strecke_sp.set_start(b.start());
                                strecke_sp.set_ende(mipu);
                                strecke_ep.set_start(b.ende());
                                strecke_ep.set_ende(mipu);
                                //strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                                strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                                strecke_sp.set_laenge_2d(rad_neu, bezug_ende);
                                strecke_ep.set_laenge_2d(rad_neu, bezug_ende);
                                b.set_startpunkt(strecke_sp.startp());
                                b.set_endpunkt(strecke_ep.startp());
                                b.set_radius(rad_neu, b.im_uzs());
                                b.set_farbe(FARBE_BLAU);
                                b.set_stil(STIL_GEPUNKTET);
                                fkon.add_bogen(b);
                            }
                        }

                    }




                }else  //bahnkorr == BAHNRORREKTUR_rechts
                {
                    double versatz = wkz_dm - kantendicke;

                    if(geo_element.get_text().contains(STRECKE))
                    {
                        strecke s(geo_element.get_text());
                        strecke strecke_sp = s;
                        strecke strecke_ep = s;
                        strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                        strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                        strecke_sp.set_laenge_2d(versatz, bezug_start);
                        strecke_ep.set_laenge_2d(versatz, bezug_ende);
                        strecke_sp.drenen_um_startpunkt_2d(90, true);
                        strecke_ep.drenen_um_endpunkt_2d(90, false);
                        punkt3d sp;
                        sp.set_x(strecke_sp.endp().x());
                        sp.set_y(strecke_sp.endp().y());
                        sp.set_z(s.startp().z());
                        punkt3d ep;
                        ep.set_x(strecke_ep.startp().x());
                        ep.set_y(strecke_ep.startp().y());
                        ep.set_z(s.endp().z());
                        s.set_start(sp);
                        s.set_ende(ep);
                        s.set_farbe(FARBE_BLAU);
                        s.set_stil(STIL_GEPUNKTET);
                        fkon.add_strecke(s);
                    }else if(geo_element.get_text().contains(BOGEN))
                    {
                        bogen b(geo_element.get_text());
                        if(b.im_uzs())
                        {
                            double rad_neu = b.rad() - versatz;
                            if(rad_neu > 0)
                            {
                                strecke strecke_sp;
                                strecke strecke_ep;
                                punkt3d mipu;
                                mipu.set_x(b.mitte().x());
                                mipu.set_y(b.mitte().y());
                                strecke_sp.set_start(b.start());
                                strecke_sp.set_ende(mipu);
                                strecke_ep.set_start(b.ende());
                                strecke_ep.set_ende(mipu);
                                //strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                                strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                                strecke_sp.set_laenge_2d(rad_neu, bezug_ende);
                                strecke_ep.set_laenge_2d(rad_neu, bezug_ende);
                                b.set_startpunkt(strecke_sp.startp());
                                b.set_endpunkt(strecke_ep.startp());
                                b.set_radius(rad_neu, b.im_uzs());
                                b.set_farbe(FARBE_BLAU);
                                b.set_stil(STIL_GEPUNKTET);
                                fkon.add_bogen(b);
                            }
                        }else
                        {
                            double rad_neu = b.rad() + versatz;
                            strecke strecke_sp;
                            strecke strecke_ep;
                            punkt3d mipu;
                            mipu.set_x(b.mitte().x());
                            mipu.set_y(b.mitte().y());
                            strecke_sp.set_start(b.start());
                            strecke_sp.set_ende(mipu);
                            strecke_ep.set_start(b.ende());
                            strecke_ep.set_ende(mipu);
                            //strecke_bezugspunkt bezug_start = strecke_bezugspunkt_start;
                            strecke_bezugspunkt bezug_ende = strecke_bezugspunkt_ende;
                            strecke_sp.set_laenge_2d(rad_neu, bezug_ende);
                            strecke_ep.set_laenge_2d(rad_neu, bezug_ende);
                            b.set_startpunkt(strecke_sp.startp());
                            b.set_endpunkt(strecke_ep.startp());
                            b.set_radius(rad_neu, b.im_uzs());
                            b.set_farbe(FARBE_BLAU);
                            b.set_stil(STIL_GEPUNKTET);
                            fkon.add_bogen(b);
                        }
                    }





                }
            }


            fkon.zeilenvorschub();
        }

    }





/*


    QString geometrie_aktuell, geometrie_dannach;

    for(uint i=1; i<=klartext.zeilenanzahl() ;i++)
    {
        QString zeile = klartext.zeile(i);
        uint anz_faufruf = 0;
        uint anz_fabfahr = 0;

        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            anz_faufruf++;
        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            anz_fabfahr++;
        }

        if(  anz_faufr > anz_fabfahr  )
        {
            text_zeilenweise fkon_tz = fkon.get_text_zeilenweise();

            text_zeilenweise fkon_tz_zeile;
            fkon_tz_zeile.set_trennzeichen(TRZ_EL_);
            fkon_tz_zeile.set_text(fkon_tz.zeile(i));

            text_zeilenweise fkon_tz_zeile_danach;
            fkon_tz_zeile_danach.set_trennzeichen(TRZ_EL_);
            fkon_tz_zeile_danach.set_text(fkon_tz.zeile(i+1));

            if(fkon_tz_zeile.zeilenanzahl() == 1)
            {
                geometrie_aktuell = fkon_tz_zeile.get_text();
            }else
            {

            }






        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {

        }
    }

    }
*/

}






