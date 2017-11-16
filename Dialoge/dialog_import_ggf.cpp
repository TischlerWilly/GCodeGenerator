#include "dialog_import_ggf.h"
#include "ui_dialog_import_ggf.h"

Dialog_import_ggf::Dialog_import_ggf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_import_ggf)
{
    ui->setupUi(this);

}

Dialog_import_ggf::~Dialog_import_ggf()
{
    delete ui;
}

void Dialog_import_ggf::getText(QString text)
{
    this->show();
    text_zeilenweise tz;
    tz.set_text(text);
    import = tz;

    QListWidgetItem* item[tz.zeilenanzahl()];
    for(uint i = 1; i<=tz.zeilenanzahl() ;i++)
    {
        QString kopf = tz.zeile(i);
        QString rumpf = tz.zeile(i);

        if(kopf.contains(RECHTECKTASCHE_DIALOG))
        {
            kopf = "Rechtecktasche: ";
            rumpf = "L: ";
            rumpf += text_mitte(tz.zeile(i), TASCHENLAENGE, ENDE_EINTRAG);
            rumpf += " / B: ";
            rumpf += text_mitte(tz.zeile(i), TASCHENBREITE, ENDE_EINTRAG);
            rumpf += " / Ti: ";
            rumpf += text_mitte(tz.zeile(i), TASCHENTIEFE, ENDE_EINTRAG);
            rumpf += " / X: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_X, ENDE_EINTRAG);
            rumpf += " / Y: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Y, ENDE_EINTRAG);
            rumpf += " / ";
            rumpf += text_mitte(tz.zeile(i), WKZ_NAME, ENDE_EINTRAG);
        }else if(kopf.contains(KREISTASCHE_DIALOG))
        {
            kopf = "Kreistasche: ";
            rumpf = "DM: ";
            rumpf += text_mitte(tz.zeile(i), DURCHMESSER, ENDE_EINTRAG);
            rumpf += " / Ti: ";
            rumpf += text_mitte(tz.zeile(i), TASCHENTIEFE, ENDE_EINTRAG);
            rumpf += " / X: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_X, ENDE_EINTRAG);
            rumpf += " / Y: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Y, ENDE_EINTRAG);
            rumpf += " / ";
            rumpf += text_mitte(tz.zeile(i), WKZ_NAME, ENDE_EINTRAG);
        }else if(kopf.contains(KOMMENTAR_DIALOG))
        {
            kopf = "Kommentar: ";
            rumpf = text_mitte(tz.zeile(i), KOMMENTAR, ENDE_EINTRAG);
        }else if(kopf.contains(FRAESERAUFRUF_DIALOG))
        {
            kopf = "Aufruf Fraeser: ";
            rumpf = "X: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_X, ENDE_EINTRAG);
            rumpf += " / Y: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Y, ENDE_EINTRAG);
            rumpf += " / Z: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Z, ENDE_EINTRAG);
            rumpf += " / ";
            rumpf += text_mitte(tz.zeile(i), WKZ_NAME, ENDE_EINTRAG);
        }else if(kopf.contains(FRAESERABFAHREN_DIALOG))
        {
            kopf = "Abfahren Fraeser";
            rumpf = "";
        }else if(kopf.contains(FRAESERGERADE_DIALOG))
        {
            kopf = "Gerade: ";
            rumpf = "X: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_X, ENDE_EINTRAG);
            rumpf += " / Y: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Y, ENDE_EINTRAG);
            rumpf += " / Z: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Z, ENDE_EINTRAG);
        }else if(kopf.contains(FRAESERBOGEN_DIALOG))
        {
            kopf = "Bogen: ";
            rumpf = "X: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_X, ENDE_EINTRAG);
            rumpf += " / Y: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Y, ENDE_EINTRAG);
            rumpf += " / Z: ";
            rumpf += text_mitte(tz.zeile(i), POSITION_Z, ENDE_EINTRAG);
            rumpf += " / Rad: ";
            rumpf += text_mitte(tz.zeile(i), RADIUS, ENDE_EINTRAG);
        }else if(kopf.contains(VARIABLE_DIALOG))
        {
            kopf = "Variable: ";
            rumpf = text_mitte(tz.zeile(i), BEZEICHNUNG, ENDE_EINTRAG);
            rumpf += " = ";
            rumpf += text_mitte(tz.zeile(i), WERT, ENDE_EINTRAG);
        }

        item[i-1] = new QListWidgetItem(kopf + rumpf , ui->listWidget);
        item[i-1]->setFlags(item[i-1]->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item[i-1]->setCheckState(Qt::Unchecked); // AND initialize check state
        ui->listWidget->addItem(item[i-1]);
    }
}

void Dialog_import_ggf::on_pushButton_abbrechen_clicked()
{
    clear();
    this->hide();
}

void Dialog_import_ggf::clear()
{
    ui->listWidget->clear();
}

void Dialog_import_ggf::on_pushButton_import_clicked()
{
    if(import.zeilenanzahl()>=1)
    {
        text_zeilenweise msg;
        for(uint i=1; i<=import.zeilenanzahl() ;i++)
        {
            if(ui->listWidget->item(i-1)->checkState())
            {
                msg.zeile_anhaengen(import.zeile(i));
            }
        }
        if(msg.zeilenanzahl()>=1)
        {
            this->hide();
            clear();
            emit sendData(msg.get_text());
        }else
        {
            QMessageBox mb;
            mb.setText("Sie haben keine Inhalte zum Import augewaelt.");
            mb.exec();
        }
    }else
    {
        QMessageBox mb;
        mb.setText("Es wurden keine Inhalte zum Import gefunden.");
        mb.exec();
    }



}

void Dialog_import_ggf::on_pushButton_alle_clicked()
{
    for(uint i=1; i<=import.zeilenanzahl() ;i++)
    {
        ui->listWidget->item(i-1)->setCheckState(Qt::Checked);
    }
}

void Dialog_import_ggf::on_pushButton_keine_clicked()
{
    for(uint i=1; i<=import.zeilenanzahl() ;i++)
    {
        ui->listWidget->item(i-1)->setCheckState(Qt::Unchecked);
    }
}
