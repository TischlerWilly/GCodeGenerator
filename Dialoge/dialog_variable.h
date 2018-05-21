#ifndef DIALOG_VARIABLE_H
#define DIALOG_VARIABLE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Variable;
}

class Dialog_Variable : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Variable(QWidget *parent = 0);
    ~Dialog_Variable();
    QString get_variable(QString name, QString wert);
    
private:
    Ui::Dialog_Variable *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Speichern_clicked();
    void on_pushButton_Abbrechen_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_VARIABLE_H
