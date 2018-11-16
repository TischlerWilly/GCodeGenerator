#include "dialog_schleife_linear.h"
#include "ui_dialog_schleife_linear.h"

Dialog_Schleife_linear::Dialog_Schleife_linear(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Schleife_linear)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
}

Dialog_Schleife_linear::~Dialog_Schleife_linear()
{
    delete ui;
}

QString Dialog_Schleife_linear::dialogDataToString()
{
    QString msg = SCHLEIFELINEAR_DIALOG ;
    msg += ANZ_X;
    msg += int_to_qstring(ui->spinBox_anzx->value());
    msg += ENDE_EINTRAG;

    msg += ANZ_Y;
    msg += int_to_qstring(ui->spinBox_anzy->value());
    msg += ENDE_EINTRAG;

    msg += VERSATZ_X;
    msg += ui->lineEdit_versatzx->text();
    msg += ENDE_EINTRAG;

    msg += VERSATZ_Y;
    msg += ui->lineEdit_versatzy->text();
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bez->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += ui->lineEdit_afb->text();
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Schleife_linear::on_pushButton_ok_clicked()
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

void Dialog_Schleife_linear::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Schleife_linear::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_Schleife_linear::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->spinBox_anzx->setValue(selektiereEintrag(text, ANZ_X, ENDE_EINTRAG).toInt());
    ui->spinBox_anzy->setValue(selektiereEintrag(text, ANZ_Y, ENDE_EINTRAG).toInt());
    ui->lineEdit_versatzx->setText(selektiereEintrag(text, VERSATZ_X, ENDE_EINTRAG));
    ui->lineEdit_versatzy->setText(selektiereEintrag(text, VERSATZ_Y, ENDE_EINTRAG));
    ui->lineEdit_bez->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_afb->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}

