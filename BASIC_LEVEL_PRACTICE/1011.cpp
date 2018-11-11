#include <iostream>
#include <string>
#include <vector>
/*
1011 A+B 和 C

describe:
给定区间 [−2​^31​​,2^​31​​] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C

input format:
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔

output format:
对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）

exmaple:
input:
    4
    1 2 3
    2 3 4
    2147483647 0 2147483646
    0 -2147483648 -2147483647
output:
    Case #1: false
    Case #2: true
    Case #3: true
    Case #4: false
*/
int main()
{
    using namespace std;
    int num;
    long long a, b, c;
    cin >> num;
    int index = 0;
    string flag;
    vector<string> vec;
    while (index < num)
    {
        cin >> a >> b >> c;
        if (a + b > c)
            flag = "true";
        else
            flag = "false";
        vec.push_back(flag);
        ++index;
    }
    for (int i = 0; i < vec.size(); ++i)
        cout << "Case #"  << (i + 1) << ": " << vec[i] << endl;
    return 0;
}