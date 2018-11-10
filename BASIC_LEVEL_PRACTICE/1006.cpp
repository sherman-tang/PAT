#include <iostream>
using namespace std;

/*
1006 换个格式输出整数

describe:
让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。
例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

input format:
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）

output format:
每个测试用例的输出占一行，用规定的格式输出 n

examples:
input:
    234
output:
    BBSSS1234
input:
    23
output:
    SS123
*/
int main()
{
    int num; // 0 < num < 1000
    cin >> num;
    int a, b, c;
    a = num / 100;
    b = num / 10 % 10;
    c = num % 10;
    for (int i = 0; i < a; ++i)
        cout << "B";
    for (int i = 0; i < b; ++i)
        cout << "S";
    for (int i = 0; i < c; ++i)
        cout << (i + 1);
    cout << endl;
    return 0;
}