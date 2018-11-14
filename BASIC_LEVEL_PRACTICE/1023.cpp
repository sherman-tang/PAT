#include <cstdio>
#include <cstring>
using namespace std;

/*
1023 组个最小数

describe:
给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。例如：给定两个 0，两个 1，三个5，
一个 8，我们得到的最小的数就是 10015558。现给定数字，请编写程序输出能够组成的最小的数。

input format:
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 
的数字。

output format:
在一行中输出能够组成的最小的数

example:
input:
    2 2 0 0 0 3 0 0 1 0
output:
    10015558
*/
int res[51];
int main()
{
    int arr[10] = {0};
    bool flag = true;
    int index = -1;
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &arr[i]);
        if (flag && arr[i] != 0 && i != 0)
        {
            index = i;
            flag = false;
        }
    }
    int pos = 0;
    res[0] = index;
    --arr[index];
    ++pos;
    for (int i = 0; i < arr[0]; ++i)
    {
        res[pos++] = 0;
    }
    for (int i = index; i < 10; i++)
    {
        while (arr[i]--)
        {
            res[pos++] = i;
        }
    }
    for (int i = 0; i < pos; ++i)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}