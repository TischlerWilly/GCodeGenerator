#ifndef TODO_H
#define TODO_H

/*
-->ERG bei Aufruf Fräser bislang nicht mit * (nicht automatisch in Variablen aufgenommen)
-->WKZ-DM berücksichtigen bei Darstellung Kreistasche

-->Beim Ausblenden von mehreren Fräserbahnen gleichzeitig muss noch die Fehlermeldung deaktiviert werden
   solange die Zeilen einzeln ausgeblendet werden.

-->Klasse Programmtext:
   ->min_x, min_y, max_x, max_y anhand von Geotext berechnen lassen

-->Programmpfade automatisch auf den angemeldeten Benutzer setzen
   (Quelltextanpassung vor compilierung entfallen lassen)

-->Klasse Programmtext
    ->Funktion void programmtext::aktualisiere_klartext_var_geo():
      >Abfahrweg Fräser noch programmieren


-->neue Funktion: in den Voreinstellungen die Möglichkeit beritstellen eine Maschine zu definieren mit Anschlägen



----------Ideen für neue Dialoge:
-->Dialog für das Zapfen-fräsen
    ->Dialog Rtasche erweitern
    ->Dialog Ktasche erweitern
-->Dialog für Vieleck-Taschen
-->Dialog für Vieleckt-Zapfen
-->Dialog Include
-->Dialog Spiegeln
-->Dialog Verschieben
-->Dialgo Drehen


----------Ideen für neue Funktionen:
-->Zuletz geöffnete Dateien




----------Bereich Ändern:



----------Bereich Vorschaufenster:
-->Anzeigen der neuen Dialoge möglich machen
    ->Fräseraufruf
    ->gerade Fräsbahn
    ->runde Fräsbahn


----------Bereich G-Code:
    -->Ausgabe von Klammern ( und ) aus Textfeldern in G-Code-Erzeugung unterdrücken,
        damit diese in Programminternen Kommentaren genutzt werden können
        ->bei neu hinzukommenden Dialogen jeweils daran denken
-->Ausgabe der neuen Dialoge möglich machen
    ->Fräseraufruf
    ->gerade Fräsbahn
    ->runde Fräsbahn


----------Bereich Werkzeug:
    -->AUTO-Werte möglich machen
        ist umgesetzt, muss jedoch in der Funktion
            void MainWindow::on_actionGCode_berechnen_triggered()
        und der Funktion
            void programmtext::aktualisiere_klartext_und_var()
        berücksichtigt werden






*/
#endif // TODO_H
