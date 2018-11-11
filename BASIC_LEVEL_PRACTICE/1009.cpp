#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

/*
1009 说反话 

describe:
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出

input format:
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间
用 1 个空格分开，输入保证句子末尾没有多余的空格

output format:
每个测试用例的输出占一行，输出倒序后的句子

example:
input:
    Hello World Here I Come
output:
    Come I Here World Hello
*/
int main()
{
    string str;
    getline(cin, str);
    vector<int> vec;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ')
            vec.push_back(i);
    }
    vec.push_back(str.length());
    for (auto p = vec.begin(); p != vec.end(); ++p)
        cout << *p << " ";
    cout << endl;
    //cout << str.substr(vec[vec.size() - 2] + 1, vec[vec.size() - 1]);
    for (int i = vec.size() - 1; i > 0; --i)
    {
        int start = vec[i - 1] + 1, end = vec[i] - start;
        cout << str.substr(start, end) << " ";
    }
    cout << str.substr(0, vec.front()) << "*";
    cout << endl;
    return 0;
}
