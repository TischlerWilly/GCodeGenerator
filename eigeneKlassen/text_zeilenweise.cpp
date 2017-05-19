#include "text_zeilenweise.h"

text_zeilenweise::text_zeilenweise()
{
    trenner = '\n';
    clear();
}

//---------------------------------------------------------------------------
//Funktionen zum lesen des Textes:
QString text_zeilenweise::zeile(uint zeilennummer)
{
    if(zeilennummer > anzahl_der_zeilen)
    {
        return "Zeilennummer ist groesser als Anzahl der Zeilen!!!";
    }
    if(zeilennummer == 0)
    {
        return "Zeilennummer ist Null!!!";
    }
    QString returntext;
    uint aktuelle_zeile = 1;
    for(int i=0 ; i<text.count() ; i++)
    {
        if(text.at(i) == trenner)
        {
            aktuelle_zeile++;
        }
        if(aktuelle_zeile == zeilennummer)
        {
            returntext += text.at(i);
        }
    }
    return textzeile_ohne_Zeilenvorschuebe(returntext);
}

QString text_zeilenweise::zeilen(uint zeilennummer_beginn, uint zeilenmenge)
{
    if(zeilennummer_beginn+zeilenmenge > anzahl_der_zeilen)
    {
        return "Zeilennummer ist groesser als Anzahl der Zeilen!!!";
    }
    if(zeilennummer_beginn == 0)
    {
        return "Zeilennummer ist Null!!!";
    }
    QString returntext;
    for(uint i=zeilennummer_beginn ; i<zeilennummer_beginn+zeilenmenge ; i++)
    {
        if(i!=zeilennummer_beginn)
        {
            returntext += trenner;
        }
        returntext += zeile(i);
    }
    return returntext;
}

//---------------------------------------------------------------------------
//Funktionen zum erweitern des Textes:
void text_zeilenweise::set_text(QString neuer_text)
{
    clear();
    text = neuer_text;
    zeilen_zaehlen();
}

void text_zeilenweise::zeile_vorwegsetzen(QString zeilentext)
{
    zeilentext = textzeile_ohne_Zeilenvorschuebe(zeilentext);
    if(anzahl_der_zeilen == 0)
    {
        set_text(zeilentext);
    }else
    {
        set_text(zeilentext + trenner + text);
    }
}

void text_zeilenweise::zeile_anhaengen(QString zeilentext)
{
    zeilentext = textzeile_ohne_Zeilenvorschuebe(zeilentext);
    if(anzahl_der_zeilen == 0)
    {
        if(zeilentext.isEmpty())
        {
            set_text("\n");
        }else
        {
            set_text(zeilentext);
        }
    }else
    {
        set_text(text + trenner + zeilentext);
    }
}

void text_zeilenweise::zeilen_anhaengen(QString zeilentext)
{
    if(anzahl_der_zeilen == 0)
    {
        if(zeilentext.isEmpty())
        {
            set_text("\n");
        }else
        {
            set_text(zeilentext);
        }
    }else
    {
        set_text(text + trenner + zeilentext);
    }
}

int text_zeilenweise::zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext)
{
    zeilentext = textzeile_ohne_Zeilenvorschuebe(zeilentext);
    if(zeilennummer_vor_neuer_zeile > anzahl_der_zeilen)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer_vor_neuer_zeile == 0)
    {
        set_text(zeilentext + trenner + text);
    }else
    {
        uint aktuelle_zeile = 1;
        QString text_davor, text_danach;
        for(int i=0 ; i<text.count() ; i++)
        {
            if(aktuelle_zeile <= zeilennummer_vor_neuer_zeile)
            {
                text_davor += text.at(i);
            }else{
                text_danach += text.at(i);
            }
            if(text.at(i) == trenner)
            {
                aktuelle_zeile++;
            }            
        }
        set_text(text_davor + zeilentext + trenner + text_danach);
    }
    return 0;
}

int text_zeilenweise::zeilen_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext)
{
    if(zeilennummer_vor_neuer_zeile > anzahl_der_zeilen)
    {
        return 1; //Meldet Fehler in der Funktion
    }

    if(zeilennummer_vor_neuer_zeile == 0)
    {
        set_text(zeilentext + trenner + text);
    }else
    {
        uint aktuelle_zeile = 1;
        QString text_davor, text_danach;

        for(int i=0 ; i<text.count() ; i++)
        {
            if(aktuelle_zeile <= zeilennummer_vor_neuer_zeile)
            {
                text_davor += text.at(i);
            }else{
                text_danach += text.at(i);
            }
            if(text.at(i) == trenner)
            {
                aktuelle_zeile++;
            }
        }
        set_text(text_davor + zeilentext + trenner + text_danach);
    }
    return 0; //Keine Fehler in der Funktion
}

