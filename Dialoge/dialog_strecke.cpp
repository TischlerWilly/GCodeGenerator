#include "dialog_strecke.h"
#include "ui_dialog_strecke.h"

Dialog_strecke::Dialog_strecke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_strecke)
{
    ui->setupUi(this);
}

Dialog_strecke::~Dialog_strecke()
{
    delete ui;
}


void Dialog_strecke::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_strecke::on_pushButton_ok_clicked()
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

void Dialog_strecke::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    strecke sneu(text);
    s = sneu;
    ui->lineEdit_spx->setText(s.startp().x_QString());
    ui->lineEdit_spy->setText(s.startp().y_QString());
    ui->lineEdit_spz->setText(s.startp().z_QString());
    ui->lineEdit_epx->setText(s.endp().x_QString());
    ui->lineEdit_epy->setText(s.endp().y_QString());
    ui->lineEdit_epz->setText(s.endp().z_QString());

    this->show();
}

QString Dialog_strecke::dialogDataToString()
{
    punkt3d p;
    p.set_x(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spx->text().toUpper())));
    p.set_y(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spy->text().toUpper())));
    p.set_z(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spz->text().toUpper())));
    s.set_start(p);
    p.set_x(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epx->text().toUpper())));
    p.set_y(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epy->text().toUpper())));
    p.set_z(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epz->text().toUpper())));
    s.set_ende(p);

    return s.get_text();
}

void Dialog_strecke::getVariablen(QString var)
{
    variablen = var;
}

void Dialog_strecke::show()
{
    this->setVisible(true);
    emit sendBraucheVariablen(STRECKE);
}
