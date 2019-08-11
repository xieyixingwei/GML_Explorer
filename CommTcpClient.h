#ifndef COMM_TCP_CLIENT_H_
#define COMM_TCP_CLIENT_H_

#include "CommunicateInterface.h"
#include "LoopBuf.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>

#define RECV_LOOP_BUF_SIZE    (1024 * 1024)

class CommTcpClient : public QThread, public CommunicateInterface
{
    Q_OBJECT
public:
    CommTcpClient();
    virtual ~CommTcpClient();

    virtual bool Open(const QString& ip, qint32 port);
    virtual void Close();
    virtual bool IsOpen() { return m_tcp_socket->isOpen(); }
    virtual u32 Send(const char* buf, u32 len);
    virtual u32 Recv(char* buf, u32 len);

protected:
    virtual void run();

private slots:
    void Connected_Slot();
    void Disconnected_Slot();

private:
    QTcpSocket*   m_tcp_socket;
    QHostAddress* m_server_ip;
    LoopBuf*      m_recv_loop_buf;
    bool m_status;
};

#endif // CUARTMANAGER_H
