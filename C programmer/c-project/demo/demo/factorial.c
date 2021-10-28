//
//  factorial.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "factorial.h"
long factorial(int n) {
    int i;
    long result = 1;
    for (i = 1 ; i <= n ; i++) {
        result *= i;
    }
    return result;
}
