/********************************************************************************
** Form generated from reading UI file 'newprobdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROBDIALOG_H
#define UI_NEWPROBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NEWPROBDIALOG
{
public:
    QGroupBox *connGroupBox;
    QGridLayout *gridLayout;
    QLineEdit *editPassword;
    QLabel *PSSWDTexLabel;
    QLineEdit *editHostname;
    QLabel *HSTNMTextLabel;
    QLabel *USRNMTexLabel;
    QLineEdit *editDatabase;
    QLineEdit *editUsername;
    QLabel *DTBTextLab;
    QSpinBox *portSpinBox;
    QLabel *PORTTextLabel;
    QPushButton *startButton;
    QPushButton *exitButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLabel *label;

    void setupUi(QDialog *NEWPROBDIALOG)
    {
        if (NEWPROBDIALOG->objectName().isEmpty())
            NEWPROBDIALOG->setObjectName(QStringLiteral("NEWPROBDIALOG"));
        NEWPROBDIALOG->resize(321, 282);
        NEWPROBDIALOG->setMinimumSize(QSize(321, 282));
        NEWPROBDIALOG->setMaximumSize(QSize(321, 282));
        connGroupBox = new QGroupBox(NEWPROBDIALOG);
        connGroupBox->setObjectName(QStringLiteral("connGroupBox"));
        connGroupBox->setGeometry(QRect(10, 10, 303, 191));
        gridLayout = new QGridLayout(connGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        editPassword = new QLineEdit(connGroupBox);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPassword, 2, 1, 1, 1);

        PSSWDTexLabel = new QLabel(connGroupBox);
        PSSWDTexLabel->setObjectName(QStringLiteral("PSSWDTexLabel"));

        gridLayout->addWidget(PSSWDTexLabel, 2, 0, 1, 1);

        editHostname = new QLineEdit(connGroupBox);
        editHostname->setObjectName(QStringLiteral("editHostname"));

        gridLayout->addWidget(editHostname, 3, 1, 1, 1);

        HSTNMTextLabel = new QLabel(connGroupBox);
        HSTNMTextLabel->setObjectName(QStringLiteral("HSTNMTextLabel"));

        gridLayout->addWidget(HSTNMTextLabel, 3, 0, 1, 1);

        USRNMTexLabel = new QLabel(connGroupBox);
        USRNMTexLabel->setObjectName(QStringLiteral("USRNMTexLabel"));

        gridLayout->addWidget(USRNMTexLabel, 1, 0, 1, 1);

        editDatabase = new QLineEdit(connGroupBox);
        editDatabase->setObjectName(QStringLiteral("editDatabase"));

        gridLayout->addWidget(editDatabase, 0, 1, 1, 1);

        editUsername = new QLineEdit(connGroupBox);
        editUsername->setObjectName(QStringLiteral("editUsername"));

        gridLayout->addWidget(editUsername, 1, 1, 1, 1);

        DTBTextLab = new QLabel(connGroupBox);
        DTBTextLab->setObjectName(QStringLiteral("DTBTextLab"));

        gridLayout->addWidget(DTBTextLab, 0, 0, 1, 1);

        portSpinBox = new QSpinBox(connGroupBox);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMinimum(-1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(-1);

        gridLayout->addWidget(portSpinBox, 4, 1, 1, 1);

        PORTTextLabel = new QLabel(connGroupBox);
        PORTTextLabel->setObjectName(QStringLiteral("PORTTextLabel"));

        gridLayout->addWidget(PORTTextLabel, 4, 0, 1, 1);

        startButton = new QPushButton(NEWPROBDIALOG);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(70, 242, 241, 31));
        exitButton = new QPushButton(NEWPROBDIALOG);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(10, 242, 51, 31));
        widget = new QWidget(NEWPROBDIALOG);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 210, 301, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

#ifndef QT_NO_SHORTCUT
        PSSWDTexLabel->setBuddy(editPassword);
        HSTNMTextLabel->setBuddy(editHostname);
        USRNMTexLabel->setBuddy(editUsername);
        DTBTextLab->setBuddy(editDatabase);
        PORTTextLabel->setBuddy(portSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(NEWPROBDIALOG);

        QMetaObject::connectSlotsByName(NEWPROBDIALOG);
    } // setupUi

    void retranslateUi(QDialog *NEWPROBDIALOG)
    {
        NEWPROBDIALOG->setWindowTitle(QApplication::translate("NEWPROBDIALOG", "Dialog", 0));
        connGroupBox->setTitle(QApplication::translate("NEWPROBDIALOG", "Connection settings", 0));
        PSSWDTexLabel->setText(QApplication::translate("NEWPROBDIALOG", "&Password:", 0));
        HSTNMTextLabel->setText(QApplication::translate("NEWPROBDIALOG", "&Hostname:", 0));
        USRNMTexLabel->setText(QApplication::translate("NEWPROBDIALOG", "&Username:", 0));
        DTBTextLab->setText(QApplication::translate("NEWPROBDIALOG", "Database Name:", 0));
        portSpinBox->setSpecialValueText(QApplication::translate("NEWPROBDIALOG", "Default", 0));
        PORTTextLabel->setText(QApplication::translate("NEWPROBDIALOG", "P&ort:", 0));
        startButton->setText(QApplication::translate("NEWPROBDIALOG", "G\320\276", 0));
        exitButton->setText(QApplication::translate("NEWPROBDIALOG", "Exit", 0));
        checkBox->setText(QApplication::translate("NEWPROBDIALOG", "Default settings", 0));
        label->setText(QApplication::translate("NEWPROBDIALOG", "  Support only MYSQL drivers.", 0));
    } // retranslateUi

};

namespace Ui {
    class NEWPROBDIALOG: public Ui_NEWPROBDIALOG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROBDIALOG_H
