#ifndef TEXT_ZEILENWEISE_H
#define TEXT_ZEILENWEISE_H


#include <QString>


class text_zeilenweise
{
public:
    text_zeilenweise();

    //Funktionen zum lesen des Textes:
    inline  QString     get_text()
    {
        return text;
    }
            QString     zeile(uint zeilennummer);
            QString     zeilen(uint zeilennummer_beginn, uint zeilenmenge);
    inline  char        get_trennzeichen()
    {
        return trenner;
    }

    //Funktionen zum erweitern des Textes:
    void    set_text(QString neuer_text);
    void    zeile_vorwegsetzen(QString zeilentext);
    void    zeile_anhaengen(QString zeilentext);
    void    zeilen_anhaengen(QString zeilentext);
    int     zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, \
                            QString zeilentext);
    int     zeilen_einfuegen(uint zeilennummer_vor_neuer_zeile, \
                            QString zeilentext);
    int     zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext);
    void    set_trennzeichen(char neues_Trennzeichen);

    //Funktionen zum veringern des Textes:
    void    clear();
    int     zeile_loeschen(uint zeilennummer);
    int     zeilen_loeschen(uint zeilennummer_beginn, uint zeilenmenge);

    //andere Funktionen:
    inline  uint zeilenanzahl()
    {
        return anzahl_der_zeilen;
    }
            uint finde_Zeile(QString zeilentext);

private:
    void zeilen_zaehlen();
    QString textzeile_ohne_Zeilenvorschuebe(QString zeilentext);


    QString     text;
    uint        anzahl_der_zeilen;
    char        trenner;           //Zeichen, dass die Zeilen trennt


};

#endif // TEXT_ZEILENWEISE_H
