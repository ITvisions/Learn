//
//  myprint.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "myprint.h"
#include <stdio.h>
void myprint(int* sarr,int slen,BOOL isBefore) {
    int si;
    if (isBefore) {
        printf("before sort:");
    } else {
        printf("after sort:");
    }
    for (si = 0; si < slen ; si++) {
        printf("%d ",sarr[si]);
    }
    printf("\n");
}
