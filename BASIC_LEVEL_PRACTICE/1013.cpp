#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
1013数素数

describe:
令 P​(i)​​ 表示第 i 个素数。现任给两个正整数 M≤N≤10​4​​，请输出 P(​M)​​ 到 P(​N)​​ 的所有素数

input format:
输入在一行中给出 M 和 N，其间以空格分隔

output format:
输出从 P​(M​)​ 到 P​(N)​​ 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格

example:
input:
    5 27
 output:
    11 13 17 19 23 29 31 37 41 43
    47 53 59 61 67 71 73 79 83 89
    97 101 103
*/
bool isPrimer(int n)
{
    for (int i = 2; i <= (int)(sqrt(n) + 0.5); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int M, N;
    cin >> M >> N;
    int num = 3;

    vector<int> vec;
    vec.push_back(2);
    while (true)
    {
        if (isPrimer(num))
        {
            vec.push_back(num);
            if (vec.size() >= N)
                break;
        }
        num += 2;
    }
    int len = N - M;
    if (len == 0){
        cout << vec[N - 1] << endl;
        return 0;
    }
    for (int i = 0; i < len; ++i)
    {
        cout << vec[M + i - 1];
        if ((i + 1) % 10 == 0)
            cout << endl;
        else
            cout << " ";
    }
    cout << vec.back() << endl;

    return 0;
}