#ifndef WENNDANNSONST_H
#define WENNDANNSONST_H

#include <QString>
#include <QMessageBox>
#include "formel.h"

class WennDannSonst : public Formel
{
public:
    WennDannSonst();
    WennDannSonst(QString WennDannSonst_formel);
    void formelText_setzen(QString text);

protected:
    QString vergleich_oparator(const QString text);
    QString vergleich_links(const QString text);
    QString vergleich_rechts(const QString text);
    bool ist_vergleich(const QString text);

    QString text_links(const QString text, const QString trenntext);
    QString text_rechts(const QString text, const QString trenntext);
    QString weDaSo(const QString text);

    bool vergleich_ist_wahr(const QString text);
    bool vergleichskette_ist_wahr(const QString text);
    bool vergleichskette_ist_wahr_nur_ODER(const QString text);

    float ergebnis_berechnen(QString formelText);

private:


};

#endif // WENNDANNSONST_H

/*

Zeichensatz geerbt:
+ für Addition
- für Subtraktion
* für Multiplikation
/ für Division
. oder , zum angeben von Kommazahlen sind erlaubt
( und ) zum einklammern

Zeichensatz eigen:
? und : für Wenn-Dann-Sonst bedingungen     Wenn  ?   Dann  : Sonst
>, <, ==, !=, >=, <= für vergleiche
&, | um Vergleiche zu verbinden

Testrechnungen:
12>3 ? 1 : 2        = 1
12<3 ? 1 : 2        = 2
12!=3 ? 1 : 2       = 1 -->hier treten noch Fehler auf!!
12==3 ? 1 : 2       = 2
12<=3 ? 1 : 2       = 2
12>=3 ? 1 : 2       = 1

1+3<5               = wahr
2*(3+5) > 5         = wahr
5 < 2*(3+5)         = wahr
-----------------------------------------------------------------------------------------------------------------
1<2  | ((1+1==5?3:4)==4)  &  2*(3+5)==16     ?     (1==1 ? 2 : 3)     :      1         = 2
wahr |  (1+1==5?3:4)      &    (3+5)         ?     wahr ? 2 : 3     :      1         = 2
wahr |   1+1==5           &  2*  8  ==16     ?         2            :      1         = 2
wahr |    2 ==5           &   16    ==16     ?         2            :      1         = 2
wahr |    falsch          &    wahr          ?         2            :      1         = 2
          wahr                               ?         2            :      1         = 2
                                                                                     = 2
1-->prüfen ob text Klammern enthällt
   wenn ja:                                    wenn nein:
2-->innerste Klammer suchen                  -->weiter mit Punkt 3
3-->prüfen ob text mind. ein '?' enthällt
   wenn ja:                                    wenn nein:
   z.B: 1<2   ?   2   :   1==1 ? 1 : 3       -->ergebniss der Rechnung in den Klammern berechnen
   z.B: 1<2   ?   1==1 ? 1 : 3   :   2
   z.B: 1<2   ?   1==1 ? 1 : 3   :   1==1 ? 1 : 3

4-->text links vom ersten ? sondieren
    z.B: 1+1<3 & 3-3==0 | 8/2!=0
    z.B: 3-3==0 | 8/2!=0 & 1+1<3

5-->prüfen ob text ein & enthällt
   wenn ja:                                    wenn nein:
6-->text links vom & sondieren              -->weiter mit punkt 7
7-->prüfen ob text ein | enthällt
   wenn ja:                                    wenn nein:
8-->text links neben dem | sondieren        -->weiter mit punkt 9
9-->prüfen ob text einen Vergleichsoperatoren enthällt
   wenn ja:                                   wenn nein:
10->Vergleich auswerten                      -->abbruch mit Fehlermeldung
  wenn WAHR:                                  wenn FALSCH:
11a>ausdruck zwischen ? und : sondieren      11b>ausdruck hinter : sondieren
-----------------------------------------------------------------------------------------------------------------
1==1 & 2<3 ? 1 : 2  = 1
1==1 | 5<3 ? 1 : 2  = 1

*/
