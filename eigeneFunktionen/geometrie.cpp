#include "geometrie.h"

punkt drehen(punkt drehzentrum, punkt alter_punkt, float drehwinkel, bool drehrichtung_im_uhrzeigersinn)
{
    if(drehwinkel == 0)
    {
        return alter_punkt;
    }else{
        punkt neuer_punkt;
        if(drehrichtung_im_uhrzeigersinn == true)
        {
            drehwinkel = -drehwinkel;
        }
        neuer_punkt.x = drehzentrum.x + (alter_punkt.x - drehzentrum.x)*cos_d(drehwinkel) - (alter_punkt.y - drehzentrum.y)*sin_d(drehwinkel);
        neuer_punkt.y = drehzentrum.y + (alter_punkt.x - drehzentrum.x)*sin_d(drehwinkel) + (alter_punkt.y - drehzentrum.y)*cos_d(drehwinkel);
        return neuer_punkt;
    }
}

punkt drehen_ij(punkt drehzentrum, float drehwinkel, bool drehrichtung_im_uhrzeigersinn, punkt bezugspunkt_ij, punkt punkt_ij)
{
    if(drehwinkel == 0)
    {
        return punkt_ij;
    }else{
        bezugspunkt_ij = drehen(drehzentrum, bezugspunkt_ij, drehwinkel, drehrichtung_im_uhrzeigersinn);
        punkt p;
        p.x = 0;
        p.y = 0;
        punkt_ij = drehen(p, punkt_ij, drehwinkel, drehrichtung_im_uhrzeigersinn);
        return punkt_ij;
    }
}

punkt kreismittelpunkt(punkt start, punkt ende, float radius, bool im_uzs)
{
    punkt m;
    /*
    (start.x - m.x)² + (start.y - m.x)² = (r)²
    (ende.x  - m.x)² + (ende.y  - m.x)² = (r)²

    Beispielwerte:
    m.x     = 27,0161
    m.y     =  9,7903
    start.x =  5
    start.y =  6
    ende.x  = 20
    ende.y  = 31
    r       = 22,34

    Gleichung 1:
    (5 - m.x)² + (6 - m.y)² = (22,34)²
    (5 - m.x)² + (6 - m.y)² = 499,0756

    Gleichung 2:
    (20 - m.x)² + (31 - m.y)² = (22,34)²
    (20 - m.x)² + (31 - m.y)² = 499,0756


    I : ( 5 - m.x)² + ( 6 - m.y)² = 499,0756
    II: (20 - m.x)² + (31 - m.y)² = 499,0756

    I : ( 5 - m.x)² + ( 6 - m.y)² = 499,0756
    I : ( 5 - m.x)*( 5 - m.x) + ( 6 - m.y)*( 6 - m.y) = 499,0756
        -> ist zweite Binomische Formel!
            (a+b)*(a+b) = a² + 2ab + b²
            (a-b)*(a-b) = a² - 2ab + b²
            (a+b)*(a-b) = a² - b²
    I : 5² - 2*5*m.x + m.x²  + 6² - 2*6*m.y + m.y² = 499,0756
    I : 25 - 10*m.x  + m.x²  + 36 - 12*m.y  + m.y² = 499,0756 |-25 -36
    I :    - 10*m.x  + m.x²       - 12*m.y  + m.y² = 438,0756

    II:20² - 2*20*m.x + m.x* + 31² - 2*31*m.y + m.y² = 499,0756
    II:400 - 40*m.x   + m.x² + 961 - 62*m.y   + m.y² = 499,0756 |-400 -961
    II:    - 40*m.x   + m.x²       - 62*m.y   + m.y² = -861,9244

    I : -10*m.x + m.x² - 12*m.y + m.y² = 438,0756
    II: -40*m.x + m.x² - 62*m.y + m.y² = -861,9244


    I : 25 - 10*x  + x²  + 36 - 12*y  + y² = 499,0756
    II:400 - 40*x   + x² + 961 - 62*y   + y² = 499,0756
    25 - 10*x  + x²  + 36 - 12*y  + y²   =   400 - 40*x   + x² + 961 - 62*y   + y² |-x² -y²
    25 - 10*x        + 36 - 12*y         =   400 - 40*x        + 961 - 62*y        |-25 -36
       - 10*x             - 12*y         =   400 - 40*x + 961 - 62*y - 61
       - 10x             - 12y         =   -40x - 62y + 1300 |+40x +12y
         30x = 50y +1300 |:10
         3x = 5y +130



    (5 - x)² + (6 - y)² = 499,0756
    (5 - x)² = 499,0756-36+12y-y²
    (5 - x)² = 463,0756 + 12y -y²
    5-x = Wurzel(463,0756 + 12y -y²)
    x=(5-Wurzel(463,0756 + 12y -y²))

    (a-b)*(a-b) = a² - 2ab + b²

    (20 - (5-Wurzel(463,0756 + 12y -y²)) )² + (31 - y)² = 499,0756
    20² - 40*(5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 31² + 2*31y + y²
    400 - 40*(5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 961 + 2*31y + y² = 499,0756
    40*(5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 961 + 2*31y + y² = 99,0756
    40*(5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 961 + 2*31y + y² = 99,0756
    40*(5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 2*31y + y² = -861,9244 |:40
    (5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + 2*31y + y² = -21,54811 |:62
    (5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + y + y² = -21,54811:62

    (5-Wurzel(463,0756 + 12y -y²)) + (5-Wurzel(463,0756 + 12y -y²))² + y + y² = -21,54811:62
    (5-Wurzel(463,0756 + 12y -y²)) + 25-10*Wurzel(463,0756 + 12y -y²)+(463,0756 + 12y -y²)+y+y² = -21,54811:62
    (5-Wurzel(463,0756 + 12y -y²)) + 25-10*Wurzel(463,0756 + 12y -y²)+463,0756 + 12y +y = -21,54811:62
    (5-Wurzel(463,0756 + 12y -y²)) + 25-10*Wurzel(463,0756 + 12y -y²)+463,0756 + 13y = -21,54811:62
    5-Wurzel(463,0756 + 12y -y²) + 25-10*Wurzel(463,0756 + 12y -y²)+463,0756 + 13y = -21,54811:62
    5+25-11*Wurzel(463,0756 + 12y -y²)+463,0756 + 13y = -21,54811:62
    30-11*Wurzel(463,0756 + 12y -y²)+463,0756 + 13y = -21,54811:62
    -11*Wurzel(463,0756 + 12y -y²)+493,0756 + 13y = -21,54811:62
    -11*Wurzel(463,0756 + 12y -y²) +13y +493,0756 = -0,3475501613
    -11*Wurzel(463,0756 + 12y -y²) +13y = 492,7280498387 |:-11
    Wurzel(463,0756 + 12y -y²) +13y = -44,7934590762 |-13y
    Wurzel(463,0756 + 12y -y²) = -44,7934590762 -13y |²
    463,0756 + 12y -y² = 2006,4539760154 -169y |-463,0756
    12y -y² = 1543,3783760154 -169y |-12y
    -y² = 1543,3783760154 -171y |+171y
    -y² + 171y = 1543,3783760154 |*-1
    y² - 171y = -1543,3783760154





    ???????????

    */

    return m;
}

