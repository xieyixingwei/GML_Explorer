#ifndef LOOP_BUF_H_
#define LOOP_BUF_H_

#include "CommType.h"

using buf_type = char;

class LoopBuf
{
public:
    LoopBuf(u32 size);
    virtual ~LoopBuf() = default;

    inline void Clear();
    inline bool IsEmpty();
    inline u32 DataCount();
    inline u32 FreeCount();
    u32 Write(const buf_type* buf, u32 len);
    u32 Read(buf_type* buf, u32 len);

private:
    buf_type* m_buf;
    u32 m_size;
    u32 m_wp;
    u32 m_rp;
};

#endif
