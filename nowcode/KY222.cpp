#include <iostream>
using namespace std;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool Is_Leap(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        day[2] = 29;
        return true;
    }
    day[2] = 28;
    return false;
}
int main()
{
    int m, n; // m: 年 n:天

    while (scanf("%d %d", &m, &n) != EOF)
    {
        int _year = m;
        int _month = 1; // 月
        int _day = n;
        if (_day <= day[_month])
        {
            printf("%d-%02d-%02d\n", _year, _month, _day);
        }
        else
        {
            Is_Leap(_year);
            while (_day > day[_month])
            {

                _day -= day[_month];
                ++_month;
                if (_month == 13)
                {
                    _month = 1;
                    ++_year;
                    Is_Leap(_year);
                }
            }
            printf("%d-%02d-%02d\n", _year, _month, _day);
        }
    }
}