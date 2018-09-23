#ifndef RECHTECKTASCHE_H
#define RECHTECKTASCHE_H

#include <iostream>
#include <string>
#include "../eigeneFunktionen/geometrie.h"
#include "../eigeneFunktionen/umwandeln.h"
#include "../eigeneFunktionen/runden.h"
#include "../eigeneKlassen/rechteck.h"

using namespace std;
/*
#define UNTEN_LINKS     1
#define UNTEN_RECHTS    2
#define OBEN_RECHTS     3
#define OBEN_LINKS      4
#define MITTE           5
*/


class rechtecktasche : public rechteck
{
    public:
        rechtecktasche();
        virtual ~rechtecktasche();

        void set_tiefe(float neue_tiefe);
        int set_zustellmass(float neues_zustellmass);
        int set_radius_fraeser(float neuer_radius);
        int set_durchmesser_fraeser(float neuer_durchmesser);
        int set_radius_taschenecken(float neuer_radius);
        int set_sicherheitsabstand(float neuer_abstand);
        void set_bezugshoehe(float neue_hoehe);
        void set_ausraeumen(bool ja_ausraemen);
        void set_vorschubgeschwindigkeit(int f);
        void set_anfahrvorschub(int f);
        void set_drehwinkel(float neuer_winkel);
        void set_fraesbahn_in_uhrzeigersinn(bool ist_im_urhzeigersinn);
        void set_anz_nachkommastellen(int anz_neu);
        inline void set_fraeser_kabo(bool kabo)
        {
            fraeser_kabo = kabo;
        }

        float get_tiefe();
        float get_zustellmass();
        float get_radius_fraeser();
        float get_durchmesser_fraeser();
        float get_radius_taschenecken();
        float get_sicherheitsabstand();
        float get_bezugshoehe();
        bool get_ausraemen_Wert();
        rechteck get_rechteck();
        int get_vorschubgeschwindigkeit();
        int get_anfahrvorschub();
        float get_drehwinkel();
        bool get_fraesbahn_im_uhrzeigersinn();
        int get_anz_nachkommastellen();
        string get_gcode();
    protected:
        string get_gcode_ausraumen(rechteck r, float radius, float tiefe_vor_eintauchen, float tiefe_nach_eintauchen);
        string get_rechteckbahn_UZS(rechteck r, float radius, float tiefe_vor_eintauchen, float tiefe_nach_eintauchen);//im Uhrzeigersinn
        string get_rechteckbahn_GUZS(rechteck r, float radius, float tiefe_vor_eintauchen, float tiefe_nach_eintauchen);//im Gegen-Uhrzeigersinn

    private:
        float tiefe;
        float zustellmass;
        float durchmesser_freaser;
        float radius_freaser;
        float radius_taschenecken;
        float sicherheitsabstand;
        float bezugshoehe;
        bool ausraeumen;
        int vorschubgeschwindigkeit;
        int anfahrvorschub;
        float drehwinkel;
        bool fraesbahn_im_uhrzeigersinn;
        int anz_nachkommastellen;
        bool fraeser_kabo;


};

#endif // RECHTECKTASCHE_H
