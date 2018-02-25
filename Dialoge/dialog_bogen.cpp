#include "dialog_bogen.h"
#include "ui_dialog_bogen.h"

Dialog_Bogen::Dialog_Bogen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Bogen)
{
    ui->setupUi(this);
}

Dialog_Bogen::~Dialog_Bogen()
{
    delete ui;
}

void Dialog_Bogen::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_Bogen::on_pushButton_ok_clicked()
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

void Dialog_Bogen::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    bogen bneu(text);
    b = bneu;
    ui->lineEdit_spx->setText(b.start().x_QString());
    ui->lineEdit_spy->setText(b.start().y_QString());
    ui->lineEdit_spz->setText(b.start().z_QString());
    ui->lineEdit_epx->setText(b.ende().x_QString());
    ui->lineEdit_epy->setText(b.ende().y_QString());
    ui->lineEdit_epz->setText(b.ende().z_QString());
    ui->lineEdit_rad->setText(b.rad_qString());

    if(b.im_uzs())
    {
        ui->radioButton_uzs->setChecked(true);
    }else
    {
        ui->radioButton_guzs->setChecked(true);
    }

    this->show();
}

QString Dialog_Bogen::dialogDataToString()
{
    punkt3d p;
    p.set_x(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spx->text().toUpper())));
    p.set_y(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spy->text().toUpper())));
    p.set_z(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_spz->text().toUpper())));
    b.set_startpunkt(p);
    p.set_x(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epx->text().toUpper())));
    p.set_y(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epy->text().toUpper())));
    p.set_z(ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_epz->text().toUpper())));
    b.set_endpunkt(p);
    bool ist_im_uzs;
    if(ui->radioButton_uzs->isChecked())
    {
        ist_im_uzs = true;
    }else
    {
        ist_im_uzs = false;
    }
    QString rad = (ausdruck_auswerten(variablen_durch_werte_ersetzten(variablen, ui->lineEdit_rad->text().toUpper())));
    b.set_radius(rad.toDouble(), ist_im_uzs);

    return b.get_text();
}

void Dialog_Bogen::show()
{
    this->setVisible(true);
    emit sendBraucheVariablen(BOGEN);
}

void Dialog_Bogen::getVariablen(QString var)
{
    variablen = var;
}


