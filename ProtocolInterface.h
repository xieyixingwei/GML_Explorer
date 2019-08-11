#ifndef PROTOCOL_INTERFACE_H_
#define PROTOCOL_INTERFACE_H_

#include "CommType.h"
#include <QThread>

class ProtocolInterface
{
protected:
    ProtocolInterface() = default;

public:
    virtual ~ProtocolInterface() = default;

    virtual u32 PackDownData(char* dest, const char* src, u32 len) = 0;
};

class CommunicateInterface;

class GmlProtocol : public QThread, public ProtocolInterface
{
    Q_OBJECT
public:
    GmlProtocol(CommunicateInterface* con);
    ~GmlProtocol();

    virtual u32 PackDownData(char* dest, const char* src, u32 len) { return 0; }

protected:
    virtual void run();

private:
    CommunicateInterface* m_communicater;
};

#endif
