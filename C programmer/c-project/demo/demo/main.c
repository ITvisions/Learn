//
//  main.c
//  demo
//
//  Created by vision chen on 2021/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "itoa.h"
//#include "myprint.h"
#include "dubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"
#include "shell_sort.h"
#include "order_search.h"
#include "binary_search.h"
#include "strcmp_alias.h"
#include "prime.h"
#include "factorial_sum.h"
#include "areaV.h"
#include "gcd.h"
#include "strchar.h"
#include "myfactorials.h"
#include "second_main.h"
#include "pointer.h" // 指针
#include "constructer.h" // 结构体
#include "fileIO.h" // 文件操作

#if _WIN32 // 识别windows平台
#include <windows.h>
#elseif __linux__ // 识别linux平台
#include <unistd.h>
#endif

int area1,area2,area3; // 全局变量
// 函数
// c语言不允许函数嵌套定义
// 以下这样的写法是正确的。两个函数func1()并没有在func2()中定义，只是调用了，因此是可以的
void func1() {
    printf("123");
}
void func2() {
    printf("456");
    func1();
}
int c1;
float c2;
char c3;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 不同的平台下调用不同的函数
#if _WIN32
    Sleep(5000);
#elseif __linux__
    sleep(5);
#endif
    printf("test for precompiler\n");
    
    int a = 99;
    char c = 'A';
    float d = 90.99;
    printf("Hello, World!\n");
    puts("hhhh");
    printf("value is %d\n",a);
    printf("a= %d,c= %c,d = %f\n",a,c,d);
    printf("a=%d,b=%c\n",100,'M');
    printf("a=%ds\n",99);
    puts("C语言中文网！"  "C语言和C++！"  "http://c.biancheng.net\n");
    long e = 2984;
    int f = sizeof(short);
    int g = sizeof(e);
    int h = sizeof e;
    printf("%d,%d,%d\n",f,g,h);
    short aa = 12;
    int b = 897;
    long cc = 7833;
    printf("%hd,%d,%ld\n",aa,b,cc);
    short ae = 0B01011;
    int ad = 0234;
    long af= 0xff1332;
    printf("%ho,%o,%lo\n",ae,ad,af); // 8进制形式输出
    printf("%hd,%d,%ld\n",ae,ad,af); // 10进制输出
    printf("%hx,%x,%lx\n",ae,ad,af); // 16进制输出
    printf("%hX,%X,%lX\n",ae,ad,af); // 16进制字母大写输出
    // 上述四个输出有一些缺陷，那就是无法分辨是8进制，还是10进制，还是16进制，可以通过加#前缀区分
    printf("%#ho,%#o,%#lo\n",ae,ad,af); // 8进制形式输出
    printf("%hd,%d,%ld\n",ae,ad,af); // 10进制输出
    printf("%#hx,%#x,%#lx\n",ae,ad,af); // 16进制输出
    printf("%#hX,%#X,%#lX\n",ae,ad,af); // 16进制字母大写输出
    // 如果只考虑正数，那么各种类型的表示的数值范围（取值范围）就比原来少了一半
    // 很多情况下，我们非常确定某个数字是正数，例如班级人数，这时符号位就是多余的，不如把符号位删掉，将所有位用来存储数值，这样能表示的数值就更大（大一倍）
    // 如果我们不希望设置符号位，可以在数据类型前面加上unsigned关键字
    unsigned short q = 12;
    unsigned int qw = 1003;
    unsigned qr = 1003; // 等价于 unsigned int qw，如果是unsigned int类型可以将int省略
    unsigned long qe = 209322;
    printf("%hd,%d,%d,%ld\n",q,qw,qr,qe);
    unsigned short we = 23;
    unsigned wr = 2312;
    unsigned long wt = 894363;
    printf("%ho,%o,%lo\n",we,wr,wt); // 输出无符号8进制数
    printf("%hu,%u,%lu\n",we,wr,wt); // 输出无符号10进制数
    printf("%hx,%x,%lx\n",we,wr,wt); // 输出无符号16进制数，小写
    printf("%hX,%X,%lX\n",we,wr,wt); // 输出无符号16进制数，大写
    int gg = 1.093e3;
    printf("%d\n",gg);
    float y1 = 1.0989909;
    double y2 = 1.09373643731;
    double y3 = 1.09379773e-2;
    printf("%f,%e,%E\n",y1,y1,y1);
    printf("%lf,%le,%lE\n",y2,y2,y2);
    printf("%lf\n",y3); // %f和%lf默认保存6位小数位，不足6位补0，超过按4舍5入截断
    float y4 = 78;
    double y5 = 90;
    printf("%f,%lf\n",y4,y5); // 将整数赋值给float或者double类型时，会变成小数
    float y6 = 10.7;
    double y7 = 923.2376234;
    printf("%e,%le\n",y6,y7); // 以指数形式输出小数时，输出结果为科学记数法，并且尾数保留6位小数，不足6位补0，超过按4舍5入截断
    float y8 = 0.0000001;
    float y9 = 90000000;
    float y10 = 1.34;
    float y11 = 1.32423232;
    // %g默认最多保留6位有效数字，包括小数部分和整数部分，%f和%e默认保留6位小数，只包括小数部分
    // %g不会强加0来凑够有效位数，而%f和%e会强加0来凑够小数部分的位数，所以一般%g会比较符合用户习惯
    // %g，%G以指数形式输出float类型，只是e大小写不一样，%lg，%lG以指数形式输出double类型，只是e大小写不一样
    printf("%g,%g,%g,%g\n",y8,y9,y10,y11); // %g会对比十进制和指数形式，以最短的方式输出小数，即占用最小的字符
    long y12 = 12; // 12和90这两个数字默认都是int类型的，而将12赋值给12，必须先从int类型转换成long
    int y13 = 90;  // 默认的不用转换
    float y14 = 23.32; // 23.32和92.303这两个数字默认是double类型的，而将92.303赋值给y15，必须先从double转换成float
    double y15 = 92.303; // 默认的不用转换
    printf("%ld,%d,%f,%lf\n",y12,y13,y14,y15);
    // 如果不想让数字使用默认类型，可以给数字加上后缀，手动指明类型
    // 加上后缀虽然数字的类型变了，但是并不意味着该数字只能赋值给制定的类型，他仍然能够赋值给其他类型，只要进行一下转换就可以了
    long y16 = 32l; // 在整数后面加上l或者L（不区分大小写）表明该数字是long类型
    long y17 = 930L;
    float y18 = 0.324f; // 在小数后面加上f或者F（不区分大小写）表明该数字是float类型
    float y19 = 2.32F;
    printf("%ld,%ld,%f,%f\n",y16,y17,y18,y19);
    // 在c语言中，小数和整数可以相互赋值
    int y20 = 12.327;
    int y21 = -31.3214;
    float y22 = 32;
    float y23 = -43;
    printf("%d,%d,%f,%f\n",y20,y21,y22,y23); // 将一个小数赋值给整数类型，会将小数部分丢掉，只能取整数部分，这会改变数字本来的值，注意是丢掉小数部分，而不是四舍五入  将一个整数赋值给小数类型，在小数点后面添加0就行，加几个无所谓 但是将小数赋值给整数类型时会“失真”，有些编译器会给出警告
    
    // 浮点数结构体
    typedef struct {
        unsigned int nMant: 23; // 尾数部分
        unsigned int nExp: 8; // 指数部分
        unsigned int nSign: 1; // 符号部分
    } FP_SIGNLE;
    char strBin[33] = {0};
    float ff = 19.625;
    FP_SIGNLE *p = (FP_SIGNLE*)&ff;
    itoa(p->nSign, strBin, 2);
    printf("sign: %s\n",strBin);
    itoa(p->nExp,strBin,2);
    printf("exp: %s\n",strBin);
    itoa(p->nMant,strBin,2);
    printf("nMain: %s\n",strBin);
    // 精度问题 对于十进制小数，小数部分转换成二进制使用“乘二取整法”，一个有限位数的小数不一定会转换成有限位数的二进制，只有位数是5的小数才有可能转换为有限位数的二进制，而float和double尾数部分都是有限的，即使能够转换成有限的二进制，也可能会超出尾数部分的长度，这样就必须“四舍五入”，所以就涉及到了精度的问题，因此，浮点数存储的不一定是正真实的小数，很可能是一个近似值
    // 对于char类型，计算机在存储的时候存储的是字符的ASCII码，而所有的字符编码都是一个整数，因此从该角度看， 字符类型和整数类型在本质上没有什么区别,所有的ASCII码实际上存储都是整数
    char q1 = '1';
    char q2 = '$';
    putchar(q1);putchar(q2);putchar('\n');
    printf("%c,%c\n",q1,q2);
    char q3 = 'E';
    char q4 = 76;
    printf("q3: %c,%d\n",q3,q3);
    printf("q4, %c,%d\n",q4,q4);
    
    // 在c语言中，没有专门的字符串类型，只能用数组或者指针来间接地存储字符串
    char str1[] = "这段是用数组的方式来存储字符串的";
    char *str2 = "这段是用指针的方式来存储字符串的";
    printf("%s\n%s\n",str1,str2);
    
    // c语言中，一个字符除了可以用它的实体（也就是真正的字符表示），还可以用编码值表示，这种用编码值来表示自字符的方式称为转义字符,可以使用八进制（\）和十六进制(\x)，也可以同时使用
    // 转义字符的初衷是用于ASCII码，所以取值有限，八进制的转移字符最多后面跟三位数，最大取值是\177,十六进制的最多跟两位，最大取值是\x7f
    // 单引号，双引号和反斜杠是特殊字符
    // 单引号是字符类型的开头和结尾，要使用\'表示，也即'\''
    // 双引号是字符串类型的开头和结尾，要使用\"表示，也即"abc\"12"
    // 反斜杠是转移字符的开头，要使用\\表示，也即'\\',或者"ab\\12"
    puts("C\tC++\tJava\n\"C\"\tfirst\tp\n");
    char a1 = '\62';
    char a2 = '\143';
    char a3 = '\x62';
    printf("%d,%d,%d\n",a1,a2,a3);
    puts("\63\32\41\62");
    puts("\x68\164\164\x70");
    // 标识符： 变量名、函数名、宏名、结构体名等都是标识符
    // c语言虽然不限制标识符的长度，但是它受不同编译器的限制，同时也受到操作系统的限制，例如某些编译器中规定标识符前128位有效，当两个标识符前128位相同时会被认为是同一标识符
    // 标识符中，大小写有区别
    // 关键字也称为保留字，例如int,float,double,unsigned等
    // 注释，单行注释//，多行注释/* */,多行注释不能嵌套使用
    // 表达式必须有一个执行结果，这个结果必须是一个值，例如2+1的结果是3，a=b=c=10的结果是10，printf("hello")的结果是5（printf的返回值是成功打印的字符的个数)
    // 以分号;结束的往往称为语句，而不是表达式，例如2+!; a=b=c;等
    
    // c语言中除法的算法有点奇怪，不同类型的除数和被除数会导致不同的运算结果
    // 当除数和被除数都是整数时，运算结果也是整数，如果不能整除，那么就直接丢掉小数部分，只保留整数部分，这跟小数赋值给整数是一个道理
    // 一旦除数和被除数中有一个是小数，那么运算结果也是小数，并且是double类型的小数
    int a7 = 18;
    int a8 =3;
    float a9 = 3.0;
    double a11 = a7 / a8;
    double a12 = a7 / a9;
    printf("%lf,%lf\n",a11,a12);
    //    int b1,b2;
    //    scanf("%d %d",&b1,&b2);
    //    printf("result:%d\n",b1/b2);
    
    // c语言中的取余运算符%，取余运算只能针对整数，也就是%两边都必须是整数，不能出现小数，否则编译器会报错
    // 余数可以是正数，也可以是负数，由%左边的整数决定，如果%左边是正数，那么余数也是正数，如果%左边是负数，那么余数也是负数
    printf("%d,%d,%d,%d\n",100%12,100%-12,-100%12,-100%-12);
    // 在printf中%是格式控制符的开头，是一种特殊字符，不能直接输出，如果想要输出%。必须在他前面再加一个%,这个时候%就是普通的字符，而不是用来表示格式控制符了
    // 自增++自减--
    // 自增自减的结果必须有变量来接收，所以自增自减只能针对变量，不能针对数字，例如10++就是错误的
    // 前自增自减和后自增自减的区别:前自增自减先自增自减后进行其他操作，后自增自减先进行其他操作后进行自增自减
    int b3 = 10,b4 = 20,b5 = 30,b6 = 40;
    int b33 = ++b3,b44 = b4++,b55 = --b5,b66 = b6--;
    printf("b3=%d,b33=%d\n",b3,b33);
    printf("b4=%d,b44=%d\n",b4,b44);
    printf("b5=%d,b55=%d\n",b5,b55);
    printf("b6=%d,b66=%d\n",b6,b66);
    int b7 = 12, b8 = 1;
    int b9 = b7 - (b8--); // 12 - 1 = 11 ，运算减法后b8就等于0了
    int b10 = (++b7) - (--b8); // 13 - (-1) = 14,先进行自增自减后才进行减法
    printf("b9=%d,b10=%d\n",b9,b10);
    // 在c语言中，变量可以定义在函数外面，也可以定义在函数里面,函数外定义的变量为全局变量，函数内定义的变量为局部变量
    // 在vc和vs编译器中，变量要在函数开头定义，例如在定义a，b之前有语句c=d+f; 这是错误的
    // 一个变量，如果不给它赋值，也会有一个默认的初始值，全局变量的默认初始值是0（它所占有的每一个字节都是0值），局部变量的默认初始值是随机的，是垃圾值，没有规律，因此在使用局部变量之前一定要初始化，否则它的值是没有意义的
    // 结合性：所谓结合性，就是当一个表达式中出现多个优先级相同的运算符时，先执行那个运算符，先执行左边的叫做左结合性，先执行右边的叫做右结合性
    // 自动类型转换，编译器自动进行转换
    // 1. 将一种数据类型赋值给另外一种类型的时候就会发生自动类型转换
    char s = 'A';
    printf("%c\n",s);
    // 在赋值运算中，赋值号两边的数据类型不同时，需要把右边表达式的类型转换为左边变量的类型，这可能会导致数据失真，或者精度降低；因此自动类型的转换并不一定是安全的，对于不安全的转换，浏览器一般会给出警告
    // 2. 在不同类型的混合运算中，编译器也会自动地进行数据类型转换，将参与运算的所有数据转换为同一种类型，然后再进行计算，转换规则如下：
    //  a. 按转换数据的长度增加的方向进行，以保证数值不失真，或者精度不降低，例如int和float参与运算时，先将int转换为float再进行运算
    //  b. 所有浮点数运算都是以双精度进行的，即使运算中只有float类型，也要先转为double类型，才能进行运算
    //  c. char与short运算参与运算时，必须先转换成int类型
    //  (short,char) -> int -> unsigned -> long -> double <- float
    float PI = 3.14159;
    int s1 , r = 5;
    double s2;
    s1 = r * r * PI;
    s2 = r * r * PI;
    printf("s1=%d,s2=%f\n",s1,s2); // 在计算r*r*PI时，r和PI都被转换成double类型，但由于s1是整型，所以赋值运算的结果仍为整型，舍去了小数部分，导致数据失真
    // 强制类型转换
    int s3 = 103;
    int s4 = 13;
    double avg;
    avg = (double) s3 / s4;
    printf("avg = %lf\n",avg); // 由于s3和s4都是int类型，如果不进行强制类型转换，那么s3/s4运算结果也是int，虽然avg是double可以接收小数，但是小数部分已经被提前“阉割”了，只能接收到整数部分，我们可以改变s3或者s4其中一个或者都改为double类型，那么运算结果也将变成double
    // 因此，对于除法运算，如果除数和被除数都是整型，那么运算结果也是整型，小数部分将会被直接丢弃
    // ()优先级高于/，对于表达式(double) s3 / s4，会先执行(double) s3，将s3转换为double类型，再进行除法运算，这样运算结果也是double类型，能够留住小数部分，注意如果写成(double)(s3 / s4),这样写的运算结果是7.000000，仍然不能保留小数部分
    // 无论是自动类型转换还是强制类型转换，都只是为了本次运算而进行的临时转换，转换的结果也会保存到临时的空间，不会改变数据本来的类型或值
    double total = 300.65;
    int count = 5;
    double unit;
    int int_total = (int) total;
    unit = int_total /count;
    printf("total=%lf,int_total=%d,unit=%lf\n",total,int_total,unit); // total变量被转换成了int类型才赋值给int_total,而这种转换并未影响到total变量本身的值和类型
    // 能自动转换的一定能强制转换，需要强制转换的不一定能自动转换
    int m1 = 10, m2 = 76, m3 = 979;
    int n1 = 89, n2 = 9087, n3 = 90865;
    printf("%9d %9d %9d\n",m1,m2,m3);
    printf("%-9d %-9d %-9d\n",n1,n2,n3); // %-9d中，d表示十进制输出，9表示最少占9个字符的宽度，宽度不足以空格补齐，-表示左对齐，不加-表示右对齐
    // printf格式控制符的完整形式为 %[flag][width][.precision]type ,其中[]表示此处的内容可有可无，可以省略
    // 1. type表示输出的类型，比如%d,%f,%c,%lf分别对应d,f,c,lf,type项必须有，这意味着输出时必须知道是什么类型
    // 2. width表示最小输出宽度，也就是至少占用几个字符的位置，例如上例中的9表示至少占用9个字符的宽度
    // 3. precision表示输出精度，也就是小数的位数，当小数部分位数大于precision时，会四舍五入的原则丢掉多余的数字，当小数部分小于precision时，会在后面补0
    // 4.
    //  当输出的宽度不足width时，以空格补齐，当输出结果的宽度超过width时，width不再起作用，按照数据本省的宽度输出
    // 5. flag时标识符。-表示左对齐，没有默认一般按右对齐，+用于整数或者小数，表示输出符号（正负号），若没有则只有在负数时才显示符号，空格 用于整数或者小数，输出为正时冠以空格，为负时冠以负号，#对于八进制（%o）和十六进制（%x / %X）整数，# 表示在输出时添加前缀；八进制的前缀是 0，十六进制的前缀是 0x / 0X。对于小数（%f / %e / %g），# 表示强迫输出小数点。如果没有小数部分，默认是不输出小数点的，加上 # 以后，即使没有小数部分也会带上小数点。
    //另外，.precision 也可以用于整数和字符串，但是功能却是相反的：
    //    用于整数时，.precision 表示最小输出宽度。与 width 不同的是，整数的宽度不足时会在左边补 0，而不是补空格。
    //    用于字符串时，.precision 表示最大输出宽度，或者说截取字符串。当字符串的长度大于 precision 时，会截掉多余的字符；当字符串的长度小于 precision 时，.precision 就不再起作用
    int m4 = 234;
    float m5 = 9.8;
    char m6 = '@';
    char *m7 = "https://www.baidu.com";
    printf("%10d%12f%4c%8s\n",m4,m5,m6,m7);
    
