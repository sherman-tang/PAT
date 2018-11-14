#include <iostream>
#include <algorithm>
#include <vector>

/*
1030完美数列

describe:
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成
一个完美数列。

input format:
输入第一行给出两个正整数 N 和 p，其中 N（≤10^​5​​）是输入的正整数的个数，p（≤10^​9​​）是给定的参数。第二行给出N个正整数，每个数不超过10​^9​​。

output format:
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

example:
input:
    10 8
    2 3 20 4 5 1 6 7 8 9
output:
    8
*/
using namespace std;
int main()
{
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + result; j < n; j++)
        {
            if (v[j] <= v[i] * p)
            {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            }
            else
            {
                break;
            }
        }
    }
    cout << result;
    return 0;
}
