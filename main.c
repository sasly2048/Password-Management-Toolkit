#include <stdio.h>
#include "constants.h"
#include "password_generator.h"
#include "strength_checker.h"
#include "utils.h"
#include <string.h>

int main(void){
    char password[MAX_PASSWORD_LENGTH+1];
    int choice=read_int("1.Generate\n2.Check\nChoice: ",1,2);
    if(choice==1){
        int len=read_int("Length (8-128): ",MIN_PASSWORD_LENGTH,MAX_PASSWORD_LENGTH);
        generate_password(password,len);
        printf("Generated: %s\n",password);
        print_strength_report(password);
    }else{
        printf("Enter password: ");
        if(fgets(password,sizeof(password),stdin)){
            password[strcspn(password,"\n")]=0;
            print_strength_report(password);
        }
    }
    secure_zero(password,sizeof(password));
    return 0;
}
