#include <QCoreApplication>
#include <QtSerialPort/QtSerialPort>
#include <iostream>
#include <QByteArray>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSerialPort IMU;
    IMU.setPortName("ttyAMA0");
    IMU.setBaudRate(QSerialPort::Baud9600);
    IMU.setDataBits(QSerialPort::Data8);
    IMU.setFlowControl(QSerialPort::NoFlowControl);
    IMU.setParity(QSerialPort::NoParity);
    IMU.setStopBits(QSerialPort::OneStop);

    IMU.open(QIODevice::ReadOnly);
    while (IMU.waitForReadyRead(1000)){
        cout << "IMU DATA" << IMU.readAll().toStdString() << endl;
    }

    IMU.close();
    return a.exec();
}
