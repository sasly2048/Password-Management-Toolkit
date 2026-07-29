#include "password_generator.h"
#include "secure_random.h"
#include <string.h>

static const char D[]="0123456789";
static const char U[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char L[]="abcdefghijklmnopqrstuvwxyz";
static const char S[]="!@#$%^&*()-_=+[]{};:,.<>?/|~";

static void swap(char*a,char*b){char t=*a;*a=*b;*b=t;}

void generate_password(char *p,int len){
    p[0]=D[secure_random_int((int)strlen(D))];
    p[1]=U[secure_random_int((int)strlen(U))];
    p[2]=L[secure_random_int((int)strlen(L))];
    p[3]=S[secure_random_int((int)strlen(S))];
    const char *sets[]={D,U,L,S};
    for(int i=4;i<len;i++){
        int s=secure_random_int(4);
        p[i]=sets[s][secure_random_int((int)strlen(sets[s]))];
    }
    for(int i=len-1;i>0;i--){
        int j=secure_random_int(i+1);
        swap(&p[i],&p[j]);
    }
    p[len]='\0';
}