//    printf("test\n");
//    sleep(5);
//    printf("等5秒\n");
    // 读取从键盘上输入的数据
    // scanf()：和 printf() 类似，scanf() 可以输入多种类型的数据  getchar()、getche()、getch()：这三个函数都用于输入单个字符  gets()：获取一行数据，并作为字符串处理
    
    // 对于scanf()输入数据的格式要和控制字符串的格式保持一致
    // scanf和printf非常相似，都有格式控制字符串，不同的是scanf的变量前要加一个&,&称为取地址符，也就是获取变量在内存中的地址
    // 对于整数、浮点数、字符，都要使用 & 获取它们的地址，scanf 会根据地址把读取到的数据写入内存
//    int m8 = 0, m9 = 0, m10 = 0 , m11 = 0;
//    scanf("%d",&m8);
//    scanf("%d",&m9);
//    printf("m8 + m9 = %d",m8+m9);
//    scanf("%d %d",&m10,&m11);
//    printf("m10 * m11 = %d\n",m10 * m11);
    
    int c1 = 12;
    char c2 = 'U';
    printf("&c1 = %p , &c2 = %p\n",&c1,&c2); // %p表示以十六进制的形式输出数据的地址，如果写成%P,那么十六进制的前缀会大写 注意这里的地址是虚拟地址，并不是真正的物理地址
    
