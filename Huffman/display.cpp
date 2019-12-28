#include "display.h"
#include "ui_display.h"
#include <QTextEdit>
#include <fstream>
#include <QMessageBox>
using namespace std;

extern char buf[1050][1050];
extern int line;

Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    QTextEdit * qte = new QTextEdit;
    qte->setParent(this);
    qte->resize(1100, 675);
    qte->move(37, 37);
    string now;
    for (int i = 0; i < line; i++) {
        now = now + buf[i] + "\n";
    }
    qte->setPlainText(QString::fromStdString(now));
}

Display::~Display()
{
    delete ui;
}
