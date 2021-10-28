//
//  binary_search.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "binary_search.h"
void binary_search(int* arr, int len,int m) {
    int low = 0;
    int hight = len;
    int mid;
    int flag = 0;
    while ((low <= hight)) {
        mid = (low + hight) / 2;
        if (m < arr[mid]) {
            hight = mid - 1;
        }
        else if(m > arr[mid]) {
            low = mid + 1;
        } else {
            printf("下标为: %d\n",mid);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("sorry!");
    }
}
