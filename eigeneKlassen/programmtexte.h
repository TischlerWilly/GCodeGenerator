#ifndef PROGRAMMTEXTE_H
#define PROGRAMMTEXTE_H


#include <QString>
#include <qvector.h>
#include "../eigeneFunktionen/umwandeln.h"
#include "programmtext.h"
#include "undo_redo.h"


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
        vpname.replace(current_index, name);
    }
    inline void set_prgname(QString name, uint index)
    {
        vpname.replace(index, name);
    }

    inline int get_size()
    {
        return vp.size();//gibt die Anzahl der Elemente wieder
    }
    inline bool dateien_sind_offen()
    {
        if(get_size() > 1)
        {
            return true;
        }else
        {
            return false;
        }
    }

    inline programmtext *get_prgtext()
    {
        return &vp[current_index];
    }
    inline programmtext *get_prgtext(uint index)
    {
        return &vp[index];
    }
    inline undo_redo *get_prg_undo_redo()
    {
        return &vur[current_index];
    }
    inline undo_redo *get_prg_undo_redo(uint index)
    {
        return &vur[index];
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
    QVector<programmtext> vp;    //Vector enthällt Programmtexte
    QVector<undo_redo> vur;      //Vector enthällt Wiederrufenschritte
    QVector<QString> vpname;     //Vektor enthällt Dateinahmen (Pfade)
    uint current_index;
};

#endif // PROGRAMMTEXTE_H
