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
    set_current_index(vp.size()-1);
}

void programmtexte::del()
{
    if(vp.size() > 1)//immer eine Instanz behalten
    {
        vp.erase(vp.begin() + current_index);
        vur.erase(vur.begin() + current_index);
        vpname.erase(vpname.begin() + current_index);
        if(vp.size() >=2)
        {
            set_current_index(1);
        }else
        {
            set_current_index(0);
        }
    }
}

void programmtexte::del(uint index)
{
    if(index <= vp.size()-1 && index > 1)//immer eine Instanz behalten
    {
        vp.erase(vp.begin() + index);
        vur.erase(vur.begin() + index);
        vpname.erase(vpname.begin() + index);
        if(vp.size() >=2)
        {
            set_current_index(1);
        }else
        {
            set_current_index(0);
        }
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
        get_prgtext()->aktualisieren_fkon_ein_aus(aktualisieren_fkon_eingeschaltet);
    }
}

text_zeilenweise programmtexte::get_names()
{
    text_zeilenweise namen;
    for(int i = 1; i<vpname.count() ; i++)//mit 1 beginnen statt mit 0 weil erstes Element ist "NICHT_DEFINIERT"
    {
        namen.zeile_anhaengen(vpname.at(i));
    }
    return namen;
}















