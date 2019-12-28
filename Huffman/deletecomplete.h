#ifndef DELETECOMPLETE_H
#define DELETECOMPLETE_H

#include <QDialog>

namespace Ui {
class DeleteComplete;
}

class DeleteComplete : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteComplete(QWidget *parent = nullptr);
    ~DeleteComplete();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DeleteComplete *ui;
};

#endif // DELETECOMPLETE_H
