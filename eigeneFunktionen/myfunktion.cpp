#include "myfunktion.h"


QString ausdruck_auswerten(QString ausdruck)
{
    QString returnstring ="";
    WennDannSonst f(ausdruck);
    returnstring = f.bekomme_Ergebnis_als_String();
    return returnstring;
}


QString variablen_durch_werte_ersetzten(QString variablen, QString formeltext)
{
    QString variablennahme = "";
    QString returnstring = "";
    for(int i=0 ; i<formeltext.count() ;i++)
    {
        if(formeltext.at(i)=='A'||formeltext.at(i)=='B'||formeltext.at(i)=='C'||formeltext.at(i)=='D'||formeltext.at(i)=='E'||formeltext.at(i)=='F'||formeltext.at(i)=='G'||formeltext.at(i)=='H'||formeltext.at(i)=='I'||formeltext.at(i)=='J'||formeltext.at(i)=='K'||formeltext.at(i)=='L'||formeltext.at(i)=='M'||formeltext.at(i)=='N'||formeltext.at(i)=='O'||formeltext.at(i)=='P'||formeltext.at(i)=='Q'||formeltext.at(i)=='R'||formeltext.at(i)=='S'||formeltext.at(i)=='T'||formeltext.at(i)=='U'||formeltext.at(i)=='V'||formeltext.at(i)=='W'||formeltext.at(i)=='X'||formeltext.at(i)=='Y'||formeltext.at(i)=='Z')
        {
            variablennahme += formeltext.at(i);

            if(i+1 == formeltext.count())
            {//Wenn letztes Zeichen erreicht ist
                QString wert;
                if(variablen.contains("["+variablennahme+"]"))
                {
                    wert = text_mitte(variablen, "["+variablennahme+"]", ENDE_EINTRAG);
                }else
                {
                    wert = "0";
                }
                returnstring += wert;
            }
        }else
        {
            if(!variablennahme.isEmpty())
            {
                QString wert;
                if(variablen.contains("["+variablennahme+"]"))
                {
                    wert = text_mitte(variablen, "["+variablennahme+"]", ENDE_EINTRAG);
                }else
                {
                    wert = "0";
                }
                returnstring += wert;
            }
            variablennahme = "";
            returnstring += formeltext.at(i);
        }
    }
    return returnstring;
}

