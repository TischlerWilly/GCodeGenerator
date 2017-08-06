#ifndef TABELLE_H
#define TABELLE_H

#include "text_zeilenweise.h"

/*
 *  Eine Tabelle in diesem Sinne ähnelt einem 3-dimensionalen array
 *  jedoch fangen alle Einträge mit dem Index 1 an
 *
*/

class tabelle
{
public:
    tabelle();
    void set_trennzeichen_zeilen(char neues_Trennzeichen);
    void set_trennzeichen_spalten(char neues_Trennzeichen);
    void set_trennzeichen_eintraege(char neues_Trennzeichen);
    void set_text(QString neuer_text);

    QString get_zeile(uint zeilennummer);
    QString get_spalte(uint zeilennummer, uint spaltennummer);
    QString get_eintrag(uint zeilennummer, uint spaltennummer, uint eintragsnummer);

private:

    text_zeilenweise zeile;
    text_zeilenweise spalte;//ein Eintrag in einer Zeile
    text_zeilenweise eintrag;

    QString trenner_zeilen;
    QString trenner_spalten;
    QString trenner_eintraege;



};

#endif // TABELLE_H
