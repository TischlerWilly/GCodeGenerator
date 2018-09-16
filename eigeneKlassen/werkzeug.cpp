#include "werkzeug.h"

werkzeug::werkzeug()
{
    clear();
}

void werkzeug::set_werkezuge(QString neue_werkzeuge)
{
    werkzeuge.set_text(neue_werkzeuge);
    werkzeuge.zeile_anhaengen(LISTENENDE);
    aktualisiere_anzeigetext();
}

void werkzeug::clear()
{
    werkzeuge.clear();
    anzeigetext.clear();
}

void werkzeug::aktualisiere_anzeigetext()
{
    anzeigetext.clear();
    for(uint i=1 ; i<=werkzeuge.zeilenanzahl() ; i++)
    {
        if(werkzeuge.zeile(i) == LISTENENDE)
        {
            if(i==1)
            {
                anzeigetext.set_text("...");
            }else
            {
                anzeigetext.zeile_anhaengen("...");
            }
            continue;
        }
        QString tmp_name;
        tmp_name = text_mitte(werkzeuge.zeile(i), WKZ_NAME, ENDE_EINTRAG);
        QString tmp_nummer;
        tmp_nummer = text_mitte(werkzeuge.zeile(i), WKZ_Nummer, ENDE_EINTRAG);
        if(i==1)
        {
            anzeigetext.set_text("[" + tmp_nummer + "]  " + tmp_name);
        }else
        {
            anzeigetext.zeile_anhaengen("[" + tmp_nummer + "]  " + tmp_name);
        }
    }
}

QString werkzeug::get_werkzeuge()
{
    QString daten = "";
    for(uint i=1 ; i<=werkzeuge.zeilenanzahl() ; i++)
    {
        QString tmp = werkzeuge.zeile(i);
        if(tmp == LISTENENDE)
        {
            continue;
        }
        if(i>1)
        {
            daten += "\n";
        }
        daten += tmp;
    }
    return daten;
}

QString werkzeug::get_werkzeug(QString werkzeugname)
{
    QString daten = "";
    for(uint i=1 ; i<=werkzeuge.zeilenanzahl() ; i++)
    {
        QString tmp = werkzeuge.zeile(i);
        if(tmp.contains(werkzeugname))
        {
            daten = tmp;
            break;
        }
    }
    return daten;
}

QString werkzeug::zeile(uint zeilennummer)
{
    return werkzeuge.zeile(zeilennummer);
}

QString werkzeug::get_anzeigetext()
{
    return anzeigetext.get_text();
}

QString werkzeug::get_anzeigetext(uint werkzeugindex)
{
    return anzeigetext.zeile(werkzeugindex);
}

int werkzeug::zeile_loeschen(uint zeilennummer)
{
    QString tmp = werkzeuge.zeile(zeilennummer);
    if(tmp == LISTENENDE)
    {
        return 0;//Listenende darf nicht gelöscht werden!!!
    }
    if(zeilennummer > werkzeuge.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    werkzeuge.zeile_loeschen(zeilennummer);
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

int werkzeug::zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext)
{
    if(zeilentext == LISTENENDE)
    {
        return 0;
    }
    if(zeilennummer_vor_neuer_zeile > werkzeuge.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer_vor_neuer_zeile == 0)
    {
        werkzeuge.zeile_vorwegsetzen(zeilentext);
    }else
    {
        werkzeuge.zeile_einfuegen(zeilennummer_vor_neuer_zeile, zeilentext);
    }
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

void werkzeug::zeile_anhaengen(QString zeilentext)
{
    werkzeuge.zeilen_anhaengen(zeilentext);
    aktualisiere_anzeigetext();
}

int werkzeug::zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext)
{
    QString tmp = werkzeuge.zeile(zeilennummer);
    if(tmp == LISTENENDE)
    {
        return 0;//Listenende darf nicht gelöscht werden!!!
    }
    if(zeilennummer > werkzeuge.zeilenanzahl())
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer == 0)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    werkzeuge.zeile_ersaetzen(zeilennummer, neuer_zeilentext);
    aktualisiere_anzeigetext();
    return 0; //Keine Fehler
}

text_zeilenweise werkzeug::get_werkzeuge_zeilenweise()
{
    text_zeilenweise tz;
    if(werkzeuge.zeilenanzahl()>0)
    {
        for(uint i=1 ; i<werkzeuge.zeilenanzahl() ; i++)
        {
            if(i==1)
            {
                tz.set_text(werkzeuge.zeile(i));
            }else
            {
                tz.zeilen_anhaengen(werkzeuge.zeile(i));
            }
        }
        return tz;
    }else
    {
        return tz; //ist dann leer
    }
}

text_zeilenweise werkzeug::get_anzeigetext_zeilenweise()
{
    return anzeigetext;
}

QString werkzeug::get_bohrwkzname(double durchmesser)
{
    QString name;
    for(uint i=1; i<=werkzeuge.zeilenanzahl() ;i++)
    {
        QString zeile = werkzeuge.zeile(i);
        QString kannbohren = text_mitte(zeile, WKZ_KANN_BOHREN, ENDE_EINTRAG);
        if(kannbohren == "1")
        {
            double wkzdm = text_mitte(zeile, WKZ_DURCHMESSER, ENDE_EINTRAG).toDouble();
            if(durchmesser == wkzdm)
            {
                name = text_mitte(zeile, WKZ_NAME, ENDE_EINTRAG);
            }
        }
    }
    return name;
}



