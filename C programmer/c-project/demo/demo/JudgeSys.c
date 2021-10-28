//
//  JudgeSys.c
//  demo
//
//  Created by vision chen on 2021/5/2.
//

#include "JudgeSys.h"
int JudgeSys() {
    union un {
        char c;
        int i;
    };
    union un a;
    a.i = 1;
    return a.c;
}
