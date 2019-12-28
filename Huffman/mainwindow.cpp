#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "huffman.h"
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>
#include <QFile>
#include <QMessageBox>
#include <bits/stdc++.h>
#include <fstream>
#include "updatedata.h"565655
#include <delete.h>
#include "display.h"
#include <deletecomplete.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Huffman编码器");

}

MainWindow::~MainWindow()
{
    delete ui;
}
QString inFile;
QString CodeFile;
QString CodePrint;
QString ToBeTran;

void MainWindow::on_pushButton_clicked()
{
    //创建权值文件，不对inFile命名
    bool isOK;
    QString filename = QInputDialog::getText(nullptr,
                                             "创建权值文件","请输入要创建的文件路径",
                                             QLineEdit::Normal,
                                             "F:\\Huffman\\",
                                             &isOK);
    while (!isOK) {
        filename = QInputDialog::getText(nullptr,
                                         "创建权值文件","请输入要创建的文件路径",
                                         QLineEdit::Normal,
                                         "F:\\Huffman\\",
                                         &isOK);
    }
    QFile file(filename);
    if (file.exists()) {
        QMessageBox::critical(this, "错误", "文件已存在");
    }
    else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.close();
        QMessageBox::information(this, "成功", "创建成功");
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    //创建编码输入文件，不命名
    bool isOK;
    QString filename = QInputDialog::getText(nullptr,
                                             "创建编码文本输入文件","请输入要创建的文件路径",
                                             QLineEdit::Normal,
                                             "F:\\Huffman\\",
                                             &isOK);
    while (!isOK) {
        filename = QInputDialog::getText(nullptr,
                                         "创建编码文本输入文件","请输入要创建的文件路径",
                                         QLineEdit::Normal,
                                         "F:\\Huffman\\",
                                         &isOK);
    }
    QFile file(filename);
    if (file.exists()) {
        QMessageBox::critical(this, "错误", "文件已存在");
    }
    else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.close();
        QMessageBox::information(this, "成功", "创建成功");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    //创建编码输出文件,命名
    bool isOK;
    QString filename = QInputDialog::getText(nullptr,
                                             "创建编码后输出文件","请输入要创建的文件路径",
                                             QLineEdit::Normal,
                                             "F:\\Huffman\\",
                                             &isOK);
    while (!isOK) {
        filename = QInputDialog::getText(nullptr,
                                         "创建编码后输出文件","请输入要创建的文件路径",
                                         QLineEdit::Normal,
                                         "F:\\Huffman\\",
                                         &isOK);
    }
    QFile file(filename);
    if (file.exists()) {
        QMessageBox::critical(this, "错误", "文件已存在,已切换该文件为输出文件");
    }
    else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.close();
        QMessageBox::information(this, "成功", "创建成功");
    }
    CodeFile = filename;
}

void MainWindow::on_pushButton_10_clicked()
{
    //创建译码输出文件，命名
    bool isOK;
    QString filename = QInputDialog::getText(nullptr,
                                             "创建译码后输出文件","请输入要创建的文件路径",
                                             QLineEdit::Normal,
                                             "F:\\Huffman\\",
                                             &isOK);
    while (!isOK) {
        filename = QInputDialog::getText(nullptr,
                                         "创建译码后输出文件","请输入要创建的文件路径",
                                         QLineEdit::Normal,
                                         "F:\\Huffman\\",
                                         &isOK);
    }
    QFile file(filename);
    if (file.exists()) {
        QMessageBox::critical(this, "错误", "文件已存在,已切换该文件为输出文件");
    }
    else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.close();
        QMessageBox::information(this, "成功", "创建成功");
    }
    CodePrint = filename;
}

void MainWindow::on_pushButton_5_clicked()
{
    //打开字母权值输入文件，更改输入路径到此文件
    inFile = QFileDialog::getOpenFileName(this, "打开字母权值输入文件",
                                          "F:\\Huffman\\", "*.txt");
    bool isOK;
    QString tmp = QInputDialog::getText(nullptr, "输入字母数量","输入字母数量",
                                        QLineEdit::Normal, "", &isOK);
    while (!isOK) {
        tmp = QInputDialog::getText(nullptr, "输入字母数量","输入字母数量",
                                    QLineEdit::Normal, "", &isOK);
    }
    int n = tmp.toInt();
    ofstream out(inFile.toStdString());
    out << n << endl;
    for (int i = 1; i <= n; i++) {
        tmp = QInputDialog::getText(nullptr, "创建字母及其权值",
                                    "输入字母及其权值，空格分隔",
                                    QLineEdit::Normal, "", &isOK);
        out << tmp.toStdString() << " ";
    }
    out << endl;
    QMessageBox::information(this, "成功", "写入成功");
}

