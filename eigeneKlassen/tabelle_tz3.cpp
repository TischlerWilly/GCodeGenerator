#include "tabelle_tz3.h"

tabelle_tz3::tabelle_tz3()
{
    set_trennzeichen_zeilen('\n');
    set_trennzeichen_spalten(';');
    set_trennzeichen_eintraege('/');
}



void tabelle_tz3::set_trennzeichen_zeilen(char neues_Trennzeichen)
{
    zeile.set_trennzeichen(neues_Trennzeichen);
}

void tabelle_tz3::set_trennzeichen_spalten(char neues_Trennzeichen)
{
    spalte.set_trennzeichen(neues_Trennzeichen);
}

void tabelle_tz3::set_trennzeichen_eintraege(char neues_Trennzeichen)
{
    eintrag.set_trennzeichen(neues_Trennzeichen);
}

void tabelle_tz3::set_text(QString neuer_text)
{
    zeile.set_text(neuer_text);
}

QString tabelle_tz3::get_zeile(uint zeilennummer)
{
    QString tmp = zeile.zeile(zeilennummer);
    if (tmp == "Zeilennummer ist groesser als Anzahl der Zeilen!!!")
    {
        tmp = "";
    }else if(tmp == "Zeilennummer ist Null!!!")
    {
        tmp = "";
    }
    return tmp;
}

QString tabelle_tz3::get_spalte(uint zeilennummer, uint spaltennummer)
{
    spalte.set_text(get_zeile(zeilennummer));

    QString tmp = spalte.zeile(spaltennummer);
    if (tmp == "Zeilennummer ist groesser als Anzahl der Zeilen!!!")
    {
        tmp = "";
    }else if(tmp == "Zeilennummer ist Null!!!")
    {
        tmp = "";
    }
    //return tmp + spalte.get_trennzeichen();
    return tmp;
}

QString tabelle_tz3::get_eintrag(uint zeilennummer, uint spaltennummer, uint eintragsnummer)
{
    eintrag.set_text(get_spalte(zeilennummer, spaltennummer));

    QString tmp = eintrag.zeile(eintragsnummer);
    if (tmp == "Zeilennummer ist groesser als Anzahl der Zeilen!!!")
    {
        tmp = "";
    }else if(tmp == "Zeilennummer ist Null!!!")
    {
        tmp = "";
    }
    return tmp;
}

bool tabelle_tz3::zeile_ersaetzen(uint zeilennummer, QString neuer_text)
{
    if(zeile.zeile_ersaetzen(zeilennummer, neuer_text))
    {
        return true;//Fehler ist aufgetreten
    }else
    {
        return false;//Kein Fehler ist aufgetreten
    }
}

bool tabelle_tz3::spalte_ersatzen(uint zeilennummer, uint spaltennummer, QString neuer_text)
{
    spalte.set_text(zeile.zeile(zeilennummer));

    if(spalte.zeile_ersaetzen(spaltennummer, neuer_text))
    {
        return true;//Fehler ist aufgetreten
    }else
    {
        if(zeile.zeile_ersaetzen(zeilennummer, spalte.get_text()))
        {
            return true;//Fehler ist aufgetreten
        }else
        {
            return false;//Kein Fehler ist aufgetreten
        }
    }
}

bool tabelle_tz3::eintrag_ersatzen(uint zeilennummer, uint spaltennummer, uint eintragsnummer, QString neuer_text)
{
    spalte.set_text(zeile.zeile(zeilennummer));
    eintrag.set_text(spalte.zeile(spaltennummer));

    if(eintrag.zeile_ersaetzen(eintragsnummer, neuer_text))
    {
        return true;//Fehler ist aufgetreten
    }else
    {
        if(spalte.zeile_ersaetzen(spaltennummer, eintrag.get_text()))
        {
            return true;//Fehler ist aufgetreten
        }else
        {
            if(zeile.zeile_ersaetzen(zeilennummer, spalte.get_text()))
            {
                return true;//Fehler ist aufgetreten
            }else
            {
                return false;//Kein Fehler ist aufgetreten
            }
        }
    }
}

void tabelle_tz3::zeile_anhaengen(QString neuer_text)
{
    zeile.zeile_anhaengen(neuer_text);
}

bool tabelle_tz3::spalte_anhaengen(uint zeilennummer, QString neuer_text)
{
    if(zeile.zeilenanzahl() < zeilennummer)
    {
        return true;//Fehler ist aufgetreten
    }else
    {
        spalte.set_text(zeile.zeile(zeilennummer));
        spalte.zeile_anhaengen(neuer_text);
        zeile.zeile_ersaetzen(zeilennummer, spalte.get_text());
        return false;//Kein Fehler ist aufgetreten
    }
}

