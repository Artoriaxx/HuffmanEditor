#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>


namespace Ui {
class Display;
}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H
