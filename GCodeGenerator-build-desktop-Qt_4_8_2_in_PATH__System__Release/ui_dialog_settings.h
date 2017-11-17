/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created: Fri Nov 17 21:27:31 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_settings
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_save;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label_tooltable;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_tooltable;
    QPushButton *pushButton_tooltable;
    QFrame *line_3;
    QLabel *label_werkzeugliste_pfad;
    QFrame *line_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_anz_undo_t;
    QSpinBox *spinBox_anz_undo_t;
    QLabel *label_anz_undo_w;
    QSpinBox *spinBox_anz_undo_w;
    QLabel *label_konfig_pfad;

    void setupUi(QDialog *dialog_settings)
    {
        if (dialog_settings->objectName().isEmpty())
            dialog_settings->setObjectName(QString::fromUtf8("dialog_settings"));
        dialog_settings->resize(730, 505);
        dialog_settings->setModal(true);
        layoutWidget = new QWidget(dialog_settings);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 450, 175, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        layoutWidget1 = new QWidget(dialog_settings);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 50, 661, 131));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(layoutWidget1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_tooltable = new QLabel(layoutWidget1);
        label_tooltable->setObjectName(QString::fromUtf8("label_tooltable"));

        verticalLayout->addWidget(label_tooltable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_tooltable = new QLineEdit(layoutWidget1);
        lineEdit_tooltable->setObjectName(QString::fromUtf8("lineEdit_tooltable"));

        horizontalLayout_2->addWidget(lineEdit_tooltable);

        pushButton_tooltable = new QPushButton(layoutWidget1);
        pushButton_tooltable->setObjectName(QString::fromUtf8("pushButton_tooltable"));

        horizontalLayout_2->addWidget(pushButton_tooltable);


        verticalLayout->addLayout(horizontalLayout_2);

        line_3 = new QFrame(layoutWidget1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_werkzeugliste_pfad = new QLabel(layoutWidget1);
        label_werkzeugliste_pfad->setObjectName(QString::fromUtf8("label_werkzeugliste_pfad"));

        verticalLayout->addWidget(label_werkzeugliste_pfad);

        line_2 = new QFrame(layoutWidget1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        layoutWidget2 = new QWidget(dialog_settings);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 200, 661, 111));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_anz_undo_t = new QLabel(layoutWidget2);
        label_anz_undo_t->setObjectName(QString::fromUtf8("label_anz_undo_t"));

        gridLayout->addWidget(label_anz_undo_t, 0, 0, 1, 1);

        spinBox_anz_undo_t = new QSpinBox(layoutWidget2);
        spinBox_anz_undo_t->setObjectName(QString::fromUtf8("spinBox_anz_undo_t"));

        gridLayout->addWidget(spinBox_anz_undo_t, 0, 1, 1, 1);

        label_anz_undo_w = new QLabel(layoutWidget2);
        label_anz_undo_w->setObjectName(QString::fromUtf8("label_anz_undo_w"));

        gridLayout->addWidget(label_anz_undo_w, 1, 0, 1, 1);

        spinBox_anz_undo_w = new QSpinBox(layoutWidget2);
        spinBox_anz_undo_w->setObjectName(QString::fromUtf8("spinBox_anz_undo_w"));

        gridLayout->addWidget(spinBox_anz_undo_w, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        label_konfig_pfad = new QLabel(dialog_settings);
        label_konfig_pfad->setObjectName(QString::fromUtf8("label_konfig_pfad"));
        label_konfig_pfad->setGeometry(QRect(30, 10, 659, 27));

        retranslateUi(dialog_settings);

        QMetaObject::connectSlotsByName(dialog_settings);
    } // setupUi

    void retranslateUi(QDialog *dialog_settings)
    {
        dialog_settings->setWindowTitle(QApplication::translate("dialog_settings", "Einstellungen", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_settings", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("dialog_settings", "Speichern", 0, QApplication::UnicodeUTF8));
        label_tooltable->setText(QApplication::translate("dialog_settings", "Pfad zur Werkzeugtabelle von EMC2:", 0, QApplication::UnicodeUTF8));
        pushButton_tooltable->setText(QApplication::translate("dialog_settings", "...", 0, QApplication::UnicodeUTF8));
        label_werkzeugliste_pfad->setText(QApplication::translate("dialog_settings", "zeigt den Pfad zur internen Wekzeugtabelle an", 0, QApplication::UnicodeUTF8));
        label_anz_undo_t->setText(QApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Programmliste:", 0, QApplication::UnicodeUTF8));
        label_anz_undo_w->setText(QApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Werkzeugliste:", 0, QApplication::UnicodeUTF8));
        label_konfig_pfad->setText(QApplication::translate("dialog_settings", "zeigt den Pfad zur Konfigurationsdatei an", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_settings: public Ui_dialog_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
