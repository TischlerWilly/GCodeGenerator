#ifndef DIALOG_SCHLEIFE_LINEAR_H
#define DIALOG_SCHLEIFE_LINEAR_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"

namespace Ui {
class Dialog_Schleife_linear;
}

class Dialog_Schleife_linear : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Schleife_linear(QWidget *parent = 0);
    ~Dialog_Schleife_linear();

private:
    Ui::Dialog_Schleife_linear *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_abbrechen_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_SCHLEIFE_LINEAR_H
