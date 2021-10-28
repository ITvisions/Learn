//
//  gcd.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "gcd.h"
int gcd(int a,int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        int temp2 = b;
        b = a % b;
        a = temp2;
    }
    return  a;
}
