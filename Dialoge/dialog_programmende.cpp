#include "dialog_programmende.h"
#include "ui_dialog_programmende.h"

Dialog_Programmende::Dialog_Programmende(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Programmende)
{
    ui->setupUi(this);
    setModus(MODUS_PENDE_NULLPUNKT);
    ui->pushButton_OK->setDefault(true);
}

Dialog_Programmende::~Dialog_Programmende()
{
    delete ui;
}

QString Dialog_Programmende::dialogDataToString()
{
    QString msg = PROGRAMMENDE_DIALOG ;
    msg += MODUS;
    msg += modusOfThisDialog;
    msg += ENDE_EINTRAG;

    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_pos_x->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_pos_y->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Z;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_pos_z->text());
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ausfuehrbedingung->text());
    msg += ENDE_EINTRAG;
    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Programmende::setModus(QString newModus)
{
    if(newModus == MODUS_PENDE_NULLPUNKT)
    {
        modusOfThisDialog = MODUS_PENDE_NULLPUNKT;
        ui->radioButton_amNullpunkt->setChecked(true);
        ui->radioButton_benutzerdefiniert->setChecked(false);
    }else if(newModus == MODUS_PENDE_BENUTZERDEF)
    {
        modusOfThisDialog = MODUS_PENDE_BENUTZERDEF;
        ui->radioButton_amNullpunkt->setChecked(false);
        ui->radioButton_benutzerdefiniert->setChecked(true);
    }
}

void Dialog_Programmende::on_pushButton_OK_clicked()
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

void Dialog_Programmende::on_pushButton_save_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Programmende::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_Programmende::on_radioButton_amNullpunkt_clicked()
{
    setModus(MODUS_PENDE_NULLPUNKT);
}

void Dialog_Programmende::on_radioButton_benutzerdefiniert_clicked()
{
    setModus(MODUS_PENDE_BENUTZERDEF);
}

void Dialog_Programmende::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    setModus(selektiereEintrag(text, MODUS, ENDE_EINTRAG));
    ui->lineEdit_pos_x->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_pos_y->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_pos_z->setText(selektiereEintrag(text, POSITION_Z, ENDE_EINTRAG));
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_ausfuehrbedingung->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}
