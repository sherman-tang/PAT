#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
1020 月饼

describe:
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。注意：销售时允许取出一部分
库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部
15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

input format:
每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的
库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

output format:
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

exmaple:
intput:
    3 20
    18 15 10
    75 72 45
output:
    94.50
*/
struct cake
{
    double store;
    double price;
    double ave;
};

struct cmp
{
    bool operator()(const cake &lhs, const cake &rhs)
    {
        return lhs.ave > rhs.ave;
    }
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<cake> vec;
    cake c;
    for (int i = 0; i < N; ++i)
    {
        scanf("%lf", &c.store);
        vec.push_back(c);
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%lf", &vec[i].price);
        vec[i].ave = vec[i].price / vec[i].store;
    }
    sort(vec.begin(), vec.end(), cmp());

    double sum = 0.0;
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        if (vec[i].store >= M)
        {
            sum += vec[i].ave * M;
            break;
        }
        else
        {
            sum += vec[i].ave * vec[i].store;
            M -= vec[i].store;
        }
    }
    printf("%.2lf\n", sum);
    return 0;
}