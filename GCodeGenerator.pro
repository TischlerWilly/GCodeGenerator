#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T13:17:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GCodeGenerator
TEMPLATE = app


SOURCES += \
    mainwindow.cpp \
    main.cpp \
    Dialoge/dialog_werkzeug.cpp \
    Dialoge/dialog_variablenwerte_anzeigen.cpp \
    Dialoge/dialog_variable.cpp \
    Dialoge/dialog_settings.cpp \
    Dialoge/dialog_rechtecktasche.cpp \
    Dialoge/dialog_programmkopf.cpp \
    Dialoge/dialog_programmende.cpp \
    Dialoge/dialog_kreistasche.cpp \
    Dialoge/dialog_kommentar.cpp \
    Dialoge/dialog_fraeser_gerade.cpp \
    Dialoge/dialog_fraeser_bogen.cpp \
    Dialoge/dialog_fraeser_aufruf.cpp \
    Dialoge/dialog_fraeser_abfahren.cpp \
    eigeneFunktionen/myfunktion.cpp \
    eigeneKlassen/werkzeug.cpp \
    eigeneKlassen/wenndannsonst.cpp \
    eigeneKlassen/vorschau.cpp \
    eigeneKlassen/undo_redo_wkz.cpp \
    eigeneKlassen/undo_redo.cpp \
    eigeneKlassen/text_zeilenweise.cpp \
    eigeneKlassen/rechtecktasche.cpp \
    eigeneKlassen/rechteck.cpp \
    eigeneKlassen/programmtext.cpp \
    eigeneKlassen/formel.cpp \
    eigeneFunktionen/geometrie.cpp \
    eigeneFunktionen/umwandeln.cpp \
    eigeneFunktionen/text.cpp \
    eigeneFunktionen/runden.cpp \
    eigeneKlassen/geometrietext.cpp \
    eigeneKlassen/punkt3d.cpp \
    eigeneKlassen/strecke.cpp \
    eigeneKlassen/bogen.cpp \
    eigeneKlassen/punkt2d.cpp \
    Dialoge/dialog_programmlisten.cpp \
    eigeneKlassen/kreis.cpp \
    eigeneKlassen/darstellungsatribute.cpp \
    eigeneKlassen/zylinder.cpp \
    eigeneKlassen/rechteck3d.cpp \
    eigeneKlassen/wuerfel.cpp \
    eigeneKlassen/tabelle.cpp

HEADERS  += \
    mainwindow.h \
    Dialoge/dialog_werkzeug.h \
    Dialoge/dialog_variablenwerte_anzeigen.h \
    Dialoge/dialog_variable.h \
    Dialoge/dialog_settings.h \
    Dialoge/dialog_rechtecktasche.h \
    Dialoge/dialog_programmkopf.h \
    Dialoge/dialog_programmende.h \
    Dialoge/dialog_kreistasche.h \
    Dialoge/dialog_kommentar.h \
    Dialoge/dialog_fraeser_gerade.h \
    Dialoge/dialog_fraeser_bogen.h \
    Dialoge/dialog_fraeser_aufruf.h \
    Dialoge/dialog_fraeser_abfahren.h \
    eigeneFunktionen/myfunktion.h \
    eigeneKlassen/werkzeug.h \
    eigeneKlassen/wenndannsonst.h \
    eigeneKlassen/vorschau.h \
    eigeneKlassen/undo_redo_wkz.h \
    eigeneKlassen/undo_redo.h \
    eigeneKlassen/text_zeilenweise.h \
    eigeneKlassen/rechtecktasche.h \
    eigeneKlassen/rechteck.h \
    eigeneKlassen/programmtext.h \
    eigeneKlassen/formel.h \
    eigeneStruncts/punkt.h \
    myDefines.h \
    eigeneFunktionen/geometrie.h \
    eigeneFunktionen/umwandeln.h \
    eigeneFunktionen/text.h \
    eigeneFunktionen/runden.h \
    eigeneMakros/makro_geometrie.h \
    ToDo.h \
    eigeneKlassen/geometrietext.h \
    eigeneDefines/defines_geometrie.h \
    eigeneKlassen/punkt3d.h \
    eigeneKlassen/strecke.h \
    eigeneKlassen/bogen.h \
    eigeneKlassen/punkt2d.h \
    Dialoge/dialog_programmlisten.h \
    eigeneKlassen/kreis.h \
    eigeneKlassen/darstellungsatribute.h \
    eigeneKlassen/zylinder.h \
    eigeneKlassen/rechteck3d.h \
    eigeneKlassen/wuerfel.h \
    eigeneKlassen/tabelle.h

FORMS    += \
    mainwindow.ui \
    Dialoge/dialog_werkzeug.ui \
    Dialoge/dialog_variablenwerte_anzeigen.ui \
    Dialoge/dialog_variable.ui \
    Dialoge/dialog_settings.ui \
    Dialoge/dialog_rechtecktasche.ui \
    Dialoge/dialog_programmkopf.ui \
    Dialoge/dialog_programmende.ui \
    Dialoge/dialog_kreistasche.ui \
    Dialoge/dialog_kommentar.ui \
    Dialoge/dialog_fraeser_gerade.ui \
    Dialoge/dialog_fraeser_bogen.ui \
    Dialoge/dialog_fraeser_aufruf.ui \
    Dialoge/dialog_fraeser_abfahren.ui \
    Dialoge/dialog_programmlisten.ui
