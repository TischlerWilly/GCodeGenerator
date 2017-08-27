#ifndef tabelle_tz3_H
#define tabelle_tz3_H

#include "text_zeilenweise.h"


class tabelle_tz3
{
public:
    tabelle_tz3();
    void set_trennzeichen_zeilen(char neues_Trennzeichen);
    void set_trennzeichen_spalten(char neues_Trennzeichen);
    void set_trennzeichen_eintraege(char neues_Trennzeichen);
    void set_text(QString neuer_text);

    inline QString get_text()
    {
        return zeile.get_text();
    }

    QString get_zeile(uint zeilennummer);
    QString get_spalte(uint zeilennummer, uint spaltennummer);
    QString get_spalten();
    QString get_eintrag(uint zeilennummer, uint spaltennummer, uint eintragsnummer);

    uint get_spaltenzahl(uint zeilennummer);

    bool zeile_ersaetzen(uint zeilennummer, QString neuer_text);
    bool spalte_ersatzen(uint zeilennummer, uint spaltennummer, QString neuer_text);
    bool vorherigespalte_ersaetzen(uint zeile_aktuell, uint spalte_aktuell, QString neuer_text);
    bool eintrag_ersatzen(uint zeilennummer, uint spaltennummer, uint eintragsnummer, QString neuer_text);

    void zeile_anhaengen(QString neuer_text);
    bool spalte_anhaengen(uint zeilennummer, QString neuer_text);
    bool eintrag_anhaengen(uint zeilennummer, uint spaltennummer, QString neuer_text);

    QString folgespalte(uint zeile_aktuell, uint spalte_aktuell);
    QString vorherigespalte(uint zeile_aktuell, uint spalte_aktuell);


private:

    text_zeilenweise zeile;
    text_zeilenweise spalte;//ein Eintrag in einer Zeile
    text_zeilenweise eintrag;



};

#endif // tabelle_tz3_H
