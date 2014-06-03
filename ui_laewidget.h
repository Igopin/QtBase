/********************************************************************************
** Form generated from reading UI file 'laewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAEWIDGET_H
#define UI_LAEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LAEWIDGET
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *LAEWIDGET)
    {
        if (LAEWIDGET->objectName().isEmpty())
            LAEWIDGET->setObjectName(QStringLiteral("LAEWIDGET"));
        LAEWIDGET->resize(367, 300);
        groupBox = new QGroupBox(LAEWIDGET);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 111, 61));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 19, 91, 31));
        groupBox_2 = new QGroupBox(LAEWIDGET);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 30, 111, 61));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 19, 91, 31));
        groupBox_3 = new QGroupBox(LAEWIDGET);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(250, 30, 111, 61));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 19, 91, 31));
        label = new QLabel(LAEWIDGET);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 71, 21));
        label_2 = new QLabel(LAEWIDGET);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 10, 46, 21));

        retranslateUi(LAEWIDGET);

        QMetaObject::connectSlotsByName(LAEWIDGET);
    } // setupUi

    void retranslateUi(QWidget *LAEWIDGET)
    {
        LAEWIDGET->setWindowTitle(QApplication::translate("laewidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("laewidget", "  A", 0));
        lineEdit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("laewidget", "B", 0));
        lineEdit_2->setText(QString());
        groupBox_3->setTitle(QApplication::translate("laewidget", "C", 0));
        lineEdit_3->setText(QString());
        label->setText(QApplication::translate("laewidget", "Poblem name:", 0));
        label_2->setText(QApplication::translate("laewidget", "None", 0));
    } // retranslateUi

};

namespace Ui {
    class LAEWIDGET: public Ui_LAEWIDGET {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAEWIDGET_H
