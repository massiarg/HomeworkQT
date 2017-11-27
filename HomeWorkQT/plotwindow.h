#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QDialog>

namespace Ui {
class Plotwindow;
}

class Plotwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Plotwindow(QWidget *parent = 0);
    ~Plotwindow();

private:
    Ui::Plotwindow *ui;
};

#endif // PLOTWINDOW_H
