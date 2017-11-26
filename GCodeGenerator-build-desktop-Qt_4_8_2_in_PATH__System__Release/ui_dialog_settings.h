/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created: Sun Nov 26 20:01:18 2017
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
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
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
    QLabel *label_konfig_pfad;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_anz_undo_t;
    QSpinBox *spinBox_anz_undo_t;
    QLabel *label_anz_undo_w;
    QSpinBox *spinBox_anz_undo_w;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_tooltable;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_tooltable;
    QPushButton *pushButton_tooltable;
    QFrame *line_3;
    QLabel *label_werkzeugliste_pfad;
    QWidget *tab_2;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_dxf_info;
    QCheckBox *checkBox_dxf_klasse;
    QLineEdit *lineEdit_dxf_klasse;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_dxf_wstnp;
    QLabel *label_dxf_Headline;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_dxf_wstnp;
    QSpacerItem *verticalSpacer_5;

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

        label_konfig_pfad = new QLabel(dialog_settings);
        label_konfig_pfad->setObjectName(QString::fromUtf8("label_konfig_pfad"));
        label_konfig_pfad->setGeometry(QRect(30, 10, 659, 27));
        tabWidget = new QTabWidget(dialog_settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 40, 711, 401));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 130, 691, 81));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_anz_undo_t = new QLabel(layoutWidget1);
        label_anz_undo_t->setObjectName(QString::fromUtf8("label_anz_undo_t"));

        gridLayout->addWidget(label_anz_undo_t, 0, 0, 1, 1);

        spinBox_anz_undo_t = new QSpinBox(layoutWidget1);
        spinBox_anz_undo_t->setObjectName(QString::fromUtf8("spinBox_anz_undo_t"));

        gridLayout->addWidget(spinBox_anz_undo_t, 0, 1, 1, 1);

        label_anz_undo_w = new QLabel(layoutWidget1);
        label_anz_undo_w->setObjectName(QString::fromUtf8("label_anz_undo_w"));

        gridLayout->addWidget(label_anz_undo_w, 1, 0, 1, 1);

        spinBox_anz_undo_w = new QSpinBox(layoutWidget1);
        spinBox_anz_undo_w->setObjectName(QString::fromUtf8("spinBox_anz_undo_w"));

        gridLayout->addWidget(spinBox_anz_undo_w, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 691, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_tooltable = new QLabel(widget);
        label_tooltable->setObjectName(QString::fromUtf8("label_tooltable"));

        verticalLayout->addWidget(label_tooltable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_tooltable = new QLineEdit(widget);
        lineEdit_tooltable->setObjectName(QString::fromUtf8("lineEdit_tooltable"));

        horizontalLayout_3->addWidget(lineEdit_tooltable);

        pushButton_tooltable = new QPushButton(widget);
        pushButton_tooltable->setObjectName(QString::fromUtf8("pushButton_tooltable"));

        horizontalLayout_3->addWidget(pushButton_tooltable);


        verticalLayout->addLayout(horizontalLayout_3);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_werkzeugliste_pfad = new QLabel(widget);
        label_werkzeugliste_pfad->setObjectName(QString::fromUtf8("label_werkzeugliste_pfad"));

        verticalLayout->addWidget(label_werkzeugliste_pfad);

        tabWidget->addTab(tab, QString());
        label_tooltable->raise();
        lineEdit_tooltable->raise();
        label_tooltable->raise();
        lineEdit_tooltable->raise();
        pushButton_tooltable->raise();
        line_3->raise();
        label_werkzeugliste_pfad->raise();
        layoutWidget->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget1 = new QWidget(tab_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 10, 681, 351));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 8, 2, 1, 1);

        label_dxf_info = new QLabel(widget1);
        label_dxf_info->setObjectName(QString::fromUtf8("label_dxf_info"));
        label_dxf_info->setWordWrap(true);

        gridLayout_2->addWidget(label_dxf_info, 5, 0, 1, 3);

        checkBox_dxf_klasse = new QCheckBox(widget1);
        checkBox_dxf_klasse->setObjectName(QString::fromUtf8("checkBox_dxf_klasse"));

        gridLayout_2->addWidget(checkBox_dxf_klasse, 7, 0, 1, 2);

        lineEdit_dxf_klasse = new QLineEdit(widget1);
        lineEdit_dxf_klasse->setObjectName(QString::fromUtf8("lineEdit_dxf_klasse"));

        gridLayout_2->addWidget(lineEdit_dxf_klasse, 7, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        lineEdit_dxf_wstnp = new QLineEdit(widget1);
        lineEdit_dxf_wstnp->setObjectName(QString::fromUtf8("lineEdit_dxf_wstnp"));

        gridLayout_2->addWidget(lineEdit_dxf_wstnp, 3, 1, 1, 2);

        label_dxf_Headline = new QLabel(widget1);
        label_dxf_Headline->setObjectName(QString::fromUtf8("label_dxf_Headline"));

        gridLayout_2->addWidget(label_dxf_Headline, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        label_dxf_wstnp = new QLabel(widget1);
        label_dxf_wstnp->setObjectName(QString::fromUtf8("label_dxf_wstnp"));

        gridLayout_2->addWidget(label_dxf_wstnp, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 4, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        QWidget::setTabOrder(tabWidget, lineEdit_tooltable);
        QWidget::setTabOrder(lineEdit_tooltable, pushButton_tooltable);
        QWidget::setTabOrder(pushButton_tooltable, spinBox_anz_undo_t);
        QWidget::setTabOrder(spinBox_anz_undo_t, spinBox_anz_undo_w);
        QWidget::setTabOrder(spinBox_anz_undo_w, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, pushButton_save);
        QWidget::setTabOrder(pushButton_save, lineEdit_dxf_wstnp);
        QWidget::setTabOrder(lineEdit_dxf_wstnp, checkBox_dxf_klasse);
        QWidget::setTabOrder(checkBox_dxf_klasse, lineEdit_dxf_klasse);

        retranslateUi(dialog_settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dialog_settings);
    } // setupUi

    void retranslateUi(QDialog *dialog_settings)
    {
        dialog_settings->setWindowTitle(QApplication::translate("dialog_settings", "Einstellungen", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_settings", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("dialog_settings", "Speichern", 0, QApplication::UnicodeUTF8));
        label_konfig_pfad->setText(QApplication::translate("dialog_settings", "zeigt den Pfad zur Konfigurationsdatei an", 0, QApplication::UnicodeUTF8));
        label_anz_undo_t->setText(QApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Programmliste:", 0, QApplication::UnicodeUTF8));
        label_anz_undo_w->setText(QApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Werkzeugliste:", 0, QApplication::UnicodeUTF8));
        label_tooltable->setText(QApplication::translate("dialog_settings", "Pfad zur Werkzeugtabelle von EMC2:", 0, QApplication::UnicodeUTF8));
        pushButton_tooltable->setText(QApplication::translate("dialog_settings", "...", 0, QApplication::UnicodeUTF8));
        label_werkzeugliste_pfad->setText(QApplication::translate("dialog_settings", "zeigt den Pfad zur internen Wekzeugtabelle an", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("dialog_settings", "allgemein", 0, QApplication::UnicodeUTF8));
        label_dxf_info->setText(QApplication::translate("dialog_settings", "Wird in der angegebenen Importdatei geneau ein Punkt gefunden, der in der oben festgelegten Klasse liegt, so wird dieser als Koordinatenursprung f\303\274r die Importierten Geometrieen angenommen.", 0, QApplication::UnicodeUTF8));
        checkBox_dxf_klasse->setText(QApplication::translate("dialog_settings", "Nur Geometrieen aus dieser Klasse importieren:", 0, QApplication::UnicodeUTF8));
        label_dxf_Headline->setText(QApplication::translate("dialog_settings", "Unterstuetzte (importierbare) Geometrieen sind: Punkte, Strecken/Linien, B\303\266gen, Kreise", 0, QApplication::UnicodeUTF8));
        label_dxf_wstnp->setText(QApplication::translate("dialog_settings", "Der Werkstuecknullpunkt liegt in der Klasse:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("dialog_settings", "Import DXF", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_settings: public Ui_dialog_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
