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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NEWPROBDIALOG
{
public:
    QGroupBox *connGroupBox;
    QGridLayout *gridLayout;
    QLabel *textLabel4;
    QLabel *textLabel5;
    QLineEdit *editUsername;
    QLineEdit *editDatabase;
    QLineEdit *editHostname;
    QSpinBox *portSpinBox;
    QLineEdit *editPassword;
    QLabel *textLabel3;
    QLabel *textLabel4_2;
    QLabel *textLabel5_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QCheckBox *checkBox;

    void setupUi(QDialog *NEWPROBDIALOG)
    {
        if (NEWPROBDIALOG->objectName().isEmpty())
            NEWPROBDIALOG->setObjectName(QStringLiteral("NEWPROBDIALOG"));
        NEWPROBDIALOG->resize(321, 391);
        NEWPROBDIALOG->setMinimumSize(QSize(321, 391));
        NEWPROBDIALOG->setMaximumSize(QSize(321, 391));
        connGroupBox = new QGroupBox(NEWPROBDIALOG);
        connGroupBox->setObjectName(QStringLiteral("connGroupBox"));
        connGroupBox->setGeometry(QRect(10, 120, 301, 181));
        gridLayout = new QGridLayout(connGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        textLabel4 = new QLabel(connGroupBox);
        textLabel4->setObjectName(QStringLiteral("textLabel4"));

        gridLayout->addWidget(textLabel4, 1, 0, 1, 1);

        textLabel5 = new QLabel(connGroupBox);
        textLabel5->setObjectName(QStringLiteral("textLabel5"));

        gridLayout->addWidget(textLabel5, 3, 0, 1, 1);

        editUsername = new QLineEdit(connGroupBox);
        editUsername->setObjectName(QStringLiteral("editUsername"));

        gridLayout->addWidget(editUsername, 1, 1, 1, 1);

        editDatabase = new QLineEdit(connGroupBox);
        editDatabase->setObjectName(QStringLiteral("editDatabase"));

        gridLayout->addWidget(editDatabase, 0, 1, 1, 1);

        editHostname = new QLineEdit(connGroupBox);
        editHostname->setObjectName(QStringLiteral("editHostname"));

        gridLayout->addWidget(editHostname, 3, 1, 1, 1);

        portSpinBox = new QSpinBox(connGroupBox);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMinimum(-1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(-1);

        gridLayout->addWidget(portSpinBox, 4, 1, 1, 1);

        editPassword = new QLineEdit(connGroupBox);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPassword, 2, 1, 1, 1);

        textLabel3 = new QLabel(connGroupBox);
        textLabel3->setObjectName(QStringLiteral("textLabel3"));

        gridLayout->addWidget(textLabel3, 0, 0, 1, 1);

        textLabel4_2 = new QLabel(connGroupBox);
        textLabel4_2->setObjectName(QStringLiteral("textLabel4_2"));

        gridLayout->addWidget(textLabel4_2, 2, 0, 1, 1);

        textLabel5_2 = new QLabel(connGroupBox);
        textLabel5_2->setObjectName(QStringLiteral("textLabel5_2"));

        gridLayout->addWidget(textLabel5_2, 4, 0, 1, 1);

        groupBox = new QGroupBox(NEWPROBDIALOG);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 91));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 30, 82, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 30, 82, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 60, 82, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(170, 60, 82, 17));
        pushButton = new QPushButton(NEWPROBDIALOG);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 352, 241, 31));
        pushButton_2 = new QPushButton(NEWPROBDIALOG);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 352, 51, 31));
        label = new QLabel(NEWPROBDIALOG);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 310, 151, 31));
        checkBox = new QCheckBox(NEWPROBDIALOG);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 310, 101, 31));
#ifndef QT_NO_SHORTCUT
        textLabel4->setBuddy(editUsername);
        textLabel5->setBuddy(editHostname);
        textLabel3->setBuddy(editDatabase);
        textLabel4_2->setBuddy(editPassword);
        textLabel5_2->setBuddy(portSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(NEWPROBDIALOG);

        QMetaObject::connectSlotsByName(NEWPROBDIALOG);
    } // setupUi

    void retranslateUi(QDialog *NEWPROBDIALOG)
    {
        NEWPROBDIALOG->setWindowTitle(QApplication::translate("NEWPROBDIALOG", "Dialog", 0));
        connGroupBox->setTitle(QApplication::translate("NEWPROBDIALOG", "Connection settings", 0));
        textLabel4->setText(QApplication::translate("NEWPROBDIALOG", "&Username:", 0));
        textLabel5->setText(QApplication::translate("NEWPROBDIALOG", "&Hostname:", 0));
        portSpinBox->setSpecialValueText(QApplication::translate("NEWPROBDIALOG", "Default", 0));
        textLabel3->setText(QApplication::translate("NEWPROBDIALOG", "Database Name:", 0));
        textLabel4_2->setText(QApplication::translate("NEWPROBDIALOG", "&Password:", 0));
        textLabel5_2->setText(QApplication::translate("NEWPROBDIALOG", "P&ort:", 0));
        groupBox->setTitle(QApplication::translate("NEWPROBDIALOG", "Choose problem", 0));
        radioButton->setText(QApplication::translate("NEWPROBDIALOG", "SLAE", 0));
        radioButton_2->setText(QApplication::translate("NEWPROBDIALOG", "ODE", 0));
        radioButton_3->setText(QApplication::translate("NEWPROBDIALOG", "Somthing", 0));
        radioButton_4->setText(QApplication::translate("NEWPROBDIALOG", "Something", 0));
        pushButton->setText(QApplication::translate("NEWPROBDIALOG", "G\320\276", 0));
        pushButton_2->setText(QApplication::translate("NEWPROBDIALOG", "Exit", 0));
        label->setText(QApplication::translate("NEWPROBDIALOG", "  Support only MYSQL drivers.", 0));
        checkBox->setText(QApplication::translate("NEWPROBDIALOG", "Default setttings", 0));
    } // retranslateUi

};

namespace Ui {
    class NEWPROBDIALOG: public Ui_NEWPROBDIALOG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROBDIALOG_H
