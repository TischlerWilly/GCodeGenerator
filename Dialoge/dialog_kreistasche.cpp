#include "dialog_kreistasche.h"
#include "ui_dialog_kreistasche.h"

Dialog_Kreistasche::Dialog_Kreistasche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Kreistasche)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), KREISTASCHE_DIALOG);
}

Dialog_Kreistasche::~Dialog_Kreistasche()
{
    delete ui;
}

QString Dialog_Kreistasche::dialogDataToString()
{
    QString msg = KREISTASCHE_DIALOG ;
    msg += WKZ_NAME;
    msg += ui->comboBox_Werkzeug->currentText();
    msg += ENDE_EINTRAG;

    msg += WKZ_DURCHMESSER;
    msg += ui->label_wkz_Durchmesser_wert->text();
    msg += ENDE_EINTRAG;

    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_posX->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_posY->text());
    msg += ENDE_EINTRAG;

    msg += DURCHMESSER;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Taschendurchmesser->text());
    msg += ENDE_EINTRAG;

    msg += TASCHENTIEFE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Taschentiefe->text());
    msg += ENDE_EINTRAG;

    msg += ZUSTELLUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Zustellung->text());
    msg += ENDE_EINTRAG;

    msg += AUSRAEUMEN;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Ausraeumen->text());
    msg += ENDE_EINTRAG;

    msg += GEGENLAUF;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Gegenlauf->text());
    msg += ENDE_EINTRAG;

    msg += ANFAHRVORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Anfahrvorschub->text());
    msg += ENDE_EINTRAG;

    msg += VORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Vorschub->text());
    msg += ENDE_EINTRAG;

    msg += DREHZAHL;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Drehzahl->text());
    msg += ENDE_EINTRAG;

    msg += KOMMENTAR;
    msg += ui->lineEdit_Kommentar->text();
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichnung->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Ausfuehbedingung->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Kreistasche::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Kreistasche::on_pushButton_Speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Kreistasche::on_pushButton_OK_clicked()
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

void Dialog_Kreistasche::getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen)
{
    openToModifyData = openToChangeData;
    ui->comboBox_Werkzeug->clear();
    ui->comboBox_Werkzeug->addItems(WerkzeugNamen);
    QString tmp_werkzeug = selektiereEintrag(text, WKZ_NAME, WKZ_ENDE_EINTRAG);
    int index;
    index = ui->comboBox_Werkzeug->findText(tmp_werkzeug);
    if(index == -1)//wenn das angegebene Werkzeug nicht in der Werkzeugliste gefunden wird
    {
        if(tmp_werkzeug.contains("???")) //Wenn 2. Durchlauf und Fräsername schon mit ??? ergänzt ist
        {
            ui->comboBox_Werkzeug->addItem(tmp_werkzeug);
            index = ui->comboBox_Werkzeug->findText(tmp_werkzeug);
            ui->comboBox_Werkzeug->setCurrentIndex(index);
        }else
        {
            ui->comboBox_Werkzeug->addItem(tmp_werkzeug + " ???");
            index = ui->comboBox_Werkzeug->findText(tmp_werkzeug + " ???");
            ui->comboBox_Werkzeug->setCurrentIndex(index);
        }
    }else
    {
        ui->comboBox_Werkzeug->setCurrentIndex(index);
    }

    ui->lineEdit_posX->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_posY->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_Taschendurchmesser->setText(selektiereEintrag(text, DURCHMESSER, ENDE_EINTRAG));
    ui->lineEdit_Taschentiefe->setText(selektiereEintrag(text, TASCHENTIEFE, ENDE_EINTRAG));
    ui->lineEdit_Zustellung->setText(selektiereEintrag(text, ZUSTELLUNG, ENDE_EINTRAG));
    ui->lineEdit_Ausraeumen->setText(selektiereEintrag(text, AUSRAEUMEN, ENDE_EINTRAG));
    ui->lineEdit_Gegenlauf->setText(selektiereEintrag(text, GEGENLAUF, ENDE_EINTRAG));
    ui->lineEdit_Anfahrvorschub->setText(selektiereEintrag(text, ANFAHRVORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Vorschub->setText(selektiereEintrag(text, VORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Drehzahl->setText(selektiereEintrag(text, DREHZAHL, ENDE_EINTRAG));
    ui->lineEdit_Kommentar->setText(selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_Ausfuehbedingung->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));

    this->show();
}


void Dialog_Kreistasche::on_tabWidget_currentChanged(int index)
{
    if(index == 2) //2 = Werkzeug
    {
        emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), KREISTASCHE_DIALOG);
    }
}

void Dialog_Kreistasche::getWerkzeugdaten(QString Werkzeugdaten)
{
    ui->label_wkz_Nummer_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_Nummer, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Name_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_NAME, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Drehrichtung_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DREHRICHTUNG, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Durchmesser_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Nutzlaenge_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_NUTZLAENGE, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Kommentar_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_KOMMENTAR, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Eintauschvorschub_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_EINTAUCHVORSCHUB, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Vorschub_XY_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_VORSCHUB, WKZ_ENDE_EINTRAG));
    ui->label_wkz_Drehzahl_wert->setText(selektiereEintrag(Werkzeugdaten, WKZ_DREHZAHL, WKZ_ENDE_EINTRAG));
}

void Dialog_Kreistasche::on_comboBox_Werkzeug_currentIndexChanged()
{
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), KREISTASCHE_DIALOG);
}

void Dialog_Kreistasche::show()
{
    this->setVisible(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), KREISTASCHE_DIALOG);
}
