#include <iostream>
#include <vector>
using namespace std;

/*
一元多项式求导

describe:
设计函数求一元多项式的导数。（注：x​^n​​（n为整数）的一阶导数为nx^(​n−1)​​。）

input format:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

output format:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0

example:
input:
    3 4 -5 2 6 1 -2 0
output:
    12 3 -10 1 6 0
*/
int main()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    else
    {
        cout << a * b << " " << (b - 1);
        while (cin >> a >> b)
        {
            if (b != 0)
                cout << " " << a * b << " " << (b - 1);
        }
    }
    cout << endl;
    return 0;
}