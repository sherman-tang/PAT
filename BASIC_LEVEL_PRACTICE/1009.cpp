#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

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