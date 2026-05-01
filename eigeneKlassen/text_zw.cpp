#include "text_zw.h"

text_zw::text_zw()
{
    clear();
}
text_zw::text_zw(QString text, char trennzeichen)
{
    set_text(text, trennzeichen);
}

//---------------------------------------------set_xy:
void text_zw::set_text(QString text, char trennzeichen)
{
    clear();
    Trennzeichen = trennzeichen;
    if(text.isEmpty())
    {
        return;
    }
    Daten = to_vector(text, trennzeichen);
}
void text_zw::set_trenz(char trennzeichen)
{
    Trennzeichen = trennzeichen;
}

//---------------------------------------------get_xy:
QString text_zw::at(uint zeilennummer)
{
    QString ret;
    if(zeilennummer < Daten.size())
    {
        ret = Daten.at(zeilennummer);
    }else
    {
        ret = "Fehler in Funktion text_zw::at(...)! Zeilennummer zu hoch.";
    }
    return ret;
}
QString text_zw::at(uint zeilennummer_beginn, uint zeilenmenge)
{
    QString ret;
    uint zeilennummer_ende = zeilennummer_beginn + zeilenmenge - 1 ;
    if(zeilennummer_ende < Daten.size())
    {
        for(uint i=zeilennummer_beginn; i<=zeilennummer_ende ;i++)
        {
            ret += Daten.at(i);
            if(i < zeilennummer_ende)
            {
                ret += Trennzeichen;
            }
        }
    }else
    {
        ret = "Fehler in Funktion text_zw::at(...)! Zeilennummer + Menge > Wertebereich";
    }
    return ret;
}
QString text_zw::text()
{
    QString ret;
    for(uint i=0; i<Daten.size() ;i++)
    {
        ret += Daten.at(i);
        if(i+1 < Daten.size())
        {
            ret += Trennzeichen;
        }
    }
    return ret;
}
char text_zw::trennz()
{
    return Trennzeichen;
}
uint text_zw::count()
{
    return Daten.size();
}
//---------------------------------------------Manipulationen:
void text_zw::clear()
{
    Daten.clear();
    Trennzeichen = '\n';
}
//---------------------------------------------
void text_zw::add_vo(QString text)
{
    if(Daten.empty())
    {
        Daten = to_vector(text, Trennzeichen);
        return;
    }
    std::vector<QString> v;
    v = to_vector(text, Trennzeichen);
    Daten.insert(Daten.begin(), v.begin(), v.end());
}
void text_zw::add_hi(QString text)
{
    if(Daten.empty())
    {
        Daten = to_vector(text, Trennzeichen);
        return;
    }
    std::vector<QString> v;
    v = to_vector(text, Trennzeichen);
    Daten.insert(Daten.end(), v.begin(), v.end());
}
int text_zw::add_mi(uint index_vor, QString text)
{
    if(Daten.empty())
    {
        //Kann nicht eingefügt werden weil Daten leer ist
        //text wird zu Daten, statt darin eingefügt zu werden:
        Daten = to_vector(text, Trennzeichen);
        return 1;
    }
    if(index_vor >= Daten.size())//index ist zu groß
    {
        //Kann nicht eingefügt werden weil Daten zu klein ist ist
        //text hinten an Daten anhängen:
        std::vector<QString> v;
        v = to_vector(text, Trennzeichen);
        Daten.insert(Daten.end(), v.begin(), v.end());
        return 2;
    }
    std::vector<QString> v;
    v = to_vector(text, Trennzeichen);
    Daten.insert(Daten.begin()+1+index_vor, v.begin(), v.end());
    return 0;
}
int text_zw::edit(uint index, QString neuer_text)
{
    if(Daten.empty())
    {
        //es gibt keine Zeilen zum ersetzen
        return 1;
    }
    if(index >= Daten.size())
    {
        //index ist zu groß
        return 2;
    }
    int ret = 0;
    //  0: keine Warnungen
    //101: text enthällt Trennzeichen / diese Trennzeichen wurden entfernt
    if(neuer_text.contains(Trennzeichen))
    {
        ret = 101;
        neuer_text.replace(Trennzeichen, "");
    }
    Daten.at(index) = neuer_text;
    return ret;
}
int text_zw::entf(uint index, uint menge)
{
    if(Daten.empty())
    {
        //es gibt keine Zeilen zum entfernen
        return 1;
    }
    if(menge == 0)
    {
        //es soll nichts entfernt werden
        return 2;
    }
    if(index + 1 > Daten.size())
    {
        //index ist zu groß
        return 3;
    }
    int ret = 0;
    //  0: keine Warnungen
    //101: Bereich überschritten / index+menge ist zu groß
    if(index + menge > Daten.size())
    {
        //index+menge ist zu groß
        ret = 101;
        menge = Daten.size()-index;
    }
    Daten.erase(Daten.begin()+index, Daten.begin()+index+menge);
    return ret;
}

//--------------------------------------------------------------------------------------
//private:
std::vector<QString> text_zw::to_vector(QString text, char trennzeichen)
{
    std::vector<QString> v;
    if(text.contains(trennzeichen))
    {
        QString zeile;
        int letztes_trennzeichen = 0;
        for(int i=0; i<text.length() ;i++)
        {
            if(text.at(i) == trennzeichen)
            {
                v.push_back(zeile);
                zeile.clear();
                letztes_trennzeichen = i;
            }else
            {
                zeile += text.at(i);
            }
        }
        int anz_rest = text.length() - letztes_trennzeichen - 1;
        if(anz_rest > 0)
        {
            v.push_back(text.right(anz_rest));
        }
    }else
    {
        v.push_back(text);
    }
    return v;
}

//-------------------Funktionen nicht innerhalb der Klasse:
bool operator ==(text_zw t1, text_zw t2)
{
    if(t1.text() == t2.text())
    {
        return true;
    }else
    {
        return false;
    }
}
bool operator !=(text_zw t1, text_zw t2)
{
    if(t1.text() != t2.text())
    {
        return true;
    }else
    {
        return false;
    }
}
