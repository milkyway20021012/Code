#include <iostream>
#include <string>
using namespace std;
// **
class Clock
{
public:
    Clock(int h, int m, int s, string str) : _hour(h), _mins(m), _secs(s), _str(str) {}

    void display()
    {
        cout << "Clock = " << _hour << ":" << _mins << ":" << _secs << " AM" << endl;
    }

protected:
    int _hour;
    int _mins;
    int _secs;
    string _str;
};

class CGUClock : public Clock
{
public:
    CGUClock(int h, int m, int s, string str) : Clock(h, m, s, str) {} // 繼承的類如果要使用被繼承的類的成員 要用被繼承的類的構造函數
    void display()
    {
        if (_str == "PM" && _hour <= 11)
        {
            _hour += 12;
        }
        if (_hour == 12 && _str == "PM")
        {
            _hour = 0;
        }
        cout << "CGUClock = " << _hour << "時" << _mins << "分" << _secs << "秒" << endl;
    }
};
int main()
{
    Clock cc(10, 25, 43, "AM");
    CGUClock cguc(10, 25, 43, "PM");

    cc.display();
    cguc.display();
    return 0;
}