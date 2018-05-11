#ifndef MYFUNKTION_H
#define MYFUNKTION_H

#include <QString>
#include "myDefines.h"
#include "../eigeneKlassen/wenndannsonst.h"
#include "text.h"
#include "umwandeln.h"
#include "../eigeneKlassen/punkt3d.h"
#include "../eigeneKlassen/punkt2d.h"


QString ausdruck_auswerten (QString ausdruck);

QString variablen_durch_werte_ersetzten(QString variablen, QString formeltext);

bool ist_ziffer(const QChar zeichen);
bool ist_zahl(const QString text);

QString genauigkeit_reduzieren(QString zahl, uint nachkommastellen);

QString genauigkeit_reduzieren(double zahl, uint nachkommastellen);

bool cagleich(punkt3d p1, punkt3d p2, double tolleranz);

bool cagleich(punkt2d p1, punkt2d p2, double tolleranz);

bool cagleich(double p1, double p2, double tolleranz);

#endif // MYFUNKTION_H
