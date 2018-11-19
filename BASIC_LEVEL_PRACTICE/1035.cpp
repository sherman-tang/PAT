#include <iostream>
#include <algorithm>
using namespace std;
/*
1035 插入与归并

describe:
根据维基百科的定义：
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

input format:
输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

output format:
首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。
数字间以空格分隔，且行首尾不得有多余空格。

examples:
input:
    10
    3 1 2 8 7 5 9 4 6 0
    1 2 3 7 8 5 9 4 6 0
output:
    Insertion Sort
    1 2 3 5 7 8 9 4 6 0
input:
    10
    3 1 2 8 7 5 9 4 0 6
    1 3 2 8 5 7 4 9 0 6
output:
    Merge Sort
    1 2 3 8 4 5 7 9 0 6
*/

int main()
{

    int n;
    cin >> n;
    int a[105];
    int b[105];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int i = 0, j = 0;
    for (; b[i + 1] >= b[i] && (i + 1) < n; ++i)
        ;
    for (j = i + 1; a[j] == b[j] && j < n; ++j)
        ;
    if (j == n)
    {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    }
    else
    {
        cout << "Merge Sort" << endl;
        int k = 2, flag = 1;
        int i = 0;
        while (flag)
        {
            for (j = 0; a[j] == b[j] && j < n; ++j)
                ;
            if (j == n)
                flag = 0;
            for (i = 0; (i + 1) * k < n; ++i)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + i * k, a + n);
            k *= 2;
        }
    }
    cout << a[0];
    for (int i = 1; i < n; ++i)
        cout << " " << a[i];
    cout << endl;

    return 0;
}
