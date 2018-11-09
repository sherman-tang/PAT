#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
1003 我要通过

describe:
得到正确答案的条件是：
    
    1. 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符
    2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串
    3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串

input format:
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格

output format:
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO

examples:
inputs:
    8
    PAT
    PAAT
    AAPATAA
    AAPAATAAAA
    xPATx
    PT
    Whatever
    APAAATAA
outputs:
    YES
    YES
    YES
    YES
    NO
    NO
    NO
    NO
*/
int countA(const char *_start, const char *_end)
{
    int cnt = 0;
    for (auto &p = _start; p != _end; ++p)
    {
        if (*p == 'A')
            ++cnt;
    }
    return cnt;
}
int main()
{
    string str;
    int num;
    cin >> num;
    vector<string> vec;
    cin.get();
    while (num--)
    {
        getline(cin, str);
        vec.push_back(str);
    }
    for (const auto &str : vec)
    {
        //cout << "elem: " << str << " -> ";
        int index1 = -1, index2 = -1;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'P')
                index1 = i;
            if (str[i] == 'T')
                index2 = i;
        }
        if (index1 >= index2 - 1 || index1 == -1 || index2 == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        if (index1 == 0 && index2 == str.length() - 1)
        {
            bool flag = true;
            for (int i = index1 + 1; i < index2; ++i)
            {
                if (str[i] != 'A')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            int cnt1 = countA(str.c_str(), str.c_str() + index1);
            int cnt2 = countA(str.c_str() + index1 + 1, str.c_str() + index2);
            int cnt3 = countA(str.c_str() + index2 + 1, str.c_str() + str.length());
            if (cnt1 * cnt2 == cnt3 && cnt1 != 0 && cnt2 != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}