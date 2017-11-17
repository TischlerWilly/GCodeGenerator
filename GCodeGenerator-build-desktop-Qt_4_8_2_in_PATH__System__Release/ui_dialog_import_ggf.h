/********************************************************************************
** Form generated from reading UI file 'dialog_import_ggf.ui'
**
** Created: Fri Nov 17 21:27:32 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_IMPORT_GGF_H
#define UI_DIALOG_IMPORT_GGF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_import_ggf
{
public:
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_import;
    QPushButton *pushButton_abbrechen;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_alle;
    QPushButton *pushButton_keine;

    void setupUi(QDialog *Dialog_import_ggf)
    {
        if (Dialog_import_ggf->objectName().isEmpty())
            Dialog_import_ggf->setObjectName(QString::fromUtf8("Dialog_import_ggf"));
        Dialog_import_ggf->resize(626, 483);
        listWidget = new QListWidget(Dialog_import_ggf);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 611, 421));
        layoutWidget = new QWidget(Dialog_import_ggf);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(363, 440, 251, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_import = new QPushButton(layoutWidget);
        pushButton_import->setObjectName(QString::fromUtf8("pushButton_import"));

        horizontalLayout->addWidget(pushButton_import);

        pushButton_abbrechen = new QPushButton(layoutWidget);
        pushButton_abbrechen->setObjectName(QString::fromUtf8("pushButton_abbrechen"));

        horizontalLayout->addWidget(pushButton_abbrechen);

        widget = new QWidget(Dialog_import_ggf);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 440, 151, 29));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_alle = new QPushButton(widget);
        pushButton_alle->setObjectName(QString::fromUtf8("pushButton_alle"));

        horizontalLayout_2->addWidget(pushButton_alle);

        pushButton_keine = new QPushButton(widget);
        pushButton_keine->setObjectName(QString::fromUtf8("pushButton_keine"));

        horizontalLayout_2->addWidget(pushButton_keine);


        retranslateUi(Dialog_import_ggf);

        QMetaObject::connectSlotsByName(Dialog_import_ggf);
    } // setupUi

    void retranslateUi(QDialog *Dialog_import_ggf)
    {
        Dialog_import_ggf->setWindowTitle(QApplication::translate("Dialog_import_ggf", "Import GGF-Datei", 0, QApplication::UnicodeUTF8));
        pushButton_import->setText(QApplication::translate("Dialog_import_ggf", "Importieren", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_import_ggf", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_alle->setText(QApplication::translate("Dialog_import_ggf", "alle", 0, QApplication::UnicodeUTF8));
        pushButton_keine->setText(QApplication::translate("Dialog_import_ggf", "keine", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_import_ggf: public Ui_Dialog_import_ggf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_IMPORT_GGF_H
