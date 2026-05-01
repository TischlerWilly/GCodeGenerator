#ifndef INDEXHISTORY_H
#define INDEXHISTORY_H

#include "text_zw.h"
#include "../eigeneFunktionen/umwandeln.h"

class indexhistory
{
public:
    indexhistory();
    void add(int index);
    void del(int index);
    void clear();
    int get_current();
    int index_vor();
    int index_nach();

private:
    text_zw history;//neue indexe vorne alte indexe hinten
};

#endif // INDEXHISTORY_H
