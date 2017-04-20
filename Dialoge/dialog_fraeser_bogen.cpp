#include "dialog_fraeser_bogen.h"
#include "ui_dialog_fraeser_bogen.h"

Dialog_fraeser_bogen::Dialog_fraeser_bogen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fraeser_bogen)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
}

Dialog_fraeser_bogen::~Dialog_fraeser_bogen()
{
    delete ui;
}

void Dialog_fraeser_bogen::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_fraeser_bogen::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_fraeser_bogen::on_pushButton_ok_clicked()
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

QString Dialog_fraeser_bogen::dialogDataToString()
{
    QString msg = FRAESERBOGEN_DIALOG;
    msg += BOGENRICHTUNG;
    if(ui->radioButton_im_UZS->isChecked())
    {
        msg += BOGENRICHTUNG_IM_UZS;
    }else if(ui->radioButton_gegen_UZS->isChecked())
    {
        msg += BOGENRICHTUNG_IM_GUZS;
    }
    msg += ENDE_EINTRAG;

    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_x->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_y->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Z;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ende_z->text());
    msg += ENDE_EINTRAG;

    msg += MODUS;
    if(ui->radioButton_radius->isChecked())
    {
        msg += MODUS_RADIUS;
    }else if(ui->radioButton_mittelpunkt->isChecked())
    {
        msg += MODUS_MITTELPUNKT;
    }
    msg += ENDE_EINTRAG;

    msg += RADIUS;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_radius->text());
    msg += ENDE_EINTRAG;

    msg += MITTELPUNKT_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_mittelpunkt_x->text());
    msg += ENDE_EINTRAG;

    msg += MITTELPUNKT_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_mittelpunkt_y->text());
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ausfbed->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;

    return msg;
}

void Dialog_fraeser_bogen::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    QString tmp;

    tmp = selektiereEintrag(text, BOGENRICHTUNG, ENDE_EINTRAG);
    if(tmp == BOGENRICHTUNG_IM_UZS)
    {
        ui->radioButton_im_UZS->setChecked(true);
    }else
    {
        ui->radioButton_gegen_UZS->setChecked(true);
    }
    ui->lineEdit_ende_x->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_ende_y->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_ende_z->setText(selektiereEintrag(text, POSITION_Z, ENDE_EINTRAG));

    tmp = selektiereEintrag(text, MODUS, ENDE_EINTRAG);
    if(tmp == MODUS_RADIUS)
    {
        ui->radioButton_radius->setChecked(true);
    }else
    {
        ui->radioButton_mittelpunkt->setChecked(true);
    }
    ui->lineEdit_radius->setText(selektiereEintrag(text, RADIUS, ENDE_EINTRAG));
    ui->lineEdit_mittelpunkt_x->setText(selektiereEintrag(text, MITTELPUNKT_X, ENDE_EINTRAG));
    ui->lineEdit_mittelpunkt_y->setText(selektiereEintrag(text, MITTELPUNKT_Y, ENDE_EINTRAG));
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_ausfbed->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}
