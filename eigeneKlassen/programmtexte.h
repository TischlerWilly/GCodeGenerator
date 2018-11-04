#ifndef PROGRAMMTEXTE_H
#define PROGRAMMTEXTE_H

#include "programmtext.h"
#include <vector>
#include <QString>

class programmtexte
{
public:
    programmtexte();
    void add(programmtext p, QString name);
    void del(uint index);
    void clear();

    void set_current_index(uint index);

    inline uint get_size()
    {
        return vp.size();//gibt die Anzahl der Elemente wieder
    }
    inline programmtext get_prgtext()
    {
        return vp.at(current_index);
    }
    inline programmtext get_prgtext(uint index)
    {
        return vp.at(index);
    }
    inline QString get_prgname()
    {
        return vpname.at(current_index);
    }
    inline QString get_prgname(uint index)
    {
        return vpname.at(index);
    }



private:
    vector<programmtext> vp;    //Vector enthällt Programmtexte
    vector<QString> vpname;     //Vektor enthällt Dateinahmen (Pfade)
    uint current_index;
};

#endif // PROGRAMMTEXTE_H
