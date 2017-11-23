#ifndef TODO_H
#define TODO_H

/*
----------Aktuell in Arbeit:
-->Import von DXF-Dateien aus LibreCAD
    ->void MainWindow::on_import_DXF_triggered()
    ->void programmtext::aktualisiere_klartext_var_geo()
    ->void programmtext::aktualisiere_anzeigetext()

    ->nur Linien importieren die einer festgelegten Klasse zugewiesen sind

    ->Vorab nach einem Nullpunkt in der Importdatei suchen
        >wenn ein Punkt, und nur ein Punkt mit der Klasse "WST_Nullpunkt" beim Import dabei ist
        >dann alle Koordinaten der linien mit dem Nullpunkt gegenrechnen



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
-->Ankörnen (mit V-Fräser?)



----------Ideen für neue Funktionen:
-->in den Voreinstellungen die Möglichkeit bereitstellen eine Maschine zu definieren mit Anschlägen





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
