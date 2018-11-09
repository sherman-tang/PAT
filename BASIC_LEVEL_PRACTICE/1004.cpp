#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
1004 成绩排名

describe:
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号

input format:
第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
  ... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的

output format:
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格

exmaple:
input:
    3
    Joe Math990112 89
    Mike CS991301 100
    Mary EE990830 95
output:
    Mike CS991301
    Joe Math990112
*/

struct Student
{
    string name;
    string stuNum;
    int score;
    Student(string _name, string _stuNum, int _score) : name(_name), stuNum(_stuNum), score(_score) {}
    bool operator<(Student &other);
    friend ostream &operator<<(ostream &os, const Student &stu);
};
bool Student::operator<(Student &other)
{
    return this->score < other.score;
}
ostream &operator<<(ostream &os, const Student &stu)
{
    os << stu.name << " " << stu.stuNum;
    return os;
}

int main()
{
    int num;
    cin >> num;
    vector<Student *> vec;
    string name, stuNum;
    int score;
    while (num--)
    {
        cin >> name >> stuNum >> score;
        vec.push_back(&Student(name, stuNum, score));
    }
    sort(vec.begin(), vec.end());
    cout << *vec.back() << endl;
    cout << *vec.front() << endl;

    return 0;
}