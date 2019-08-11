
#include "ProtocolInterface.h"
#include "CommunicateInterface.h"

GmlProtocol::GmlProtocol(CommunicateInterface* con)
    : m_communicater(con)
{
    this->start();
}

GmlProtocol::~GmlProtocol()
{

}

void GmlProtocol::run()
{
    char byte = 0;

    while(true)
    {
        QThread::msleep(20);

        if(!m_communicater->IsOpen())
        {
            continue;
        }

        while(1 == m_communicater->Recv(&byte, 1))
        {

        }
    }
}
