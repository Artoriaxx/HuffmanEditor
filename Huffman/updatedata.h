#ifndef UPDATEDATA_H
#define UPDATEDATA_H

#include <QDialog>

namespace Ui {
class UpdateData;
}

class UpdateData : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateData(QWidget *parent = nullptr);
    ~UpdateData();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdateData *ui;
};

#endif // UPDATEDATA_H
