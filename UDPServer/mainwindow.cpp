#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->append("aaa");
    udpSocket=new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost,11451);
    connect(udpSocket,&QUdpSocket::readyRead,this,&MainWindow::processData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processData(){
    QString UDPdata;
    while(udpSocket->hasPendingDatagrams()){
            QByteArray dataGram;
            dataGram.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(dataGram.data(),dataGram.size());
            ui->textBrowser->append(dataGram);

    }
 qDebug("receive ");
    return;
}
