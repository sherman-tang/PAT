#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

/*
1018 锤子剪刀布

descrieb:
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势, 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

input format:
输入第 1 行给出正整数 N（≤10​^5​​），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 
代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

output format:
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，
则输出按字母序最小的解。

exmaple:
input: 
    10
    C J
    J B
    C B
    B B
    B C
    C C
    C B
    J B
    B C
    J J
output:
    5 3 2
    2 3 5
    B B
*/
using namespace std;

int cmp(char c1, char c2)
{
    // C->锤子， B->布， J->剪刀
    if (c1 == 'C')
    {
        switch (c2)
        {
        case 'C':
            return 0;
        case 'B':
            return -1;
        case 'J':
            return 1;
        }
    }
    else if (c1 == 'B')
    {
        switch (c2)
        {
        case 'B':
            return 0;
        case 'C':
            return 1;
        case 'J':
            return -1;
        }
    }
    else
    {
        switch (c2)
        {
        case 'J':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return -1;
        }
    }
}

struct comp
{
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
    }
};

int main()
{
    int num;
    scanf("%d", &num);
    while (getchar() != '\n')
        ;
    char ch1, ch2;
    int cnt_win[3] = {0};
    map<char, int> map1;
    map<char, int> map2;
    while (num--)
    {
        scanf("%c %c", &ch1, &ch2);
        while (getchar() != '\n')
            ;
        if (cmp(ch1, ch2) == 1)
        {
            cnt_win[0]++;
            map1[ch1]++;
        }
        else if (cmp(ch1, ch2) == 0)
        {
            cnt_win[1]++;
        }
        else
        {
            cnt_win[2]++;
            map2[ch2]++;
        }
    }
    vector<pair<char, int>> vec1(map1.begin(), map1.end());
    vector<pair<char, int>> vec2(map2.begin(), map2.end());
    sort(vec1.begin(), vec1.end(), comp());
    sort(vec2.begin(), vec2.end(), [](const pair<char, int> &p1, const pair<char, int> &p2)
                                     { return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first; });
    printf("%d %d %d\n", cnt_win[0], cnt_win[1], cnt_win[2]);
    printf("%d %d %d\n", cnt_win[2], cnt_win[1], cnt_win[0]);
    char c1 = vec1.size() ? vec1.front().first : 'B';
    char c2 = vec2.size() ? vec2.front().first : 'B';
    printf("%c %c\n", c1, c2);
    return 0;
}