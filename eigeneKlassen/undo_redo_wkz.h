#ifndef UNDO_REDO_WKZ_H
#define UNDO_REDO_WKZ_H

#include <vector>
#include "werkzeug.h"


class undo_redo_wkz
{
public:
    undo_redo_wkz();
    void neu(werkzeug w_neu);
    void set_groesse_max(uint maximale_anzahl_an_wiederrufenschritten);
    uint get_groesse_max();
    uint get_groesse();
    void clear();
    werkzeug undo();
    werkzeug redo();
    int get_erstes_aktives_element();
    int get_anz_aktive_elemente();


private:
    std::vector<werkzeug> vector_w;
    std::vector<int> erstes_aktives_element_t;
    std::vector<int> anz_aktive_elemente_t;

    int aktuelle_position;
    uint max_anzahl;
};

#endif // UNDO_REDO_WKZ_H
