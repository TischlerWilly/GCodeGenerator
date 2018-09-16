#ifndef WERKZEUG_H
#define WERKZEUG_H

#include <QString>
#include "text_zeilenweise.h"
#include "../myDefines.h"
#include "../eigeneFunktionen/umwandeln.h"
#include "../eigeneFunktionen/text.h"
#include "wenndannsonst.h"



class werkzeug
{
public:
    werkzeug();
    void set_werkezuge(QString neue_werkzeuge);
    void clear();
    QString get_werkzeuge();
    QString get_werkzeug(QString werkzeugname);
    text_zeilenweise get_werkzeuge_zeilenweise();
    QString get_bohrwkzname(double durchmesser);
    QString get_anzeigetext();
    text_zeilenweise get_anzeigetext_zeilenweise();

    QString get_anzeigetext(uint werkzeugindex);
    QString zeile(uint zeilennummer);
    int zeile_loeschen(uint zeilennummer);
    int zeile_einfuegen(uint zeilennummer_vor_neuer_zeile, QString zeilentext);
    void zeile_anhaengen(QString zeilentext);
    int zeile_ersaetzen(uint zeilennummer, QString neuer_zeilentext);

private:
    text_zeilenweise werkzeuge;
    text_zeilenweise anzeigetext;

    void aktualisiere_anzeigetext();


};

#endif // WERKZEUG_H
