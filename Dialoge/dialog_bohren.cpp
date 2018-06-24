#include "dialog_bohren.h"
#include "ui_dialog_bohren.h"

Dialog_bohren::Dialog_bohren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_bohren)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_wkz->currentText(), BOHREN_DIALOG);
}

Dialog_bohren::~Dialog_bohren()
{
    delete ui;
}

void Dialog_bohren::show()
{
    this->setVisible(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_wkz->currentText(), BOHREN_DIALOG);
}

QString Dialog_bohren::dialogDataToString()
{
    QString msg = BOHREN_DIALOG ;
    msg += WKZ_NAME;
    msg += ui->comboBox_wkz->currentText();
    msg += ENDE_EINTRAG;

    msg += WKZ_DURCHMESSER;
    msg += ui->label_wkz_dm->text();
    msg += ENDE_EINTRAG;

    msg += DURCHMESSER;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_dm->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_x->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_y->text());
    msg += ENDE_EINTRAG;

    msg += BOHRTIEFE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_boti->text());
    msg += ENDE_EINTRAG;

    msg += ANBOHRTI;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_anboti->text());
    msg += ENDE_EINTRAG;

    msg += RESTBOHRTI;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_reboma->text());
    msg += ENDE_EINTRAG;

    msg += ZUSTELLUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_zust->text());
    msg += ENDE_EINTRAG;

    msg += ANFAHRVORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_anbovors->text());
    msg += ENDE_EINTRAG;

    msg += VORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_bovors->text());
    msg += ENDE_EINTRAG;

    msg += DREHZAHL;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_drehzahl->text());
    msg += ENDE_EINTRAG;

    msg += KOMMENTAR;
    msg += ui->lineEdit_kom->text();
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bez->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_afb->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_bohren::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_bohren::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_bohren::on_pushButton_ok_clicked()
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

void Dialog_bohren::getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen)
{
    openToModifyData = openToChangeData;
    ui->comboBox_wkz->clear();
    ui->comboBox_wkz->addItems(WerkzeugNamen);
    QString tmp_werkzeug = selektiereEintrag(text, WKZ_NAME, WKZ_ENDE_EINTRAG);
    int index;
    index = ui->comboBox_wkz->findText(tmp_werkzeug);
    if(index == -1)//wenn das angegebene Werkzeug nicht in der Werkzeugliste gefunden wird
    {
        if(tmp_werkzeug.contains("???")) //Wenn 2. Durchlauf und Fräsername schon mit ??? ergänzt ist
        {
            ui->comboBox_wkz->addItem(tmp_werkzeug);
            index = ui->comboBox_wkz->findText(tmp_werkzeug);
            ui->comboBox_wkz->setCurrentIndex(index);
        }else
        {
            ui->comboBox_wkz->addItem(tmp_werkzeug + " ???");
            index = ui->comboBox_wkz->findText(tmp_werkzeug + " ???");
            ui->comboBox_wkz->setCurrentIndex(index);
        }
    }else
    {
        ui->comboBox_wkz->setCurrentIndex(index);
    }

    ui->lineEdit_x->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_y->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_dm->setText(selektiereEintrag(text, DURCHMESSER, ENDE_EINTRAG));
    ui->lineEdit_boti->setText(selektiereEintrag(text, BOHRTIEFE, ENDE_EINTRAG));
    ui->lineEdit_anboti->setText(selektiereEintrag(text, ANBOHRTI, ENDE_EINTRAG));
    ui->lineEdit_reboma->setText(selektiereEintrag(text, RESTBOHRTI, ENDE_EINTRAG));
    ui->lineEdit_zust->setText(selektiereEintrag(text, ZUSTELLUNG, ENDE_EINTRAG));
    ui->lineEdit_anbovors->setText(selektiereEintrag(text, ANFAHRVORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_bovors->setText(selektiereEintrag(text, VORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_drehzahl->setText(selektiereEintrag(text, DREHZAHL, ENDE_EINTRAG));
    ui->lineEdit_kom->setText(selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_bez->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_afb->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));

    this->show();
}

void Dialog_bohren::on_tabWidget_currentChanged(int index)
{
    if(index == 2) //2 = Werkzeug
    {
        emit signalBraucheWerkzeugdaten(ui->comboBox_wkz->currentText(), BOHREN_DIALOG);
    }
}

void Dialog_bohren::getWerkzeugdaten(QString Werkzeugdaten)
{
    ui->label_wkz_nummer_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_Nummer, WKZ_ENDE_EINTRAG));
    ui->label_wkz_name_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_NAME, WKZ_ENDE_EINTRAG));
    ui->label_wkz_drehri_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DREHRICHTUNG, WKZ_ENDE_EINTRAG));
    ui->label_wkz_dm_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG));
    ui->lineEdit_dm->setText(selektiereEintrag(Werkzeugdaten, WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG));
    ui->label_wkz_nutzl_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_NUTZLAENGE, WKZ_ENDE_EINTRAG));
    ui->label_wkz_kom_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_KOMMENTAR, WKZ_ENDE_EINTRAG));
    ui->label_wkz_fan_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_EINTAUCHVORSCHUB, WKZ_ENDE_EINTRAG));
    ui->label_wkz_f_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_VORSCHUB, WKZ_ENDE_EINTRAG));
    ui->label_wkz_n_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DREHZAHL, WKZ_ENDE_EINTRAG));

}

void Dialog_bohren::on_comboBox_wkz_currentIndexChanged()
{
    emit signalBraucheWerkzeugdaten(ui->comboBox_wkz->currentText(), BOHREN_DIALOG);
}


