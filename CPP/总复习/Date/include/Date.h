#include <assert.h>
#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

class Date {
  friend ostream &operator<<(ostream &os, const Date &d);
  friend istream &operator>>(istream &is, Date &d);

public:
  Date(int year = 2025, int month = 7, int day = 29)
      : _year(year), _month(month), _day(day) {
    assert(CheckDate());
  }
  void Print() {
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
  }
  // 拷贝构造实现
  // (其实可以不用实现，用编译器生成的就够了。因为没有涉及到开空间的问题)
  // 何时调用拷贝？如果对一个不存在的对象赋值，就是调用拷贝
  Date(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
  }
  Date &operator=(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
    return *this;
  }
  int GetMonthDay(int year, int month) {
    static unordered_map<int, int> days = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30},  {5, 31},  {6, 30},
        {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    if (month == 2 && Is_Leap_Year(year)) {
      return 29;
    }
    return days[month];
  }
  // 再来日期类会有哪些功能？
  // 1. n天后？
  Date operator+(int day) {
    Date tmp(*this);
    tmp._day += day;
    while (tmp._day > GetMonthDay(tmp._year, tmp._month)) {
      tmp._day -= GetMonthDay(tmp._year, tmp._month);
      ++tmp._month;
      if (tmp._month == 13) {
        tmp._month = 1;
        ++tmp._year;
      }
    }
    return tmp;
  }
  Date &operator+=(int day) {
    _day += day;
    while (_day > GetMonthDay(_year, _month)) {
      _day -= GetMonthDay(_year, _month);
      ++_month;
      if (_month == 13) {
        _month = 1;
        ++_year;
      }
    }
    return *this;
  }
  Date &operator++() {
    *this += 1;
    return *this;
  }
  Date operator++(int) { // 后置++
    Date tmp(*this);
    *this += 1;
    return tmp;
  }

  // 2. n天前？
  Date operator-(int day) {
    Date tmp(*this);

    tmp._day -= day;
    while (tmp._day < 0) {
      --tmp._month;
      if (tmp._month == 0) {
        tmp._month = 12;
        --tmp._year;
      }
      tmp._day += GetMonthDay(tmp._year, tmp._month);
    }
    return tmp;
  }
  Date &operator-=(int day) {
    _day -= day;
    while (_day < 0) {
      --_month;
      if (_month == 0) {
        _month = 12;
        --_year;
      }
      _day += GetMonthDay(_year, _month);
    }
    return *this;
  }
  Date &operator--() {
    *this -= 1;
    return *this;
  }
  Date operator--(int) { // 后置--
    Date tmp(*this);
    *this -= 1;
    return tmp;
  }
  bool operator>(const Date &d) const {
    return _year > d._year || (_year == d._year && _month > d._month) ||
           (_year == d._year && _month == d._month && _day > d._day);
  }
  bool operator==(const Date &d) const {
    return _year == d._year && _month == d._month && _day == d._day;
  }
  bool operator>=(const Date &d) const { return *this > d || *this == d; }
  bool operator<(const Date &d) const { return !(*this > d) && !(*this == d); }
  bool operator<=(const Date &d) const { return *this < d || *this == d; }
  bool operator!=(const Date &d) const { return !(*this == d); }
  // 3. 两个日期相加？ 没意义 相减？ => 相差几天
  int operator-(const Date &d) {
    // 两个数要相减 -> 先考虑哪个日期较大
    Date max = *this;
    Date min = d;
    int flag = 1;
    int n = 0;
    if (*this < d) {
      min = *this;
      max = d;
      flag = -1;
    }
    while (min != max) {
      ++min;
      ++n;
    }
    return n * flag;
  }

private:
  // 判断是否为闰年
  /*
  能被4整除但不能被100整除的年份是闰年；能被100整除但不能被400整除的年份是平年；能被400整除的年份是闰年
  */
  bool Is_Leap_Year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 100 == 0 && year % 400 != 0) || (year % 400 == 0)) {
      return true;
    }
    return false;
  }
  bool CheckDate() {
    if ((_month < 1 || _month > 12) ||
        (_day < 1 || _day > GetMonthDay(_year, _month))) {
      return false;
    }
    return true;
  }
  int _year;
  int _month;
  int _day;
};

ostream &operator<<(ostream &os, const Date &d) {
  os << d._year << " " << d._month << " " << d._day;
  return os;
}

istream &operator>>(istream &is, Date &d) {
  is >> d._year >> d._month >> d._day;
  assert((d._month < 1 || d._month > 12) ||
         (d._day < 1 || d._day > d.GetMonthDay(d._year, d._month)));
  return is;
}