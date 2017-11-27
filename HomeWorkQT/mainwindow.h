#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
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
    void saveToFile(QList<QPair<QString, QString>> in);

private slots:
    void on_Btn1_clicked();
    void on_Btn2_clicked();

public slots:
    void loadWebPage();
    void myReplyFinished(QNetworkReply* reply);
    QString getstrd();

private:
    Ui::MainWindow *ui;
    QString strd;
};

#endif // MAINWINDOW_H
