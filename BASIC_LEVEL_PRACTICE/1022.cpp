/*
给定Ｄ进制的两个数Ａ, B返回A+B的Ｄ进制结果
#include <iostream>
using namespace std;

// 
int main()
{
    int num1, num2, d;
    cin >> num1 >> num2 >> d;
    int carry = 0;
    int a, b;
    int x;
    int sum = 0, product = 1;
    while (num1 || num2 || carry)
    {
        a = num1 ? num1 % 10 : 0;
        b = num2 ? num2 % 10 : 0;
        
        sum += ((a + b + carry) % d) * product;
        carry = (a + b + carry) / d;
        product *= d;
        num1 = num1 ? num1 / 10 : 0;
        num2 = num2 ? num2 / 10 : 0;
        //same as follow:
        //num1 /= 10;
        //num2 /= 10;
    }
    cout << sum << endl;
}*/

/*
1022 D进制的Ａ+B

describe:
输入两个非负 10 进制整数 A 和 B (≤2​^30​​−1)，输出 A+B 的 D (1<D≤10)进制数

input format:
输入在一行中依次给出 3 个整数 A、B 和 D

output format:
输出 A+B 的 D 进制数

examples:
input: 123 456 8
output: 1103
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a, b, d;
    stack<int> stk;
    cin >> a >> b >> d;
    int sum = a + b;
    if (sum == 0)
        stk.push(0);
    while (sum)
    {
        stk.push(sum % d);
        sum /= d;
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
}