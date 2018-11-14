#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
1028 人口普查

describe:
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200
的老人，而今天是 2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

input format:
输入在第一行给出正整数N，取值在(0,10​^5​​]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证
最年长和最年轻的人没有并列。

output format:
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

example:
input:
    5
    John 2001/05/12
    Tom 1814/09/06
    Ann 2121/01/30
    James 1814/09/05
    Steve 1967/11/20
output:
    3 Tom John

*/
struct Person
{
    string name;
    int year;
    int month;
    int day;

    Person(int y, int m, int d, string n = "") : year(y), month(m), day(d), name(n) {}

    bool operator<(const Person &p)
    {
        return year > p.year || (year == p.year && month > p.month) ||
               (year == p.year && month == p.month && day > p.day);
    }
    bool operator==(const Person &p)
    {
        return year == p.year && month == p.month && day == p.day;
    }
    bool operator<=(const Person &p)
    {
        return *this < p || *this == p;
    }
};

bool isValidDate(int year, int month, int day)
{
    Person oldest(1814, 9, 6);
    Person youngest(2014, 9, 6);
    Person person(year, month, day);
    return person <= oldest && youngest <= person;
}

int main()
{
    int N;
    vector<Person> persons;
    scanf("%d", &N);
    char aName[6];
    for (int i = 0; i < N; ++i)
    {
        int aYear, aMonth, aDay;
        scanf("%s %d/%d/%d", aName, &aYear, &aMonth, &aDay);
        if (isValidDate(aYear, aMonth, aDay))
        {
            persons.push_back(Person(aYear, aMonth, aDay, aName));
        }
    }
    if (persons.empty()){
        printf("0\n");
        return 0;
    }
    int size = static_cast<int>(persons.size());
    
    sort(persons.begin(), persons.end());
    printf("%d %s %s\n", size, persons.back().name.c_str(), persons.front().name.c_str());
    return 0;
}