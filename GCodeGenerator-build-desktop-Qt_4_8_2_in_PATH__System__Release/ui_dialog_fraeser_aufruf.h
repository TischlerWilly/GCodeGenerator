/********************************************************************************
** Form generated from reading UI file 'dialog_fraeser_aufruf.ui'
**
** Created: Sat Nov 18 22:23:19 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FRAESER_AUFRUF_H
#define UI_DIALOG_FRAESER_AUFRUF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Fraeser_Aufruf
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_kantdi;
    QLabel *label_startz;
    QLabel *label_startx;
    QLabel *label_starty;
    QLabel *label_starty_var;
    QComboBox *comboBox_werkzeug;
    QLabel *label__bahnkor_var;
    QComboBox *comboBox__bahnkor;
    QLabel *label_werkzeug;
    QLabel *label__werkzeug_var;
    QLabel *label_bahnkor;
    QLabel *label_startz_var;
    QLabel *label_eckruglob;
    QLabel *label__eckruglob_var;
    QLineEdit *lineEdit_starty;
    QLabel *label_kantdi_var;
    QLineEdit *lineEdit_eckruglob;
    QLineEdit *lineEdit_startz;
    QLineEdit *lineEdit_kantdi;
    QLineEdit *lineEdit_startx;
    QLabel *label__startx_var;
    QLabel *label_bild_fraeser;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_abftyp;
    QLabel *label_ausfbed_var;
    QLineEdit *lineEdit_ausfbed;
    QLabel *label_bezeichn;
    QLabel *label_komment;
    QLabel *label_vorschub;
    QLabel *label_ausfbed;
    QLineEdit *lineEdit_bezeichn;
    QLabel *label_drehzahl;
    QLabel *label_komment_var;
    QLabel *label_bezeichn_var;
    QLineEdit *lineEdit_komment;
    QLabel *label_anftyp;
    QLabel *label_eintvors;
    QLabel *label_abftyp_var;
    QLabel *label_anftyp_var;
    QLabel *label_drehzahl_var;
    QLabel *label_vorschub_var;
    QLabel *label_eintvors_var;
    QLineEdit *lineEdit_eintvors;
    QLineEdit *lineEdit_vorschub;
    QLineEdit *lineEdit_drehzahl;
    QComboBox *comboBox_anftyp;
    QComboBox *comboBox_abftyp;
    QLabel *label__zustellung;
    QLabel *label_zustellung_var;
    QLineEdit *lineEdit_zustellung;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_abbrechen;
    QPushButton *pushButton_speichern;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Dialog_Fraeser_Aufruf)
    {
        if (Dialog_Fraeser_Aufruf->objectName().isEmpty())
            Dialog_Fraeser_Aufruf->setObjectName(QString::fromUtf8("Dialog_Fraeser_Aufruf"));
        Dialog_Fraeser_Aufruf->resize(603, 658);
        tabWidget = new QTabWidget(Dialog_Fraeser_Aufruf);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 581, 601));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 561, 291));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_kantdi = new QLabel(layoutWidget);
        label_kantdi->setObjectName(QString::fromUtf8("label_kantdi"));

        gridLayout->addWidget(label_kantdi, 6, 0, 1, 1);

        label_startz = new QLabel(layoutWidget);
        label_startz->setObjectName(QString::fromUtf8("label_startz"));

        gridLayout->addWidget(label_startz, 4, 0, 1, 1);

        label_startx = new QLabel(layoutWidget);
        label_startx->setObjectName(QString::fromUtf8("label_startx"));

        gridLayout->addWidget(label_startx, 2, 0, 1, 1);

        label_starty = new QLabel(layoutWidget);
        label_starty->setObjectName(QString::fromUtf8("label_starty"));

        gridLayout->addWidget(label_starty, 3, 0, 1, 1);

        label_starty_var = new QLabel(layoutWidget);
        label_starty_var->setObjectName(QString::fromUtf8("label_starty_var"));

        gridLayout->addWidget(label_starty_var, 3, 1, 1, 1);

        comboBox_werkzeug = new QComboBox(layoutWidget);
        comboBox_werkzeug->setObjectName(QString::fromUtf8("comboBox_werkzeug"));

        gridLayout->addWidget(comboBox_werkzeug, 0, 2, 1, 1);

        label__bahnkor_var = new QLabel(layoutWidget);
        label__bahnkor_var->setObjectName(QString::fromUtf8("label__bahnkor_var"));

        gridLayout->addWidget(label__bahnkor_var, 1, 1, 1, 1);

        comboBox__bahnkor = new QComboBox(layoutWidget);
        comboBox__bahnkor->setObjectName(QString::fromUtf8("comboBox__bahnkor"));

        gridLayout->addWidget(comboBox__bahnkor, 1, 2, 1, 1);

        label_werkzeug = new QLabel(layoutWidget);
        label_werkzeug->setObjectName(QString::fromUtf8("label_werkzeug"));

        gridLayout->addWidget(label_werkzeug, 0, 0, 1, 1);

        label__werkzeug_var = new QLabel(layoutWidget);
        label__werkzeug_var->setObjectName(QString::fromUtf8("label__werkzeug_var"));

        gridLayout->addWidget(label__werkzeug_var, 0, 1, 1, 1);

        label_bahnkor = new QLabel(layoutWidget);
        label_bahnkor->setObjectName(QString::fromUtf8("label_bahnkor"));

        gridLayout->addWidget(label_bahnkor, 1, 0, 1, 1);

        label_startz_var = new QLabel(layoutWidget);
        label_startz_var->setObjectName(QString::fromUtf8("label_startz_var"));

        gridLayout->addWidget(label_startz_var, 4, 1, 1, 1);

        label_eckruglob = new QLabel(layoutWidget);
        label_eckruglob->setObjectName(QString::fromUtf8("label_eckruglob"));

        gridLayout->addWidget(label_eckruglob, 5, 0, 1, 1);

        label__eckruglob_var = new QLabel(layoutWidget);
        label__eckruglob_var->setObjectName(QString::fromUtf8("label__eckruglob_var"));

        gridLayout->addWidget(label__eckruglob_var, 5, 1, 1, 1);

        lineEdit_starty = new QLineEdit(layoutWidget);
        lineEdit_starty->setObjectName(QString::fromUtf8("lineEdit_starty"));

        gridLayout->addWidget(lineEdit_starty, 3, 2, 1, 1);

        label_kantdi_var = new QLabel(layoutWidget);
        label_kantdi_var->setObjectName(QString::fromUtf8("label_kantdi_var"));

        gridLayout->addWidget(label_kantdi_var, 6, 1, 1, 1);

        lineEdit_eckruglob = new QLineEdit(layoutWidget);
        lineEdit_eckruglob->setObjectName(QString::fromUtf8("lineEdit_eckruglob"));

        gridLayout->addWidget(lineEdit_eckruglob, 5, 2, 1, 1);

        lineEdit_startz = new QLineEdit(layoutWidget);
        lineEdit_startz->setObjectName(QString::fromUtf8("lineEdit_startz"));

        gridLayout->addWidget(lineEdit_startz, 4, 2, 1, 1);

        lineEdit_kantdi = new QLineEdit(layoutWidget);
        lineEdit_kantdi->setObjectName(QString::fromUtf8("lineEdit_kantdi"));

        gridLayout->addWidget(lineEdit_kantdi, 6, 2, 1, 1);

        lineEdit_startx = new QLineEdit(layoutWidget);
        lineEdit_startx->setObjectName(QString::fromUtf8("lineEdit_startx"));

        gridLayout->addWidget(lineEdit_startx, 2, 2, 1, 1);

        label__startx_var = new QLabel(layoutWidget);
        label__startx_var->setObjectName(QString::fromUtf8("label__startx_var"));

        gridLayout->addWidget(label__startx_var, 2, 1, 1, 1);

        label_bild_fraeser = new QLabel(tab);
        label_bild_fraeser->setObjectName(QString::fromUtf8("label_bild_fraeser"));
        label_bild_fraeser->setGeometry(QRect(120, 315, 281, 251));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 7, 551, 551));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_abftyp = new QLabel(layoutWidget1);
        label_abftyp->setObjectName(QString::fromUtf8("label_abftyp"));

        gridLayout_2->addWidget(label_abftyp, 5, 0, 1, 1);

        label_ausfbed_var = new QLabel(layoutWidget1);
        label_ausfbed_var->setObjectName(QString::fromUtf8("label_ausfbed_var"));

        gridLayout_2->addWidget(label_ausfbed_var, 8, 1, 1, 1);

        lineEdit_ausfbed = new QLineEdit(layoutWidget1);
        lineEdit_ausfbed->setObjectName(QString::fromUtf8("lineEdit_ausfbed"));

        gridLayout_2->addWidget(lineEdit_ausfbed, 8, 2, 1, 1);

        label_bezeichn = new QLabel(layoutWidget1);
        label_bezeichn->setObjectName(QString::fromUtf8("label_bezeichn"));

        gridLayout_2->addWidget(label_bezeichn, 7, 0, 1, 1);

        label_komment = new QLabel(layoutWidget1);
        label_komment->setObjectName(QString::fromUtf8("label_komment"));

        gridLayout_2->addWidget(label_komment, 6, 0, 1, 1);

        label_vorschub = new QLabel(layoutWidget1);
        label_vorschub->setObjectName(QString::fromUtf8("label_vorschub"));

        gridLayout_2->addWidget(label_vorschub, 2, 0, 1, 1);

        label_ausfbed = new QLabel(layoutWidget1);
        label_ausfbed->setObjectName(QString::fromUtf8("label_ausfbed"));

        gridLayout_2->addWidget(label_ausfbed, 8, 0, 1, 1);

        lineEdit_bezeichn = new QLineEdit(layoutWidget1);
        lineEdit_bezeichn->setObjectName(QString::fromUtf8("lineEdit_bezeichn"));

        gridLayout_2->addWidget(lineEdit_bezeichn, 7, 2, 1, 1);

        label_drehzahl = new QLabel(layoutWidget1);
        label_drehzahl->setObjectName(QString::fromUtf8("label_drehzahl"));

        gridLayout_2->addWidget(label_drehzahl, 3, 0, 1, 1);

        label_komment_var = new QLabel(layoutWidget1);
        label_komment_var->setObjectName(QString::fromUtf8("label_komment_var"));

        gridLayout_2->addWidget(label_komment_var, 6, 1, 1, 1);

        label_bezeichn_var = new QLabel(layoutWidget1);
        label_bezeichn_var->setObjectName(QString::fromUtf8("label_bezeichn_var"));

        gridLayout_2->addWidget(label_bezeichn_var, 7, 1, 1, 1);

        lineEdit_komment = new QLineEdit(layoutWidget1);
        lineEdit_komment->setObjectName(QString::fromUtf8("lineEdit_komment"));

        gridLayout_2->addWidget(lineEdit_komment, 6, 2, 1, 1);

        label_anftyp = new QLabel(layoutWidget1);
        label_anftyp->setObjectName(QString::fromUtf8("label_anftyp"));

        gridLayout_2->addWidget(label_anftyp, 4, 0, 1, 1);

        label_eintvors = new QLabel(layoutWidget1);
        label_eintvors->setObjectName(QString::fromUtf8("label_eintvors"));

        gridLayout_2->addWidget(label_eintvors, 1, 0, 1, 1);

        label_abftyp_var = new QLabel(layoutWidget1);
        label_abftyp_var->setObjectName(QString::fromUtf8("label_abftyp_var"));

        gridLayout_2->addWidget(label_abftyp_var, 5, 1, 1, 1);

        label_anftyp_var = new QLabel(layoutWidget1);
        label_anftyp_var->setObjectName(QString::fromUtf8("label_anftyp_var"));

        gridLayout_2->addWidget(label_anftyp_var, 4, 1, 1, 1);

        label_drehzahl_var = new QLabel(layoutWidget1);
        label_drehzahl_var->setObjectName(QString::fromUtf8("label_drehzahl_var"));

        gridLayout_2->addWidget(label_drehzahl_var, 3, 1, 1, 1);

        label_vorschub_var = new QLabel(layoutWidget1);
        label_vorschub_var->setObjectName(QString::fromUtf8("label_vorschub_var"));

        gridLayout_2->addWidget(label_vorschub_var, 2, 1, 1, 1);

        label_eintvors_var = new QLabel(layoutWidget1);
        label_eintvors_var->setObjectName(QString::fromUtf8("label_eintvors_var"));

        gridLayout_2->addWidget(label_eintvors_var, 1, 1, 1, 1);

        lineEdit_eintvors = new QLineEdit(layoutWidget1);
        lineEdit_eintvors->setObjectName(QString::fromUtf8("lineEdit_eintvors"));

        gridLayout_2->addWidget(lineEdit_eintvors, 1, 2, 1, 1);

        lineEdit_vorschub = new QLineEdit(layoutWidget1);
        lineEdit_vorschub->setObjectName(QString::fromUtf8("lineEdit_vorschub"));

        gridLayout_2->addWidget(lineEdit_vorschub, 2, 2, 1, 1);

        lineEdit_drehzahl = new QLineEdit(layoutWidget1);
        lineEdit_drehzahl->setObjectName(QString::fromUtf8("lineEdit_drehzahl"));

        gridLayout_2->addWidget(lineEdit_drehzahl, 3, 2, 1, 1);

        comboBox_anftyp = new QComboBox(layoutWidget1);
        comboBox_anftyp->setObjectName(QString::fromUtf8("comboBox_anftyp"));

        gridLayout_2->addWidget(comboBox_anftyp, 4, 2, 1, 1);

        comboBox_abftyp = new QComboBox(layoutWidget1);
        comboBox_abftyp->setObjectName(QString::fromUtf8("comboBox_abftyp"));

        gridLayout_2->addWidget(comboBox_abftyp, 5, 2, 1, 1);

        label__zustellung = new QLabel(layoutWidget1);
        label__zustellung->setObjectName(QString::fromUtf8("label__zustellung"));

        gridLayout_2->addWidget(label__zustellung, 0, 0, 1, 1);

        label_zustellung_var = new QLabel(layoutWidget1);
        label_zustellung_var->setObjectName(QString::fromUtf8("label_zustellung_var"));

        gridLayout_2->addWidget(label_zustellung_var, 0, 1, 1, 1);

        lineEdit_zustellung = new QLineEdit(layoutWidget1);
        lineEdit_zustellung->setObjectName(QString::fromUtf8("lineEdit_zustellung"));

        gridLayout_2->addWidget(lineEdit_zustellung, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        layoutWidget2 = new QWidget(Dialog_Fraeser_Aufruf);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(250, 620, 341, 31));
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

        QWidget::setTabOrder(comboBox_werkzeug, comboBox__bahnkor);
        QWidget::setTabOrder(comboBox__bahnkor, lineEdit_startx);
        QWidget::setTabOrder(lineEdit_startx, lineEdit_starty);
        QWidget::setTabOrder(lineEdit_starty, lineEdit_startz);
        QWidget::setTabOrder(lineEdit_startz, lineEdit_eckruglob);
        QWidget::setTabOrder(lineEdit_eckruglob, lineEdit_kantdi);
        QWidget::setTabOrder(lineEdit_kantdi, lineEdit_zustellung);
        QWidget::setTabOrder(lineEdit_zustellung, lineEdit_eintvors);
        QWidget::setTabOrder(lineEdit_eintvors, lineEdit_vorschub);
        QWidget::setTabOrder(lineEdit_vorschub, lineEdit_drehzahl);
        QWidget::setTabOrder(lineEdit_drehzahl, comboBox_anftyp);
        QWidget::setTabOrder(comboBox_anftyp, comboBox_abftyp);
        QWidget::setTabOrder(comboBox_abftyp, lineEdit_komment);
        QWidget::setTabOrder(lineEdit_komment, lineEdit_bezeichn);
        QWidget::setTabOrder(lineEdit_bezeichn, lineEdit_ausfbed);
        QWidget::setTabOrder(lineEdit_ausfbed, pushButton_abbrechen);
        QWidget::setTabOrder(pushButton_abbrechen, pushButton_speichern);
        QWidget::setTabOrder(pushButton_speichern, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, tabWidget);

        retranslateUi(Dialog_Fraeser_Aufruf);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_Fraeser_Aufruf);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Fraeser_Aufruf)
    {
        Dialog_Fraeser_Aufruf->setWindowTitle(QApplication::translate("Dialog_Fraeser_Aufruf", "Fraeser-Aufruf", 0, QApplication::UnicodeUTF8));
        label_kantdi->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Kantendicke", 0, QApplication::UnicodeUTF8));
        label_startz->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Startpunkt Z", 0, QApplication::UnicodeUTF8));
        label_startx->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Startpunkt X", 0, QApplication::UnicodeUTF8));
        label_starty->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Startpunkt Y", 0, QApplication::UnicodeUTF8));
        label_starty_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "*[Y]", 0, QApplication::UnicodeUTF8));
        label__bahnkor_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[BKO]", 0, QApplication::UnicodeUTF8));
        label_werkzeug->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Werkzeug", 0, QApplication::UnicodeUTF8));
        label__werkzeug_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[WKZ]", 0, QApplication::UnicodeUTF8));
        label_bahnkor->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Bahnkorrektur", 0, QApplication::UnicodeUTF8));
        label_startz_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "*[Z]", 0, QApplication::UnicodeUTF8));
        label_eckruglob->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Eckenrunden Global", 0, QApplication::UnicodeUTF8));
        label__eckruglob_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "*[ERG]", 0, QApplication::UnicodeUTF8));
        label_kantdi_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[KD]", 0, QApplication::UnicodeUTF8));
        label__startx_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "*[X]", 0, QApplication::UnicodeUTF8));
        label_bild_fraeser->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Bild des Fr\303\244sers", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog_Fraeser_Aufruf", "allgemein", 0, QApplication::UnicodeUTF8));
        label_abftyp->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Abfahrtyp", 0, QApplication::UnicodeUTF8));
        label_ausfbed_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "*[AFB]", 0, QApplication::UnicodeUTF8));
        label_bezeichn->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Bezeichnung", 0, QApplication::UnicodeUTF8));
        label_komment->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Kommentar", 0, QApplication::UnicodeUTF8));
        label_vorschub->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Vorschub XY", 0, QApplication::UnicodeUTF8));
        label_ausfbed->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Ausf\303\274hrbedingung", 0, QApplication::UnicodeUTF8));
        label_drehzahl->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Drehzahl", 0, QApplication::UnicodeUTF8));
        label_komment_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[KOM]", 0, QApplication::UnicodeUTF8));
        label_bezeichn_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[BEZ]", 0, QApplication::UnicodeUTF8));
        label_anftyp->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Anfahrtyp", 0, QApplication::UnicodeUTF8));
        label_eintvors->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Eintauchvorschub", 0, QApplication::UnicodeUTF8));
        label_abftyp_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[ANT]", 0, QApplication::UnicodeUTF8));
        label_anftyp_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[ABT]", 0, QApplication::UnicodeUTF8));
        label_drehzahl_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[N]", 0, QApplication::UnicodeUTF8));
        label_vorschub_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[F]", 0, QApplication::UnicodeUTF8));
        label_eintvors_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[FAN]", 0, QApplication::UnicodeUTF8));
        label__zustellung->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Zustellmass", 0, QApplication::UnicodeUTF8));
        label_zustellung_var->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "[ZUST]", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog_Fraeser_Aufruf", "Technologie", 0, QApplication::UnicodeUTF8));
        pushButton_abbrechen->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Abbrechen", 0, QApplication::UnicodeUTF8));
        pushButton_speichern->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("Dialog_Fraeser_Aufruf", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Fraeser_Aufruf: public Ui_Dialog_Fraeser_Aufruf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FRAESER_AUFRUF_H
