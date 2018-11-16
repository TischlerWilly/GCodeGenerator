#include "dialog_schleifenende.h"
#include "ui_dialog_schleifenende.h"

Dialog_Schleifenende::Dialog_Schleifenende(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Schleifenende)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
}

Dialog_Schleifenende::~Dialog_Schleifenende()
{
    delete ui;
}

QString Dialog_Schleifenende::dialogDataToString()
{
    QString msg = SCHLEIFENENDE_DIALOG ;
    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bez->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += ui->lineEdit_afb->text();
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Schleifenende::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_Schleifenende::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Schleifenende::on_pushButton_ok_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    if(openToModifyData)
    {
        openToModifyData = false;
        emit sendDialogDataModifyed(msg);
    } else
    {
        emit sendDialogData(msg);
    }
}

void Dialog_Schleifenende::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_bez->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_afb->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}
