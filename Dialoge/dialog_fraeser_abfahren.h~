#ifndef DIALOG_FRAESER_ABFAHREN_H
#define DIALOG_FRAESER_ABFAHREN_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_fraeser_abfahren;
}

class Dialog_fraeser_abfahren : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_fraeser_abfahren(QWidget *parent = 0);
    ~Dialog_fraeser_abfahren();

private:
    Ui::Dialog_fraeser_abfahren *ui;
    bool openToModifyData;
    QString dialogDataToString();

public slots:
        void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_ok_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);
};

#endif // DIALOG_FRAESER_ABFAHREN_H
