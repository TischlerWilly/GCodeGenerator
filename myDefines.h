#ifndef MYDEFINES_H
#define MYDEFINES_H

#define PFAD_ZUM_PROGRAMMORDNER     "/home/oliver/.gcodegenerator"
#define PFAD_ZU_DEN_WERKZEUGBILDERN "/home/oliver/.gcodegenerator/werkzeugbilder"
#define INI_FILE                    "/home/oliver/.gcodegenerator/konfiguration.ini"
#define WKZ_FILE                    "/home/oliver/.gcodegenerator/werkzeug.ini"
#define WKZ_BILDER_PFAD             "/home/oliver/.gcodegenerator/werkzeugbilder/"
#define DATEIENDUNG_EIGENE          ".ggf"
#define DATEIENDUNG_BACKUP          ".bak_"
#define DATEIENDUNG_GCODE           ".ngc"
#define PROGRAMMNAME                "GCODEGENDERATORGUI"
#define SICHERHEITSABSTAND_WERT     "5"

//-------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Einstellungen:
#define BEGIN_EINSTELLUNGEN "Einstellungen:"
#define ENDE_EINSTELLUNGEN  "---------------------------"

//Parameter:
#define SETTINGS_PFAD_WERKZEUGE     "[Pfad Werkzeugliste]"
#define SETTINGS_ANZ_UNDO_T         "[Anzahl Wiederrufenschritte Programmliste]"
#define SETTINGS_ANZ_UNDO_W         "[Anzahl Wiederrufenschritte Werkzeugliste]"
#define ENDE_ZEILE                  "#ENDE#"

//-------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Dialoge:
#define BEGIN_DIALOGE       "Dialoge:"
#define ENDE_DIALOGE        "---------------------------"

//Dialogarten:
#define PROGRAMMKOPF_DIALOG     ">PRGKOPF:"
#define KOMMENTAR_DIALOG        ">KOMMENTAR:"
#define PROGRAMMENDE_DIALOG     ">PRGENDE:"
#define VARIABLE_DIALOG         ">VARIABLE:"
#define KREISTASCHE_DIALOG      ">KTASCHE:"
#define RECHTECKTASCHE_DIALOG   ">RTASCHE:"
#define WERKZEUG_DIALOG         ">WERKZEUG:"
#define FRAESERAUFRUF_DIALOG    ">FAUFR:"
#define FRAESERGERADE_DIALOG    ">FGERADE:"
#define FRAESERBOGEN_DIALOG    ">FBOGEN:"
#define FRAESERABFAHREN_DIALOG    ">FABFA:"
#define LISTENENDE              ">ENDE"
//#define ENDE_ZEILE            "#ENDE#"

//Parameter:
//Parameter müssen immer zwischen [ und ] definiert sein
#define ANFAHRTYP           "[ANT]"
#define ABFAHRTYP           "[ABT]"
#define ANABFAHRTYP_GARADE          "gerade"
#define ANABFAHRTYP_KREISBOGEN_RE   "bogen von rechts"
#define ANABFAHRTYP_KREISBOGEN_LI   "bogen von links"
#define ANABFAHRTYP_KEIN            "kein"
#define AUSFUEHRBEDINGUNG   "[AFB]"
#define AUSRAEUMEN          "[AUSR]"
#define BAHNRORREKTUR       "[BKO]"
#define BAHNRORREKTUR_links         "links"
#define BAHNRORREKTUR_keine         "keine"
#define BAHNRORREKTUR_rechts        "rechts"
#define BREITE              "[B]"
#define BEZEICHNUNG         "[BEZ]"
#define BEZUGSPUNKT         "[BEZPUNKT]"
#define BEZUGSPUNKT_UNTEN_LINKS     "1"
#define BEZUGSPUNKT_UNTEN_RECHTS    "2"
#define BEZUGSPUNKT_OBEN_RECHTS     "3"
#define BEZUGSPUNKT_OBEN_LINKS      "4"
#define BEZUGSPUNKT_MITTE           "5"
#define BEZUGSPUNKT_LINKS           "6"
#define BEZUGSPUNKT_RECHTS          "7"
#define BEZUGSPUNKT_OBEN            "8"
#define BEZUGSPUNKT_UNTEN           "9"
#define BEZUGSHOEHE         "[BH]"
#define BOGENRICHTUNG       "[BRICH]"
#define BOGENRICHTUNG_IM_UZS        "uzs"
#define BOGENRICHTUNG_IM_GUZS       "guzs"
#define CAD_BEGIN           "[CAD]"
#define CAD_ENDE            "[CADEND]"
#define CAD_PUNKT                   "{p}"   //x / y
#define CAD_STRECKE                 "{s}"   //x_begin / y_begin / x_end / y_end
#define CAD_BOGEN                   "{b}"   //x_begin / y_begin / x_end / y_end / x_mittelpunkt / y_mittelpunkt
#define DICKE               "[D]"
#define DURCHMESSER         "[DM]"
#define ECKENRUNDENGLOBAL   "[ERG]"
#define VORSCHUB            "[F]"
#define ANFAHRVORSCHUB      "[FAN]"
#define GEGENLAUF           "[GEGL]"
#define KANTENDICKE         "[KD]"
#define KOMMENTAR           "[KOM]"
#define LAENGE              "[L]"
#define MITTELPUNKT_X       "[MPX]"
#define MITTELPUNKT_Y       "[MPY]"
#define MODUS               "[MODUS]"
#define MODUS_PENDE_NULLPUNKT       "nullpunkt"
#define MODUS_PENDE_BENUTZERDEF     "benutzerdefiniert"
#define MODUS_RADIUS                "radius"
#define MODUS_MITTELPUNKT           "mittelpunkt"
#define DREHZAHL            "[N]"
#define SICHERHEITSABSTAND  "[SIA]"
//#define TIEFE               "[TI]"
#define WERT                "[WERT]"
#define WERKZEUG            "[WKZ]"
#define POSITION_X          "[X]"
#define POSITION_Y          "[Y]"
#define POSITION_Z          "[Z]"
#define ZUSTELLUNG          "[ZUST]"
#define TASCHENLAENGE       "[TL]"
#define TASCHENBREITE       "[TB]"
#define TASCHENTIEFE        "[TT]"
#define RADIUS              "[RAD]"
#define WINKEL              "[W]"
#define AUTOMATISCH                 "AUTO"
#define ENDE_EINTRAG        ";"

