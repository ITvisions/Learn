//
//  select_sort.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "select_sort.h"

//void select_sort(int* a,int len){
//    int temp;
//    int minIndex;
//    for (int i = 0 ; i < len - 1; i++) {
//        // 每一轮从待排数组中选出最小的，将最小的放在下标为i处
//        temp = a[i];
//        minIndex = i;
//        for (int j = i ; j < len; j++) {
//            minIndex = a[j] < a[minIndex] ? j:minIndex;
//        }
//        a[i] = a[minIndex];
//        a[minIndex] = temp;
//        for (int m = 0 ; m < len ; m++) {
//            printf("%d ",a[m]);
//        }
//        printf("\n");
//    }
//}

//void select_sort(int*  arr,int len) {
//    int temp,minIndex;
//    for(int i = 0 ; i < len - 1 ; i++) {
//      temp = arr[i];
//      minIndex = i;
//      for(int j = i ; j < len ; j++) {
//        minIndex = arr[j] < arr[minIndex] ? j:minIndex;
//      }
//      arr[i] = arr[minIndex];
//      arr[minIndex] = temp;
//      for(int m = 0 ; m < len ; m++) {
//        printf("%d ",arr[m]);
//      }
//      printf("\n");
//    }
//  }

void select_sort(int* a,int len) {
    int temp,minIndex;
    for(int i = 0 ; i < len - 1; i++) {
      temp = a[i];
      minIndex = i;
      for(int j = i; j < len ; j++) {
        minIndex = a[j] < a[minIndex] ? j:minIndex;
      }
      a[i] = a[minIndex];
      a[minIndex] = temp;
      for(int m = 0 ; m < len ; m++) {
        printf("%d ",a[m]);
      }
      printf("\n");
    }
  }
