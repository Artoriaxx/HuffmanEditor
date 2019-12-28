/********************************************************************************
** Form generated from reading UI file 'deletecomplete.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECOMPLETE_H
#define UI_DELETECOMPLETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteComplete
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DeleteComplete)
    {
        if (DeleteComplete->objectName().isEmpty())
            DeleteComplete->setObjectName(QString::fromUtf8("DeleteComplete"));
        DeleteComplete->resize(750, 750);
        pushButton = new QPushButton(DeleteComplete);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 690, 111, 41));
        pushButton_2 = new QPushButton(DeleteComplete);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 690, 111, 41));

        retranslateUi(DeleteComplete);

        QMetaObject::connectSlotsByName(DeleteComplete);
    } // setupUi

    void retranslateUi(QDialog *DeleteComplete)
    {
        DeleteComplete->setWindowTitle(QCoreApplication::translate("DeleteComplete", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteComplete", "\347\211\251\347\220\206\345\210\240\351\231\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeleteComplete", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteComplete: public Ui_DeleteComplete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECOMPLETE_H
