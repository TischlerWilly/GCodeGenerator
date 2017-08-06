#include "tabelle.h"

tabelle::tabelle()
{
    set_trennzeichen_zeilen('\n');
    set_trennzeichen_spalten(';');
    set_trennzeichen_eintraege('/');
}



void tabelle::set_trennzeichen_zeilen(char neues_Trennzeichen)
{
    zeile.set_trennzeichen(neues_Trennzeichen);
}

void tabelle::set_trennzeichen_spalten(char neues_Trennzeichen)
{
    spalte.set_trennzeichen(neues_Trennzeichen);
}

void tabelle::set_trennzeichen_eintraege(char neues_Trennzeichen)
{
    eintrag.set_trennzeichen(neues_Trennzeichen);
}

void tabelle::set_text(QString neuer_text)
{
    zeile.set_text(neuer_text);
}

QString tabelle::get_zeile(uint zeilennummer)
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

QString tabelle::get_spalte(uint zeilennummer, uint spaltennummer)
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
    return tmp;
}

QString tabelle::get_eintrag(uint zeilennummer, uint spaltennummer, uint eintragsnummer)
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
