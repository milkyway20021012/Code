#include "../include/Date.h"

void DateTest1()
{
    Date d1(2023, 4, 26);
    d1+=100;
    d1.Print();
}
// 什么时候是拷贝 什么时候是赋值？

// 用一个已经存在的对象来初始化另一个新对象 -- 拷贝构造函数
// 两个已经存在的对象间复制拷贝 -- 赋值运算符重载
int main()
{

    DateTest1();
    return 0;
}