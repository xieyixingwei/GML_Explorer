#ifndef COMM_UART_H_
#define COMM_UART_H_

#include "CommunicateInterface.h"
#include "LoopBuf.h"
#include <QtSerialPort/QtSerialPort>
#include <QThread>

#define RECV_LOOP_BUF_SIZE    (1024 * 1024)

class CommUart : public QThread, public CommunicateInterface
{
    Q_OBJECT
public:
    CommUart();
    virtual ~CommUart();

    virtual bool Open(const QString& comPort, qint32 baudRate);
    virtual void Close();
    virtual bool IsOpen() { m_serial->isOpen(); }
    virtual u32 Send(const char* buf, u32 len);
    virtual u32 Recv(char* buf, u32 len);

protected:
    virtual void run();

private:
    QSerialPort* m_serial;
    LoopBuf*     m_recv_loop_buf;
};

#endif // CUARTMANAGER_H
