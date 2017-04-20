#include "dialog_werkzeug.h"
#include "ui_dialog_werkzeug.h"

Dialog_Werkzeug::Dialog_Werkzeug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Werkzeug)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
    ui->comboBox_Drehrichtung->addItem(WKZ_DREHRICHTUNG_LINKS);
    ui->comboBox_Drehrichtung->addItem(WKZ_DREHRICHTUNG_RECHTS);
    ui->comboBox_Drehrichtung->addItem(WKZ_DREHRICHTUNG_UNBEKANNT);    
}

Dialog_Werkzeug::~Dialog_Werkzeug()
{
    delete ui;
}

QString Dialog_Werkzeug::dialogDataToString()
{
    QString msg = WERKZEUG_DIALOG;

    msg += WKZ_NAME;
    msg += ui->lineEdit_Werkzeugname->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_Nummer;
    msg += ui->lineEdit_Werkzeugnummer->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_STECKPLATZ;
    msg += ui->lineEdit_Steckplatz->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_X;
    msg += ui->lineEdit_Offset_X->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_Y;
    msg += ui->lineEdit_Offset_Y->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_Z;
    msg += ui->lineEdit_Offset_Z->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_A;
    msg += ui->lineEdit_Offset_A->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_B;
    msg += ui->lineEdit_Offset_B->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_C;
    msg += ui->lineEdit_Offset_C->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_U;
    msg += ui->lineEdit_Offset_U->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_V;
    msg += ui->lineEdit_Offset_V->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_OFFSET_W;
    msg += ui->lineEdit_Offset_W->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_DURCHMESSER;
    msg += ui->lineEdit_Durchmesser->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_FRONTWINKEL;
    msg += ui->lineEdit_Frontwinkel->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_RUECKWINKEL;
    msg += ui->lineEdit_Rueckwinkel->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_RICHTUNG;
    msg += ui->lineEdit_Richtung->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_KOMMENTAR;
    msg += ui->lineEdit_Kommentar->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_DREHRICHTUNG;
    msg += ui->comboBox_Drehrichtung->currentText();
    msg += ENDE_EINTRAG;

    msg += WKZ_NUTZLAENGE;
    msg += ui->lineEdit__Nutzlaenge->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_EINTAUCHVORSCHUB;
    msg += ui->lineEdit_Eintauchvorschub->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_VORSCHUB;
    msg += ui->lineEdit_Vorschub_XY->text();
    msg += ENDE_EINTRAG;

    msg += WKZ_DREHZAHL;
    msg += ui->lineEdit_Drehzahl->text();
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Werkzeug::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_Werkzeugnummer->setText(selektiereEintrag(text, WKZ_Nummer, ENDE_EINTRAG));
    ui->lineEdit_Steckplatz->setText(selektiereEintrag(text, WKZ_STECKPLATZ, ENDE_EINTRAG));
    ui->lineEdit_Offset_X->setText(selektiereEintrag(text, WKZ_OFFSET_X, ENDE_EINTRAG));
    ui->lineEdit_Offset_Y->setText(selektiereEintrag(text, WKZ_OFFSET_Y, ENDE_EINTRAG));
    ui->lineEdit_Offset_Z->setText(selektiereEintrag(text, WKZ_OFFSET_Z, ENDE_EINTRAG));
    ui->lineEdit_Offset_A->setText(selektiereEintrag(text, WKZ_OFFSET_A, ENDE_EINTRAG));
    ui->lineEdit_Offset_B->setText(selektiereEintrag(text, WKZ_OFFSET_B, ENDE_EINTRAG));
    ui->lineEdit_Offset_C->setText(selektiereEintrag(text, WKZ_OFFSET_C, ENDE_EINTRAG));
    ui->lineEdit_Offset_U->setText(selektiereEintrag(text, WKZ_OFFSET_U, ENDE_EINTRAG));
    ui->lineEdit_Offset_V->setText(selektiereEintrag(text, WKZ_OFFSET_V, ENDE_EINTRAG));
    ui->lineEdit_Offset_W->setText(selektiereEintrag(text, WKZ_OFFSET_W, ENDE_EINTRAG));
    ui->lineEdit_Durchmesser->setText(selektiereEintrag(text, WKZ_DURCHMESSER, ENDE_EINTRAG));
    ui->lineEdit_Frontwinkel->setText(selektiereEintrag(text, WKZ_FRONTWINKEL, ENDE_EINTRAG));
    ui->lineEdit_Rueckwinkel->setText(selektiereEintrag(text, WKZ_RUECKWINKEL, ENDE_EINTRAG));
    ui->lineEdit_Richtung->setText(selektiereEintrag(text, WKZ_RICHTUNG, ENDE_EINTRAG));
    ui->lineEdit_Kommentar->setText(selektiereEintrag(text, WKZ_KOMMENTAR, ENDE_EINTRAG));
    ui->lineEdit_Werkzeugname->setText(selektiereEintrag(text, WKZ_NAME, ENDE_EINTRAG));
    ui->lineEdit__Nutzlaenge->setText(selektiereEintrag(text, WKZ_NUTZLAENGE, ENDE_EINTRAG));
    ui->lineEdit_Eintauchvorschub->setText(selektiereEintrag(text, WKZ_EINTAUCHVORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Vorschub_XY->setText(selektiereEintrag(text, WKZ_VORSCHUB, ENDE_EINTRAG));
    ui->lineEdit_Drehzahl->setText(selektiereEintrag(text, WKZ_DREHZAHL, ENDE_EINTRAG));
    int index;
    index = ui->comboBox_Drehrichtung->findText(selektiereEintrag(text, WKZ_DREHRICHTUNG, ENDE_EINTRAG));
    ui->comboBox_Drehrichtung->setCurrentIndex(index);

    //QPixmap pix("./werkzeugbilder/testbild.jpg");
    QPixmap pix(WKZ_BILDER_PFAD + text_mitte(text, WKZ_Nummer, ENDE_EINTRAG)+".jpg");
    ui->label_bild->setPixmap(pix);
    ui->label_bild->setScaledContents(true);//Bild skallieren

    this->show();
}

void Dialog_Werkzeug::on_pushButton_Abbrechen_clicked()
{
    this->close();
}

void Dialog_Werkzeug::on_pushButton_Speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Werkzeug::on_pushButton_OK_clicked()
{
    QString msg = dialogDataToString();
    QString tmp = text_mitte(msg, WKZ_Nummer, ENDE_EINTRAG);
    if(tmp.isEmpty())
    {
        QMessageBox mb;
        mb.setText("Werkzeugnummer darf nicht leer sein!");
        mb.exec();
        return;
    }else
    {
        QString alte_nummer = tmp;
        int num = tmp.toInt(0, 10);
        tmp = QString::fromStdString(int_to_string(num));
        if(tmp != alte_nummer)
        {
            QMessageBox mb;
            mb.setText("Werkzeugnummer ist ungueltig!\nBitte nur ganze Zahlen verwenden.");
            mb.exec();
            return;
        }
        if(num > 99999)
        {
            QMessageBox mb;
            mb.setText("Werkzeugnummer ist zu gross\nMaximal 99999 ist erlaubt!");
            mb.exec();
            return;
        }
    }
    tmp = text_mitte(msg, WKZ_NAME, ENDE_EINTRAG);
    if(tmp.isEmpty())
    {
        QMessageBox mb;
        mb.setText("Werkzeugname darf nicht leer sein!");
        mb.exec();
        return;
    }
    tmp = text_mitte(msg, WKZ_NUTZLAENGE, ENDE_EINTRAG);
    if(tmp.isEmpty())
    {
        QMessageBox mb;
        mb.setText("Nutzlaenge ist nicht definiert!");
        mb.exec();
        return;
    }
    tmp = text_mitte(msg, WKZ_DURCHMESSER, ENDE_EINTRAG);
    if(tmp.isEmpty())
    {
        QMessageBox mb;
        mb.setText("Werkzeugdurchmesser darf nicht leer sein!");
        mb.exec();
        return;
    }
    tmp = text_mitte(msg, WKZ_STECKPLATZ, ENDE_EINTRAG);
    if(!tmp.isEmpty())
    {
        QString alte_nummer = tmp;
        int num = tmp.toInt(0, 10);
        tmp = QString::fromStdString(int_to_string(num));
        if(tmp != alte_nummer)
        {
            QMessageBox mb;
            mb.setText("Steckplatz ist ungueltig!\nBitte nur ganze Zahlen verwenden.");
            mb.exec();
            return;
        }
    }
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


void Dialog_Werkzeug::on_pushButton_bild_info_clicked()
{
    QString nachricht;
    nachricht = "Im Ordner \"";
    nachricht += WKZ_BILDER_PFAD;
    nachricht += "\" koennen Bilder der Werkzeuge abgelegt werden. Ein Bild wird im Werkzeugdialog angezeigt, wenn es nach der Nummer des Werkzeuges benannt ist. Es werden nur Bilder im JPG-Format akzeptiert.\nz.B:   1.jpg  \nfuer das Bild des Fraesers mit der Werkzeugnummer 1";
    QMessageBox mb;
    mb.setText(nachricht);
    mb.exec();
}
