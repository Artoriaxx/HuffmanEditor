#include "delete.h"
#include "ui_delete.h"
#include <QTextEdit>
#include <QMessageBox>
#include <fstream>

using namespace std;

QTextEdit * qte1;
extern QString text;
extern QString UpdateFileName;

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    qte1 = new QTextEdit;
    qte1->setParent(this);
    qte1->resize(600, 600);
    qte1->move(75, 75);

    qte1->setPlainText(text);
    this->setFixedSize(750,750);
    this->setWindowTitle("文件内容如下");
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_clicked()
{
    ofstream out(UpdateFileName.toStdString());
    QString str = qte1->toPlainText();
    out << str.toStdString();
    QMessageBox::information(this, "提示", "修改成功", "确定");
}

void Delete::on_pushButton_2_clicked()
{
    close();
}
