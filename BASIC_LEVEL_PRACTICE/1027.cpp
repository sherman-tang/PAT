#include <cstdio>
using namespace std;

/*
1027 打印漏

describe:
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印:
    *****
     ***
      *
     ***
    *****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。给定任意N个符号，不一
定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

input format:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔

output format:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。**注意**:漏斗的有半部分不需要打印空格

example:
input:
    19 *
output:
    *****
     ***
      *
     ***
    *****
2
*/
int main()
{
    int num;
    char ch;
    scanf("%d %c", &num, &ch);
    int row = 1;
    int sum = 1;
    while (true)
    {
        if (sum + ((row + 1) * 2 - 1) * 2 > num)
            break;
        sum += ((row + 1) * 2 - 1) * 2;
        ++row;
    }
    int rest = num - sum;
    int max_width = row * 2 - 1;
    for (int i = row; i > 0; i--)
    {
        int ch_width = 2 * i - 1;
        for (int j = 0; j < (max_width - ch_width) / 2; j++)
            printf(" ");
        for (int j = 0; j < ch_width; j++)
            printf("%c", ch);
        printf("\n");
    }
    for (int i = 1; i < row; ++i)
    {
        int ch_width = 2 * i + 1;
        for (int j = 0; j < (max_width - ch_width) / 2; ++j)
            printf(" ");
        for (int j = 0; j < ch_width; ++j)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d\n", rest);
    return 0;
}