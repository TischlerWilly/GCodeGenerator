#ifndef MYFUNKTION_H
#define MYFUNKTION_H

#include <QString>
#include "myDefines.h"
#include "../eigeneKlassen/wenndannsonst.h"
#include "text.h"
#include "umwandeln.h"


QString ausdruck_auswerten (QString ausdruck);

QString variablen_durch_werte_ersetzten(QString variablen, QString formeltext);

bool ist_ziffer(const QChar zeichen);
bool ist_zahl(const QString text);

QString genauigkeit_reduzieren(QString zahl, uint nachkommastellen);

#endif // MYFUNKTION_H
