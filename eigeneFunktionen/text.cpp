#include "text.h"

QString selektiereEintrag(QString text, QString beginntMit, QString endetMit)
{
    QString returnText;
    int indexBegin;
    int indexEnde;
    int countetLetters;
    int lengthOf_beginntMit = beginntMit.length();

    if(!text.contains(beginntMit))
    {
        return "Fehler in Funktion \"selektiereEintrag\" bei Parameter \"beginntMit\"!";
    } else
    {
        indexBegin = text.indexOf(beginntMit);
        indexBegin += lengthOf_beginntMit-1;
    }

    if(!text.contains(endetMit))
    {
        return "Fehler in Funktion \"selektiereEintrag\" bei Parameter \"endetMit\"!";
    } else
    {
        indexEnde = text.indexOf(endetMit,indexBegin);
    }

    countetLetters = indexEnde - indexBegin -1;
    returnText = text.mid(indexBegin+1 , countetLetters);

    return returnText;
}

QString text_links(const QString text, const QString trenntext)
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

QString text_rechts(const QString text, const QString trenntext)
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

QString text_mitte(const QString text, const QString textDavor, const QString textDanach)
{
    QString tmp = text_rechts(text, textDavor);
    tmp = text_links( tmp, textDanach);
    return tmp;
}

QString buchstaben_alle_GROSS_schreiben(QString text)
{
    return text.toUpper();
}

