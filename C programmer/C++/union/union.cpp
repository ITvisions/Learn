#include <iostream>

using namespace std;
/**
 * 默认访问控制符为public
 */
 union UnionTest{
     /**
     * 可以含有构造函数、析构函数
     */
     UnionTest() : i(10) {print(i + 9);};
     ~UnionTest(){};
     int i;
 private:
     void print(int i){std::cout<<i<<std::endl;};
 };
 /**
 * 全局匿名联合必须是静态的
 */
 static union {
     int i;
     double d;
 };
int main() {
    UnionTest u;
    union {
        int i;
        double d;
    };
    cout << u.i << endl; // 输出 UnionTest 联合的 10
    ::i = 20;
    cout << ::i << endl; // 输出全局静态匿名联合的 20
    /**
     * 匿名union在定义所在作用域可直接访问union成员
     */
     i = 30;
     cout << i << endl; // 输出局部匿名联合的 30
    return 0;
}