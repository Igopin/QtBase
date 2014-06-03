/********************************************************************************
** Form generated from reading UI file 'solvelae.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVELAE_H
#define UI_SOLVELAE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SOLVELAE
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLineEdit *a_line_edit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *b_line_edit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLineEdit *c_line_edit;
    QHBoxLayout *horizontalLayout;
    QPushButton *prob_done_button;
    QPushButton *prob_button_solve;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLineEdit *res_line_edit;

    void setupUi(QDialog *SOLVELAE)
    {
        if (SOLVELAE->objectName().isEmpty())
            SOLVELAE->setObjectName(QStringLiteral("SOLVELAE"));
        SOLVELAE->resize(430, 159);
        SOLVELAE->setMinimumSize(QSize(369, 140));
        SOLVELAE->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(SOLVELAE);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 412, 144));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        a_line_edit = new QLineEdit(groupBox);
        a_line_edit->setObjectName(QStringLiteral("a_line_edit"));
        a_line_edit->setMinimumSize(QSize(91, 31));

        gridLayout_3->addWidget(a_line_edit, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        b_line_edit = new QLineEdit(groupBox_2);
        b_line_edit->setObjectName(QStringLiteral("b_line_edit"));
        b_line_edit->setMinimumSize(QSize(91, 31));

        gridLayout_2->addWidget(b_line_edit, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        c_line_edit = new QLineEdit(groupBox_3);
        c_line_edit->setObjectName(QStringLiteral("c_line_edit"));
        c_line_edit->setMinimumSize(QSize(91, 31));

        gridLayout->addWidget(c_line_edit, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prob_done_button = new QPushButton(widget);
        prob_done_button->setObjectName(QStringLiteral("prob_done_button"));
        prob_done_button->setMinimumSize(QSize(0, 41));

        horizontalLayout->addWidget(prob_done_button);

        prob_button_solve = new QPushButton(widget);
        prob_button_solve->setObjectName(QStringLiteral("prob_button_solve"));
        prob_button_solve->setMinimumSize(QSize(0, 41));

        horizontalLayout->addWidget(prob_button_solve);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        res_line_edit = new QLineEdit(groupBox_4);
        res_line_edit->setObjectName(QStringLiteral("res_line_edit"));
        res_line_edit->setMinimumSize(QSize(91, 31));

        gridLayout_4->addWidget(res_line_edit, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SOLVELAE);

        QMetaObject::connectSlotsByName(SOLVELAE);
    } // setupUi

    void retranslateUi(QDialog *SOLVELAE)
    {
        SOLVELAE->setWindowTitle(QApplication::translate("SOLVELAE", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("SOLVELAE", "A", 0));
        a_line_edit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("SOLVELAE", "B", 0));
        b_line_edit->setText(QString());
        groupBox_3->setTitle(QApplication::translate("SOLVELAE", "C", 0));
        c_line_edit->setText(QString());
        prob_done_button->setText(QApplication::translate("SOLVELAE", "Done", 0));
        prob_button_solve->setText(QApplication::translate("SOLVELAE", "Solve", 0));
        groupBox_4->setTitle(QApplication::translate("SOLVELAE", "Result", 0));
        res_line_edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SOLVELAE: public Ui_SOLVELAE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVELAE_H
