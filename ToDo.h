#ifndef TODO_H
#define TODO_H

/*
----------Aktuell in Arbeit:

-->Default-Vorlagen für Dialoge prüfen:  QString MainWindow::saveConfig()

-->CAD in CAM umwandeln und umgekehrt
  ->fetig: Funktion zum CAD sortieren
            >void programmtext::cad_sortieren(...)
  ->fertig: Funktion zum Umwandeln CAD zu CAM

  ->fertig: Funktion zum Umwandeln CAM zu CAD
            (eine Zeile der Fräsbahn aktiviert zu haben soll reicht,
             das Programm soll dann FAufruf und FAbfahr selbst finden)
  ->Funktion zum Umkehren der Fräs-Richtung
    (eine Zeile der Fräsbahn aktiviert zu haben soll reicht,
     das Programm soll dann FAufruf und FAbfahr selbst finden)

-->Funktion zum verschieben des Startpunktes der Fräsbahn
    (bei geschlossenen Konturen)

-->BUG: DXF-Export fehlerhaft wenn CAD Blöcke aus FreeCAD enthällt




----------Ideen für neue Dialoge:
-->Dialog für das Zapfen-fräsen
    ->Dialog Rtasche erweitern
    ->Dialog Ktasche erweitern
-->Dialog für Vieleck-Taschen
-->Dialog für Vieleckt-Zapfen
-->Dialog Include
-->Dialog Spiegeln
-->Dialog Verschieben
-->Dialog Drehen
-->Ankörnen (mit V-Fräser?)



----------Ideen für neue Funktionen:







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
