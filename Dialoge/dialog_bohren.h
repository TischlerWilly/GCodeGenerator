#ifndef DIALOG_BOHREN_H
#define DIALOG_BOHREN_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneFunktionen/myfunktion.h"

namespace Ui {
class Dialog_bohren;
}

class Dialog_bohren : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_bohren(QWidget *parent = 0);
    ~Dialog_bohren();
    void show();
    
private:
    Ui::Dialog_bohren *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen);
    void getWerkzeugdaten(QString Werkzeugdaten);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_ok_clicked();
    void on_comboBox_wkz_currentIndexChanged();
    void on_tabWidget_currentChanged(int index);

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);
    void signalBraucheWerkzeugdaten(QString Werkzeugname, QString Dialog);

};

#endif // DIALOG_BOHREN_H
