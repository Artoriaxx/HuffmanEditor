#include "deletecomplete.h"
#include "ui_deletecomplete.h"
#include <QTextEdit>
#include <QMessageBox>
#include <fstream>

using namespace std;

QTextEdit * qte2;
extern QString text;
extern QString UpdateFileName;

DeleteComplete::DeleteComplete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteComplete)
{
    ui->setupUi(this);
    qte2 = new QTextEdit;
    qte2->setParent(this);
    qte2->resize(600, 600);
    qte2->move(75, 75);

    qte2->setPlainText(text);
    this->setFixedSize(750,750);
    this->setWindowTitle("文件内容如下");
}

DeleteComplete::~DeleteComplete()
{
    delete ui;
}


void DeleteComplete::on_pushButton_clicked()
{
    ofstream out(UpdateFileName.toStdString());
    QString str = qte2->toPlainText();
    out << str.toStdString();
    QMessageBox::information(this, "提示", "修改成功", "确定");
}

void DeleteComplete::on_pushButton_2_clicked()
{
    close();
}
