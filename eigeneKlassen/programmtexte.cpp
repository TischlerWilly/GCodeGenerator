#include "programmtexte.h"

programmtexte::programmtexte()
{
    clear();
}

void programmtexte::add(programmtext p, QString name, undo_redo ur)
{
    vp.push_back(p);
    vpname.push_back(name);
    vur.push_back(ur);
    current_index = vp.size()-1;
}

void programmtexte::del()
{
    if(vp.size() > 1)//immer eine Instanz behalten
    {
        vp.erase(vp.begin() + current_index);
        vur.erase(vur.begin() + current_index);
        vpname.erase(vpname.begin() + current_index);
        current_index = 0;
    }
}

void programmtexte::del(uint index)
{
    if(index <= vp.size()-1 && index > 1)//immer eine Instanz behalten
    {
        vp.erase(vp.begin() + index);
        vur.erase(vur.begin() + index);
        vpname.erase(vpname.begin() + index);
    }
}

void programmtexte::clear()
{
    vp.clear();
    vur.clear();
    vpname.clear();

    //immer eine Instanz behalten:
    programmtext t;
    vp.push_back(t);
    QString name = NICHT_DEFINIERT;
    vpname.push_back(name);
    undo_redo ur;
    vur.push_back(ur);
    current_index = 0;
}

void programmtexte::set_current_index(uint index)
{
    if(index <= vp.size()-1)
    {
        current_index = index;
    }
}
