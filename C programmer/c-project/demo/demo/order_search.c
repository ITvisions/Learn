//
//  order_search.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "order_search.h"

void order_search(int* a,int len, int m) {
    int i;
    for (i = 0 ; i < len; i++) {
        if (a[i] == m) {
            printf("下标为：%d\n",i);
            break;
        }
    }
    if (i == len) {
        printf("sorry\n");
    }
}
