#ifndef DIALOG_PROGRAMMLISTEN_H
#define DIALOG_PROGRAMMLISTEN_H

#include <QDialog>

namespace Ui {
class Dialog_Programmlisten;
}

class Dialog_Programmlisten : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Programmlisten(QWidget *parent = 0);
    ~Dialog_Programmlisten();

public slots:
    void daten_anzeigen(QString prgtext, QString klartext, \
                        QString variabel, QString geotext, \
                        QString fkon);
    
private:
    Ui::Dialog_Programmlisten *ui;
};

#endif // DIALOG_PROGRAMMLISTEN_H
