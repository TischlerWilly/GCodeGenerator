#include "dialog_kommentar.h"
#include "ui_dialog_kommentar.h"

Dialog_Kommentar::Dialog_Kommentar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Kommentar)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
}

Dialog_Kommentar::~Dialog_Kommentar()
{
    delete ui;
}

QString Dialog_Kommentar::dialogDataToString()
{
    QString msg = KOMMENTAR_DIALOG;

    msg += KOMMENTAR;
    msg += ui->lineEdit_Kommentar->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += ui->lineEdit_AFB->text();
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Kommentar::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_Kommentar->setText(selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_AFB->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}

void Dialog_Kommentar::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Kommentar::on_pushButton_OK_clicked()
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

void Dialog_Kommentar::on_pushButton_save_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}
