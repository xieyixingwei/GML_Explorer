
#include "CommUart.h"
#include <QString>

CommUart::CommUart()
{
    m_serial = new QSerialPort;
    m_recv_loop_buf = new LoopBuf(RECV_LOOP_BUF_SIZE);
}

CommUart::~CommUart()
{
    DELETE(m_serial);
    DELETE(m_recv_loop_buf);
}

bool CommUart::Open(const QString& comPort, qint32 baudRate)
{
    if(m_serial->isOpen())
    {
        return false;
    }

    m_serial->setPortName(comPort);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    bool res = m_serial->open(QIODevice::ReadWrite);

    if(true == res)
    {
        this->start(); //start the recv thread -- void run()
    }

    return res;
}

void CommUart::Close()
{
    if(m_serial->isOpen())
    {
        m_serial->clear();
        m_serial->close();
        this->terminate(); //terminate recv thread -- void run()
        this->wait(); //waiting for recv thread is stoped
    }
}

u32 CommUart::Send(const char* buf, u32 len)
{
    return m_serial->write(buf, (qint64)len);
}

u32 CommUart::Recv(char* buf, u32 len)
{
    return m_recv_loop_buf->Read(buf, len);
}

void CommUart::run()
{
    const qint64 TEMP_BUF_SIZE = 10 * 1024;
    char buf[TEMP_BUF_SIZE] = { 0 };
    qint64 len = 0;

    while(true)
    {
        while(m_serial->isOpen() && ((len = m_serial->bytesAvailable()) > 0))
        {
            len = m_serial->read(buf, len);

            if(len > 0)
            {
                m_recv_loop_buf->Write(buf, len);
            }
        }

        QThread::msleep(20);
    }
}
