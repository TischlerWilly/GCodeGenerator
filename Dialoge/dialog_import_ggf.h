#ifndef DIALOG_IMPORT_GGF_H
#define DIALOG_IMPORT_GGF_H

#include <QDialog>
#include <QMessageBox>
#include <QCheckBox>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

#include "../eigeneKlassen/text_zeilenweise.h"

namespace Ui {
class Dialog_import_ggf;
}

class Dialog_import_ggf : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_import_ggf(QWidget *parent = 0);
    ~Dialog_import_ggf();
    
public slots:
    void getText(QString text);

private slots:
    void on_pushButton_abbrechen_clicked();
    void on_pushButton_import_clicked();
    void on_pushButton_alle_clicked();
    void on_pushButton_keine_clicked();

signals:
    void sendData(QString text);

private:
    Ui::Dialog_import_ggf *ui;
    text_zeilenweise import;
    void clear();


};

#endif // DIALOG_IMPORT_GGF_H
