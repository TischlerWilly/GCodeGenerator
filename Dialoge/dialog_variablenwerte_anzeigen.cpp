#include "dialog_variablenwerte_anzeigen.h"
#include "ui_dialog_variablenwerte_anzeigen.h"

Dialog_variablenwerte_anzeigen::Dialog_variablenwerte_anzeigen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_variablenwerte_anzeigen)
{
    ui->setupUi(this);
    this->setWindowTitle("Variablenwerte anzeigen");
}

Dialog_variablenwerte_anzeigen::~Dialog_variablenwerte_anzeigen()
{
    delete ui;
}

void Dialog_variablenwerte_anzeigen::on_pushButton_clicked()
{
    emit brauche_variablen();
}

void Dialog_variablenwerte_anzeigen::slot_bekomme_variablen(text_zeilenweise variablen)
{
    int zeile_int = ui->lineEdit_zeilennummer->text().toInt();
    if(zeile_int == 0)
    {
        return;
    }
    if(zeile_int > (int)variablen.zeilenanzahl())
    {
        return;
    }
    QString tmp = variablen.zeile(zeile_int);
    QString name = "["+ui->lineEdit_bez->text()+"]";
    name = buchstaben_alle_GROSS_schreiben(name);
    tmp = text_mitte(tmp, name, ENDE_EINTRAG);
    ui->label_wert->setText(tmp);
}
