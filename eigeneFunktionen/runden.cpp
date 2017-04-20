#include"runden.h"

int aufrunden(float zahl)
{
    int returnwert = 0;
    returnwert = static_cast<int>(zahl) +1;
    return returnwert;
}

int abrunden(float zahl)
{
    int returnwert = 0;
    returnwert = static_cast<int>(zahl);
    return returnwert;
}

float runden(float alte_zahl, int anzahl_der_nachkommastellen)
{
    double v[] = { 1, 10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8 };  // mgl. verlängern
    return floor(alte_zahl * v[anzahl_der_nachkommastellen] + 0.5) / v[anzahl_der_nachkommastellen];
}
