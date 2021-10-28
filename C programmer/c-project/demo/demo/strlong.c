//
//  strlong.c
//  demo
//
//  Created by vision chen on 2021/4/20.
//

#include <stdio.h>
#include <string.h>
#include "strlong.h"
char *strlong(char *str1, char *str2) {
    if (strlen(str1) >= strlen(str2)) {
        return str1;
    } else {
        return str2;
    }
}
