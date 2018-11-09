#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
1005 继续(3n+1)猜想

describe:
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对 n=3 进行验证的时候，我们需要计算 3、5、8、4、2、1，则当我们对 n=5、8、4、2 进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这 4 个数已经在验证3的时候遇到过了，我们称 5、8、4、2 是被 3“覆盖”的数。我们称一个数列中的某个数 n 为“关键数”，如果 n 不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

input format:
每个测试输入包含 1 个测试用例，第 1 行给出一个正整数 K (<100)，第 2 行给出 K 个互不相同的待验证的正整数 n (1<n≤100)的值，数字间用空格隔开

output format:
每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用 1 个空格隔开，但一行中最后一个数字后没有空格

example:
input
*/
using namespace std;
int main()
{
    vector<int> vec;
    unordered_set<int> elems;
    unordered_set<int> outputs;
    int num;
    cin >> num;
    int val;
    while (num--)
    {
        cin >> val;
        vec.push_back(val);
    }
    for (auto &e : vec)
    {
        if (elems.find(e) != elems.end())
            //found in elems set and continue
            continue;
        else
        {
            outputs.insert(e);
            while (e != 1)
            {
                e = e % 2 == 0 ? e / 2 : (3 * e + 1) / 2;
                if (elems.find(e) == elems.end())
                    elems.insert(e);
                if (outputs.find(e) != elems.end())
                    outputs.erase(e);
            }
        }
    }
    vector<int> res(outputs.begin(), outputs.end());
    sort(res.begin(), res.end(), [](int a, int b) {
        return a > b;
    });
    /*
    for (auto p = res.rbegin(); p != res.rend() - 1; ++p)
        cout << *p << " ";
    cout << res.front() << endl;
    */
    /*
    for (auto p = res.end() - 1; p != res.begin(); --p)
        cout << *p << " ";
    cout << res.front() << endl;
    */
    for (auto p = res.begin(); p != res.end() - 1; ++p)
        cout << *p << " ";
    cout << res.back() << endl;
    return 0;
}