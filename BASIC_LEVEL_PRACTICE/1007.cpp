#include <iostream>
#include <vector>
#include <cmath>

/*
1007 素数对猜想

describe:
让我们定义d​n​​为：d​(n)​​=p(​n+1)​​−p​(n)​​，其中p(​i)​​是第i个素数。显然有d(​1)​​=1，且对于n>1有d​(n)​​是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10​5​​)，请计算不超过N的满足猜想的素数对的个数

input format:
输入在一行给出正整数N

output format:
在一行中输出不超过N的满足猜想的素数对的个数

example:
input:
    20
output:
    4
*/
using namespace std;

bool isPrimer(int n)
{
    for (int i = 2; i <= (int)(sqrt(n) + 0.5); ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    vector<int> vec;
    int num;
    cin >> num;
    if (num <= 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vec.push_back(2);
    for (int i = 3; i <= num; i += 2)
    {
        if (isPrimer(i))
            vec.push_back(i);
    }
    int cnt = 0;
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] - vec[i - 1] == 2)
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}