#include "myudp.h"
#include <QUdpSocket>
myUDP::myUDP()
{
     port=11451;
     addr="127.0.0.1";
     udpSocket=new QUdpSocket();


     connect(udpSocket,&QUdpSocket::readyRead,this,&myUDP::receiveData);

}
myUDP::myUDP(QObject *parent) : QObject(parent)
{
    port=11451;
    addr="127.0.0.1";
    udpSocket=new QUdpSocket(parent);

    connect(udpSocket,&QUdpSocket::readyRead,this,&myUDP::receiveData);

}
myUDP::~myUDP(){
return ;
}
void myUDP::sendMessage(QString text)
{

    QByteArray dataGram=text.toUtf8();
    udpSocket->writeDatagram(dataGram.data(),
                            dataGram.size(),
                            QHostAddress(addr),    //udp广播地址
                            port);
    qDebug("Send message:"+dataGram);
}
bool myUDP::setPort(QString portNum){
    if(portNum.toUtf8().isEmpty()){
         qDebug("null port");
         return false;
    }else{
            int num=portNum.toUtf8().toInt();
            if(num==0||num>65535){
               qDebug("error port,out of port range");
               return false;
            }else{
                port= num;
                qDebug("set port:"+QString::number(port,10).toUtf8());
            }
        }
    return true;
}
bool myUDP::setIp(QString IpNum){
    QHostAddress test;
    if (!test.setAddress(IpNum))
        {
            qDebug("wrong IP number");
            return false;
        }
    else {
        addr=IpNum;
    }
    return true;
}
void myUDP::receiveData(){
    QString UDPdata;
    while(udpSocket->hasPendingDatagrams()){
            QByteArray dataGram;
            dataGram.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(dataGram.data(),dataGram.size());
            UDPdata=dataGram;
    }
    qDebug("receive:"+UDPdata.toUtf8());
    emit(signalReceiveData(UDPdata));
    return ;
}
QString myUDP::getIP(){
    return addr;
}

QString myUDP::getPort(){
    return QString::number(port);
}


