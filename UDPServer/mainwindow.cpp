#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    myUDPsocket=new myUDP(this);

    ui->EditIP->setText("127.0.0.1");
    ui->Editport->setText("11451");
    ui->labelIP->setText("当前IP：127.0.0.1");
    ui->labelPort->setText("当前端口：11451");
    connect(myUDPsocket,&myUDP::signalReceiveData ,this,&MainWindow::processData);
    connect(ui->btn_Confirm,&QPushButton::clicked,this,[=](){upDateIP();setPort();});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processData(QString text){
    ui->textBrowser->append(text);
    return;
}

void MainWindow::setPort(){
    if( myUDPsocket->setPort(ui->Editport->text().toUtf8())){
        ui->labelPort->setText("当前端口："+ui->Editport->text().toUtf8());
    }else{
        ui->Editport->setText(myUDPsocket->getPort());
    }

}

void MainWindow::upDateIP(){

    if( myUDPsocket->setIp(ui->EditIP->text().toUtf8())){
        ui->labelIP->setText("当前IP："+ui->EditIP->text().toUtf8());
    }else{
        ui->EditIP->setText(myUDPsocket->getIP());
    }
}
