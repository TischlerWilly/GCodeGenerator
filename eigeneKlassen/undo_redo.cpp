#include "undo_redo.h"


undo_redo::undo_redo()
{
    set_groesse_max(20);
    clear();
}


void undo_redo::set_groesse_max(uint maximale_anzahl_an_wiederrufenschritten)
{
    if(maximale_anzahl_an_wiederrufenschritten > vector_t.size())
    {
        max_anzahl = maximale_anzahl_an_wiederrufenschritten;
    }
    if(maximale_anzahl_an_wiederrufenschritten < vector_t.size())
    {
        vector_t.clear();
        max_anzahl = maximale_anzahl_an_wiederrufenschritten;
    }

}

uint undo_redo::get_groesse_max()
{
    return max_anzahl;
}

uint undo_redo::get_groesse()
{
    return vector_t.size();
}

void undo_redo::neu(programmtext t_neu)
{
    if((uint)aktuelle_position+1 == vector_t.size())
    {
        if(vector_t.size() < max_anzahl)
        {
            vector_t.push_back(t_neu);
            aktuelle_position++;
        }else
        {
            vector_t.erase(vector_t.begin());
            vector_t.push_back(t_neu);
        }
    }else
    {
        vector_t.erase(vector_t.begin()+aktuelle_position+1, vector_t.end());
        vector_t.push_back(t_neu);
        aktuelle_position = vector_t.size()-1;
    }
    //QMessageBox mb;
    //mb.setText("neu " + QString::fromStdString(lib_ol_int_to_string(aktuelle_position)));
    //mb.exec();
}

void undo_redo::clear()
{
    aktuelle_position = -1;
    vector_t.clear();
}

programmtext undo_redo::undo()
{
    //QMessageBox mb;
    //mb.setText("undo " + QString::fromStdString(lib_ol_int_to_string(aktuelle_position)));
    //mb.exec();
    if(aktuelle_position > 0)
    {
        aktuelle_position--;
        return vector_t.at(aktuelle_position);
    }else
    {
        return vector_t.at(0);
    }
}

programmtext undo_redo::redo()
{
    if((uint)aktuelle_position+1 < vector_t.size())
    {
        aktuelle_position++;
        return vector_t.at(aktuelle_position);
    }else
    {
        return vector_t.at(aktuelle_position);
    }
}

int undo_redo::get_erstes_aktives_element()
{
    return erstes_aktives_element_t.at(aktuelle_position);
}

int undo_redo::get_anz_aktive_elemente()
{
    return anz_aktive_elemente_t.at(aktuelle_position);
}
