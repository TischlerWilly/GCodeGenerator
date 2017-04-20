#include"umwandeln.h"


std::string int_to_string(int zahl)
{
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return returnstring;
}

std::string float_to_string(float zahl)
{
    std::string returnstring;
    std::stringstream ss;
    ss << zahl;
    returnstring = ss.str();
    return returnstring;
}

