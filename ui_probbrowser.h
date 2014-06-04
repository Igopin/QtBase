/********************************************************************************
** Form generated from reading UI file 'probbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBBROWSER_H
#define UI_PROBBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PROBBROWSER
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *database_label;
    QLabel *current_base_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *problem_type_combo_box;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QComboBox *current_problem_combo_box;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *open_problem_button;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QComboBox *opened_problem_combo_box;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *new_problem_button;
    QPushButton *prob_edit_button;
    QPushButton *save_problem_button;
    QPushButton *close_button;

    void setupUi(QWidget *PROBBROWSER)
    {
        if (PROBBROWSER->objectName().isEmpty())
            PROBBROWSER->setObjectName(QStringLiteral("PROBBROWSER"));
        PROBBROWSER->resize(437, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PROBBROWSER->sizePolicy().hasHeightForWidth());
        PROBBROWSER->setSizePolicy(sizePolicy);
        PROBBROWSER->setMinimumSize(QSize(0, 0));
        PROBBROWSER->setMaximumSize(QSize(100000, 1000000));
        PROBBROWSER->setWindowOpacity(0.5);
        gridLayout_3 = new QGridLayout(PROBBROWSER);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        database_label = new QLabel(PROBBROWSER);
        database_label->setObjectName(QStringLiteral("database_label"));
        database_label->setMinimumSize(QSize(89, 13));
        database_label->setMaximumSize(QSize(89, 13));

        horizontalLayout_3->addWidget(database_label);

        current_base_label = new QLabel(PROBBROWSER);
        current_base_label->setObjectName(QStringLiteral("current_base_label"));
        current_base_label->setMinimumSize(QSize(25, 13));

        horizontalLayout_3->addWidget(current_base_label);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(PROBBROWSER);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(75, 31));
        label_3->setMaximumSize(QSize(75, 31));

        horizontalLayout_2->addWidget(label_3);

        problem_type_combo_box = new QComboBox(PROBBROWSER);
        problem_type_combo_box->setObjectName(QStringLiteral("problem_type_combo_box"));
        problem_type_combo_box->setMinimumSize(QSize(141, 31));

        horizontalLayout_2->addWidget(problem_type_combo_box);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(PROBBROWSER);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(201, 271));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        current_problem_combo_box = new QComboBox(groupBox);
        current_problem_combo_box->setObjectName(QStringLiteral("current_problem_combo_box"));
        current_problem_combo_box->setMinimumSize(QSize(181, 31));

        verticalLayout_3->addWidget(current_problem_combo_box);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        open_problem_button = new QPushButton(groupBox);
        open_problem_button->setObjectName(QStringLiteral("open_problem_button"));
        open_problem_button->setMinimumSize(QSize(161, 31));

        verticalLayout_2->addWidget(open_problem_button);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(161, 31));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PROBBROWSER);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        opened_problem_combo_box = new QComboBox(groupBox_2);
        opened_problem_combo_box->setObjectName(QStringLiteral("opened_problem_combo_box"));
        opened_problem_combo_box->setMinimumSize(QSize(181, 31));

        verticalLayout_4->addWidget(opened_problem_combo_box);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        new_problem_button = new QPushButton(groupBox_2);
        new_problem_button->setObjectName(QStringLiteral("new_problem_button"));
        new_problem_button->setMinimumSize(QSize(161, 31));

        verticalLayout->addWidget(new_problem_button);

        prob_edit_button = new QPushButton(groupBox_2);
        prob_edit_button->setObjectName(QStringLiteral("prob_edit_button"));
        prob_edit_button->setMinimumSize(QSize(161, 31));

        verticalLayout->addWidget(prob_edit_button);

        save_problem_button = new QPushButton(groupBox_2);
        save_problem_button->setObjectName(QStringLiteral("save_problem_button"));
        save_problem_button->setMinimumSize(QSize(161, 31));

        verticalLayout->addWidget(save_problem_button);

        close_button = new QPushButton(groupBox_2);
        close_button->setObjectName(QStringLiteral("close_button"));
        close_button->setMinimumSize(QSize(161, 31));

        verticalLayout->addWidget(close_button);


        verticalLayout_4->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(PROBBROWSER);

        QMetaObject::connectSlotsByName(PROBBROWSER);
    } // setupUi

    void retranslateUi(QWidget *PROBBROWSER)
    {
        PROBBROWSER->setWindowTitle(QApplication::translate("PROBBROWSER", "Form", 0));
        database_label->setText(QApplication::translate("PROBBROWSER", "Current database:", 0));
        current_base_label->setText(QApplication::translate("PROBBROWSER", "None", 0));
        label_3->setText(QApplication::translate("PROBBROWSER", "Problem Type:", 0));
        groupBox->setTitle(QApplication::translate("PROBBROWSER", "Problems in database", 0));
        open_problem_button->setText(QApplication::translate("PROBBROWSER", "Open", 0));
        pushButton->setText(QApplication::translate("PROBBROWSER", "Remove", 0));
        groupBox_2->setTitle(QApplication::translate("PROBBROWSER", "Opened problems", 0));
        new_problem_button->setText(QApplication::translate("PROBBROWSER", "New", 0));
        prob_edit_button->setText(QApplication::translate("PROBBROWSER", "Edit", 0));
        save_problem_button->setText(QApplication::translate("PROBBROWSER", "Save", 0));
        close_button->setText(QApplication::translate("PROBBROWSER", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class PROBBROWSER: public Ui_PROBBROWSER {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBBROWSER_H