void text_zeilenweise::set_trennzeichen(char neues_Trennzeichen)
{
    trenner = neues_Trennzeichen;
    QString tmp = text;
    set_text(tmp);//neuberechnung anstoßen
}

//---------------------------------------------------------------------------
//Funktionen zum manipulieren/ändern des Textes:
int text_zeilenweise::zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext)
{
    neuer_zeilentext = textzeile_ohne_Zeilenvorschuebe(neuer_zeilentext);
    if(zeilennummer > anzahl_der_zeilen)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    if(zeilennummer == 0)
    {
        return 1; //Meldet Fehler in der Funktion
    }else if(zeilennummer == anzahl_der_zeilen)
    {                           //Wenn wir in der letzten Zeile sind:
        uint aktuelle_zeile = 1;
        QString text_davor;
        for(int i=0 ; i<text.count() ; i++)
        {
            if(aktuelle_zeile < zeilennummer)
            {
                text_davor += text.at(i);
            }
            if(text.at(i) == trenner)
            {
                aktuelle_zeile++;
            }
        }
        set_text(text_davor + neuer_zeilentext);
    }else
    {
        uint aktuelle_zeile = 1;
        QString text_davor, text_danach;
        for(int i=0 ; i<text.count() ; i++)
        {
            if(aktuelle_zeile < zeilennummer)
            {
                text_davor += text.at(i);
            }else if(aktuelle_zeile > zeilennummer)
            {
                text_danach += text.at(i);
            }
            if(text.at(i) == trenner)
            {
                aktuelle_zeile++;
            }
        }
        set_text(text_davor + neuer_zeilentext + trenner + text_danach);
    }
    return 0;
}

//---------------------------------------------------------------------------
//Funktionen zum veringern des Textes:
void text_zeilenweise::clear()
{
    text = "";
    anzahl_der_zeilen = 0;
}

int text_zeilenweise::zeile_loeschen(uint zeilennummer)
{
    if(zeilennummer > anzahl_der_zeilen)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    uint aktuelle_zeile = 1;
    QString tmp;
    for(int i=0 ; i<text.count() ; i++)
    {
        if(aktuelle_zeile != zeilennummer)
        {
            tmp += text.at(i);
        }
        if(text.at(i) == trenner)
        {
            aktuelle_zeile++;
        }

    }
    if(tmp.at(tmp.count()-1) == trenner)
    {//Wenn das letzte Zeichen ein Zeilenvorschub ist:
        //letztes Zeichen entfernen:
        QString tmp_neu;
        for(int i =0 ; i<tmp.count()-1 ;i++)
        {
            tmp_neu += tmp.at(i);
        }
        tmp = tmp_neu;
    }
    set_text(tmp);

    return 0; //Keine Fehler in der Funktion
}

int text_zeilenweise::zeilen_loeschen(uint zeilennummer_beginn, uint zeilenmenge)
{
    if(zeilennummer_beginn+zeilenmenge-1 > anzahl_der_zeilen)
    {
        return 1; //Meldet Fehler in der Funktion
    }
    uint aktuelle_zeile = 1;
    QString tmp;
    for(int i=0 ; i<text.count() ; i++)
    {
        if(text.at(i) == trenner)
        {
            if(  (zeilennummer_beginn == 1)  &&  (aktuelle_zeile <= zeilenmenge)  )
            {
                aktuelle_zeile++;
                continue;
            }else
            {
                aktuelle_zeile++;
            }
        }
        if(  (aktuelle_zeile < zeilennummer_beginn)  ||  (aktuelle_zeile >=zeilennummer_beginn + zeilenmenge)  )
        {
            tmp += text.at(i);
        }
    }
    set_text(tmp);

    return 0; //Keine Fehler in der Funktion
}


//---------------------------------------------------------------------------
//andere Funktionen:
uint text_zeilenweise::finde_Zeile(QString zeilentext)
{
    if(text.contains(zeilentext))
    {
        for(uint i = 1; i<= zeilenanzahl() ; i++)
        {
            if(zeile(i)== zeilentext)
            {
                return i;
            }
        }
    }
    return 0;
}

//---------------------------------------------------------------------------
//interne Funktinen:
void text_zeilenweise::zeilen_zaehlen()
{
    if(text.isEmpty())
    {
        anzahl_der_zeilen = 0;
    }else
    {
        anzahl_der_zeilen = 1;
        for(int i=0 ; i<text.count() ; i++)
        {
            if(text.at(i) == trenner)
            {
                anzahl_der_zeilen++;
            }
        }
    }
}

QString text_zeilenweise::textzeile_ohne_Zeilenvorschuebe(QString zeilentext)
{
    QString tmp;
    for(int i=0 ; i<zeilentext.count() ;i++)
    {
        if(zeilentext.at(i) != trenner)
        {
            tmp += zeilentext.at(i);
        }
    }
    return tmp;
}






