#ifndef DIALOG_PROGRAMMENDE_H
#define DIALOG_PROGRAMMENDE_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Programmende;
}

class Dialog_Programmende : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Programmende(QWidget *parent = 0);
    ~Dialog_Programmende();

private:
    Ui::Dialog_Programmende *ui;
    bool openToModifyData;
    QString dialogDataToString();
    QString modusOfThisDialog;

    void setModus(QString newModus);

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_abbrechen_clicked();
    void on_radioButton_amNullpunkt_clicked();
    void on_radioButton_benutzerdefiniert_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_PROGRAMMENDE_H
