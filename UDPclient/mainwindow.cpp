#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::btn_sendMessage);
}

void MainWindow::btn_sendMessage()
{

    QByteArray dataGram=ui->textEdit->toPlainText().toUtf8();
    udpSocket->writeDatagram(dataGram.data(),
                            dataGram.size(),
                            QHostAddress::LocalHost,    //udp广播地址
                            11451);
     qDebug("Send message:"+dataGram);
}

MainWindow::~MainWindow()
{
    delete ui;
}