void MainWindow::on_pushButton_4_clicked()
{
    //打开编码输入文件，更改路径
    ToBeTran = QFileDialog::getOpenFileName(this, "打开编码输入文件",
                                            "F:\\Huffman\\", "*.txt");
    bool isOK;
    QString tmp = QInputDialog::getText(nullptr, "输入编码文本","输入编码文本",
                                        QLineEdit::Normal, "", &isOK);
    ofstream out(ToBeTran.toStdString());
    out << tmp.toStdString() << endl;
    QMessageBox::information(this, "成功", "写入成功");
}
QString ToBeDecode;
void MainWindow::on_pushButton_6_clicked()
{
    //打开译码输入文件
    ToBeDecode = QFileDialog::getOpenFileName(this, "打开译码输入文件", "F:\\Huffman\\", "*.txt");
    bool isOK;
    QString tmp = QInputDialog::getText(NULL, "输入译码文本","输入译码文本", QLineEdit::Normal, "", &isOK);
    ofstream out(CodeFile.toStdString());
    out << tmp.toStdString() << endl;
    QMessageBox::information(this, "成功", "写入成功");
}
bool flag = false;
void MainWindow::on_pushButton_11_clicked()
{
    //显示huffman树
    if (!flag) {
        hf->init(inFile.toStdString());
        flag = true;
    }
    Display ds;
    ds.exec();
}


void MainWindow::on_pushButton_7_clicked()
{
    //编码，输入文件为ToBeTran，输出文件CodeFile
    if (!flag) {
        QMessageBox::warning(this, "提示", "请先初始化", "退出");
        return;
    }
    if (CodeFile == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建编码输出文件", "退出");
        return;
    }
    if (ToBeTran == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建编码输入文件", "退出");
        return;
    }
    int status = hf->encode(ToBeTran.toStdString(), CodeFile.toStdString());
    if (status == 1) QMessageBox::information(this, "提示", "编码成功", "退出");
    else QMessageBox::warning(this, "编码失败", "请检查权值文件是否输入正确", "退出");
}


void MainWindow::on_pushButton_8_clicked()
{
    //译码，输入文件为ToBeDecode，输出文件CodePrint
    if (!flag) {
        QMessageBox::warning(this, "提示", "请先初始化", "退出");
        return;
    }
    if (CodePrint == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建译码输出文件", "退出");
        return;
    }
    if (ToBeDecode == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建译码输入文件", "退出");
        return;
    }
    int status = hf->decode(ToBeDecode.toStdString(), CodePrint.toStdString());
    if (status == 1) QMessageBox::information(this, "提示", "译码成功", "退出");
    else QMessageBox::information(this, "译码失败", "请检查权值文件是否输入正确", "退出");
}


void MainWindow::on_pushButton_9_clicked()
{
    //查询编码记录
    if (CodeFile == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建编码输出文件", "退出");
        return;
    }
    ifstream in(CodeFile.toStdString());
    string text;
    int cnt = 0;
    while (getline(in, text)) {
        if (text.compare("##") == 0) {
            cnt++;
            continue;
        }
        if (text.length() == 0) continue;
        QMessageBox msg;
        msg.addButton("继续查看", QMessageBox::AcceptRole);
        msg.addButton("退出", QMessageBox::RejectRole);
        msg.setWindowTitle("第"+QString::number(cnt)+"条记录");
        msg.setText(QString::fromStdString(text));
        if(msg.exec() == QMessageBox::AcceptRole) {
            continue;
        }
        else break;
    }
    QMessageBox::information(this, "提示", "记录已查询完毕", "退出");
    in.close();
}


