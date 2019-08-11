
#include "LoopBuf.h"

extern "C" {
#include <string.h>
}

LoopBuf::LoopBuf(u32 size)
{
    m_buf = new char[size];
    m_size = size;
    m_wp = 0;
    m_rp = 0;
}

void LoopBuf::Clear()
{
    m_wp = 0;
    m_rp = 0;
}

bool LoopBuf::IsEmpty()
{
    return m_wp == m_rp;
}

u32 LoopBuf::DataCount()
{
    u32 wPos = m_wp; //avoid m_wp be modify
    u32 rPos = m_rp; //avoid m_rp be modify

    return (wPos >= rPos) ? (wPos - rPos) : (m_size - rPos + wPos);
}

u32 LoopBuf::FreeCount()
{
    return (m_size - DataCount());
}

u32 LoopBuf::Write(const buf_type* buf, u32 len)
{
    if((nullptr == buf) || (len > FreeCount()))
    {
        return 0;
    }

    u32 bufLen = m_size - m_wp;
    u32 firstCopyLen = (len < bufLen) ? len : bufLen;
    u32 secondCopyLen = len - firstCopyLen;

    memcpy(&m_buf[m_wp], &buf[0], firstCopyLen);
    memcpy(&m_buf[0], &buf[firstCopyLen], secondCopyLen);

    m_wp = (len < bufLen) ? (m_wp + firstCopyLen) : secondCopyLen;

    return len;
}

u32 LoopBuf::Read(buf_type* buf, u32 len)
{
    if((nullptr == buf) || (len > DataCount()))
    {
        return 0;
    }

    u32 bufLen = m_size - m_rp;
    u32 firstCopyLen = (len < bufLen) ? len : bufLen;
    u32 secondCopyLen = len - firstCopyLen;

    memcpy(&buf[0], &m_buf[m_rp], firstCopyLen);
    memcpy(&buf[firstCopyLen], &m_buf[0], secondCopyLen);

    m_rp = (len < bufLen) ? (m_rp + firstCopyLen) : secondCopyLen;

    return len;
}

