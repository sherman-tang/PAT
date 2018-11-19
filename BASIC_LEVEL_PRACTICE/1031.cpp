#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

/*
1031 查验身份证

describe:
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：
首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：
    Z：0 1 2 3 4 5 6 7 8 9 10
    M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

input format:
输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

output format:
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出All passed。

examples:
input:
    4
    320124198808240056
    12010X198901011234
    110108196711301866
    37070419881216001X
output:
    12010X198901011234
    110108196711301866
    37070419881216001X
input:
    2
    320124198808240056
    110108196711301862
output:
    All passed

*/
int main()
{
    int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    unordered_map<int, char> maps = {{0, '1'}, {1, '0'}, {2, 'X'}, {3, '9'}, {4, '8'}, {5, '7'}, {6, '6'}, {7, '5'}, {8, '4'}, {9, '3'}, {10, '2'}};
    int num;
    scanf("%d", &num);
    bool isAllPass = true;
    for (int i = 0; i < num; ++i)
    {
        char id[19];
        scanf("%s", id);
        if (strlen(id) != 18)
        {

            printf("%s\n", id);
            isAllPass = false;
            continue;
        }
        int sum = 0;
        bool isDigit = true;
        for (int i = 0; i < strlen(id) - 1; ++i)
        {
            if (id[i] < '0' || id[i] > '9')
            {
                printf("%s\n", id);
                isAllPass = false;
                isDigit = false;
                break;
            }
            sum += ((id[i] - '0') * weights[i]);
        }
        if (isDigit)
        {
            sum %= 11;
            if (maps[sum] != id[strlen(id) - 1])
            {
                printf("%s\n", id);
                isAllPass = false;
            }
        }
    }
    if (isAllPass)
        printf("All passed\n");
    return 0;
}