#ifndef RECHTECK_H
#define RECHTECK_H


using namespace std;

#ifndef UNTEN_LINKS
#define UNTEN_LINKS     1
#endif
#ifndef UNTEN_RECHTS
#define UNTEN_RECHTS    2
#endif
#ifndef OBEN_RECHTS
#define OBEN_RECHTS     3
#endif
#ifndef OBEN_LINKS
#define OBEN_LINKS      4
#endif
#ifndef MITTE
#define MITTE           5
#endif
#ifndef LINKS
#define LINKS           6
#endif
#ifndef RECHTS
#define RECHTS          7
#endif
#ifndef OBEN
#define OBEN            8
#endif
#ifndef UNTEN
#define UNTEN           9
#endif

#include "../eigeneStruncts/punkt.h"

class rechteck
{
    public:
        rechteck();
        virtual ~rechteck();

        void set_laenge(float neue_laenge);
        void set_breite(float neue_breite);
        void set_einfuegepunkt(float x, float y);
        void set_einfuegepunkt (punkt neuer_einfuegepunkt);
        void set_bezugspunkt_nummer(int neuer_bezugspunkt);

        float get_laenge();
        float get_breite();
        float get_einfuegepunkt_x();
        float get_einfuegepunkt_y();
        punkt get_einfuegepunkt();
        int get_bezugspunkt_nummer();
        float get_bezugspunkt_x();
        float get_bezugspunkt_y();
        punkt get_bezugspunkt();
        float get_eckpunkt_unten_links_x();
        float get_eckpunkt_unten_links_y();
        punkt get_eckpunkt_unten_links();
        float get_eckpunkt_unten_rechts_x();
        float get_eckpunkt_unten_rechts_y();
        punkt get_eckpunkt_unten_rechts();
        float get_eckpunkt_oben_rechts_x();
        float get_eckpunkt_oben_rechts_y();
        punkt get_eckpunkt_oben_rechts();
        float get_eckpunkt_oben_links_x();
        float get_eckpunkt_oben_links_y();
        punkt get_eckpunkt_oben_links();
        float get_mittelpunkt_x();
        float get_mittelpunkt_y();
        punkt get_mittelpunkt();

        float get_eckpunkt_links_mitte_x();
        float get_eckpunkt_links_mitte_y();
        punkt get_eckpunkt_links_mitte();
        float get_eckpunkt_rechts_mitte_x();
        float get_eckpunkt_rechts_mitte_y();
        punkt get_eckpunkt_rechts_mitte();
        float get_eckpunkt_oben_mitte_x();
        float get_eckpunkt_oben_mitte_y();
        punkt get_eckpunkt_oben_mitte();
        float get_eckpunkt_unten_mitte_x();
        float get_eckpunkt_unten_mitte_y();
        punkt get_eckpunkt_unten_mitte();
    protected:

    private:
        float laenge;
        float breite;
        int bezugspunkt;
        punkt einfuegepunkt;
        punkt eckpunkt_unten_links;
        punkt eckpunkt_unten_rechts;
        punkt eckpunkt_oben_rechts;
        punkt eckpunkt_oben_links;
        punkt mittelpunkt;
        punkt eckpunkt_links_mitte;
        punkt eckpunkt_rechts_mitte;
        punkt eckpunkt_oben_mitte;
        punkt eckpunkt_unten_mitte;

};

#endif // RECHTECK_H
