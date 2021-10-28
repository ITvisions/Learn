//
//  right_swap.c
//  demo
//
//  Created by vision chen on 2021/4/20.
//

#include "right_swap.h"
#include <stdio.h>
void right_swap(int *p1,int *p2) {
    int temp;  //临时变量
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
