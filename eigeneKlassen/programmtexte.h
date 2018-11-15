#ifndef PROGRAMMTEXTE_H
#define PROGRAMMTEXTE_H


#include <QString>
#include <qvector.h>
#include "../eigeneFunktionen/umwandeln.h"
#include "programmtext.h"
#include "undo_redo.h"
#include "indexhisory.h"


class programmtexte
{
public:
    programmtexte();
    void add(programmtext p, QString name, undo_redo ur);
    void del();
    void del(uint index);
    void clear();

    void set_current_index(int index);
    void set_current_index(QString pfad);
    void set_index_vor();
    void set_index_nach();
    inline void set_prgname(QString name)
    {
        vpname.replace(current_index, name);
    }
    inline void set_prgname(QString name, uint index)
    {
        vpname.replace(index, name);
    }
    void aktualisieren_fkon_ein_aus(bool einschalten);

    inline  bool get_aktualisieren_fkon_ein_aus()
    {
        return aktualisieren_fkon_eingeschaltet;
    }

    int get_size();
    bool dateien_sind_offen();
    bool isopen(QString pfad);

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

    text_zeilenweise get_names();

private:
    QVector<programmtext> vp;    //Vector enthällt Programmtexte
    QVector<undo_redo> vur;      //Vector enthällt Wiederrufenschritte
    QVector<QString> vpname;     //Vektor enthällt Dateinahmen (Pfade)
    uint current_index;
    indexhisory ih;
    bool    aktualisieren_fkon_eingeschaltet;
};

#endif // PROGRAMMTEXTE_H
