/********************************************************************************
** Form generated from reading UI file 'updatedata.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEDATA_H
#define UI_UPDATEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdateData
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UpdateData)
    {
        if (UpdateData->objectName().isEmpty())
            UpdateData->setObjectName(QString::fromUtf8("UpdateData"));
        UpdateData->resize(750, 750);
        pushButton = new QPushButton(UpdateData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 680, 91, 41));
        pushButton_2 = new QPushButton(UpdateData);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 680, 91, 41));

        retranslateUi(UpdateData);

        QMetaObject::connectSlotsByName(UpdateData);
    } // setupUi

    void retranslateUi(QDialog *UpdateData)
    {
        UpdateData->setWindowTitle(QCoreApplication::translate("UpdateData", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("UpdateData", "\347\241\256\345\256\232\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UpdateData", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateData: public Ui_UpdateData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEDATA_H
