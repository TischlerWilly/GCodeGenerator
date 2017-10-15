#ifndef TODO_H
#define TODO_H

/*
-->Funktion Trimmen vervollständigen (eigene Funktionen geometrie.cpp):
    ->Trimmen Geraden zu Bögen
            >hier bei nächsten Mal weiter machen
    ->Trimmen Bogen zu Bogen

-->Fräsernahmen automatisch mit in der Programmliste anzeigen bei Aufruf Fräser

-->neue Funktion: in den Voreinstellungen die Möglichkeit bereitstellen eine Maschine zu definieren mit Anschlägen


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
-->Import von anderen (programmeigenen) CNC-Programmen, mit Auswahl der zu importierenden Zeilen


----------Bereich Ändern:


----------Bereich Vorschaufenster:


----------Bereich G-Code:
###    -->Ausgabe von Klammern ( und ) aus Textfeldern in G-Code-Erzeugung unterdrücken,
###        damit diese in Programminternen Kommentaren genutzt werden können
###        ->bei neu hinzukommenden Dialogen jeweils daran denken



----------Bereich Werkzeug:
###    -->AUTO-Werte möglich machen
###        ist umgesetzt, muss jedoch in der Funktion
###            void MainWindow::on_actionGCode_berechnen_triggered()
###        und der Funktion
###            void programmtext::aktualisiere_klartext_und_var()
###        berücksichtigt werden wenn neue Elemente hinzukommen






*/
#endif // TODO_H
