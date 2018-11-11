#include <stdio.h>
#include <math.h>

/*
1012 数字分类

describe:
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

    A​1​​ = 能被 5 整除的数字中所有偶数的和；
    A​2​​ = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n​1​​−n​2​​+n​3​​−n​4​​⋯；
    A​3​​ = 被 5 除后余 2 的数字的个数；
    A​4​​ = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
    A​5​​ = 被 5 除后余 4 的数字中最大数字。

input format:
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔

output format:
对给定的 N 个正整数，按题目要求计算 A​1​​~A​5​​ 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格,
若其中某一类数字不存在，则在相应位置输出 N

examples:
input:
    13 1 2 3 4 5 6 7 8 9 10 20 16 18
output:
    30 11 2 9.7 9
input:
    8 1 2 4 5 6 7 9 16
output:
    N 11 2 N 9
*/
int main()
{
    int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
    int N, n = 0;
    int i2 = 0, i4 = 0;
    if (scanf("%d", &N))
    {
    };

    while (N--)
    {
        if (scanf("%d", &n))
        {
        };
        switch (n % 5)
        {
        case 0:
            A1 += n % 2 ? 0 : n;
            break;
        case 1:
            A2 += pow(-1, i2++) * n;
            break;
        case 2:
            A3++;
            break;
        case 3:
            A4 += n;
            i4++;
            break;
        default:
            A5 = n > A5 ? n : A5;
            break;
        }
    }
    if (A1)
        printf("%d", A1);
    else
        printf("N");
    if (i2)
        printf(" %d", A2);
    else
        printf(" N");
    if (A3)
        printf(" %d", A3);
    else
        printf(" N");
    if (A4)
        printf(" %.1f", A4 * 1.0 / i4);
    else
        printf(" N");
    if (A5)
        printf(" %d", A5);
    else
        printf(" N");

    printf("\n");

    return 0;
}