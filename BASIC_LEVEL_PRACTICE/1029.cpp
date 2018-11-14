#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <cctype>

/*
1029 旧键盘

describe:
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

input format:
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。
题目保证 2 个字符串均非空。

output format:
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

example:
input:
    7_This_is_a_test
    _hs_s_a_es
output:
    7TI



*/
using namespace std;

bool findElem(const vector<char> &vec, char ch)
{
    for (auto &elem : vec)
    {
        if (elem == ch)
            return true;
    }
    return false;
}

int main()
{
    char str1[81];
    char str2[81];
    scanf("%s\n%s", str1, str2);
    int pos1, pos2;
    pos1 = pos2 = 0;

    vector<char> vec;

    while (pos2 < strlen(str2))
    {
        while (str1[pos1] != str2[pos2])
        {
            char ch = isalpha(str1[pos1]) ? toupper(str1[pos1]) : str1[pos1];
            if (!findElem(vec, ch))//O(n)
                vec.push_back(ch);
            ++pos1;
        }
        ++pos1;
        ++pos2;
    }

    while (pos1 <= strlen(str1))
    {
        char ch = isalpha(str1[pos1]) ? toupper((str1[pos1])) : str1[pos1];
        if (!findElem(vec, ch))
            vec.push_back(ch);
        ++pos1;
    }

    for (auto &elem : vec)
        printf("%c", elem);
    printf("\n");
    return 0;
}