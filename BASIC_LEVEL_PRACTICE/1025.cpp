#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1025 反转链表

describe:
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为
4→3→2→1→5→6，即最后不到 K 个元素不反转。

input format:
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10​5​​)、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。接下来有 N 行，每行格式为: Address Data Next。 其中Address为结点的地址，Data为结点的数据，Next为下一个结点的地址。

output format:
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

examples:
input:
    00100 6 4
    00000 4 99999
    00100 1 12309
    68237 6 -1
    33218 3 00000
    99999 5 68237
    12309 2 33218  
output:
    00000 4 33218
    33218 3 12309
    12309 2 00100
    00100 1 99999
    99999 5 68237
    68237 6 -1 
*/
struct Node
{
    int val;
    int next;
} nodes[100100];

int main()
{
    int firstAddr, N, K;
    scanf("%d %d %d", &firstAddr, &N, &K);
    if (firstAddr == -1)
    {
        printf("%d\n", -1);
        return 0;
    }
    for (int i = 0; i < N; ++i)
    {
        int aAddr, aVal, aNext;
        scanf("%d %d %d", &aAddr, &aVal, &aNext);
        //printf("addr: %d, val: %d, next: %d\n", aAddr, aVal, aNext);
        nodes[aAddr].val = aVal;
        nodes[aAddr].next = aNext;
    }
    //return 0;
    int p = firstAddr;
    vector<int> addr_vec;
    while (p != -1)
    {
        addr_vec.push_back(p);
        p = nodes[p].next;
    }
    unsigned int size = addr_vec.size();
    int i = 0;
    while (i + K <= size)
    {
        reverse(&addr_vec[i], &addr_vec[i + K]);
        i += K;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        printf("%05d %d %05d\n", addr_vec[i], nodes[addr_vec[i]].val, addr_vec[i + 1]);
    }
    printf("%05d %d %d\n", addr_vec.back(), nodes[addr_vec.back()].val, -1);
    return 0;
}