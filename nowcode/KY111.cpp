#include <bits/stdc++.h>
using namespace std;
bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 計算從0000年1月1日到某個日期的總天數
int daysFromStart(int y, int m, int d)
{
    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};
    int total = d;
    for (int i = 1; i < m; ++i)
    {
        if (i == 2 && isLeap(y))
            total += 29;
        else
            total += dayOfMonth[i];
    }
    for (int i = 0; i < y; ++i)
    {
        total += 365 + isLeap(i);
    }
    return total;
}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;
    int y1 = date1 / 10000;
    int m1 = (date1 / 100) % 100;
    int d1 = date1 % 100;

    int y2 = date2 / 10000;
    int m2 = (date2 / 100) % 100;
    int d2 = date2 % 100;

    int diff = abs(daysFromStart(y1, m1, d1) - daysFromStart(y2, m2, d2));
    cout << diff + 1 << endl;
    return 0;
}