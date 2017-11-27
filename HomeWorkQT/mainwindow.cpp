#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(myReplyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn1_clicked()
{
    loadWebPage();
}

void MainWindow::on_Btn2_clicked()
{

}

void MainWindow::setstrd(QString in){
    MainWindow::strd = in;
}

QString MainWindow::getstrd(){
    return MainWindow::strd;
}

void MainWindow::saveToFile(QList<QPair<QString, QString> > in){
    QString fileName = "D:\\GitQT\\HomeworkQT\\HomeworkQT\\Datafromwebsite.txt";
    QFile file(fileName);

    if(file.open(QIODevice::ReadWrite)){
        for(int i = 0; i<in.size(); i++){
            QPair<QString, QString> data = in[i];

            QTextStream stream(&file);
            stream<< data.first << " - " << data.second<<"\r\n";
        }
    }

}

void MainWindow::loadWebPage(){
    QNetworkRequest request;

    QString apiKey = "demo";
    QString urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=%0").arg(apiKey);

    QUrl url(urlString);

    request.setUrl(url);

    QNetworkReply *reply = manager->get(request);

    setstrd("Loading data is finished");
}

void MainWindow::myReplyFinished(QNetworkReply *reply){
    QByteArray webdata = reply->readAll();

    QList<QPair<QString, QString>> graphValues;

    QJsonDocument document = QJsonDocument::fromJson(webdata);

    if(document.isArray() == true){
        QJsonArray rootArray = document.array();

    }else if (document.isObject() == true){
        QJsonObject rootObject = document.object();

        QJsonObject timeSeries = rootObject["Time Series (Daily)"].toObject();
        QStringList keys = timeSeries.keys();
        for(QString k : keys){
            QJsonObject dayValues = timeSeries[k].toObject();
            QString openValues = dayValues["1. open"].toString();

            QPair<QString, QString> dataItem;
            dataItem.first = k;
            dataItem.second = openValues;

            graphValues.append(dataItem);
        }

        saveToFile(graphValues);
    }

}
