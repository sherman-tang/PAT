#include <cstdio>
#include <iterator>
#include <algorithm>

using namespace std;

/*
1019 数字黑洞

describe:
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。例如，
    7766 - 6677 = 1089
    9810 - 0189 = 9621
    9621 - 1269 = 8352
    8532 - 2358 = 6174
    7641 - 1467 = 6174
    ... ...

input format:
输入给出一个 (0,10^​4​​) 区间内的正整数 N

output format:
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数
格式输出。

examples:
input:
    6767
output:
    7766 - 6677 = 1089
    9810 - 0189 = 9621
    9621 - 1269 = 8352
    8532 - 2358 = 6174
input:
    2222
output:
    2222 - 2222 = 0000
*/
void reformArray(int arr[], int num)
{
    arr[3] = num % 10;
    arr[2] = num / 10 % 10;
    arr[1] = num / 100 % 10;
    arr[0] = num / 1000;
}
int getMaxVal(int arr[])
{
    return 1000 * arr[3] + 100 * arr[2] + 10 * arr[1] + arr[0];
}
int getMinVal(int arr[])
{
    return 1000 * arr[0] + 100 * arr[1] + 10 * arr[2] + arr[3];
}
int main()
{
    int arr[4];
    int num;
    scanf("%d", &num);
    reformArray(arr, num);
    if (arr[0] == arr[1] && arr[2] == arr[3] && arr[1] == arr[3])
    {
        printf("%04d - %04d = %04d\n", num, num, 0);
        return 0;
    }
    sort(begin(arr), end(arr));
    int maxVal = getMaxVal(arr);
    int minVal = getMinVal(arr);

    while (true)
    {
        int res = maxVal - minVal;
        printf("%04d - %04d = %04d\n", maxVal, minVal, res);
        if (res == 6174)
            break;
        reformArray(arr, res);
        sort(begin(arr), end(arr));
        maxVal = getMaxVal(arr);
        minVal = getMinVal(arr);
    }
    return 0;
}