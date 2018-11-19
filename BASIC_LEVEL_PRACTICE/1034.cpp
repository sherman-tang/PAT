#include <iostream>
#include <cmath>

/*
1034 有理数四则运算

describe:
本题要求编写程序，计算 2 个有理数的和、差、积、商。

input format:
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

output format:
分别在4行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中k是整数部分，
a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。
注意：分子分母全部在整型范围内的整数，但是在加减乘除运算过程中可能导致溢出错误。

examples:
input:
    2/3 -4/2
output:
    2/3 + (-2) = (-1 1/3)
    2/3 - (-2) = 2 2/3
    2/3 * (-2) = (-1 1/3)
    2/3 / (-2) = (-1/3)
input:
    5/3 0/6
output:
    1 2/3 + 0 = 1 2/3
    1 2/3 - 0 = 1 2/3
    1 2/3 * 0 = 0
    1 2/3 / 0 = Inf
*/

using namespace std;
enum sign
{
    Neg = -1,
    Zero = 0,
    Pos = 1
};

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
class RationalNum
{
  public:
    RationalNum(long a, long b) : a(a), b(b)
    {
        if (a < 0)
            flag = Neg;
        else if (a == 0)
            flag = Zero;
        else
            flag = Pos;
        reformat();
    }
    RationalNum operator+(RationalNum &num);
    RationalNum operator-(RationalNum &num);
    RationalNum operator*(RationalNum &num);
    RationalNum operator/(RationalNum &num);

    friend ostream &operator<<(ostream &os, RationalNum &num);

  private:
    void reformat();
    long a, b;
    sign flag;
    long integer, numerator, denominator; // interger, numerator, denominator都是正数，数的符号由flag控制
};

void RationalNum::reformat()
{
    if (a == 0 && b == 0) {
        return;
    }
    integer = abs(a) / b;
    numerator = abs(a) % b;
    denominator = b;
    if (numerator == 0)
    {
        numerator = 0;
        denominator = b;
    }
    else
    {
        long gcdNum = gcd(numerator, denominator);
        numerator /= gcdNum;
        denominator /= gcdNum;
    }
}

RationalNum RationalNum::operator+(RationalNum &num)
{
    if (this->a == 0)
        return RationalNum(num.a, num.b);
    else if (num.a == 0)
        return RationalNum(this->a, this->b);
    long aa1 = a * num.b;
    long aa2 = num.a * b;
    RationalNum temp(aa1 + aa2, b * num.b);
    return temp;
}

RationalNum RationalNum::operator-(RationalNum &num)
{
    RationalNum negativeNum(-num.a, num.b);
    RationalNum res = *this + negativeNum;
    return res;
}

RationalNum RationalNum::operator*(RationalNum &num)
{
    if (this->a == 0 || num.a == 0)
    {
        return RationalNum(0, 1); // 1是随便选取的，选择其它不为零的数也可以
    }
    int multiFalg = this->flag * num.flag;
    long aa = this->a * num.a;
    long bb = this->b * num.b;
    return RationalNum(multiFalg * abs(aa), bb);
}
RationalNum RationalNum::operator/(RationalNum &num)
{
    if (num.a == 0)
        return RationalNum(0, 0); // 产生除零错误，故意返回一个(0, 0)的RationalNum对象
    if (this->a == 0)
        return RationalNum(0, 1);
    int multiFalg = this->flag * num.flag;
    long aa = abs(this->a * num.b);
    long bb = abs(this->b * num.a);
    return RationalNum(multiFalg * aa, bb);
}

ostream &operator<<(ostream &os, RationalNum &num)
{
    if (num.a == 0 && num.b == 0){
        os << "Inf";
        return os;
    }
        
    if (num.flag == Pos)
    {
        if (num.integer)
        {
            if (num.numerator)
                os << num.integer << " " << num.numerator << "/" << num.denominator;
            else
                os << num.integer;
        }
        else
            os << num.numerator << "/" << num.denominator;
    }
    else if (num.flag == Zero)
    {
        os << 0;
    }
    else
    {
        if (num.integer)
        {
            if (num.numerator)
                os << "(" << num.flag * num.integer << " " << num.numerator << "/" << num.denominator << ")";
            else
                os << "(" << num.flag * num.integer << ")";
        }
        else
            os << "(" << num.flag * num.numerator << "/" << num.denominator << ")";
    }
    return os;
}
int main()
{
    cout << sizeof(long) << endl;
    long a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    RationalNum val1(a1, b1);
    RationalNum val2(a2, b2);
    RationalNum res1 = val1 + val2;
    RationalNum res2 = val1 - val2;
    RationalNum res3 = val1 * val2;
    RationalNum res4 = val1 / val2;

    cout << val1 << " + " << val2 << " = ";
    cout << res1 << endl;

    cout << val1 << " - " << val2 << " = ";
    cout << res2 << endl;

    cout << val1 << " * " << val2 << " = ";
    cout << res3 << endl;

    cout << val1 << " / " << val2 << " = ";
    cout << res4 << endl;
}