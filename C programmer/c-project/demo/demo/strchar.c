//
//  strchar.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "strchar.h"
#include "string.h"
void strchar(char *str , char c) {
    int flag = 0;
    int index;
    for (int i = 0 , len = strlen(str); i < len ; i++) {
        if (str[i] == c) {
            flag = 1;
            index = i;
        }
    }
    if (flag != 0) {
        printf("%c is exit in %s, the index is %d\n",c,str,index);
    } else {
        printf("%c is not exit in %s\n",c,str);
    }
}
