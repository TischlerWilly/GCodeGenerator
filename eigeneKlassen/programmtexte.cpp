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
    ih.add(vp.size()-1);
}

void programmtexte::del()
{
    if(vp.size() > 1)//immer eine Instanz behalten
    {        
        vp.erase(vp.begin() + current_index);
        vur.erase(vur.begin() + current_index);
        vpname.erase(vpname.begin() + current_index);
        ih.del(current_index);
        set_current_index(ih.get_current());
    }
    if(vp.size() == 1)
    {
        clear();
    }
}

void programmtexte::del(uint index)
{
    if(index <= vp.size()-1 && index > 1)//immer eine Instanz behalten
    {
        vp.erase(vp.begin() + index);
        vur.erase(vur.begin() + index);
        vpname.erase(vpname.begin() + index);
        ih.del(index);
        set_current_index(ih.get_current());
    }
}

void programmtexte::clear()
{
    vp.clear();
    vur.clear();
    vpname.clear();
    ih.clear();

    //immer eine Instanz behalten:
    programmtext t;
    vp.push_back(t);
    QString name = NICHT_DEFINIERT;
    vpname.push_back(name);
    undo_redo ur;
    vur.push_back(ur);
    current_index = 0;
}

void programmtexte::set_current_index(int index)
{
    if(index <= vp.size()-1)
    {
        current_index = index;
        ih.add(index);
        get_prgtext()->aktualisieren_fkon_ein_aus(aktualisieren_fkon_eingeschaltet);
    }
}

void programmtexte::set_current_index(QString pfad)
{
    for(int i=0; i<vpname.size() ;i++)
    {
        if(vpname.at(i) == pfad)
        {
            set_current_index(i);
            ih.add(i);
        }
    }
}

void programmtexte::set_index_vor()
{
    set_current_index(ih.index_vor());
}

void programmtexte::set_index_nach()
{
    set_current_index(ih.index_nach());
}

void programmtexte::aktualisieren_fkon_ein_aus(bool einschalten)
{
    if(einschalten)
    {
        aktualisieren_fkon_eingeschaltet = true;
        get_prgtext()->aktualisieren_fkon_ein_aus(true);
    }else
    {
        aktualisieren_fkon_eingeschaltet = false;
        get_prgtext()->aktualisieren_fkon_ein_aus(false);
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

int programmtexte::get_size()
{
    int size = vp.size();//gibt die Anzahl der Elemente wieder
    size = size-1;//-1 weil immer 1 Element vorhanden bleibt was jedoch nicht mitgezählt werden soll
    return size;
}

bool programmtexte::dateien_sind_offen()
{
    if(get_size() > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool programmtexte::isopen(QString pfad)
{
    bool offen = false;
    for(int i=0; i<vpname.size() ;i++)
    {
        if(vpname.at(i) == pfad)
        {
            offen = true;
            break;
        }
    }
    return offen;
}











