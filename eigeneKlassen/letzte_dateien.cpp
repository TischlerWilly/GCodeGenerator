#include "letzte_dateien.h"

letzte_dateien::letzte_dateien()
{
    set_anz_eintreage(3);
}

letzte_dateien::letzte_dateien(uint anzahl_der_eintraege)
{
    set_anz_eintreage(anzahl_der_eintraege);
}

void letzte_dateien::set_anz_eintreage(uint neue_anz)
{
    //darf nicht verwendet werde, wenn bereits Daten eingelesen sind
    if(neue_anz > 1)
    {
        dateinamen.clear();
        anz_eintraege = neue_anz;
    }
}

void letzte_dateien::datei_merken(QString name)
{
    QString tmp = dateinamen.get_text();
    if(tmp.contains(name))
    {
        uint pos=0;
        for(uint i = 1 ; i<=dateinamen.zeilenanzahl() ; i++)
        {
            if(dateinamen.zeile(i) == name)
            {
                pos = i;
                break;
            }
        }
        dateinamen.zeilen_loeschen(pos,1);
        dateinamen.zeile_anhaengen(name);
    }else if(dateinamen.zeilenanzahl() < anz_eintraege)
    {
        dateinamen.zeile_anhaengen(name);
    }else
    {
        dateinamen.zeilen_loeschen(1,1);
        dateinamen.zeile_anhaengen(name);
    }
}

void letzte_dateien::datei_vergessen(QString name)
{
    for(uint i=1; i<=dateinamen.zeilenanzahl() ;i++)
    {
        if(dateinamen.zeile(i) == name)
        {
            dateinamen.zeile_loeschen(i);
            break;
        }
    }
}

QString letzte_dateien::get_text()
{
    QString retstr;
    //Reihenfolge der Einträge umdrehen:
    for(uint i=dateinamen.zeilenanzahl(); i>0;i--)
    {
        retstr += dateinamen.zeile(i);
        retstr += "\n";
    }
    retstr = retstr.left(retstr.length() - 1);//letzets Zeichen löschen = "\n"
    return retstr;
}
void letzte_dateien::set_text(QString liste)
{
    text_zeilenweise tz;
    tz.set_text(liste);

    if(tz.zeilenanzahl() <= anz_eintraege)
    {
        dateinamen = tz;
    }
}
