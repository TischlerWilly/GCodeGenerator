#include "dialog_rechtecktasche.h"
#include "ui_dialog_rechtecktasche.h"

Dialog_Rechtecktasche::Dialog_Rechtecktasche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Rechtecktasche)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), KREISTASCHE_DIALOG);
}

Dialog_Rechtecktasche::~Dialog_Rechtecktasche()
{
    delete ui;
}

QString Dialog_Rechtecktasche::dialogDataToString()
{
    QString msg = RECHTECKTASCHE_DIALOG ;
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

    msg += TASCHENLAENGE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_laenge->text());
    msg += ENDE_EINTRAG;

    msg += TASCHENBREITE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_breite->text());
    msg += ENDE_EINTRAG;

    msg += TASCHENTIEFE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_tiefe->text());
    msg += ENDE_EINTRAG;

    msg += RADIUS;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_radius->text());
    msg += ENDE_EINTRAG;

    msg += ZUSTELLUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Zustellung->text());
    msg += ENDE_EINTRAG;

    msg += GEGENLAUF;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Gegenlauf->text());
    msg += ENDE_EINTRAG;

    msg += WINKEL;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_winkel->text());
    msg += ENDE_EINTRAG;

    msg += AUSRAEUMEN;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ausraeumen->text());
    msg += ENDE_EINTRAG;

    msg += ANFAHRVORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Eintauchvorschub->text());
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
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Ausfuehrbedingung->text());
    msg += ENDE_EINTRAG;

    msg += BEZUGSPUNKT;
    if(ui->radioButton_unten_links->isChecked())
    {
        msg += BEZUGSPUNKT_UNTEN_LINKS;
    }else if(ui->radioButton_unten_rechts->isChecked())
    {
        msg += BEZUGSPUNKT_UNTEN_RECHTS;
    }else if(ui->radioButton_oben_rechts->isChecked())
    {
        msg += BEZUGSPUNKT_OBEN_RECHTS;
    }else if(ui->radioButton_oben_links->isChecked())
    {
        msg += BEZUGSPUNKT_OBEN_LINKS;
    }else if(ui->radioButton_mitte->isChecked())
    {
        msg += BEZUGSPUNKT_MITTE;
    }else if(ui->radioButton_links->isChecked())
    {
        msg += BEZUGSPUNKT_LINKS;
    }else if(ui->radioButton_rechts->isChecked())
    {
        msg += BEZUGSPUNKT_RECHTS;
    }else if(ui->radioButton_oben->isChecked())
    {
        msg += BEZUGSPUNKT_OBEN;
    }else if(ui->radioButton_unten->isChecked())
    {
        msg += BEZUGSPUNKT_UNTEN;
    }
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Rechtecktasche::on_pushButton_OK_clicked()
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

void Dialog_Rechtecktasche::on_pushButton_Speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Rechtecktasche::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Rechtecktasche::on_tabWidget_currentChanged(int index)
{
    if(index == 3) //3 = Werkzeug
    {
        emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), RECHTECKTASCHE_DIALOG);
    }
}

void Dialog_Rechtecktasche::getWerkzeugdaten(QString Werkzeugdaten)
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

void Dialog_Rechtecktasche::getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen)
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
    ui->lineEdit_laenge->setText(selektiereEintrag(text, TASCHENLAENGE, ENDE_EINTRAG));
    ui->lineEdit_breite->setText(selektiereEintrag(text, TASCHENBREITE, ENDE_EINTRAG));
    ui->lineEdit_tiefe->setText(selektiereEintrag(text, TASCHENTIEFE, ENDE_EINTRAG));
    ui->lineEdit_radius->setText(selektiereEintrag(text, RADIUS, ENDE_EINTRAG));
    ui->lineEdit_Zustellung->setText(selektiereEintrag(text, ZUSTELLUNG, ENDE_EINTRAG));
    ui->lineEdit_Gegenlauf->setText(selektiereEintrag(text, GEGENLAUF, ENDE_EINTRAG));
    ui->lineEdit_winkel->setText(selektiereEintrag(text, WINKEL, ENDE_EINTRAG));
    ui->lineEdit_ausraeumen->setText(selektiereEintrag(text, AUSRAEUMEN, ENDE_EINTRAG));
    ui->lineEdit_Eintauchvorschub->setText(selektiereEintrag(text, ANFAHRVORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Vorschub->setText(selektiereEintrag(text, VORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Drehzahl->setText(selektiereEintrag(text, DREHZAHL, ENDE_EINTRAG));
    ui->lineEdit_Kommentar->setText(selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_Ausfuehrbedingung->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));

    QString bezugspunkt = selektiereEintrag(text, BEZUGSPUNKT, ENDE_EINTRAG);
    if(bezugspunkt == BEZUGSPUNKT_UNTEN_LINKS)
    {
        ui->radioButton_unten_links->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_UNTEN_RECHTS)
    {
        ui->radioButton_unten_rechts->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_OBEN_RECHTS)
    {
        ui->radioButton_oben_rechts->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_OBEN_LINKS)
    {
        ui->radioButton_oben_links->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_MITTE)
    {
        ui->radioButton_mitte->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_LINKS)
    {
        ui->radioButton_links->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_RECHTS)
    {
        ui->radioButton_rechts->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_OBEN)
    {
        ui->radioButton_oben->setChecked(true);
    }else if(bezugspunkt == BEZUGSPUNKT_UNTEN)
    {
        ui->radioButton_unten->setChecked(true);
    }

    this->show();
}

void Dialog_Rechtecktasche::show()
{
    this->setVisible(true);
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), RECHTECKTASCHE_DIALOG);
}

void Dialog_Rechtecktasche::on_comboBox_Werkzeug_currentIndexChanged()
{
    emit signalBraucheWerkzeugdaten(ui->comboBox_Werkzeug->currentText(), RECHTECKTASCHE_DIALOG);
}
