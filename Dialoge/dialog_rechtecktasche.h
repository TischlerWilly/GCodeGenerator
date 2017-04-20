#ifndef DIALOG_RECHTECKTASCHE_H
#define DIALOG_RECHTECKTASCHE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Rechtecktasche;
}

class Dialog_Rechtecktasche : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Rechtecktasche(QWidget *parent = 0);
    ~Dialog_Rechtecktasche();
    
private:
    Ui::Dialog_Rechtecktasche *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen);
    void getWerkzeugdaten(QString Werkzeugdaten);

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Speichern_clicked();
    void on_pushButton_Abbrechen_clicked();
    void on_tabWidget_currentChanged(int index);

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);
    void signalBraucheWerkzeugdaten(QString Werkzeugname, QString Dialog);



};

#endif // DIALOG_RECHTECKTASCHE_H