#define FEHLER              "Fehler"
#define NICHT_DEFINIERT     "ist nicht definiert"


//-------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Werkzeuge:
#define BEGIN_WERKZEUGE     "Werkzeuge:"
#define ENDE_WERKZEUGE      "---------------------------"

//Daten aus EMC2:
#define EMC2_WKZ_Nummer      "T" //tool number, 0-99999 (you can have a large number of tools in inventory)
#define EMC2_WKZ_STECKPLATZ  "P" //pocket number, 1-99999 (tool table has a lower number of entries, currently 56.)
#define EMC2_WKZ_OFFSET_X    "X" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_Y    "Y" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_Z    "Z" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_A    "A" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_B    "B" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_C    "C" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_U    "U" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_V    "V" //tool offset on specified axis - floating-point
#define EMC2_WKZ_OFFSET_W    "W" //tool offset on specified axis - floating-point
#define EMC2_WKZ_DURCHMESSER "D" //tool diameter - floating-point
#define EMC2_WKZ_FRONTWINKEL "I" //front angle (lathe only) - floating-point      //nur für Drehmaschienen
#define EMC2_WKZ_RUECKWINKEL "J" //back angle (lathe only) - floating-point       //nur für Drehmaschienen
#define EMC2_WKZ_RICHTUNG    "Q" //tool orientation (lathe only) - integer, 0-9   //nur für Drehmaschienen
#define EMC2_WKZ_KOMMENTAR   ";" //beginning of comment or remark - text

//interne Daten:
#define WKZ_Nummer          "[wT]" //tool number, 0-99999 (you can have a large number of tools in inventory)
#define WKZ_STECKPLATZ      "[wP]" //pocket number, 1-99999 (tool table has a lower number of entries, currently 56.)
#define WKZ_OFFSET_X        "[wX]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_Y        "[wY]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_Z        "[wZ]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_A        "[wA]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_B        "[wB]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_C        "[wC]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_U        "[wU]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_V        "[wV]" //tool offset on specified axis - floating-point
#define WKZ_OFFSET_W        "[wW]" //tool offset on specified axis - floating-point
#define WKZ_DURCHMESSER     "[wD]" //tool diameter - floating-point
#define WKZ_FRONTWINKEL     "[wI]" //front angle (lathe only) - floating-point      //nur für Drehmaschienen
#define WKZ_RUECKWINKEL     "[wJ]" //back angle (lathe only) - floating-point       //nur für Drehmaschienen
#define WKZ_RICHTUNG        "[wQ]" //tool orientation (lathe only) - integer, 0-9   //nur für Drehmaschienen
#define WKZ_KOMMENTAR       "[wKOM]" //beginning of comment or remark - text
#define WKZ_NAME            "[wNAME]"
#define WKZ_DREHRICHTUNG    "[wDIR]"
#define WKZ_DREHRICHTUNG_LINKS      "links"
#define WKZ_DREHRICHTUNG_RECHTS     "rechts"
#define WKZ_DREHRICHTUNG_UNBEKANNT  "unbekannt"
#define WKZ_NUTZLAENGE      "[wNUTZL]"
#define WKZ_EINTAUCHVORSCHUB "[wFAN]"
#define WKZ_VORSCHUB        "[wF]"
#define WKZ_DREHZAHL        "[wN]"
#define WKZ_ENDE_EINTRAG    ";"


#endif // MYDEFINES_H
