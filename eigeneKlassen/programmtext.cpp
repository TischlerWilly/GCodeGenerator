#include "programmtext.h"

//------------------------------------------------------------
//public:
programmtext::programmtext()
{
    clear();
    warnungen_einschalten(true);
    aktualisieren_ein_aus(true);
    aktualisieren_fkon_ein_aus(false);
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
    text_kopie.clear();
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
    versatz_x = 0;
    versatz_y = 0;
    versatz_z = 0;
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

void programmtext::set_maschinengeometrie(text_zeilenweise tz)
{
    maschinengeo.clear();

    for(uint i=1; i<=tz.zeilenanzahl();i++)
    {
        QString zeile = tz.zeile(i);
        if(zeile.contains(STRECKE))
        {
            strecke s(zeile);
            maschinengeo.add_strecke(s);
            maschinengeo.zeilenvorschub();
        }else if(zeile.contains(BOGEN))
        {
            bogen b(zeile);
            maschinengeo.add_bogen(b);
            maschinengeo.zeilenvorschub();
        }else if (zeile.contains(KREIS))
        {
            kreis k(zeile);
            maschinengeo.add_kreis(k);
            maschinengeo.zeilenvorschub();
        }
    }
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
void programmtext::cad_sortieren(uint zeinumbeg, uint zeinumend, uint anz_der_durchlaeufe)
{
    //zeinumbeg: Nummer der ersten Zeile
    //zeinumend: Nummer der letzten Zeile

    //--------------------------------------------------Schritt 0 prüfen ob CAD in Auswahl ist:
    bool hat_cad = false;
    for(uint i=zeinumbeg; i<=zeinumend; i++)
    {
        if(text.zeile(i).contains(STRECKE) || \
           (text.zeile(i).contains(BOGEN) && !text.zeile(i).contains(FRAESERBOGEN_DIALOG))   || \
           text.zeile(i).contains(KREIS)   )
        {
           hat_cad = true;
           break;
        }
    }
    if(hat_cad == false)
    {
        QMessageBox mb;
        mb.setText("Es sind keine CAD-Elemente aktiviert!");
        mb.exec();
        return;
    }

    //--------------------------------------------------Schritt 1 trennen der Auswahl:
    text_zeilenweise potfkon; //potentielle Fräskontur
    text_zeilenweise anderes;
    for(uint i=zeinumbeg; i<=zeinumend; i++)
    {
        if(text.zeile(i).contains(LISTENENDE))
        {
            break;
        }
        if(text.zeile(i).contains(STRECKE) || \
           text.zeile(i).contains(BOGEN)      )
        {
            potfkon.zeile_anhaengen(text.zeile(i));
        }else
        {
            anderes.zeile_anhaengen(text.zeile(i));
        }
    }

    //--------------------------------------------------Schritt 2 sortieren:
    punkt3d sp;
    punkt3d ep;
    text_zeilenweise sortiert;
    text_zeilenweise polylinie;

    polylinie.set_text(potfkon.zeile(1));
    potfkon.zeile_loeschen(1);

    double tolleranz = 0.1;
    while(potfkon.zeilenanzahl()>0)
    {
        QString vergleich = "1234567890";
        while(vergleich != potfkon.get_text())//So lange wie sich potfkon verändert Schleife durchlaufen
        {
            vergleich = potfkon.get_text();//Inhalt von potfkon zu schleifenbeginn merken

            for(uint i=1; i<=potfkon.zeilenanzahl() && i>0 ; )
            {
                //--------------------------------------Startpunkt bestimmen:
                QString erstes = polylinie.zeile(1);
                if(erstes.contains(STRECKE))
                {
                    strecke s(erstes);
                    sp = s.startp();
                }else if(erstes.contains(BOGEN))
                {
                    bogen b(erstes);
                    sp = b.start();
                }
                //--------------------------------------Endpunkt bestimmen:
                QString letztes = polylinie.zeile(sortiert.zeilenanzahl());
                if(letztes.contains(STRECKE))
                {
                    strecke s(letztes);
                    ep = s.endp();
                }else if(letztes.contains(BOGEN))
                {
                    bogen b(letztes);
                    ep = b.ende();
                }
                //--------------------------------------Folgegeometrie suchen:
                QString zeile = potfkon.zeile(i);
                if(zeile.contains(STRECKE))
                {
                    strecke s(zeile);
                    if(cagleich(s.startp(), ep, tolleranz))
                    {
                        polylinie.zeile_anhaengen(s.get_text());
                        potfkon.zeile_loeschen(i);
                        ep = s.endp();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }if(cagleich(s.endp(), ep, tolleranz))
                    {
                        s.richtung_unkehren();
                        polylinie.zeile_anhaengen(s.get_text());
                        potfkon.zeile_loeschen(i);
                        ep = s.endp();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }else if(cagleich(s.endp(), sp, tolleranz))
                    {
                        polylinie.zeile_vorwegsetzen(s.get_text());
                        potfkon.zeile_loeschen(i);
                        sp = s.startp();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }if(cagleich(s.startp(), sp, tolleranz))
                    {
                        s.richtung_unkehren();
                        polylinie.zeile_vorwegsetzen(s.get_text());
                        potfkon.zeile_loeschen(i);
                        sp = s.startp();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }else
                    {
                        if(i+1 <= potfkon.zeilenanzahl())
                        {
                            i++;
                            continue;
                        }else
                        {
                            polylinie.zeilen_anhaengen(potfkon.zeile(1));
                            potfkon.zeile_loeschen(1);
                            break;
                        }
                    }

                }else if(zeile.contains(BOGEN))
                {
                    bogen b(zeile);
                    if(cagleich(b.start(), ep, tolleranz))
                    {
                        polylinie.zeile_anhaengen(b.get_text());
                        potfkon.zeile_loeschen(i);
                        ep = b.ende();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }if(cagleich(b.ende(), ep, tolleranz))
                    {
                        b.richtung_unkehren();
                        polylinie.zeile_anhaengen(b.get_text());
                        potfkon.zeile_loeschen(i);
                        ep = b.ende();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }else if(cagleich(b.ende(), sp, tolleranz))
                    {
                        polylinie.zeile_vorwegsetzen(b.get_text());
                        potfkon.zeile_loeschen(i);
                        sp = b.start();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }else if(cagleich(b.start(), sp, tolleranz))
                    {
                        b.richtung_unkehren();
                        polylinie.zeile_vorwegsetzen(b.get_text());
                        potfkon.zeile_loeschen(i);
                        sp = b.start();
                        //durch das Löschen der Zeile ist der Index der Folgezeile um eins kleiner
                        //daher belibt i für den nächsten Schleifendurchlauf gleich
                        continue;
                    }else
                    {
                        if(i+1 <= potfkon.zeilenanzahl())
                        {
                            i++;
                            continue;
                        }else
                        {
                            polylinie.zeilen_anhaengen(potfkon.zeile(1));
                            potfkon.zeile_loeschen(1);
                            break;
                        }
                    }
                }else//Wenn in potfkon etwas nicht Strecke oder Bogen ist, dann ist etwas grundsätzlich
                {    //flasch gelaufen!!! weil dann gehört es in tz->anderes
                    i++;
                    continue;
                }
            }
        }
        if(potfkon.zeilenanzahl()>0)//Wenn noch geo übrig sind die nicht passen
        {
            sortiert.zeilen_anhaengen(polylinie.get_text());

            //dann fange eine neue polylinie an:
            polylinie.set_text(potfkon.zeile(1));
            potfkon.zeile_loeschen(1);

        }else //wir sind im letzten Schleifendurchlauf
        {
            sortiert.zeilen_anhaengen(polylinie.get_text());
        }
    }

    //--------------------------------------------------Schritt 3 rückspeichern:
    uint ipot = 1;
    uint iand = 1;
    for(uint i=zeinumbeg; i<=zeinumend; i++)
    {
        if(iand <= anderes.zeilenanzahl())
        {
            text.zeile_ersaetzen(i, anderes.zeile(iand));
            iand++;
        }else
        {
            //text.zeile_ersaetzen(i, potfkon.zeile(ipot));
            text.zeile_ersaetzen(i, sortiert.zeile(ipot));
            ipot++;
        }
    }

    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();

    anz_der_durchlaeufe--;
    if(anz_der_durchlaeufe > 0)
    {
        cad_sortieren(zeinumbeg, zeinumend, anz_der_durchlaeufe);
    }
}

void programmtext::linien_zu_fkon(uint zeinumbeg, uint zeinumend, text_zeilenweise defaultwerte_Dialoge)
{
    //Schritt 1 prüfen, ob nur geeignete Zeilen aktiviert wurden:
    bool auswahl_ok = true;
    for(uint i=zeinumbeg; i<=zeinumend ;i++)
    {
        if(!text.zeile(i).contains(STRECKE) && \
           !text.zeile(i).contains(BOGEN)      )
        {
            auswahl_ok = false;
        }
    }
    if(auswahl_ok == false)
    {
        QMessageBox mb;
        mb.setText("Auswahl ist nicht zulaessig!\n Funtion wurde abgebrochen.");
        mb.exec();
        return;
    }else if(zeinumend >= zeinumbeg)
    {
        //Schritt 2 Linien in fkon umrechnen:
        QString vorlage_faufr;
        QString vorlage_fabfa;
        QString vorlage_fgerade;
        QString vorlage_fbogen;
        punkt3d pend, pfolge;

        for(uint i = 1; i<=defaultwerte_Dialoge.zeilenanzahl();i++)
        {
            QString aktuelle_zeile = defaultwerte_Dialoge.zeile(i);
            if(aktuelle_zeile.contains(FRAESERAUFRUF_DIALOG))
            {
                vorlage_faufr = aktuelle_zeile;
            }else if(aktuelle_zeile.contains(FRAESERABFAHREN_DIALOG))
            {
                vorlage_fabfa = aktuelle_zeile;
            }else if(aktuelle_zeile.contains(FRAESERGERADE_DIALOG))
            {
                vorlage_fgerade = aktuelle_zeile;
            }else if(aktuelle_zeile.contains(FRAESERBOGEN_DIALOG))
            {
                vorlage_fbogen = aktuelle_zeile;
            }
        }

        text_zeilenweise tzfkon;
        QString aktuelle_zeile = text.zeile(zeinumbeg);

        if(aktuelle_zeile.contains(STRECKE))
        {
            strecke s(aktuelle_zeile);
            QString faufr = vorlage_faufr;            

            QString tmp;
            tmp = POSITION_X + text_mitte(faufr, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
            faufr.replace(tmp, POSITION_X + s.startp().x_QString() + ENDE_EINTRAG);
            tmp = POSITION_Y + text_mitte(faufr, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
            faufr.replace(tmp, POSITION_Y + s.startp().y_QString() + ENDE_EINTRAG);
            tmp = POSITION_Z + text_mitte(faufr, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
            faufr.replace(tmp, POSITION_Z + s.startp().z_QString() + ENDE_EINTRAG);
            tzfkon.zeile_anhaengen(faufr);

            QString fgerde = vorlage_fgerade;
            tmp = POSITION_X + text_mitte(fgerde, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(s.startp().x() == s.endp().x())
            {
                QString wert = "X";
                fgerde.replace(tmp, POSITION_X + wert + ENDE_EINTRAG);
            }else
            {
                fgerde.replace(tmp, POSITION_X + s.endp().x_QString() + ENDE_EINTRAG);
            }
            tmp = POSITION_Y + text_mitte(fgerde, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(s.startp().y() == s.endp().y())
            {
                QString wert = "Y";
                fgerde.replace(tmp, POSITION_Y + wert + ENDE_EINTRAG);
            }else
            {
                fgerde.replace(tmp, POSITION_Y + s.endp().y_QString() + ENDE_EINTRAG);
            }
            tmp = POSITION_Z + text_mitte(fgerde, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(s.startp().z() == s.endp().z())
            {
                QString wert = "Z";
                fgerde.replace(tmp, POSITION_Z + wert + ENDE_EINTRAG);
            }else
            {
                fgerde.replace(tmp, POSITION_Z + s.endp().z_QString() + ENDE_EINTRAG);
            }
            tzfkon.zeile_anhaengen(fgerde);
            pend = s.endp();
        }else if(aktuelle_zeile.contains(BOGEN))
        {
            bogen b(aktuelle_zeile);
            QString faufr = vorlage_faufr;

            QString tmp;
            tmp = POSITION_X + text_mitte(faufr, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;            
            faufr.replace(tmp, POSITION_X + b.start().x_QString() + ENDE_EINTRAG);
            tmp = POSITION_Y + text_mitte(faufr, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
            faufr.replace(tmp, POSITION_Y + b.start().y_QString() + ENDE_EINTRAG);
            tmp = POSITION_Z + text_mitte(faufr, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
            faufr.replace(tmp, POSITION_Z + b.start().z_QString() + ENDE_EINTRAG);
            tzfkon.zeile_anhaengen(faufr);

            QString fbogen = vorlage_fbogen;
            tmp = POSITION_X + text_mitte(fbogen, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(b.start().x() == b.ende().x())
            {
                QString wert = "X";
                fbogen.replace(tmp, POSITION_X + wert + ENDE_EINTRAG);
            }else
            {
                fbogen.replace(tmp, POSITION_X + b.ende().x_QString() + ENDE_EINTRAG);
            }
            tmp = POSITION_Y + text_mitte(fbogen, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(b.start().y() == b.ende().y())
            {
                QString wert = "Y";
                fbogen.replace(tmp, POSITION_Y + wert + ENDE_EINTRAG);
            }else
            {
                fbogen.replace(tmp, POSITION_Y + b.ende().y_QString() + ENDE_EINTRAG);
            }
            tmp = POSITION_Z + text_mitte(fbogen, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(b.start().z() == b.ende().z())
            {
                QString wert = "Z";
                fbogen.replace(tmp, POSITION_Z + wert + ENDE_EINTRAG);
            }else
            {
                fbogen.replace(tmp, POSITION_Z + b.ende().z_QString() + ENDE_EINTRAG);
            }
            tmp = RADIUS + text_mitte(fbogen, RADIUS, ENDE_EINTRAG) + ENDE_EINTRAG;
            fbogen.replace(tmp, RADIUS + b.rad_qString() + ENDE_EINTRAG);
            tmp = BOGENRICHTUNG + text_mitte(fbogen, BOGENRICHTUNG, ENDE_EINTRAG) + ENDE_EINTRAG;
            if(b.im_uzs() == true)
            {
                QString richtung = BOGENRICHTUNG_IM_UZS;
                fbogen.replace(tmp,BOGENRICHTUNG + richtung + ENDE_EINTRAG);
            }else
            {
                QString richtung = BOGENRICHTUNG_IM_GUZS;
                fbogen.replace(tmp,BOGENRICHTUNG + richtung + ENDE_EINTRAG);
            }
            tzfkon.zeile_anhaengen(fbogen);
            pend = b.ende();
        }

        for(uint i=zeinumbeg+1; i<=zeinumend ;i++)
        {
            aktuelle_zeile = text.zeile(i);
            if(aktuelle_zeile.contains(STRECKE))
            {
                strecke s(aktuelle_zeile);
                QString tmp;

                pfolge = s.startp();
                if(cagleich(pend, pfolge, 0.1) == false)
                {
                    tzfkon.zeile_anhaengen(vorlage_fabfa);
                    QString faufr = vorlage_faufr;
                    tmp = POSITION_X + text_mitte(faufr, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_X + s.startp().x_QString() + ENDE_EINTRAG);
                    tmp = POSITION_Y + text_mitte(faufr, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_Y + s.startp().y_QString() + ENDE_EINTRAG);
                    tmp = POSITION_Z + text_mitte(faufr, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_Z + s.startp().z_QString() + ENDE_EINTRAG);
                    tzfkon.zeile_anhaengen(faufr);
                }

                QString fgerde = vorlage_fgerade;
                tmp = POSITION_X + text_mitte(fgerde, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(s.startp().x() == s.endp().x())
                {
                    QString wert = "X";
                    fgerde.replace(tmp, POSITION_X + wert + ENDE_EINTRAG);
                }else
                {
                    fgerde.replace(tmp, POSITION_X + s.endp().x_QString() + ENDE_EINTRAG);
                }
                tmp = POSITION_Y + text_mitte(fgerde, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(s.startp().y() == s.endp().y())
                {
                    QString wert = "Y";
                    fgerde.replace(tmp, POSITION_Y + wert + ENDE_EINTRAG);
                }else
                {
                    fgerde.replace(tmp, POSITION_Y + s.endp().y_QString() + ENDE_EINTRAG);
                }
                tmp = POSITION_Z + text_mitte(fgerde, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(s.startp().z() == s.endp().z())
                {
                    QString wert = "Z";
                    fgerde.replace(tmp, POSITION_Z + wert + ENDE_EINTRAG);
                }else
                {
                    fgerde.replace(tmp, POSITION_Z + s.endp().z_QString() + ENDE_EINTRAG);
                }
                tzfkon.zeile_anhaengen(fgerde);
                pend = s.endp();
            }else if(aktuelle_zeile.contains(BOGEN))
            {
                bogen b(aktuelle_zeile);
                QString tmp;

                pfolge = b.start();
                if(cagleich(pend, pfolge, 0.1) == false)
                {
                    tzfkon.zeile_anhaengen(vorlage_fabfa);
                    QString faufr = vorlage_faufr;
                    tmp = POSITION_X + text_mitte(faufr, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_X + b.start().x_QString() + ENDE_EINTRAG);
                    tmp = POSITION_Y + text_mitte(faufr, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_Y + b.start().y_QString() + ENDE_EINTRAG);
                    tmp = POSITION_Z + text_mitte(faufr, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                    faufr.replace(tmp, POSITION_Z + b.start().z_QString() + ENDE_EINTRAG);
                    tzfkon.zeile_anhaengen(faufr);
                }

                QString fbogen = vorlage_fbogen;
                tmp = POSITION_X + text_mitte(fbogen, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(b.start().x() == b.ende().x())
                {
                    QString wert = "X";
                    fbogen.replace(tmp, POSITION_X + wert + ENDE_EINTRAG);
                }else
                {
                    fbogen.replace(tmp, POSITION_X + b.ende().x_QString() + ENDE_EINTRAG);
                }
                tmp = POSITION_Y + text_mitte(fbogen, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(b.start().y() == b.ende().y())
                {
                    QString wert = "Y";
                    fbogen.replace(tmp, POSITION_Y + wert + ENDE_EINTRAG);
                }else
                {
                    fbogen.replace(tmp, POSITION_Y + b.ende().y_QString() + ENDE_EINTRAG);
                }
                tmp = POSITION_Z + text_mitte(fbogen, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(b.start().z() == b.ende().z())
                {
                    QString wert = "Z";
                    fbogen.replace(tmp, POSITION_Z + wert + ENDE_EINTRAG);
                }else
                {
                    fbogen.replace(tmp, POSITION_Z + b.ende().z_QString() + ENDE_EINTRAG);
                }
                tmp = RADIUS + text_mitte(fbogen, RADIUS, ENDE_EINTRAG) + ENDE_EINTRAG;
                fbogen.replace(tmp, RADIUS + b.rad_qString() + ENDE_EINTRAG);
                tmp = BOGENRICHTUNG + text_mitte(fbogen, BOGENRICHTUNG, ENDE_EINTRAG) + ENDE_EINTRAG;
                if(b.im_uzs() == true)
                {
                    QString richtung = BOGENRICHTUNG_IM_UZS;
                    fbogen.replace(tmp,BOGENRICHTUNG + richtung + ENDE_EINTRAG);
                }else
                {
                    QString richtung = BOGENRICHTUNG_IM_GUZS;
                    fbogen.replace(tmp,BOGENRICHTUNG + richtung + ENDE_EINTRAG);
                }
                tzfkon.zeile_anhaengen(fbogen);
                pend = b.ende();
            }
        }
        tzfkon.zeile_anhaengen(vorlage_fabfa);

        //Schritt 3 CAD löschen und CAM einfügen:
        text.zeilen_loeschen(zeinumbeg, zeinumend-zeinumbeg+1);
        if(zeinumbeg > 1)
        {
            text.zeilen_einfuegen(zeinumbeg-1, tzfkon.get_text());
        }else
        {
            text.zeile_vorwegsetzen(tzfkon.zeile(1));
            tzfkon.zeile_loeschen(1);
            text.zeilen_einfuegen(1, tzfkon.get_text());
        }
        aktualisiere_klartext_var_geo();
        aktualisiere_fkon();
        aktualisiere_anzeigetext();
    }
}

void programmtext::fkon_zu_linien(uint zeinumbeg, uint zeinumend)
{
    punkt3d p;
    QString aktzeil = klartext.zeile(zeinumbeg);
    p.set_x(text_mitte(aktzeil, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    p.set_y(text_mitte(aktzeil, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    p.set_z(text_mitte(aktzeil, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());
    text_zeilenweise tzgeo;
    for(uint i =zeinumbeg+1; i<=zeinumend ;i++)
    {
        aktzeil = klartext.zeile(i);
        if(aktzeil.contains(FRAESERGERADE_DIALOG))
        {
            strecke s;
            s.set_farbe(FARBE_GRUEN);
            s.set_start(p);
            p.set_x(text_mitte(aktzeil, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
            p.set_y(text_mitte(aktzeil, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
            p.set_z(text_mitte(aktzeil, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());
            s.set_ende(p);
            tzgeo.zeile_anhaengen(s.get_text());
        }else if(aktzeil.contains(FRAESERBOGEN_DIALOG))
        {
            bogen b;
            b.set_farbe(FARBE_GRUEN);
            b.set_startpunkt(p);
            p.set_x(text_mitte(aktzeil, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
            p.set_y(text_mitte(aktzeil, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
            p.set_z(text_mitte(aktzeil, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());
            b.set_endpunkt(p);
            QString richtung = (text_mitte(aktzeil, BOGENRICHTUNG, ENDE_EINTRAG));
            QString rad = (text_mitte(aktzeil, RADIUS, ENDE_EINTRAG));
            if(richtung == BOGENRICHTUNG_IM_UZS)
            {
                b.set_radius(rad, true);
            }else
            {
                b.set_radius(rad, false);
            }
            tzgeo.zeile_anhaengen(b.get_text());
        }
    }
    //CAM löschen und CAD einfügen:
    text.zeilen_loeschen(zeinumbeg, zeinumend-zeinumbeg+1);
    if(zeinumbeg > 1)
    {
        text.zeilen_einfuegen(zeinumbeg-1, tzgeo.get_text());
    }else
    {
        text.zeile_vorwegsetzen(tzgeo.zeile(1));
        tzgeo.zeile_loeschen(1);
        text.zeilen_einfuegen(1, tzgeo.get_text());
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

text_zeilenweise programmtext::fkon_use_values(text_zeilenweise cam)
{
    //Wo möglich Variablen statt fixer Werte eintragen:

    //Erste Zeile ist Fräseraufruf:
    double xvor = text_mitte(cam.zeile(1), POSITION_X, ENDE_EINTRAG).toDouble();
    double yvor = text_mitte(cam.zeile(1), POSITION_Y, ENDE_EINTRAG).toDouble();
    double zvor = text_mitte(cam.zeile(1), POSITION_Z, ENDE_EINTRAG).toDouble();

    //Mit der 2. Zeile beginnt die Fräsbahn:
    for(uint i=2; i<=cam.zeilenanzahl() ;i++)
    {
        QString zeile = cam.zeile(i);
        double xakt = text_mitte(zeile, POSITION_X, ENDE_EINTRAG).toDouble();
        double yakt = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG).toDouble();
        double zakt = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG).toDouble();
        if(xvor == xakt)
        {
            QString vor;
            vor += POSITION_X;
            vor += text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            vor += ENDE_EINTRAG;
            QString nach;
            nach += POSITION_X;
            nach += "X";
            nach += ENDE_EINTRAG;
            zeile.replace(vor, nach);
        }
        if(yvor == yakt)
        {
            QString vor;
            vor += POSITION_Y;
            vor += text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            vor += ENDE_EINTRAG;
            QString nach;
            nach += POSITION_Y;
            nach += "Y";
            nach += ENDE_EINTRAG;
            zeile.replace(vor, nach);
        }
        if(zvor == zakt)
        {
            QString vor;
            vor += POSITION_Z;
            vor += text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
            vor += ENDE_EINTRAG;
            QString nach;
            nach += POSITION_Z;
            nach += "Z";
            nach += ENDE_EINTRAG;
            zeile.replace(vor, nach);
        }
        cam.zeile_ersaetzen(i, zeile);
        xvor = xakt;
        yvor = yakt;
        zvor = zakt;
    }
    return cam;
}

void programmtext::fkon_richtung_wechseln(uint zeinumbeg, uint zeinumend)
{
    //Inhalt der Dialoge merken:
    QString aufruf = text.zeile(zeinumbeg);
    QString abfahen = text.zeile(zeinumend);

    //Richtung umkehren:
    text_zeilenweise tzcam;
    QString akttext;
    QString aktklartext;
    QString vorklartext;
    punkt3d p;
    for(uint i=zeinumend-1; i>=zeinumbeg ;i--)
    {
        aktklartext = klartext.zeile(i);

        if(i == zeinumend-1)//Letzter Punkt auf der Kontur = erster Punkt in Gegenrichtung
        {
            //Inhalt des Fräseraufrufes ändern und für später merken:
            p.set_x(text_mitte(aktklartext, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
            p.set_y(text_mitte(aktklartext, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
            p.set_z(text_mitte(aktklartext, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());
            QString tmp;
            tmp = POSITION_X + text_mitte(aufruf, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
            aufruf.replace(tmp, POSITION_X + p.x_QString() + ENDE_EINTRAG);
            tmp = POSITION_Y + text_mitte(aufruf, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
            aufruf.replace(tmp, POSITION_Y + p.y_QString() + ENDE_EINTRAG);
            tmp = POSITION_Z + text_mitte(aufruf, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
            aufruf.replace(tmp, POSITION_Z + p.z_QString() + ENDE_EINTRAG);

        }

        if(i == zeinumbeg)//faufruf vor umkehr der Richtung //letzter Schleifendurchlauf
        {
            //wird gegen fabfah getauscht
            tzcam.zeile_vorwegsetzen(aufruf);
            tzcam.zeile_anhaengen(abfahen);
        }else//Fräsbahnen zwischen Aufruf und Abfahren
        {
            akttext = text.zeile(i);
            vorklartext = klartext.zeile(i-1);

            p.set_x(text_mitte(vorklartext, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
            p.set_y(text_mitte(vorklartext, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
            p.set_z(text_mitte(vorklartext, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());
            if(aktklartext.contains(FRAESERGERADE_DIALOG))
            {
                QString tmp;
                tmp = POSITION_X + text_mitte(akttext, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_X + p.x_QString() + ENDE_EINTRAG);
                tmp = POSITION_Y + text_mitte(akttext, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_Y + p.y_QString() + ENDE_EINTRAG);
                tmp = POSITION_Z + text_mitte(akttext, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_Z + p.z_QString() + ENDE_EINTRAG);
                tzcam.zeile_anhaengen(akttext);
            }else if(aktklartext.contains(FRAESERBOGEN_DIALOG))
            {
                QString tmp;
                tmp = POSITION_X + text_mitte(akttext, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_X + p.x_QString() + ENDE_EINTRAG);
                tmp = POSITION_Y + text_mitte(akttext, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_Y + p.y_QString() + ENDE_EINTRAG);
                tmp = POSITION_Z + text_mitte(akttext, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
                akttext.replace(tmp, POSITION_Z + p.z_QString() + ENDE_EINTRAG);
                QString richtung = text_mitte(akttext, BOGENRICHTUNG, ENDE_EINTRAG);
                tmp = BOGENRICHTUNG + richtung + ENDE_EINTRAG;
                if(richtung == BOGENRICHTUNG_IM_UZS)
                {
                    richtung = BOGENRICHTUNG_IM_GUZS;

                }else
                {
                    richtung = BOGENRICHTUNG_IM_UZS;
                }
                akttext.replace(tmp, BOGENRICHTUNG + richtung + ENDE_EINTRAG);
                tzcam.zeile_anhaengen(akttext);
            }
        }
    }
    //Wo möglich Variablen statt fixer Werte eintragen:
    tzcam = fkon_use_values(tzcam);

    //Änderungen zurück in programmtext schreiben:
    text.zeilen_loeschen(zeinumbeg, zeinumend-zeinumbeg+1);
    if(zeinumbeg > 1)
    {
        text.zeilen_einfuegen(zeinumbeg-1, tzcam.get_text());
    }else
    {
        text.zeile_vorwegsetzen(tzcam.zeile(1));
        tzcam.zeile_loeschen(1);
        text.zeilen_einfuegen(1, tzcam.get_text());
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();

}

void programmtext::fkon_vor(uint zeinumbeg, uint zeinumend)
{
    //Ist fkon mind 4 Zeilen lang (Aufruf + 2x Gerade oder Bogen + Abfahren)?:
    int anz = zeinumend-zeinumbeg+1;
    if(anz < 4)
    {
        return;
    }

    //Inhalt der Dialoge merken:
    QString aufruf_t = text.zeile(zeinumbeg);
    QString aufruf_kt = klartext.zeile(zeinumbeg);

    //QString abfa_t = text.zeile(zeinumend);
    //QString abfa_kt = klartext.zeile(zeinumend);

    //QString camvorabfa_t = text.zeile(zeinumend-1);
    QString camvorabfa_kt = klartext.zeile(zeinumend-1);

    QString camnachaufruf_t = text.zeile(zeinumbeg+1);
    QString camnachaufruf_kt = klartext.zeile(zeinumbeg+1);

    text_zeilenweise tzcam_t;
    tzcam_t.set_text(text.zeilen(zeinumbeg, zeinumend-zeinumbeg+1));

    //Prüfen, ob fkon eine geschlossene Kontur ist:
    //Ist der Endpunkt der Startpunkt?:
    punkt3d pstart;
    punkt3d pend;
    pstart.set_x(text_mitte(aufruf_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    pstart.set_y(text_mitte(aufruf_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    pend.set_x(text_mitte(camvorabfa_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    pend.set_y(text_mitte(camvorabfa_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    if(!cagleich(pstart, pend, 0.1))
    {
        return;
    }

    //Fräseraufruf um einen Punkt nach vorne verschieben:
    QString tmp;
    QString aufruf_t_neu = aufruf_t;
    punkt3d p;
    p.set_x(text_mitte(camnachaufruf_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    p.set_y(text_mitte(camnachaufruf_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    p.set_z(text_mitte(camnachaufruf_kt, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());

    tmp = POSITION_X + text_mitte(aufruf_t_neu, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_X + p.x_QString() + ENDE_EINTRAG);
    tmp = POSITION_Y + text_mitte(aufruf_t_neu, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_Y + p.y_QString() + ENDE_EINTRAG);
    tmp = POSITION_Z + text_mitte(aufruf_t_neu, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_Z + p.z_QString() + ENDE_EINTRAG);

    //Fräseraufruf + erste Gerade oder erster Bogen löschen:
    tzcam_t.zeilen_loeschen(1,2);
    //erste Gerade oder ersten Bogen vor dem Abfahren einfügen:
    tzcam_t.zeile_einfuegen(tzcam_t.zeilenanzahl()-1, camnachaufruf_t);
    //geänderten Fräseraufruf am Anfang einfügen:
    tzcam_t.zeile_vorwegsetzen(aufruf_t_neu);

    //Wo möglich Variablen statt fixer Werte eintragen:
    tzcam_t = fkon_use_values(tzcam_t);

    //Änderungen zurück in programmtext schreiben:
    text.zeilen_loeschen(zeinumbeg, zeinumend-zeinumbeg+1);
    if(zeinumbeg > 1)
    {
        text.zeilen_einfuegen(zeinumbeg-1, tzcam_t.get_text());
    }else
    {
        text.zeile_vorwegsetzen(tzcam_t.zeile(1));
        tzcam_t.zeile_loeschen(1);
        text.zeilen_einfuegen(1, tzcam_t.get_text());
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::fkon_nach(uint zeinumbeg, uint zeinumend)
{
    //Ist fkon mind 4 Zeilen lang (Aufruf + 2x Gerade oder Bogen + Abfahren)?:
    int anz = zeinumend-zeinumbeg+1;
    if(anz < 4)
    {
        return;
    }

    //Inhalt der Dialoge merken:
    QString aufruf_t = text.zeile(zeinumbeg);
    QString aufruf_kt = klartext.zeile(zeinumbeg);

    //QString abfa_t = text.zeile(zeinumend);
    //QString abfa_kt = klartext.zeile(zeinumend);

    QString camvorabfa_t = text.zeile(zeinumend-1);
    QString camvorabfa_kt = klartext.zeile(zeinumend-1);
    //QString cam2vorabfa_t = text.zeile(zeinumend-2);
    QString cam2vorabfa_kt = klartext.zeile(zeinumend-2);

    //QString camnachaufruf_t = text.zeile(zeinumbeg+1);
    //QString camnachaufruf_kt = klartext.zeile(zeinumbeg+1);

    text_zeilenweise tzcam_t;
    tzcam_t.set_text(text.zeilen(zeinumbeg, zeinumend-zeinumbeg+1));

    //Prüfen, ob fkon eine geschlossene Kontur ist:
    //Ist der Endpunkt der Startpunkt?:
    punkt3d pstart;
    punkt3d pend;
    pstart.set_x(text_mitte(aufruf_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    pstart.set_y(text_mitte(aufruf_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    pend.set_x(text_mitte(camvorabfa_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    pend.set_y(text_mitte(camvorabfa_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    if(!cagleich(pstart, pend, 0.1))
    {
        return;
    }

    //Fräseraufruf um einen Punkt zurück verschieben:
    QString tmp;
    QString aufruf_t_neu = aufruf_t;
    punkt3d p;
    p.set_x(text_mitte(cam2vorabfa_kt, POSITION_X, ENDE_EINTRAG).toDouble() - get_ax());
    p.set_y(text_mitte(cam2vorabfa_kt, POSITION_Y, ENDE_EINTRAG).toDouble() - get_ay());
    p.set_z(text_mitte(cam2vorabfa_kt, POSITION_Z, ENDE_EINTRAG).toDouble() - get_az());

    tmp = POSITION_X + text_mitte(aufruf_t_neu, POSITION_X, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_X + p.x_QString() + ENDE_EINTRAG);
    tmp = POSITION_Y + text_mitte(aufruf_t_neu, POSITION_Y, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_Y + p.y_QString() + ENDE_EINTRAG);
    tmp = POSITION_Z + text_mitte(aufruf_t_neu, POSITION_Z, ENDE_EINTRAG) + ENDE_EINTRAG;
    aufruf_t_neu.replace(tmp, POSITION_Z + p.z_QString() + ENDE_EINTRAG);

    //Fräseraufruf löschen:
    tzcam_t.zeile_loeschen(1);
    //Lete Gerade oder letzten Bogen löschen:
    tzcam_t.zeile_loeschen(tzcam_t.zeilenanzahl()-1);

    //letzte Gerade oder letzten Bogen am Anfang einfügen:
    tzcam_t.zeile_vorwegsetzen(camvorabfa_t);
    //geänderten Fräseraufruf am Anfang einfügen:
    tzcam_t.zeile_vorwegsetzen(aufruf_t_neu);

    //Wo möglich Variablen statt fixer Werte eintragen:
    tzcam_t = fkon_use_values(tzcam_t);

    //Änderungen zurück in programmtext schreiben:
    text.zeilen_loeschen(zeinumbeg, zeinumend-zeinumbeg+1);
    if(zeinumbeg > 1)
    {
        text.zeilen_einfuegen(zeinumbeg-1, tzcam_t.get_text());
    }else
    {
        text.zeile_vorwegsetzen(tzcam_t.zeile(1));
        tzcam_t.zeile_loeschen(1);
        text.zeilen_einfuegen(1, tzcam_t.get_text());
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::rta_zu_cad(uint zeinumakt)
{
    QString zeitex = klartext.zeile(zeinumakt);
    if(!zeitex.contains(RECHTECKTASCHE_DIALOG))
    {
        return;
    }

    //AX + AY + Schablonenhöhe wieder abzeihen:
    QString x_alt = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG);
    QString tmp = x_alt;
    tmp += "-";
    tmp += get_ax_qstring();
    QString x_neu = ausdruck_auswerten(tmp);
    zeitex.replace(POSITION_X + x_alt + ENDE_EINTRAG, POSITION_X + x_neu + ENDE_EINTRAG);

    QString y_alt = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG);
    tmp = y_alt;
    tmp += "-";
    tmp += get_ay_qstring();
    QString y_neu = ausdruck_auswerten(tmp);
    zeitex.replace(POSITION_Y + y_alt + ENDE_EINTRAG, POSITION_Y + y_neu + ENDE_EINTRAG);

    QString z_alt = text_mitte(zeitex, POSITION_Z, ENDE_EINTRAG);
    tmp = z_alt;
    tmp += "-";
    tmp += get_az_qstring();
    QString z_neu = ausdruck_auswerten(tmp);
    zeitex.replace(POSITION_Z + z_alt + ENDE_EINTRAG, POSITION_Z + z_neu + ENDE_EINTRAG);


    double eckrad = text_mitte(zeitex, RADIUS, ENDE_EINTRAG).toDouble();
    double drewi = text_mitte(zeitex, WINKEL, ENDE_EINTRAG).toDouble();
    //dreht rta immer um den mipu unabhängig vom Bezugspunkt
    double tati = text_mitte(zeitex, TASCHENTIEFE, ENDE_EINTRAG).toDouble();
    double posinz = werkstueckdicke - tati;
    double tal = text_mitte(zeitex, TASCHENLAENGE, ENDE_EINTRAG).toDouble();
    double tab = text_mitte(zeitex, TASCHENBREITE, ENDE_EINTRAG).toDouble();
    QString bezpunkt = text_mitte(zeitex, BEZUGSPUNKT, ENDE_EINTRAG);
    punkt3d mipu;
    if(bezpunkt == BEZUGSPUNKT_MITTE)
    {
        double x;
        double y;
        mipu.set_x(text_mitte(zeitex, POSITION_X, ENDE_EINTRAG));
        mipu.set_y(text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG));
    }else if(bezpunkt == BEZUGSPUNKT_LINKS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x + tal/2);
        mipu.set_y(y);
    }else if(bezpunkt == BEZUGSPUNKT_RECHTS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x - tal/2);
        mipu.set_y(y);
    }else if(bezpunkt == BEZUGSPUNKT_OBEN)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x);
        mipu.set_y(y - tab/2);
    }else if(bezpunkt == BEZUGSPUNKT_UNTEN)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x);
        mipu.set_y(y + tab/2);
    }else if(bezpunkt == BEZUGSPUNKT_OBEN_LINKS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x + tal/2);
        mipu.set_y(y - tab/2);
    }else if(bezpunkt == BEZUGSPUNKT_OBEN_RECHTS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x - tal/2);
        mipu.set_y(y - tab/2);
    }else if(bezpunkt == BEZUGSPUNKT_UNTEN_LINKS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x + tal/2);
        mipu.set_y(y + tab/2);
    }else if(bezpunkt == BEZUGSPUNKT_UNTEN_RECHTS)
    {
        double x = text_mitte(zeitex, POSITION_X, ENDE_EINTRAG).toDouble();
        double y = text_mitte(zeitex, POSITION_Y, ENDE_EINTRAG).toDouble();
        mipu.set_x(x - tal/2);
        mipu.set_y(y + tab/2);
    }

    mipu.set_z(posinz);

    rechteck3d reck;
    reck.set_bezugspunkt(BEZUGSPUNKT_MITTE);
    reck.set_einfuegepunkt(mipu);
    reck.set_laenge(tal);
    reck.set_breite(tab);
    reck.set_drewi(drewi * -1);
    reck.set_z(posinz);

    QString farbe = FARBE_GRUEN;

    strecke sli;
    sli.set_farbe(farbe);
    sli.set_start(reck.unl(false));
    sli.set_ende(reck.obl(false));
    strecke sob;
    sob.set_farbe(farbe);
    sob.set_start(reck.obl(false));
    sob.set_ende(reck.obr(false));
    strecke sre;
    sre.set_farbe(farbe);
    sre.set_start(reck.obr(false));
    sre.set_ende(reck.unr(false));
    strecke sun;
    sun.set_farbe(farbe);
    sun.set_start(reck.unr(false));
    sun.set_ende(reck.unl(false));

    text_zeilenweise tzcad;

    if(eckrad <= 0)
    {
        tzcad.set_text(sli.get_text());
        tzcad.zeile_anhaengen(sob.get_text());
        tzcad.zeile_anhaengen(sre.get_text());
        tzcad.zeile_anhaengen(sun.get_text());
    }else
    {
        double mindim;
        if(tab < tal)
        {
            mindim = tab;
        }else
        {
            mindim = tal;
        }
        if(eckrad*2 < mindim)
        {
            //Strecken und Bögen einfügen:
            strecke_bezugspunkt sbez = strecke_bezugspunkt_mitte;
            sli.set_laenge_2d(sli.laenge2dim() - 2*eckrad , sbez);
            sob.set_laenge_2d(sob.laenge2dim() - 2*eckrad , sbez);
            sre.set_laenge_2d(sre.laenge2dim() - 2*eckrad , sbez);
            sun.set_laenge_2d(sun.laenge2dim() - 2*eckrad , sbez);

            bogen bol;
            bol.set_farbe(farbe);
            bol.set_startpunkt(sli.endp());
            bol.set_endpunkt(sob.startp());
            bol.set_radius(eckrad, true);
            bogen bor;
            bor.set_farbe(farbe);
            bor.set_startpunkt(sob.endp());
            bor.set_endpunkt(sre.startp());
            bor.set_radius(eckrad, true);
            bogen bur;
            bur.set_farbe(farbe);
            bur.set_startpunkt(sre.endp());
            bur.set_endpunkt(sun.startp());
            bur.set_radius(eckrad, true);
            bogen bul;
            bul.set_farbe(farbe);
            bul.set_startpunkt(sun.endp());
            bul.set_endpunkt(sli.startp());
            bul.set_radius(eckrad, true);

            tzcad.set_text(sli.get_text());
            tzcad.zeile_anhaengen(bol.get_text());
            tzcad.zeile_anhaengen(sob.get_text());
            tzcad.zeile_anhaengen(bor.get_text());
            tzcad.zeile_anhaengen(sre.get_text());
            tzcad.zeile_anhaengen(bur.get_text());
            tzcad.zeile_anhaengen(sun.get_text());
            tzcad.zeile_anhaengen(bul.get_text());

        }else if(eckrad*2 == mindim)
        {
            //nur Bögen einfügen:
            strecke_bezugspunkt sbez = strecke_bezugspunkt_mitte;
            sli.set_laenge_2d(sli.laenge2dim() - 2*eckrad , sbez);
            sob.set_laenge_2d(sob.laenge2dim() - 2*eckrad , sbez);
            sre.set_laenge_2d(sre.laenge2dim() - 2*eckrad , sbez);
            sun.set_laenge_2d(sun.laenge2dim() - 2*eckrad , sbez);

            bogen bol;
            bol.set_farbe(farbe);
            bol.set_startpunkt(sli.endp());
            bol.set_endpunkt(sob.startp());
            bol.set_radius(eckrad, true);
            bogen bor;
            bor.set_farbe(farbe);
            bor.set_startpunkt(sob.endp());
            bor.set_endpunkt(sre.startp());
            bor.set_radius(eckrad, true);
            bogen bur;
            bur.set_farbe(farbe);
            bur.set_startpunkt(sre.endp());
            bur.set_endpunkt(sun.startp());
            bur.set_radius(eckrad, true);
            bogen bul;
            bul.set_farbe(farbe);
            bul.set_startpunkt(sun.endp());
            bul.set_endpunkt(sli.startp());
            bul.set_radius(eckrad, true);

            if(tal == tab)
            {
                tzcad.set_text(bol.get_text());
                tzcad.zeile_anhaengen(bor.get_text());
                tzcad.zeile_anhaengen(bur.get_text());
                tzcad.zeile_anhaengen(bul.get_text());
            }else if(tal == mindim)
            {
                tzcad.set_text(sli.get_text());
                tzcad.zeile_anhaengen(bol.get_text());
                //sob nicht
                tzcad.zeile_anhaengen(bor.get_text());
                tzcad.zeile_anhaengen(sre.get_text());
                tzcad.zeile_anhaengen(bur.get_text());
                //sun nicht
                tzcad.zeile_anhaengen(bul.get_text());
            }else //if(tab == mindim)
            {
                //sli nicht
                tzcad.set_text(bol.get_text());
                tzcad.zeile_anhaengen(sob.get_text());
                tzcad.zeile_anhaengen(bor.get_text());
                //sre nicht
                tzcad.zeile_anhaengen(bur.get_text());
                tzcad.zeile_anhaengen(sun.get_text());
                tzcad.zeile_anhaengen(bul.get_text());
            }


        }else //(eckrad*2 > mindim) --> get technisch nicht
        {
            return;
        }
    }

    //rta löschen und cad einfügen:
    text.zeile_loeschen(zeinumakt);
    if(zeinumakt > 1)
    {
        text.zeilen_einfuegen(zeinumakt-1, tzcad.get_text());
    }else
    {
        text.zeile_vorwegsetzen(tzcad.zeile(1));
        tzcad.zeile_loeschen(1);
        text.zeilen_einfuegen(1, tzcad.get_text());
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::versatzvar(uint zeinumbeg, uint zeinumend)
{
    QString varname_ax = "VX";
    QString varname_ay = "VY";

    Dialog_Variable dialvar;
    QString variable_ax = dialvar.get_variable(varname_ax, "0");
    QString variable_ay = dialvar.get_variable(varname_ay, "0");

    for(uint i=zeinumbeg; i<=zeinumend ; i++)
    {
        QString zeile = text.zeile(i);
        if(zeile.contains(KREISTASCHE_DIALOG)       || \
           zeile.contains(RECHTECKTASCHE_DIALOG)    || \
           zeile.contains(FRAESERAUFRUF_DIALOG)     || \
           zeile.contains(FRAESERGERADE_DIALOG)     || \
           zeile.contains(FRAESERBOGEN_DIALOG)      || \
           zeile.contains(BOHREN_DIALOG)             )
        {
            QString xalt;
            xalt = POSITION_X;
            xalt += text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            xalt += ENDE_EINTRAG;
            QString xneu;
            xneu = POSITION_X;
            xneu += text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            xneu += "+";
            xneu += varname_ax;
            xneu += ENDE_EINTRAG;
            zeile.replace(xalt, xneu);

            QString yalt;
            yalt = POSITION_Y;
            yalt += text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            yalt += ENDE_EINTRAG;
            QString yneu;
            yneu = POSITION_Y;
            yneu += text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            yneu += "+";
            yneu += varname_ay;
            yneu += ENDE_EINTRAG;
            zeile.replace(yalt, yneu);
        }
        text.zeile_ersaetzen(i, zeile);
    }

    if(zeinumbeg >= 2)
    {
        text.zeile_einfuegen(zeinumbeg-1, variable_ax);
        text.zeile_einfuegen(zeinumbeg-1, variable_ay);
    }else
    {
        text.zeile_vorwegsetzen(variable_ay);
        text.zeile_vorwegsetzen(variable_ax);
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::spiegeln_verti(uint zeinumbeg, uint zeinumend)
{
    for(uint i=zeinumbeg; i<=zeinumend ; i++)
    {
        QString zeile = text.zeile(i);
        QString zeilekt = klartext.zeile(i);

        if(zeile.contains(KREISTASCHE_DIALOG)       || \
           zeile.contains(RECHTECKTASCHE_DIALOG)    || \
           zeile.contains(FRAESERAUFRUF_DIALOG)     || \
           zeile.contains(FRAESERGERADE_DIALOG)     || \
           zeile.contains(FRAESERBOGEN_DIALOG)      || \
           zeile.contains(BOHREN_DIALOG)             )
        {
            QString xalt;
            xalt = POSITION_X;
            xalt += text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
            xalt += ENDE_EINTRAG;
            double mass = text_mitte(zeilekt, POSITION_X, ENDE_EINTRAG).toDouble();
            mass = werkstuecklaenge - mass;
            QString xneu;
            xneu = POSITION_X;
            xneu += double_to_qstring(mass);
            xneu += ENDE_EINTRAG;
            zeile.replace(xalt, xneu);

            if(zeile.contains(FRAESERBOGEN_DIALOG))
            {
                QString bogenrichtung = text_mitte(zeile, BOGENRICHTUNG, ENDE_EINTRAG);
                if(bogenrichtung == BOGENRICHTUNG_IM_UZS)
                {
                    QString richtung_alt;
                    richtung_alt  = BOGENRICHTUNG;
                    richtung_alt += BOGENRICHTUNG_IM_UZS;
                    richtung_alt += ENDE_EINTRAG;
                    QString richtung_neu;
                    richtung_neu  = BOGENRICHTUNG;
                    richtung_neu += BOGENRICHTUNG_IM_GUZS;
                    richtung_neu += ENDE_EINTRAG;
                    zeile.replace(richtung_alt, richtung_neu);
                }else
                {
                    QString richtung_alt;
                    richtung_alt  = BOGENRICHTUNG;
                    richtung_alt += BOGENRICHTUNG_IM_GUZS;
                    richtung_alt += ENDE_EINTRAG;
                    QString richtung_neu;
                    richtung_neu  = BOGENRICHTUNG;
                    richtung_neu += BOGENRICHTUNG_IM_UZS;
                    richtung_neu += ENDE_EINTRAG;
                    zeile.replace(richtung_alt, richtung_neu);
                }
            }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
            {
                double drewinkel = text_mitte(zeilekt, WINKEL, ENDE_EINTRAG).toDouble();
                drewinkel = 180 - drewinkel;
                QString alt;
                alt  = WINKEL;
                alt += text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                QString neu;
                neu  = WINKEL;
                neu += double_to_qstring(drewinkel);
                neu += ENDE_EINTRAG;
                zeile.replace(alt, neu);
            }
        }
        text.zeile_ersaetzen(i, zeile);
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
}

void programmtext::spiegeln_hori(uint zeinumbeg, uint zeinumend)
{
    for(uint i=zeinumbeg; i<=zeinumend ; i++)
    {
        QString zeile = text.zeile(i);
        QString zeilekt = klartext.zeile(i);

        if(zeile.contains(KREISTASCHE_DIALOG)       || \
           zeile.contains(RECHTECKTASCHE_DIALOG)    || \
           zeile.contains(FRAESERAUFRUF_DIALOG)     || \
           zeile.contains(FRAESERGERADE_DIALOG)     || \
           zeile.contains(FRAESERBOGEN_DIALOG)      || \
           zeile.contains(BOHREN_DIALOG)             )
        {
            QString yalt;
            yalt = POSITION_Y;
            yalt += text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
            yalt += ENDE_EINTRAG;
            double mass = text_mitte(zeilekt, POSITION_Y, ENDE_EINTRAG).toDouble();
            mass = werkstueckbreite - mass;
            QString yneu;
            yneu = POSITION_Y;
            yneu += double_to_qstring(mass);
            yneu += ENDE_EINTRAG;
            zeile.replace(yalt, yneu);

            if(zeile.contains(FRAESERBOGEN_DIALOG))
            {
                QString bogenrichtung = text_mitte(zeile, BOGENRICHTUNG, ENDE_EINTRAG);
                if(bogenrichtung == BOGENRICHTUNG_IM_UZS)
                {
                    QString richtung_alt;
                    richtung_alt  = BOGENRICHTUNG;
                    richtung_alt += BOGENRICHTUNG_IM_UZS;
                    richtung_alt += ENDE_EINTRAG;
                    QString richtung_neu;
                    richtung_neu  = BOGENRICHTUNG;
                    richtung_neu += BOGENRICHTUNG_IM_GUZS;
                    richtung_neu += ENDE_EINTRAG;
                    zeile.replace(richtung_alt, richtung_neu);
                }else
                {
                    QString richtung_alt;
                    richtung_alt  = BOGENRICHTUNG;
                    richtung_alt += BOGENRICHTUNG_IM_GUZS;
                    richtung_alt += ENDE_EINTRAG;
                    QString richtung_neu;
                    richtung_neu  = BOGENRICHTUNG;
                    richtung_neu += BOGENRICHTUNG_IM_UZS;
                    richtung_neu += ENDE_EINTRAG;
                    zeile.replace(richtung_alt, richtung_neu);
                }
            }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
            {
                double drewinkel = text_mitte(zeilekt, WINKEL, ENDE_EINTRAG).toDouble();
                drewinkel = 180 - drewinkel;
                QString alt;
                alt  = WINKEL;
                alt += text_mitte(zeile, WINKEL, ENDE_EINTRAG);
                alt += ENDE_EINTRAG;
                QString neu;
                neu  = WINKEL;
                neu += double_to_qstring(drewinkel);
                neu += ENDE_EINTRAG;
                zeile.replace(alt, neu);
            }
        }
        text.zeile_ersaetzen(i, zeile);
    }
    aktualisiere_klartext_var_geo();
    aktualisiere_fkon();
    aktualisiere_anzeigetext();
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
    if(!aktualisieren_eingeschaltet)
    {
        return;
    }

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

                zeile_klartext += VERSATZ_X;
                tmp = text_mitte(zeile, VERSATZ_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                set_versatz_x(tmp.toFloat());
                if(!variablen.contains(VERSATZ_X))
                {
                    variablen += VERSATZ_X;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, VERSATZ_X, ENDE_EINTRAG);
                    variablen.replace(VERSATZ_X+alterWert, VERSATZ_X+tmp);
                }

                zeile_klartext += VERSATZ_Y;
                tmp = text_mitte(zeile, VERSATZ_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                set_versatz_y(tmp.toFloat());
                if(!variablen.contains(VERSATZ_Y))
                {
                    variablen += VERSATZ_Y;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, VERSATZ_Y, ENDE_EINTRAG);
                    variablen.replace(VERSATZ_Y+alterWert, VERSATZ_Y+tmp);
                }

                zeile_klartext += VERSATZ_Z;
                tmp = text_mitte(zeile, VERSATZ_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                set_versatz_z(tmp.toFloat());
                if(!variablen.contains(VERSATZ_Z))
                {
                    variablen += VERSATZ_Z;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, VERSATZ_Z, ENDE_EINTRAG);
                    variablen.replace(VERSATZ_Z+alterWert, VERSATZ_Z+tmp);
                }

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }else if(zeile.contains(PROGRAMMENDE_DIALOG))
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
        }else if(zeile.contains(VARIABLE_DIALOG))
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
                wert = variablen_durch_werte_ersetzten(variablen,wert);
                wert = ausdruck_auswerten(wert);
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
        }else if(zeile.contains(KOMMENTAR_DIALOG))
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
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
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
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_z));
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
        }else if(zeile.contains(KREISTASCHE_DIALOG))
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
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
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_z));
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
        }else if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            QString tmp;
            QString tmp_var;
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
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_z));
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp_var);
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

                tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ZUSTELLUNG;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }else if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            QString tmp;
            QString tmp_var;
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
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_z));
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp_var);
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
        }else if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            QString tmp;
            QString tmp_var;
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
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
                zeile_klartext += POSITION_X;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_X))
                {
                    variablen += POSITION_X;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_X, ENDE_EINTRAG);
                    variablen.replace(POSITION_X+alterWert, POSITION_X+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Y, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
                zeile_klartext += POSITION_Y;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Y))
                {
                    variablen += POSITION_Y;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Y, ENDE_EINTRAG);
                    variablen.replace(POSITION_Y+alterWert, POSITION_Y+tmp_var);
                }

                tmp = text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp_var = ausdruck_auswerten(tmp);
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_z));
                zeile_klartext += POSITION_Z;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(POSITION_Z))
                {
                    variablen += POSITION_Z;
                    variablen += tmp_var;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, POSITION_Z, ENDE_EINTRAG);
                    variablen.replace(POSITION_Z+alterWert, POSITION_Z+tmp_var);
                }

                tmp = text_mitte(zeile, RADIUS, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp + "+0,0001");
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
        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
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
        }else if(zeile.contains(STRECKE))
        {
            strecke s(zeile);
            punkt3d sp = s.startp();
            punkt3d ep = s.endp();
            punkt3d p = sp;
            p.set_x(ausdruck_auswerten("(" + p.x_QString() + ")" + "+" + float_to_qstring(versatz_x)));
            p.set_y(ausdruck_auswerten("(" + p.y_QString() + ")" + "+" + float_to_qstring(versatz_y)));
            p.set_z(ausdruck_auswerten("(" + p.z_QString() + ")" + "+" + float_to_qstring(versatz_z)));
            s.set_start(p);
            p = ep;
            p.set_x(ausdruck_auswerten("(" + p.x_QString() + ")" + "+" + float_to_qstring(versatz_x)));
            p.set_y(ausdruck_auswerten("(" + p.y_QString() + ")" + "+" + float_to_qstring(versatz_y)));
            p.set_z(ausdruck_auswerten("(" + p.z_QString() + ")" + "+" + float_to_qstring(versatz_z)));
            s.set_ende(p);

            klartext.zeilen_anhaengen(s.get_text());
            var.zeile_anhaengen(variablen);
        }else if(zeile.contains(KREIS))
        {
            kreis k(zeile);
            punkt3d p = k.mitte3d();
            p.set_x(ausdruck_auswerten("(" + p.x_QString() + ")" + "+" + float_to_qstring(versatz_x)));
            p.set_y(ausdruck_auswerten("(" + p.y_QString() + ")" + "+" + float_to_qstring(versatz_y)));
            p.set_z(ausdruck_auswerten("(" + p.z_QString() + ")" + "+" + float_to_qstring(versatz_z)));
            k.set_mittelpunkt(p);

            klartext.zeilen_anhaengen(k.get_text());
            var.zeile_anhaengen(variablen);
        }else if(zeile.contains(BOGEN))
        {
            bogen b(zeile);
            punkt3d sp = b.start();
            punkt3d ep = b.ende();
            punkt3d p = sp;
            p.set_x(ausdruck_auswerten("(" + p.x_QString() + ")" + "+" + float_to_qstring(versatz_x)));
            p.set_y(ausdruck_auswerten("(" + p.y_QString() + ")" + "+" + float_to_qstring(versatz_y)));
            p.set_z(ausdruck_auswerten("(" + p.z_QString() + ")" + "+" + float_to_qstring(versatz_z)));
            b.set_startpunkt(p);
            p = ep;
            p.set_x(ausdruck_auswerten("(" + p.x_QString() + ")" + "+" + float_to_qstring(versatz_x)));
            p.set_y(ausdruck_auswerten("(" + p.y_QString() + ")" + "+" + float_to_qstring(versatz_y)));
            p.set_z(ausdruck_auswerten("(" + p.z_QString() + ")" + "+" + float_to_qstring(versatz_z)));
            b.set_endpunkt(p);

            klartext.zeilen_anhaengen(b.get_text());
            var.zeile_anhaengen(variablen);
        }else if(zeile.contains(BOHREN_DIALOG))
        {
            QString tmp;
            tmp = text_mitte(zeile, AUSFUEHRBEDINGUNG, ENDE_EINTRAG);
            tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
            tmp = ausdruck_auswerten(tmp);
            if(tmp.toFloat() == true)
            {
                QString zeile_klartext;
                zeile_klartext += BOHREN_DIALOG;
                tmp = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
                zeile_klartext += WKZ_NAME;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG);
                zeile_klartext += WKZ_DURCHMESSER;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

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

                tmp = text_mitte(zeile, POSITION_X, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_x));
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
                tmp = ausdruck_auswerten("(" + tmp + ")" + "+" + float_to_qstring(versatz_y));
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

                tmp = text_mitte(zeile, BOHRTIEFE, ENDE_EINTRAG);
                tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                tmp = ausdruck_auswerten(tmp);
                zeile_klartext += BOHRTIEFE;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;
                if(!variablen.contains(BOHRTIEFE))
                {
                    variablen += BOHRTIEFE;
                    variablen += tmp;
                    variablen += ENDE_EINTRAG;
                }else
                {
                    QString alterWert = text_mitte(variablen, BOHRTIEFE, ENDE_EINTRAG);
                    variablen.replace(BOHRTIEFE+alterWert, BOHRTIEFE+tmp);
                }






                tmp = text_mitte(zeile, ANBOHRTI, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ANBOHRTI;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, RESTBOHRTI, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += RESTBOHRTI;
                zeile_klartext += tmp;
                zeile_klartext += ENDE_EINTRAG;

                tmp = text_mitte(zeile, ZUSTELLUNG, ENDE_EINTRAG);
                if(tmp == "AUTO")
                {
                    //AUTO so weitergeben
                }else
                {
                    tmp = variablen_durch_werte_ersetzten(variablen, tmp);//Variablen durch Werte ersetzen
                    tmp = ausdruck_auswerten(tmp);
                }
                zeile_klartext += ZUSTELLUNG;
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

                klartext.zeilen_anhaengen(zeile_klartext);
                var.zeile_anhaengen(variablen);
            }else
            {//Wenn AFB == 0;
                klartext.zeilen_anhaengen(" ");//leere Zeile
                var.zeile_anhaengen(variablen);
            }
        }else
        {
            klartext.zeilen_anhaengen("");
            var.zeilen_anhaengen("");
        }


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
                rec.set_einfuegepunkt(versatz_x,versatz_y,0);
                rec.set_laenge(text_mitte(zeile, LAENGE, ENDE_EINTRAG));
                rec.set_breite(text_mitte(zeile, BREITE, ENDE_EINTRAG));
                rec.set_farbe_fuellung(FARBE_GRAU);
                geo.add_rechteck(rec);

                geo.zeilenvorschub();
            }else if(zeile.contains(PROGRAMMENDE_DIALOG))
            {
                geo.zeilenvorschub();
            }else if(text.zeile(i).contains(VARIABLE_DIALOG))//es gibt keine Variablen im Klartext
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
                            startpunkt.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                            startpu.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                                p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                                p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                                p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                                p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                             strecke s3 = s;//s3 prüft, ob die Geraden in einer Linie zueinander liegen
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
                                 if(seite_b<0)
                                 {
                                     seite_b = seite_b*-1;
                                 }
                                 //---------------------------------------------------

                                 strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                                 strecke_bezugspunkt sb2 = strecke_bezugspunkt_ende;
                                 s.set_laenge_2d(s.laenge2dim()-seite_b, sb);
                                 s2.set_laenge_2d(s2.laenge2dim()-seite_b, sb2);
                                 bogen b;
                                 b.set_startpunkt(s.endp());
                                 b.set_endpunkt(s2.startp());

                                 //------------------------------------------------------------------------
//--------->
                                 b.set_radius(rad_akt, endpunkt);
                                 if(b.hat_fehler())
                                 {
                                     QMessageBox mb;
                                     mb.setText("Bogen hat Fehler");
                                     mb.exec();
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
//----->
                             b.set_radius(rad_akt, endpunkt);
                             if(b.hat_fehler())
                             {
                                 QMessageBox mb;
                                 mb.setText("Bogen hat Fehler");
                                 mb.exec();
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
                        endpunkt.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                        endpu.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                            p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                            p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
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
                            p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(punkt_davor);
                            b.set_endpunkt(p3);
                            b.set_radius(fdm*2, true);
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
                            p3.set_z(versatz_z + werkstueckdicke + sicherheitsabstand);
                            bogen b;
                            b.set_startpunkt(punkt_davor);
                            b.set_endpunkt(p3);
                            b.set_radius(fdm*2, false);
                            geo.add_bogen(b);
                        }
                    }
                }
                geo.zeilenvorschub();
            }else if(zeile.contains(STRECKE))
            {
                strecke s(zeile);
                geo.add_strecke(s);

                geo.zeilenvorschub();
            }else if(zeile.contains(KREIS))
            {
                kreis k(zeile);
                geo.add_kreis(k);

                geo.zeilenvorschub();
            }else if(zeile.contains(BOGEN))
            {
                bogen b(zeile);
                geo.add_bogen(b);

                geo.zeilenvorschub();
            }else if(zeile.contains(BOHREN_DIALOG))
            {
                zylinder z;
                punkt3d p3;
                p3.set_x(text_mitte(zeile, POSITION_X, ENDE_EINTRAG));
                p3.set_y(text_mitte(zeile, POSITION_Y, ENDE_EINTRAG));
                p3.set_z(werkstueckdicke);
                z.set_mittelpunkt(p3);
                z.set_hoehe(text_mitte(zeile, BOHRTIEFE, ENDE_EINTRAG));
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

                strecke s;
                p3.set_y(z.mitte3d().y() - z.radius() - 2);
                s.set_start(p3);
                p3.set_y(z.mitte3d().y() + z.radius() + 2);
                s.set_ende(p3);
                geo.add_strecke(s);

                s.drenen_um_mittelpunkt_2d(90,true);
                geo.add_strecke(s);

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
    aktualisiere_fraeserdarst();
}

void programmtext::aktualisiere_anzeigetext()
{
    if(!aktualisieren_eingeschaltet)
    {
        return;
    }

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
            tmp += " = ";
            tmp += text_mitte(zeile, WERT, ENDE_EINTRAG);
            tmp += "";
        }else if(zeile.contains(KOMMENTAR_DIALOG))
        {
            tmp += text_mitte(zeile, KOMMENTAR, ENDE_EINTRAG);
        }else if(zeile.contains(RECHTECKTASCHE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [";
            tmp += text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            tmp += "]";
        }else if(zeile.contains(KREISTASCHE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [";
            tmp += text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            tmp += "]";
        }else if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [";
            tmp += text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            tmp += "]";
            tmp += " [Z: ";
            tmp += text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
            tmp += "]";
        }else if(zeile.contains(FRAESERGERADE_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [Z: ";
            tmp += text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
            tmp += "]";
        }else if(zeile.contains(FRAESERBOGEN_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [Z: ";
            tmp += text_mitte(zeile, POSITION_Z, ENDE_EINTRAG);
            tmp += "]";
        }else if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
        }else if(zeile.contains(STRECKE))
        {
            tmp += "CAD / Strecke";
        }else if(zeile.contains(KREIS))
        {
            tmp += "CAD / Kreis";
        }else if(zeile.contains(BOGEN))
        {
            tmp += "CAD / Bogen";
        }else if(zeile.contains(BOHREN_DIALOG))
        {
            tmp += text_mitte(zeile, BEZEICHNUNG, ENDE_EINTRAG);
            tmp += " [";
            tmp += text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            tmp += "]";
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
    if(!aktualisieren_eingeschaltet)
    {
        return;
    }
    if(!aktualisieren_fkon_eingeschaltet)
    {
        return;
    }

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
        }else if(text.zeile(i).contains(VARIABLE_DIALOG))//es gibt keine Variablen im Klartext
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
        }else if(zeile.contains(BOHREN_DIALOG))
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
                    double versatz = wkz_dm/2 - kantendicke;

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
                    double versatz = wkz_dm/2 - kantendicke;

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
        }else
        {
            fkon.zeilenvorschub();
        }
    }

    //----------------------------------------------------------------------------
    //Übergänge verbinden nach parallelverschiebung:

    tabelle_tz3 tab_fkon;
    tab_fkon.set_trennzeichen_zeilen('\n');
    tab_fkon.set_trennzeichen_spalten(TRZ_EL_);//Bogen, Strecke...
    tab_fkon.set_text(fkon.get_text());
    uint anz_faufruf = 0;
    uint anz_fabfahr = 0;

    for(uint i=1; i<=klartext.zeilenanzahl() ;i++)
    {
        QString zeile = klartext.zeile(i);

        if(zeile.contains(FRAESERABFAHREN_DIALOG))
        {
            anz_fabfahr = 0;
            anz_faufruf = 0;
        }
        //Prüfen, ob Anfahrty = kein gesetzt ist!!
        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            QString anftyp = text_mitte(zeile, ANFAHRTYP, ENDE_EINTRAG);
            if(anftyp == ANABFAHRTYP_KEIN)
            {
                anz_faufruf++;
                while(text.zeile(i+1).at(0)=='/'  &&  \
                      text.zeile(i+1).at(1)=='/'  &&  \
                      i+1 < text.zeilenanzahl())
                {
                    i++;
                }
                if(i+1 < text.zeilenanzahl())
                {
                    i++;
                }
                continue;
            }
        }

        //die aktuelle Zeile mit der Zeile davor verbinden:
        if(anz_faufruf > anz_fabfahr)
        {
            for(uint ii=1 ; ii<tab_fkon.get_spaltenzahl(i) ; ii++)//Spaltenzahl ist aus einem mir noch nicht bekannten Grund um 1 zu groß!!! desshalb < und nicht <=
            {
                QString spalte_jetzt = tab_fkon.get_spalte(i,ii);
                QString spalte_davor = tab_fkon.vorherigespalte(i,ii);

                trimmen(&spalte_davor, &spalte_jetzt);

                tab_fkon.vorherigespalte_ersaetzen(i,ii,spalte_davor);
                tab_fkon.spalte_ersatzen(i,ii,spalte_jetzt);
            }
        }
        //----------------------------------------
        if(zeile.contains(FRAESERAUFRUF_DIALOG))
        {
            anz_faufruf++;
        }
    }


    //Daten in fkon zurückspeichern
    fkon.set_text(tab_fkon.get_text());

}

bool programmtext::cagleich(punkt3d p1, punkt3d p2, double tolleranz = 0.1)
{
    if(  (  (p1.x() == p2.x()) || ((p1.x() - tolleranz <= p2.x()) && (p1.x() + tolleranz >= p2.x()))  )  && \
         (  (p1.y() == p2.y()) || ((p1.y() - tolleranz <= p2.y()) && (p1.y() + tolleranz >= p2.y()))  )  && \
         (  (p1.z() == p2.z()) || ((p1.z() - tolleranz <= p2.z()) && (p1.z() + tolleranz >= p2.z()))  )     )
    {
        return true;
    }else
    {
        return false;
    }
}

void programmtext::aktualisiere_fraeserdarst()
{
    fraeserdarst.clear();
    QString farbe = FARBE_BLAU;
    for(uint i=1; i<=text.zeilenanzahl() ;i++)
    {
        QString aktzei = klartext.zeile(i);
        if(aktzei.contains(FRAESERAUFRUF_DIALOG))
        {
            punkt3d p;
            p.set_x(text_mitte(aktzei, POSITION_X, ENDE_EINTRAG));
            p.set_y(text_mitte(aktzei, POSITION_Y, ENDE_EINTRAG));
            p.set_z(text_mitte(aktzei, POSITION_Z, ENDE_EINTRAG));
            double wkzdm = text_mitte(aktzei, WKZ_DURCHMESSER, ENDE_EINTRAG).toDouble();
            if(wkzdm < 2)
            {
                wkzdm =2;
            }
            QString bankor = text_mitte(aktzei, BAHNRORREKTUR, ENDE_EINTRAG);
            if(bankor == BAHNRORREKTUR_keine)
            {
                kreis k;
                k.set_farbe(farbe);
                k.set_mittelpunkt(p);
                k.set_radius(wkzdm/2);
                fraeserdarst.add_kreis(k);
            }else if(bankor == BAHNRORREKTUR_links)
            {
                if(i+1 <=text.zeilenanzahl())
                {
                    QString folgzei = klartext.zeile(i+1);
                    if(folgzei.contains(FRAESERGERADE_DIALOG))
                    {
                        punkt3d p2;
                        p2.set_x(text_mitte(folgzei, POSITION_X, ENDE_EINTRAG));
                        p2.set_y(text_mitte(folgzei, POSITION_Y, ENDE_EINTRAG));
                        p2.set_z(text_mitte(folgzei, POSITION_Z, ENDE_EINTRAG));
                        strecke s;
                        s.set_start(p);
                        s.set_ende(p2);
                        strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                        s.set_laenge_2d(wkzdm/2, sb);
                        s.drenen_um_startpunkt_2d(90, false);
                        kreis k;
                        k.set_farbe(farbe);
                        k.set_mittelpunkt(s.endp());
                        k.set_radius(wkzdm/2);
                        fraeserdarst.add_kreis(k);
                    }else if(folgzei.contains(FRAESERBOGEN_DIALOG))
                    {
                        punkt3d p2;
                        p2.set_x(text_mitte(folgzei, POSITION_X, ENDE_EINTRAG));
                        p2.set_y(text_mitte(folgzei, POSITION_Y, ENDE_EINTRAG));
                        p2.set_z(text_mitte(folgzei, POSITION_Z, ENDE_EINTRAG));
                        bogen b;
                        b.set_startpunkt(p);
                        b.set_endpunkt(p2);
                        QString bograd = text_mitte(folgzei, RADIUS, ENDE_EINTRAG);
                        QString richtung = text_mitte(folgzei, BOGENRICHTUNG, ENDE_EINTRAG);
                        if(richtung == BOGENRICHTUNG_IM_UZS)
                        {
                            b.set_radius(bograd, true);
                        }else
                        {
                            b.set_radius(bograd, false);
                        }
                        strecke s;
                        s.set_start(p);
                        punkt3d mipu;
                        mipu.set_x(b.mitte().x());
                        mipu.set_y(b.mitte().y());
                        s.set_ende(mipu);
                        strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                        s.set_laenge_2d(wkzdm/2, sb);
                        sb = strecke_bezugspunkt_ende;
                        s.set_laenge_2d(wkzdm, sb);
                        kreis k;
                        k.set_farbe(farbe);
                        if(richtung == BOGENRICHTUNG_IM_UZS)
                        {
                            k.set_mittelpunkt(s.startp());
                        }else
                        {
                            k.set_mittelpunkt(s.endp());
                        }
                        k.set_radius(wkzdm/2);
                        fraeserdarst.add_kreis(k);
                    }
                }
            }else //if(bankor == BAHNRORREKTUR_rechts)
            {
                if(i+1 <=text.zeilenanzahl())
                {
                    QString folgzei = klartext.zeile(i+1);
                    if(folgzei.contains(FRAESERGERADE_DIALOG))
                    {
                        punkt3d p2;
                        p2.set_x(text_mitte(folgzei, POSITION_X, ENDE_EINTRAG));
                        p2.set_y(text_mitte(folgzei, POSITION_Y, ENDE_EINTRAG));
                        p2.set_z(text_mitte(folgzei, POSITION_Z, ENDE_EINTRAG));
                        strecke s;
                        s.set_start(p);
                        s.set_ende(p2);
                        strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                        s.set_laenge_2d(wkzdm/2, sb);
                        s.drenen_um_startpunkt_2d(90, true);
                        kreis k;
                        k.set_farbe(farbe);
                        k.set_mittelpunkt(s.endp());
                        k.set_radius(wkzdm/2);
                        fraeserdarst.add_kreis(k);
                    }else if(folgzei.contains(FRAESERBOGEN_DIALOG))
                    {
                        punkt3d p2;
                        p2.set_x(text_mitte(folgzei, POSITION_X, ENDE_EINTRAG));
                        p2.set_y(text_mitte(folgzei, POSITION_Y, ENDE_EINTRAG));
                        p2.set_z(text_mitte(folgzei, POSITION_Z, ENDE_EINTRAG));
                        bogen b;
                        b.set_startpunkt(p);
                        b.set_endpunkt(p2);
                        QString bograd = text_mitte(folgzei, RADIUS, ENDE_EINTRAG);
                        QString richtung = text_mitte(folgzei, BOGENRICHTUNG, ENDE_EINTRAG);
                        if(richtung == BOGENRICHTUNG_IM_UZS)
                        {
                            b.set_radius(bograd, true);
                        }else
                        {
                            b.set_radius(bograd, false);
                        }
                        strecke s;
                        s.set_start(p);
                        punkt3d mipu;
                        mipu.set_x(b.mitte().x());
                        mipu.set_y(b.mitte().y());
                        s.set_ende(mipu);
                        strecke_bezugspunkt sb = strecke_bezugspunkt_start;
                        s.set_laenge_2d(wkzdm/2, sb);
                        sb = strecke_bezugspunkt_ende;
                        s.set_laenge_2d(wkzdm, sb);
                        kreis k;
                        k.set_farbe(farbe);
                        if(richtung == BOGENRICHTUNG_IM_UZS)
                        {
                            k.set_mittelpunkt(s.endp());
                        }else
                        {
                            k.set_mittelpunkt(s.startp());
                        }
                        k.set_radius(wkzdm/2);
                        fraeserdarst.add_kreis(k);
                    }
                }
            }
        }
        fraeserdarst.zeilenvorschub();
    }
}

bool programmtext::get_hat_ungesicherte_inhalte()
{
    if(text.get_text().isEmpty())//Hat gar keine Inhalte
    {
        return false;
    }
    if(text_kopie.get_text() == text.get_text())//Inhalt wurde seit dem Speichern noch nicht verändert
    {
        return false;
    }else
    {
        return true;
    }
}

void programmtext::wurde_gespeichert()
{
    text_kopie = text;
}













