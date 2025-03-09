#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1);
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    int GetMonthDay(int year, int month);
    bool operator==(const Date &d);
    bool operator<(const Date &d);
    bool operator<=(const Date &d);
    bool operator>(const Date &d);
    bool operator>=(const Date &d);
    bool operator!=(const Date &d);
    Date &operator=(Date &d2);
    Date &operator+=(int day);
    Date operator+(int day);
    Date &operator++();
    // 增加int参数不是为了传递，而是为了占位，跟前置++的函数做区分构成重载
    Date operator++(int);

private:
    int _year;
    int _month;
    int _day;
};