#ifndef TODO_H
#define TODO_H





#define PROGRAMMVERSION     "2.2018.06.24"

/*
----------Aktuell in Arbeit:
-->Umwandeln Kreis in Bohrung
-->Umwandeln Bohrung in Kreis
-->Umwandeln Bohrung in KTA
-->Umwandeln KTA in Bohrung





-->BUG: DXF-Import fehlerhaft wenn CAD Blöcke aus FreeCAD enthällt?
    ->noch nicht genauer heraus gefunden wodurch der Import-Fehler verursacht wurde



----------Ideen für neue Dialoge:
-->Dialog Include
-->Dialog Bearbeitung spiegeln
-->Dialog Bearbeitung drehen




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


---------------------------------------------------
QT-Fehlermeldung:
X Error: BadDrawable (invalid Pixmap or Window parameter) 9
  Major opcode: 62 (X_CopyArea)
  Resource id:  0x0
Lösung:
sudo gedit /etc/environment
Add this line
QT_X11_NO_MITSHM=1

------------------------------------------------------
Zur Erinnerung Einlesen deutscher Umlaute auf Linux:
while(!file.atEnd())
{
    tmp += QString::fromUtf8(file.readLine());
}


*/
#endif // TODO_H
