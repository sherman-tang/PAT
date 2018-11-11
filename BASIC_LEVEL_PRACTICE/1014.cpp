#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
/*
1014 福尔摩斯的约会

describe:
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上
就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第5个英
文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第4个位
置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间

input format:
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串

output format:
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示
星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解

example:
input:
    3485djDkxh4hhGE 
    2984akDfkkkkggEdsb 
    s&hgsfdk 
    d&Hyscvnm
ouput:
    THU 14:04
*/

using namespace std;

int main()
{
    vector<string> vec;
    string str;
    for (int i = 0; i < 4; ++i)
    {
        getline(cin, str);
        vec.push_back(str);
    }
    unordered_map<int, string> map{{0, "MON"},
                                   {1, "TUE"},
                                   {2, "WED"},
                                   {3, "THU"},
                                   {4, "FRI"},
                                   {5, "SAT"},
                                   {6, "SUN"}};
    unsigned int len1 = vec[0].length() < vec[1].length() ? vec[0].length() : vec[1].length();
    bool flag = true;
    for (int i = 0; i < len1; i++)
    {
        if (flag && (vec[0][i] >= 'A') && (vec[0][i] <= 'G') && (vec[0][i] == vec[1][i]))
        {
            cout << map[vec[0][i] - 'A'] << " ";
            flag = false;
        }
        else if (!flag && vec[0][i] == vec[1][i])
        {
            if (vec[0][i] >= 'A' && vec[0][i] <= 'N')
            {
                cout << (vec[0][i] - 'A' + 10) << ":";
                break;
            }
            else if (vec[0][i] >= '0' && vec[0][i] <= '9')
            {
                cout << "0" << (vec[0][i] - '0') << ":";
                break;
            }
        }
    }

    int len2 = vec[2].length() < vec[3].length() ? vec[2].length() : vec[3].length();
    for (int i = 0; i < len2; ++i)
    {
        if (vec[2][i] == vec[3][i] && isalpha(vec[2][i]))
        {
            if (i < 9)
                cout << "0" << i << endl;
            else
                cout << i << endl;
            break;
        }
    }
    return 0;
}