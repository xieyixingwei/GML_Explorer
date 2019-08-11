#ifndef COMM_TYPE_H_
#define COMM_TYPE_H_

typedef char            s8;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef short           s16;
typedef unsigned int    u32;
typedef int             s32;

#ifndef NULL
#define NULL   0
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))
#endif

#define DELETE(x) \
    do{\
        if(NULL != x){\
            delete x;\
            x = NULL;}\
    }while(0)

#define DELETE_ARRAY(x) \
    do{\
        if(NULL != x){\
            delete[] x;\
            x = NULL;}\
    }while(0)

#endif

