#include "dialog_variable.h"
#include "ui_dialog_variable.h"

Dialog_Variable::Dialog_Variable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Variable)
{
    ui->setupUi(this);
    openToModifyData = false;
    ui->pushButton_OK->setDefault(true);
}

Dialog_Variable::~Dialog_Variable()
{
    delete ui;
}

void Dialog_Variable::getDialogData(QString text, bool openToChangeData)
{
    openToModifyData = openToChangeData;
    ui->lineEdit_Bezeichnung->setText(selektiereEintrag(text, BEZEICHNUNG, ENDE_EINTRAG));
    ui->lineEdit_Wert->setText(selektiereEintrag(text, WERT, ENDE_EINTRAG));
    ui->lineEdit_Ausfuehrbedingung->setText(selektiereEintrag(text, AUSFUEHRBEDINGUNG, ENDE_EINTRAG));
    this->show();
}

QString Dialog_Variable::dialogDataToString()
{
    QString msg = VARIABLE_DIALOG;

    msg += BEZEICHNUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Bezeichnung->text());
    msg += ENDE_EINTRAG;

    msg += WERT;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Wert->text());
    msg += ENDE_EINTRAG;

    msg += AUSFUEHRBEDINGUNG;
    msg += buchstaben_alle_GROSS_schreiben(ui->lineEdit_Ausfuehrbedingung->text());
    msg += ENDE_EINTRAG;

    msg += ENDE_ZEILE;
    return msg;
}

void Dialog_Variable::on_pushButton_OK_clicked()
{
    if(ui->lineEdit_Bezeichnung->text().contains("_"))
    {
        QMessageBox mb;
        mb.setText("Unerlaubtes Zeichen im Namen \"_\"!");
        mb.exec();
        return;
    }else if(ui->lineEdit_Bezeichnung->text().contains("0")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("1")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("2")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("3")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("4")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("5")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("6")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("7")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("8")  ||  \
             ui->lineEdit_Bezeichnung->text().contains("9")  )
    {
        QMessageBox mb;
        mb.setText("Name darf keine Zahlen enthalten!");
        mb.exec();
        return;
    }

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

void Dialog_Variable::on_pushButton_Speichern_clicked()
{
    QString msg = dialogDataToString();
    this->hide();
    emit signalSaveConfig(msg);
}

void Dialog_Variable::on_pushButton_Abbrechen_clicked()
{
    this->close();
}
