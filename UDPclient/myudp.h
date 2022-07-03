#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

class myUDP : public QObject
{
Q_OBJECT
public:
    myUDP();
    explicit myUDP(QObject *parent=nullptr);
    ~myUDP();
public slots:
    //发送信息
    void sendMessage(QString text);
    //设置端口
    bool setPort(QString portNum);
    //设置目标IP
    bool setIp(QString IpNum);
    //接收数据
    void receiveData();
    //获取IP
    QString getIP();
    //获取端口
    QString getPort();

signals:
    void signalReceiveData(QString data);
private:
    //UDP套接字
    QUdpSocket* udpSocket;
    //当前端口
    int port;
    QString addr;
};

#endif // MYUDP_H