//    int c3,c4,c5;
//    scanf("%d %d",&c3,&c4);
//    printf("c3+c4=%d\n",c3+c4);
//    scanf("%d      %d",&c3,&c4);
//    printf("c3+c4=%d\n",c3+c4);
//    scanf("%d,%d,%d",&c3,&c4,&c5);
//    printf("c3+c4+c5=%d\n",c3+c4+c5);
//    scanf("%d is bigger than %d",&c3,&c4);
//    printf("c3 - c4 = %d\n",c3 - c4);
    // 从本质上讲，我们从键盘输入的数据并没有直接交给 scanf()，而是放入了缓冲区中，直到我们按下回车键，scanf() 才到缓冲区中读取数据
    // 对于char a[] = 'dafad'和char *a = 'adfad'这两种定义字符串的形式是有区别的，第一种形式的字符串即有读取权限也有写入权限，第二种只有读取权限，没有写入权限
    // printf()、puts() 等字符串输出函数只要求字符串有读取权限，而 scanf()、gets() 等字符串输入函数要求字符串有写入权限
    // 第一种形式的字符串既可以用于输出函数又可以用于输入函数，而第二种形式的字符串只能用于输出函数。
    // scanf() 遇到空格就认为字符串结束了，不再继续读取了。
    // 输入单个字符，我们可以使用scanf("%c").也可以使用getchar(),getche(),getch()这三个字符输入函数，他们具有scanf没有的特性，是scanf()不能替代的
    // 1. 最容易理解的字符输入函数是 getchar()，它就是scanf("%c", c)的替代品，除了更加简洁，没有其它优势了；或者说，getchar() 就是 scanf() 的一个简化版本。
