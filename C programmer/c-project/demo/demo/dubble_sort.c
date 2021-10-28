//
//  dubble_sort.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//
#include <stdio.h>
#include "dubble_sort.h"
//void dubble_sort(int* a,int len){
//    for (int i = 0 ; i < len - 1 ; i++) { // 外层循环 多少轮
//        for (int j = 0 ; j < len - i - 1 ; j++) { //内层循环，比较元素
//            if (a[j] > a[j+1] ) {
//                int tem = a[j];
//                a[j] = a[j+1];
//                a[j+1] = tem;
//            }
//        }
//        for (int s = 0 ; s < 10; s++) {
//            printf("%d ",a[s]);
//        }
//        printf("\n");
//    }
//}
void dubble_sort(int* a,int len) {
    int temp;
    for(int i = 0 ; i < len - 1 ; i++) {
      for(int j = 0 ; j < len - i - 1 ; j++) {
        if(a[j+1] < a[j]) {
          temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }
      for(int m = 0 ; m < len ; m++) {
        printf("%d ",a[m]);
      }
      printf("\n");
    }
  }