void MainWindow::on_pushButton_12_clicked()
{
    //查询译码记录
    if (CodePrint == nullptr) {
        QMessageBox::warning(this, "提示", "请先创建译码输出文件", "退出");
        return;
    }
    ifstream in(CodePrint.toStdString());
    string text;
    int cnt = 0;
    while (getline(in, text)) {
        if (text.compare("##") == 0) {
            cnt++;
            continue;
        }
        if (text.length() == 0) continue;
        QMessageBox msg;
        msg.addButton("继续查看", QMessageBox::AcceptRole);
        msg.addButton("退出", QMessageBox::RejectRole);
        msg.setWindowTitle("第"+QString::number(cnt)+"条记录");
        msg.setText(QString::fromStdString(text));
        if(msg.exec() == QMessageBox::AcceptRole) {
            continue;
        }
        else break;
    }
    QMessageBox::information(this, "提示", "记录已查询完毕", "退出");
    in.close();
}
QString text;
QString UpdateFileName;
void MainWindow::on_pushButton_13_clicked()
{
    //修改某个记录
    UpdateFileName = QFileDialog::getOpenFileName(this, "打开要修改的文件", "F:\\Huffman\\", "*.txt");
    while (UpdateFileName == nullptr) {
        UpdateFileName = QFileDialog::getOpenFileName(this, "打开要修改的文件", "F:\\Huffman\\", "*.txt");
    }
    ifstream in(UpdateFileName.toStdString());

    string tmp;
    int cnt;
    string text1;
    while (getline(in, tmp)) {
        text1 = text1 + tmp + "\n";
    }
    text = QString::fromStdString(text1);
    UpdateData nw;
    nw.exec();


}
string buffer;
QString bufferName;
void MainWindow::on_pushButton_14_clicked()
{
    //删除某个记录，逻辑删除
    UpdateFileName = QFileDialog::getOpenFileName(this, "打开要删除记录的文件",
                                                  "F:\\Huffman\\", "*.txt");
    while (UpdateFileName == nullptr) {
        UpdateFileName = QFileDialog::getOpenFileName(this, "打开要删除记录的文件",
                                                      "F:\\Huffman\\", "*.txt");
    }

    ifstream in(UpdateFileName.toStdString());

    string tmp;
    string text1;
    while (getline(in, tmp)) {
        text1 = text1 + tmp + "\n";
    }
    text = QString::fromStdString(text1);
    buffer = text.toStdString();
    bufferName = UpdateFileName;
    Delete dl;
    dl.exec();
}


void MainWindow::on_pushButton_15_clicked()
{
    UpdateFileName = QFileDialog::getOpenFileName(this, "打开要删除记录的文件",
                                                  "F:\\Huffman\\", "*.txt");
    while (UpdateFileName == nullptr) {
        UpdateFileName = QFileDialog::getOpenFileName(this, "打开要删除记录的文件",
                                                      "F:\\Huffman\\", "*.txt");
    }
    ifstream in(UpdateFileName.toStdString());

    string tmp;
    string text1;
    while (getline(in, tmp)) {
        text1 = text1 + tmp + "\n";
    }
    text = QString::fromStdString(text1);
    DeleteComplete dl;
    dl.exec();
}



void MainWindow::on_pushButton_16_clicked()
{
    if (buffer.length() == 0) {
        QMessageBox::information(this, "提示", "没有可以恢复的记录", "退出");
        return;
    }

    ofstream out(bufferName.toStdString());
    out << buffer;
    buffer = "";
    bufferName = "";
    QMessageBox::information(this, "提示", "恢复完毕", "退出");
}

void MainWindow::on_pushButton_17_clicked()
{
    //选择权值文件
    inFile = QFileDialog::getOpenFileName(this, "打开字母权值输入文件", "F:\\Huffman\\", "*.txt");
    QMessageBox::information(this, "成功", "打开成功");
}

void MainWindow::on_pushButton_18_clicked()
{
    //选择编码文本文件
    ToBeTran = QFileDialog::getOpenFileName(this, "打开编码输入文件", "F:\\Huffman\\", "*.txt");
    QMessageBox::information(this, "成功", "打开成功");

}

void MainWindow::on_pushButton_19_clicked()
{
    ToBeDecode = QFileDialog::getOpenFileName(this, "打开译码输入文件", "F:\\Huffman\\", "*.txt");
    QMessageBox::information(this, "成功", "打开成功");
}

void MainWindow::on_pushButton_20_clicked()
{
    if (!flag) {
        hf->init(inFile.toStdString());
        flag = true;
    }
}
