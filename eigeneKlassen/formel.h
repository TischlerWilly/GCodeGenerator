#ifndef FORMEL_H
#define FORMEL_H

#include <QString>

class Formel
{
public:
    Formel();
    Formel(QString formel);
    float bekomme_Ergebnis_als_float();
    QString bekomme_Ergebnis_als_String();
    bool ist_fehlerhaft();
    QString bekomme_fehler_text();

protected:
    void formelText_setzen(QString text);
    QString formelText_bekommen();
    float ergebnis_berechnen(QString formelText);
    void ergebnis_setzen(float wert);
    void fehler_melden(QString neuerFehlerText);
    void fehler_nullen();
    bool ist_ziffer(const QChar zeichen);
    bool ist_zahl(const QString text);
    bool ist_Addition(const QString text);
    bool ist_Subtraktion(const QString text);
    bool ist_Multiplikation(const QString text);
    bool ist_Division(const QString text);
    bool ist_Division_durch_Null(const QString text);
    bool ist_einfache_Berechnung(const QString text);
    bool ist_ohne_ungueltige_Zeichen(const QChar zeichen);
    bool ist_ohne_ungueltige_Zeichen(const QString text);
    bool ist_ohne_ungueltige_Klammernhaelften(const  QString text);
    bool ist_ohne_ungueltige_Kommas(QString text);
    bool ist_ohne_ungueltige_Rechenzeichen(const QString text);
    float zahl_aus_string(QString text);
    float addition(QString text);
    float subtraktion(QString text);
    float multiplikation(QString text);
    float division(QString text);
    QString berechne(QString text);
    QString Verschachtelung_aufloesen(QString text);
    QString Verschachtelung_text_links(const QString text, const QChar rechenzeichen);
    QString Verschachtelung_text_mitte(const QString text, const QChar rechenzeichen);
    QString Verschachtelung_text_rechts(const QString text, const QChar rechenzeichen);
    QString Klammern_aufloesen(QString text);
    QString Klammern_aufloesen_text_links(const QString text);
    QString Klammern_aufloesen_text_mitte(const QString text);
    QString Klammern_aufloesen_text_rechts(const QString text);
    QString leerzeichen_entfernen(QString text);



private:


    //Variablen:
    //QString formelAlsString;
    QString FormelText;
    float ergebnis;
    bool istFehlerhaft;
    QString fehlerText;
};

#endif // FORMEL_H

/*

Zeichensatz:
+ für Addition
- für Subtraktion
* für Multiplikation
/ für Division
. oder , zum angeben von Kommazahlen sind erlaubt
( und ) zum einklammern

Testrechnungen:
2+-3*-4+-5 = 9
2,1+-3,1*-4,1+-5,1 = 9,71
(1+2)*2 = 6
((1+2)*2)/3  = 2
(((1+2)*2))/3+(((1+2)*2))/3*6 = 14
32+12+12+12+1 = 69
12+(11+3) = 26

*/
