#include <cstring>
#include <cstdio>

/*
1024 科学计数法

describe:
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数
字及其指数部分的正负号即使对正数也必定明确给出。现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

input format:
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

output format:
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

examples:
input:
    +1.23400E-03
output:
    0.00123400
input:
    -1.2E+10
output:
    -12000000000
*/
char res[20100];
char input[10010];
int main()
{
    scanf("%s", input);
    int pos_e;
    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] == 'E')
        {
            pos_e = i;
            break;
        }
    }
    int cnt = pos_e - 1;
    int exp = 0, product = 1;
    int pos;

    int idx = strlen(input) - 1;
    while (true)
    {
        exp += (input[idx] - '0') * product;
        --idx;
        if (idx == pos_e + 1)
            break;
        product *= 10;
    }
    //rintf("cnt: %d\nexp: %d\n", cnt, exp);
    if (input[0] == '-')
    {
        res[0] = '-';
        pos = 1;
    }
    else
        pos = 0;

    if (input[pos_e + 1] == '-')
    {
        for (int i = 0; i < exp + 1; i++)
        {
            if (i == 1)
                res[pos++] = '.';
            else
                res[pos++] = '0';
        }
        for (int i = 0; i < cnt; ++i)
        {
            if (input[i + 1] != '.')
                res[pos++] = input[i + 1];
        }
    }
    else
    {
        if (cnt == exp + 2)
        {
            for (int i = 0; i < cnt; ++i)
                if (input[i + 1] != '.')
                    res[pos++] = input[i + 1];
        }
        else if (cnt > exp + 2)
        {

            for (int i = 0; i < cnt; ++i)
            {
                if (input[i + 1] == '.')
                {
                    continue;
                }
                if (i == exp + 2)
                {
                    res[pos++] = '.';
                }
                res[pos++] = input[i + 1];
            }
        }
        else
        {
            int diff = exp + 2 - cnt;
            for (int i = 0; i < cnt; ++i)
            {
                if (input[i + 1] != '.')
                    res[pos++] = input[i + 1];
            }
            for (int i = 0; i < diff; ++i)
                res[pos++] = '0';
        }
    }
    printf("%s\n", res);
    return 0;
}
