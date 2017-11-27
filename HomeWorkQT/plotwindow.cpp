#include "plotwindow.h"
#include "ui_plotwindow.h"

Plotwindow::Plotwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plotwindow)
{
    ui->setupUi(this);
}

Plotwindow::~Plotwindow()
{
    delete ui;
}
