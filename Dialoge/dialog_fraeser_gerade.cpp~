#include "dialog_fraeser_gerade.h"
#include "ui_dialog_fraeser_gerade.h"

Dialog_fraeser_gerade::Dialog_fraeser_gerade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fraeser_gerade)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
}

Dialog_fraeser_gerade::~Dialog_fraeser_gerade()
{
    delete ui;
}

void Dialog_fraeser_gerade::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_fraeser_gerade::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_fraeser_gerade::on_pushButton_ok_clicked()
{
    //Infos an MainWindow weitergeben:
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

QString Dialog_fraeser_gerade::dialogDataToString()
{
    QString msg = FRAESERGERADE_DIALOG;
    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_x->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_y->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Z;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_z->text());
    msg += ENDE_EINTRAG;

    msg += RADIUS;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_radius->text());
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_afb->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;

    return msg;
}

void Dialog_fraeser_gerade::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_ende_x->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_ende_y->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_ende_z->setText(selektiereEintrag(text, POSITION_Z, ENDE_EINTRAG));
    ui->lineEdit_radius->setText(selektiereEintrag(text, RADIUS, ENDE_EINTRAG));
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_afb->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}







