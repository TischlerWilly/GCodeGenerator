#include "dialog_fraeser_aufruf.h"
#include "ui_dialog_fraeser_aufruf.h"

Dialog_Fraeser_Aufruf::Dialog_Fraeser_Aufruf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Fraeser_Aufruf)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_ok->setDefault(true);
    ui->comboBox__bahnkor->addItem(BAHNRORREKTUR_links);
    ui->comboBox__bahnkor->addItem(BAHNRORREKTUR_keine);
    ui->comboBox__bahnkor->addItem(BAHNRORREKTUR_rechts);

    ui->comboBox_anftyp->addItem(ANABFAHRTYP_KEIN);
    ui->comboBox_anftyp->addItem(ANABFAHRTYP_GARADE);
    ui->comboBox_anftyp->addItem(ANABFAHRTYP_KREISBOGEN_LI);
    ui->comboBox_anftyp->addItem(ANABFAHRTYP_KREISBOGEN_RE);

    ui->comboBox_abftyp->addItem(ANABFAHRTYP_KEIN);
    ui->comboBox_abftyp->addItem(ANABFAHRTYP_GARADE);
    ui->comboBox_abftyp->addItem(ANABFAHRTYP_KREISBOGEN_LI);
    ui->comboBox_abftyp->addItem(ANABFAHRTYP_KREISBOGEN_RE);
}

Dialog_Fraeser_Aufruf::~Dialog_Fraeser_Aufruf()
{
    delete ui;
}



void Dialog_Fraeser_Aufruf::on_pushButton_abbrechen_clicked()
{
    this->close();
}

