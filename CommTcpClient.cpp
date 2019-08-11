
#include "CommTcpClient.h"
#include <QString>
#include <QTime>
#include <QCoreApplication>

CommTcpClient::CommTcpClient()
{
    m_tcp_socket = new QTcpSocket(this);
    m_server_ip = new QHostAddress;
    m_recv_loop_buf = new LoopBuf(RECV_LOOP_BUF_SIZE);
    m_status = false;

    connect(m_tcp_socket, SIGNAL(connected()), this, SLOT(Connected_Slot()));
    connect(m_tcp_socket, SIGNAL(disconnected()), this, SLOT(Disconnected_Slot()));
}

CommTcpClient::~CommTcpClient()
{
    DELETE(m_tcp_socket);
    DELETE(m_recv_loop_buf);
}

void CommTcpClient::Connected_Slot()
{
    m_status = true;
}

void CommTcpClient::Disconnected_Slot()
{
    m_status = false;
}

bool CommTcpClient::Open(const QString& ip, qint32 port)
{
    if(m_tcp_socket->isOpen())
    {
        return true;
    }

    m_server_ip->setAddress(ip);
    m_tcp_socket->connectToHost(*m_server_ip, port);

    const qint32 TIME_OUT = 500;
    qint32 i = 0;

    while((false == m_status) && (++i < TIME_OUT))
    {
        QTime dieTime = QTime::currentTime().addMSecs(10); //10ms
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    if(true == m_status)
    {
        this->start(); //start the recv thread -- void run()
    }

    return m_status;
}

void CommTcpClient::Close()
{
    if(m_tcp_socket->isOpen())
    {
        m_tcp_socket->close();
        this->terminate(); //terminate recv thread -- void run()
        this->wait(); //waiting for recv thread is stoped
    }
}

u32 CommTcpClient::Send(const char* buf, u32 len)
{
    return m_tcp_socket->write(buf, (qint64)len);
}

u32 CommTcpClient::Recv(char* buf, u32 len)
{
    return m_recv_loop_buf->Read(buf, len);
}

void CommTcpClient::run()
{
    const qint64 TEMP_BUF_SIZE = 10 * 1024;
    char buf[TEMP_BUF_SIZE] = { 0 };
    qint64 len = 0;

    while(true)
    {
        while(m_tcp_socket->isOpen() && ((len = m_tcp_socket->bytesAvailable()) > 0))
        {
            len = m_tcp_socket->read(buf, (qint64)len);

            if(len > 0)
            {
                m_recv_loop_buf->Write(buf, len);
            }
        }

        QThread::msleep(20);
    }
}
