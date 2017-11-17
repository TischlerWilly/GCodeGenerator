/********************************************************************************
** Form generated from reading UI file 'dialog_programmende.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMMENDE_H
#define UI_DIALOG_PROGRAMMENDE_H

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

class Ui_Dialog_Programmende
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_amNullpunkt;
    QRadioButton *radioButton_benutzerdefiniert;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ausfuehrbedingung;
    QLineEdit *lineEdit_pos_z;
    QLabel *label_pos_y;
    QLineEdit *lineEdit_pos_x;
    QLineEdit *lineEdit_pos_y;
    QLabel *label_Ausfuerbedingung;
    QLabel *label_pos_z;
    QLabel *label_pos_x;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_bezeichnung;
    QLabel *label__bezeichnung_var;
    QLabel *label_bezeichnung;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *Dialog_Programmende)
    {
        if (Dialog_Programmende->objectName().isEmpty())
            Dialog_Programmende->setObjectName(QString::fromUtf8("Dialog_Programmende"));
        Dialog_Programmende->resize(440, 272);
        Dialog_Programmende->setModal(true);
        layoutWidget = new QWidget(Dialog_Programmende);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 419, 251));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_amNullpunkt = new QRadioButton(layoutWidget);
        radioButton_amNullpunkt->setObjectName(QString::fromUtf8("radioButton_amNullpunkt"));

        verticalLayout->addWidget(radioButton_amNullpunkt);

        radioButton_benutzerdefiniert = new QRadioButton(layoutWidget);
        radioButton_benutzerdefiniert->setObjectName(QString::fromUtf8("radioButton_benutzerdefiniert"));

        verticalLayout->addWidget(radioButton_benutzerdefiniert);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_ausfuehrbedingung = new QLineEdit(layoutWidget);
        lineEdit_ausfuehrbedingung->setObjectName(QString::fromUtf8("lineEdit_ausfuehrbedingung"));

        gridLayout->addWidget(lineEdit_ausfuehrbedingung, 4, 2, 1, 1);

        lineEdit_pos_z = new QLineEdit(layoutWidget);
        lineEdit_pos_z->setObjectName(QString::fromUtf8("lineEdit_pos_z"));

        gridLayout->addWidget(lineEdit_pos_z, 2, 2, 1, 1);

        label_pos_y = new QLabel(layoutWidget);
        label_pos_y->setObjectName(QString::fromUtf8("label_pos_y"));

        gridLayout->addWidget(label_pos_y, 1, 0, 1, 1);

        lineEdit_pos_x = new QLineEdit(layoutWidget);
        lineEdit_pos_x->setObjectName(QString::fromUtf8("lineEdit_pos_x"));

        gridLayout->addWidget(lineEdit_pos_x, 0, 2, 1, 1);

        lineEdit_pos_y = new QLineEdit(layoutWidget);
        lineEdit_pos_y->setObjectName(QString::fromUtf8("lineEdit_pos_y"));

        gridLayout->addWidget(lineEdit_pos_y, 1, 2, 1, 1);

        label_Ausfuerbedingung = new QLabel(layoutWidget);
        label_Ausfuerbedingung->setObjectName(QString::fromUtf8("label_Ausfuerbedingung"));

        gridLayout->addWidget(label_Ausfuerbedingung, 4, 0, 1, 1);

        label_pos_z = new QLabel(layoutWidget);
        label_pos_z->setObjectName(QString::fromUtf8("label_pos_z"));

        gridLayout->addWidget(label_pos_z, 2, 0, 1, 1);

        label_pos_x = new QLabel(layoutWidget);
        label_pos_x->setObjectName(QString::fromUtf8("label_pos_x"));

        gridLayout->addWidget(label_pos_x, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        lineEdit_bezeichnung = new QLineEdit(layoutWidget);
        lineEdit_bezeichnung->setObjectName(QString::fromUtf8("lineEdit_bezeichnung"));

        gridLayout->addWidget(lineEdit_bezeichnung, 3, 2, 1, 1);

        label__bezeichnung_var = new QLabel(layoutWidget);
        label__bezeichnung_var->setObjectName(QString::fromUtf8("label__bezeichnung_var"));

        gridLayout->addWidget(label__bezeichnung_var, 3, 1, 1, 1);

        label_bezeichnung = new QLabel(layoutWidget);
        label_bezeichnung->setObjectName(QString::fromUtf8("label_bezeichnung"));

        gridLayout->addWidget(label_bezeichnung, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName(QString::fromUtf8("pushButton_abbrechen"));

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);


        verticalLayout_3->addLayout(horizontalLayout);

        QWidget::setTabOrder(radioButton_amNullpunkt, radioButton_benutzerdefiniert);
        QWidget::setTabOrder(radioButton_benutzerdefiniert, lineEdit_pos_x);
        QWidget::setTabOrder(lineEdit_pos_x, lineEdit_pos_y);
        QWidget::setTabOrder(lineEdit_pos_y, lineEdit_pos_z);
        QWidget::setTabOrder(lineEdit_pos_z, lineEdit_bezeichnung);
        QWidget::setTabOrder(lineEdit_bezeichnung, lineEdit_ausfuehrbedingung);
        QWidget::setTabOrder(lineEdit_ausfuehrbedingung, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Programmende);

        QMetaObject::connectSlotsByName(Dialog_Programmende);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programmende)
    {
        Dialog_Programmende->setWindowTitle(QApplication::translate("Dialog_Programmende", "Programmende", 0, QApplication::UnicodeUTF8));
        radioButton_amNullpunkt->setText(QApplication::translate("Dialog_Programmende", "am Nullpunkt", 0, QApplication::UnicodeUTF8));
        radioButton_benutzerdefiniert->setText(QApplication::translate("Dialog_Programmende", "an Benutzerdefinierter Position", 0, QApplication::UnicodeUTF8));
        label_pos_y->setText(QApplication::translate("Dialog_Programmende", "Position in Y:", 0, QApplication::UnicodeUTF8));
        label_Ausfuerbedingung->setText(QApplication::translate("Dialog_Programmende", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_pos_z->setText(QApplication::translate("Dialog_Programmende", "Position in Z:", 0, QApplication::UnicodeUTF8));
        label_pos_x->setText(QApplication::translate("Dialog_Programmende", "Position in X:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_Programmende", "[Y]", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog_Programmende", "[X]", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_Programmende", "[Z]", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog_Programmende", "[AFB]", 0, QApplication::UnicodeUTF8));
        label__bezeichnung_var->setText(QApplication::translate("Dialog_Programmende", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_bezeichnung->setText(QApplication::translate("Dialog_Programmende", "Bezeichnung:", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_Programmende", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Dialog_Programmende", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Programmende", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programmende: public Ui_Dialog_Programmende {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMMENDE_H
