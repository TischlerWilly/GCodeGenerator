#include "dialog_settings.h"
#include "ui_dialog_settings.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

dialog_settings::dialog_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_settings)
{
    ui->setupUi(this);
    openToModifyData = false;
    QString msg = "Pfad Werkzeugtabelle von ";
    msg += PROGRAMMNAME;
    msg += ":\n";
    msg += QDir::homePath();
    msg += WKZ_FILE;
    ui->label_werkzeugliste_pfad->setText(msg);
    msg = "Pfad Konfigurationsdatei von ";
    msg += PROGRAMMNAME;
    msg += ":\n";
    msg += QDir::homePath();
    msg += INI_FILE;
    ui->label_konfig_pfad->setText(msg);
}

dialog_settings::~dialog_settings()
{
    delete ui;
}

void dialog_settings::on_pushButton_cancel_clicked()
{
    this->close();
}

void dialog_settings::on_pushButton_save_clicked()
{
    this->hide();
    QString msg;
    msg =  SETTINGS_PFAD_WERKZEUGE;
    msg += ui->lineEdit_tooltable->text();
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_ANZ_UNDO_T;
    msg += ui->spinBox_anz_undo_t->text();
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_ANZ_UNDO_W;
    msg += ui->spinBox_anz_undo_w->text();
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_DXF_KLASSE_WSTNP;
    msg += ui->lineEdit_dxf_wstnp->text();
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_DXF_KLASSE_GEO;
    msg += ui->lineEdit_dxf_klasse->text();
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_DXF_KLASSE_GEO_BEACHTEN;
    if(ui->checkBox_dxf_klasse->isChecked())
    {
        msg += "ja";
    }else
    {
        msg += "nein";
    }
    msg += ENDE_ZEILE;
    msg += "\n";
    msg += SETTINGS_FKON_BERECHNEN;
    if(ui->checkBox_fkon_berechnen->isChecked())
    {
        msg += "ja";
    }else
    {
        msg += "nein";
    }
    msg += ENDE_ZEILE;
    msg += "\n";
    emit signalSaveConfig(msg);
}

void dialog_settings::on_pushButton_tooltable_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Waehle Werkzeug-Datei"), "/home/oliver/linuxcnc/configs", tr("ini Dateien (*.tbl)"));
    ui->lineEdit_tooltable->setText(fileName);
}

void dialog_settings::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;

    QString tmp = selektiereEintrag(text, SETTINGS_PFAD_WERKZEUGE, ENDE_ZEILE);
    if(tmp != NICHT_DEFINIERT)
    {
        ui->lineEdit_tooltable->setText(tmp);
    }else
    {
        ui->lineEdit_tooltable->setText("Bitte noch den Pfad angeben");
    }
    tmp = selektiereEintrag(text, SETTINGS_ANZ_UNDO_T, ENDE_ZEILE);
    ui->spinBox_anz_undo_t->setValue(tmp.toInt());
    tmp = selektiereEintrag(text, SETTINGS_ANZ_UNDO_W, ENDE_ZEILE);
    ui->spinBox_anz_undo_w->setValue(tmp.toInt());
    tmp = selektiereEintrag(text, SETTINGS_DXF_KLASSE_WSTNP, ENDE_ZEILE);
    ui->lineEdit_dxf_wstnp->setText(tmp);
    tmp = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO, ENDE_ZEILE);
    ui->lineEdit_dxf_klasse->setText(tmp);
    tmp = selektiereEintrag(text, SETTINGS_DXF_KLASSE_GEO_BEACHTEN, ENDE_ZEILE);
    if(tmp == "ja")
    {
        ui->checkBox_dxf_klasse->setChecked(true);
    }else
    {
        ui->checkBox_dxf_klasse->setChecked(false);
    }
    tmp = selektiereEintrag(text, SETTINGS_FKON_BERECHNEN, ENDE_ZEILE);
    if(tmp == "ja")
    {
        ui->checkBox_fkon_berechnen->setChecked(true);
    }else
    {
        ui->checkBox_fkon_berechnen->setChecked(false);
    }

    this->show();
}


