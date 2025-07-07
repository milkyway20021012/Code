#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
    // 因为如果 << >> 作为成员函数重载会不符合我们期望的结果，因此把这两个运算符重载在全局
    // 但重载在全局会面临无法访问私有成员的问题

    /*
    // 重载为全局 面临对象访问私有成员的问题有几种方法
    1、成员放公有
    2、Date提供getxxx函数来访问私有成员
    3、友元函数
    4、重载为成员函数（在 << 和 >> 这个方法是不行的）
    */

    friend ostream &operator<<(ostream &out, Date &d);
    friend istream &operator>>(istream &in, Date &d);

public:
    Date(int year = 2025, int month = 3, int day = 15);
    const void Print() const;
    // 这里的const 作用是什么？ Print函数应该是 void Print(Date* const this);
    // 如果在Print()后加上const就会变成 void Print(const Date* const this); 因为不期望在Print函数中修改传入的类对象的值

    // 检查日期
    bool CheckDate();
    // 获取每个月的天数
    int GetMonthDay(int year, int month);

    // 运算符重载
    bool operator<(const Date &d) const;
    bool operator==(const Date &d) const;
    // 实现了 < 和 == 后就可以直接利用这个两个函数重载其他比较运算符
    bool operator<=(const Date &d) const;
    bool operator>(const Date &d) const;
    bool operator>=(const Date &d) const;
    bool operator!=(const Date &d) const;

    //  day天后是什么时候
    Date operator+(int day) const;
    //  day天前是什么时候
    Date operator-(int day) const;
    Date &operator+=(int day);
    Date &operator-=(int day);
    // 前置++
    Date &operator++();
    // 后置++
    Date operator++(int);
    // 前置--
    Date &operator--();
    // 后置--
    Date operator--(int);
    // d1 - d2
    Date operator-(const Date &d) const;

private:
    int _year;
    int _month;
    int _day;
};

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
    if (!CheckDate())
    {
        cout << "非法日期" << endl;
    }
}
const void Date::Print() const
{
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}
// 检查日期，避免非法输入
bool Date::CheckDate()
{
    if ((_month < 1 || _month > 12) || (_day < 1 || _day > GetMonthDay(_year, _month)))
    {
        return false;
    }
    return true;
}
// 获取每个月的天数
int Date::GetMonthDay(int year, int month)
{
    assert(month > 0 && month < 13);
    static int Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 判断是否是闰年
    if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 29;
    }
    return Day[month];
}

bool Date::operator<(const Date &d) const
{
    {
        if (_year < d._year)
        {
            return true;
        }
        if (_year == d._year && _month < d._month)
        {
            return true;
        }
        if (_year == d._year && _month == d._month && _day < d._day)
        {
            return true;
        }
        return false;
    }
}
bool Date::operator==(const Date &d) const
{
    return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
bool Date::operator<=(const Date &d) const
{
    return *this < d || *this == d;
}
bool Date::operator>(const Date &d) const
{
    return !(*this <= d);
}
bool Date::operator>=(const Date &d) const
{
    return !(*this < d);
}
bool Date::operator!=(const Date &d) const
{
    return !(*this == d);
}

Date &Date::operator+=(int day)
{
    if (day < 0)
    {
        _day -= -day;
    }
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13)
        {
            _month = 1;
            ++_year;
        }
    }
    return *this;
}
Date Date::operator+(int day) const
{
    Date tmp(*this); // 把*this 「拷贝」给tmp 注意是拷贝不是赋值
    tmp += day;
    return tmp;
}

Date &Date::operator-=(int day)
{
    // 2025 3 15
    //-       30
    // 2025 3 -15
    // 2025 3
    if (day < 0)
    {
        _day += -day;
    }
    _day -= day;
    while (_day < 0)
    {
        --_month;
        if (_month < 1)
        {
            _month = 12;
            --_year;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}
Date Date::operator-(int day) const
{
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
Date Date::operator-(const Date &d) const
{
    // 两个日期要相减，要先考虑哪一个人日期比较大
    Date max = *this;
    Date min = d;
    int flag = 1;
    if (*this < d)
    {
        max = d;
        min = *this;
        flag = -1;
    }
    int n = 0;
    while (min != max)
    {
        ++min;
        ++n;
    }
    return n * flag;
}
Date &Date::operator++()
{
    *this += 1;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date &Date::operator--()
{
    *this -= 1;
    return *this;
}
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

ostream &operator<<(ostream &out, Date &d)
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
}

istream &operator>>(istream &in, Date &d)
{
    cout << "请输入日期：";
    in >> d._year >> d._month >> d._day;
    if (!(d.CheckDate()))
    {
        cout << "非法日期" << endl;
    }
}
