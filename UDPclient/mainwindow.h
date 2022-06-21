#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "QUdpSocket"
#include "QHostAddress"
#include "QString"
#include "QTextEdit"

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
    void btn_sendMessage();
private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
};
#endif // MAINWINDOW_H
