#include "dialog_programmlisten.h"
#include "ui_dialog_programmlisten.h"

Dialog_Programmlisten::Dialog_Programmlisten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Programmlisten)
{
    ui->setupUi(this);
}

Dialog_Programmlisten::~Dialog_Programmlisten()
{
    delete ui;
}

void Dialog_Programmlisten::daten_anzeigen(QString prgtext, QString klartext, \
                                           QString variabel, QString geotext, \
                                           QString fkon)
{
    ui->plainTextEdit_programmtext->setPlainText(prgtext);
    ui->plainTextEdit_klartext->setPlainText(klartext);
    ui->plainTextEdit_variablen->setPlainText(variabel);
    ui->plainTextEdit_geometrietext->setPlainText(geotext);
    ui->plainTextEdit_fkon->setPlainText(fkon);
    this->show();
}
