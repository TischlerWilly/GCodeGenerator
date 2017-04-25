#include "geometrietext.h"

geometrietext::geometrietext()
{
    clear();
}

void geometrietext::clear()
{
    text.clear();
    zeilenvorschub();
}

void geometrietext::zeilenvorschub()
{
    text.zeilen_anhaengen(" ");
    aktuelle_zeile = text.zeilenanzahl();
}

void geometrietext::add_punkt(punkt3d p)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + PUNKT + \
                         p.x_QString() + TRZ_PA + \
                         p.y_QString() + TRZ_PA + \
                         p.z_QString() + TRZ_EL);
}

void geometrietext::add_strecke(strecke s)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + STRECKE + \
                         s.startp().x_QString() + TRZ_PA + \
                         s.startp().y_QString() + TRZ_PA + \
                         s.startp().z_QString() + TRZ_PA + \
                         s.endp().x_QString() + TRZ_PA + \
                         s.endp().y_QString() + TRZ_PA + \
                         s.endp().z_QString() + TRZ_EL);
}

void geometrietext::add_bogen(bogen b)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + BOGEN + \
                         b.start().x_QString() + TRZ_PA + \
                         b.start().y_QString() + TRZ_PA + \
                         b.start().z_QString() + TRZ_PA + \
                         b.ende().x_QString() + TRZ_PA + \
                         b.ende().y_QString() + TRZ_PA + \
                         b.ende().z_QString() + TRZ_PA + \
                         b.rad_qString() + TRZ_PA + \
                         b.im_uzs_QString() + TRZ_EL);
}

void geometrietext::add_kreis(kreis k)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + KREIS + \
                         k.mitte3d().x_QString() + TRZ_PA + \
                         k.mitte3d().y_QString() + TRZ_PA + \
                         k.mitte3d().z_QString() + TRZ_PA + \
                         k.radius_QString() + TRZ_PA + \
                         k.ist_ausgefuellt_QString() + TRZ_EL);
}
