#ifndef DIALOG_BOHREN_H
#define DIALOG_BOHREN_H

#include <QDialog>

namespace Ui {
class Dialog_bohren;
}

class Dialog_bohren : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_bohren(QWidget *parent = 0);
    ~Dialog_bohren();
    
private:
    Ui::Dialog_bohren *ui;
};

#endif // DIALOG_BOHREN_H
