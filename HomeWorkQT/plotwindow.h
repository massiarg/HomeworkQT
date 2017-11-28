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
    void setValues(QList<QPair<QString, QString>> in);
    QList<QPair<QString, QString>> getValues();



public slots:
    void makeplot(QList<QPair<QString, QString>> in);



private:
    Ui::Plotwindow *ui;
    QList<QPair<QString, QString>> values;
};

#endif // PLOTWINDOW_H
