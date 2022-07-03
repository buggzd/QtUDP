#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "QUdpSocket"
#include "QHostAddress"
#include "QString"
#include "myudp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //设置监听端口
    void setPort();
private:
    Ui::MainWindow *ui;
    myUDP *myUDPsocket;
    //处理数据
    void processData(QString text);
    //设置监听端口
    void upDateIP();
};
#endif // MAINWINDOW_H
