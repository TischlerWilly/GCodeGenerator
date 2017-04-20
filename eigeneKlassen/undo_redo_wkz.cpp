#include "undo_redo_wkz.h"




undo_redo_wkz::undo_redo_wkz()
{
    set_groesse_max(30);
    clear();
}


void undo_redo_wkz::set_groesse_max(uint maximale_anzahl_an_wiederrufenschritten)
{
    if(maximale_anzahl_an_wiederrufenschritten > vector_w.size())
    {
        max_anzahl = maximale_anzahl_an_wiederrufenschritten;
    }
    if(maximale_anzahl_an_wiederrufenschritten < vector_w.size())
    {
        vector_w.clear();
        max_anzahl = maximale_anzahl_an_wiederrufenschritten;
    }
}

uint undo_redo_wkz::get_groesse_max()
{
    return max_anzahl;
}

uint undo_redo_wkz::get_groesse()
{
    return vector_w.size();
}

void undo_redo_wkz::neu(werkzeug w_neu)
{
    if((uint)aktuelle_position+1 == vector_w.size())
    {
        if(vector_w.size() < max_anzahl)
        {
            vector_w.push_back(w_neu);
            aktuelle_position++;
        }else
        {
            vector_w.erase(vector_w.begin());
            vector_w.push_back(w_neu);
        }
    }else
    {
        vector_w.erase(vector_w.begin()+aktuelle_position+1, vector_w.end());
        vector_w.push_back(w_neu);
        aktuelle_position = vector_w.size()-1;
    }
    //QMessageBox mb;
    //mb.setText("neu " + QString::fromStdString(lib_ol_int_to_string(aktuelle_position)));
    //mb.exec();
}

void undo_redo_wkz::clear()
{
    aktuelle_position = -1;
    vector_w.clear();
}

werkzeug undo_redo_wkz::undo()
{
    //QMessageBox mb;
    //mb.setText("undo " + QString::fromStdString(lib_ol_int_to_string(aktuelle_position)));
    //mb.exec();
    if(aktuelle_position > 0)
    {
        aktuelle_position--;
        return vector_w.at(aktuelle_position);
    }else
    {
        return vector_w.at(0);
    }
}

werkzeug undo_redo_wkz::redo()
{
    if((uint)aktuelle_position+1 < vector_w.size())
    {
        aktuelle_position++;
        return vector_w.at(aktuelle_position);
    }else
    {
        return vector_w.at(aktuelle_position);
    }
}

int undo_redo_wkz::get_erstes_aktives_element()
{
    return erstes_aktives_element_t.at(aktuelle_position);
}

int undo_redo_wkz::get_anz_aktive_elemente()
{
    return anz_aktive_elemente_t.at(aktuelle_position);
}
