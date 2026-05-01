/********************************************************************************
** Form generated from reading UI file 'dialog_import_ggf.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_IMPORT_GGF_H
#define UI_DIALOG_IMPORT_GGF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_import_ggf
{
public:
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_import;
    QPushButton *pushButton_abbrechen;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_alle;
    QPushButton *pushButton_keine;

    void setupUi(QDialog *Dialog_import_ggf)
    {
        if (Dialog_import_ggf->objectName().isEmpty())
            Dialog_import_ggf->setObjectName("Dialog_import_ggf");
        Dialog_import_ggf->resize(626, 483);
        Dialog_import_ggf->setModal(true);
        listWidget = new QListWidget(Dialog_import_ggf);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 10, 611, 421));
        layoutWidget = new QWidget(Dialog_import_ggf);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(363, 440, 251, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_import = new QPushButton(layoutWidget);
        pushButton_import->setObjectName("pushButton_import");

        horizontalLayout->addWidget(pushButton_import);

        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        layoutWidget1 = new QWidget(Dialog_import_ggf);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 440, 151, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_alle = new QPushButton(layoutWidget1);
        pushButton_alle->setObjectName("pushButton_alle");

        horizontalLayout_2->addWidget(pushButton_alle);

        pushButton_keine = new QPushButton(layoutWidget1);
        pushButton_keine->setObjectName("pushButton_keine");

        horizontalLayout_2->addWidget(pushButton_keine);


        retranslateUi(Dialog_import_ggf);

        QMetaObject::connectSlotsByName(Dialog_import_ggf);
    } // setupUi

    void retranslateUi(QDialog *Dialog_import_ggf)
    {
        Dialog_import_ggf->setWindowTitle(QCoreApplication::translate("Dialog_import_ggf", "Import GGF-Datei", nullptr));
        pushButton_import->setText(QCoreApplication::translate("Dialog_import_ggf", "Importieren", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_import_ggf", "Abbrechen", nullptr));
        pushButton_alle->setText(QCoreApplication::translate("Dialog_import_ggf", "alle", nullptr));
        pushButton_keine->setText(QCoreApplication::translate("Dialog_import_ggf", "keine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_import_ggf: public Ui_Dialog_import_ggf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_IMPORT_GGF_H
