#include "strength_checker.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int password_score(const char *p){
    int len=(int)strlen(p),u=0,l=0,d=0,s=0,rep=0;
    for(int i=0;i<len;i++){
        unsigned char c=(unsigned char)p[i];
        if(isupper(c))u=1;
        else if(islower(c))l=1;
        else if(isdigit(c))d=1;
        else s=1;
        if(i>0 && p[i]==p[i-1]) rep++;
    }
    int score=0;
    if(len>=12) score+=2;
    else if(len>=8) score++;
    score+=u+l+d+s;
    if(rep>2) score--;
    if(score<0)score=0;
    if(score>6)score=6;
    return score;
}
void print_strength_report(const char *p){
    static const char*label[]={"Very Weak","Weak","Fair","Moderate","Strong","Very Strong","Excellent"};
    printf("Strength: %s\\n",label[password_score(p)]);
}
