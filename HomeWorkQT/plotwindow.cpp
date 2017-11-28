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

void Plotwindow::setValues(QList<QPair<QString, QString> > in){
    Plotwindow::values = in;
}

QList<QPair<QString, QString>> Plotwindow::getValues(){
    return Plotwindow::values;
}

void Plotwindow::makeplot(QList<QPair<QString, QString> > in){
    QVector<double> x(in.size()), y(in.size());
    for (int i = 0; i<in.size(); i++){
        x[i] = (double)i;
        QPair<QString, QString> temp = in[i];
        double tmpd = temp.second.toDouble();
        y[i] = tmpd;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, in.size());
    ui->customPlot->yAxis->setRange(0, 87);
    ui->customPlot->replot();
}
