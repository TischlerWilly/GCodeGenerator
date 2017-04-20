#ifndef DIALOG_KOMMENTAR_H
#define DIALOG_KOMMENTAR_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class Dialog_Kommentar;
}

class Dialog_Kommentar : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Kommentar(QWidget *parent = 0);
    ~Dialog_Kommentar();
    
private:
    Ui::Dialog_Kommentar *ui;
        bool openToModifyData;
        QString dialogDataToString();

public slots:
        void getDialogData(QString text, bool openToChangeData);

private slots:
        void on_pushButton_Abbrechen_clicked();
        void on_pushButton_OK_clicked();
        void on_pushButton_save_clicked();

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

};

#endif // DIALOG_KOMMENTAR_H
