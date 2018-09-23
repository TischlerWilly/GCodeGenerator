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
    QString msg = QString::number(zahl, 'f', 3);//3 sorgt für 3 Nachkommastellen
    return msg.toStdString();
}

QString float_to_qstring(float zahl)
{
    QString msg = QString::number(zahl, 'f', 3);//3 sorgt für 3 Nachkommastellen
    return msg;
}

std::string double_to_string(double zahl)
{
    QString msg = QString::number(zahl, 'f', 6);//6 sorgt für 6 Nachkommastellen
    return msg.toStdString();
}

QString double_to_qstring(double zahl)
{
    QString msg = QString::number(zahl, 'f', 6);//6 sorgt für 6 Nachkommastellen
    return msg;
}
