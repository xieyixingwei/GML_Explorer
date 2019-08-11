#ifndef COMMUNICATE_INTERFACE_H_
#define COMMUNICATE_INTERFACE_H_

#include "CommType.h"

class CommunicateInterface
{
protected:
    CommunicateInterface() = default;

public:
    virtual ~CommunicateInterface() = default;

    virtual bool Open() = 0;
    virtual void Close() = 0;
    virtual bool IsOpen() = 0;
    virtual u32 Send(const char* buf, u32 len) = 0;
    virtual u32 Recv(char* buf, u32 len) = 0;
};

#endif
