/********************************************************************************
** Form generated from reading UI file 'newslaewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSLAEWIDGET_H
#define UI_NEWSLAEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NEWSLAEWIDGET
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *problem_name_line_edit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpinBox *num_of_slae_eq_line_edit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *create_button;
    QPushButton *exit_button;

    void setupUi(QWidget *NEWSLAEWIDGET)
    {
        if (NEWSLAEWIDGET->objectName().isEmpty())
            NEWSLAEWIDGET->setObjectName(QStringLiteral("NEWSLAEWIDGET"));
        NEWSLAEWIDGET->resize(381, 142);
        NEWSLAEWIDGET->setMinimumSize(QSize(381, 142));
        NEWSLAEWIDGET->setMaximumSize(QSize(381, 142));
        widget = new QWidget(NEWSLAEWIDGET);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 361, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        problem_name_line_edit = new QLineEdit(groupBox);
        problem_name_line_edit->setObjectName(QStringLiteral("problem_name_line_edit"));
        problem_name_line_edit->setMinimumSize(QSize(113, 31));

        gridLayout->addWidget(problem_name_line_edit, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        num_of_slae_eq_line_edit = new QSpinBox(groupBox_2);
        num_of_slae_eq_line_edit->setObjectName(QStringLiteral("num_of_slae_eq_line_edit"));
        num_of_slae_eq_line_edit->setMinimumSize(QSize(113, 31));

        gridLayout_2->addWidget(num_of_slae_eq_line_edit, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        create_button = new QPushButton(widget);
        create_button->setObjectName(QStringLiteral("create_button"));
        create_button->setMinimumSize(QSize(0, 41));

        horizontalLayout_2->addWidget(create_button);

        exit_button = new QPushButton(widget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setMinimumSize(QSize(0, 41));

        horizontalLayout_2->addWidget(exit_button);


        verticalLayout->addLayout(horizontalLayout_2);

        exit_button->raise();
        create_button->raise();
        create_button->raise();
        groupBox->raise();
        groupBox_2->raise();

        retranslateUi(NEWSLAEWIDGET);

        QMetaObject::connectSlotsByName(NEWSLAEWIDGET);
    } // setupUi

    void retranslateUi(QWidget *NEWSLAEWIDGET)
    {
        NEWSLAEWIDGET->setWindowTitle(QApplication::translate("NEWSLAEWIDGET", "Form", 0));
        groupBox->setTitle(QApplication::translate("NEWSLAEWIDGET", "Name of problem", 0));
        groupBox_2->setTitle(QApplication::translate("NEWSLAEWIDGET", "Number of SLAE equation", 0));
        create_button->setText(QApplication::translate("NEWSLAEWIDGET", "Create", 0));
        exit_button->setText(QApplication::translate("NEWSLAEWIDGET", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class NEWSLAEWIDGET: public Ui_NEWSLAEWIDGET {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSLAEWIDGET_H
