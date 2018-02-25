#include "dialog_kreis.h"
#include "ui_dialog_kreis.h"

Dialog_Kreis::Dialog_Kreis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Kreis)
{
    ui->setupUi(this);
}

Dialog_Kreis::~Dialog_Kreis()
{
    delete ui;
}

void Dialog_Kreis::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Kreis::on_pushButton_OK_clicked()
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

void Dialog_Kreis::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    kreis kneu(text);
    k = kneu;
    ui->lineEdit_x->setText(k.mitte3d().x_QString());
    ui->lineEdit_y->setText(k.mitte3d().y_QString());
    ui->lineEdit_z->setText(k.mitte3d().z_QString());
    ui->lineEdit_r->setText(k.radius_QString());

    this->show();
}

QString Dialog_Kreis::dialogDataToString()
{
    punkt3d mipu;
    mipu.set_x(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_x->text().toUpper())));
    mipu.set_y(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_y->text().toUpper())));
    mipu.set_z(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_z->text().toUpper())));
    k.set_mittelpunkt(mipu);
    k.set_radius(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_r->text().toUpper())));

    return k.get_text();
}

void Dialog_Kreis::show()
{
    this->setVisible(true);
    emit sendBraucheVariablen(KREIS);
}

void Dialog_Kreis::getVariablen(QString var)
{
    variablen = var;
}
