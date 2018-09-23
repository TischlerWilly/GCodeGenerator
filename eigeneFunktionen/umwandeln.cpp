#include"umwandeln.h"


std::string int_to_string(int zahl)
{
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return returnstring;
}

QString int_to_qstring(int zahl)
{
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return QString::fromStdString(returnstring);
}

std::string float_to_string(float zahl)
{   
    //Nachkommastellen reduzeiren:
    uint genauigkeit = 6;
    zahl = zahl * pow(10,genauigkeit);//pow == Potenzfuntion
    uint tmp = zahl;//Nachkommastellen abschneiden
    zahl = tmp;
    zahl = zahl / pow(10,genauigkeit);//pow == Potenzfuntion

    //umwandeln:
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return returnstring;
}

QString float_to_qstring(float zahl)
{
    //Nachkommastellen reduzeiren:
    uint genauigkeit = 6;
    zahl = zahl * pow(10,genauigkeit);//pow == Potenzfuntion
    uint tmp = zahl;//Nachkommastellen abschneiden
    zahl = tmp;
    zahl = zahl / pow(10,genauigkeit);//pow == Potenzfuntion

    //umwandeln:
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return QString::fromStdString(returnstring);
}

std::string double_to_string(double zahl)
{
    //Nachkommastellen reduzeiren:
    uint genauigkeit = 6;
    zahl = zahl * pow(10,genauigkeit);//pow == Potenzfuntion
    uint tmp = zahl;//Nachkommastellen abschneiden
    zahl = tmp;
    zahl = zahl / pow(10,genauigkeit);//pow == Potenzfuntion

    //umwandeln:
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return returnstring;
}

QString double_to_qstring(double zahl)
{
    QString msg = QString::number(zahl, 'f', 6);//6 sorgt für 6 Nachkommastellen
    return msg;
}
