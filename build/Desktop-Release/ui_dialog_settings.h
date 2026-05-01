/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_tooltable;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_tooltable;
    QPushButton *pushButton_tooltable;
    QFrame *line_3;
    QLabel *label_werkzeugliste_pfad;
    QCheckBox *checkBox_fkon_berechnen;
    QWidget *tab_2;
    QWidget *layoutWidget3;
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
            dialog_settings->setObjectName("dialog_settings");
        dialog_settings->resize(730, 505);
        dialog_settings->setModal(true);
        layoutWidget = new QWidget(dialog_settings);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(290, 450, 175, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_save = new QPushButton(layoutWidget);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        label_konfig_pfad = new QLabel(dialog_settings);
        label_konfig_pfad->setObjectName("label_konfig_pfad");
        label_konfig_pfad->setGeometry(QRect(30, 10, 659, 27));
        tabWidget = new QTabWidget(dialog_settings);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 40, 711, 401));
        tab = new QWidget();
        tab->setObjectName("tab");
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 130, 691, 81));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_anz_undo_t = new QLabel(layoutWidget1);
        label_anz_undo_t->setObjectName("label_anz_undo_t");

        gridLayout->addWidget(label_anz_undo_t, 0, 0, 1, 1);

        spinBox_anz_undo_t = new QSpinBox(layoutWidget1);
        spinBox_anz_undo_t->setObjectName("spinBox_anz_undo_t");

        gridLayout->addWidget(spinBox_anz_undo_t, 0, 1, 1, 1);

        label_anz_undo_w = new QLabel(layoutWidget1);
        label_anz_undo_w->setObjectName("label_anz_undo_w");

        gridLayout->addWidget(label_anz_undo_w, 1, 0, 1, 1);

        spinBox_anz_undo_w = new QSpinBox(layoutWidget1);
        spinBox_anz_undo_w->setObjectName("spinBox_anz_undo_w");

        gridLayout->addWidget(spinBox_anz_undo_w, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 10, 691, 111));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_tooltable = new QLabel(layoutWidget2);
        label_tooltable->setObjectName("label_tooltable");

        verticalLayout->addWidget(label_tooltable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_tooltable = new QLineEdit(layoutWidget2);
        lineEdit_tooltable->setObjectName("lineEdit_tooltable");

        horizontalLayout_3->addWidget(lineEdit_tooltable);

        pushButton_tooltable = new QPushButton(layoutWidget2);
        pushButton_tooltable->setObjectName("pushButton_tooltable");

        horizontalLayout_3->addWidget(pushButton_tooltable);


        verticalLayout->addLayout(horizontalLayout_3);

        line_3 = new QFrame(layoutWidget2);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        label_werkzeugliste_pfad = new QLabel(layoutWidget2);
        label_werkzeugliste_pfad->setObjectName("label_werkzeugliste_pfad");

        verticalLayout->addWidget(label_werkzeugliste_pfad);

        checkBox_fkon_berechnen = new QCheckBox(tab);
        checkBox_fkon_berechnen->setObjectName("checkBox_fkon_berechnen");
        checkBox_fkon_berechnen->setGeometry(QRect(10, 220, 691, 20));
        tabWidget->addTab(tab, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        checkBox_fkon_berechnen->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 10, 681, 351));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 8, 2, 1, 1);

        label_dxf_info = new QLabel(layoutWidget3);
        label_dxf_info->setObjectName("label_dxf_info");
        label_dxf_info->setWordWrap(true);

        gridLayout_2->addWidget(label_dxf_info, 5, 0, 1, 3);

        checkBox_dxf_klasse = new QCheckBox(layoutWidget3);
        checkBox_dxf_klasse->setObjectName("checkBox_dxf_klasse");

        gridLayout_2->addWidget(checkBox_dxf_klasse, 7, 0, 1, 2);

        lineEdit_dxf_klasse = new QLineEdit(layoutWidget3);
        lineEdit_dxf_klasse->setObjectName("lineEdit_dxf_klasse");

        gridLayout_2->addWidget(lineEdit_dxf_klasse, 7, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        lineEdit_dxf_wstnp = new QLineEdit(layoutWidget3);
        lineEdit_dxf_wstnp->setObjectName("lineEdit_dxf_wstnp");

        gridLayout_2->addWidget(lineEdit_dxf_wstnp, 3, 1, 1, 2);

        label_dxf_Headline = new QLabel(layoutWidget3);
        label_dxf_Headline->setObjectName("label_dxf_Headline");

        gridLayout_2->addWidget(label_dxf_Headline, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        label_dxf_wstnp = new QLabel(layoutWidget3);
        label_dxf_wstnp->setObjectName("label_dxf_wstnp");

        gridLayout_2->addWidget(label_dxf_wstnp, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

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
        dialog_settings->setWindowTitle(QCoreApplication::translate("dialog_settings", "Einstellungen", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("dialog_settings", "Abbrechen", nullptr));
        pushButton_save->setText(QCoreApplication::translate("dialog_settings", "Speichern", nullptr));
        label_konfig_pfad->setText(QCoreApplication::translate("dialog_settings", "zeigt den Pfad zur Konfigurationsdatei an", nullptr));
        label_anz_undo_t->setText(QCoreApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Programmliste:", nullptr));
        label_anz_undo_w->setText(QCoreApplication::translate("dialog_settings", "Anzahl der Wiederrufenschritte in der Werkzeugliste:", nullptr));
        label_tooltable->setText(QCoreApplication::translate("dialog_settings", "Pfad zur Werkzeugtabelle von EMC2:", nullptr));
        pushButton_tooltable->setText(QCoreApplication::translate("dialog_settings", "...", nullptr));
        label_werkzeugliste_pfad->setText(QCoreApplication::translate("dialog_settings", "zeigt den Pfad zur internen Wekzeugtabelle an", nullptr));
        checkBox_fkon_berechnen->setText(QCoreApplication::translate("dialog_settings", "Fr\303\244skonturen grafisch darstellen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("dialog_settings", "allgemein", nullptr));
        label_dxf_info->setText(QCoreApplication::translate("dialog_settings", "Wird in der angegebenen Importdatei geneau ein Punkt gefunden, der in der oben festgelegten Klasse liegt, so wird dieser als Koordinatenursprung f\303\274r die Importierten Geometrieen angenommen.", nullptr));
        checkBox_dxf_klasse->setText(QCoreApplication::translate("dialog_settings", "Nur Geometrieen aus dieser Klasse importieren:", nullptr));
        label_dxf_Headline->setText(QCoreApplication::translate("dialog_settings", "Unterstuetzte (importierbare) Geometrieen sind: Punkte, Strecken/Linien, B\303\266gen, Kreise", nullptr));
        label_dxf_wstnp->setText(QCoreApplication::translate("dialog_settings", "Der Werkstuecknullpunkt liegt in der Klasse:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("dialog_settings", "Import DXF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_settings: public Ui_dialog_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
