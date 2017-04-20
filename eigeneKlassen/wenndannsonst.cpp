#include "wenndannsonst.h"

WennDannSonst::WennDannSonst()
{
    formelText_setzen("");
}

WennDannSonst::WennDannSonst( QString WennDannSonst_formel)
{
    formelText_setzen(WennDannSonst_formel);
}

void WennDannSonst::formelText_setzen(QString text)
{
    fehler_nullen();
    text = leerzeichen_entfernen(text);
    ergebnis_setzen(  ergebnis_berechnen(text)  );
}

QString WennDannSonst::vergleich_oparator(const QString text)
{
    QString returnString = "";
    int indexBegin = 0;
    int indexEnde = 0;
    bool operatorGefunden = false;

    for(int i=0 ; i<text.count()-1 ; i++)
    {
        if(  text.at(i)=='>'  ||  text.at(i)=='<'  )
        {
            indexBegin = i;
            indexEnde = i;
            operatorGefunden = true;
            if(  text.at(i+1)=='='  )
            {
                indexEnde = i+1;
                break;
            }else
            {
                break;
            }
        }
    }
    if(operatorGefunden == false)
    {
        for(int i=0 ; i<text.count()-1 ; i++)
        {
            if(  (text.at(i)=='=' && text.at(i+1)=='=')  ||  (text.at(i)=='!' && text.at(i+1)=='=')  )
            {
                indexBegin = i;
                indexEnde = i+1;
                operatorGefunden = true;
                break;
            }
        }
    }
    if(  indexEnde+1<text.count()  &&  !ist_ziffer(text.at(indexEnde+1))  )
    {
        fehler_melden("Fehler! ungueltiger Vergleichsoperator");
        return "";
    }
    if(indexBegin == indexEnde)
    {
        returnString = text.at(indexBegin);
    }else
    {
        returnString = text.at(indexBegin);
        returnString += text.at(indexEnde);
    }
    if(operatorGefunden == true)
    {
        return returnString;
    }else
    {
        fehler_melden("Fehler! Keinen gueltigen Vergleichoperator gefunden!");
    }
    return "";
}

QString WennDannSonst::vergleich_links(const QString text)
{
       QString returnString = "";
       for(int i=0 ; i<text.count() ; i++)
       {
           if( text.at(i)=='<'  ||  text.at(i)=='>'  ||  text.at(i)=='='  ||  text.at(i)=='!'  )
           {
               break;
           }else
           {
               returnString += text.at(i);
           }
       }
       if(returnString == "")
       {
           fehler_melden("Fehler! links neben Vergleichsoperator nichts gefunden!");
       }
       return returnString;
}

QString WennDannSonst::vergleich_rechts(const QString text)
{
    QString returnString = "";
    int indexBegin = 0;

    for(int i=0 ; i<text.count()-1 ; i++)
    {
        if(  (text.at(i)=='<'  ||  text.at(i)=='>'  ||  text.at(i)=='='  ||  text.at(i)=='!')  &&  (text.at(i+1)!='=')  )
        {
            indexBegin = i+1;
            break;
        }
    }
    if(indexBegin == 0)
    {
        fehler_melden("Fehler! rechts neben Vergleichsoperator nichts gefunden!");
    }
    for(int i=indexBegin ; i<text.count() ; i++)
    {
        returnString += text.at(i);
    }
    return returnString;
}

