#include "dialog_fraeser_abfahren.h"
#include "ui_dialog_fraeser_abfahren.h"

Dialog_fraeser_abfahren::Dialog_fraeser_abfahren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fraeser_abfahren)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
}

Dialog_fraeser_abfahren::~Dialog_fraeser_abfahren()
{
    delete ui;
}

void Dialog_fraeser_abfahren::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_fraeser_abfahren::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_fraeser_abfahren::on_pushButton_ok_clicked()
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

QString Dialog_fraeser_abfahren::dialogDataToString()
{
    QString msg = FRAESERABFAHREN_DIALOG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_afb->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_fraeser_abfahren::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_afb->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}
