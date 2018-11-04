#include "programmtexte.h"

programmtexte::programmtexte()
{
    clear();
}

void programmtexte::add(programmtext p, QString name)
{
    vp.push_back(p);
    vpname.push_back(name);
    current_index = vp.size()-1;
}

void programmtexte::del(uint index)
{
    if(index <= vp.size()-1)
    {
        vp.erase(vp.begin() + index);
        vpname.erase(vpname.begin() + index);
    }
}

void programmtexte::clear()
{
    vp.clear();
    vpname.clear();
    current_index = 0;
}

void programmtexte::set_current_index(uint index)
{
    if(index <= vp.size()-1)
    {
        current_index = index;
    }
}
