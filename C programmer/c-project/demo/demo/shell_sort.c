//
//  shell_sort.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "shell_sort.h"
void shell_sort(int* a,int len) {
    int step = len / 2;
    int temp,j;
    while (step) {
        for (int i = step; i < len ; i++) {
            temp = a[i];
            j = i - step;
            while (j >= 0 && a[j] > temp) {
                a[j+step] = a[j];
                j -= step;
            }
            a[j+step] = temp;
        }
        step = step/2;
    }
    for (int m = 0 ; m < len ; m++) {
        printf("%d ",a[m]);
    }
    printf("\n");
}
