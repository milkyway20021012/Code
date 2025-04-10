#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 13> Month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int _year, _month, _day;
    cin >> _year >> _month >> _day;

    if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
    {
        Month_day[2] = 29;
    }
    else
    {
        Month_day[2] = 28;
    }

    int month = 1, day = 0;

    int sum = 0;

    while ((month != _month) || (day != _day))
    {
        if (month != _month)
        {
            sum += Month_day[month];
            ++month;
        }
        else
        {
            sum += 1;
            ++day;
        }
    }

    cout << sum << endl;
}