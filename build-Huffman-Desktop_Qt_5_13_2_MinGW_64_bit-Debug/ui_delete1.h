/********************************************************************************
** Form generated from reading UI file 'delete1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE1_H
#define UI_DELETE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Delete1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Delete1)
    {
        if (Delete1->objectName().isEmpty())
            Delete1->setObjectName(QString::fromUtf8("Delete1"));
        Delete1->resize(750, 750);
        centralwidget = new QWidget(Delete1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 640, 111, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 640, 111, 41));
        Delete1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Delete1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 26));
        Delete1->setMenuBar(menubar);
        statusbar = new QStatusBar(Delete1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Delete1->setStatusBar(statusbar);

        retranslateUi(Delete1);

        QMetaObject::connectSlotsByName(Delete1);
    } // setupUi

    void retranslateUi(QMainWindow *Delete1)
    {
        Delete1->setWindowTitle(QCoreApplication::translate("Delete1", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Delete1", "\347\211\251\347\220\206\345\210\240\351\231\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Delete1", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete1: public Ui_Delete1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE1_H
