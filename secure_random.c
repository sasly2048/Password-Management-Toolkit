#include "secure_random.h"
#ifdef _WIN32
#include <windows.h>
#include <bcrypt.h>
#pragma comment(lib,"bcrypt.lib")
void secure_random_bytes(unsigned char *buf,size_t len){
    BCryptGenRandom(NULL,buf,(ULONG)len,BCRYPT_USE_SYSTEM_PREFERRED_RNG);
}
int secure_random_int(int max){
    unsigned int x;
    secure_random_bytes((unsigned char*)&x,sizeof(x));
    return (int)(x % (unsigned)max);
}
#else
#include <stdlib.h>
#include <time.h>
void secure_random_bytes(unsigned char *buf,size_t len){
    static int init=0;
    if(!init){srand((unsigned)time(NULL));init=1;}
    for(size_t i=0;i<len;i++) buf[i]=(unsigned char)(rand()%256);
}
int secure_random_int(int max){
    unsigned int x;
    secure_random_bytes((unsigned char*)&x,sizeof(x));
    return (int)(x % (unsigned)max);
}
#endif
