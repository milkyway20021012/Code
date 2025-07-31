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
    void Print() const;
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
    int operator-(const Date &d) const;

private:
    int _year;
    int _month;
    int _day;
};
