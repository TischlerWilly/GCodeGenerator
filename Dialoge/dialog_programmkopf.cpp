#include "dialog_programmkopf.h"
#include "ui_dialog_programmkopf.h"

Dialog_Programmkopf::Dialog_Programmkopf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Programmkopf)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
}

Dialog_Programmkopf::~Dialog_Programmkopf()
{
    delete ui;
}

QString Dialog_Programmkopf::dialogDataToString()
{
    QString msg = PROGRAMMKOPF_DIALOG ;
    msg += LAENGE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_laenge->text());
    msg += ENDE_EINTRAG;

    msg += BREITE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_breite->text());
    msg += ENDE_EINTRAG;

    msg += DICKE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_dicke->text());
    msg += ENDE_EINTRAG;

    msg += KOMMENTAR;
    msg += ui->lineEdit_kommentar1->text();
    msg += ENDE_EINTRAG;

    msg += SICHERHEITSABSTAND;
    msg += ui->lineEdit_sicherheitsabstand->text();
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit__bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_AFB->text());
    msg += ENDE_EINTRAG;

    msg += VERSATZ_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ax->text());
    msg += ENDE_EINTRAG;

    msg += VERSATZ_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ay->text());
    msg += ENDE_EINTRAG;

    msg += VERSATZ_Z;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_schabl->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Programmkopf::on_pushButton_OK_clicked()
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

void Dialog_Programmkopf::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Programmkopf::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_laenge->setText(selektiereEintrag(text, LAENGE, ENDE_EINTRAG));
    ui->lineEdit_breite->setText(selektiereEintrag(text, BREITE, ENDE_EINTRAG));
    ui->lineEdit_dicke->setText(selektiereEintrag(text, DICKE, ENDE_EINTRAG));
    ui->lineEdit_kommentar1->setText( selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_sicherheitsabstand->setText(selektiereEintrag(text, SICHERHEITSABSTAND, ENDE_EINTRAG));
    ui->lineEdit__bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_AFB->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    ui->lineEdit_ax->setText(selektiereEintrag(text, VERSATZ_X, ENDE_EINTRAG));
    ui->lineEdit_ay->setText(selektiereEintrag(text, VERSATZ_Y, ENDE_EINTRAG));
    ui->lineEdit_schabl->setText(selektiereEintrag(text, VERSATZ_Z, ENDE_EINTRAG));
    this->show();
}

void Dialog_Programmkopf::on_pushButton_save_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}
