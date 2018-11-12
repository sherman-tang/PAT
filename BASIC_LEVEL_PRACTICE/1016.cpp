#include <cstdio>
#include <cstring>
using namespace std;

/*
1016 部分A+B

describe:
正整数 A 的“D​A​​（为 1 位整数）部分”定义为由 A 中所有 D​A​​ 组成的新整数 P​A​​。例如：给定 A=3862767，D​A​​=6，则 A 的“6 部分”P​A​​ 是 66，因为 A 中有 2 个 6。
现给定 A、D​A​​、B、D​B​​，请编写程序计算 P​A​​+P​B​​。

input format:
输入在一行中依次给出 A、D​A​​、B、D​B​​，中间以空格分隔，其中 0<A,B<10^​10​​。

output format:
在一行中输出 P​A​​+P​B​​ 的值

exmaples:
input:
    3862767 6 13530293 3
output:
    399
input:
    3862767 1 13530293 8
output:
    0

*/
int main() {
    char num1[11], num2[11];
    int a, b;
    int cnt1 = 0, cnt2 = 0;
    scanf("%s %d %s %d", num1, &a, num2, &b);
    for (int i = 0; i < strlen(num1); ++i) {
        if (num1[i] - '0' == a)
            ++cnt1;
    }
    for (int i =0; i < strlen(num2); ++i){
        if (num2[i] - '0' == b)
            ++cnt2;
    }
    long long sum1 = 0, sum2 = 0;
    int product;
    if (cnt1 == 0)
    sum1 = 0;
    else{
        product = 1;
        for (int i = 0; i < cnt1; ++i) {
            sum1 += product * a;
            product *= 10;
        }
    }
    if (cnt2 == 0)
    sum2 = 0;
    else {
        product = 1;
        for (int i = 0; i <cnt2; ++i){
            sum2 += product * b;
            product *= 10;
        }
    }
    printf("%lld\n", (sum1 + sum2));
    return 0;
}