#include "formel.h"

Formel::Formel()
{
    fehler_nullen();
    formelText_setzen("");
    ergebnis_setzen(0);
}

Formel::Formel(QString formel)
{
    fehler_nullen();
    formelText_setzen(formel);
    ergebnis_setzen(  ergebnis_berechnen(formelText_bekommen())  );
}

void Formel::formelText_setzen(QString text)
{
    FormelText = text;
}

QString Formel::formelText_bekommen()
{
    return FormelText;
}

float Formel::ergebnis_berechnen(QString formelText)
{
    fehler_nullen();

    formelText = leerzeichen_entfernen(formelText);
    //auf Fehler prüfen:
    if(!ist_ohne_ungueltige_Zeichen(formelText))
    {
        fehler_melden("Formel entheallt ungueltige Zeichen!");
    }else if(!ist_ohne_ungueltige_Klammernhaelften(formelText))
    {
        fehler_melden("Formel entheallt unterschiedlich viele Klammer-Haelften \"(\" und \")\" !");
    }else if(!ist_ohne_ungueltige_Kommas(formelText))
    {
        fehler_melden("Formel entheallt ungueltige Kommasetzung!");
    }else if(  (!formelText.contains("(") || !formelText.contains(")")  )  &&  !ist_ohne_ungueltige_Rechenzeichen(formelText))
    {
        fehler_melden("Formel entheallt doppelte Rechenzeichen!");
    }else
    {
        return zahl_aus_string(Klammern_aufloesen(formelText));
    }
    //Wird nie erreicht:
    return 0;
}

void Formel::ergebnis_setzen(float wert)
{
    ergebnis = wert;
}

void Formel::fehler_nullen()
{
    istFehlerhaft = false;
    fehlerText = "kein Fehler gefunden";
}

void Formel::fehler_melden(QString neuerFehlerText)
{
    istFehlerhaft = true;
    fehlerText = neuerFehlerText;
    ergebnis = 0;
}

bool Formel::ist_ziffer(const QChar zeichen)
{
    if(zeichen == '0' || zeichen == '1' || zeichen == '2' || zeichen == '2' || zeichen == '3' || zeichen == '4' || zeichen == '5' || zeichen == '6' || zeichen == '7' || zeichen == '8' || zeichen == '9')
    {
        return true;
    }else
    {
        return false;
    }
}

bool Formel::ist_zahl(const QString text)
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
    }
    //Wenn diese Stelle erreicht wird dann enthällt der Text nur Zahlen:
    return true;
}

bool Formel::ist_Addition(const QString text)
{
    if(text.contains("+"))
    {
        int index = text.indexOf("+");
        QString links;
        QString rechts;
        for(int i=0 ; i<index ; i++)
        {
            links += text.at(i);
        }
        for(int i = index+1 ; i<text.count() ; i++)
        {
            rechts += text.at(i);
        }
        if(links.isEmpty())
        {
            return false;
        }
        if(rechts.isEmpty())
        {
            return false;
        }
        if(ist_zahl(links) && ist_zahl(rechts))
        {
            return true;
        }
    }
    //Wenn diese Stelle erreicht wird
    return false;
}

bool Formel::ist_Subtraktion(const QString text)
{
    if(text.contains("-"))
    {
        int index = text.indexOf("-");
        QString links;
        QString rechts;
        for(int i=0 ; i<index ; i++)
        {
            links += text.at(i);
        }
        for(int i = index+1 ; i<text.count() ; i++)
        {
            rechts += text.at(i);
        }
        if(links.isEmpty())
        {
            return false;
        }
        if(rechts.isEmpty())
        {
            return false;
        }
        if(ist_zahl(links) && ist_zahl(rechts))
        {
            return true;
        }
    }
    //Wenn diese Stelle erreicht wird
    return false;
}

bool Formel::ist_Multiplikation(const QString text)
{
    if(text.contains("*"))
    {
        int index = text.indexOf("*");
        QString links;
        QString rechts;
        for(int i=0 ; i<index ; i++)
        {
            links += text.at(i);
        }
        for(int i = index+1 ; i<text.count() ; i++)
        {
            rechts += text.at(i);
        }
        if(links.isEmpty())
        {
            return false;
        }
        if(rechts.isEmpty())
        {
            return false;
        }
        if(ist_zahl(links) && ist_zahl(rechts))
        {
            return true;
        }
    }
    //Wenn diese Stelle erreicht wird
    return false;
}

