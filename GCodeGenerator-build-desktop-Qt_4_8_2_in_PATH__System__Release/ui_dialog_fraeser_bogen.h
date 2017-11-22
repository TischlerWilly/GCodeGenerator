/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_bogen.ui'
**
** Created: Wed Nov 22 20:54:07 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_BOGEN_H
#define UI_DIALOG_FRAESER_BOGEN_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_fraeser_bogen
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_radius;
    QLabel *label_ende_x;
    QLabel *label_ende_x_var;
    QLineEdit *lineEdit_ende_x;
    QLabel *label_ende_y;
    QLabel *label_ende_y_var;
    QLineEdit *lineEdit_ende_y;
    QLabel *label_ende_z;
    QLabel *label_ende_z_var;
    QLineEdit *lineEdit_ende_z;
    QLabel *label_radius_var;
    QLabel *label_radius;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_bezeichnung;
    QLabel *label_bezeichnung_var;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label_ausfbed;
    QLabel *label_ausfbed_var;
    QLineEdit *lineEdit_ausfbed;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_im_UZS;
    QRadioButton *radioButton_gegen_UZS;

    void setupUi(QDialog *Dialog_fraeser_bogen)
    {
        if (Dialog_fraeser_bogen->objectName().isEmpty())
            Dialog_fraeser_bogen->setObjectName(QString::fromUtf8("Dialog_fraeser_bogen"));
        Dialog_fraeser_bogen->resize(453, 399);
        layoutWidget = new QWidget(Dialog_fraeser_bogen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 431, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_radius = new QLineEdit(layoutWidget);
        lineEdit_radius->setObjectName(QString::fromUtf8("lineEdit_radius"));

        gridLayout->addWidget(lineEdit_radius, 3, 2, 1, 1);

        label_ende_x = new QLabel(layoutWidget);
        label_ende_x->setObjectName(QString::fromUtf8("label_ende_x"));

        gridLayout->addWidget(label_ende_x, 0, 0, 1, 1);

        label_ende_x_var = new QLabel(layoutWidget);
        label_ende_x_var->setObjectName(QString::fromUtf8("label_ende_x_var"));

        gridLayout->addWidget(label_ende_x_var, 0, 1, 1, 1);

        lineEdit_ende_x = new QLineEdit(layoutWidget);
        lineEdit_ende_x->setObjectName(QString::fromUtf8("lineEdit_ende_x"));

        gridLayout->addWidget(lineEdit_ende_x, 0, 2, 1, 1);

        label_ende_y = new QLabel(layoutWidget);
        label_ende_y->setObjectName(QString::fromUtf8("label_ende_y"));

        gridLayout->addWidget(label_ende_y, 1, 0, 1, 1);

        label_ende_y_var = new QLabel(layoutWidget);
        label_ende_y_var->setObjectName(QString::fromUtf8("label_ende_y_var"));

        gridLayout->addWidget(label_ende_y_var, 1, 1, 1, 1);

        lineEdit_ende_y = new QLineEdit(layoutWidget);
        lineEdit_ende_y->setObjectName(QString::fromUtf8("lineEdit_ende_y"));

        gridLayout->addWidget(lineEdit_ende_y, 1, 2, 1, 1);

        label_ende_z = new QLabel(layoutWidget);
        label_ende_z->setObjectName(QString::fromUtf8("label_ende_z"));

        gridLayout->addWidget(label_ende_z, 2, 0, 1, 1);

        label_ende_z_var = new QLabel(layoutWidget);
        label_ende_z_var->setObjectName(QString::fromUtf8("label_ende_z_var"));

        gridLayout->addWidget(label_ende_z_var, 2, 1, 1, 1);

        lineEdit_ende_z = new QLineEdit(layoutWidget);
        lineEdit_ende_z->setObjectName(QString::fromUtf8("lineEdit_ende_z"));

        gridLayout->addWidget(lineEdit_ende_z, 2, 2, 1, 1);

        label_radius_var = new QLabel(layoutWidget);
        label_radius_var->setObjectName(QString::fromUtf8("label_radius_var"));

        gridLayout->addWidget(label_radius_var, 3, 1, 1, 1);

        label_radius = new QLabel(layoutWidget);
        label_radius->setObjectName(QString::fromUtf8("label_radius"));

        gridLayout->addWidget(label_radius, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 290, 431, 61));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_bezeichnung = new QLabel(layoutWidget1);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout_3->addWidget(label_bezeichnung, 0, 0, 1, 1);

        label_bezeichnung_var = new QLabel(layoutWidget1);
        label_bezeichnung_var->setObjectName(QString::fromUtf8("label_bezeichnung_var"));

        gridLayout_3->addWidget(label_bezeichnung_var, 0, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget1);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout_3->addWidget(lineEdit_bezeichnung, 0, 2, 1, 1);

        label_ausfbed = new QLabel(layoutWidget1);
        label_ausfbed->setObjectName(QString::fromUtf8("label_ausfbed"));

        gridLayout_3->addWidget(label_ausfbed, 1, 0, 1, 1);

        label_ausfbed_var = new QLabel(layoutWidget1);
        label_ausfbed_var->setObjectName(QString::fromUtf8("label_ausfbed_var"));

        gridLayout_3->addWidget(label_ausfbed_var, 1, 1, 1, 1);

        lineEdit_ausfbed = new QLineEdit(layoutWidget1);
        lineEdit_ausfbed->setObjectName(QString::fromUtf8("lineEdit_ausfbed"));

        gridLayout_3->addWidget(lineEdit_ausfbed, 1, 2, 1, 1);

        layoutWidget2 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 360, 431, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget2);
        pushButton_abbrechen->setObjectName(QString::fromUtf8("pushButton_abbrechen"));

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget2);
        pushButton_speichern->setObjectName(QString::fromUtf8("pushButton_speichern"));

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget2);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout->addWidget(pushButton_ok);

        layoutWidget3 = new QWidget(Dialog_fraeser_bogen);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(9, 221, 431, 61));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_im_UZS = new QRadioButton(layoutWidget3);
        radioButton_im_UZS->setObjectName(QString::fromUtf8("radioButton_im_UZS"));

        verticalLayout->addWidget(radioButton_im_UZS);

        radioButton_gegen_UZS = new QRadioButton(layoutWidget3);
        radioButton_gegen_UZS->setObjectName(QString::fromUtf8("radioButton_gegen_UZS"));

        verticalLayout->addWidget(radioButton_gegen_UZS);

        QWidget::setTabOrder(lineEdit_ende_x, lineEdit_ende_y);
        QWidget::setTabOrder(lineEdit_ende_y, lineEdit_ende_z);
        QWidget::setTabOrder(lineEdit_ende_z, lineEdit_radius);
        QWidget::setTabOrder(lineEdit_radius, radioButton_im_UZS);
        QWidget::setTabOrder(radioButton_im_UZS, radioButton_gegen_UZS);
        QWidget::setTabOrder(radioButton_gegen_UZS, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_ausfbed);
        QWidget::setTabOrder(lineEdit_ausfbed, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);

        retranslateUi(Dialog_fraeser_bogen);

        QMetaObject::connectSlotsByName(Dialog_fraeser_bogen);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fraeser_bogen)
    {
        Dialog_fraeser_bogen->setWindowTitle(QApplication::translate("Dialog_fraeser_bogen", "gebogene Fr\303\244sbahn", 0, QApplication::UnicodeUTF8));
        label_ende_x->setText(QApplication::translate("Dialog_fraeser_bogen", "Endpunkt in X", 0, QApplication::UnicodeUTF8));
        label_ende_x_var->setText(QApplication::translate("Dialog_fraeser_bogen", "*[X]", 0, QApplication::UnicodeUTF8));
        label_ende_y->setText(QApplication::translate("Dialog_fraeser_bogen", "Endpunkt in Y", 0, QApplication::UnicodeUTF8));
        label_ende_y_var->setText(QApplication::translate("Dialog_fraeser_bogen", "*[Y]", 0, QApplication::UnicodeUTF8));
        label_ende_z->setText(QApplication::translate("Dialog_fraeser_bogen", "Endpunkt in Z", 0, QApplication::UnicodeUTF8));
        label_ende_z_var->setText(QApplication::translate("Dialog_fraeser_bogen", "*[Z]", 0, QApplication::UnicodeUTF8));
        label_radius_var->setText(QApplication::translate("Dialog_fraeser_bogen", "[RAD]", 0, QApplication::UnicodeUTF8));
        label_radius->setText(QApplication::translate("Dialog_fraeser_bogen", "Radius", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_fraeser_bogen", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        label_bezeichnung_var->setText(QApplication::translate("Dialog_fraeser_bogen", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_ausfbed->setText(QApplication::translate("Dialog_fraeser_bogen", "Ausf\303\274hrbedinging", 0, QApplication::UnicodeUTF8));
        label_ausfbed_var->setText(QApplication::translate("Dialog_fraeser_bogen", "[AFB]", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_fraeser_bogen", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_speichern->setText(QApplication::translate("Dialog_fraeser_bogen", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("Dialog_fraeser_bogen", "OK", 0, QApplication::UnicodeUTF8));
        radioButton_im_UZS->setText(QApplication::translate("Dialog_fraeser_bogen", "in Uhrzeigersinn (G02)", 0, QApplication::UnicodeUTF8));
        radioButton_gegen_UZS->setText(QApplication::translate("Dialog_fraeser_bogen", "gegen den Uhrzeigersinn (G03)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_fraeser_bogen: public Ui_Dialog_fraeser_bogen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_BOGEN_H
