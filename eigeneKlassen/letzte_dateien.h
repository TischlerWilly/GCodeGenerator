#ifndef LETZTE_DATEIEN_H
#define LETZTE_DATEIEN_H

#include "eigeneKlassen/text_zeilenweise.h"

class letzte_dateien
{
public:
    letzte_dateien();
    letzte_dateien(uint anzahl_der_eintraege);

    QString get_text();
    inline uint get_anz_eintreage()
    {
        return anz_eintraege;
    }

    void set_text(QString liste);
    void set_anz_eintreage(uint neue_anz);
    void datei_merken(QString name);
    void datei_vergessen(QString name);



private:
    text_zeilenweise dateinamen;
    uint anz_eintraege;



};

#endif // LETZTE_DATEIEN_H
