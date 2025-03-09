#include "../include/Date.h"

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
}

Date &Date::operator=(Date &d2)
{
    if (this != &d2)
    {
        this->_year = d2._year;
        this->_month = d2._month;
        this->_day = d2._day;
    }
    return *this;
}

bool Date::operator==(const Date &d)
{
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<(const Date &d2)
{
    if (this->_year < d2._year)
    {
        return true;
    }
    if (this->_year == d2._year && this->_month < d2._month)
    {
        return true;
    }
    if (this->_year == d2._year && this->_month == d2._month && this->_day < d2._day)
    {
        return true;
    }
    return false;
}

bool Date::operator<=(const Date &d)
{
    return *this < d || *this == d;
}

bool Date::operator>(const Date &d)
{
    return !(*this <= d);
}

bool Date::operator>=(const Date &d)
{
    // return *this > d || *this == d;
    return !(*this < d);
}

bool Date::operator!=(const Date &d)
{
    return !(*this == d);
}

int Date::GetMonthDay(int year, int month)

{
    static int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return arr[month] + 1;
    }
    return arr[month];
}
// += 会改变自身
Date &Date::operator+=(int day)
{
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month > 12)
        {
            ++_year;
            _month -= 12;
        }
    }
    return *this;
}
// + 不会改变自身 d1 + 100
Date Date::operator+(int day)
{
    Date tmp(*this); // 拷贝一个与*this 相同的对象
    tmp += day;
    return tmp;
    //     // while (tmp._day > GetMonthDay(tmp._year, tmp._month))
    //     // {
    //     //     tmp._day -= GetMonthDay(tmp._year, tmp._month);
    //     //     ++tmp._month;
    //     //     if (tmp._month > 12)
    //     //     {
    //     //         ++tmp._year;
    //     //         tmp._month -= 12;
    //     //     }
    //     // }
    //     // return tmp;
}

// Date Date::operator+(int day)
// {
//     Date tmp(*this); // 拷贝一个与*this 相同的对象
//     tmp._day += _day;
//     while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//     {
//         tmp._day -= GetMonthDay(tmp._year, tmp._month);
//         ++tmp._month;
//         if (tmp._month > 12)
//         {
//             ++tmp._year;
//             tmp._month -= 12;
//         }
//     }
//     return tmp;
// }

// 前置++
Date &Date::operator++()
{
    *this += 1;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp = *this;
    *this += 1;
    return tmp;
}