//    char c6 = getchar();
//    printf("%c\n",c6);
    // getche() 就比较有意思了，它没有缓冲区，输入一个字符后会立即读取，不用等待用户按下回车键，这是它和 scanf()、getchar() 的最大区别,getche位于 conio.h 头文件中，而这个头文件是 Windows 特有的
//    char c7 = getche();
//    printf("%c\n",c7);
    // getch() 也没有缓冲区，输入一个字符后会立即读取，不用按下回车键，这一点和 getche() 相同。getch() 的特别之处是它没有回显，看不到输入的字符。所谓回显，就是在控制台上显示出用户输入的字符；没有回显，就不会显示用户输入的字符，就好像根本没有输入一样。
    // 通常用在输入密码时，我们不希望回显
    // getch() 也位于 conio.h 头文件中，也不是标准函数，默认只能在 Windows 下使用
    
    //gets() 这个专用的字符串输入函数，它拥有一个 scanf() 不具备的特性
//    char c8[30];
//    gets(c8);
//    printf("c8: %s\n",c8); // gets() 是有缓冲区的，每次按下回车键，就代表当前输入结束了，gets() 开始从缓冲区中读取内容，这一点和 scanf() 是一样的
    //gets() 和 scanf() 的主要区别:
    // scanf() 读取字符串时以空格为分隔，遇到空格就认为当前字符串结束了，所以无法读取含有空格的字符串
    // gets() 认为空格也是字符串的一部分，只有遇到回车键时才认为字符串输入结束，所以，不管输入了多少个空格，只要不按下回车键，对 gets() 来说就是一个完整的字符串
    // gets() 能读取含有空格的字符串，而 scanf() 不能
    // 缓冲区是为了让低速的输入输出设备和高速的用户程序能够协调工作，并降低输入输出设备的读写次数
    // 根据缓冲区对应的是输入设备还是输出设备，可以分为输入缓冲区和输出缓冲区
    // 根据数据刷新（也可以称为清空缓冲区，就是将缓冲区的数据“倒出”）的时机，可以划分为全缓冲，行缓冲，不带缓冲
    // 1. 全缓冲：当缓冲区被填满以后再进行真正的输入输出操作，缓冲区的大小都是有限制的，比如1kb,1mb等，数据量达到最大值时就清空缓冲区 在实际开发中，将数据写入文件后，打开文件并不能立即看到内容，只有清空缓冲区，或者关闭文件，或者关闭程序后，才能在文件中看到内容，这就是缓冲区在作怪
    // 2. 行缓冲： 当在输入或输出的过程中遇到换行符时，才执行真正的输入输出操作，行缓冲的经典代表就是标准输入设备（键盘）和标准输出设备（显示器）
    // 3. 不带缓冲： 数据没有地方缓存，必须立即进行输入输出getche和getch就不带缓冲，输入一个字符后就立即执行了，不用按回车键
    // c语言标准规定，输入输出缓冲区要具有以下特征： 1.当且仅当输入输出不涉及交互设备时，他们才是全缓冲的 2. 错误显示设备不能带有缓冲区
    
    // 1) 输入设备
     /* scanf()、getchar()、gets() 就是从输入设备（键盘）上读取内容。对于输入设备，没有缓冲区将导致非常奇怪的行为，比如，我们本来想输入一个整数 947，没有缓冲区的话，输入 9 就立即读取了，根本没有机会输入 47，所以，没有输入缓冲区是不能接受的。Windows、Linux、Mac OS 在实现时都给输入设备带上了行缓冲，所以 scanf()、getchar()、gets() 在每个平台下的表现都一致。
      但是在某些特殊情况下，我们又希望程序能够立即响应用户按键，例如在游戏中，用户按下方向键人物要立即转向，而且越快越好，这肯定就不能带有缓冲区了。Windows 下特有的 getche() 和 getch() 就是为这种特殊需求而设计的，它们都不带缓冲区。
      */
    // Windows 平台下，输出设备是不带缓冲区的；Linux 和 Mac OS 平台下，输出设备带有行缓冲区
    // 刷新缓冲区，就是将缓冲区中的内容送达到目的地，缓冲区的刷新遵循以下的规则：
    /* 1. 不管是行缓冲还是全缓冲，缓冲区满时会自动刷新；
    2. 行缓冲遇到换行符\n时会刷新；
    3. 关闭文件时会刷新缓冲区；
    4. 程序关闭时一般也会刷新缓冲区，这个是由标准库来保障的；
    5. 使用特定的函数也可以手动刷新缓冲区
     */
    
    /*scanf() 是带有缓冲区的。遇到 scanf() 函数，程序会先检查输入缓冲区中是否有数据
    1如果没有，就等待用户输入。用户从键盘输入的每个字符都会暂时保存到缓冲区，直到按下回车键，输入结束，scanf() 再从缓冲区中读取数据，赋值给变量。
    2如果有数据，哪怕是一个字符，scanf() 也会直接读取，不会等待用户输入*/
    
//    int p1,p2,p3;
//    scanf("%d",&p1);
//    scanf("%d",&p2);
//    scanf("%d",&p3);
//    printf("p1 = %d, p2 = %d , p3 = %d\n",p1,p2,p3);
    // 注意：scanf() 匹配到想要的数据后，会将匹配到的数据从缓冲区中删除，而没有匹配到的数据仍然会留在缓冲区中。
    
    // 阻塞式键盘监听，阻塞式键盘监听用于用户输入时一般没有任何问题，用户输入完数据再执行后面的代码往往也符合逻辑。然而在很多小游戏中，阻塞式键盘监听会带来很大的麻烦，用户要不停按键游戏才能进行，这简直就是灾难，所以在小游戏中一般采用非阻塞式键盘监听：用户输入数据后程序可以捕获，用户不输入数据程序也可以继续执行。Windows 系统中，conio.h头文件中的kbhit()函数就可以用来实现非阻塞式键盘监听
    // c语言中三大结构：顺序结构，选择结构，循环结构
//    int age1;
//    printf("please enter your age\n");
//    scanf("%d\n",&age1);
//    if (age1 > 18) {
//        printf("adult\n");
//    } else {
//        printf("teenager\n");
//    }
//    system("pause");
    
//    int a0,b0,max;
//    printf("two num:");
//    scanf("%d %d",&a0,&b0);
//    if (a0>b0) max = a0;
//    else max = b0;
//    printf("较大的值是：%d\n",max);
    
    // 像1+2这样的有两个操作数，+是操作符，我们称这样的运算符为双目运算符（+-*/），有一个操作的称为单目远算符（++，--），三目运算符（只有？）
    // 关系运算符的结果只有0或1，当条件成立时结果为1，不成立结果为0
    char c20 = 'k';
    int i1 = 1, j1 = 2, k1= 3;
    float x10 = 3e5,ya2=0.85;
    int result_1 = 'a' + 5 < c20 ,result_2 = x10 - 5.25 <= x10 + ya2;
    printf("%d %d\n",result_1,-i1-2*j1 >= k1+1);
    printf("%d %d\n",1<j1,result_2);
    printf("%d %d\n",i1 + j1 + k1 == -2 * j1,k1 == j1 == i1 +5);
    // 对于含多个关系运算符的表达式，如 k==j==i+5，根据运算符的左结合性，先计算k==j，该式不成立，其值为0，再计算0==i+5，也不成立，故表达式值为0
    // 逻辑运算符
    // 逻辑运算符中&&和｜|为左结合性，！为右结合性
    // 一般称非零值为真，零值为假
    // 逻辑运算符与其他运算符的优先级 赋值运算符（=）< &&和｜｜ < 关系运算符 < 算数运算符 < 非(!)
