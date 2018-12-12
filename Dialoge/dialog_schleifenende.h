#ifndef DIALOG_SCHLEIFENENDE_H
#define DIALOG_SCHLEIFENENDE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"

namespace Ui {
class Dialog_Schleifenende;
}

class Dialog_Schleifenende : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Schleifenende(QWidget *parent = 0);
    ~Dialog_Schleifenende();

private:
    Ui::Dialog_Schleifenende *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_ok_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_SCHLEIFENENDE_H
