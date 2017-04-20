#ifndef DIALOG_VARIABLENWERTE_ANZEIGEN_H
#define DIALOG_VARIABLENWERTE_ANZEIGEN_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneKlassen/text_zeilenweise.h"
#include "../eigeneKlassen/wenndannsonst.h"
#include "../eigeneFunktionen/text.h"


namespace Ui {
class Dialog_variablenwerte_anzeigen;
}

class Dialog_variablenwerte_anzeigen : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_variablenwerte_anzeigen(QWidget *parent = 0);
    ~Dialog_variablenwerte_anzeigen();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_variablenwerte_anzeigen *ui;

signals:
    void brauche_variablen();

public slots:
    void slot_bekomme_variablen(text_zeilenweise variablen);

};

#endif // DIALOG_VARIABLENWERTE_ANZEIGEN_H