//    int age1;
//    float score1;
//    printf("please enter your age and socre:");
//    scanf("%d %f",&age1,&score1);
//    if (age1 >= 18 && score1 >= 60) {
//        printf("welcome!\n");
//    } else {
//        printf("sorry!");
//    }
    
    // break 是C语言中的一个关键字，专门用于跳出 switch 语句。所谓“跳出”，是指一旦遇到 break，就不再执行 switch 中的任何语句，包括当前分支中的语句和其他分支中的语句；也就是说，整个 switch 执行结束了，接着会执行整个 switch 后面的代码
//    int number1;
//    printf("please enter a number");
//    scanf("%d",&number1);
//    switch (number1) {
//        case 1:
//            printf("monday");
//            break;
//        case 2:
//            printf("tuesday");
//            break;
//        case 3:
//            printf("wednesday");
//            break;
//        case 4:
//            printf("thursday");
//            break;
//        case 5:
//            printf("friday");
//            break;
//        case 6:
//            printf("saturday");
//            break;
//        case 7:
//            printf("sunday");
//            break;
//        default:
//            printf("error");
//            break;
//    }
    
    //case 后面必须是一个整数，或者是结果为整数的表达式，但不能包含任何变量,其中字符和整数可以相互转换（例如'A'可以转换）
    //default 不是必须的。当没有 default 时，如果所有 case 都匹配失败，那么就什么都不执行
    // 条件运算符(?)是c语言中唯一的三目远算符
    // 条件表达式应注意1.条件运算符的优先级低于关系运算符和算术运算符，但高于赋值符 2.条件运算符?和：是一对运算符，不能分开单独使用 3.条件运算符的结合方向是自右至左例： a>b ? a : c>d ? c : d; 应该理解为 a>b ? a : ( c>d ? c : d );
//    int nu1 ,nu2;
//    printf("please enter two integer number:");
//    scanf("%d %d",&nu1,&nu2);
//    printf("max = %d\n",nu1>nu2?nu1:nu2);
    int base = 1 , sums = 0;
    while (base <= 100) {
        sums += base;
        base++;
    }
    printf("sums = %d\n",sums);
    // while 循环的整体思路是这样的：设置一个带有变量的循环条件，也即一个带有变量的表达式；在循环体中额外添加一条语句，让它能够改变循环条件中变量的值。这样，随着循环的不断执行，循环条件中变量的值也会不断变化，终有一个时刻，循环条件不再成立，整个循环就结束了
    // 获取输入的字符串长度，回车结束
//    int mp = 0;
//    printf("please enter:");
//    while (getchar() != '\n') {
//        mp++;
//    }
//    printf("number of characters: %d\n",mp);
    // do-while循环与while循环的不同在于：它会先执行“语句块”，然后再判断表达式是否为真，如果为真则继续循环；如果为假，则终止循环。因此，do-while 循环至少要执行一次“语句块”
    // for循环
    int sum2 = 0 ;
    for (int as = 0; as <= 100 ; as++) {
        sum2 += as;
    }
    printf("sum2=%d\n",sum2);
    // 当 break 关键字用于 while、for 循环时，会终止循环而执行整个循环语句后面的代码。break 关键字通常和 if 语句一起使用，即满足条件时便跳出循环。
    int sum3 = 0 , ii = 1;
    while(1) {
        sum3 += ii;
        ii++;
        if (ii > 100) {
            break;
        }
    }
    printf("sum3 = %d\n",sum3);
    // 在多层循环中，一个 break 语句只向外跳一层
    int i0 = 1, j0;
    while (1) {
        j0 = 1;
        while (1) {
            printf("%-4d",i0 * j0);
            j0++;
            if (j0>4) {
                break; // 结束内层循环
            }
        }
        printf("\n");
        i0++;
        if (i0 > 4) {
            break; // 外层循环
        }
    }
    // continue 语句的作用是跳过循环体中剩余的语句而强制进入下一次循环。continue语句只用在 while、for 循环中，常与 if 条件语句一起使用，判断条件是否成立
//    char ca = 0;
//    while (ca != '\n') {
//        ca = getchar();
//        if (ca == '4' || ca == '5') {
//            continue;
//        }
//        putchar(ca);
//    }
    // break与continue的对比：break 用来结束所有循环，循环语句不再有执行的机会；continue 用来结束本次循环，直接跳到下一次循环，如果循环条件成立，还会继续循环。
    // 循环嵌套
    int y, v;
    for (y = 1; y <= 4; y++) {
        for (v = 1; v <= 4; v++) {
            printf("%-4d",v * y);
        }
        printf("\n");
    }
    // 内层 for 每循环一次输出一个数据，而外层 for 每循环一次输出一行数据
    int y0 ,v0;
    for (y0=1; y0 <= 9; y0++) {
        for (v0 = 1; v0 < y0; v0++) {
            printf("%d * %d = %-2d ",v0,y0,y0*v0);
        }
        printf("\n");
    }
    // 除了 while 和 for，C语言中还有一个 goto 语句，它也能构成循环结构。不过由于 goto 语句很容易造成代码混乱，维护和阅读困难，饱受诟病，不被推荐，而且 goto 循环完全可以被其他循环取代，所以后来的很多编程语言都取消了 goto 语句
    
    // 数组
    // 按数组元素的类型不同，数组又可分为数值数组、字符数组、指针数组、结构数组等各种类别
    // int a[4]; 这样，就在内存中分配了4个int类型的内存空间，共 4×4=16 个字节，并为它们起了一个名字，叫a
    // 把这样的一组数据的集合称为数组（Array），它所包含的每一个数据叫做数组元素（Element），所包含的数据的个数称为数组长度（Length），例如int a[4];就定义了一个长度为4的整型数组，名字是a
    int arr[10];
    int tp;
    for (tp = 0; tp < 10 ; tp++) {
        arr[tp] = (tp+1);
    }
    for(tp=0;tp<10;tp++) {
        printf("%d ",arr[tp]);
    }
    
//    int arr2[10];
//    int tp2;
//    for (tp2 = 0; tp2 < 10; tp2++) {
//        scanf("%d",&arr2[tp2]);
//    }
//    for (tp2 = 0; tp2 < 10 ; tp2++) {
//        printf("%d ",arr2[tp2]);
//    }
    // 数组的定义方式：dataType  arrayName[length]; dataType 为数据类型，arrayName 为数组名称，length 为数组长度
    // float m[12];  //定义一个长度为 12 的浮点型数组
    // 注意： 1. 数组中每个元素的数据类型必须相同，对于int a[4];，每个元素都必须为 int。 2. 数组长度 length 最好是整数或者常量表达式，例如 10、20*4 等，这样在所有编译器下都能运行通过；如果 length 中包含了变量，例如 n、4*m 等，在某些编译器下就会报错 3. 访问数组元素时，下标的取值范围为 0 ≤ index < length，过大或过小都会越界，导致数组溢出
    // 数组是一个整体，它的内存是连续的；也就是说，数组元素之间是相互挨着的，彼此之间没有一点点缝隙
    // 连续的内存为指针操作（通过指针来访问数组元素）和内存处理（整块内存的复制、写入等）提供了便利，这使得数组可以作为缓存（临时存储数据的一块内存）使用
