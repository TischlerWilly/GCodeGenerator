#include "indexhisory.h"

indexhisory::indexhisory()
{

}

void indexhisory::add(int index)
{
    del(index);
    QString tmp = int_to_qstring(index);
    history.zeile_vorwegsetzen(tmp);
}

void indexhisory::del(int index)
{
    QString tmp = int_to_qstring(index);
    uint gefunden = 0;
    for(uint i=1; i<=history.zeilenanzahl() ;i++)
    {
        if(history.zeile(i) == tmp)
        {
            gefunden = i;
            break;
        }
    }
    if(gefunden !=0)
    {
        history.zeile_loeschen(gefunden);
    }
}

int indexhisory::get_current()
{
    if(history.get_text().isEmpty())
    {
        return 0;
    }else
    {
        return history.zeile(1).toInt();
    }
}

void indexhisory::clear()
{
    history.clear();
}

int indexhisory::index_vor()
{
    if(history.zeilenanzahl() > 1)
    {
        QString tmp = history.zeile(1);
        history.zeile_loeschen(1);
        history.zeile_anhaengen(tmp);
    }
    return get_current();
}

int indexhisory::index_nach()
{
    if(history.zeilenanzahl() > 1)
    {
        QString tmp = history.zeile(history.zeilenanzahl());
        history.zeile_loeschen(history.zeilenanzahl());
        history.zeile_vorwegsetzen(tmp);
    }
    return get_current();
}
