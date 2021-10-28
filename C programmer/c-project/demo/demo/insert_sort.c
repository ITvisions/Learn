//
//  insert_sort.c
//  demo
//
//  Created by vision chen on 2021/3/28.
//

#include "insert_sort.h"
//void insert_sort(int* a,int len) {
//    int temp,j;
//    for (int i = 1 ; i < len ; i++) { // 从第二个开始，到最后一个插入到有序数组中
//        temp = a[i];
//        j = i - 1;
//        while (j >= 0 && a[j] > temp) {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j + 1] = temp;
//        for (int m = 0 ; m < len ; m++) {
//            printf("%d ",a[m]);
//        }
//        printf("\n");
//    }
//}

//void insert_sort(int* arr,int len) {
//    int temp,j;
//    for(int i = 1 ; i < len ; i++) {
//      temp = arr[i];
//      j = i - 1;
//      while(j >= 0 &&  arr[j] > temp) {
//        arr[j+1] = arr[j];
//        j--;
//      }
//      arr[j+1] = temp;
//      for(int m = 0 ; m < len ; m++) {
//        printf("%d ",arr[m]);
//      }
//      printf("\n");
//    }
//  }

void insert_sort(int* a,int len) {
    int temp,j;
    for(int i = 1 ; i < len ; i++) {
      temp = a[i];
      j = i - 1;
      while(j >= 0 && a[j] > temp) {
        a[j+1] = a[j];
        j--;
      }
      a[j + 1] = temp;
      for(int m = 0 ; m < len ; m++) {
        printf("%d ",a[m]);
      }
      printf("\n");
    }
  }
