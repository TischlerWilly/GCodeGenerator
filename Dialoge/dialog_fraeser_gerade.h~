#ifndef DIALOG_FRAESER_GERADE_H
#define DIALOG_FRAESER_GERADE_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneKlassen/werkzeug.h"

namespace Ui {
class Dialog_fraeser_gerade;
}

class Dialog_fraeser_gerade : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_fraeser_gerade(QWidget *parent = 0);
    ~Dialog_fraeser_gerade();
    
private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_ok_clicked();

public slots:
        void getDialogData(QString text, bool openToChangeData);

private:
    Ui::Dialog_fraeser_gerade *ui;
    bool openToModifyData;
    QString dialogDataToString();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);
};

#endif // DIALOG_FRAESER_GERADE_H
