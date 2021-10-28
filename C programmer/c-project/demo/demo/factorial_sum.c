//
//  factorial_sum.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "factorial_sum.h"
#include "factorial.h"
long factorial_sum(long n) {
    int i;
    long result = 0;
    for (i = 1 ; i <= n ; i++) {
        result += factorial(i);
    }
    return  result;
}