//    int arr3[4] = {12,34,54,24};
    // 对于数组的初始化
    // 1. 可以只给部分元素赋值。当{ }中值的个数少于元素个数时，只给前面部分元素赋值 例如 int arr4[10] = {12,23,21,43}; 表示只给 a[0]~a[3] 4个元素赋值，而后面 4 个元素自动初始化为 0, 对于short、int、long，就是整数 0 , 对于char，就是字符 '\0' ,对于float、double，就是小数 0.0
    // 2. 只能给元素逐个赋值，不能给数组整体赋值。例如给 10 个元素全部赋值为 1,只能写作int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};不能写成int a[10] = 1;
    // 将所有元素初始化为0
//    int num5[10] = {0}; char str[10] = {0};float scores[10] = {0.0};
    // 3. 如给全部元素赋值，那么在定义数组时可以不给出数组长度。例如int a[] = {1, 2, 3, 4, 5};
    // 二维数组 定义 dataType arrayName[length1][length2]; dataType 为数据类型，arrayName 为数组名，length1 为第一维下标的长度，length2 为第二维下标的长度
    // 二维数组在概念上是二维的，但在内存中是连续存放的；换句话说，二维数组的各个元素是相互挨着的，彼此之间没有缝隙，在线性内存中存二维数组的两种方式：
    // 1. 一种是按行排列，即放完一行之后再放第二行 2. 另一种是按咧排列，存放完一列之后再放第二列、
    // 在c语言中，数组是按行排列的
//    int l,k;// 二维数组下标
//    int sum = 0; // 当前科目的总成绩
//    int average; // 总平均分
//    int arr6[3]; // 各科平均分
//    int arr7[5][3]; //用来保存各个同学各科成绩的二维数组
//    printf("input score: \n");
//    for (l=0; l<3; l++) {
//        for (k=0; k<5; k++) {
//            scanf("%d",&arr7[k][l]);
//            sum+=arr7[k][l];
//        }
//        arr6[l] = sum / 5;
//        sum = 0;
//    }
//    average = (arr6[0] + arr6[1] + arr6[2]) / 3;
//    printf("Math average: %d,C averafe: %d, Java average: %d\n",arr6[0],arr6[1],arr6[2]);
//    printf("Total average: %d\n",average);
//    二维数组的初始化可以按行分段赋值，也可按行连续赋值
//    int arr8[3][2] = {{1,2},{1,3},{4,6}};
//    int arr9[2][2] = {1,2,2,4};
    // 数组的初始化 1. 可以只对部分元素赋值，未赋值的元素自动取“零”值
    // 如果对全部元素赋值，那么第一维的长度可以不给出，例如
//    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};可以写成int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //二维数组可以看作是由一维数组嵌套而成的；如果一个数组的每个元素又是一个数组，那么它就是二维数组。当然，前提是各个元素的类型必须相同。根据这样的分析，一个二维数组也可以分解为多个一维数组，C语言允许这种分解。
    // 二维数组a[3][4]可分解为三个一维数组，它们的数组名分别为 a[0]、a[1]、a[2]。这三个一维数组可以直接拿来使用。这三个一维数组都有 4 个元素，比如，一维数组 a[0] 的元素为 a[0][0]、a[0][1]、a[0][2]、a[0][3]。
    // c语言中判断数组中是否含有某个元素
    // 对无序数组的查询，遍历数组中的每个元素
//    int arr8[6] = {3,7,2,456,43,65,};
//    int ind,numd,thisindex = -1;
//    printf("please enter integer number:");
//    scanf("%d",&numd);
//    for (ind = 0; ind < 10; ind++) {
//        if (arr8[ind] == numd) {
//            thisindex = ind;
//            break;
//        }
//    }
//    if (thisindex < 0) {
//        printf("%d is not in the array\n",numd);
//    } else {
//        printf("%d is in the array,its index is %d\n",numd,thisindex);
//    }
    // 对有序数组的查询
//    int arr9[6] = {2,4,6,9,12,23};
//    int ind2,numd2,thisindex2 = -1;
//    printf("please enter integer number:");
//    scanf("%d",&numd2);
//    for (ind2=0; ind2 < 10; ind2++) {
//        if (arr9[ind2] == numd2) {
//            thisindex2 = ind2;
//            break;
//        } else if(arr9[ind2] > numd2) {
//            break; // 当 nums[i] > num 时，i 后边的元素也都大于 num 了，num 肯定不在数组中了，就没有必要再继续比较了，终止循环
//        }
//    }
//    if (thisindex2 < 0) {
//        printf("%d is not in array\n",numd2);
//    } else {
//        printf("%d is in the array,it index is %d\n",numd2,thisindex2);
//    }
    // 用来存放字符的数组称为字符数组
    // char c[20]={'c', '  ', 'p', 'r', 'o', 'g', 'r', 'a','m'};  // 给部分数组元素赋值
    // char d[]={'c', ' ', 'p', 'r', 'o', 'g', 'r', 'a', 'm' };  //对全体元素赋值时可以省去长度
    // 在C语言中，没有专门的字符串变量，没有string类型，通常就用一个字符数组来存放一个字符串,是一系列字符的集合
    // c语言中可以直接将字符串赋值给字符数组
//    char str3[30] = {"www.baidu.com"};
//    char str4[30] = "www.baidu.com"; // 也可以不指定长度
    // 符数组只有在定义时才能将整个字符串一次性地赋值给它，一旦定义完了，就只能一个字符一个字符地赋值了
    // char str[7];
    // str = "abc123";  //错误
    // 正确
