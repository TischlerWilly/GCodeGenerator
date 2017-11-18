#ifndef DIALOG_KREISTASCHE_H
#define DIALOG_KREISTASCHE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"

namespace Ui {
class Dialog_Kreistasche;
}

class Dialog_Kreistasche : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Kreistasche(QWidget *parent = 0);
    ~Dialog_Kreistasche();
    void show();

private:
    Ui::Dialog_Kreistasche *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen);
    void getWerkzeugdaten(QString Werkzeugdaten);

private slots:
    void on_pushButton_Abbrechen_clicked();
    void on_pushButton_Speichern_clicked();
    void on_pushButton_OK_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_comboBox_Werkzeug_currentIndexChanged();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);
    void signalBraucheWerkzeugdaten(QString Werkzeugname, QString Dialog);

};

#endif // DIALOG_KREISTASCHE_H
