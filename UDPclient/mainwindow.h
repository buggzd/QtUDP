#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "QUdpSocket"
#include "QHostAddress"
#include "QString"
#include "QTextEdit"
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
    //按钮的槽函数
private slots:
    //消息发送按钮
    void btn_sendMessage();
    //设置端口
    void btn_setPort();
private:
    Ui::MainWindow *ui;
    myUDP *myUDPsocket;
    //设置目标IP
    void upDateIP();
};
#endif // MAINWINDOW_H
