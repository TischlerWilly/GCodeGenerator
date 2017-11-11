#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include <QDialog>
#include "../myDefines.h"
#include "../eigeneFunktionen/text.h"

namespace Ui {
class dialog_settings;
}

class dialog_settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_settings(QWidget *parent = 0);
    ~dialog_settings();

public slots:
    void getDialogData(QString text, bool openToChangeData);

private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_tooltable_clicked();

private:
    Ui::dialog_settings *ui;
    bool openToModifyData;

signals:
    void signalSaveConfig(QString text);
};

#endif // DIALOG_SETTINGS_H
