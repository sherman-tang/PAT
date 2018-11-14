#include <cstdio>

/*
1026 程序运行时间 

describe:
要获得一个 C 语言程序的运行时间，常用的方法是调用头文件 time.h，其中提供了 clock() 函数，可以捕捉从程序开始运行到 clock() 被调用时所耗费的时间。这个时间单位是
clock tick，即“时钟打点”。同时还有一个常数 CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得一个函数 f 的运行时间，我们只要在调用f之前先调用 clock()，
获得一个时钟打点数 C1；在 f 执行完成后再调用 clock()，获得另一个时钟打点数 C2；两次获得的时钟打点数之差 (C2-C1) 就是 f 运行所消耗的时钟打点数，再除以常数 
CLK_TCK，就得到了以秒为单位的运行时间。这里不妨简单假设常数 CLK_TCK 为 100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。

input format:
输入在一行中顺序给出 2 个整数 C1 和 C2。注意两次获得的时钟打点数肯定不相同，即 C1 < C2，并且取值在 [0,10​^7​​]

output format:
在一行中输出被测函数运行的时间。运行时间必须按照 hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒

example:
input:
    123 4577973
output:
    12:42:59
*/
const unsigned int CLK_TCK = 100;

using namespace std;

int main()
{
    unsigned int _start, _end;
    scanf("%u %u", &_start, &_end);
    unsigned int total = (int)((_end - _start) * 1.0 / CLK_TCK + 0.5);
    unsigned int hour, min, sec;
    hour = total / 3600;
    min = total % 3600 / 60;
    sec = total % 3600 % 60;
    printf("%02u:%02u:%02u\n", hour, min, sec);
    return 0;
}