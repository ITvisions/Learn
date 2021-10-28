//
//  areaV.c
//  demo
//
//  Created by vision chen on 2021/4/4.
//

#include "areaV.h"
extern int area1,area2,area3;
int areaV(int a,int b,int c){
    int v;
    v = a * b * c;
    area1 = a * b;
    area2 = b * c;
    area3 = a * c;
    return v;
}