bool Formel::ist_Division(const QString text)
{
    if(text.contains("/"))
    {
        int index = text.indexOf("/");
        QString links;
        QString rechts;
        for(int i=0 ; i<index ; i++)
        {
            links += text.at(i);
        }
        for(int i = index+1 ; i<text.count() ; i++)
        {
            rechts += text.at(i);
        }
        if(links.isEmpty())
        {
            return false;
        }
        if(rechts.isEmpty())
        {
            return false;
        }
        if(ist_zahl(links) && ist_zahl(rechts))
        {
            return true;
        }
    }
    //Wenn diese Stelle erreicht wird
    return false;
}

bool Formel::ist_Division_durch_Null(const QString text)
{
    if(ist_Division(text))
    {
        int index = 0;
        if(text.contains("/"))
        {
            index = text.indexOf("/");
        }
        QString rechts;
        for(int i = index+1 ; i<text.count() ; i++)
        {
            rechts += text.at(i);
        }
        if((zahl_aus_string(rechts) == 0))
        {
            return true;
        }
    }
    //Wenn diese Stelle erreicht wird
    return false;
}

bool Formel::ist_einfache_Berechnung(const QString text)
{
    int anzahl_an_nichtzahlen = 0;
    for(int i = 0 ; i < text.count() ; i++)
    {
        if(  text.at(i) == '+' || text.at(i) == '-' || text.at(i) == '*' || text.at(i) == '/'  )
        {
            anzahl_an_nichtzahlen += 1;
        }
    }
    if(text.at(0) == '+' || text.at(0) == '-')//Vorzeichen vor der ersten Zahl ist kein Rechenoperator und muss abgezogen werden
    {
        anzahl_an_nichtzahlen -= 1;
    }
    for(int i = 0 ; i<text.count()-1 ; i++)////Vorzeichen vor der zweiten Zahl ist kein Rechenoperator und muss abgezogen werden
    {
        if(  (text.at(i) == '+' || text.at(i) == '-' || text.at(i) == '*' || text.at(i) == '/')  &&  (text.at(i+1) == '+' || text.at(i+1) == '-')  )//Wenn z.B. "12+-3"
        {
            anzahl_an_nichtzahlen -= 1;
        }
    }
    if(anzahl_an_nichtzahlen == 1)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Formel::ist_ohne_ungueltige_Zeichen(const QChar zeichen)
{
    if(zeichen == '0' || zeichen == '1' || zeichen == '2' || zeichen == '2' || zeichen == '3' || zeichen == '4' || zeichen == '5' || zeichen == '6' || zeichen == '7' || zeichen == '8' || zeichen == '9' || zeichen == '.' || zeichen == ',' || zeichen == '+' || zeichen == '-' || zeichen == '*' || zeichen == '/' || zeichen == '(' || zeichen == ')' ||  zeichen == '?' || zeichen == ':')
    {
        return true;
    }else
    {
        return false;
    }
}

bool Formel::ist_ohne_ungueltige_Zeichen(const QString text)
{
    for(int i=0 ; i<text.count() ; i++)
    {
        if(!ist_ohne_ungueltige_Zeichen(text.at(i)))
        {
            return false;
        }
    }
    return true;
}

bool Formel::ist_ohne_ungueltige_Klammernhaelften(const QString text)
{
    int anzahl_Klammer_links = 0;
    int anzahl_Klammer_rechts = 0;
    for(int i=0 ; i<text.count() ; i++)
    {
        if(text.at(i)=='(')
        {
            anzahl_Klammer_links += 1;
        }
        if(text.at(i)==')')
        {
            anzahl_Klammer_rechts += 1;
        }
    }
    if(anzahl_Klammer_links == anzahl_Klammer_rechts)
    {
        return true;
    }
    return false;
}

bool Formel::ist_ohne_ungueltige_Kommas(QString text)
{
    QChar ch = '.';
    while(text.contains(ch))
    {
        int indexKomma = text.indexOf(ch);
        if(  (indexKomma == 0)  || (indexKomma == text.count())  )
        {
            return false;
        }
        if(  !ist_ziffer(text.at(indexKomma-1))  ||  !ist_ziffer(text.at(indexKomma+1))  )
        {
            return false;
        }else
        {
            //Punkt aus string löschen:
            text.remove(indexKomma, 1);
        }
    }
    ch = ',';
    while(text.contains(ch))
    {
        int indexKomma = text.indexOf(ch);
        if(  (indexKomma == 0)  || (indexKomma == text.count())  )
        {
            return false;
        }
        if(  !ist_ziffer(text.at(indexKomma-1))  ||  !ist_ziffer(text.at(indexKomma+1))  )
        {
            return false;
        }else
        {
            //Komma aus string löschen:
            text.remove(indexKomma, 1);
        }
    }
    return true;
}

bool Formel::ist_ohne_ungueltige_Rechenzeichen(const QString text)
{
    //Hinweiß: In der zu prüfenden Formel dürfen keine Klammern enthalten sein!!

    if(text.at(0)=='*' || text.at(0)=='/')
    {//Wenn erstes Zeichen '*' oder '/' ist
        return false;
    }
    if(text.at(text.count()-1)=='*' ||  text.at(text.count()-1)=='/' ||  text.at(text.count()-1)=='+' ||  text.at(text.count()-1)=='-')
    {//Wenn letztes Zeichen '*' oder '/' oder '+' oder '-' ist
        return false;
    }
    for(int i=1; i<text.count() ;i++)
    {//Wenn der Vorgänger eines '*' oder eines '/' ein Rechenzeichen ist
        if(text.at(i)=='*' || text.at(i)=='/')
        {
            if(text.at(i-1)=='*' || text.at(i-1)=='/' || text.at(i-1)=='+' || text.at(i-1)=='-')
            {
                return false;
            }
        }
    }
    for(int i=2; i<text.count() ;i++)
    {//Wenn vor einem '+' oder einem '-' zwei Rechenzeichen stehen
        if(text.at(i)=='+' || text.at(i)=='-')
        {
            if(text.at(i-1)=='*' || text.at(i-1)=='/' || text.at(i-1)=='+' || text.at(i-1)=='-')
            {
                if(text.at(i-2)=='*' || text.at(i-2)=='/' || text.at(i-2)=='+' || text.at(i-2)=='-')
                {
                    return false;
                }
            }
        }
    }
    return true;
}

float Formel::zahl_aus_string(QString text)
{
    return text.toFloat();
}

float Formel::bekomme_Ergebnis_als_float()
{
    if(!ist_fehlerhaft())
    {
        return ergebnis;
    }
    return 0;
}

QString Formel::bekomme_Ergebnis_als_String()
{
    QString ergebnis_als_String;
    ergebnis_als_String.setNum(bekomme_Ergebnis_als_float());
    return ergebnis_als_String;
}

float Formel::addition(QString text)
{
    int index = text.indexOf("+");
    QString links;
    QString rechts;
    for(int i=0 ; i<index ; i++)
    {
        links += text.at(i);
    }
    for(int i = index+1 ; i<text.count() ; i++)
    {
        rechts += text.at(i);
    }
    float links_zahlenwert = zahl_aus_string(links);
    float rechts_zahlenwert = zahl_aus_string(rechts);

    return links_zahlenwert + rechts_zahlenwert;
}

float Formel::subtraktion(QString text)
{
    int index = text.indexOf("-");
    QString links;
    QString rechts;
    for(int i=0 ; i<index ; i++)
    {
        links += text.at(i);
    }
    for(int i = index+1 ; i<text.count() ; i++)
    {
        rechts += text.at(i);
    }
    float links_zahlenwert = zahl_aus_string(links);
    float rechts_zahlenwert = zahl_aus_string(rechts);

    return links_zahlenwert - rechts_zahlenwert;
}

float Formel::multiplikation(QString text)
{
    int index = text.indexOf("*");
    QString links;
    QString rechts;
    for(int i=0 ; i<index ; i++)
    {
        links += text.at(i);
    }
    for(int i = index+1 ; i<text.count() ; i++)
    {
        rechts += text.at(i);
    }
    float links_zahlenwert = zahl_aus_string(links);
    float rechts_zahlenwert = zahl_aus_string(rechts);

    return links_zahlenwert * rechts_zahlenwert;
}

float Formel::division(QString text)
{
    int index = text.indexOf("/");
    QString links;
    QString rechts;
    for(int i=0 ; i<index ; i++)
    {
        links += text.at(i);
    }
    for(int i = index+1 ; i<text.count() ; i++)
    {
        rechts += text.at(i);
    }
    float links_zahlenwert = zahl_aus_string(links);
    float rechts_zahlenwert = zahl_aus_string(rechts);

    return links_zahlenwert / rechts_zahlenwert;
}

bool Formel::ist_fehlerhaft()
{
    if(istFehlerhaft == true)
    {
        return true;
    }else
    {
        return false;
    }
}

QString Formel::bekomme_fehler_text()
{
    return fehlerText;
}

QString Formel::Verschachtelung_text_links(const QString text, const QChar rechenzeichen)
{
    QString links;
    int index = text.indexOf(rechenzeichen, 1);//Erst ab dem 2. Zeichen suchen, wenn erstes Zeichen dann ist es ein Vorzeichen
    int indexBegin = 0;
    for(int i = index-1 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  &&  i>0  ; i--)
    {
        indexBegin = i;
    }
    //Vorzeichen erkennen und ggf mitnehmen:
    if(indexBegin-1 >= 0)
    {
        if( text.at(indexBegin-1) == '+'  || text.at(indexBegin-1) == '-'  )
        {
            if(indexBegin-2 >= 0)
            {
                if( text.at(indexBegin-2) == '+'  || text.at(indexBegin-2) == '-' || text.at(indexBegin-2) == '*' || text.at(indexBegin-2) == '/'  )
                {
                    indexBegin -= 1;
                }
            }
        }
    }
    if(indexBegin != 1)
    {
        for(int i = 0 ; i<indexBegin ; i++)
        {
            links += text.at(i);
        }
    }
    //QMessageBox mb;
    //QString indexAlsString;
    //indexAlsString.setNum(index);
    //mb.setText("text: " + text + "\n" + "links= " + links + "\n zeichen: " + rechenzeichen + " index: " + indexAlsString);
    //mb.exec();
    return links;
}

QString Formel::Verschachtelung_text_mitte(const QString text, const QChar rechenzeichen)
{
    QString mitte;
    int index = text.indexOf(rechenzeichen, 1);//Erst ab dem 2. Zeichen suchen, wenn erstes Zeichen dann ist es ein Vorzeichen
    int indexBegin = 0;
    int indexEnde = text.count();
    for(int i = index-1 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' ) && i>=0  ; i--)
    {
        indexBegin = i;
    }
    //Vorzeichen erkennen und ggf mitnehmen:
    if(indexBegin-1 >= 0)
    {
        if( text.at(indexBegin-1) == '+'  || text.at(indexBegin-1) == '-'  )
        {
            if(indexBegin-2 >= 0)
            {
                if( text.at(indexBegin-2) == '+'  || text.at(indexBegin-2) == '-' || text.at(indexBegin-2) == '*' || text.at(indexBegin-2) == '/'  )
                {
                    indexBegin -= 1;
                }
            }
        }
    }
    if(  index+1<=text.count()  &&  text.at(index+1)!='+' && text.at(index+1)!='-'  )
    {
        for(int i = index+1 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  && i<=text.count() ; i++)
        {
            indexEnde = i;
        }
    }else if(  index+2<=text.count()  &&  (text.at(index+1)=='+' || text.at(index+1)=='-')  )
    {
        for(int i = index+2 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  && i<=text.count() ; i++)
        {
            indexEnde = i;
        }
    }

    if(indexEnde == text.count())
    {
        for(int i = indexBegin ; i<indexEnde ; i++)
        {
            mitte += text.at(i);
        }
    }else
    {
        for(int i = indexBegin ; i<=indexEnde ; i++)
        {
            mitte += text.at(i);
        }
    }
    //QMessageBox mb;
    //QString indexAlsString;
    //indexAlsString.setNum(index);
    //mb.setText("text: " + text + "\n" + "mitte= " + mitte + "\n zeichen: " + rechenzeichen + " index: " + indexAlsString);
    //mb.exec();
    return mitte;
}

QString Formel::Verschachtelung_text_rechts(const QString text, const QChar rechenzeichen)
{
    QString rechts;
    int index = text.indexOf(rechenzeichen);
    int indexEnde = text.count();
    //for(int i = index+1 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  &&  ( text.at(i)!='+' && text.at(i)!='-' && i<text.count() ) ; i++)
    //{
    //    indexEnde = i;
    //}
    if(  index+1<=text.count()  &&  text.at(index+1)!='+' && text.at(index+1)!='-'  )
    {
        for(int i = index+1 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  && i<=text.count() ; i++)
        {
            indexEnde = i;
        }
    }else if(  index+2<=text.count()  &&  (text.at(index+1)=='+' || text.at(index+1)=='-')  )
    {
        for(int i = index+2 ; ( ist_ziffer(text.at(i)) || text.at(i)=='.' || text.at(i)==',' )  && i<=text.count() ; i++)
        {
            indexEnde = i;
        }
    }
    if(indexEnde+1 != text.count())
    {
        for(int i = indexEnde+1 ; i < text.count() ; i++)
        {
            rechts += text.at(i);
        }
    }
    //QMessageBox mb;
    //QString indexAlsString;
    //indexAlsString.setNum(index);
    //mb.setText("text: " + text + "\n" + "rechts= " + rechts + "\n zeichen: " + rechenzeichen + " index: " + indexAlsString);
    //mb.exec();
    return rechts;
}

QString Formel::Verschachtelung_aufloesen(QString text)
{
    QString links;
    QString rechts;
    QString mitte;

    if(text.isEmpty())
    {
        return "";
    }
    if(ist_zahl(text))//Wenn keine Berechnungen notwendig sind weil die formel nur aus einer Zahl besteht
    {
        return text;//Dann gib diese Zahl wieder zurück
    }else
    {
        if(ist_einfache_Berechnung(text))  //Wenn eine unverschachtelte Berechnung genügt
        {
            return berechne(text);
        }else  //Wenn die Berechnung noch verschachtelt ist:
        {
            while(!ist_einfache_Berechnung(text))
            {
                while(text.contains('*')  ||  text.contains('/'))
                {
                    int pos_mal = 9999999;
                    int pos_durch = 9999999;
                    if(text.contains('*'))
                    {
                        pos_mal = text.indexOf('*');
                    }
                    if(text.contains('/'))
                    {
                        pos_durch = text.indexOf('/');
                    }
                    if(  (pos_mal < pos_durch)  &&  (text.contains('*'))  )
                    {
                        QChar ch = '*';
                        links = Verschachtelung_text_links(text, ch);
                        mitte = Verschachtelung_text_mitte(text, ch);
                        rechts = Verschachtelung_text_rechts(text, ch);
                        QString     tmp =   links;
                                    tmp +=  berechne(mitte);
                                    tmp += rechts;
                        text = tmp;
                        if(ist_einfache_Berechnung(text))
                        {
                            text = berechne(text);
                            return text;
                        }
                    }else if(text.contains('/'))
                    {
                        QChar ch = '/';
                        links = Verschachtelung_text_links(text, ch);
                        mitte = Verschachtelung_text_mitte(text, ch);
                        rechts = Verschachtelung_text_rechts(text, ch);
                        QString     tmp =   links;
                                    tmp +=  berechne(mitte);
                                    tmp += rechts;
                        text = tmp;
                        if(ist_einfache_Berechnung(text))
                        {
                            text = berechne(text);
                            return text;
                        }
                    }
                }
                QChar ch = '-';
                while(  text.contains(ch)  &&  (text.indexOf(ch)>0)  &&  (text.at(text.indexOf(ch)-1)!='+')  &&  (text.at(text.indexOf(ch)-1)!='-')  &&  (text.at(text.indexOf(ch)-1)!='*')  &&  (text.at(text.indexOf(ch)-1)!='/')  )
                {
                    links = Verschachtelung_text_links(text, ch);
                    mitte = Verschachtelung_text_mitte(text, ch);
                    rechts = Verschachtelung_text_rechts(text, ch);
                    QString     tmp =   links;
                                tmp +=  berechne(mitte);
                                tmp += rechts;
                    text = tmp;
                    if(ist_einfache_Berechnung(text))
                    {
                        text = berechne(text);
                        return text;
                    }
                }
                ch = '+';
                while(  text.contains(ch)  &&  (text.indexOf(ch)>0)  &&  (text.at(text.indexOf(ch)-1)!='+')  &&  (text.at(text.indexOf(ch)-1)!='-')  &&  (text.at(text.indexOf(ch)-1)!='*')  &&  (text.at(text.indexOf(ch)-1)!='/')  )
                {
                    links = Verschachtelung_text_links(text, ch);
                    mitte = Verschachtelung_text_mitte(text, ch);
                    rechts = Verschachtelung_text_rechts(text, ch);
                    QString     tmp =   links;
                                tmp +=  berechne(mitte);
                                tmp += rechts;
                    text = tmp;
                    if(ist_einfache_Berechnung(text))
                    {
                        text = berechne(text);
                        return text;
                    }
                }
            }
        }
    }
    return "12345";
}

QString Formel::berechne(QString text)
{
    QString returnText;

    if(ist_Addition(text))
    {
        returnText.setNum(addition(text));
        return returnText;
    }else if(ist_Subtraktion(text))
    {
        returnText.setNum(subtraktion(text));
        return returnText;
    }else if(ist_Multiplikation(text))
    {
        returnText.setNum(multiplikation(text));
        return returnText;
    }else if(ist_Division(text))
    {
        returnText.setNum(division(text));
        return returnText;
        if(ist_Division_durch_Null(text))
        {
            istFehlerhaft = true;
            fehlerText = "Division durch Null nicht erlaubt!";
            return "0";
        }
    }
    return "Diese Stelle wird nie erreicht"; //Damit der Compiler nicht meckert hier noch ein return
}

QString Formel::Klammern_aufloesen(QString text)
{
    if(!text.contains("("))
    {
        if(!ist_ohne_ungueltige_Rechenzeichen(text))
        {
            istFehlerhaft = true;
            fehlerText = "Formel entheallt doppelte Rechenzeichen!";
            return "0";
        }
        return Verschachtelung_aufloesen(text);
    }
    QString links;
    QString mitte;
    QString rechts;
    while(text.contains("("))
    {
        links = Klammern_aufloesen_text_links(text);
        mitte = Verschachtelung_aufloesen(Klammern_aufloesen_text_mitte(text));
        rechts = Klammern_aufloesen_text_rechts(text);

        //QMessageBox mb;
        //mb.setText(text + "\n" + links + " ## " + mitte + " ## " + rechts);
        //mb.exec();

        text = links + mitte + rechts;
    }
    text = Verschachtelung_aufloesen(text);
    return text;
}

QString Formel::Klammern_aufloesen_text_mitte(const QString text)
{
    int indexBegin = 0;
    bool indexBeginIstGesetzt = false;
    int indexEnde = 0;
    QString returnString;
    for(int i = 0 ; i<text.count() ; i++)
    {
        if(  text.at(i) == '('   &&   indexBeginIstGesetzt == false  )
        {
            indexBegin = i;
            indexBeginIstGesetzt = true;
            i++;
        }
        if(  indexBeginIstGesetzt== true  &&  ( text.at(i) == '('  ||  text.at(i) == ')' )  )
        {
            if(text.at(i)==')')
            {
                indexEnde = i;
                break;
            }else
            {
                indexBegin = i;
            }
        }
    }
    for(int i=indexBegin+1 ; i<indexEnde ;i++)
    {
        returnString += text.at(i);
    }
    return returnString;
}

QString Formel::Klammern_aufloesen_text_links(const QString text)
{
    int indexBegin = 0;
    bool indexBeginIstGesetzt = false;
    //int indexEnde = 0;
    QString returnString;
    for(int i = 0 ; i<text.count() ; i++)
    {
        if(  text.at(i) == '('   &&   indexBeginIstGesetzt == false  )
        {
            indexBegin = i;
            indexBeginIstGesetzt = true;
            i++;
        }
        if(  indexBeginIstGesetzt== true  &&  ( text.at(i) == '('  ||  text.at(i) == ')' )  )
        {
            if(text.at(i)==')')
            {
                //indexEnde = i;
                break;
            }else
            {
                indexBegin = i;
            }
        }
    }
    for(int i=0 ; i<indexBegin ;i++)
    {
        returnString += text.at(i);
    }
    return returnString;
}

QString Formel::Klammern_aufloesen_text_rechts(const QString text)
{
    //int indexBegin = 0;
    bool indexBeginIstGesetzt = false;
    int indexEnde = 0;
    QString returnString;
    for(int i = 0 ; i<text.count() ; i++)
    {
        if(  text.at(i) == '('   &&   indexBeginIstGesetzt == false  )
        {
            //indexBegin = i;
            indexBeginIstGesetzt = true;
            i++;
        }
        if(  indexBeginIstGesetzt== true  &&  ( text.at(i) == '('  ||  text.at(i) == ')' )  )
        {
            if(text.at(i)==')')
            {
                indexEnde = i;
                break;
            }else
            {
                //indexBegin = i;
            }
        }
    }
    for(int i=indexEnde+1 ; i<text.count() ;i++)
    {
        returnString += text.at(i);
    }
    return returnString;
}

QString Formel::leerzeichen_entfernen(QString text)
{
    QString tmp;
    for(int i=0 ; i<text.count() ; i++)
    {
        if(text.at(i)!=' ')
        {
            tmp += text.at(i);
        }
    }
    return tmp;
}
