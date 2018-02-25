#ifndef DIALOG_BOGEN_H
#define DIALOG_BOGEN_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "eigeneKlassen/bogen.h"

namespace Ui {
class Dialog_Bogen;
}

class Dialog_Bogen : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Bogen(QWidget *parent = 0);
    ~Dialog_Bogen();
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
    Ui::Dialog_Bogen *ui;
    bool openToModifyData;
    bogen b;
    QString variablen;
    QString dialogDataToString();
};

#endif // DIALOG_BOGEN_H
