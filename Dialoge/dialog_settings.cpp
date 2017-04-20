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

    this->show();
}
