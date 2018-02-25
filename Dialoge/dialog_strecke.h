#ifndef DIALOG_STRECKE_H
#define DIALOG_STRECKE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "../eigeneKlassen/strecke.h"

namespace Ui {
class Dialog_strecke;
}

class Dialog_strecke : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_strecke(QWidget *parent = 0);
    ~Dialog_strecke();
    void show();
    
public slots:
    void getDialogData(QString text, bool openToChangeData);
    void getVariablen(QString var);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_ok_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void sendBraucheVariablen(QString kennung);

private:
    Ui::Dialog_strecke *ui;
    bool openToModifyData;
    strecke s;
    QString variablen;
    QString dialogDataToString();
};

#endif // DIALOG_STRECKE_H
