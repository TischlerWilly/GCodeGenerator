#ifndef DIALOG_KREIS_H
#define DIALOG_KREIS_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "eigeneKlassen/kreis.h"

namespace Ui {
class Dialog_Kreis;
}

class Dialog_Kreis : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Kreis(QWidget *parent = 0);
    ~Dialog_Kreis();
    
public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_Abbrechen_clicked();
    void on_pushButton_OK_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);

private:
    Ui::Dialog_Kreis *ui;
    bool openToModifyData;
    kreis k;
    QString dialogDataToString();
};

#endif // DIALOG_KREIS_H
