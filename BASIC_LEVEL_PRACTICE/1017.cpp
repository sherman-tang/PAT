#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

/*
1017 A除以B

describe:
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

input format:
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

output format:
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

example:
input:
    123456789050987654321 7
output:
    17636684150141093474 3
*/
char arr[1001];
int main() {
    int r;
    int last;
    scanf("%s %d", arr, &r);
    int len = (int)strlen(arr);
    if (len == 1) {
        if (arr[0] - '0' < r) {
            printf("%d %d\n", 0, (arr[0] - '0'));
        }else {
            printf("%d %d\n", (arr[0] - '0') / r, (arr[0] - '0') % r);
        }
        return 0;
    }
    vector<int> vec;
    for (int i = 0; i < len; ++i){
        int remain;
        if (i == 0){
            int val;
            if (arr[i] - '0' < r){
                val = (arr[i] - '0') * 10 + (arr[i + 1] - '0');
                i++;
            }else {
                val = (arr[i] - '0');
            }
            vec.push_back(val / r);
            if (i == len - 1){
                last = (val % r) % r;
                break;
            }
            remain = val % r;
        }else{
            int val = remain * 10 + (arr[i] - '0');
            vec.push_back(val / r);
            remain = val % r;
            if (i == (strlen(arr) - 1)){
                last = val % r;
            }
        } 
    }
    for (int i = 0; i < vec.size(); ++i){
        printf("%d", vec[i]);
    }
    printf(" %d\n", last);
    return 0;
}