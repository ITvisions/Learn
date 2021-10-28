//
//  getpwd.c
//  demo
//
//  Created by vision chen on 2021/2/28.
//
#include <stdio.h>
#include <ctype.h>
//#include "getpwd.h"
void getpwd(char *pwd,int pwdlen) {
    char ch = 0;
    int i = 0;
    while (i < pwdlen) {
//        ch = getch();
        if (ch == 'r') { // 回车结束输入
            printf("\n");
            break;
        }
        if (ch == '\b' && i > 0) {
            i--;
            printf("\b \b");
        } else if(isprint(ch)) {
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }
}
