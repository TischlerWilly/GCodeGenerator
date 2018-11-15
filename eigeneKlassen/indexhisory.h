#ifndef INDEXHISORY_H
#define INDEXHISORY_H

#include "text_zeilenweise.h"
#include "../eigeneFunktionen/umwandeln.h"

class indexhisory
{
public:
    indexhisory();
    void add(int index);
    void del(int index);
    void clear();
    int get_current();
    int index_vor();
    int index_nach();

private:
    text_zeilenweise history;//neue indexe vorne alte indexe hinten
};

#endif // INDEXHISORY_H
