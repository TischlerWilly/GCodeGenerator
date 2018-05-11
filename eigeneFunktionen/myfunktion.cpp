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

bool ist_ziffer(const QChar zeichen)
{
    if(zeichen == '0' || zeichen == '1' || zeichen == '2' || zeichen == '2' || zeichen == '3' || zeichen == '4' || zeichen == '5' || zeichen == '6' || zeichen == '7' || zeichen == '8' || zeichen == '9')
    {
        return true;
    }else
    {
        return false;
    }
}

bool ist_zahl(const QString text)
{
    if(ist_ziffer(text.at(0))  || text.at(0)=='+' || text.at(0)=='-')//wenn erstes Zeichen eine Zahl oder ein Vorzeichen ist
    {
        int laenge = text.count();
        for(int i=1 ; i<laenge ; i++)
        {
            if(!ist_ziffer(text.at(i)) && text.at(i)!='.' && text.at(i)!=',' )
            {
                return false;
            }
        }
    }else
    {
        return false;
    }
    //Wenn diese Stelle erreicht wird dann enthällt der Text nur Zahlen:
    return true;
}

QString genauigkeit_reduzieren(QString zahl, uint nachkommastellen)
{
    if(zahl.contains("."))
    {
        QString li = text_links(zahl, ".");
        QString re = text_rechts(zahl, ".");
        zahl = li;
        zahl += ".";
        for(uint i=0; i<nachkommastellen && i<re.length();i++)
        {
            zahl += re.at(i);
        }
    }else if(zahl.contains(","))
    {
        QString li = text_links(zahl, ",");
        QString re = text_rechts(zahl, ",");
        zahl = li;
        zahl += ",";
        for(uint i=0; i<nachkommastellen && i<re.length();i++)
        {
            zahl += re.at(i);
        }
    }
    return zahl;
}

QString genauigkeit_reduzieren(double zahl, uint nachkommastellen)
{
    int zahlalsint = zahl*(10*nachkommastellen);
    zahl = zahlalsint/(10*nachkommastellen);
    return double_to_qstring(zahl);
}

bool cagleich(punkt3d p1, punkt3d p2, double tolleranz = 0.1)
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

bool cagleich(punkt2d p1, punkt2d p2, double tolleranz = 0.1)
{
    if(  (  (p1.x() == p2.x()) || ((p1.x() - tolleranz <= p2.x()) && (p1.x() + tolleranz >= p2.x()))  )  && \
         (  (p1.y() == p2.y()) || ((p1.y() - tolleranz <= p2.y()) && (p1.y() + tolleranz >= p2.y()))  )      )
    {
        return true;
    }else
    {
        return false;
    }
}

bool cagleich(double p1, double p2, double tolleranz = 0.1)
{
    if(    (p1 == p2) || ((p1 - tolleranz <= p2) && (p1 + tolleranz >= p2))  )
    {
        return true;
    }else
    {
        return false;
    }
}