bool tabelle_tz3::eintrag_anhaengen(uint zeilennummer, uint spaltennummer, QString neuer_text)
{
    if(zeile.zeilenanzahl() < zeilennummer)
    {
        return true;//Fehler ist aufgetreten
    }else
    {
        if(spalte.zeilenanzahl() < spaltennummer)
        {
            return true;//Fehler ist aufgetreten
        }else
        {
            spalte.set_text(zeile.zeile(zeilennummer));
            eintrag.set_text(spalte.zeile(spaltennummer));
            eintrag.zeile_anhaengen(neuer_text);
            spalte.zeile_ersaetzen(spaltennummer, eintrag.get_text());
            zeile.zeile_ersaetzen(zeilennummer, spalte.get_text());
            return false;//Kein Fehler ist aufgetreten
        }
    }
}

QString tabelle_tz3::folgespalte(uint zeile_aktuell, uint spalte_aktuell)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(spalte.get_trennzeichen());
    uint pos = 0;

    for(uint i=1 ; i<=zeile.zeilenanzahl() ; i++)
    {
        spalte.set_text(zeile.zeile(i));
        for(uint ii=1 ; ii<=spalte.zeilenanzahl(); ii++)
        {
            QString tmp = spalte.zeile(ii);
            //tmp.remove(spalte.get_trennzeichen());
            if(!tmp.isEmpty() &&  tmp!=" ")
            {
                tz.zeilen_anhaengen(tmp);
            }
            if(i==zeile_aktuell  &&  ii==spalte_aktuell)
            {
                pos = tz.zeilenanzahl();
            }
        }
    }

    if(pos < tz.zeilenanzahl()  &&  pos>0)
    {
        return tz.zeile(pos+1);
    }else
    {
        return "";
    }
}

QString tabelle_tz3::vorherigespalte(uint zeile_aktuell, uint spalte_aktuell)
{
    text_zeilenweise tz;
    tz.set_trennzeichen(spalte.get_trennzeichen());
    uint pos = 0;

    for(uint i=1 ; i<=zeile.zeilenanzahl() ; i++)
    {
        spalte.set_text(zeile.zeile(i));
        for(uint ii=1 ; ii<=spalte.zeilenanzahl(); ii++)
        {
            QString tmp = spalte.zeile(ii);
            //tmp.remove(spalte.get_trennzeichen());
            if(!tmp.isEmpty() &&  tmp!=" ")
            {
                tz.zeilen_anhaengen(tmp);
            }
            if(i==zeile_aktuell  &&  ii==spalte_aktuell)
            {
                pos = tz.zeilenanzahl();
            }
        }
    }

    if(pos <= tz.zeilenanzahl()  &&  pos>0)
    {
        return tz.zeile(pos-1);
    }else
    {
        return "";
    }
}

QString tabelle_tz3::get_spalten()
{
    text_zeilenweise tz;

    for(uint i=1 ; i<=zeile.zeilenanzahl() ; i++)
    {
        spalte.set_text(zeile.zeile(i));
        for(uint ii=1 ; ii<=spalte.zeilenanzahl(); ii++)
        {
            QString tmp = spalte.zeile(ii);
            //tmp.remove(spalte.get_trennzeichen());
            if(!tmp.isEmpty() &&  tmp!=" ")
            {
                tz.zeilen_anhaengen(tmp);
            }
        }
    }

    return tz.get_text();
}

uint tabelle_tz3::get_spaltenzahl(uint zeilennummer)
{
    spalte.set_text(zeile.zeile(zeilennummer));
    return spalte.zeilenanzahl();
}

bool tabelle_tz3::vorherigespalte_ersaetzen(uint zeile_aktuell, uint spalte_aktuell, QString neuer_text)
{
    //Pos der vorheriegen Spalte finden:
    //Die Funktion arbeitet ein bisschen quick&dirty, weil nur nach dem
    //ersten Vorkommen eines identischen Textes vor der aktuellen Position gesucht wird
    //und angenommen wird, dass es nur einen identischen Text gibt
    QString text_vorherige_spalte = vorherigespalte(zeile_aktuell, spalte_aktuell);
    uint zeilennummer = 0;
    uint spaltennummer = 0;

    for(uint i=1 ; i<=zeile.zeilenanzahl() ; i++)
    {
        spalte.set_text(zeile.zeile(i));
        for(uint ii=1 ; ii<=spalte.zeilenanzahl(); ii++)
        {
            QString tmp = spalte.zeile(ii);
            if(tmp == text_vorherige_spalte   &&    \
                    i <= zeile_aktuell  &&          \
                    ii <= spalte_aktuell)
            {
                zeilennummer = i;
                spaltennummer = ii;
            }
        }
    }
    //Text ersetzen:
    return spalte_ersatzen(zeilennummer, spaltennummer, neuer_text);
}
