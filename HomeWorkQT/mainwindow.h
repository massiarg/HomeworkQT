#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "plotwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QNetworkAccessManager* manager;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setstrd(QString in);
    void saveToFile(QList<QList<QPair<QString, QString>>> in);



private slots:
    void on_Btn1_clicked();
    void on_Btn2_clicked();

    void on_Btn3_clicked();

    void on_Btn4_clicked();

    void on_Btn5_clicked();

    void on_Btn6_clicked();

public slots:
    void loadWebPage();
    void myReplyFinished(QNetworkReply* reply);
    QString getstrd();

private:
    Ui::MainWindow *ui;
    QString strd;
    QList<QPair<QString, QString>> graphValues;
    QList<QList<QPair<QString, QString>>> alldata;
    Plotwindow *plotOpen, *plotHigh, *plotLow, *plotClose, *plotVolume;
};

#endif // MAINWINDOW_H
