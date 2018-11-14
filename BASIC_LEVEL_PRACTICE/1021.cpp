#include <cstdio>
#include <cstring>
using namespace std;

/*
1021 个位数统计

describe:
请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

input format:
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

output format:
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

example:
input:
    100311
output:
    0:2
    1:3
    3:1
*/
char num[1001];
int main()
{
    int arr[10] = {0};
    scanf("%s", num);
    for (unsigned int i = 0; i < strlen(num); ++i)
    {
        ++arr[num[i] - '0'];
    }
    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] != 0)
            printf("%d:%d\n", i, arr[i]);
    }
    return 0;
}