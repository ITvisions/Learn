//
//  prime.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "prime.h"
void prime(int n) {
    int is_prime = 1, i;
    if (n < 0) {
        printf("illegal number: %d\n",n);
        return;
    }
    for (i = 2 ; i < n ; i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    if (is_prime > 0 ) {
        printf("%d is a preme number\n",n);
    } else {
        printf("%d is not a preme number\n",n);
    }
}
