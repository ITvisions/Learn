#define NDEBUG // 忽略断言
#include <iostream>
#include <assert.h>
using namespace std;

int main() {
    int x = 7;
    assert(x==5);
    return 0;
}