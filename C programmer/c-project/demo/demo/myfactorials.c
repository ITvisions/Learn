//
//  myfactorials.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "myfactorials.h"
long myfactorials(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return myfactorials(n-1) * n;
    }
}
