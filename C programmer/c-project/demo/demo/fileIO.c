//
//  fileIO.c
//  demo
//
//  Created by vision chen on 2021/5/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#define N 10
#define N1 5
#define N2 2
void fileIO() {
    // 文件流
    // 所有的文件（保存在磁盘）都要载入内存才能处理，所有的数据必须写入文件（磁盘）才不会丢失。数据在文件和内存之间传递的过程叫做文件流，类似水从一个地方流动到另一个地方。数据从文件复制到内存的过程叫做输入流，从内存保存到文件的过程叫做输出流
    // 把数据在数据源和程序（内存）之间传递的过程叫做数据流(Data Stream)。相应的，数据从数据源到程序（内存）的过程叫做输入流(Input Stream)，从程序（内存）到数据源的过程叫做输出流(Output Stream)
    // 在C语言中，操作文件之前必须先打开文件；所谓“打开文件”，就是让程序和文件建立连接的过程.打开文件之后，程序可以得到文件的相关信息，例如大小、类型、权限、创建者、更新时间等。在后续读写文件的过程中，程序还可以记录当前读写到了哪个位置，下次可以在此基础上继续操作
    // 使用 <stdio.h> 头文件中的 fopen() 函数即可打开文件，它的用法为 FILE *fopen(char *filename, char *mode); filename为文件名（包括文件路径），mode为打开方式，它们都是字符串
    // 如果希望接收 fopen() 的返回值，就需要定义一个 FILE 类型的指针。例如：
    // FILE *fp = fopen("demo.txt", "r"); 表示以“只读”方式打开当前目录下的 demo.txt 文件，并使 fp 指向该文件，这样就可以通过 fp 来操作 demo.txt 了。fp 通常被称为文件指针
    // FILE *fp = fopen("D:\\demo.txt","rb+"); 表示以二进制方式打开 D 盘下的 demo.txt 文件，允许读和写。
    // 判断文件是否打开成功
    // 打开文件出错时，fopen() 将返回一个空指针，也就是 NULL，我们可以利用这一点来判断文件是否打开成功
//    FILE *fp;
//    if( (fp=fopen("D:\\demo.txt","rb") == NULL)){
//        printf("Fail to open file!\n");
//        return;
//    };
    // 以上代码是文件操作的规范写法，在打开文件时一定要判断文件是否打开成功，因为一旦打开失败，后续操作就都没法进行了，往往以“结束程序”告终
    
    // fopen() 函数的打开方式
    // 不同的操作需要不同的文件权限。例如，只想读取文件中的数据的话，“只读”权限就够了；既想读取又想写入数据的话，“读写”权限就是必须的了
    
    // 控制读写权限的字符串（必须指明）
    // "r"    以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
    // "w"    以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    // "a"    以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
    // "r+"    以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
    // "w+"    以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    // "a+"    以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
    
    // 控制读写方式的字符串（可以不写)
    // "t"    文本文件。如果不写，默认为"t"
    // "b"    二进制文件
    // 调用 fopen() 函数时必须指明读写权限，但是可以不指明读写方式（此时默认为"t"）
    // 整体来说，文件打开方式由 r、w、a、t、b、+ 六个字符拼成，各字符的含义是： r(read)：读 w(write)：写 a(append)：追加 t(text)：文本文件 b(binary)：二进制文件 +：读和写
    
    // 关闭文件
    // 文件一旦使用完毕，应该用 fclose() 函数把文件关闭，以释放相关资源，避免数据丢失 fclose() 的用法为： int fclose(FILE *fp);
    // 文件正常关闭时，fclose() 的返回值为0，如果返回非零值则表示有错误发生
    
//    FILE *fps;
//    char str[N + 1];
//    if ((fps = fopen("/Users/visionchen/programming/C programmer/c-project/demo/demo/test.text","rt") == NULL)) {
//        puts("Fail to open file!");
//        return;
//    }
//    while(fgets(str, N, fps)!= NULL ) {
//        printf("%s", str);
//    }
//    fclose(fps);
    
    
    // fgetc和fputc函数
    // 以字符形式读写文件时，每次可以从文件中读取一个字符，或者向文件中写入一个字符。主要使用两个函数，分别是 fgetc() 和 fputc()
    // fgetc() 的用法为：int fgetc (FILE *fp);  fgetc() 读取成功时返回读取到的字符，读取到文件末尾或读取失败时返回EOF
    // EOF 是 end of file 的缩写，表示文件末尾，是在 stdio.h 中定义的宏，它的值是一个负数，往往是 -1。fgetc() 的返回值类型之所以为 int，就是为了容纳这个负数（char不能是负数） EOF 不绝对是 -1，也可以是其他负数，这要看编译器的实现
    char ch;
    FILE *fp;
    if ((fp = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.md", "rt")) == NULL) {
        puts("fail open file");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    putchar('\n');
    fclose(fp);
    // FILE *fp = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.md", "r+");
    // ch = fgetc(fp); // 文件中读取一个字符，并保存到变量 ch 中
    // 在文件内部有一个位置指针，用来指向当前读写到的位置，也就是读写到第几个字节。在文件打开时，该指针总是指向文件的第一个字节。使用 fgetc() 函数后，该指针会向后移动一个字节，所以可以连续多次使用 fgetc() 读取多个字符。
    // 这个文件内部的位置指针与C语言中的指针不是一回事。位置指针仅仅是一个标志，表示文件读写到的位置，也就是读写到第几个字节，它不表示地址。文件每读写一次，位置指针就会移动一次，它不需要你在程序中定义和赋值，而是由系统自动设置，对用户是隐藏的
    // EOF 本来表示文件末尾，意味着读取结束，但是很多函数在读取出错时也返回 EOF，那么当返回 EOF 时，到底是文件读取完毕了还是读取出错了？我们可以借助 stdio.h 中的两个函数来判断，分别是 feof() 和 ferror()
    // feof() 函数用来判断文件内部指针是否指向了文件末尾，它的原型是： int feof ( FILE * fp ); 当指向文件末尾时返回非零值，否则返回零值
    // ferror() 函数用来判断文件操作是否出错，它的原型是： int ferror ( FILE *fp ); 出错时返回非零值，否则返回零值
    FILE *fp2;
    char ch2;
    if ((fp2 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "rt")) == NULL) {
        puts("fail open file");
        exit(0);
    }
    while ((ch2 = fgetc(fp2)) != EOF) {
        putchar(ch2);
    }
    putchar('\n');
    if (ferror(fp2)) {
        puts("读取错误");
    } else {
        puts("读取成功");
    }
    fclose(fp2);
    // 字符写入函数 fputc, 意思是向指定的文件中写入一个字符。fputc() 的用法为 int fputc ( int ch, FILE *fp );
    // ch 为要写入的字符，fp 为文件指针。fputc() 写入成功时返回写入的字符，失败时返回 EOF，返回值类型为 int 也是为了容纳这个负数。例如：fputc('a', fp);或者char ch = 'a'; fputc(ch, fp);  表示把字符 'a' 写入fp所指向的文件中。
    // 两点说明：
    // 1) 被写入的文件可以用写、读写、追加方式打开，用写或读写方式打开一个已存在的文件时将清除原有的文件内容，并将写入的字符放在文件开头。如需保留原有文件内容，并把写入的字符放在文件末尾，就必须以追加方式打开文件。不管以何种方式打开，被写入的文件若不存在时则创建该文件
    // 2) 每写入一个字符，文件内部位置指针向后移动一个字节
    
//    从键盘输入一行字符，写入文件
//    FILE *fp3;
//    char ch3;
//    if ((fp3 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "at+")) == NULL) {
//        puts("fail open file");
//        exit(0);
//    }
//    printf("input a string:\n");
//    while ((ch3 = getchar()) != '\n') {
//        fputc(ch3, fp3);
//    }
//    while ((ch3 = fgetc(fp3)) != EOF) {
//        putchar(ch3);
//    }
//    putchar('\n');
//    if (ferror(fp3)) {
//        puts("读取失败\n");
//    } else {
//        puts("读取成功");
//    }
//    fclose(fp3);
    
    // fgets和fputs函数的用法详解（以字符串的形式读写文件）
    // fgetc() 和 fputc() 函数每次只能读写一个字符，速度较慢；实际开发中往往是每次读写一个字符串或者一个数据块，这样能明显提高效率
    // 读字符串函数 fgets用来从指定的文件中读取一个字符串，并保存到字符数组中，它的用法为：char *fgets ( char *str, int n, FILE *fp );str 为字符数组，n 为要读取的字符数目，fp 为文件指针。
    // 返回值：读取成功时返回字符数组首地址，也即 str；读取失败时返回 NULL；如果开始读取时文件内部指针已经指向了文件末尾，那么将读取不到任何字符，也返回 NULL
    // 注意，读取到的字符串会在末尾自动添加 '\0'，n 个字符也包括 '\0'。也就是说，实际只读取到了 n-1 个字符，如果希望读取 100 个字符，n 的值应该为 101
    // 需要重点说明的是，在读取到 n-1 个字符之前如果出现了换行，或者读到了文件末尾，则读取结束。这就意味着，不管 n 的值多大，fgets() 最多只能读取一行数据，不能跨行。在C语言中，没有按行读取文件的函数，我们可以借助 fgets()，将 n 的值设置地足够大，每次就可以读取到一行数据。
    // 【示例】一行一行地读取文件
    FILE *fp4;
    char str2[N + 1];
    if ((fp4 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "rt")) == NULL) {
        puts("fail open file");
        exit(0);
    }
    while (fgets(str2, N, fp4)) {
        printf("%s", str2);
    }
    putchar('\n');
    if (ferror(fp4)) {
        puts("读取失败");
    } else {
        puts("读取成功");
    }
    fclose(fp4);
    // fgets() 遇到换行时，会将换行符一并读取到当前字符串。该示例的输出结果之所以和 demo.txt 保持一致，该换行的地方换行，就是因为 fgets() 能够读取到换行符。而 gets() 不一样，它会忽略换行符。
    // 写字符串函数 fputs用来向指定的文件写入一个字符串，它的用法为：int fputs( char *str, FILE *fp );str 为要写入的字符串，fp 为文件指针。写入成功返回非负数，失败返回 EOF。例如：
    char *str3 = "\nhttp://baidu.com";
    FILE *fp5 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "at+");
    fputs(str3, fp5);
    if (ferror(fp5)) {
        puts("写入失败");
    } else {
        puts("写入成功");
    }
    fclose(fp5);
    
    // fread和fwrite的用法详解（以数据块的形式读写文件）
    // fgets() 有局限性，每次最多只能从文件中读取一行内容，因为 fgets() 遇到换行符就结束读取。如果希望读取多行内容，需要使用 fread() 函数；相应地写入函数为 fwrite()。
    // 对于 Windows 系统，使用 fread() 和 fwrite() 时应该以二进制的形式打开文件
    // fread() 函数用来从指定文件中读取块数据。所谓块数据，也就是若干个字节的数据，可以是一个字符，可以是一个字符串，可以是多行数据，并没有什么限制。fread() 的原型为：size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );
    // fwrite() 函数用来向文件中写入块数据，它的原型为：size_t fwrite ( void * ptr, size_t size, size_t count, FILE *fp );
    // ptr 为内存区块的指针，它可以是数组、变量、结构体等。fread() 中的 ptr 用来存放读取到的数据，fwrite() 中的 ptr 用来存放要写入的数据;
    // size：表示每个数据块的字节数
    // count：表示要读写的数据块的块数。
    // fp：表示文件指针
    // 理论上，每次读写 size*count 个字节的数据
    // size_t 是在 stdio.h 和 stdlib.h 头文件中使用 typedef 定义的数据类型，表示无符号整数，也即非负数，常用来表示数量
    // 返回值：返回成功读写的块数，也即 count。如果返回值小于 count：
    // 对于 fwrite() 来说，肯定发生了写入错误，可以用 ferror() 函数检测。
    // 对于 fread() 来说，可能读到了文件末尾，可能发生了错误，可以用 ferror() 或 feof() 检测。
    // 从键盘输入一个数组，将数组写入文件再读取出来
