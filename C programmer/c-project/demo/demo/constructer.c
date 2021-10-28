//
//  constructer.c
//  demo
//
//  Created by vision chen on 2021/4/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constructer.h"
#include "JudgeSys.h"

char str[3][10] = {
    "http://c.biancheng.net",
    "C语言中文网",
    "C-Language"
};
int getNum() {
    return  100;
};
size_t strnchr(const char *str, char ch) {
    int i, n = 0, len = strlen(str);
    for (i = 0; i < len ; i++) {
        if (str[i] == ch) {
            n++;
        }
    }
    return n;
}

void constructer() {
    // 结构体（Struct）从本质上讲是一种自定义的数据类型，只不过这种数据类型比较复杂，是由 int、char、float 等基本类型组成的。你可以认为结构体是一种聚合类型
    // 用结构体（Struct）来存放一组不同类型的数据
    // 结构体的定义形式为：struct 结构体名{结构体所包含的变量或数组};
    // 像 int、float、char 等是由C语言本身提供的数据类型，不能再进行分拆，我们称之为基本数据类型；而结构体可以包含多个基本类型的数据，也可以包含其他的结构体，我们将它称为复杂数据类型或构造数据类型
    // 结构体变量 struct stu stu1, stu2;定义了两个变量 stu1 和 stu2，它们都是 stu 类型
    // 将变量放在结构体定义的最后
    struct stu{
        char *name;
        int num;
        int age;
        char group;
        float score;
    } stu1,stu2;
    // 如果只需要 stu1、stu2 两个变量，后面不需要再使用结构体名定义其他变量，那么在定义时也可以不给出结构体名
    // 这样做书写简单，但是因为没有结构体名，后面就没法用该结构体定义新的变量
    struct {
        char *name;
        int num;
        int age;
        char group;
        float score;
    } stu3,stu4;
    // 理论上讲结构体的各个成员在内存中是连续存储的，和数组非常类似.共占用 4+4+4+1+4 = 17 个字节
    // 但是在编译器的具体实现中，各个成员之间可能会存在缝隙,对于 stu1、stu2，成员变量 group 和 score 之间就存在 3 个字节的空白填充,stu1、stu2 其实占用了 17 + 3 = 20 个字节
    // 成员的获取和赋值,结构体使用点号.获取单个成员
    stu1.name = "xiaoming";
    stu1.num = 19;
    stu1.age = 20;
    stu1.group = 'A';
    stu1.score = 139.7;
    printf("%s学号是%d,年龄%d,在第%c组，分数是%.2f\n",stu1.name,stu1.num,stu1.age,stu1.group,stu1.score);
    // 除了可以对成员进行逐一赋值，也可以在定义时整体赋值
    struct {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } stu5,stu6 = { "Tom", 12, 18, 'A', 136.5 };
    //  注意：  需要注意的是，结构体是一种自定义的数据类型，是创建变量的模板，不占用内存空间；结构体变量才包含了实实在在的数据，需要内存空间来存储。
    // 结构体组 是指数组中的每个元素都是一个结构体，常被用来表示一个拥有相同数据结构的群体，比如一个班的学生
    // 结构体数组定义
    // 表示一个班级有5个学生
    struct {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } class[5];
    // 结构体数组在定义的同时也可以初始化
    // 当对数组中全部元素赋值时，也可不给出数组长度,注意是全部
    struct {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } class2[5] = {
        {"Li ping", 5, 18, 'C', 145.0},
        {"Zhang ping", 4, 19, 'A', 130.5},
        {"He fang", 1, 18, 'A', 148.5},
        {"Cheng ling", 2, 17, 'F', 139.0},
        {"Wang ming", 3, 17, 'B', 144.5}
    };
    // 计算全班学生的总成绩、平均成绩和以及 140 分以下的人数
    int i,num_140 = 0;
    float sum = 0;
    for (i = 0 ; i < 5; i++) {
        sum += class2[i].score;
        if (class2[i].score < 140 ) {
            num_140++;
        }
    }
    printf("sum=%.2f, avg=%.2f, num_140=%d\n",sum,sum/5,num_140);
    
    // 结构体指针 当一个指针变量指向结构体时，我们就称它为结构体指针
    // 定义形式一般为：struct 结构体名 *变量名;
    struct stu *pstu = &stu1;
    // 也可以在定义结构体的同时定义结构体指针
    struct stu2{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } stu7 = {"nnn",12,32,'B',129.3}, *pstu7 = &stu7;
    // 注意，结构体变量名和数组名不同，数组名在表达式中会被转换为数组指针，而结构体变量名不会，无论在任何表达式中它表示的都是整个集合本身，要想取得结构体变量的地址，必须在前面加&，所以给 pstu 赋值只能写作: struct stu *pstu = &stu1; 而不能写作struct stu *pstu = stu1;
    // 注意，结构体和结构体变量是两个不同的概念：结构体是一种数据类型，是一种创建变量的模板，编译器不会为它分配内存空间，就像 int、float、char 这些关键字本身不占用内存一样；结构体变量才包含实实在在的数据，才需要内存来存储。下面的写法是错误的，不可能去取一个结构体名的地址，也不能将它赋值给其他变量： struct stu *pstu = &stu; struct stu *pstu = stu;
    //通过结构体指针可以获取结构体成员，一般形式为 (*pointer).memberName   pointer->memberName
    // 第一种写法中，.的优先级高于*，(*pointer)两边的括号不能少。如果去掉括号写作*pointer.memberName，那么就等效于*(pointer.memberName)，这样意义就完全不对了
    // 第二种写法中，->是一个新的运算符，习惯称它为“箭头”，有了它，可以通过结构体指针直接取得结构体成员；这也是->在C语言中的唯一用途
    // 上面的两种写法是等效的，我们通常采用后面的写法
    // 第一种写法
    printf("%s的学号是%d,年龄是%d,在%c组，今年的成绩是%.1f\n",(*pstu7).name,(*pstu).num,(*pstu7).age,(*pstu7).group,(*pstu7).score);
    // 第二种写法
    printf("%s的学号是%d,年龄是%d,在%c组，今年的成绩是%.1f\n",pstu7->name,pstu7->num,pstu7->age,pstu7->group,pstu7->score);
    struct stu3 {
        char *name;
        int num;
        int age;
        char group;
        float scores;
    } stu8[] = {
        {"Zhou ping", 5, 18, 'C', 145.0},
        {"Zhang ping", 4, 19, 'A', 130.5},
        {"Liu fang", 1, 18, 'A', 148.5},
        {"Cheng ling", 2, 17, 'F', 139.0},
        {"Wang ming", 3, 17, 'B', 144.5}
    }, *pstu8;
    int pstu8_len = sizeof(stu8) / sizeof(struct stu3);
    printf("name\tnum\tage\tgroup\tscores\n");
    for (pstu8 = stu8; pstu8 < stu8 + pstu8_len ; pstu8++) {
        printf("%s\t%d\t%d\t%c\t%.1f\n",pstu8->name,pstu8->num,pstu8->age,pstu8->group,pstu8->scores);
    }
    // 结构体指针作为函数参数
    // 结构体变量名代表的是整个集合本身，作为函数参数时传递的整个集合，也就是所有成员，而不是像数组一样被编译器转换成一个指针。如果结构体成员较多，尤其是成员为数组时，传送的时间和空间开销会很大，影响程序的运行效率。所以最好的办法就是使用结构体指针，这时由实参传向形参的只是一个地址，非常快速
    
    // 枚举类型enum
    // 在实际编程中，有些数据的取值往往是有限的，只能是非常少量的整数，并且最好为每个值都取一个名字，以方便在后续代码中使用
    // #define命令虽然能解决问题，但也带来了不小的副作用，导致宏名过多，代码松散，看起来总有点不舒服。C语言提供了一种枚举（Enum）类型，能够列出所有可能的取值，并给它们取一个名字。
    // 枚举定义 enum typeName{ valueName1, valueName2, valueName3, ...... };
    // 例如，列出一个星期有几天：enum week{ Mon, Tues, Wed, Thurs, Fri, Sat, Sun };
    // 我们仅仅给出了名字，却没有给出名字对应的值，这是因为枚举值默认从 0 开始，往后逐个加 1（递增）；也就是说，week 中的 Mon、Tues ...... Sun 对应的值分别为 0、1 ...... 6
    // 也可以给每个名字都指定一个值
    // enum week{ Mon = 1, Tues = 2, Wed = 3, Thurs = 4, Fri = 5, Sat = 6, Sun = 7 };
    // 更为简单的方法是只给第一个名字指定值： enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun }; 这样枚举值就从 1 开始递增
    // 枚举是一种类型，通过它可以定义枚举变量 enum week a, b, c;
    // 也可以在定义枚举类型的同时定义变量 enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } a, b, c;
    // 有了枚举变量，就可以把列表中的值赋给它
    // enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun };
    // enum week a = Mon, b = Wed, c = Sat;
    // 或者： enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } a = Mon, b = Wed, c = Sat;
    //  判断用户输入的是星期几
//    enum week{Mon = 1, Tues , Wed , Thurs, Fri, Sat, Sun} day;
//    scanf("%d", &day);
//    switch (day) {
//        case Mon:
//            puts("Mon");
//            break;
//        case Tues:
//            puts("Tues");
//            break;
//        case Wed:
//            puts("Wed");
//            break;
//        case Thurs:
//            puts("Thurs");
//            break;
//        case Fri:
//            puts("Fri");
//            break;
//        case Sat:
//            puts("Sat");
//            break;
//        case Sun:
//            puts("Sun");
//            break;
//        default:
//            puts("Error");
//    }
    // 1) 枚举列表中的 Mon、Tues、Wed 这些标识符的作用范围是全局的（严格来说是 main() 函数内部），不能再定义与它们名字相同的变量
    // 2) Mon、Tues、Wed 等都是常量，不能对它们赋值，只能将它们的值赋给其他的变量
    // 枚举和宏其实非常类似：宏在预处理阶段将名字替换成对应的值，枚举在编译阶段将名字替换成对应的值。我们可以将枚举理解为编译阶段的宏
    // Mon、Tues、Wed 等都不是变量，它们不占用数据区（常量区、全局数据区、栈区和堆区）的内存，而是直接被编译到命令里面，放到代码区，所以不能用&取得它们的地址。这就是枚举的本质
    
    // 共用体（Union），它的定义格式为：union 共用体名{成员列表};
    // 结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；而共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员
    // 结构体占用的内存大于等于所有成员占用的内存的总和（成员之间可能会存在缝隙），共用体占用的内存等于最长的成员占用的内存。共用体使用了内存覆盖技术，同一时刻只能保存一个成员的值，如果对新的成员赋值，就会把原来成员的值覆盖掉。
    // 先定义共同体，在创建变量
    union data {
        int n;
        char ch;
        float f;
    };
    union data u1, u2;
    // 在定义的同时创建变量
    union data2{
        int n;
        char ch;
        float f;
    } a, b, c;
//    如果不再定义新的变量，也可以将共用体的名字省略
    union {
        int n;
        char ch;
        float f;
    } a1, b1, c1;
    // 共用体 data 中，成员 f 占用的内存最多，为 8 个字节，所以 data 类型的变量（也就是 a、b、c）也占用 8 个字节的内存
    union data3 {
        int n;
        char ch;
        float m;
    };
    union data3 d3;
    printf("%d, %d\n", sizeof(d3), sizeof(union data3));
    d3.n = 0*40;
    printf("%X, %c, %hX\n", d3.n, d3.ch, d3.m);
    d3.ch = '9';
    printf("%X, %c, %hX\n", d3.n, d3.ch, d3.m);
    d3.m = 0x2059;
    printf("%X, %c, %hX\n", d3.n, d3.ch, d3.m);
    d3.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", d3.n, d3.ch, d3.m);
    // 大端小端
    //  大端模式： 是指数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中，这样的存储模式有点儿类似于把数据当作字符串顺序处理：地址由小向大增加，而数据从高位往低位放
    //  小端模式：  是指数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中，这种存储模式将地址的高低和数据位权有效地结合起来，高地址部分权值高，低地址部分权值低，和我们的逻辑方法一致
    // 检测 CPU 是大端模式还是小端模式
    int res = JudgeSys();
    if (res == 1) {
        printf("该系统是大端模式\n");
    } else {
        printf("该系统是小端模式\n");
    }
    
    // 位域（位段）
    // 有些数据在存储时并不需要占用一个完整的字节，只需要占用一个或几个二进制位即可。例如开关只有通电和断电两种状态，用 0 和 1 表示足以，也就是用一个二进位。正是基于这种考虑，C语言又提供了一种叫做位域的数据结构
    // 在结构体定义时，我们可以指定某个成员变量所占用的二进制位数（Bit），这就是位域
    // :后面的数字用来限定成员变量占用的位数,成员 m 没有限制，根据数据类型即可推算出它占用 4 个字节（Byte）的内存。成员 n、ch 被:后面的数字限制，不能再根据数据类型计算长度，它们分别占用 4、6 位（Bit）的内存
    struct bs {
        unsigned m;
        unsigned n: 4;
        unsigned char ch: 6;
    };
    // n、ch 的取值范围非常有限，数据稍微大些就会发生溢出
    struct bs bs1 = { 0xad, 0xE, '$' };
    printf("%#x, %#x, %c\n", bs1.m, bs1.n, bs1.ch); // 第一次输出
    bs1.m = 0xb8901c;
    bs1.n = 0x2d;
    bs1.ch = 'z';
    printf("%#x, %#x, %c\n", bs1.m, bs1.n, bs1.ch); // //更改值后再次输出
    // 对于 n 和 ch，第一次输出的数据是完整的，第二次输出的数据是残缺的。
    // 第一次输出时，n、ch 的值分别是 0xE、0x24（'$' 对应的 ASCII 码为 0x24），换算成二进制是 1110、10 0100，都没有超出限定的位数，能够正常输出。
    // 第二次输出时，n、ch 的值变为 0x2d、0x7a（'z' 对应的 ASCII 码为 0x7a），换算成二进制分别是 10 1101、111 1010，都超出了限定的位数。超出部分被直接截去，剩下 1101、11 1010，换算成十六进制为 0xd、0x3a（0x3a 对应的字符是 :）。
    // C语言标准规定，位域的宽度不能超过它所依附的数据类型的长度。通俗地讲，成员变量都是有类型的，这个类型限制了成员变量的最大长度，:后面的数字不能超过这个长度
    // 例如上面的 bs，n 的类型是 unsigned int，长度为 4 个字节，共计 32 位，那么 n 后面的数字就不能超过 32；ch 的类型是 unsigned char，长度为 1 个字节，共计 8 位，那么 ch 后面的数字就不能超过 8
    // 位域技术就是在成员变量所占用的内存中选出一部分位宽来存储数据
    // C语言标准还规定，只有有限的几种数据类型可以用于位域。在 ANSI C 中，这几种数据类型是 int、signed int 和 unsigned int（int 默认就是 signed int）；到了 C99，_Bool 也被支持了。
    // 但编译器在具体实现时都进行了扩展，额外支持了 char、signed char、unsigned char 以及 enum 类型
    // 位域的具体存储规则如下
    // 1) 当相邻成员的类型相同时，如果它们的位宽之和小于类型的 sizeof 大小，那么后面的成员紧邻前一个成员存储，直到不能容纳为止；如果它们的位宽之和大于类型的 sizeof 大小，那么后面的成员将从新的存储单元开始，其偏移量为类型大小的整数倍
    // 例如
    struct bs3 {
        unsigned m: 6;
        unsigned n: 12;
        unsigned p: 4;
    };
    printf("%d\n",sizeof(struct bs3));
    // m、n、p 的类型都是 unsigned int，sizeof 的结果为 4 个字节（Byte），也即 32 个位（Bit）。m、n、p 的位宽之和为 6+12+4 = 22，小于 32，所以它们会挨着存储，中间没有缝隙
    // 如果将成员 m 的位宽改为 22，那么输出结果将会是 8，因为 22+12 = 34，大于 32，n 会从新的位置开始存储，相对 m 的偏移量是 sizeof(unsigned int)，也即 4 个字节 如果再将成员 p 的位宽也改为 22，那么输出结果将会是 12，三个成员都不会挨着存储
    // 2) 当相邻成员的类型不同时，不同的编译器有不同的实现方案，GCC 会压缩存储，而 VC/VS 不会
    // 3) 如果成员之间穿插着非位域成员，那么不会进行压缩。例如对于上面的 bs，在各个编译器下 sizeof 的结果都是 12
    // 通过上面的分析，我们发现位域成员往往不占用完整的字节，有时候也不处于字节的开头位置，因此使用&获取位域成员的地址是没有意义的，C语言也禁止这样做。地址是字节（Byte）的编号，而不是位（Bit）的编号
    // 无名位域： 位域成员可以没有名称，只给出数据类型和位宽，如下所示：
    struct bs4 {
        int m: 12;
        int :20;
        int n: 4;
    };
    printf("%d\n",sizeof(struct bs4));
    // 无名位域一般用来作填充或者调整成员位置。因为没有名称，无名位域不能使用
    // 上面的例子中，如果没有位宽为 20 的无名成员，m、n 将会挨着存储，sizeof(struct bs) 的结果为 4；有了这 20 位作为填充，m、n 将分开存储，sizeof(struct bs) 的结果为 8。
    
    // 位运算（按位与运算、或运算、异或运算、左移运算、右移运算）
    // 按位与运算（&）
    // 一个比特（Bit）位只有 0 和 1 两个取值，只有参与&运算的两个位都为 1 时，结果才为 1，否则为 0。例如1&1为 1，0&0为 0，1&0也为 0，这和逻辑运算符&&非常类似
    // C语言中不能直接使用二进制，&两边的操作数可以是十进制、八进制、十六进制，它们在内存中最终都是以二进制形式存储，&就是对这些内存中的二进制位进行运算。其他的位运算符也是相同的道理
    // 也就是说，按位与运算会对参与运算的两个数的所有二进制位进行&运算，9 & 5的结果为 1
    // -9 & 5的结果是 5
    // 再强调一遍，&是根据内存中的二进制位进行运算的，而不是数据的二进制形式；其他位运算符也一样。以-9&5为例，-9 的在内存中的存储和 -9 的二进制形式截然不同
//    1111 1111 -- 1111 1111 -- 1111 1111 -- 1111 0111  （-9 在内存中的存储）
//    -0000 0000 -- 0000 0000 -- 0000 0000 -- 0000 1001  （-9 的二进制形式，前面多余的 0 可以抹掉）
    // 按位与运算通常用来对某些位清 0，或者保留某些位
    // 例如要把 n 的高 16 位清 0 ，保留低 16 位，可以进行n & 0XFFFF运算（0XFFFF 在内存中的存储形式为 0000 0000 -- 0000 0000 -- 1111 1111 -- 1111 1111）
    int n2 = 0X8FA6002D;
    printf("%d, %d, %X\n", 9 & 5, -9 & 5, n2 & 0XFFFF);
    // 按位或运算（|）,参与|运算的两个二进制位有一个为 1 时，结果就为 1，两个都为 0 时结果才为 0。例如1|1为1，0|0为0，1|0为1，这和逻辑运算中的||非常类似 9 | 5的结果为 13 -9 | 5的结果是 -9
    // 按位或运算可以用来将某些位置 1，或者保留某些位。例如要把 n 的高 16 位置 1，保留低 16 位，可以进行n | 0XFFFF0000运算（0XFFFF0000 在内存中的存储形式为 1111 1111 -- 1111 1111 -- 0000 0000 -- 0000 0000）
    int n3 = 0X2D;
    printf("%d, %d, %X\n", 9 & 5, 9 & -5, n3 | 0XFFFF0000);
    // 按位异或运算(^)，参与^运算两个二进制位不同时，结果为 1，相同时结果为 0。例如0^1为1，0^0为0，1^1为0 9 ^ 5的结果为 12 -9 ^ 5的结果是 -14
    // 按位异或运算可以用来将某些二进制位反转。例如要把 n 的高 16 位反转，保留低 16 位，可以进行n ^ 0XFFFF0000运算
    int n4 = 0X0A07002D;
    printf("%d, %d, %X\n", 9 ^ 5, 9 ^ -5, n4 ^ 0XFFFF0000);
    // 取反运算（~） 取反运算符~为单目运算符，右结合性，作用是对参与运算的二进制位取反。例如~1为0，~0为1，这和逻辑运算中的!非常类似
    // ~9的结果为 -10, ~-9的结果为 8
    printf("%d, %d\n", ~9, ~-9 );
    // 左移运算（<<）左移运算符<<用来把操作数的各个二进制位全部左移若干位，高位丢弃，低位补0。
    // 9<<3的结果为 72 (-9)<<3的结果为 -72 如果数据较小，被丢弃的高位不包含 1，那么左移 n 位相当于乘以 2 的 n 次方
    printf("%d, %d\n", 9<<3, (-9)<<3 );
    // 右移运算（>>） 右移运算符>>用来把操作数的各个二进制位全部右移若干位，低位丢弃，高位补 0 或 1。如果数据的最高位是 0，那么就补 0；如果最高位是 1，那么就补 1
    // 9>>3的结果为 1 (-9)>>3的结果为 -2 如果被丢弃的低位不包含 1，那么右移 n 位相当于除以 2 的 n 次方（但被移除的位中经常会包含 1）
    printf("%d, %d\n", 9>>3, (-9)>>3 );
    char plaintext = 'a'; // 明文
    char secretkey = '!'; // 密钥
    char ciphertext = plaintext ^ secretkey; //密文
    char decodetext = ciphertext ^ secretkey; // 解密后的字符
    char buffer[9];
//    printf("            char    ASCII\n");
    // itoa()用来将数字转换为字符串，可以设定转换时的进制（基数）
    // 这里将字符对应的ascii码转换为二进制
//    printf(" plaintext   %c     %7s\n", plaintext, itoa(plaintext, buffer, 2));
//    printf(" secretkey   %c     %7s\n", secretkey, itoa(secretkey, buffer, 2));
//    printf("ciphertext   %c     %7s\n", ciphertext, itoa(ciphertext, buffer, 2));
//    printf("decodetext   %c     %7s\n", decodetext, itoa(decodetext, buffer, 2));
    // 如果加密和解密的密钥不同，则称为非对称加密算法。在非对称算法中，加密的密钥称为公钥，解密的密钥称为私钥，只知道公钥是无法解密的，还必须知道私钥
    
    // typedef的用法详解
    // 起别名的目的不是为了提高程序运行效率，而是为了编码方便,例如有一个结构体的名字是 stu，要想定义一个结构体变量就得这样写：struct stu stu1; struct 看起来就是多余的，但不写又会报错。如果为 struct stu 起了一个别名 STU，书写起来就简单了： STU stu1;
    // 使用关键字 typedef 可以为类型起一个新的别名。typedef 的用法一般为 typedef  oldName  newName;
    typedef int INTEGER;
    INTEGER a2, b2; //  INTEGER a, b;等效于int a, b;
    // typedef 还可以给数组、指针、结构体等类型定义别名
    // typedef char ARRAY20[20]; 表示 ARRAY20 是类型char [20]的别名。它是一个长度为 20 的数组类型。接着可以用 ARRAY20 定义数组：
    typedef char Array20[20];
    Array20 a3, a4; // 等价于char a3[20], a4[20]；
    // 又如，为结构体类型定义别名：
    typedef struct stu5{
        char name[20];
        int age;
        char sex;
    } STU;
    // STU 是 struct stu 的别名，可以用 STU 定义结构体变量：
    STU body1,body2; // 等价于 struct stu body1, body2;
    // 为指针类型定义别名：
    typedef int (*PTR_TO_ARR)[4]; // 表示 PTR_TO_ARR 是类型int * [4]的别名，它是一个二维数组指针类型。接着可以使用 PTR_TO_ARR 定义二维数组指针：
    PTR_TO_ARR p1, p2;
//    PTR_TO_ARR parr = str;
//    int i1;
//    for(i1=0; i1<3; i1++){
//        printf("str[%d]: %s\n", i1, *(parr+i1));
//    }
    
    // typedef 和 #define 的区别
    // typedef 在表现上有时候类似于 #define，但它和宏替换之间存在一个关键性的区别。正确思考这个问题的方法就是把 typedef 看成一种彻底的“封装”类型，声明之后不能再往里面增加别的东西
    // 1) 可以使用其他类型说明符对宏类型名进行扩展，但对 typedef 所定义的类型名却不能这样做
    // #define INTERGE int
    // unsigned INTERGE n;  //没问题
    // typedef int INTERGE;
    // unsigned INTERGE n;  //错误，不能在 INTERGE 前面添加 unsigned
    // 2) 在连续定义几个变量的时候，typedef 能够保证定义的所有变量均为同一类型，而 #define 则无法保证。例如
    // #define PTR_INT int *
    // PTR_INT p1, p2; 经过宏替换以后，变为： int *p1, p2; 这使得 p1、p2 成为不同的类型：p1 是指向 int 类型的指针，p2 是 int 类型
    // typedef int * PTR_INT
    // PTR_INT p1, p2;  p1、p2 类型相同，它们都是指向 int 类型的指针
    
    // const的用法详解，C语言常量定义详解
    // 有时候我们希望定义这样一种变量，它的值不能被改变，在整个作用域中都保持固定。例如，用一个变量来表示班级的最大人数，或者表示缓冲区的大小。为了满足这一要求，可以使用const关键字对变量加以限定：
    const int MaxNum = 100;  //班级的最大人数
    // 这样 MaxNum 的值就不能被修改了，任何对 MaxNum 赋值的行为都将引发错误：
    // MaxNum = 90;  //错误，试图向 const 变量写入数据
    // 创建常量格式 const type name = value;
    // const 和 type 都是用来修饰变量的，它们的位置可以互换，也就是将 type 放在 const 前面： type const name = value;
    // 由于常量一旦被创建后其值就不能再改变，所以常量必须在定义的同时赋值（初始化），后面的任何赋值行为都将引发错误。一如既往，初始化常量可以使用任意形式的表达式，如下所示：
    int n5 = 90;
    const int MaxNum1 = getNum(); // 运行时初始化
    const int MaxNum2 = n5; // 运行时初始化
    const int MaxNum3 = 23; // 编译时初始化
    printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
    
    // const 也可以和指针变量一起使用，这样可以限制指针变量本身，也可以限制指针指向的数据。const 和指针一起使用会有几种不同的顺序，如下所示：
    const int *p3;
    int const *p4;
    int * const p5;
    // 在最后一种情况下，指针是只读的，也就是 p3 本身的值不能被修改；在前面两种情况下，指针所指向的数据是只读的，也就是 p1、p2 本身的值可以修改（指向不同的数据），但它们指向的数据不能被修改。
    // 指针本身和它指向的数据都有可能是只读的，下面的两种写法能够做到这一点：
    const int * const p6;
    int const * const p7;
    // const 离变量名近就是用来修饰指针变量的，离变量名远就是用来修饰指针指向的数据，如果近的和远的都有，那么就同时修饰指针变量以及它指向的数据
    // 在C语言中，单独定义 const 变量没有明显的优势，完全可以使用#define命令代替。const 通常用在函数形参中，如果形参是一个指针，为了防止在函数内部修改指针指向的数据，就可以用 const 来限制
    // 查找字符串中某个字符出现的次数
    char *str = "http://c.biancheng.net";
    char ch = 't';
    int n = strnchr(str, ch);
    printf("%d\n", n); // 根据 strnchr() 的功能可以推断，函数内部要对字符串 str 进行遍历，不应该有修改的动作，用 const 加以限制 可以防止由于程序员误操作引起的字符串修改
    // const char *和char *是不同的类型，不能将const char *类型的数据赋值给char *类型的变量。但反过来是可以的，编译器允许将char *类型的数据赋值给const char *类型的变量
    // 这种限制很容易理解，char *指向的数据有读取和写入权限，而const char *指向的数据只有读取权限，降低数据的权限不会带来任何问题，但提升数据的权限就有可能发生危险
    
    // 随机数生成教程，C语言rand和srand用法
    // 在C语言中，我们一般使用 <stdlib.h> 头文件中的 rand() 函数来生成随机数，它的用法为： int rand (void); void 表示不需要传递参数
    // C语言中还有一个 random() 函数可以获取随机数，但是 random() 不是标准函数，不能在 VC/VS 等编译器通过，所以比较少用
    // rand() 会随机生成一个位于 0 ~ RAND_MAX 之间的整数
    int a5 = rand();
    printf("%d\n", a5);
    // 多次运行上面的代码，你会发现每次产生的随机数都一样，这是怎么回事呢？为什么随机数并不随机呢？
    // 随机数的本质
    // rand() 函数产生的随机数是伪随机数，是根据一个数值按照某个公式推算出来的，这个数值我们称之为“种子”。种子和随机数之间的关系是一种正态分布，如下图所示
    // 种子在每次启动计算机时是随机的，但是一旦计算机启动以后它就不再变化了；也就是说，每次启动计算机以后，种子就是定值了，所以根据公式推算出来的结果（也就是生成的随机数）就是固定的
    // 我们可以通过 srand() 函数来重新“播种”，这样种子就会发生改变。srand() 的用法为： void srand (unsigned int seed);
    // 它需要一个 unsigned int 类型的参数。在实际开发中，我们可以用时间作为参数，只要每次播种的时间不同，那么生成的种子就不同，最终的随机数也就不同
    //  使用 <time.h> 头文件中的 time() 函数即可得到当前的时间（精确到秒），就像这样：srand((unsigned)time(NULL));
    int a6;
    srand((unsigned)time(NULL));
    a6 = rand();
    printf("%d\n", a6);
    // 这些随机数会有逐渐增大或者逐渐减小的趋势，这是因为我们以时间为种子，时间是逐渐增大的，结合上面的正态分布图，很容易推断出随机数也会逐渐增大或者减小
    
    // 生成一定范围内的随机数
    // int a = rand() % 10;    //产生0~9的随机数，注意10会被整除
    // 如果要规定上下限：
    int a7 = rand() % 51 + 13;    //产生13~63的随机数
    //分析：取模即取余，rand()%51+13我们可以看成两部分：rand()%51是产生 0~50 的随机数，后面+13保证 a 最小只能是 13，最大就是 50+13=63。
    int a8;
    srand((unsigned)time(NULL));
    a8 = rand() % 51 + 13;
    printf("%d\n", a8);
}