//    str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
//    str[3] = '1'; str[4] = '2'; str[5] = '3';
    // 字符串结束标志
    // 字符串是一系列连续的字符的组合，要想在内存中定位一个字符串，除了要知道它的开头，还要知道它的结尾，只要知道它名字就能找到开头
    // 在C语言中，字符串总是以'\0'作为结尾，所以'\0'也被称为字符串结束标志，或者字符串结束符
    // C语言在处理字符串时，会从前往后逐个扫描字符，一旦遇到'\0'就认为到达了字符串的末尾，就结束处理。'\0'至关重要，没有'\0'就意味着永远也到达不了字符串的结尾
    // 由" "包围的字符串会自动在末尾添加'\0'，例如，"abc123"从表面看起来只包含了 6 个字符，其实不然，C语言会在最后隐式地添加一个'\0'
    // 注意： 逐个字符地给数组赋值并不会自动添加'\0' ，例如 char str[] = {'a', 'b', 'c'};数组 str 的长度为 3，而不是 4，因为最后没有'\0'
    // "abc123"看起来只包含了 6 个字符，我们却将 str 的长度定义为 7，就是为了能够容纳最后的'\0'。如果将 str 的长度定义为 6，它就无法容纳'\0'了。
    // 在函数内部定义的变量、数组、结构体、共用体等都称为局部数据。在很多编译器下，局部数据的初始值都是随机的、无意义的，而不是我们通常认为的“零”值，所以如果是对元素一个一个的进行赋值，一定要记住在后面手动添加'\0'
    char strs[30];
    char c9;
    int ind3;
    for (c9 = 65,ind3 = 0; c9 <= 90; c9++,ind3++) {
        strs[ind3] = c9;
    }
    strs[ind3] = 0;
    printf("%s\n",strs);
    // 专业写法：将所有元素都初始化为0，或者说'\0'
    // 如果只初始化部分数组元素，那么剩余的数组元素也会自动初始化为“零”值，所以我们只需要将 str 的第 0 个元素赋值为 0，剩下的元素就都是 0 了
    char strs2[30] = {0};
    char c10;
    int ind4;
    for (c10 = 65, ind4 = 0; c10 <= 90; c10++,ind4++) {
        strs2[ind4] = c10;
    }
    printf("%s\n",strs2);
    // 字符串长度就是字符串包含了多少个字符（不包括最后的结束符'\0'）。例如"abc"的长度是 3，而不是 4
    // C语言中，使用string.h头文件中的 strlen() 函数来求字符串的长度
    char strs3[] = "www.hdisahfidsha.com";
    long len = strlen(strs3);
    printf("the length of strs3 is %ld\n",len);
    // 在C语言中，有两个函数可以在控制台（显示器）上输出字符串，它们分别是:
    // 1. puts()：输出字符串并自动换行，该函数只能输出字符串
    // 2. printf()：通过格式控制符%s输出字符串，不能自动换行。除了字符串，printf() 还能输出其他类型的数据。
    // 在C语言中，有两个函数可以让用户从键盘上输入字符串，它们分别是：
    // 1. scanf()：通过格式控制符%s输入字符串。除了字符串，scanf() 还能输入其他类型的数据, 遇到空格就认为当前字符串结束了,无法读取含有空格的字符串
    // 2. gets()：直接输入字符串，并且只能输入字符串,认为空格也是字符串的一部分，只有遇到回车键时才认为字符串输入结束
    // 注意： scanf() 在读取数据时需要的是数据的地址，这一点是恒定不变的，对于 int、char、float 等类型的变量都要在前边添加&以获取它们的地址，字符串名字或者数组名字在使用的过程中一般都会转换为地址，所以再添加&就是多此一举，甚至会导致错误了
    // int、char、float 等类型的变量用于 scanf() 时都要在前面添加&，而数组或者字符串用于 scanf() 时不用添加&
    // 以下功能都是 gets() 不具备的：
    // 1. scanf()可以控制读取字符串的数目
    // 2. scanf()可以只读取指定的字符
    // 3. scanf()可以不读区某些字符
    // 4. scanf()可以把读取到的字符丢弃
    // scanf("%[^\n]%*c", str);表示读到字符‘\n’停止读取，并且读入一个字符但是不赋值给变量
    // scanf()函数是通用终端格式化输入函数 调用格式为: scanf("<格式化字符串>"，<地址表>);scanf()函数返回成功赋值的数据项数，出错时则返回EOF
    // 1. 格式化说明符：%n 至此已读入值的等价字符数 %[] 扫描字符集合 %% 读%符号
    // 1. * 亦可用于格式中, (即 %*d 和 %*s) 加了星号 (*) 表示跳过此数据不读入. (也就是不把此数据读入参数中)
    // 2. {a|b|c}表示a,b,c中选一，[d],表示可以有d也可以没有d。
    // 3. width表示读取宽度
    // 4. 参数的size: 常用的有hh表示单字节size，h表示2字节 size
    // 5.空白字符会使scanf()函数在读操作中略去输入中的一个或多个空白字符，空白符可以是space,tab,newline等，直到第一个非空白符出现为止
    
    // c语言字符串处理函数
    // C语言提供了丰富的字符串处理函数，可以对字符串进行输入、输出、合并、修改、比较、转换、复制、搜索等操作，使用这些现成的函数可以大大减轻我们的编程负担
    // 1. 字符串连接函数 strcat()，意思是把两个字符串拼接在一起，语法格式 strcat(arrayName1, arrayName2);strcat() 将把 arrayName2 连接到 arrayName1 后面，并删除原来 arrayName1 最后的结束标志'\0'。意味着arrayName1 必须足够长，要能够同时容纳 arrayName1 和 arrayName2，否则会越界（超出范围）。strcat() 的返回值为 arrayName1 的地址。
//    char strn[80] = "The ULL is";
//    char strn2[30];
//    printf("input a url:");
//    gets(strn2);
//    strcat(strn, strn2);
//    puts(strn);
    // 字符串复制函数 strcpy(),即将字符串从一个地方复制到另外一个地方，语法格式为：strcpy(arrayName1, arrayName2);strcpy() 会把 arrayName2 中的字符串拷贝到 arrayName1 中，字符串结束标志'\0'也一同拷贝,strcpy() 要求 arrayName1 要有足够的长度，否则不能全部装入所拷贝的字符串
    char strn3[50] = "<<c语言牛逼>>";
    char strn4[50] = "java牛逼";
    strcpy(strn3,strn4);
    printf("strn3 = %s\n",strn3);
    // 字符串比较函数 strcmp(),语法格式为：strcmp(arrayName1, arrayName2);arrayName1 和 arrayName2 是需要比较的两个字符串.字符本身没有大小之分，strcmp() 以各个字符对应的 ASCII 码值进行比较.strcmp() 从两个字符串的第 0 个字符开始比较，如果它们相等，就继续比较下一个字符，直到遇见不同的字符，或者到字符串的末尾。
    // 若 arrayName1 和 arrayName2 相同，则返回0；若 arrayName1 大于 arrayName2，则返回大于 0 的值；若 arrayName1 小于 arrayName2，则返回小于0 的值
    char strn5[] = "abCdef";
    char strn6[] = "abCdef";
    char strn7[] = "abcd";
    char strn8[] = "ABCDEF";
    printf("相等的: %d\n",strcmp(strn5, strn6));
    printf("大于的: %d\n",strcmp(strn5, strn8)); // 小写字母的ascII码大于大写字母的acsII码
    printf("小于的: %d\n",strcmp(strn5, strn7));
    // c语言中不允许动态数组类型。例如： int n;scanf("%d",&n);int a[n]; 用变量表示长度，想对数组的大小作动态说明， 这是错误的
//    但是在实际的编程中，往往会发生这种情况， 即所需的内存空间取决于实际输入的数据，而无法预先确定。对于这种问题，用数组的办法很难解决。为了解决上述问题，C语言提供了一些内存管理函数，这些内存管理函数可以按需要动态地分配内存空间，也可把不再使用的空间回收待用，为有效地利用内存资源提供了手段。其它文献中所提到的"动态数组",指的就是利用内存的申请和释放函数,在程序的运行过程中，根据实际需要指定数组的大小.其本质是一个指向数组的指针变量.常用的内存管理函数有以下三个：
//    1. 分配内存空间函数malloc 调用形式： (类型说明符*) malloc (size) 功能：在内存的动态存储区中分配一块长度为"size" 字节的连续区域。函数的返回值为该区域的首地址 “类型说明符”表示把该区域用于何种数据类型。(类型说明符*)表示把返回值强制转换为该类型指针。“size”是一个无符号数。例如： pc=(char *) malloc (100); 表示分配100个字节的内存空间，并强制转换为字符数组类型， 函数的返回值为指向该字符数组的指针， 把该指针赋予指针变量pc,分配成功则返回指针地址，分配失败则返回NULL
//    2.分配内存空间函数 calloc 调用形式： (类型说明符*)calloc(n,size)
    // 在创建动态数组的过程中我们要遵循一个原则，那就是在创建的时候从外层往里层，逐层创建；而释放的时候从里层往外层，逐层释放
    // 动态创建一维数组
