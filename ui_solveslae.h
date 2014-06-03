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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SOLVESLAE
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *result_column_table_widget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *matrix_table_widget;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *b_column_table_widget;
    QVBoxLayout *verticalLayout_5;
    QPushButton *solve_button;
    QSpacerItem *verticalSpacer;
    QPushButton *plot_solution_button;
    QSpacerItem *verticalSpacer_2;
    QPushButton *done_bitton;

    void setupUi(QDialog *SOLVESLAE)
    {
        if (SOLVESLAE->objectName().isEmpty())
            SOLVESLAE->setObjectName(QStringLiteral("SOLVESLAE"));
        SOLVESLAE->resize(642, 408);
        gridLayout = new QGridLayout(SOLVESLAE);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_3 = new QGroupBox(SOLVESLAE);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        result_column_table_widget = new QTableWidget(groupBox_3);
        result_column_table_widget->setObjectName(QStringLiteral("result_column_table_widget"));

        verticalLayout_7->addWidget(result_column_table_widget);


        gridLayout->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox = new QGroupBox(SOLVESLAE);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        matrix_table_widget = new QTableWidget(groupBox);
        matrix_table_widget->setObjectName(QStringLiteral("matrix_table_widget"));

        horizontalLayout_4->addWidget(matrix_table_widget);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(SOLVESLAE);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        b_column_table_widget = new QTableWidget(groupBox_2);
        b_column_table_widget->setObjectName(QStringLiteral("b_column_table_widget"));

        horizontalLayout_3->addWidget(b_column_table_widget);

        b_column_table_widget->raise();
        groupBox_3->raise();

        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        solve_button = new QPushButton(SOLVESLAE);
        solve_button->setObjectName(QStringLiteral("solve_button"));
        solve_button->setMinimumSize(QSize(0, 41));

        verticalLayout_5->addWidget(solve_button);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        plot_solution_button = new QPushButton(SOLVESLAE);
        plot_solution_button->setObjectName(QStringLiteral("plot_solution_button"));
        plot_solution_button->setMinimumSize(QSize(0, 41));

        verticalLayout_5->addWidget(plot_solution_button);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        done_bitton = new QPushButton(SOLVESLAE);
        done_bitton->setObjectName(QStringLiteral("done_bitton"));
        done_bitton->setMinimumSize(QSize(371, 41));

        verticalLayout_5->addWidget(done_bitton);


        gridLayout->addLayout(verticalLayout_5, 1, 0, 1, 1);


        retranslateUi(SOLVESLAE);

        QMetaObject::connectSlotsByName(SOLVESLAE);
    } // setupUi

    void retranslateUi(QDialog *SOLVESLAE)
    {
        SOLVESLAE->setWindowTitle(QApplication::translate("SOLVESLAE", "Dialog", 0));
        groupBox_3->setTitle(QApplication::translate("SOLVESLAE", "Result column", 0));
        groupBox->setTitle(QApplication::translate("SOLVESLAE", "Matrix of system", 0));
        groupBox_2->setTitle(QApplication::translate("SOLVESLAE", "B - column", 0));
        solve_button->setText(QApplication::translate("SOLVESLAE", "Solve", 0));
        plot_solution_button->setText(QApplication::translate("SOLVESLAE", "Plot solution", 0));
        done_bitton->setText(QApplication::translate("SOLVESLAE", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class SOLVESLAE: public Ui_SOLVESLAE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVESLAE_H
