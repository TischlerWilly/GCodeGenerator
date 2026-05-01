#include "indexhisory.h"

indexhisory::indexhisory()
{

}

void indexhisory::add(int index)
{
    del(index);
    QString tmp = int_to_qstring(index);
    history.add_vo(tmp);
}

void indexhisory::del(int index)
{
    history.entf(index,1);
}

int indexhisory::get_current()
{
    if(!history.count())
    {
        return 0;
    }else
    {
        return history.at(1).toInt();
    }
}

void indexhisory::clear()
{
    history.clear();
}

int indexhisory::index_vor()
{
    if(history.count() > 1)
    {
        QString tmp = history.at(0);
        history.entf(0,1);
        history.add_hi(tmp);
    }
    return get_current();
}

int indexhisory::index_nach()
{
    if(history.count() > 1)
    {
        QString tmp = history.at(history.count()-1);//das letzte Element kopieren
        history.entf(history.count()-1,1);//das letzte Element löschen
        history.add_vo(tmp);
    }
    return get_current();
}