//    int k2,z;
//    int *array;
//    printf("please enter single array:");
//    scanf("%d",&k2);
//    array = (int *)calloc(k2, sizeof(int));
//    for (z = 0; z < k2 ; z++) {
//        printf("%d\t",array[z]);
//    }
//    printf("\n");
//    for (z = 0; z < k2 ; z++) {
//        array[z] = z+1;
//        printf("%d\t",array[z]);
//    }
//    printf("\n");
//    free(array);
    // 动态创建二维数组
//    int k3,z1;
//    printf("请输入动态二维数组的第一个维度：");
//    scanf("%d",&k3);
//    printf("请输入动态二维数组的第二个维度：");
//    scanf("%d",&z1);
//    int **array1 = (int **)calloc(k3, sizeof(int));
//    for (int inde = 0; inde < k3; inde++) {
//        array1[inde] = (int*)calloc(z1, sizeof(int));
//    }
//    for (int inde = 0; inde < k3; inde++) {
//        for (int inde2 = 0; inde2 < z1; inde2++) {
//            array1[inde][inde2] = inde*z1+inde2+1;
//            printf("%d\t",array1[inde][inde2]);
//        }
//        printf("\n");
//    }
//    for (int z2 = 0; z2 < k3 ; z2++) {
//        free(array1[z2]);
//    }
//    free(array1);
    // 对数组元素进行排序
    // 对数组元素进行排序的方法有很多种，比如冒泡排序、归并排序、选择排序、插入排序、快速排序，shell排序、分组排序、基数排序、桶（箱）排序、堆排序、计数排序等
    // 冒泡排序
    int arrq[10] = {3,2,5,2,43,6,9,54,57,32};
    int ai,aj,at;
    for (ai = 0; ai < 10 - 1; ai++) {
        for (aj = 0; aj < 10 - ai - 1; aj++) {
            if (arrq[aj] > arrq[aj + 1]) {
                at = arrq[aj];
                arrq[aj] = arrq[aj + 1];
                arrq[aj + 1] = at;
            }
        }
    }
    for (ai = 0; ai < 10; ai++) {
        printf("%d ",arrq[ai]);
    }
    printf("\n");
    // 优化算法
    int arrq1[10] ={43,432,54,64,88,6,65,93,23,90};
    int ai1,aj1,at1,isSorted;
    for (ai1 = 0; ai1 < 10 -1; ai1++) {
        isSorted = 1;
        for (aj1 = 0; aj1<10-1-ai1; aj1++) {
            if (arrq1[aj1] > arrq1[aj1 + 1]) {
                at1 = arrq1[aj1];
                arrq1[aj1] = arrq1[aj1+1];
                arrq1[aj1+1] = at1;
                isSorted = 0;
            }
        }
        if(isSorted) break;
    }
    for (ai1=0; ai1 < 10 ; ai1++) {
        printf("%d ",arrq1[ai1]);
    }
    printf("\n");
    
    printf("************\n");
    // 冒泡排序,时间复杂度O(n^2)  -> O(n^2/2 ~ n^2)
    int test_ar[10] = {10,43,3,23,21,2,43,32,432,43};
    printf("dubble_sort:\n");
    dubble_sort(test_ar,10);
    // 选择排序,时间复杂度O(n^2/2 + (n-1))
    int test_ar2[10] = {10,43,3,23,21,2,43,32,432,43};
    printf("select_sort: \n");
    select_sort(test_ar2 , 10);
    // 插入排序，时间复杂度O(n^2 ~ 2n)
    int test_ar3[10] = {10,43,3,23,21,2,43,32,432,43};
    printf("insert_sort:\n");
    insert_sort(test_ar3, 10);
    // shell排序
    int test_ar4[10] = {10,43,3,23,21,2,43,32,432,43};
    printf("shell_sort: \n");
    shell_sort(test_ar4, 10);
    
    // 搜索
    int test_ar5[10] = {10,43,3,23,21,2,43,32,432,43};
    int lengths = sizeof(test_ar5) / sizeof(int);
    order_search(test_ar5, lengths, 2);
    order_search(test_ar5, lengths, 100);
    // 折半查找的前提是已经拍好序了，一般不在链表中使用折半查找，反而可能会降低效率
    int lengths2 = sizeof(test_ar4) / sizeof(int);
    binary_search(test_ar4,lengths2,43);
    
    // 函数
    char strw1[] = "http://c.biancheng.net/view/1850.html";
    char strw2[] = "https://segmentfault.com/a/1190000019818564";
    int resultw = strcmp(strw1, strw2);
    printf("%d \n",resultw);
    // 函数不能嵌套定义，main也是一个函数定义，因此要将自己定义的函数放在main外面，必须先定义后使用
    // 注意：main 是函数定义，不是函数调用。当可执行文件加载到内存后，系统从 main 函数开始执行，也就是说，系统会调用我们定义的 main 函数
    char str33[] = "dfsasf";
    char str44[] = "llllllll";
    int result_9 = strcmp_alias(str33,str44);
    printf("str33 - str44 = %d \n",result_9);
    // 判断是否为素数
//    int nn;
//    scanf("please enter a number %d",&nn);
//    prime(nn);
    printf("1-10的阶乘和为： %ld\n",factorial_sum(10));
    int vv , length3 , widths, heights;
    printf("enter length , with, height: ");
//    scanf("%d %d %d",&length3, &widths, &heights);
    vv = areaV(length3,widths,heights);
    printf("v= %d,area1 = %d, area2 = %d, area3 = %d\n",vv,area1,area2,area3);
    printf("the greatest common divisor is %d\n",gcd(100, 60));
    char urls[] = "http://baidu.com";
    char cs = 'c';
    strchar(urls,cs);
    printf("factorials(10) = %d\n",myfactorials(5));
    // 以#号开头的命令称为预处理命令
    // 在编译之前对源文件进行简单加工的过程，就称为预处理（即预先处理、提前处理）
    // 编译实例: 开发一个C语言程序，让它暂停 5 秒以后再输出内容，并且要求跨平台，在 Windows 和 Linux 下都能运行
    // 不同平台下的暂停函数和头文件都不一样 Windows 平台下的暂停函数的原型是void Sleep(DWORD dwMilliseconds)（注意 S 是大写的），参数的单位是“毫秒”，位于 <windows.h> 头文件。
    //    Linux 平台下暂停函数的原型是unsigned int sleep (unsigned int seconds)，参数的单位是“秒”，位于 <unistd.h> 头文件
    // 这就要求我们在编译之前，也就是预处理阶段来解决这个问题
    // ！！！写在最上面了
    // #if、#elif、#endif 就是预处理命令，它们都是在编译之前由预处理程序来执行的
    
    // #include叫做文件包含命令，用来引入对应的头文件（.h文件）。#include 也是C语言预处理命令的一种
    // 使用尖括号< >和双引号" "的区别在于头文件的搜索路径不同
    // 使用尖括号< >，编译器会到系统路径下查找头文件；
    // 而使用双引号" "，编译器首先在当前目录下查找头文件，如果没有找到，再到系统路径下查找
    
    // #define 叫做宏定义命令，它也是C语言预处理命令的一种。所谓宏定义，就是用一个标识符来表示一个字符串，如果在后面的代码中出现了该标识符，那么就全部替换成指定的字符串
    second_main();
    pointer();
    constructer();
    fileIO();
}
