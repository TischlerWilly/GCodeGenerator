/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_gerade.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_GERADE_H
#define UI_DIALOG_FRAESER_GERADE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_fraeser_gerade
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_ende_y_var;
    QLineEdit *lineEdit_radius;
    QLineEdit *lineEdit_afb;
    QLabel *label_ende_z_var;
    QLabel *label_ende_x_var;
    QLabel *label_radius_var;
    QLabel *label_ende_y;
    QLineEdit *lineEdit_ende_x;
    QLabel *label_afb;
    QLabel *label_ende_z;
    QLabel *label_ende_x;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_ende_z;
    QLabel *label_radius;
    QLineEdit *lineEdit_ende_y;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_fraeser_gerade)
    {
        if (Dialog_fraeser_gerade->objectName().isEmpty())
            Dialog_fraeser_gerade->setObjectName(QString::fromUtf8("Dialog_fraeser_gerade"));
        Dialog_fraeser_gerade->resize(400, 326);
        layoutWidget = new QWidget(Dialog_fraeser_gerade);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_ende_y_var = new QLabel(layoutWidget);
        label_ende_y_var->setObjectName(QString::fromUtf8("label_ende_y_var"));

        gridLayout->addWidget(label_ende_y_var, 1, 1, 1, 1);

        lineEdit_radius = new QLineEdit(layoutWidget);
        lineEdit_radius->setObjectName(QString::fromUtf8("lineEdit_radius"));

        gridLayout->addWidget(lineEdit_radius, 3, 2, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget);
        lineEdit_afb->setObjectName(QString::fromUtf8("lineEdit_afb"));

        gridLayout->addWidget(lineEdit_afb, 5, 2, 1, 1);

        label_ende_z_var = new QLabel(layoutWidget);
        label_ende_z_var->setObjectName(QString::fromUtf8("label_ende_z_var"));

        gridLayout->addWidget(label_ende_z_var, 2, 1, 1, 1);

        label_ende_x_var = new QLabel(layoutWidget);
        label_ende_x_var->setObjectName(QString::fromUtf8("label_ende_x_var"));

        gridLayout->addWidget(label_ende_x_var, 0, 1, 1, 1);

        label_radius_var = new QLabel(layoutWidget);
        label_radius_var->setObjectName(QString::fromUtf8("label_radius_var"));

        gridLayout->addWidget(label_radius_var, 3, 1, 1, 1);

        label_ende_y = new QLabel(layoutWidget);
        label_ende_y->setObjectName(QString::fromUtf8("label_ende_y"));

        gridLayout->addWidget(label_ende_y, 1, 0, 1, 1);

        lineEdit_ende_x = new QLineEdit(layoutWidget);
        lineEdit_ende_x->setObjectName(QString::fromUtf8("lineEdit_ende_x"));

        gridLayout->addWidget(lineEdit_ende_x, 0, 2, 1, 1);

        label_afb = new QLabel(layoutWidget);
        label_afb->setObjectName(QString::fromUtf8("label_afb"));

        gridLayout->addWidget(label_afb, 5, 0, 1, 1);

        label_ende_z = new QLabel(layoutWidget);
        label_ende_z->setObjectName(QString::fromUtf8("label_ende_z"));

        gridLayout->addWidget(label_ende_z, 2, 0, 1, 1);

        label_ende_x = new QLabel(layoutWidget);
        label_ende_x->setObjectName(QString::fromUtf8("label_ende_x"));

        gridLayout->addWidget(label_ende_x, 0, 0, 1, 1);

        label_afb_var = new QLabel(layoutWidget);
        label_afb_var->setObjectName(QString::fromUtf8("label_afb_var"));

        gridLayout->addWidget(label_afb_var, 5, 1, 1, 1);

        lineEdit_ende_z = new QLineEdit(layoutWidget);
        lineEdit_ende_z->setObjectName(QString::fromUtf8("lineEdit_ende_z"));

        gridLayout->addWidget(lineEdit_ende_z, 2, 2, 1, 1);

        label_radius = new QLabel(layoutWidget);
        label_radius->setObjectName(QString::fromUtf8("label_radius"));

        gridLayout->addWidget(label_radius, 3, 0, 1, 1);

        lineEdit_ende_y = new QLineEdit(layoutWidget);
        lineEdit_ende_y->setObjectName(QString::fromUtf8("lineEdit_ende_y"));

        gridLayout->addWidget(lineEdit_ende_y, 1, 2, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout->addWidget(label_bezeichnung, 4, 0, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget);
        label_bezeichnung_var->setObjectName(QString::fromUtf8("label_bezeichnung_var"));

        gridLayout->addWidget(label_bezeichnung_var, 4, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout->addWidget(lineEdit_bezeichnung, 4, 2, 1, 1);

        layoutWidget1 = new QWidget(Dialog_fraeser_gerade);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 290, 381, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget1);
        pushButton_abbrechen->setObjectName(QString::fromUtf8("pushButton_abbrechen"));

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget1);
        pushButton_speichern->setObjectName(QString::fromUtf8("pushButton_speichern"));

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget1);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout->addWidget(pushButton_ok);

        QWidget::setTabOrder(lineEdit_ende_x, lineEdit_ende_y);
        QWidget::setTabOrder(lineEdit_ende_y, lineEdit_ende_z);
        QWidget::setTabOrder(lineEdit_ende_z, lineEdit_radius);
        QWidget::setTabOrder(lineEdit_radius, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_afb);
        QWidget::setTabOrder(lineEdit_afb, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_fraeser_gerade);

        QMetaObject::connectSlotsByName(Dialog_fraeser_gerade);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_gerade)
    {
        Dialog_fraeser_gerade->setWindowTitle(QApplication::translate("Dialog_fraeser_gerade", "Gerade Fraesbahn", 0, QApplication::UnicodeUTF8));
        label_ende_y_var->setText(QApplication::translate("Dialog_fraeser_gerade", "*[Y]", 0, QApplication::UnicodeUTF8));
        label_ende_z_var->setText(QApplication::translate("Dialog_fraeser_gerade", "*[Z]", 0, QApplication::UnicodeUTF8));
        label_ende_x_var->setText(QApplication::translate("Dialog_fraeser_gerade", "*[X]", 0, QApplication::UnicodeUTF8));
        label_radius_var->setText(QApplication::translate("Dialog_fraeser_gerade", "[RAD]", 0, QApplication::UnicodeUTF8));
        label_ende_y->setText(QApplication::translate("Dialog_fraeser_gerade", "Endpunkt Y:", 0, QApplication::UnicodeUTF8));
        label_afb->setText(QApplication::translate("Dialog_fraeser_gerade", "Ausf\303\274hrbedingung:", 0, QApplication::UnicodeUTF8));
        label_ende_z->setText(QApplication::translate("Dialog_fraeser_gerade", "Endpunkt Z:", 0, QApplication::UnicodeUTF8));
        label_ende_x->setText(QApplication::translate("Dialog_fraeser_gerade", "Endpunkt X:", 0, QApplication::UnicodeUTF8));
        label_afb_var->setText(QApplication::translate("Dialog_fraeser_gerade", "[AFB]", 0, QApplication::UnicodeUTF8));
        label_radius->setText(QApplication::translate("Dialog_fraeser_gerade", "Radius zum Nachfolger:", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_fraeser_gerade", "Bezeichnung:", 0, QApplication::UnicodeUTF8));
        label_bezeichnung_var->setText(QApplication::translate("Dialog_fraeser_gerade", "[BEZ]", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_fraeser_gerade", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_speichern->setText(QApplication::translate("Dialog_fraeser_gerade", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("Dialog_fraeser_gerade", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_gerade: public Ui_Dialog_fraeser_gerade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_GERADE_H
