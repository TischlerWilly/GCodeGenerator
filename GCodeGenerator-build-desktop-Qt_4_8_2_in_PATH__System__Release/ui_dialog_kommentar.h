/********************************************************************************
** Form generated from reading UI file 'dialog_kommentar.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_KOMMENTAR_H
#define UI_DIALOG_KOMMENTAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Kommentar
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Abbrechen;
    QPushButton *pushButton_save;
    QPushButton *pushButton_OK;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Kommentar;
    QLabel *label_AFB;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Kommentar_var;
    QLabel *label_AFB_var;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Kommentar;
    QLineEdit *lineEdit_AFB;

    void setupUi(QDialog *Dialog_Kommentar)
    {
        if (Dialog_Kommentar->objectName().isEmpty())
            Dialog_Kommentar->setObjectName(QString::fromUtf8("Dialog_Kommentar"));
        Dialog_Kommentar->resize(498, 129);
        Dialog_Kommentar->setModal(true);
        layoutWidget = new QWidget(Dialog_Kommentar);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(191, 90, 301, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Abbrechen = new QPushButton(layoutWidget);
        pushButton_Abbrechen->setObjectName(QString::fromUtf8("pushButton_Abbrechen"));

        horizontalLayout->addWidget(pushButton_Abbrechen);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        pushButton_OK = new QPushButton(layoutWidget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        layoutWidget1 = new QWidget(Dialog_Kommentar);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 10, 481, 56));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_Kommentar = new QLabel(layoutWidget1);
        label_Kommentar->setObjectName(QString::fromUtf8("label_Kommentar"));

        verticalLayout_3->addWidget(label_Kommentar);

        label_AFB = new QLabel(layoutWidget1);
        label_AFB->setObjectName(QString::fromUtf8("label_AFB"));

        verticalLayout_3->addWidget(label_AFB);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_Kommentar_var = new QLabel(layoutWidget1);
        label_Kommentar_var->setObjectName(QString::fromUtf8("label_Kommentar_var"));

        verticalLayout_2->addWidget(label_Kommentar_var);

        label_AFB_var = new QLabel(layoutWidget1);
        label_AFB_var->setObjectName(QString::fromUtf8("label_AFB_var"));

        verticalLayout_2->addWidget(label_AFB_var);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_Kommentar = new QLineEdit(layoutWidget1);
        lineEdit_Kommentar->setObjectName(QString::fromUtf8("lineEdit_Kommentar"));

        verticalLayout->addWidget(lineEdit_Kommentar);

        lineEdit_AFB = new QLineEdit(layoutWidget1);
        lineEdit_AFB->setObjectName(QString::fromUtf8("lineEdit_AFB"));

        verticalLayout->addWidget(lineEdit_AFB);


        horizontalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(lineEdit_Kommentar, lineEdit_AFB);
        QWidget::setTabOrder(lineEdit_AFB, pushButton_Abbrechen);
        QWidget::setTabOrder(pushButton_Abbrechen, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_OK);

        retranslateUi(Dialog_Kommentar);

        QMetaObject::connectSlotsByName(Dialog_Kommentar);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Kommentar)
    {
        Dialog_Kommentar->setWindowTitle(QApplication::translate("Dialog_Kommentar", "Kommentar", 0, QApplication::UnicodeUTF8));
        pushButton_Abbrechen->setText(QApplication::translate("Dialog_Kommentar", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Dialog_Kommentar", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("Dialog_Kommentar", "OK", 0, QApplication::UnicodeUTF8));
        label_Kommentar->setText(QApplication::translate("Dialog_Kommentar", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_AFB->setText(QApplication::translate("Dialog_Kommentar", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_Kommentar_var->setText(QApplication::translate("Dialog_Kommentar", "[KOM]", 0, QApplication::UnicodeUTF8));
        label_AFB_var->setText(QApplication::translate("Dialog_Kommentar", "[AFB]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Kommentar: public Ui_Dialog_Kommentar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_KOMMENTAR_H
