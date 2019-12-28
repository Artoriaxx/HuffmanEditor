#include "updatedata.h"
#include "ui_updatedata.h"
#include <QDebug>
#include <QTextEdit>
#include <fstream>
#include <QMessageBox>
using namespace std;

extern QString text;
extern QString UpdateFileName;
QTextEdit * qte;
UpdateData::UpdateData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateData)
{
    ui->setupUi(this);
    qte = new QTextEdit;
    qte->setParent(this);
    qte->resize(600, 600);
    qte->move(75, 75);

    qte->setPlainText(text);
    this->setFixedSize(750,750);
    this->setWindowTitle("文件内容如下");

}

UpdateData::~UpdateData()
{
    delete ui;
}



void UpdateData::on_pushButton_clicked()
{
    ofstream out(UpdateFileName.toStdString());
    QString str = qte->toPlainText();
    out << str.toStdString();
    QMessageBox::information(this, "提示", "修改成功", "确定");
}

void UpdateData::on_pushButton_2_clicked()
{
    close();
}
