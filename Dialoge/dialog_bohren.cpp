#include "dialog_bohren.h"
#include "ui_dialog_bohren.h"

Dialog_bohren::Dialog_bohren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_bohren)
{
    ui->setupUi(this);
}

Dialog_bohren::~Dialog_bohren()
{
    delete ui;
}
