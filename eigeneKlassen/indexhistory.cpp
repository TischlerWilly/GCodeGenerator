#include "indexhistory.h"

indexhistory::indexhistory()
{

}

void indexhistory::add(int index)
{
    del(index);
    QString tmp = int_to_qstring(index);
    history.add_vo(tmp);
}

void indexhistory::del(int index)
{
    history.entf(index,1);
}

int indexhistory::get_current()
{
    if(!history.count())
    {
        return 0;
    }else
    {
        return history.at(1).toInt();
    }
}

void indexhistory::clear()
{
    history.clear();
}

int indexhistory::index_vor()
{
    if(history.count() > 1)
    {
        QString tmp = history.at(0);
        history.entf(0,1);
        history.add_hi(tmp);
    }
    return get_current();
}

int indexhistory::index_nach()
{
    if(history.count() > 1)
    {
        QString tmp = history.at(history.count()-1);//das letzte Element kopieren
        history.entf(history.count()-1,1);//das letzte Element löschen
        history.add_vo(tmp);
    }
    return get_current();
}
