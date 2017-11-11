#ifndef DIALOG_FRAESER_AUFRUF_H
#define DIALOG_FRAESER_AUFRUF_H

#include <QDialog>
#include <QDir>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"
#include "../eigeneKlassen/werkzeug.h"

namespace Ui {
class Dialog_Fraeser_Aufruf;
}

class Dialog_Fraeser_Aufruf : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Fraeser_Aufruf(QWidget *parent = 0);
    ~Dialog_Fraeser_Aufruf();
    
private:
    Ui::Dialog_Fraeser_Aufruf *ui;
    bool openToModifyData;
    QString dialogDataToString();
    werkzeug w;

public slots:
        void getDialogData(QString text, bool openToChangeData, QStringList WerkzeugNamen, werkzeug wkz);

signals:
    void sendDialogData(QString text);
    void sendDialogDataModifyed(QString text);
    void signalSaveConfig(QString text);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_speichern_clicked();
    void on_pushButton_ok_clicked();
    void on_comboBox_werkzeug_currentIndexChanged(const QString &arg1);
};

#endif // DIALOG_FRAESER_AUFRUF_H
