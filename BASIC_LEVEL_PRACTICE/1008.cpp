#include <iostream>

/*
1008  数组元素循环右移问题

describe:
一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A​0​​A​1​​⋯A​N−1​​）变换为
（A​N−M​​⋯A​N−1​​A​0​​A​1​​⋯A​N−M−1​​）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

input format:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔

output format:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格

example:
input:
    6 2
    1 2 3 4 5 6
output:
    5 6 1 2 3 4
*/

using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;
}
int main()
{
    int N, M;
    cin >> N >> M;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    M %= N;
    if (M == 0)
    {
        print(arr, N);
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        int temp = arr[N - 1];
        for (int j = N - 1; j > 0; --j)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    print(arr, N);
    return 0;
}