#include <iostream>
using namespace std;
// 友元函数
// class Date
// {
//     friend ostream &operator<<(ostream &_cout, const Date &d);
//     friend istream &operator>>(istream &_cin, Date &d);

// public:
//     Date(int year = 1900, int month = 1, int day = 1)
//         : _year(year), _month(month), _day(day)
//     {
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };
// ostream &operator<<(ostream &_cout, const Date &d)
// {
//     _cout << d._year << "-" << d._month << "-" << d._day;
//     return _cout;
// }

// istream &operator>>(istream &_cin, Date &d)
// {
//     _cin >>
//         d._year;
//     _cin >> d._month;
//     _cin >> d._day;
//     return _cin;
// }
// 友元类
class Time
{
public:
    friend class Date; //声明日期类是时间类的友元，在日期类中可以直接访问时间类的私有成员
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour), _minute(minute), _second(second)
    {
    }

private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day)
    {
    }
    void SetTimeOfDate(int hour, int minute, int second)
    {
        // 直接访问时间类私有的成员变量
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};
int main()
{
    Date d;
    // cin >> d;
    // cout << d << endl;
    return 0;
}