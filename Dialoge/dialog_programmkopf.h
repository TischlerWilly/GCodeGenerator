#ifndef DIALOG_PROGRAMMKOPF_H
#define DIALOG_PROGRAMMKOPF_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Programmkopf;
}

class Dialog_Programmkopf : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Programmkopf(QWidget *parent = 0);
    ~Dialog_Programmkopf();

private:
    Ui::Dialog_Programmkopf *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Abbrechen_clicked();
    void on_pushButton_save_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_PROGRAMMKOPF_H