bool WennDannSonst::vergleich_ist_wahr(const QString text)
{
    if(!ist_vergleich(text))
    {
        if(ist_zahl(text))
        {
            if(text == "0")
            {
                return false;
            }else
            {
                return true;
            }
        }else
        {
            Formel f(text);
            if(!f.ist_fehlerhaft())
            {
                QString erg = f.bekomme_Ergebnis_als_String();
                if(erg == "0")
                {
                    return false;
                }else
                {
                    return true;
                }
            }

            fehler_melden("Fehler in Funktion vergleich_ist_wahr!");
            return false;
        }
    }
    QString links = "";
    QString op = "";
    QString rechts = "";
    float linksZahl = 0;
    float rechtsZahl = 0;

    links = vergleich_links(text);
    op = vergleich_oparator(text);
    rechts = vergleich_rechts(text);

    if(ist_fehlerhaft())
    {//Wenn die Funktionen oben Fehler gemeldet haben
        return false;
    }

    Formel ausdruck_links(links);
    if(!ausdruck_links.ist_fehlerhaft())
    {
        linksZahl = ausdruck_links.bekomme_Ergebnis_als_float();
    }else
    {
        fehler_melden(ausdruck_links.bekomme_fehler_text());
        //QMessageBox mb;
        //mb.setText(ausdruck_links.bekomme_fehler_text());
        //mb.exec();
        return false;
    }

    Formel ausdruck_rechts(rechts);
    if(!ausdruck_rechts.ist_fehlerhaft())
    {
        rechtsZahl = ausdruck_rechts.bekomme_Ergebnis_als_float();
    }else
    {
        fehler_melden(ausdruck_rechts.bekomme_fehler_text());
        //QMessageBox mb;
        //mb.setText(ausdruck_rechts.bekomme_fehler_text());
        //mb.exec();
        return false;
    }

    if(op == "<")
    {
        if(linksZahl < rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }
    if(op == ">")
    {
        if(linksZahl > rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }
    if(op == "<=")
    {
        if(linksZahl <= rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }
    if(op == ">=")
    {
        if(linksZahl >= rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }
    if(op == "==")
    {
        if(linksZahl == rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }
    if(op == "!=")
    {
        if(linksZahl != rechtsZahl)
        {
            return true;
        }else
        {
            return false;
        }
    }

    return false;
}

bool WennDannSonst::ist_vergleich(const QString text)
{//Funktion prüft ob ein Ausdruck ein einfacher Vergleich ist
    fehler_nullen();
    int anz_operatoren = 0;
    int anz_verbindungszeichen = 0;
    if( !ist_ziffer( text.at(0))  &&  text.at(0)!='+'  && text.at(0)!='-'  )
    {//wenn der vergleich nicht mit einer Ziffer, nicht mit + und nicht mit -  beginnt
        return false;
    }
    for(int i = 0 ; i < text.count() ; i++)
    {
        if(  text.at(i) == '<'  ||  text.at(i) == '>'  || text.at(i) == '='  ||  text.at(i) == '!'  )
        {
            if(  text.at(i-1)!= '<'  &&  text.at(i-1)!= '>'  &&  text.at(i-1)!= '='  &&  text.at(i-1)!= '!')
            {
                anz_operatoren++;
            }
        }
        if(  text.at(i)=='&'  ||  text.at(i)=='|'  )
        {
            anz_verbindungszeichen++;
        }
    }

    QString op;
    op.setNum(anz_operatoren);
    QString ve;
    ve.setNum(anz_verbindungszeichen);
    QMessageBox mb;
    mb.setText("operatoren: " + op + " verb: " + ve);
    mb.exec();

    if(anz_verbindungszeichen == anz_operatoren-1)
    {
        if(anz_verbindungszeichen == 0)
        {//Wenn es keine Vergleichskette ist
            return true;
        }
    }else if(  anz_operatoren!= 0  ||  anz_verbindungszeichen!=0  )
    {
        fehler_melden("ungueltige Anzahl von Vergleichsoperatoren oder ungueltige Anzahl an Vergleichs-Verbindungsoperatoren");
    }
    return false;
}

QString WennDannSonst::text_links(const QString text, const QString trenntext)
{
    if(!text.contains(trenntext))
    {
        return "";
    }
    int beginn_Trenntext = text.indexOf(trenntext);
    QString return_string = "";
    for(int i=0 ; i<beginn_Trenntext; i++)
    {
        return_string += text.at(i);
    }
    return return_string;
}

QString WennDannSonst::text_rechts(const QString text, const QString trenntext)
{
    if(!text.contains(trenntext))
    {
        return "";
    }
    int ende_Trenntext = text.indexOf(trenntext)+trenntext.length();
    QString return_string = "";
    for(int i=ende_Trenntext ; i<text.count(); i++)
    {
        return_string += text.at(i);
    }
    return return_string;
}

bool WennDannSonst::vergleichskette_ist_wahr_nur_ODER(const QString text)
{
    bool istWahr = false;
    QString tmp = text;
    while(tmp.contains("|"))
    {
        QString links;
        links = text_links(tmp, "|");

        if(  vergleich_ist_wahr(links)  )
        {
            istWahr = true;
            break;
        }
        tmp = text_rechts(tmp, "|");
    }
    if(!istWahr)
    {
        istWahr = vergleich_ist_wahr(tmp);
    }
    return istWahr;
}

bool WennDannSonst::vergleichskette_ist_wahr(const QString text)
{
    bool istWahr = false;

    if(ist_zahl(text))
    {
        if(text == "0")
        {
            return false;
        }else
        {
            return true;
        }
    }

    Formel f(text);
    if(!f.ist_fehlerhaft())
    {
        QString erg = f.bekomme_Ergebnis_als_String();
        if(erg == "0")
        {
            return false;
        }else
        {
            return true;
        }
    }

    if(ist_vergleich(text))
    {
        return vergleich_ist_wahr(text);
    }

    if(  text.contains("|")  &&  !text.contains("&")) //Wenn text nur Oder-Verbindungen und keine Und-Verbindungen enthällt
    {
        istWahr = vergleichskette_ist_wahr_nur_ODER(text);

    }else if (  text.contains("&")  &&  !text.contains("|")  ) //Wenn text Und-Verbindungen enthällt und keine ODER-Verbindungen
    {
        QString tmp = text;
        while(tmp.contains("&"))
        {
            QString links;
            links = text_links(tmp, "&");

            if(vergleich_ist_wahr(links))
            {
                istWahr = true;
            }else
            {
                return false;
            }
            tmp = text_rechts(tmp, "&");

            if(!tmp.contains("&"))
            {// = in der letzten Runde
                istWahr = vergleich_ist_wahr(tmp);
            }
        }
    }else if (  text.contains("&")  &&  text.contains("|")  ) //Wenn text Und-Verbindungen enthällt und ODER-Verbindungen
    {
        QString tmp = text;
        while(tmp.contains("&"))
        {
            QString links;
            links = text_links(tmp, "&");

            if(vergleichskette_ist_wahr_nur_ODER(links))
            {
                istWahr = true;
            }else
            {
                return false;
            }
            tmp = text_rechts(tmp, "&");

            if(!tmp.contains("&"))
            {// = in der letzten Runde
                istWahr = vergleichskette_ist_wahr_nur_ODER(tmp);
            }
        }
    }

    return istWahr;
}

QString WennDannSonst::weDaSo(const QString text)
{
    QString returnString;

    QString bedingung, dann, sonst;
    bedingung = text_links(text, "?");
    QString tmp = text_rechts(text, "?");

    if(tmp.contains("?"))
    {
        fehler_melden("Fehler in Funktion weDaSo!\nZu viele \"?\" ggf muessen teile der Formel in Klammern gruppiert werden");
        return "0";
    }

    dann = text_links(tmp, ":");
    sonst = text_rechts(tmp, ":");

    if(vergleichskette_ist_wahr(bedingung))
    {
        Formel f(dann);
        returnString = f.bekomme_Ergebnis_als_String();
    }else
    {
        Formel f(sonst);
        returnString = f.bekomme_Ergebnis_als_String();
    }

    return returnString;
}

float WennDannSonst::ergebnis_berechnen(QString formelText)
{
    fehler_nullen();
    formelText = leerzeichen_entfernen(formelText);

    while(formelText.contains("("))
    {
        QString links, mitte, rechts;
        links = Klammern_aufloesen_text_links(formelText);
        mitte = Klammern_aufloesen_text_mitte(formelText);
        rechts = Klammern_aufloesen_text_rechts(formelText);

        if(mitte.contains("?"))
        {
            mitte = weDaSo(mitte);
        }else
        {
            Formel f(mitte);
            if(!f.ist_fehlerhaft())
            {
                mitte = f.bekomme_Ergebnis_als_String();
            }else
            {
                if(ist_vergleich(mitte))
                {
                    weDaSo(mitte);
                }else
                {
                    fehler_melden("Hier Fehler");
                }
            }
        }
        formelText = links + mitte + rechts;
    }
    if(formelText.contains("?"))
    {
        formelText = weDaSo(formelText);
    }else
    {
        Formel f(formelText);
        formelText = f.bekomme_Ergebnis_als_String();
    }
    Formel f(formelText);
    if(f.ist_fehlerhaft())
    {
        fehler_melden(f.bekomme_fehler_text());
    }
    return f.bekomme_Ergebnis_als_float();
}
