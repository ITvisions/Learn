//
//  strcmp_alias.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "strcmp_alias.h"
int strcmp_alias(char *s21, char *s22){
    int i, result;
        for(i=0; (result = s21[i] - s22[i]) == 0; i++){
            if(s21[i] == '\0' || s22[i] == '\0'){
                break;
            }
        }
       
    return result;
}
