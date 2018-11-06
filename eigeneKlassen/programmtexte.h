#ifndef PROGRAMMTEXTE_H
#define PROGRAMMTEXTE_H

#include "programmtext.h"
#include "undo_redo.h"
#include <vector>
#include <QString>

class programmtexte
{
public:
    programmtexte();
    void add(programmtext p, QString name, undo_redo ur);
    void del();
    void del(uint index);
    void clear();

    void set_current_index(uint index);
    inline void set_prgname(QString name)
    {
        vpname.at(current_index) = name;
    }
    inline void set_prgname(QString name, uint index)
    {
        vpname.at(index) = name;
    }

    inline uint get_size()
    {
        return vp.size();//gibt die Anzahl der Elemente wieder
    }
    inline programmtext *get_prgtext()
    {
        return &vp.at(current_index);
    }
    inline programmtext *get_prgtext(uint index)
    {
        return &vp.at(index);
    }
    inline undo_redo *get_prg_undo_redo()
    {
        return &vur.at(current_index);
    }
    inline undo_redo *get_prg_undo_redo(uint index)
    {
        return &vur.at(index);
    }
    inline QString get_prgname()
    {
        return vpname.at(current_index);
    }
    inline QString get_prgname(uint index)
    {
        return vpname.at(index);
    }
    inline uint get_current_index()
    {
        return current_index;
    }


private:
    vector<programmtext> vp;    //Vector enthällt Programmtexte
    vector<undo_redo> vur;      //Vector enthällt Wiederrufenschritte
    vector<QString> vpname;     //Vektor enthällt Dateinahmen (Pfade)
    uint current_index;
};

#endif // PROGRAMMTEXTE_H
