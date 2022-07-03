#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myUDPsocket=new myUDP(this);

    myUDPsocket->setIp("127.0.0.1");
    ui->EditPort->setText("11451");
    ui->EditIP->setText("127.0.0.1");
    ui->labelPort->setText("目标端口：11451");
    ui->labelIP->setText("目标IP：127.0.0.1");
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){btn_sendMessage();});
    connect(ui->btnConfirm,&QPushButton::clicked,this,[=](){btn_setPort();upDateIP();});
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::btn_sendMessage(){
    myUDPsocket->sendMessage(ui->textEdit->toPlainText().toUtf8());
    ui->textBrowser->append(ui->textEdit->toPlainText().toUtf8());
    ui->textEdit->clear();
}

void MainWindow::btn_setPort(){

   if( myUDPsocket->setPort(ui->EditPort->text().toUtf8())){
       ui->labelPort->clear();
       ui->labelPort->setText("目标端口："+ui->EditPort->text().toUtf8());
   }else {
//TODO 错误弹窗
       ui->EditPort->setText(myUDPsocket->getPort());
    }

}
void MainWindow::upDateIP(){
    if( myUDPsocket->setIp(ui->EditIP->text().toUtf8())){
        ui->labelIP->clear();
        ui->labelIP->setText("目标IP："+ui->EditIP->text().toUtf8());
    }else {
//TODO 错误弹窗
            ui->EditIP->setText(myUDPsocket->getIP());
}
}
