#ifndef TEXT_TZ_H
#define TEXT_TZ_H

#include <QString>
#include <vector>

class text_zw
{
public:
    text_zw();
    text_zw(QString text, char trennzeichen = '\n');

    //---------------------------------------------set_xy:
    void    set_text(QString text, char trennzeichen);
    void    set_trenz(char trennzeichen);

    //---------------------------------------------get_xy:
    QString     at(uint zeilennummer);
    QString     at(uint zeilennummer_beginn, uint zeilenmenge);
    QString     text();
    char        trennz();
    uint        count();

    //---------------------------------------------Manipulationen:
    void    clear();
    void    add_vo(QString text);
    void    add_hi(QString text);
    int     add_mi(uint index_vor, QString text);
    int     edit(uint index, QString neuer_text);
    int     entf(uint index, uint menge = 1);

private:
    std::vector<QString> Daten;
    char Trennzeichen;

    std::vector<QString> to_vector(QString text, char trennzeichen = '\n');



};
//-------------------Funktionen nicht innerhalb der Klasse:
bool operator ==(text_zw t1, text_zw t2);
bool operator !=(text_zw t1, text_zw t2);

#endif // TEXT_TZ_H
