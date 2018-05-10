#ifndef DIALOG_WERKZEUG_H
#define DIALOG_WERKZEUG_H

#include <QDialog>
#include <QMessageBox>
#include <QDir>
#include "../myDefines.h"
#include "../eigeneFunktionen/myfunktion.h"
#include "../eigeneFunktionen/umwandeln.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Werkzeug;
}

class Dialog_Werkzeug : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Werkzeug(QWidget *parent = 0);
    ~Dialog_Werkzeug();
    QString getDefault();
    
private:
    Ui::Dialog_Werkzeug *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_Abbrechen_clicked();
    void on_pushButton_Speichern_clicked();
    void on_pushButton_OK_clicked();
    void on_pushButton_bild_info_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_WERKZEUG_H
