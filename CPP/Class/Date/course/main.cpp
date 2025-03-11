#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
    Date(int year = 2023, int month = 1, int day = 1):_year(year),_month(month),_day(day){

    }
    Date *operator&()
    {
        cout << "Date* operator 调用" << endl;
        return this;
    }
    const Date *operator&() const
    {
        cout << "const Date* operator&()const 调用" << endl;
        return this;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1;
    const Date d2;

    cout << &d1 << endl;
    cout << &d2 << endl;
    return 0;
}