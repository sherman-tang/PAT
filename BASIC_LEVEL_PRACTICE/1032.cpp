/*
1032 挖掘机技术哪家强

describe:
输入在第 1 行给出不超过 10​5​​ 的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

inputs:
6
3 65
2 80
1 100
2 70
3 40
3 0

outputs:
2 150
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    unordered_map<int, int> map;
    cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b;
        if (map.find(a) != map.end())
            map[a] += b;
        else
            map[a] = b;
    }

    pair<int, int> p{0, 0};
    for (auto &elem: map) {
        if (elem.second > p.second)
            p = make_pair(elem.first, elem.second);
    }
    cout << p.first << " " << p.second << endl;
    return 0;
}
