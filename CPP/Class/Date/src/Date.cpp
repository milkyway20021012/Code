#include "../include/Date.h"

Date::Date(int year, int month, int day)
{
    if (month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "非法日期" << endl;
        assert(false);
    }
}

bool Date::operator<(const Date &x) const
{
    if (_year < x._year)
    {
        return true;
    }
    else if (_year == x._year && _month < x._month)
    {
        return true;
    }
    else if (_year == x._year && _month == x._month && _day < x._day)
    {
        return true;
    }

    return false;
}

bool Date::operator==(const Date &x) const
{
    return _year == x._year && _month == x._month && _day == x._day;
}

// 复用
// d1 <= d2
bool Date::operator<=(const Date &x) const
{
    return *this < x || *this == x;
}

bool Date::operator>(const Date &x) const
{
    return !(*this <= x);
}

bool Date::operator>=(const Date &x) const
{
    return !(*this < x);
}

bool Date::operator!=(const Date &x) const
{
    return !(*this == x);
}

int Date::GetMonthDay(int year, int month)
{
    static int daysArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    else
    {
        return daysArr[month];
    }
}

Date &Date::operator+=(int day)
{
    if (day < 0)
    {
        return *this -= -day;
    }

    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month == 13)
        {
            ++_year;
            _month = 1;
        }
    }

    return *this;
}

// d1 + 100
Date Date::operator+(int day) const
{
    Date tmp(*this);
    tmp += day;
    return tmp;

    /*tmp._day += day;
    while (tmp._day > GetMonthDay(tmp._year, tmp._month))
    {
        tmp._day -= GetMonthDay(tmp._year, tmp._month);
        ++tmp._month;
        if (tmp._month == 13)
        {
            ++tmp._year;
            tmp._month = 1;
        }
    }
    return tmp;
    */
}

Date &Date::operator-=(int day)
{
    if (day < 0)
    {
        return *this += -day;
    }

    _day -= day;
    while (_day <= 0)
    {
        --_month;
        if (_month == 0)
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
    Date tmp = *this;
    tmp -= day;
    return tmp;
}

// 前置++
Date &Date::operator++()
{
    *this += 1;
    return *this;
}

// 后置++
// 增加这个int参数不是为了接收具体的值，仅仅是占位，跟前置++构成重载
Date Date::operator++(int)
{
    Date tmp = *this;
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
    Date tmp = *this;
    *this -= 1;
    return tmp;
}

// d1 - d2;
int Date::operator-(const Date &d)
{
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

ostream &operator<<(ostream &out, const Date &d1)
{
    out << d1._year << "年" << d1._month << "月" << d1._day << "日" << endl;
    return out;
}
istream &operator>>(istream &in, Date &d1)
{
    int year, month, day;
    cin >> year >> month >> day;
    if (month > 0 && month < 13 && day > 0 && day <= d1.GetMonthDay(year, month))
    {
        d1._year = year;
        d1._month = month;
        d1._day = day;
    }
    else
    {
        cout << "非法日期" << endl;
        assert(false);
    }
    return in;
}
