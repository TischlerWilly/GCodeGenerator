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
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + PUNKT + TRZ_PA + \
                         p.x_QString() + TRZ_PA + \
                         p.y_QString() + TRZ_PA + \
                         p.z_QString() + TRZ_PA + \
                         p.get_farbe() + TRZ_PA + \
                         p.get_breite_qstring() + TRZ_EL);
}

void geometrietext::add_strecke(strecke s)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + STRECKE + TRZ_PA + \
                         s.startp().x_QString() + TRZ_PA + \
                         s.startp().y_QString() + TRZ_PA + \
                         s.startp().z_QString() + TRZ_PA + \
                         s.endp().x_QString() + TRZ_PA + \
                         s.endp().y_QString() + TRZ_PA + \
                         s.endp().z_QString() + TRZ_PA + \
                         s.get_farbe() + TRZ_PA + \
                         s.get_breite_qstring() + TRZ_PA + \
                         s.get_stil() + TRZ_EL);
}

void geometrietext::add_bogen(bogen b)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + BOGEN + TRZ_PA + \
                         b.start().x_QString() + TRZ_PA + \
                         b.start().y_QString() + TRZ_PA + \
                         b.start().z_QString() + TRZ_PA + \
                         b.ende().x_QString() + TRZ_PA + \
                         b.ende().y_QString() + TRZ_PA + \
                         b.ende().z_QString() + TRZ_PA + \
                         b.rad_qString() + TRZ_PA + \
                         b.im_uzs_QString() + TRZ_PA + \
                         b.mitte().x_QString() + TRZ_PA + \
                         b.mitte().y_QString() + TRZ_PA + \
                         b.get_farbe() + TRZ_PA + \
                         b.get_breite_qstring() + TRZ_PA + \
                         b.get_stil() + TRZ_EL);

}

void geometrietext::add_kreis(kreis k)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + KREIS + TRZ_PA + \
                         k.mitte3d().x_QString() + TRZ_PA + \
                         k.mitte3d().y_QString() + TRZ_PA + \
                         k.mitte3d().z_QString() + TRZ_PA + \
                         k.radius_QString() + TRZ_PA + \
                         k.get_farbe() + TRZ_PA + \
                         k.get_farbe_fuellung() + TRZ_PA + \
                         k.get_breite_qstring() + TRZ_PA + \
                         k.get_stil() + TRZ_EL);
}

void geometrietext::add_zylinder(zylinder z)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + ZYLINDER + TRZ_PA + \
                         z.mitte3d().x_QString() + TRZ_PA + \
                         z.mitte3d().y_QString() + TRZ_PA + \
                         z.mitte3d().z_QString() + TRZ_PA + \
                         z.radius_QString() + TRZ_PA + \
                         z.get_hoehe_qstring() + TRZ_PA + \
                         z.get_farbe() + TRZ_PA + \
                         z.get_farbe_fuellung() + TRZ_PA + \
                         z.get_breite_qstring() + TRZ_PA + \
                         z.get_stil() + TRZ_EL);
}

void geometrietext::add_rechteck(rechteck3d rec)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + RECHTECK3D + TRZ_PA + \
                         rec.bezpunkt_num_qstring() + TRZ_PA + \
                         rec.einfpunkt().x_QString() + TRZ_PA + \
                         rec.einfpunkt().y_QString() + TRZ_PA + \
                         rec.einfpunkt().z_QString() + TRZ_PA + \
                         rec.l_qstring() + TRZ_PA + \
                         rec.b_qstring() + TRZ_PA + \
                         rec.rad_qstring() + TRZ_PA + \
                         rec.drewi_qstring() + TRZ_PA + \
                         rec.get_farbe() + TRZ_PA + \
                         rec.get_farbe_fuellung() + TRZ_PA + \
                         rec.get_breite_qstring() + TRZ_PA + \
                         rec.get_stil() + TRZ_EL);
}

void geometrietext::add_wuerfel(wuerfel w)
{
    QString alter_inhalt = text.zeile(aktuelle_zeile);
    text.zeile_ersaetzen(aktuelle_zeile, alter_inhalt + WUERFEL + TRZ_PA + \
                         w.bezpunkt_num_qstring() + TRZ_PA + \
                         w.einfpunkt().x_QString() + TRZ_PA + \
                         w.einfpunkt().y_QString() + TRZ_PA + \
                         w.einfpunkt().z_QString() + TRZ_PA + \
                         w.l_qstring() + TRZ_PA + \
                         w.b_qstring() + TRZ_PA + \
                         w.rad_qstring() + TRZ_PA + \
                         w.drewi_qstring() + TRZ_PA + \
                         w.get_hoehe_qstring() + TRZ_PA + \
                         w.get_farbe() + TRZ_PA + \
                         w.get_farbe_fuellung() + TRZ_PA + \
                         w.get_breite_qstring() + TRZ_PA + \
                         w.get_stil() + TRZ_EL);
}

void geometrietext::set_text(QString neuer_text)
{
    text.clear();
    text.set_text(neuer_text);
    aktuelle_zeile=1;
}
