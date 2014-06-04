/********************************************************************************
** Form generated from reading UI file 'solveslae.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVESLAE_H
#define UI_SOLVESLAE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SOLVESLAE
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *main_layout;
    QVBoxLayout *right_part_layout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *matrix_table_widget;
    QVBoxLayout *buttons_layout;
    QHBoxLayout *set_dim_layout;
    QPushButton *set_dim_button;
    QPushButton *solve_button;
    QPushButton *plot_solution_button;
    QPushButton *done_bitton;
    QVBoxLayout *left_part_layout;
    QGroupBox *b_vec_group_box;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *b_column_table_widget;
    QGroupBox *res_vec_group_box;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *result_column_table_widget;

    void setupUi(QDialog *SOLVESLAE)
    {
        if (SOLVESLAE->objectName().isEmpty())
            SOLVESLAE->setObjectName(QStringLiteral("SOLVESLAE"));
        SOLVESLAE->resize(547, 486);
        gridLayout = new QGridLayout(SOLVESLAE);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        main_layout = new QHBoxLayout();
        main_layout->setObjectName(QStringLiteral("main_layout"));
        right_part_layout = new QVBoxLayout();
        right_part_layout->setObjectName(QStringLiteral("right_part_layout"));
        groupBox = new QGroupBox(SOLVESLAE);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        matrix_table_widget = new QTableWidget(groupBox);
        matrix_table_widget->setObjectName(QStringLiteral("matrix_table_widget"));

        horizontalLayout_4->addWidget(matrix_table_widget);


        right_part_layout->addWidget(groupBox);

        buttons_layout = new QVBoxLayout();
        buttons_layout->setObjectName(QStringLiteral("buttons_layout"));
        set_dim_layout = new QHBoxLayout();
        set_dim_layout->setObjectName(QStringLiteral("set_dim_layout"));
        set_dim_button = new QPushButton(SOLVESLAE);
        set_dim_button->setObjectName(QStringLiteral("set_dim_button"));

        set_dim_layout->addWidget(set_dim_button);


        buttons_layout->addLayout(set_dim_layout);

        solve_button = new QPushButton(SOLVESLAE);
        solve_button->setObjectName(QStringLiteral("solve_button"));
        solve_button->setMinimumSize(QSize(0, 41));

        buttons_layout->addWidget(solve_button);

        plot_solution_button = new QPushButton(SOLVESLAE);
        plot_solution_button->setObjectName(QStringLiteral("plot_solution_button"));
        plot_solution_button->setMinimumSize(QSize(0, 41));

        buttons_layout->addWidget(plot_solution_button);

        done_bitton = new QPushButton(SOLVESLAE);
        done_bitton->setObjectName(QStringLiteral("done_bitton"));
        done_bitton->setMinimumSize(QSize(371, 41));

        buttons_layout->addWidget(done_bitton);


        right_part_layout->addLayout(buttons_layout);


        main_layout->addLayout(right_part_layout);

        left_part_layout = new QVBoxLayout();
        left_part_layout->setObjectName(QStringLiteral("left_part_layout"));
        b_vec_group_box = new QGroupBox(SOLVESLAE);
        b_vec_group_box->setObjectName(QStringLiteral("b_vec_group_box"));
        b_vec_group_box->setMaximumSize(QSize(160, 16777215));
        verticalLayout_11 = new QVBoxLayout(b_vec_group_box);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        b_column_table_widget = new QTableWidget(b_vec_group_box);
        b_column_table_widget->setObjectName(QStringLiteral("b_column_table_widget"));
        b_column_table_widget->setMaximumSize(QSize(140, 16777215));

        verticalLayout_11->addWidget(b_column_table_widget);


        left_part_layout->addWidget(b_vec_group_box);

        res_vec_group_box = new QGroupBox(SOLVESLAE);
        res_vec_group_box->setObjectName(QStringLiteral("res_vec_group_box"));
        res_vec_group_box->setMaximumSize(QSize(160, 16777215));
        verticalLayout_7 = new QVBoxLayout(res_vec_group_box);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        result_column_table_widget = new QTableWidget(res_vec_group_box);
        result_column_table_widget->setObjectName(QStringLiteral("result_column_table_widget"));
        result_column_table_widget->setMaximumSize(QSize(140, 16777215));

        verticalLayout_7->addWidget(result_column_table_widget);


        left_part_layout->addWidget(res_vec_group_box);


        main_layout->addLayout(left_part_layout);


        gridLayout->addLayout(main_layout, 0, 0, 1, 1);


        retranslateUi(SOLVESLAE);

        QMetaObject::connectSlotsByName(SOLVESLAE);
    } // setupUi

    void retranslateUi(QDialog *SOLVESLAE)
    {
        SOLVESLAE->setWindowTitle(QApplication::translate("SOLVESLAE", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("SOLVESLAE", "Matrix of system", 0));
        set_dim_button->setText(QApplication::translate("SOLVESLAE", "Set dimension", 0));
        solve_button->setText(QApplication::translate("SOLVESLAE", "Solve", 0));
        plot_solution_button->setText(QApplication::translate("SOLVESLAE", "Plot solution", 0));
        done_bitton->setText(QApplication::translate("SOLVESLAE", "Done", 0));
        b_vec_group_box->setTitle(QApplication::translate("SOLVESLAE", "B - column", 0));
        res_vec_group_box->setTitle(QApplication::translate("SOLVESLAE", "Result column", 0));
    } // retranslateUi

};

namespace Ui {
    class SOLVESLAE: public Ui_SOLVESLAE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVESLAE_H
