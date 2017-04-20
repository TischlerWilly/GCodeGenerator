#ifndef UNDO_REDO_H
#define UNDO_REDO_H

#include <vector>
#include "programmtext.h"




class undo_redo
{
public:
    undo_redo();
    void neu(programmtext t_neu);
    void set_groesse_max(uint maximale_anzahl_an_wiederrufenschritten);
    uint get_groesse_max();
    uint get_groesse();
    void clear();
    programmtext undo();
    programmtext redo();
    int get_erstes_aktives_element();
    int get_anz_aktive_elemente();


private:
    vector<programmtext> vector_t;
    vector<int> erstes_aktives_element_t;
    vector<int> anz_aktive_elemente_t;

    int aktuelle_position;
    uint max_anzahl;




};

#endif // UNDO_REDO_H