//    int a1[N], b1[N];
//    int i, size = sizeof(int);
//    FILE *fp6;
//    if ((fp6 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "rb+")) == NULL) {
//        puts("fail open file");
//        exit(0);
//    }
//    for (i = 0; i < N1; i++) {
//        scanf("%d", &a1[i]);
//    }
//    fwrite(a1, size, N, fp6); //将数组a的内容写入到文件
//    rewind(fp6); //将文件中的位置指针重新定位到文件开头
//    fread(b1, size, N, fp6); //从文件读取内容并保存到数组b
//    for (i = 0; i < N; i++) {
//        printf("%d", b1[i]);
//    }
//    printf("\n");
//    rewind(fp6);
//    fclose(fp6);
    
    // 从键盘输入两个学生数据，写入一个文件中，再读出这两个学生的数据显示在屏幕上
//    struct student {
//        char name[10];
//        int num;
//        int age;
//        float score;
//    } boya[N], boyb[N], *pa, *pb;
//    FILE *fp7;
//    int i2;
//    pa = boya;
//    pb = boyb;
//    if ((fp7 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/test.text", "wb+")) == NULL) {
//        puts("fail open file");
//        exit(0);
//    }
//    printf("input data:\n");
//    for (i2 = 0; i2 < N2; i2++, pa++) {
//        scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
//    }
//    fwrite(boya, sizeof(struct student), N, fp7); //将数组 boya 的数据写入文件
//    rewind(fp7); //将文件指针重置到文件开头
//    fread(boyb, sizeof(struct student), N, fp7);
//    for (i2 = 0; i2 < N2; i2++, pb++) {
//        printf("%s %d %d %f\n", pb->name, pb->num, pb->age, pb->score);
//    }
//    fclose(fp7);
    
    // fscanf和fprintf函数的用法详解（格式化读写文件)
    // fscanf() 和 fprintf() 函数与前面使用的 scanf() 和 printf() 功能相似，都是格式化读写函数，两者的区别在于 fscanf() 和 fprintf() 的读写对象不是键盘和显示器，而是磁盘文件
    // 这两个函数的原型为 int fscanf ( FILE *fp, char * format, ... ); int fprintf ( FILE *fp, char * format, ... );
    // fp 为文件指针，format 为格式控制字符串，... 表示参数列表
    // fprintf() 返回成功写入的字符的个数，失败则返回负数。fscanf() 返回参数列表中被成功赋值的参数个数
    // 用 fscanf 和 fprintf 函数来完成对学生信息的读写
    struct stu {
        char name[10];
        int num;
        int age;
        float score;
    } boya1[N2], boyb1[N2], *pa1, *pb1;
    pa1 = boya1;
    pb1 = boyb1;
    FILE *fp8;
    int i;
    if ((fp8 = fopen("/Users/visionchen/programming/C\ programmer/c-project/demo/demo/student.md", "wt+")) == NULL) {
        puts("fail open file");
        exit(0);
    }
    printf("input data: \n");
    for (i = 0; i < N2; i++, pa1++) {
        scanf("%s %d %d %f", pa1->name, &pa1->num, &pa1->age, &pa1->score);
    }
    pa1 = boya1;
    for (i = 0; i < N2; i++, pa1++) {
        fprintf(fp8, "%s %d %d %f\n", pa1->name, pa1->num, pa1->age, pa1->score);
    }
    rewind(fp8);
    for (i = 0; i < N2; i++, pb1++) {
        fscanf(fp8,"%s %d %d %f\n", pb1->name, &pb1->num, &pb1->age, &pb1->score);
    }
    pb1 = boyb1;
    for (i = 0; i < N2; i++, pb1++) {
        printf("%s %d %d %f\n", pb1->name, pb1->num, pb1->age, pb1->score);
    }
    fclose(fp8);
    // 发现文件的内容是可以阅读的，格式非常清晰。用 fprintf() 和 fscanf() 函数读写配置文件、日志文件会非常方便，不但程序能够识别，用户也可以看懂，可以手动修改。
    // 如果将 fp 设置为 stdin，那么 fscanf() 函数将会从键盘读取数据，与 scanf 的作用相同；设置为 stdout，那么 fprintf() 函数将会向显示器输出内容，与 printf 的作用相同。例如：
    int a, b, sum;
    fprintf(stdout, "Input two numbers: ");
    fscanf(stdin, "%d %d", &a, &b);
    sum = a + b;
    fprintf(stdout, "sum=%d\n", sum);
}
