/********************************************************************************
** Form generated from reading UI file 'setdimdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDIMDIALOG_H
#define UI_SETDIMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SETDIMDIALOG
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *increase_radio_button;
    QRadioButton *reduce_radio_button;
    QRadioButton *set_radio_button;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QPushButton *change_button;
    QPushButton *exit_button;

    void setupUi(QDialog *SETDIMDIALOG)
    {
        if (SETDIMDIALOG->objectName().isEmpty())
            SETDIMDIALOG->setObjectName(QStringLiteral("SETDIMDIALOG"));
        SETDIMDIALOG->resize(273, 79);
        SETDIMDIALOG->setMinimumSize(QSize(273, 79));
        SETDIMDIALOG->setMaximumSize(QSize(273, 79));
        gridLayout = new QGridLayout(SETDIMDIALOG);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        increase_radio_button = new QRadioButton(SETDIMDIALOG);
        increase_radio_button->setObjectName(QStringLiteral("increase_radio_button"));

        horizontalLayout->addWidget(increase_radio_button);

        reduce_radio_button = new QRadioButton(SETDIMDIALOG);
        reduce_radio_button->setObjectName(QStringLiteral("reduce_radio_button"));

        horizontalLayout->addWidget(reduce_radio_button);

        set_radio_button = new QRadioButton(SETDIMDIALOG);
        set_radio_button->setObjectName(QStringLiteral("set_radio_button"));

        horizontalLayout->addWidget(set_radio_button);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(SETDIMDIALOG);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(0, 31));

        horizontalLayout_2->addWidget(spinBox);

        change_button = new QPushButton(SETDIMDIALOG);
        change_button->setObjectName(QStringLiteral("change_button"));
        change_button->setMinimumSize(QSize(0, 31));

        horizontalLayout_2->addWidget(change_button);

        exit_button = new QPushButton(SETDIMDIALOG);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setMinimumSize(QSize(0, 31));

        horizontalLayout_2->addWidget(exit_button);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SETDIMDIALOG);

        QMetaObject::connectSlotsByName(SETDIMDIALOG);
    } // setupUi

    void retranslateUi(QDialog *SETDIMDIALOG)
    {
        SETDIMDIALOG->setWindowTitle(QApplication::translate("SETDIMDIALOG", "Dialog", 0));
        increase_radio_button->setText(QApplication::translate("SETDIMDIALOG", "Increase", 0));
        reduce_radio_button->setText(QApplication::translate("SETDIMDIALOG", "Reduce", 0));
        set_radio_button->setText(QApplication::translate("SETDIMDIALOG", "Set", 0));
        change_button->setText(QApplication::translate("SETDIMDIALOG", "Change", 0));
        exit_button->setText(QApplication::translate("SETDIMDIALOG", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class SETDIMDIALOG: public Ui_SETDIMDIALOG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDIMDIALOG_H
