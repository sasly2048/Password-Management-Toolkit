#include "utils.h"
#include <stdio.h>
#include <string.h>
int read_int(const char *prompt,int min,int max){
    char buf[64];
    long v;
    while(1){
        printf("%s",prompt);
        if(!fgets(buf,sizeof(buf),stdin)) return min;
        if(sscanf(buf,"%ld",&v)==1 && v>=min && v<=max) return (int)v;
        printf("Invalid input.\n");
    }
}
void secure_zero(void *ptr,unsigned long n){
    volatile unsigned char *p=(volatile unsigned char*)ptr;
    while(n--) *p++=0;
}
