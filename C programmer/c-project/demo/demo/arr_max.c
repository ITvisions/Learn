//
//  arr_max.c
//  demo
//
//  Created by vision chen on 2021/4/20.
//

#include "arr_max.h"
#include <stdio.h>
int arr_max(int *arr, int len) {
    int i , max = arr[0];
    for (i = 0 ; i < len; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
