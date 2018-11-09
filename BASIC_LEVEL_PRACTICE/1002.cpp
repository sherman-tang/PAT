#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/*
1002 写出这个数

describe:
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字

input format:
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10​^100

output format:
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格

examples:
input
    1234567890987654321123456789
output:
    yi san wu
*/
int main() {
    string str;
    getline(cin, str);
    int sum = 0;
    for(int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
    }
    //cout << sum << endl;
    unordered_map<int, string> map{{0, "ling"}, {1, "yi"}, {2, "er"}, {3, "san"}, {4, "si"}, {5, "wu"}, {6, "liu"}, {7, "qi"}, {8, "ba"},{9,"jiu"}};
    if (sum < 9) {
        cout << map[sum] << endl;
        return 0;
    }
    stack<int> stk;
    while(sum) {
        stk.push(sum % 10);
        sum /= 10;
    }
    while(stk.size() > 1) {
        cout << map[stk.top()] << " ";
        stk.pop();
    }
    cout << map[stk.top()] << endl;

    return 0;
}