void Dialog_Fraeser_Aufruf::on_pushButton_speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Fraeser_Aufruf::on_pushButton_ok_clicked()
{
    //Infos an MainWindow weitergeben:
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

QString Dialog_Fraeser_Aufruf::dialogDataToString()
{
    QString msg = FRAESERAUFRUF_DIALOG;
    msg += WKZ_NAME;
    msg += ui->comboBox_werkzeug->currentText();
    msg += ENDE_EINTRAG;

    msg += BAHNRORREKTUR;
    msg += ui->comboBox__bahnkor->currentText();
    msg += ENDE_EINTRAG;

    msg += POSITION_X;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_startx->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Y;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_starty->text());
    msg += ENDE_EINTRAG;

    msg += POSITION_Z;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_startz->text());
    msg += ENDE_EINTRAG;

    msg += ECKENRUNDENGLOBAL;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_eckruglob->text());
    msg += ENDE_EINTRAG;

    msg += KANTENDICKE;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_kantdi->text());
    msg += ENDE_EINTRAG;

    msg += ANFAHRVORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_eintvors->text());
    msg += ENDE_EINTRAG;

    msg += VORSCHUB;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_vorschub->text());
    msg += ENDE_EINTRAG;

    msg += DREHZAHL;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_drehzahl->text());
    msg += ENDE_EINTRAG;

    msg += ANFAHRTYP;
    msg += ui->comboBox_anftyp->currentText();
    msg += ENDE_EINTRAG;

    msg += ABFAHRTYP;
    msg += ui->comboBox_abftyp->currentText();
    msg += ENDE_EINTRAG;

    msg += KOMMENTAR;
    msg += ui->lineEdit_komment->text();
    msg += ENDE_EINTRAG;

    msg += BEZEICHNUNG;
    msg += ui->lineEdit_bezeichn->text();
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_ausfbed->text());
    msg += ENDE_EINTRAG;

    msg += WKZ_DURCHMESSER;
    msg += text_mitte(w.get_werkzeug(ui->comboBox_werkzeug->currentText()), WKZ_DURCHMESSER, WKZ_ENDE_EINTRAG);
    msg += ENDE_EINTRAG;

    msg += ZUSTELLUNG;
    msg += ui->lineEdit_zustellung->text();
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Fraeser_Aufruf::getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen, werkzeug wkz)
{
    w = wkz;
    openToModifyData = openToChangeData;
    ui->comboBox_werkzeug->clear();
    ui->comboBox_werkzeug->addItems(WerkzeugNamen);
    QString tmp_werkzeug = selektiereEintrag(text, WKZ_NAME, WKZ_ENDE_EINTRAG);
    int index;
    index = ui->comboBox_werkzeug->findText(tmp_werkzeug);
    if(index == -1)//wenn das angegebene Werkzeug nicht in der Werkzeugliste gefunden wird
    {
        if(tmp_werkzeug.contains("???")) //Wenn 2. Durchlauf und Fräsername schon mit ??? ergänzt ist
        {
            ui->comboBox_werkzeug->addItem(tmp_werkzeug);
            index = ui->comboBox_werkzeug->findText(tmp_werkzeug);
            ui->comboBox_werkzeug->setCurrentIndex(index);
        }else
        {
            ui->comboBox_werkzeug->addItem(tmp_werkzeug + " ???");
            index = ui->comboBox_werkzeug->findText(tmp_werkzeug + " ???");
            ui->comboBox_werkzeug->setCurrentIndex(index);
        }
    }else
    {
        ui->comboBox_werkzeug->setCurrentIndex(index);
    }

    QString tmp = selektiereEintrag(text, BAHNRORREKTUR, ENDE_EINTRAG);
    index = ui->comboBox__bahnkor->findText(tmp);
    ui->comboBox__bahnkor->setCurrentIndex(index);

    ui->lineEdit_startx->setText(selektiereEintrag(text, POSITION_X, ENDE_EINTRAG));
    ui->lineEdit_starty->setText(selektiereEintrag(text, POSITION_Y, ENDE_EINTRAG));
    ui->lineEdit_startz->setText(selektiereEintrag(text, POSITION_Z, ENDE_EINTRAG));
    ui->lineEdit_eckruglob->setText(selektiereEintrag(text, ECKENRUNDENGLOBAL, ENDE_EINTRAG));
    ui->lineEdit_kantdi->setText(selektiereEintrag(text, KANTENDICKE, ENDE_EINTRAG));
    ui->lineEdit_eintvors->setText(selektiereEintrag(text, ANFAHRVORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_vorschub->setText(selektiereEintrag(text, VORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_drehzahl->setText(selektiereEintrag(text, DREHZAHL, ENDE_EINTRAG));
    ui->lineEdit_zustellung->setText(selektiereEintrag(text, ZUSTELLUNG, ENDE_EINTRAG));

    tmp = selektiereEintrag(text, ANFAHRTYP, ENDE_EINTRAG);
    index = ui->comboBox_anftyp->findText(tmp);
    ui->comboBox_anftyp->setCurrentIndex(index);

    tmp = selektiereEintrag(text, ABFAHRTYP, ENDE_EINTRAG);
    index = ui->comboBox_abftyp->findText(tmp);
    ui->comboBox_abftyp->setCurrentIndex(index);

    ui->lineEdit_komment->setText(selektiereEintrag(text, KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_bezeichn->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_ausfbed->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));

    tmp = w.get_werkzeug(tmp_werkzeug);
    QPixmap pix(QDir::homePath() + WKZ_BILDER_PFAD + text_mitte(tmp, WKZ_Nummer, ENDE_EINTRAG)+".jpg");
    ui->label_bild_fraeser->setPixmap(pix);
    ui->label_bild_fraeser->setScaledContents(true);//Bild skallieren

    this->show();
}

void Dialog_Fraeser_Aufruf::on_comboBox_werkzeug_currentIndexChanged(const QString &arg1)
{
    QString tmp = w.get_werkzeug(arg1);
    QPixmap pix(QDir::homePath() + WKZ_BILDER_PFAD + text_mitte(tmp, WKZ_Nummer, ENDE_EINTRAG)+".jpg");
    ui->label_bild_fraeser->setPixmap(pix);
    ui->label_bild_fraeser->setScaledContents(true);//Bild skallieren
}
