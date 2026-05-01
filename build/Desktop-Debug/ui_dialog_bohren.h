/********************************************************************************
** Form generated from reading UI file 'dialog_bohren.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_BOHREN_H
#define UI_DIALOG_BOHREN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_bohren
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_allg;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_x_var;
    QLabel *label_y_var;
    QLineEdit *lineEdit_x;
    QLabel *label_dm;
    QComboBox *comboBox_wkz;
    QLabel *label_wkz;
    QLabel *label_wkz_var;
    QLabel *label_y;
    QLabel *label_x;
    QLineEdit *lineEdit_y;
    QLabel *label_boti;
    QLabel *label_boti_var;
    QLineEdit *lineEdit_boti;
    QLineEdit *lineEdit_dm;
    QLabel *label_dm_var;
    QWidget *tab_tech;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_anboti_var;
    QLabel *label_zust_var;
    QLineEdit *lineEdit_zust;
    QLineEdit *lineEdit_reboma;
    QLabel *label_bovors;
    QLabel *label_reboma_var;
    QLabel *label_anboti;
    QLabel *label_kom_var;
    QLineEdit *lineEdit_anbovors;
    QLineEdit *lineEdit_bovors;
    QLabel *label_anbovors_var;
    QLabel *label_anbovors;
    QLabel *label_bez;
    QLineEdit *lineEdit_bez;
    QLineEdit *lineEdit_afb;
    QLabel *label_afb_var;
    QLineEdit *lineEdit_anboti;
    QLabel *label_afb;
    QLabel *label_kom;
    QLabel *label_bovors_var;
    QLabel *label_reboma;
    QLabel *label_zust;
    QLineEdit *lineEdit_kom;
    QLabel *label_bez_var;
    QLabel *label_drehzahl;
    QLabel *label_drehzahl_var;
    QLineEdit *lineEdit_drehzahl;
    QWidget *tab_wkz;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label_wkz_kom_wert;
    QLabel *label_autowerte;
    QLabel *label_wkz_fan;
    QLabel *label_wkz_fan_wert;
    QLabel *label_wkz_n_wert;
    QLabel *label_wkz_drehri_wert;
    QLabel *label_wkz_nummer_wert;
    QLabel *label_wkz_nutzl_wert;
    QLabel *label_wkz_name;
    QLabel *label_wkz_nummer;
    QLabel *label_wkz_dm_wert;
    QLabel *label_wkz_dm;
    QLabel *label_wkz_name_wert;
    QLabel *label_wkz_drehri;
    QLabel *label_wkz_kom;
    QLabel *label_wkz_nutzl;
    QLabel *label_wkz_f;
    QLabel *label_wkz_n;
    QLabel *label_wkz_f_wert;
    QFrame *line;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_bohren)
    {
        if (Dialog_bohren->objectName().isEmpty())
            Dialog_bohren->setObjectName("Dialog_bohren");
        Dialog_bohren->resize(538, 617);
        Dialog_bohren->setModal(true);
        tabWidget = new QTabWidget(Dialog_bohren);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 521, 561));
        tab_allg = new QWidget();
        tab_allg->setObjectName("tab_allg");
        layoutWidget = new QWidget(tab_allg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 501, 511));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_x_var = new QLabel(layoutWidget);
        label_x_var->setObjectName("label_x_var");

        gridLayout->addWidget(label_x_var, 2, 1, 1, 1);

        label_y_var = new QLabel(layoutWidget);
        label_y_var->setObjectName("label_y_var");

        gridLayout->addWidget(label_y_var, 3, 1, 1, 1);

        lineEdit_x = new QLineEdit(layoutWidget);
        lineEdit_x->setObjectName("lineEdit_x");

        gridLayout->addWidget(lineEdit_x, 2, 2, 1, 1);

        label_dm = new QLabel(layoutWidget);
        label_dm->setObjectName("label_dm");

        gridLayout->addWidget(label_dm, 1, 0, 1, 1);

        comboBox_wkz = new QComboBox(layoutWidget);
        comboBox_wkz->setObjectName("comboBox_wkz");

        gridLayout->addWidget(comboBox_wkz, 0, 2, 1, 1);

        label_wkz = new QLabel(layoutWidget);
        label_wkz->setObjectName("label_wkz");

        gridLayout->addWidget(label_wkz, 0, 0, 1, 1);

        label_wkz_var = new QLabel(layoutWidget);
        label_wkz_var->setObjectName("label_wkz_var");

        gridLayout->addWidget(label_wkz_var, 0, 1, 1, 1);

        label_y = new QLabel(layoutWidget);
        label_y->setObjectName("label_y");

        gridLayout->addWidget(label_y, 3, 0, 1, 1);

        label_x = new QLabel(layoutWidget);
        label_x->setObjectName("label_x");

        gridLayout->addWidget(label_x, 2, 0, 1, 1);

        lineEdit_y = new QLineEdit(layoutWidget);
        lineEdit_y->setObjectName("lineEdit_y");

        gridLayout->addWidget(lineEdit_y, 3, 2, 1, 1);

        label_boti = new QLabel(layoutWidget);
        label_boti->setObjectName("label_boti");

        gridLayout->addWidget(label_boti, 4, 0, 1, 1);

        label_boti_var = new QLabel(layoutWidget);
        label_boti_var->setObjectName("label_boti_var");

        gridLayout->addWidget(label_boti_var, 4, 1, 1, 1);

        lineEdit_boti = new QLineEdit(layoutWidget);
        lineEdit_boti->setObjectName("lineEdit_boti");

        gridLayout->addWidget(lineEdit_boti, 4, 2, 1, 1);

        lineEdit_dm = new QLineEdit(layoutWidget);
        lineEdit_dm->setObjectName("lineEdit_dm");
        lineEdit_dm->setEnabled(false);

        gridLayout->addWidget(lineEdit_dm, 1, 2, 1, 1);

        label_dm_var = new QLabel(layoutWidget);
        label_dm_var->setObjectName("label_dm_var");

        gridLayout->addWidget(label_dm_var, 1, 1, 1, 1);

        tabWidget->addTab(tab_allg, QString());
        tab_tech = new QWidget();
        tab_tech->setObjectName("tab_tech");
        layoutWidget1 = new QWidget(tab_tech);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 501, 511));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_anboti_var = new QLabel(layoutWidget1);
        label_anboti_var->setObjectName("label_anboti_var");

        gridLayout_2->addWidget(label_anboti_var, 0, 1, 1, 1);

        label_zust_var = new QLabel(layoutWidget1);
        label_zust_var->setObjectName("label_zust_var");

        gridLayout_2->addWidget(label_zust_var, 1, 1, 1, 1);

        lineEdit_zust = new QLineEdit(layoutWidget1);
        lineEdit_zust->setObjectName("lineEdit_zust");

        gridLayout_2->addWidget(lineEdit_zust, 1, 2, 1, 1);

        lineEdit_reboma = new QLineEdit(layoutWidget1);
        lineEdit_reboma->setObjectName("lineEdit_reboma");

        gridLayout_2->addWidget(lineEdit_reboma, 2, 2, 1, 1);

        label_bovors = new QLabel(layoutWidget1);
        label_bovors->setObjectName("label_bovors");

        gridLayout_2->addWidget(label_bovors, 4, 0, 1, 1);

        label_reboma_var = new QLabel(layoutWidget1);
        label_reboma_var->setObjectName("label_reboma_var");

        gridLayout_2->addWidget(label_reboma_var, 2, 1, 1, 1);

        label_anboti = new QLabel(layoutWidget1);
        label_anboti->setObjectName("label_anboti");

        gridLayout_2->addWidget(label_anboti, 0, 0, 1, 1);

        label_kom_var = new QLabel(layoutWidget1);
        label_kom_var->setObjectName("label_kom_var");

        gridLayout_2->addWidget(label_kom_var, 6, 1, 1, 1);

        lineEdit_anbovors = new QLineEdit(layoutWidget1);
        lineEdit_anbovors->setObjectName("lineEdit_anbovors");

        gridLayout_2->addWidget(lineEdit_anbovors, 3, 2, 1, 1);

        lineEdit_bovors = new QLineEdit(layoutWidget1);
        lineEdit_bovors->setObjectName("lineEdit_bovors");

        gridLayout_2->addWidget(lineEdit_bovors, 4, 2, 1, 1);

        label_anbovors_var = new QLabel(layoutWidget1);
        label_anbovors_var->setObjectName("label_anbovors_var");

        gridLayout_2->addWidget(label_anbovors_var, 3, 1, 1, 1);

        label_anbovors = new QLabel(layoutWidget1);
        label_anbovors->setObjectName("label_anbovors");

        gridLayout_2->addWidget(label_anbovors, 3, 0, 1, 1);

        label_bez = new QLabel(layoutWidget1);
        label_bez->setObjectName("label_bez");

        gridLayout_2->addWidget(label_bez, 7, 0, 1, 1);

        lineEdit_bez = new QLineEdit(layoutWidget1);
        lineEdit_bez->setObjectName("lineEdit_bez");

        gridLayout_2->addWidget(lineEdit_bez, 7, 2, 1, 1);

        lineEdit_afb = new QLineEdit(layoutWidget1);
        lineEdit_afb->setObjectName("lineEdit_afb");

        gridLayout_2->addWidget(lineEdit_afb, 8, 2, 1, 1);

        label_afb_var = new QLabel(layoutWidget1);
        label_afb_var->setObjectName("label_afb_var");

        gridLayout_2->addWidget(label_afb_var, 8, 1, 1, 1);

        lineEdit_anboti = new QLineEdit(layoutWidget1);
        lineEdit_anboti->setObjectName("lineEdit_anboti");

        gridLayout_2->addWidget(lineEdit_anboti, 0, 2, 1, 1);

        label_afb = new QLabel(layoutWidget1);
        label_afb->setObjectName("label_afb");

        gridLayout_2->addWidget(label_afb, 8, 0, 1, 1);

        label_kom = new QLabel(layoutWidget1);
        label_kom->setObjectName("label_kom");

        gridLayout_2->addWidget(label_kom, 6, 0, 1, 1);

        label_bovors_var = new QLabel(layoutWidget1);
        label_bovors_var->setObjectName("label_bovors_var");

        gridLayout_2->addWidget(label_bovors_var, 4, 1, 1, 1);

        label_reboma = new QLabel(layoutWidget1);
        label_reboma->setObjectName("label_reboma");

        gridLayout_2->addWidget(label_reboma, 2, 0, 1, 1);

        label_zust = new QLabel(layoutWidget1);
        label_zust->setObjectName("label_zust");

        gridLayout_2->addWidget(label_zust, 1, 0, 1, 1);

        lineEdit_kom = new QLineEdit(layoutWidget1);
        lineEdit_kom->setObjectName("lineEdit_kom");

        gridLayout_2->addWidget(lineEdit_kom, 6, 2, 1, 1);

        label_bez_var = new QLabel(layoutWidget1);
        label_bez_var->setObjectName("label_bez_var");

        gridLayout_2->addWidget(label_bez_var, 7, 1, 1, 1);

        label_drehzahl = new QLabel(layoutWidget1);
        label_drehzahl->setObjectName("label_drehzahl");

        gridLayout_2->addWidget(label_drehzahl, 5, 0, 1, 1);

        label_drehzahl_var = new QLabel(layoutWidget1);
        label_drehzahl_var->setObjectName("label_drehzahl_var");

        gridLayout_2->addWidget(label_drehzahl_var, 5, 1, 1, 1);

        lineEdit_drehzahl = new QLineEdit(layoutWidget1);
        lineEdit_drehzahl->setObjectName("lineEdit_drehzahl");

        gridLayout_2->addWidget(lineEdit_drehzahl, 5, 2, 1, 1);

        tabWidget->addTab(tab_tech, QString());
        tab_wkz = new QWidget();
        tab_wkz->setObjectName("tab_wkz");
        layoutWidget2 = new QWidget(tab_wkz);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 10, 501, 511));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_wkz_kom_wert = new QLabel(layoutWidget2);
        label_wkz_kom_wert->setObjectName("label_wkz_kom_wert");

        gridLayout_3->addWidget(label_wkz_kom_wert, 5, 1, 1, 1);

        label_autowerte = new QLabel(layoutWidget2);
        label_autowerte->setObjectName("label_autowerte");

        gridLayout_3->addWidget(label_autowerte, 7, 0, 1, 1);

        label_wkz_fan = new QLabel(layoutWidget2);
        label_wkz_fan->setObjectName("label_wkz_fan");

        gridLayout_3->addWidget(label_wkz_fan, 8, 0, 1, 1);

        label_wkz_fan_wert = new QLabel(layoutWidget2);
        label_wkz_fan_wert->setObjectName("label_wkz_fan_wert");

        gridLayout_3->addWidget(label_wkz_fan_wert, 8, 1, 1, 1);

        label_wkz_n_wert = new QLabel(layoutWidget2);
        label_wkz_n_wert->setObjectName("label_wkz_n_wert");

        gridLayout_3->addWidget(label_wkz_n_wert, 10, 1, 1, 1);

        label_wkz_drehri_wert = new QLabel(layoutWidget2);
        label_wkz_drehri_wert->setObjectName("label_wkz_drehri_wert");

        gridLayout_3->addWidget(label_wkz_drehri_wert, 2, 1, 1, 1);

        label_wkz_nummer_wert = new QLabel(layoutWidget2);
        label_wkz_nummer_wert->setObjectName("label_wkz_nummer_wert");

        gridLayout_3->addWidget(label_wkz_nummer_wert, 0, 1, 1, 1);

        label_wkz_nutzl_wert = new QLabel(layoutWidget2);
        label_wkz_nutzl_wert->setObjectName("label_wkz_nutzl_wert");

        gridLayout_3->addWidget(label_wkz_nutzl_wert, 4, 1, 1, 1);

        label_wkz_name = new QLabel(layoutWidget2);
        label_wkz_name->setObjectName("label_wkz_name");

        gridLayout_3->addWidget(label_wkz_name, 1, 0, 1, 1);

        label_wkz_nummer = new QLabel(layoutWidget2);
        label_wkz_nummer->setObjectName("label_wkz_nummer");

        gridLayout_3->addWidget(label_wkz_nummer, 0, 0, 1, 1);

        label_wkz_dm_wert = new QLabel(layoutWidget2);
        label_wkz_dm_wert->setObjectName("label_wkz_dm_wert");

        gridLayout_3->addWidget(label_wkz_dm_wert, 3, 1, 1, 1);

        label_wkz_dm = new QLabel(layoutWidget2);
        label_wkz_dm->setObjectName("label_wkz_dm");

        gridLayout_3->addWidget(label_wkz_dm, 3, 0, 1, 1);

        label_wkz_name_wert = new QLabel(layoutWidget2);
        label_wkz_name_wert->setObjectName("label_wkz_name_wert");

        gridLayout_3->addWidget(label_wkz_name_wert, 1, 1, 1, 1);

        label_wkz_drehri = new QLabel(layoutWidget2);
        label_wkz_drehri->setObjectName("label_wkz_drehri");

        gridLayout_3->addWidget(label_wkz_drehri, 2, 0, 1, 1);

        label_wkz_kom = new QLabel(layoutWidget2);
        label_wkz_kom->setObjectName("label_wkz_kom");

        gridLayout_3->addWidget(label_wkz_kom, 5, 0, 1, 1);

        label_wkz_nutzl = new QLabel(layoutWidget2);
        label_wkz_nutzl->setObjectName("label_wkz_nutzl");

        gridLayout_3->addWidget(label_wkz_nutzl, 4, 0, 1, 1);

        label_wkz_f = new QLabel(layoutWidget2);
        label_wkz_f->setObjectName("label_wkz_f");

        gridLayout_3->addWidget(label_wkz_f, 9, 0, 1, 1);

        label_wkz_n = new QLabel(layoutWidget2);
        label_wkz_n->setObjectName("label_wkz_n");

        gridLayout_3->addWidget(label_wkz_n, 10, 0, 1, 1);

        label_wkz_f_wert = new QLabel(layoutWidget2);
        label_wkz_f_wert->setObjectName("label_wkz_f_wert");

        gridLayout_3->addWidget(label_wkz_f_wert, 9, 1, 1, 1);

        line = new QFrame(layoutWidget2);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_3->addWidget(line, 6, 0, 1, 2);

        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 5);
        tabWidget->addTab(tab_wkz, QString());
        layoutWidget3 = new QWidget(Dialog_bohren);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(120, 580, 411, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_abbrechen = new QPushButton(layoutWidget3);
        pushButton_abbrechen->setObjectName("pushButton_abbrechen");

        horizontalLayout->addWidget(pushButton_abbrechen);

        pushButton_speichern = new QPushButton(layoutWidget3);
        pushButton_speichern->setObjectName("pushButton_speichern");

        horizontalLayout->addWidget(pushButton_speichern);

        pushButton_ok = new QPushButton(layoutWidget3);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        QWidget::setTabOrder(comboBox_wkz, lineEdit_dm);
        QWidget::setTabOrder(lineEdit_dm, lineEdit_x);
        QWidget::setTabOrder(lineEdit_x, lineEdit_y);
        QWidget::setTabOrder(lineEdit_y, lineEdit_boti);
        QWidget::setTabOrder(lineEdit_boti, tabWidget);
        QWidget::setTabOrder(tabWidget, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, lineEdit_anboti);
        QWidget::setTabOrder(lineEdit_anboti, lineEdit_zust);
        QWidget::setTabOrder(lineEdit_zust, lineEdit_reboma);
        QWidget::setTabOrder(lineEdit_reboma, lineEdit_anbovors);
        QWidget::setTabOrder(lineEdit_anbovors, lineEdit_bovors);
        QWidget::setTabOrder(lineEdit_bovors, lineEdit_drehzahl);
        QWidget::setTabOrder(lineEdit_drehzahl, lineEdit_kom);
        QWidget::setTabOrder(lineEdit_kom, lineEdit_bez);
        QWidget::setTabOrder(lineEdit_bez, lineEdit_afb);

        retranslateUi(Dialog_bohren);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog_bohren);
    } // setupUi

    void retranslateUi(QDialog *Dialog_bohren)
    {
        Dialog_bohren->setWindowTitle(QCoreApplication::translate("Dialog_bohren", "Bohren", nullptr));
        label_x_var->setText(QCoreApplication::translate("Dialog_bohren", "[*X]", nullptr));
        label_y_var->setText(QCoreApplication::translate("Dialog_bohren", "[*Y]", nullptr));
        label_dm->setText(QCoreApplication::translate("Dialog_bohren", "Durchmesser", nullptr));
        label_wkz->setText(QCoreApplication::translate("Dialog_bohren", "Werkzeug", nullptr));
        label_wkz_var->setText(QCoreApplication::translate("Dialog_bohren", "[WKZ]", nullptr));
        label_y->setText(QCoreApplication::translate("Dialog_bohren", "Mittelpunkt Y", nullptr));
        label_x->setText(QCoreApplication::translate("Dialog_bohren", "Mittelpunkt X", nullptr));
        label_boti->setText(QCoreApplication::translate("Dialog_bohren", "Tiefe", nullptr));
        label_boti_var->setText(QCoreApplication::translate("Dialog_bohren", "[*BT]", nullptr));
        label_dm_var->setText(QCoreApplication::translate("Dialog_bohren", "[*DM]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_allg), QCoreApplication::translate("Dialog_bohren", "allgemein", nullptr));
        label_anboti_var->setText(QCoreApplication::translate("Dialog_bohren", "[ANBT]", nullptr));
        label_zust_var->setText(QCoreApplication::translate("Dialog_bohren", "[ZUST]", nullptr));
        label_bovors->setText(QCoreApplication::translate("Dialog_bohren", "Bohrvorschub", nullptr));
        label_reboma_var->setText(QCoreApplication::translate("Dialog_bohren", "[REBT]", nullptr));
        label_anboti->setText(QCoreApplication::translate("Dialog_bohren", "Anbohrtiefe", nullptr));
        label_kom_var->setText(QCoreApplication::translate("Dialog_bohren", "[KOM]", nullptr));
        label_anbovors_var->setText(QCoreApplication::translate("Dialog_bohren", "[FAN]", nullptr));
        label_anbovors->setText(QCoreApplication::translate("Dialog_bohren", "Anbohrvorschub", nullptr));
        label_bez->setText(QCoreApplication::translate("Dialog_bohren", "Bezeichnung", nullptr));
        label_afb_var->setText(QCoreApplication::translate("Dialog_bohren", "[AFB]", nullptr));
        label_afb->setText(QCoreApplication::translate("Dialog_bohren", "Ausf\303\274hrbedingung", nullptr));
        label_kom->setText(QCoreApplication::translate("Dialog_bohren", "Kommentar", nullptr));
        label_bovors_var->setText(QCoreApplication::translate("Dialog_bohren", "[F]", nullptr));
        label_reboma->setText(QCoreApplication::translate("Dialog_bohren", "Restbohrma\303\237", nullptr));
        label_zust->setText(QCoreApplication::translate("Dialog_bohren", "Zustellma\303\237", nullptr));
        label_bez_var->setText(QCoreApplication::translate("Dialog_bohren", "[BEZ]", nullptr));
        label_drehzahl->setText(QCoreApplication::translate("Dialog_bohren", "Drehzahl", nullptr));
        label_drehzahl_var->setText(QCoreApplication::translate("Dialog_bohren", "[N]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_tech), QCoreApplication::translate("Dialog_bohren", "Technologie", nullptr));
        label_wkz_kom_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_autowerte->setText(QCoreApplication::translate("Dialog_bohren", "AUTO-Werte:", nullptr));
        label_wkz_fan->setText(QCoreApplication::translate("Dialog_bohren", "Eintauchvorschub", nullptr));
        label_wkz_fan_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_n_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_drehri_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_nummer_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_nutzl_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_name->setText(QCoreApplication::translate("Dialog_bohren", "Name", nullptr));
        label_wkz_nummer->setText(QCoreApplication::translate("Dialog_bohren", "Nummer", nullptr));
        label_wkz_dm_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_dm->setText(QCoreApplication::translate("Dialog_bohren", "Durchmesser", nullptr));
        label_wkz_name_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        label_wkz_drehri->setText(QCoreApplication::translate("Dialog_bohren", "Drehrichtung", nullptr));
        label_wkz_kom->setText(QCoreApplication::translate("Dialog_bohren", "Kommentar", nullptr));
        label_wkz_nutzl->setText(QCoreApplication::translate("Dialog_bohren", "Nutzl\303\244nge", nullptr));
        label_wkz_f->setText(QCoreApplication::translate("Dialog_bohren", "Vorschub", nullptr));
        label_wkz_n->setText(QCoreApplication::translate("Dialog_bohren", "Drehzahl", nullptr));
        label_wkz_f_wert->setText(QCoreApplication::translate("Dialog_bohren", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_wkz), QCoreApplication::translate("Dialog_bohren", "Werkzeug", nullptr));
        pushButton_abbrechen->setText(QCoreApplication::translate("Dialog_bohren", "Abbrechen", nullptr));
        pushButton_speichern->setText(QCoreApplication::translate("Dialog_bohren", "Speichern", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Dialog_bohren", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_bohren: public Ui_Dialog_bohren {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_BOHREN_H
